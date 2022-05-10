/*
 * loaddspace.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "loaddspace".
 *
 * Model version              : 1.59
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Oct 25 15:41:33 2021
 *
 * Target selection: rti1006.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_loaddspace_h_
#define RTW_HEADER_loaddspace_h_
#include <string.h>
#include <math.h>
#include <float.h>
#ifndef loaddspace_COMMON_INCLUDES_
#define loaddspace_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <ds2101.h>
#include <ds4002.h>
#include <ds4201s.h>
#include <dsser.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* loaddspace_COMMON_INCLUDES_ */

#include "loaddspace_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals for system '<S112>/MATLAB Function' */
typedef struct {
  real_T K;                            /* '<S112>/MATLAB Function' */
  real_T C;                            /* '<S112>/MATLAB Function' */
} B_MATLABFunction_loaddspace_T;

/* Block signals (default storage) */
typedef struct {
  real_T ubvbwb[3];                    /* '<S26>/ub,vb,wb' */
  real_T UnitConversion[3];            /* '<S40>/Unit Conversion' */
  real_T Va[3];                        /* '<S34>/Sum2' */
  real_T Switch1;                      /* '<S127>/Switch1' */
  real_T m_deltaP_to_volt;             /* '<S128>/m_deltaP_to_volt' */
  real_T Sum;                          /* '<S128>/Sum' */
  real_T Gain;                         /* '<S21>/Gain' */
  real_T White_press;                  /* '<S18>/White_press' */
  real_T PositionIntegrator2[3];       /* '<S83>/Position Integrator2' */
  real_T Limitaltitudetotroposhere; /* '<S95>/Limit  altitude  to troposhere' */
  real_T LapseRate;                    /* '<S95>/Lapse Rate' */
  real_T Sum1;                         /* '<S95>/Sum1' */
  real_T uT0;                          /* '<S95>/1//T0' */
  real_T TT0gLR;                       /* '<S95>/(T//T0)^(g//LR) ' */
  real_T P0;                           /* '<S95>/P0' */
  real_T Sum_h;                        /* '<S95>/Sum' */
  real_T LimitaltitudetoStratosphere;
                                  /* '<S95>/Limit  altitude  to Stratosphere' */
  real_T gR;                           /* '<S95>/g//R' */
  real_T Product1;                     /* '<S95>/Product1' */
  real_T StratosphereModel;            /* '<S95>/Stratosphere Model' */
  real_T Product2;                     /* '<S95>/Product2' */
  real_T RateTransition;               /* '<S18>/Rate Transition' */
  real_T Sum13;                        /* '<S18>/Sum13' */
  real_T uDLookupTable;                /* '<S18>/1-D Lookup Table' */
  real_T WhiteNoise4;                  /* '<S18>/White Noise4' */
  real_T phithetapsi[3];               /* '<S36>/phi theta psi' */
  real_T h_ground;                     /* '<S18>/Byte Unpack' */
  real_T Sum_e;                        /* '<S18>/Sum' */
  real_T Gain_m;                       /* '<S18>/Gain' */
  real_T Saturation3;                  /* '<S18>/Saturation3' */
  real_T Sum14;                        /* '<S18>/Sum14' */
  real_T RateTransition1;              /* '<S18>/Rate Transition1' */
  real_T RateTransition2;              /* '<S18>/Rate Transition2' */
  real_T MathFunction;                 /* '<S18>/Math Function' */
  real_T Gain3;                        /* '<S18>/Gain3' */
  real_T Divide;                       /* '<S18>/Divide' */
  real_T Gain4;                        /* '<S18>/Gain4' */
  real_T Sum2;                         /* '<S85>/Sum2' */
  real_T MathFunction_f;               /* '<S85>/Math Function' */
  real_T Sum1_p;                       /* '<S85>/Sum1' */
  real_T Gain_h;                       /* '<S16>/Gain' */
  real_T Sum2_d;                       /* '<S84>/Sum2' */
  real_T MathFunction_h;               /* '<S84>/Math Function' */
  real_T Sum1_m;                       /* '<S84>/Sum1' */
  real_T MathFunction1;                /* '<S84>/Math Function1' */
  real_T Switch;                       /* '<S84>/Switch' */
  real_T Gain_g;                       /* '<S17>/Gain' */
  real_T TmpSignalConversionAtSFunctionB[6];
  real_T DiscreteTimeIntegrator;       /* '<S108>/Discrete-Time Integrator' */
  real_T Sum1_o;                       /* '<S108>/Sum1' */
  real_T ZeroOrderHold;                /* '<S104>/Zero-Order Hold' */
  real_T Gain_a;                       /* '<S99>/Gain' */
  real_T DiscreteTimeIntegrator_e;     /* '<S109>/Discrete-Time Integrator' */
  real_T Sum1_o4;                      /* '<S109>/Sum1' */
  real_T ZeroOrderHold1;               /* '<S104>/Zero-Order Hold1' */
  real_T Gain_o;                       /* '<S100>/Gain' */
  real_T TmpSignalConversionAtsincosInpo[3];
  real_T sincos_o1[3];                 /* '<S44>/sincos' */
  real_T sincos_o2[3];                 /* '<S44>/sincos' */
  real_T VectorConcatenate[9];         /* '<S46>/Vector Concatenate' */
  real_T Reshape9to3x3columnmajor[9];
                                 /* '<S46>/Reshape (9) to [3x3] column-major' */
  real_T Transpose[9];                 /* '<S26>/Transpose' */
  real_T Reshape1[3];                  /* '<S43>/Reshape1' */
  real_T Product[3];                   /* '<S43>/Product' */
  real_T Reshape2[3];                  /* '<S43>/Reshape2' */
  real_T UnitConversion_f[3];          /* '<S41>/Unit Conversion' */
  real_T Square2;                      /* '<S80>/Square2' */
  real_T Square1;                      /* '<S80>/Square1' */
  real_T Add;                          /* '<S80>/Add' */
  real_T Sqrt;                         /* '<S80>/Sqrt' */
  real_T ZeroOrderHold2;               /* '<S110>/Zero-Order Hold2' */
  real_T NoiseV_hor;                   /* '<S110>/Noise V_hor' */
  real_T noiseterraV_hor1;             /* '<S110>/noise terra V_hor1' */
  real_T Abs;                          /* '<S110>/Abs' */
  real_T Switch4;                      /* '<S110>/Switch4' */
  real_T Sum5;                         /* '<S110>/Sum5' */
  real_T ZeroOrderHold4;               /* '<S104>/Zero-Order Hold4' */
  real_T Gain5;                        /* '<S18>/Gain5' */
  real_T Atan2;                        /* '<S81>/Atan2' */
  real_T ZeroOrderHold_o;              /* '<S110>/Zero-Order Hold' */
  real_T Rumorebianco;                 /* '<S110>/Rumore bianco' */
  real_T Noiseterracourse;             /* '<S110>/Noise terra course' */
  real_T Switch3;                      /* '<S110>/Switch3' */
  real_T Course_sporco;                /* '<S110>/Add' */
  real_T Switch1_f;                    /* '<S110>/Switch1' */
  real_T ZeroOrderHold5;               /* '<S104>/Zero-Order Hold5' */
  real_T Gain_n;                       /* '<S97>/Gain' */
  real_T ZeroOrderHold6;               /* '<S104>/Zero-Order Hold6' */
  real_T u;                            /* '<S34>/Trigonometric Function1' */
  real_T u_m;                          /* '<S34>/Trigonometric Function2' */
  real_T uDLookupTable_n;              /* '<S58>/2-D Lookup Table' */
  real_T Sum1_d;                       /* '<S58>/Sum1' */
  real_T CD;                           /* '<S55>/Gain4' */
  real_T uDLookupTable_g;              /* '<S59>/2-D Lookup Table' */
  real_T Saturation;                   /* '<S59>/Saturation' */
  real_T pqr[3];                       /* '<S26>/p,q,r ' */
  real_T Timone;                       /* '<S2>/State-Space2' */
  real_T Timone_p;                     /* '<S3>/State-Space2' */
  real_T deltaR;                       /* '<Root>/Manual Switch' */
  real_T Product_h;                    /* '<S59>/Product' */
  real_T Alettoni;                     /* '<S2>/State-Space1' */
  real_T Alettoni_n;                   /* '<S3>/State-Space1' */
  real_T deltaA;                       /* '<Root>/Manual Switch' */
  real_T Product3;                     /* '<S59>/Product3' */
  real_T Sum_k;                        /* '<S59>/Sum' */
  real_T uDLookupTable_k;              /* '<S60>/2-D Lookup Table' */
  real_T Gain1;                        /* '<S60>/Gain1' */
  real_T Equilibratore;                /* '<S2>/State-Space' */
  real_T Equilibratore_o;              /* '<S3>/State-Space' */
  real_T deltaE;                       /* '<Root>/Manual Switch' */
  real_T Product4;                     /* '<S60>/Product4' */
  real_T Sum_m;                        /* '<S60>/Sum' */
  real_T CL;                           /* '<S55>/Gain5' */
  real_T TmpSignalConversionAtMatrixMult[3];/* '<S28>/Forze assi vento//q' */
  real_T FA_Bq[3];                     /* '<S28>/Matrix Multiply' */
  real_T Product_k;                    /* '<S54>/Product' */
  real_T Product1_l;                   /* '<S54>/Product1' */
  real_T Product2_o;                   /* '<S54>/Product2' */
  real_T Sum_a;                        /* '<S54>/Sum' */
  real_T xeyeze[3];                    /* '<S26>/xe,ye,ze' */
  real_T Gain_n1;                      /* '<S1>/Gain' */
  real_T Limitaltitudetotroposhere_l;
                                    /* '<S24>/Limit  altitude  to troposhere' */
  real_T LapseRate_g;                  /* '<S24>/Lapse Rate' */
  real_T Sum1_j;                       /* '<S24>/Sum1' */
  real_T uT0_h;                        /* '<S24>/1//T0' */
  real_T TT0gLR_n;                     /* '<S24>/(T//T0)^(g//LR) ' */
  real_T Product_a;                    /* '<S24>/Product' */
  real_T rho0;                         /* '<S24>/rho0' */
  real_T Sum_p;                        /* '<S24>/Sum' */
  real_T LimitaltitudetoStratosphere_i;
                                  /* '<S24>/Limit  altitude  to Stratosphere' */
  real_T gR_j;                         /* '<S24>/g//R' */
  real_T Product1_f;                   /* '<S24>/Product1' */
  real_T StratosphereModel_c;          /* '<S24>/Stratosphere Model' */
  real_T Product3_f;                   /* '<S24>/Product3' */
  real_T Product2_k;                   /* '<S27>/Product2' */
  real_T u2rhoV2;                      /* '<S27>/1//2rhoV^2' */
  real_T Product_ks[3];                /* '<S28>/Product' */
  real_T uDLookupTable_m;              /* '<S64>/2-D Lookup Table' */
  real_T Gain4_k;                      /* '<S64>/Gain4' */
  real_T Product2_c;                   /* '<S64>/Product2' */
  real_T Product3_e;                   /* '<S64>/Product3' */
  real_T Sum_n;                        /* '<S64>/Sum' */
  real_T Cl;                           /* '<S57>/Product' */
  real_T uDLookupTable_km;             /* '<S65>/2-D Lookup Table' */
  real_T Gain1_o;                      /* '<S65>/Gain1' */
  real_T Product2_j;                   /* '<S65>/Product2' */
  real_T Sum_hs;                       /* '<S65>/Sum' */
  real_T Cm;                           /* '<S57>/Product1' */
  real_T uDLookupTable_i;              /* '<S66>/2-D Lookup Table' */
  real_T Product2_p;                   /* '<S66>/Product2' */
  real_T Product3_c;                   /* '<S66>/Product3' */
  real_T Sum_hu;                       /* '<S66>/Sum' */
  real_T Cn;                           /* '<S57>/Product3' */
  real_T Product2_i[3];                /* '<S28>/Product2' */
  real_T Product3_l[3];                /* '<S35>/Product3' */
  real_T UnitDelay;                    /* '<S31>/Unit Delay' */
  real_T RPMRPs;                       /* '<S31>/RPM->RPs' */
  real_T MathFunction3;                /* '<S31>/Math Function3' */
  real_T MathFunction_c;               /* '<S31>/Math Function' */
  real_T Product1_m;                   /* '<S31>/Product1' */
  real_T uDLookupTable_b;              /* '<S75>/2-D Lookup Table' */
  real_T Product2_f;                   /* '<S31>/Product2' */
  real_T F[3];                         /* '<S22>/Sum' */
  real_T sincos_o1_g[3];               /* '<S45>/sincos' */
  real_T sincos_o2_m[3];               /* '<S45>/sincos' */
  real_T phidot;                       /* '<S45>/phidot' */
  real_T thetadot;                     /* '<S45>/thetadot' */
  real_T psidot;                       /* '<S45>/psidot' */
  real_T TmpSignalConversionAtphithetaps[3];/* '<S36>/phidot thetadot psidot' */
  real_T VectorConcatenate_m[18];      /* '<S38>/Vector Concatenate' */
  real_T Selector[9];                  /* '<S37>/Selector' */
  real_T Reshape1_k[3];                /* '<S48>/Reshape1' */
  real_T Product_f[3];                 /* '<S48>/Product' */
  real_T Reshape2_a[3];                /* '<S48>/Reshape2' */
  real_T ixj;                          /* '<S50>/i x j' */
  real_T jxk;                          /* '<S50>/j x k' */
  real_T kxi;                          /* '<S50>/k x i' */
  real_T ixk;                          /* '<S51>/i x k' */
  real_T jxi;                          /* '<S51>/j x i' */
  real_T kxj;                          /* '<S51>/k x j' */
  real_T Sum_o[3];                     /* '<S47>/Sum' */
  real_T Selector1[9];                 /* '<S37>/Selector1' */
  real_T Reshape1_l[3];                /* '<S49>/Reshape1' */
  real_T Product_p[3];                 /* '<S49>/Product' */
  real_T Reshape2_i[3];                /* '<S49>/Reshape2' */
  real_T uDLookupTable1;               /* '<S75>/2-D Lookup Table1' */
  real_T MathFunction2;                /* '<S31>/Math Function2' */
  real_T MathFunction1_c;              /* '<S31>/Math Function1' */
  real_T Product3_i;                   /* '<S31>/Product3' */
  real_T Gain_gk;                      /* '<S76>/Gain' */
  real_T Divide_b;                     /* '<S76>/Divide' */
  real_T Gain1_f;                      /* '<S76>/Gain1' */
  real_T Divide1;                      /* '<S76>/Divide1' */
  real_T Sum1_i[3];                    /* '<S22>/Sum1' */
  real_T DiscreteTimeIntegrator_c;     /* '<S18>/Discrete-Time Integrator' */
  real_T Switch_k;                     /* '<S18>/Switch' */
  real_T Sum3[3];                      /* '<S22>/Sum3' */
  real_T Sum2_i[3];                    /* '<S37>/Sum2' */
  real_T Reshape1_o[3];                /* '<S37>/Reshape1' */
  real_T Selector2[9];                 /* '<S37>/Selector2' */
  real_T Product2_kq[3];               /* '<S37>/Product2' */
  real_T Reshape[3];                   /* '<S37>/Reshape' */
  real_T F_a[3];                       /* '<S22>/Sum2' */
  real_T Product_j[3];                 /* '<S26>/Product' */
  real_T jxk_e;                        /* '<S52>/j x k' */
  real_T kxi_d;                        /* '<S52>/k x i' */
  real_T ixj_i;                        /* '<S52>/i x j' */
  real_T kxj_n;                        /* '<S53>/k x j' */
  real_T ixk_b;                        /* '<S53>/i x k' */
  real_T jxi_j;                        /* '<S53>/j x i' */
  real_T Sum_j[3];                     /* '<S39>/Sum' */
  real_T Sum_f[3];                     /* '<S26>/Sum' */
  real_T UnitConversion_h;             /* '<S42>/Unit Conversion' */
  real_T Gain1_e;                      /* '<S22>/Gain1' */
  real_T Product_g;                    /* '<S22>/Product' */
  real_T Product1_h[3];                /* '<S22>/Product1' */
  real_T Gain_p;                       /* '<S31>/Gain' */
  real_T SFunction_o1;                 /* '<S113>/S-Function' */
  real_T SFunction_o2;                 /* '<S113>/S-Function' */
  real_T Divide_d;                     /* '<S19>/Divide' */
  real_T Gain_ow;                      /* '<S19>/Gain' */
  real_T Sum1_l;                       /* '<S122>/Sum1' */
  real_T Gain_k;                       /* '<S122>/Gain' */
  real_T Sum_g;                        /* '<S122>/Sum' */
  real_T Manetta;                      /* '<Root>/Manual Switch' */
  real_T Saturation_i;                 /* '<S31>/Saturation' */
  real_T LUTMOTORE;                    /* '<S31>/LUT MOTORE' */
  real_T Fcn;                          /* '<S31>/Fcn' */
  real_T RPsrads;                      /* '<S31>/RPs->rad//s' */
  real_T u_o;                          /* '<S22>/Trigonometric Function' */
  real_T rPG[3];                       /* '<S23>/Constant' */
  real_T rLEG[3];                      /* '<S23>/Constant5' */
  real_T rACwG[3];                     /* '<S23>/Constant6' */
  real_T rACtG[3];                     /* '<S23>/Constant7' */
  real_T rNPG[3];                      /* '<S23>/Constant8' */
  real_T Jeng;                         /* '<S23>/Jeng' */
  real_T Jprop;                        /* '<S23>/Jprop' */
  real_T Rprop;                        /* '<S23>/Rprop' */
  real_T b;                            /* '<S23>/b' */
  real_T c;                            /* '<S23>/c' */
  real_T P0_j;                         /* '<S24>/P0' */
  real_T Product2_b;                   /* '<S24>/Product2' */
  real_T gammaR;                       /* '<S24>/gamma*R' */
  real_T a;                            /* '<S24>/a' */
  real_T Product_f4[3];                /* '<S25>/Product' */
  real_T Sum1_p3[3];                   /* '<S25>/Sum1' */
  real_T Sum_am[3];                    /* '<S25>/Sum' */
  real_T Gain_nh;                      /* '<S83>/Gain' */
  real_T UnitConversion_hr;            /* '<S87>/Unit Conversion' */
  real_T Sum_ke;                       /* '<S86>/Sum' */
  real_T Product4_l;                   /* '<S86>/Product4' */
  real_T Product1_k;                   /* '<S86>/Product1' */
  real_T TrigonometricFunction;        /* '<S86>/Trigonometric Function' */
  real_T Sum1_n;                       /* '<S86>/Sum1' */
  real_T Product2_l;                   /* '<S86>/Product2' */
  real_T Sum2_g;                       /* '<S86>/Sum2' */
  real_T Product3_m;                   /* '<S86>/Product3' */
  real_T sqrt_e;                       /* '<S86>/sqrt' */
  real_T Sum_h1;                       /* '<S83>/Sum' */
  real_T Sum1_lf;                      /* '<S83>/Sum1' */
  real_T VnRmh;                        /* '<S83>/Vn//(Rm+h)' */
  real_T cosphi;                       /* '<S83>/cos(phi)' */
  real_T VeRnhcosphi;                  /* '<S83>/Ve//(Rn+h)cos(phi)' */
  real_T TmpSignalConversionAtPositionIn[3];
  real_T DiscreteTimeIntegrator3;      /* '<S103>/Discrete-Time Integrator3' */
  real_T Sum12;                        /* '<S103>/Sum12' */
  real_T ZeroOrderHold9;               /* '<S103>/Zero-Order Hold9' */
  real_T Gain_gz;                      /* '<S102>/Gain' */
  real_T Saturation5;                  /* '<S18>/Saturation5' */
  real_T DiscreteTimeIntegrator4;      /* '<S103>/Discrete-Time Integrator4' */
  real_T Sum16;                        /* '<S103>/Sum16' */
  real_T ZeroOrderHold10;              /* '<S103>/Zero-Order Hold10' */
  real_T Gain_l;                       /* '<S98>/Gain' */
  real_T Saturation6;                  /* '<S18>/Saturation6' */
  real_T DiscreteTimeIntegrator5;      /* '<S103>/Discrete-Time Integrator5' */
  real_T Sum18;                        /* '<S103>/Sum18' */
  real_T ZeroOrderHold11;              /* '<S103>/Zero-Order Hold11' */
  real_T Gain_h5;                      /* '<S101>/Gain' */
  real_T Saturation4;                  /* '<S18>/Saturation4' */
  real_T RandomNumber6;                /* '<S103>/Random Number6' */
  real_T Sum23;                        /* '<S103>/Sum23' */
  real_T ZeroOrderHold15;              /* '<S103>/Zero-Order Hold15' */
  real_T RandomNumber7;                /* '<S103>/Random Number7' */
  real_T Sum14_i;                      /* '<S103>/Sum14' */
  real_T ZeroOrderHold16;              /* '<S103>/Zero-Order Hold16' */
  real_T RandomNumber8;                /* '<S103>/Random Number8' */
  real_T Sum15;                        /* '<S103>/Sum15' */
  real_T ZeroOrderHold17;              /* '<S103>/Zero-Order Hold17' */
  real_T RandomNumber3;                /* '<S103>/Random Number3' */
  real_T Sum20;                        /* '<S103>/Sum20' */
  real_T ZeroOrderHold12;              /* '<S103>/Zero-Order Hold12' */
  real_T RandomNumber4;                /* '<S103>/Random Number4' */
  real_T Sum21;                        /* '<S103>/Sum21' */
  real_T ZeroOrderHold13;              /* '<S103>/Zero-Order Hold13' */
  real_T RandomNumber5;                /* '<S103>/Random Number5' */
  real_T Sum22;                        /* '<S103>/Sum22' */
  real_T ZeroOrderHold14;              /* '<S103>/Zero-Order Hold14' */
  real_T Product_b;                    /* '<S95>/Product' */
  real_T rho0_n;                       /* '<S95>/rho0' */
  real_T Product3_k;                   /* '<S95>/Product3' */
  real_T gammaR_o;                     /* '<S95>/gamma*R' */
  real_T a_h;                          /* '<S95>/a' */
  real_T UnitConversion_k;             /* '<S107>/Unit Conversion' */
  real_T SFunction;                    /* '<S96>/S-Function' */
  real_T UnitConversion_l;             /* '<S106>/Unit Conversion' */
  real_T Gain3_h;                      /* '<S103>/Gain3' */
  real_T RandomNumber;                 /* '<S103>/Random Number' */
  real_T Sum13_d;                      /* '<S103>/Sum13' */
  real_T Gain4_n;                      /* '<S103>/Gain4' */
  real_T RandomNumber1;                /* '<S103>/Random Number1' */
  real_T Sum17;                        /* '<S103>/Sum17' */
  real_T Gain5_j;                      /* '<S103>/Gain5' */
  real_T RandomNumber2;                /* '<S103>/Random Number2' */
  real_T Sum19;                        /* '<S103>/Sum19' */
  real_T Gain_f;                       /* '<S108>/Gain' */
  real_T WhiteNoiseLat;                /* '<S108>/White Noise Lat' */
  real_T Sum_c;                        /* '<S108>/Sum' */
  real_T Gain_i;                       /* '<S109>/Gain' */
  real_T WhiteNoise;                   /* '<S109>/White Noise' */
  real_T Sum_e0;                       /* '<S109>/Sum' */
  real_T Cos1;                         /* '<S110>/Cos1' */
  real_T V_n;                          /* '<S110>/Multiply6' */
  real_T Sin1;                         /* '<S110>/Sin1' */
  real_T V_e;                          /* '<S110>/Multiply7' */
  real_T ZeroOrderHold2_m;             /* '<S104>/Zero-Order Hold2' */
  real_T ZeroOrderHold3;               /* '<S104>/Zero-Order Hold3' */
  real_T SFunction_o1_h;               /* '<S115>/S-Function' */
  real_T SFunction_o2_g;               /* '<S115>/S-Function' */
  real_T Divide2;                      /* '<S19>/Divide2' */
  real_T Gain2;                        /* '<S19>/Gain2' */
  real_T Product_pb;                   /* '<S112>/Product' */
  real_T Add_c;                        /* '<S112>/Add' */
  real_T Gain1_n;                      /* '<S119>/Gain1' */
  real_T SFunction_o1_f;               /* '<S116>/S-Function' */
  real_T SFunction_o2_k;               /* '<S116>/S-Function' */
  real_T Divide3;                      /* '<S19>/Divide3' */
  real_T SFunction_o1_j;               /* '<S114>/S-Function' */
  real_T SFunction_o2_e;               /* '<S114>/S-Function' */
  real_T Divide1_d;                    /* '<S19>/Divide1' */
  real_T Gain1_fv;                     /* '<S19>/Gain1' */
  real_T Product_jy;                   /* '<S120>/Product' */
  real_T Add_n;                        /* '<S120>/Add' */
  real_T Gain1_i;                      /* '<S117>/Gain1' */
  real_T Gain3_a;                      /* '<S19>/Gain3' */
  real_T Product_hc;                   /* '<S121>/Product' */
  real_T Add_h;                        /* '<S121>/Add' */
  real_T Gain1_ne;                     /* '<S118>/Gain1' */
  real_T deltaP;                       /* '<S21>/MATLAB Function' */
  real_T K;                            /* '<S120>/MATLAB Function' */
  real_T C;                            /* '<S120>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctionI[3];
                                   /* '<S18>/trasformazione quota earth-body' */
  real_T h_lidar;                  /* '<S18>/trasformazione quota earth-body' */
  real_T Divide2_e;                    /* '<S110>/Divide2' */
  real_T Multiply5;                    /* '<S110>/Multiply5' */
  real_T y;                            /* '<S110>/0-2pi Wrapper' */
  real_T deltaR_g;                     /* '<S3>/Saturation3' */
  real_T deltaR_j;                     /* '<S2>/Saturation3' */
  real_T deltaA_g;                     /* '<S3>/Saturation2' */
  real_T deltaA_l;                     /* '<S2>/Saturation2' */
  real_T deltaE_b;                     /* '<S3>/Saturation1' */
  real_T deltaE_i;                     /* '<S2>/Saturation1' */
  real_T ChSign;                       /* '<S84>/ChSign' */
  real_T TmpSignalConversionAtSFunctio_d[6];/* '<S25>/MATLAB Function' */
  real_T y_c[3];                       /* '<S25>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctio_p[2];
                                 /* '<S34>/controllo divisione per 0 su beta' */
  real_T y_f;                    /* '<S34>/controllo divisione per 0 su beta' */
  real_T TmpSignalConversionAtSFunctio_l[2];
                                /* '<S34>/controllo divisione per 0 su alpha' */
  real_T y_e;                   /* '<S34>/controllo divisione per 0 su alpha' */
  real_T module;                       /* '<S34>/MATLAB Function' */
  real_T invR[9];                      /* '<S22>/MATLAB Function' */
  real_T Fgear[3];                     /* '<S29>/MATLAB Function2' */
  real_T Mgear[3];                     /* '<S29>/MATLAB Function2' */
  real_T diffRm;                       /* '<S29>/MATLAB Function' */
  real_T Ds;                           /* '<S29>/MATLAB Function' */
  real_T Drm;                          /* '<S29>/MATLAB Function' */
  real_T Dlm;                          /* '<S29>/MATLAB Function' */
  real_T Fss;                          /* '<S29>/MATLAB Function' */
  real_T Frms;                         /* '<S29>/MATLAB Function' */
  real_T Flms;                         /* '<S29>/MATLAB Function' */
  real_T Fsd;                          /* '<S29>/MATLAB Function' */
  real_T Frmd;                         /* '<S29>/MATLAB Function' */
  real_T Flmd;                         /* '<S29>/MATLAB Function' */
  real_T Ns;                           /* '<S29>/MATLAB Function' */
  real_T Nrm;                          /* '<S29>/MATLAB Function' */
  real_T Nlm;                          /* '<S29>/MATLAB Function' */
  real_T Ntot;                         /* '<S29>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctio_m[4];
                                  /* '<S66>/controllo divisione per zero nr ' */
  real_T y_cd;                    /* '<S66>/controllo divisione per zero nr ' */
  real_T TmpSignalConversionAtSFunctio_a[4];
                                  /* '<S66>/controllo divisione per zero np ' */
  real_T y_a;                     /* '<S66>/controllo divisione per zero np ' */
  real_T TmpSignalConversionAtSFunctio_o[4];
                                  /* '<S65>/controllo divisione per zero mq ' */
  real_T y_cl;                    /* '<S65>/controllo divisione per zero mq ' */
  real_T TmpSignalConversionAtSFunctio_f[4];
                                  /* '<S64>/controllo divisione per zero lr ' */
  real_T y_o;                     /* '<S64>/controllo divisione per zero lr ' */
  real_T TmpSignalConversionAtSFunctio_k[4];
                                  /* '<S64>/controllo divisione per zero lp ' */
  real_T y_n;                     /* '<S64>/controllo divisione per zero lp ' */
  real_T Lbw[9];                       /* '<S28>/MATLAB Function' */
  real_T TmpSignalConversionAtSFuncti_am[4];
                                  /* '<S60>/controllo divisione per zero Lq ' */
  real_T y_ak;                    /* '<S60>/controllo divisione per zero Lq ' */
  real_T TmpSignalConversionAtSFuncti_mf[4];
                                   /* '<S59>/controllo divisione per zero Yr' */
  real_T y_j;                      /* '<S59>/controllo divisione per zero Yr' */
  real_T TmpSignalConversionAtSFuncti_kl[4];
                                  /* '<S59>/controllo divisione per zero Yp ' */
  real_T y_g;                     /* '<S59>/controllo divisione per zero Yp ' */
  uint32_T SFunctionBuilder1_o2;       /* '<Root>/S-Function Builder1' */
  uint32_T SFunction1_o1;              /* '<S11>/S-Function1' */
  real32_T DataTypeConversion[9];      /* '<S93>/Data Type Conversion' */
  real32_T SFunctionBuilder1_o3[9];    /* '<S93>/S-Function Builder1' */
  int32_T DataTypeConversion_m;        /* '<S18>/Data Type Conversion' */
  int32_T DataTypeConversion2;         /* '<S18>/Data Type Conversion2' */
  int32_T SFunction1_o2;               /* '<S11>/S-Function1' */
  int32_T SFunctionBuilder1_o2_j;      /* '<S93>/S-Function Builder1' */
  uint16_T DataTypeConversion1;        /* '<S18>/Data Type Conversion1' */
  uint8_T BytePack1[4];                /* '<S18>/Byte Pack1' */
  uint8_T SFunction1[8];               /* '<S92>/S-Function1' */
  uint8_T BytePack[2];                 /* '<S18>/Byte Pack' */
  uint8_T BytePack2[4];                /* '<S18>/Byte Pack2' */
  uint8_T SFunctionBuilder1_o1[64];    /* '<Root>/S-Function Builder1' */
  uint8_T SFunctionBuilder1[131];      /* '<S94>/S-Function Builder1' */
  uint8_T RateTransition_e[41];        /* '<Root>/Rate Transition' */
  uint8_T SFunctionBuilder1_o1_g[41];  /* '<S93>/S-Function Builder1' */
  boolean_T Compare;                   /* '<S74>/Compare' */
  B_MATLABFunction_loaddspace_T sf_MATLABFunction_j;/* '<S121>/MATLAB Function' */
  B_MATLABFunction_loaddspace_T sf_MATLABFunction_b;/* '<S112>/MATLAB Function' */
} B_loaddspace_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S108>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S109>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S31>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S18>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S103>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator4_DSTATE;/* '<S103>/Discrete-Time Integrator4' */
  real_T DiscreteTimeIntegrator5_DSTATE;/* '<S103>/Discrete-Time Integrator5' */
  real_T NextOutput;                   /* '<S18>/White_press' */
  real_T RateTransition_Buffer;        /* '<S18>/Rate Transition' */
  real_T NextOutput_a;                 /* '<S18>/White Noise4' */
  real_T RateTransition1_Buffer;       /* '<S18>/Rate Transition1' */
  real_T RateTransition2_Buffer;       /* '<S18>/Rate Transition2' */
  real_T NextOutput_b;                 /* '<S110>/Noise V_hor' */
  real_T NextOutput_am;                /* '<S110>/noise terra V_hor1' */
  real_T NextOutput_p;                 /* '<S110>/Rumore bianco' */
  real_T NextOutput_k;                 /* '<S110>/Noise terra course' */
  real_T Product2_DWORK1[9];           /* '<S37>/Product2' */
  real_T Product2_DWORK3[9];           /* '<S37>/Product2' */
  real_T Product2_DWORK4[9];           /* '<S37>/Product2' */
  real_T Product2_DWORK5[9];           /* '<S37>/Product2' */
  real_T NextOutput_i;                 /* '<S103>/Random Number6' */
  real_T NextOutput_e;                 /* '<S103>/Random Number7' */
  real_T NextOutput_c;                 /* '<S103>/Random Number8' */
  real_T NextOutput_ig;                /* '<S103>/Random Number3' */
  real_T NextOutput_pp;                /* '<S103>/Random Number4' */
  real_T NextOutput_bc;                /* '<S103>/Random Number5' */
  real_T SFunction_temp_table[8];      /* '<S96>/S-Function' */
  real_T SFunction_pres_table[8];      /* '<S96>/S-Function' */
  real_T NextOutput_aa;                /* '<S103>/Random Number' */
  real_T NextOutput_j;                 /* '<S103>/Random Number1' */
  real_T NextOutput_jf;                /* '<S103>/Random Number2' */
  real_T NextOutput_n;                 /* '<S108>/White Noise Lat' */
  real_T NextOutput_n2;                /* '<S109>/White Noise' */
  int32_T Product2_DWORK2[3];          /* '<S37>/Product2' */
  uint32_T RandSeed;                   /* '<S18>/White_press' */
  uint32_T RandSeed_o;                 /* '<S18>/White Noise4' */
  uint32_T RandSeed_n;                 /* '<S110>/Noise V_hor' */
  uint32_T RandSeed_f;                 /* '<S110>/noise terra V_hor1' */
  uint32_T RandSeed_d;                 /* '<S110>/Rumore bianco' */
  uint32_T RandSeed_a;                 /* '<S110>/Noise terra course' */
  uint32_T RandSeed_am;                /* '<S103>/Random Number6' */
  uint32_T RandSeed_g;                 /* '<S103>/Random Number7' */
  uint32_T RandSeed_e;                 /* '<S103>/Random Number8' */
  uint32_T RandSeed_g5;                /* '<S103>/Random Number3' */
  uint32_T RandSeed_gp;                /* '<S103>/Random Number4' */
  uint32_T RandSeed_b;                 /* '<S103>/Random Number5' */
  uint32_T RandSeed_fw;                /* '<S103>/Random Number' */
  uint32_T RandSeed_i;                 /* '<S103>/Random Number1' */
  uint32_T RandSeed_o0;                /* '<S103>/Random Number2' */
  uint32_T RandSeed_bo;                /* '<S108>/White Noise Lat' */
  uint32_T RandSeed_k;                 /* '<S109>/White Noise' */
  volatile int8_T RateTransition_write_buf;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition_read_buf;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition_last_buf_wr;/* '<Root>/Rate Transition' */
  volatile uint8_T RateTransition_Buffer0[41];/* '<Root>/Rate Transition' */
  volatile uint8_T RateTransition_Buffer1[41];/* '<Root>/Rate Transition' */
} DW_loaddspace_T;

/* Continuous states (default storage) */
typedef struct {
  real_T ubvbwb_CSTATE[3];             /* '<S26>/ub,vb,wb' */
  real_T PositionIntegrator2_CSTATE[3];/* '<S83>/Position Integrator2' */
  real_T phithetapsi_CSTATE[3];        /* '<S36>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S26>/p,q,r ' */
  real_T StateSpace2_CSTATE;           /* '<S2>/State-Space2' */
  real_T StateSpace2_CSTATE_g;         /* '<S3>/State-Space2' */
  real_T StateSpace1_CSTATE;           /* '<S2>/State-Space1' */
  real_T StateSpace1_CSTATE_n;         /* '<S3>/State-Space1' */
  real_T StateSpace_CSTATE;            /* '<S2>/State-Space' */
  real_T StateSpace_CSTATE_k;          /* '<S3>/State-Space' */
  real_T xeyeze_CSTATE[3];             /* '<S26>/xe,ye,ze' */
} X_loaddspace_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_loaddspace_T[3];
typedef real_T PeriodicRngX_loaddspace_T[6];

/* State derivatives (default storage) */
typedef struct {
  real_T ubvbwb_CSTATE[3];             /* '<S26>/ub,vb,wb' */
  real_T PositionIntegrator2_CSTATE[3];/* '<S83>/Position Integrator2' */
  real_T phithetapsi_CSTATE[3];        /* '<S36>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S26>/p,q,r ' */
  real_T StateSpace2_CSTATE;           /* '<S2>/State-Space2' */
  real_T StateSpace2_CSTATE_g;         /* '<S3>/State-Space2' */
  real_T StateSpace1_CSTATE;           /* '<S2>/State-Space1' */
  real_T StateSpace1_CSTATE_n;         /* '<S3>/State-Space1' */
  real_T StateSpace_CSTATE;            /* '<S2>/State-Space' */
  real_T StateSpace_CSTATE_k;          /* '<S3>/State-Space' */
  real_T xeyeze_CSTATE[3];             /* '<S26>/xe,ye,ze' */
} XDot_loaddspace_T;

/* State disabled  */
typedef struct {
  boolean_T ubvbwb_CSTATE[3];          /* '<S26>/ub,vb,wb' */
  boolean_T PositionIntegrator2_CSTATE[3];/* '<S83>/Position Integrator2' */
  boolean_T phithetapsi_CSTATE[3];     /* '<S36>/phi theta psi' */
  boolean_T pqr_CSTATE[3];             /* '<S26>/p,q,r ' */
  boolean_T StateSpace2_CSTATE;        /* '<S2>/State-Space2' */
  boolean_T StateSpace2_CSTATE_g;      /* '<S3>/State-Space2' */
  boolean_T StateSpace1_CSTATE;        /* '<S2>/State-Space1' */
  boolean_T StateSpace1_CSTATE_n;      /* '<S3>/State-Space1' */
  boolean_T StateSpace_CSTATE;         /* '<S2>/State-Space' */
  boolean_T StateSpace_CSTATE_k;       /* '<S3>/State-Space' */
  boolean_T xeyeze_CSTATE[3];          /* '<S26>/xe,ye,ze' */
} XDis_loaddspace_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (default storage) */
struct P_loaddspace_T_ {
  struct_ckUvIw1SyOAjdVf7lN2sjG State0;/* Variable: State0
                                        * Referenced by:
                                        *   '<S2>/State-Space'
                                        *   '<S2>/State-Space1'
                                        *   '<S2>/State-Space2'
                                        *   '<S3>/State-Space'
                                        *   '<S3>/State-Space1'
                                        *   '<S3>/State-Space2'
                                        *   '<S26>/p,q,r '
                                        *   '<S26>/ub,vb,wb'
                                        *   '<S26>/xe,ye,ze'
                                        *   '<S36>/phi theta psi'
                                        */
  real_T CD0;                          /* Variable: CD0
                                        * Referenced by: '<S23>/CD_0'
                                        */
  real_T CLdE;                         /* Variable: CLdE
                                        * Referenced by: '<S23>/CL_dE '
                                        */
  real_T CLq;                          /* Variable: CLq
                                        * Referenced by: '<S23>/CL_q '
                                        */
  real_T CYdA;                         /* Variable: CYdA
                                        * Referenced by: '<S23>/CY_dA'
                                        */
  real_T CYdR;                         /* Variable: CYdR
                                        * Referenced by: '<S23>/CY_dR'
                                        */
  real_T CYp;                          /* Variable: CYp
                                        * Referenced by: '<S23>/CY_p '
                                        */
  real_T CYr;                          /* Variable: CYr
                                        * Referenced by: '<S23>/CY_r'
                                        */
  real_T CldA;                         /* Variable: CldA
                                        * Referenced by: '<S23>/Cl_dA'
                                        */
  real_T CldR;                         /* Variable: CldR
                                        * Referenced by: '<S23>/Cl_dR'
                                        */
  real_T Clp;                          /* Variable: Clp
                                        * Referenced by: '<S23>/Cl_p '
                                        */
  real_T Clr;                          /* Variable: Clr
                                        * Referenced by: '<S23>/Cl_r '
                                        */
  real_T CmdE;                         /* Variable: CmdE
                                        * Referenced by: '<S23>/Cm_dE '
                                        */
  real_T Cmq;                          /* Variable: Cmq
                                        * Referenced by: '<S23>/Cm_q '
                                        */
  real_T CndA;                         /* Variable: CndA
                                        * Referenced by: '<S23>/Cn_dA'
                                        */
  real_T CndR;                         /* Variable: CndR
                                        * Referenced by: '<S23>/Cn_dR '
                                        */
  real_T Cnp;                          /* Variable: Cnp
                                        * Referenced by: '<S23>/Cn_p '
                                        */
  real_T Cnr;                          /* Variable: Cnr
                                        * Referenced by: '<S23>/Cn_r '
                                        */
  real_T Dprop;                        /* Variable: Dprop
                                        * Referenced by: '<S23>/Dprop'
                                        */
  real_T I[9];                         /* Variable: I
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T J_vec[30];                    /* Variable: J_vec
                                        * Referenced by:
                                        *   '<S75>/2-D Lookup Table'
                                        *   '<S75>/2-D Lookup Table1'
                                        */
  real_T Jeng;                         /* Variable: Jeng
                                        * Referenced by: '<S23>/Jeng'
                                        */
  real_T Jprop;                        /* Variable: Jprop
                                        * Referenced by: '<S23>/Jprop'
                                        */
  real_T Rprop;                        /* Variable: Rprop
                                        * Referenced by: '<S23>/Rprop'
                                        */
  real_T S;                            /* Variable: S
                                        * Referenced by:
                                        *   '<S23>/S'
                                        *   '<S23>/S*b '
                                        *   '<S23>/S*cbar'
                                        */
  real_T Std_vel;                      /* Variable: Std_vel
                                        * Referenced by: '<S110>/Std_vel'
                                        */
  real_T Ta_lat;                       /* Variable: Ta_lat
                                        * Referenced by: '<S108>/Gain'
                                        */
  real_T Ta_long;                      /* Variable: Ta_long
                                        * Referenced by: '<S109>/Gain'
                                        */
  real_T U0[4];                        /* Variable: U0
                                        * Referenced by:
                                        *   '<S4>/A'
                                        *   '<S4>/E'
                                        *   '<S4>/R'
                                        *   '<S4>/T'
                                        */
  real_T Var_V_hor_static;             /* Variable: Var_V_hor_static
                                        * Referenced by: '<S110>/noise terra V_hor1'
                                        */
  real_T Var_heading_static;           /* Variable: Var_heading_static
                                        * Referenced by: '<S110>/Noise terra course'
                                        */
  real_T W[3];                         /* Variable: W
                                        * Referenced by: '<S23>/W'
                                        */
  real_T White_ax;                     /* Variable: White_ax
                                        * Referenced by: '<S103>/Random Number3'
                                        */
  real_T White_ay;                     /* Variable: White_ay
                                        * Referenced by: '<S103>/Random Number4'
                                        */
  real_T White_az;                     /* Variable: White_az
                                        * Referenced by: '<S103>/Random Number5'
                                        */
  real_T White_gm_phi;                 /* Variable: White_gm_phi
                                        * Referenced by: '<S103>/Random Number'
                                        */
  real_T White_gm_psi;                 /* Variable: White_gm_psi
                                        * Referenced by: '<S103>/Random Number2'
                                        */
  real_T White_gm_theta;               /* Variable: White_gm_theta
                                        * Referenced by: '<S103>/Random Number1'
                                        */
  real_T White_p;                      /* Variable: White_p
                                        * Referenced by: '<S103>/Random Number6'
                                        */
  real_T White_pressione;              /* Variable: White_pressione
                                        * Referenced by: '<S18>/White_press'
                                        */
  real_T White_q;                      /* Variable: White_q
                                        * Referenced by: '<S103>/Random Number7'
                                        */
  real_T White_r;                      /* Variable: White_r
                                        * Referenced by: '<S103>/Random Number8'
                                        */
  real_T Zeng;                         /* Variable: Zeng
                                        * Referenced by: '<S23>/Zeng'
                                        */
  real_T adc_P_bmp[16363];             /* Variable: adc_P_bmp
                                        * Referenced by: '<S18>/1-D Lookup Table'
                                        */
  real_T alphavec_rad[13];             /* Variable: alphavec_rad
                                        * Referenced by:
                                        *   '<S58>/2-D Lookup Table'
                                        *   '<S59>/2-D Lookup Table'
                                        *   '<S60>/2-D Lookup Table'
                                        *   '<S64>/2-D Lookup Table'
                                        *   '<S65>/2-D Lookup Table'
                                        *   '<S66>/2-D Lookup Table'
                                        */
  real_T attuatore_Amax;               /* Variable: attuatore_Amax
                                        * Referenced by:
                                        *   '<S2>/Saturation2'
                                        *   '<S3>/Saturation2'
                                        */
  real_T attuatore_Emax;               /* Variable: attuatore_Emax
                                        * Referenced by:
                                        *   '<S2>/Saturation1'
                                        *   '<S3>/Saturation1'
                                        */
  real_T attuatore_Rmax;               /* Variable: attuatore_Rmax
                                        * Referenced by:
                                        *   '<S2>/Saturation3'
                                        *   '<S3>/Saturation3'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by:
                                        *   '<S23>/S*b '
                                        *   '<S23>/b'
                                        *   '<S23>/b//2'
                                        */
  real_T beta_phi;                     /* Variable: beta_phi
                                        * Referenced by: '<S103>/Gain3'
                                        */
  real_T beta_psi;                     /* Variable: beta_psi
                                        * Referenced by: '<S103>/Gain5'
                                        */
  real_T beta_theta;                   /* Variable: beta_theta
                                        * Referenced by: '<S103>/Gain4'
                                        */
  real_T betavec_rad[7];               /* Variable: betavec_rad
                                        * Referenced by:
                                        *   '<S58>/2-D Lookup Table'
                                        *   '<S59>/2-D Lookup Table'
                                        *   '<S60>/2-D Lookup Table'
                                        *   '<S64>/2-D Lookup Table'
                                        *   '<S65>/2-D Lookup Table'
                                        *   '<S66>/2-D Lookup Table'
                                        */
  real_T c;                            /* Variable: c
                                        * Referenced by: '<S23>/c'
                                        */
  real_T cbar;                         /* Variable: cbar
                                        * Referenced by:
                                        *   '<S23>/S*cbar'
                                        *   '<S23>/cbar '
                                        */
  real_T degree_aileron[43];           /* Variable: degree_aileron
                                        * Referenced by: '<S112>/Constant5'
                                        */
  real_T degree_elevator[15];          /* Variable: degree_elevator
                                        * Referenced by: '<S120>/Constant5'
                                        */
  real_T degree_rudder[43];            /* Variable: degree_rudder
                                        * Referenced by: '<S121>/Constant6'
                                        */
  real_T deltaTtrim;                   /* Variable: deltaTtrim
                                        * Referenced by: '<S31>/Unit Delay'
                                        */
  real_T g[3];                         /* Variable: g
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T mean_ax;                      /* Variable: mean_ax
                                        * Referenced by: '<S103>/Random Number3'
                                        */
  real_T mean_ay;                      /* Variable: mean_ay
                                        * Referenced by: '<S103>/Random Number4'
                                        */
  real_T mean_az;                      /* Variable: mean_az
                                        * Referenced by: '<S103>/Random Number5'
                                        */
  real_T mean_p;                       /* Variable: mean_p
                                        * Referenced by: '<S103>/Random Number6'
                                        */
  real_T mean_q;                       /* Variable: mean_q
                                        * Referenced by: '<S103>/Random Number7'
                                        */
  real_T mean_r;                       /* Variable: mean_r
                                        * Referenced by: '<S103>/Random Number8'
                                        */
  real_T microsec_aileron[43];         /* Variable: microsec_aileron
                                        * Referenced by: '<S112>/Constant4'
                                        */
  real_T microsec_elevator[15];        /* Variable: microsec_elevator
                                        * Referenced by: '<S120>/Constant4'
                                        */
  real_T microsec_rudder[43];          /* Variable: microsec_rudder
                                        * Referenced by: '<S121>/Constant5'
                                        */
  real_T p_bmp[16363];                 /* Variable: p_bmp
                                        * Referenced by: '<S18>/1-D Lookup Table'
                                        */
  real_T rACtG[3];                     /* Variable: rACtG
                                        * Referenced by: '<S23>/Constant7'
                                        */
  real_T rACwG[3];                     /* Variable: rACwG
                                        * Referenced by: '<S23>/Constant6'
                                        */
  real_T rAHRSG[3];                    /* Variable: rAHRSG
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T rLEG[3];                      /* Variable: rLEG
                                        * Referenced by: '<S23>/Constant5'
                                        */
  real_T rNPG[3];                      /* Variable: rNPG
                                        * Referenced by: '<S23>/Constant8'
                                        */
  real_T rPG[3];                       /* Variable: rPG
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T rmglG[3];                     /* Variable: rmglG
                                        * Referenced by: '<S23>/Constant3'
                                        */
  real_T rmgrG[3];                     /* Variable: rmgrG
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T rngG[3];                      /* Variable: rngG
                                        * Referenced by: '<S23>/Constant4'
                                        */
  real_T seed_ahrs;                    /* Variable: seed_ahrs
                                        * Referenced by:
                                        *   '<S103>/Random Number'
                                        *   '<S103>/Random Number1'
                                        *   '<S103>/Random Number2'
                                        *   '<S103>/Random Number3'
                                        *   '<S103>/Random Number4'
                                        *   '<S103>/Random Number5'
                                        *   '<S103>/Random Number6'
                                        *   '<S103>/Random Number7'
                                        *   '<S103>/Random Number8'
                                        */
  real_T seed_baro;                    /* Variable: seed_baro
                                        * Referenced by: '<S18>/White_press'
                                        */
  real_T seed_gps;                     /* Variable: seed_gps
                                        * Referenced by:
                                        *   '<S110>/Noise V_hor'
                                        *   '<S110>/Noise terra course'
                                        *   '<S110>/Rumore bianco'
                                        *   '<S110>/noise terra V_hor1'
                                        */
  real_T wind_constant[3];             /* Variable: wind_constant
                                        * Referenced by: '<S14>/Winds'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S74>/Constant'
                                       */
  real_T ChSign_Gain;                  /* Expression: -1
                                        * Referenced by: '<S84>/ChSign'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S110>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 45
                                        * Referenced by: '<S127>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 45
                                        * Referenced by: '<S127>/Switch1'
                                        */
  real_T m_deltaP_to_volt_Gain;        /* Expression: 41/24884
                                        * Referenced by: '<S128>/m_deltaP_to_volt'
                                        */
  real_T q_deltaP_to_volt_Value;       /* Expression: 49/20
                                        * Referenced by: '<S128>/q_deltaP_to_volt'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.2
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T White_press_Mean;             /* Expression: 0
                                        * Referenced by: '<S18>/White_press'
                                        */
  real_T SeaLevelTemperature_Value;    /* Expression: T0
                                        * Referenced by: '<S95>/Sea Level  Temperature'
                                        */
  real_T PositionIntegrator2_IC[3];
                              /* Expression: [latitudineINI longitudineINI HINI]
                               * Referenced by: '<S83>/Position Integrator2'
                               */
  real_T Limitaltitudetotroposhere_Upper;/* Expression: h_trop
                                          * Referenced by: '<S95>/Limit  altitude  to troposhere'
                                          */
  real_T Limitaltitudetotroposhere_Lower;/* Expression: h0
                                          * Referenced by: '<S95>/Limit  altitude  to troposhere'
                                          */
  real_T LapseRate_Gain;               /* Expression: L
                                        * Referenced by: '<S95>/Lapse Rate'
                                        */
  real_T uT0_Gain;                     /* Expression: 1/T0
                                        * Referenced by: '<S95>/1//T0'
                                        */
  real_T Constant_Value_i;             /* Expression: g/(L*R)
                                        * Referenced by: '<S95>/Constant'
                                        */
  real_T P0_Gain;                      /* Expression: P0
                                        * Referenced by: '<S95>/P0'
                                        */
  real_T AltitudeofTroposphere_Value;  /* Expression: h_trop
                                        * Referenced by: '<S95>/Altitude of Troposphere'
                                        */
  real_T LimitaltitudetoStratosphere_Upp;/* Expression: 0
                                          * Referenced by: '<S95>/Limit  altitude  to Stratosphere'
                                          */
  real_T LimitaltitudetoStratosphere_Low;/* Expression: h_trop-h_strat
                                          * Referenced by: '<S95>/Limit  altitude  to Stratosphere'
                                          */
  real_T gR_Gain;                      /* Expression: g/R
                                        * Referenced by: '<S95>/g//R'
                                        */
  real_T WhiteNoise4_Mean;             /* Expression: 0
                                        * Referenced by: '<S18>/White Noise4'
                                        */
  real_T WhiteNoise4_StdDev;           /* Computed Parameter: WhiteNoise4_StdDev
                                        * Referenced by: '<S18>/White Noise4'
                                        */
  real_T WhiteNoise4_Seed;             /* Expression: [23341]
                                        * Referenced by: '<S18>/White Noise4'
                                        */
  real_T phithetapsi_WrappedStateUpperVa;/* Expression: pi
                                          * Referenced by: '<S36>/phi theta psi'
                                          */
  real_T phithetapsi_WrappedStateLowerVa;/* Expression: -pi
                                          * Referenced by: '<S36>/phi theta psi'
                                          */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T SFunction1_BytesRefNumOf;     /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S92>/S-Function1'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 100
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 4000
                                        * Referenced by: '<S18>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S18>/Saturation3'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1.225
                                        * Referenced by: '<S18>/Gain3'
                                        */
  real_T Constant2_Value;              /* Expression: 2
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 100
                                        * Referenced by: '<S18>/Gain4'
                                        */
  real_T pi_Value;                     /* Expression: pi
                                        * Referenced by: '<S85>/pi'
                                        */
  real_T upi_Value;                    /* Expression: 2*pi
                                        * Referenced by: '<S85>/2pi'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 180/pi
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T pi2_Value;                    /* Expression: pi/2
                                        * Referenced by: '<S84>/pi//2'
                                        */
  real_T pi_Value_d;                   /* Expression: pi
                                        * Referenced by: '<S84>/pi'
                                        */
  real_T upi_Value_e;                  /* Expression: 2*pi
                                        * Referenced by: '<S84>/2pi'
                                        */
  real_T Switch_Threshold;             /* Expression: pi
                                        * Referenced by: '<S84>/Switch'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 180/pi
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S108>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S108>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 180/pi
                                        * Referenced by: '<S99>/Gain'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                           * Referenced by: '<S109>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S109>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S100>/Gain'
                                        */
  real_T NoiseV_hor_Mean;              /* Expression: 0
                                        * Referenced by: '<S110>/Noise V_hor'
                                        */
  real_T NoiseV_hor_StdDev;            /* Computed Parameter: NoiseV_hor_StdDev
                                        * Referenced by: '<S110>/Noise V_hor'
                                        */
  real_T noiseterraV_hor1_Mean;        /* Expression: 0
                                        * Referenced by: '<S110>/noise terra V_hor1'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0.3
                                        * Referenced by: '<S110>/Switch4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1.94384
                                        * Referenced by: '<S18>/Gain5'
                                        */
  real_T Rumorebianco_Mean;            /* Expression: 0
                                        * Referenced by: '<S110>/Rumore bianco'
                                        */
  real_T Rumorebianco_StdDev;         /* Computed Parameter: Rumorebianco_StdDev
                                       * Referenced by: '<S110>/Rumore bianco'
                                       */
  real_T Noiseterracourse_Mean;        /* Expression: 0
                                        * Referenced by: '<S110>/Noise terra course'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S110>/Switch3'
                                        */
  real_T Switch1_Threshold_i;          /* Expression: 0.3
                                        * Referenced by: '<S110>/Switch1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S97>/Gain'
                                        */
  real_T uDLookupTable_tableData[91];  /* Expression: CD(2:end,2:end)
                                        * Referenced by: '<S58>/2-D Lookup Table'
                                        */
  real_T Gain4_Gain_j;                 /* Expression: -1
                                        * Referenced by: '<S55>/Gain4'
                                        */
  real_T uDLookupTable_tableData_k[91];/* Expression: CY(2:end,2:end)
                                        * Referenced by: '<S59>/2-D Lookup Table'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.1
                                        * Referenced by: '<S59>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.1
                                        * Referenced by: '<S59>/Saturation'
                                        */
  real_T StateSpace2_A;                /* Computed Parameter: StateSpace2_A
                                        * Referenced by: '<S2>/State-Space2'
                                        */
  real_T StateSpace2_B;                /* Computed Parameter: StateSpace2_B
                                        * Referenced by: '<S2>/State-Space2'
                                        */
  real_T StateSpace2_C;                /* Computed Parameter: StateSpace2_C
                                        * Referenced by: '<S2>/State-Space2'
                                        */
  real_T StateSpace2_A_l;              /* Computed Parameter: StateSpace2_A_l
                                        * Referenced by: '<S3>/State-Space2'
                                        */
  real_T StateSpace2_B_o;              /* Computed Parameter: StateSpace2_B_o
                                        * Referenced by: '<S3>/State-Space2'
                                        */
  real_T StateSpace2_C_b;              /* Computed Parameter: StateSpace2_C_b
                                        * Referenced by: '<S3>/State-Space2'
                                        */
  real_T StateSpace1_A;                /* Computed Parameter: StateSpace1_A
                                        * Referenced by: '<S2>/State-Space1'
                                        */
  real_T StateSpace1_B;                /* Computed Parameter: StateSpace1_B
                                        * Referenced by: '<S2>/State-Space1'
                                        */
  real_T StateSpace1_C;                /* Computed Parameter: StateSpace1_C
                                        * Referenced by: '<S2>/State-Space1'
                                        */
  real_T StateSpace1_A_b;              /* Computed Parameter: StateSpace1_A_b
                                        * Referenced by: '<S3>/State-Space1'
                                        */
  real_T StateSpace1_B_a;              /* Computed Parameter: StateSpace1_B_a
                                        * Referenced by: '<S3>/State-Space1'
                                        */
  real_T StateSpace1_C_o;              /* Computed Parameter: StateSpace1_C_o
                                        * Referenced by: '<S3>/State-Space1'
                                        */
  real_T uDLookupTable_tableData_a[91];/* Expression: CL(2:end,2:end)
                                        * Referenced by: '<S60>/2-D Lookup Table'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S60>/Gain1'
                                        */
  real_T StateSpace_A;                 /* Computed Parameter: StateSpace_A
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T StateSpace_B;                 /* Computed Parameter: StateSpace_B
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T StateSpace_C;                 /* Computed Parameter: StateSpace_C
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T StateSpace_A_h;               /* Computed Parameter: StateSpace_A_h
                                        * Referenced by: '<S3>/State-Space'
                                        */
  real_T StateSpace_B_o;               /* Computed Parameter: StateSpace_B_o
                                        * Referenced by: '<S3>/State-Space'
                                        */
  real_T StateSpace_C_a;               /* Computed Parameter: StateSpace_C_a
                                        * Referenced by: '<S3>/State-Space'
                                        */
  real_T Gain5_Gain_e;                 /* Expression: -1
                                        * Referenced by: '<S55>/Gain5'
                                        */
  real_T SeaLevelTemperature_Value_i;  /* Expression: T0
                                        * Referenced by: '<S24>/Sea Level  Temperature'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Limitaltitudetotroposhere_Upp_a;/* Expression: h_trop
                                          * Referenced by: '<S24>/Limit  altitude  to troposhere'
                                          */
  real_T Limitaltitudetotroposhere_Low_o;/* Expression: h0
                                          * Referenced by: '<S24>/Limit  altitude  to troposhere'
                                          */
  real_T LapseRate_Gain_n;             /* Expression: L
                                        * Referenced by: '<S24>/Lapse Rate'
                                        */
  real_T uT0_Gain_i;                   /* Expression: 1/T0
                                        * Referenced by: '<S24>/1//T0'
                                        */
  real_T Constant_Value_c;             /* Expression: g/(L*R)
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T rho0_Gain;                    /* Expression: rho0
                                        * Referenced by: '<S24>/rho0'
                                        */
  real_T AltitudeofTroposphere_Value_p;/* Expression: h_trop
                                        * Referenced by: '<S24>/Altitude of Troposphere'
                                        */
  real_T LimitaltitudetoStratosphere_U_o;/* Expression: 0
                                          * Referenced by: '<S24>/Limit  altitude  to Stratosphere'
                                          */
  real_T LimitaltitudetoStratosphere_L_k;/* Expression: h_trop-h_strat
                                          * Referenced by: '<S24>/Limit  altitude  to Stratosphere'
                                          */
  real_T gR_Gain_i;                    /* Expression: g/R
                                        * Referenced by: '<S24>/g//R'
                                        */
  real_T u2rhoV2_Gain;                 /* Expression: 1/2
                                        * Referenced by: '<S27>/1//2rhoV^2'
                                        */
  real_T uDLookupTable_tableData_d[91];/* Expression: Cl(2:end,2:end)
                                        * Referenced by: '<S64>/2-D Lookup Table'
                                        */
  real_T Gain4_Gain_c;                 /* Expression: 1.5
                                        * Referenced by: '<S64>/Gain4'
                                        */
  real_T uDLookupTable_tableData_c[91];/* Expression: Cm(2:end,2:end)
                                        * Referenced by: '<S65>/2-D Lookup Table'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S65>/Gain1'
                                        */
  real_T uDLookupTable_tableData_h[91];/* Expression: Cn(2:end,2:end)
                                        * Referenced by: '<S66>/2-D Lookup Table'
                                        */
  real_T RPMRPs_Gain;                  /* Expression: 1/60
                                        * Referenced by: '<S31>/RPM->RPs'
                                        */
  real_T Constant_Value_n;             /* Expression: 2
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 4
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T uDLookupTable_tableData_f[330];/* Expression: Ct(2:end,2:end)
                                         * Referenced by: '<S75>/2-D Lookup Table'
                                         */
  real_T uDLookupTable_bp02Data[11];   /* Expression: RPM_vec(2:end)
                                        * Referenced by: '<S75>/2-D Lookup Table'
                                        */
  real_T Constant_Value_i4;            /* Expression: 0
                                        * Referenced by: '<S76>/Constant'
                                        */
  real_T Constant2_Value_l[9];         /* Expression: zeros(3)
                                        * Referenced by: '<S38>/Constant2'
                                        */
  real_T uDLookupTable1_tableData[330];/* Expression: Cp(2:end,2:end)
                                        * Referenced by: '<S75>/2-D Lookup Table1'
                                        */
  real_T uDLookupTable1_bp02Data[11];  /* Expression: RPM_vec(2:end)
                                        * Referenced by: '<S75>/2-D Lookup Table1'
                                        */
  real_T Constant3_Value_h;            /* Expression: 5
                                        * Referenced by: '<S31>/Constant3'
                                        */
  real_T Constant2_Value_p;            /* Expression: 3
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Gain_Gain_lp;                 /* Expression: 2*pi
                                        * Referenced by: '<S76>/Gain'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: -1
                                        * Referenced by: '<S76>/Gain1'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S76>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                           * Referenced by: '<S18>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_cw; /* Expression: 0
                                        * Referenced by: '<S18>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 11
                                          * Referenced by: '<S18>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S18>/Discrete-Time Integrator'
                                          */
  real_T Constant3_Value_i;            /* Expression: 2.4
                                        * Referenced by: '<S18>/Constant3'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 10
                                        * Referenced by: '<S18>/Switch'
                                        */
  real_T kng_Value;                    /* Expression: 8716.2
                                        * Referenced by: '<S23>/kng'
                                        */
  real_T kmg_Value;                    /* Expression: 9499.1
                                        * Referenced by: '<S23>/kmg'
                                        */
  real_T cng_Value;                    /* Expression: 187.1616
                                        * Referenced by: '<S23>/cng'
                                        */
  real_T cmg_Value;                    /* Expression: 194.9910
                                        * Referenced by: '<S23>/cmg'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: -1
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1/(0.8*37)
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T Gain_Gain_l3;                 /* Expression: 10^6
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Constant1_Value_i;            /* Expression: 2
                                        * Referenced by: '<S122>/Constant1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1/800
                                        * Referenced by: '<S122>/Gain'
                                        */
  real_T Constant_Value_id;            /* Expression: 11/8
                                        * Referenced by: '<S122>/Constant'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1
                                        * Referenced by: '<S31>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: 0.001
                                        * Referenced by: '<S31>/Saturation'
                                        */
  real_T LUTMOTORE_Gain;               /* Expression: 7400
                                        * Referenced by: '<S31>/LUT MOTORE'
                                        */
  real_T RPsrads_Gain;                 /* Expression: 2*pi
                                        * Referenced by: '<S31>/RPs->rad//s'
                                        */
  real_T P0_Gain_h;                    /* Expression: P0
                                        * Referenced by: '<S24>/P0'
                                        */
  real_T gammaR_Gain;                  /* Expression: gamma*R
                                        * Referenced by: '<S24>/gamma*R'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -1
                                        * Referenced by: '<S83>/Gain'
                                        */
  real_T Constant_Value_nj;            /* Expression: 1
                                        * Referenced by: '<S86>/Constant'
                                        */
  real_T f_Value;                      /* Expression: F
                                        * Referenced by: '<S86>/f'
                                        */
  real_T Re_Value;                     /* Expression: R
                                        * Referenced by: '<S86>/Re'
                                        */
  real_T DiscreteTimeIntegrator3_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator3_gainval
                           * Referenced by: '<S103>/Discrete-Time Integrator3'
                           */
  real_T DiscreteTimeIntegrator3_IC;   /* Expression: 0
                                        * Referenced by: '<S103>/Discrete-Time Integrator3'
                                        */
  real_T Gain_Gain_li;                 /* Expression: 180/pi
                                        * Referenced by: '<S102>/Gain'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: 180
                                        * Referenced by: '<S18>/Saturation5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -180
                                        * Referenced by: '<S18>/Saturation5'
                                        */
  real_T DiscreteTimeIntegrator4_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator4_gainval
                           * Referenced by: '<S103>/Discrete-Time Integrator4'
                           */
  real_T DiscreteTimeIntegrator4_IC;   /* Expression: 0
                                        * Referenced by: '<S103>/Discrete-Time Integrator4'
                                        */
  real_T Gain_Gain_ow;                 /* Expression: 180/pi
                                        * Referenced by: '<S98>/Gain'
                                        */
  real_T Saturation6_UpperSat;         /* Expression: 90
                                        * Referenced by: '<S18>/Saturation6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -90
                                        * Referenced by: '<S18>/Saturation6'
                                        */
  real_T DiscreteTimeIntegrator5_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator5_gainval
                           * Referenced by: '<S103>/Discrete-Time Integrator5'
                           */
  real_T DiscreteTimeIntegrator5_IC;   /* Expression: 0
                                        * Referenced by: '<S103>/Discrete-Time Integrator5'
                                        */
  real_T Gain_Gain_jt;                 /* Expression: 180/pi
                                        * Referenced by: '<S101>/Gain'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 180
                                        * Referenced by: '<S18>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -180
                                        * Referenced by: '<S18>/Saturation4'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S18>/Constant4'
                                        */
  real_T rho0_Gain_n;                  /* Expression: rho0
                                        * Referenced by: '<S95>/rho0'
                                        */
  real_T gammaR_Gain_b;                /* Expression: gamma*R
                                        * Referenced by: '<S95>/gamma*R'
                                        */
  real_T RandomNumber_Mean;            /* Expression: 0
                                        * Referenced by: '<S103>/Random Number'
                                        */
  real_T RandomNumber1_Mean;           /* Expression: 0
                                        * Referenced by: '<S103>/Random Number1'
                                        */
  real_T RandomNumber2_Mean;           /* Expression: 0
                                        * Referenced by: '<S103>/Random Number2'
                                        */
  real_T WhiteNoiseLat_Mean;           /* Expression: 0
                                        * Referenced by: '<S108>/White Noise Lat'
                                        */
  real_T WhiteNoiseLat_StdDev;       /* Computed Parameter: WhiteNoiseLat_StdDev
                                      * Referenced by: '<S108>/White Noise Lat'
                                      */
  real_T WhiteNoiseLat_Seed;           /* Expression: 0
                                        * Referenced by: '<S108>/White Noise Lat'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S109>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S109>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: 0
                                        * Referenced by: '<S109>/White Noise'
                                        */
  real_T Gain2_Gain;                   /* Expression: 10^6
                                        * Referenced by: '<S19>/Gain2'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S112>/Constant1'
                                        */
  real_T Gain1_Gain_cd;                /* Expression: pi/180
                                        * Referenced by: '<S119>/Gain1'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 10^6
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S120>/Constant1'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: pi/180
                                        * Referenced by: '<S117>/Gain1'
                                        */
  real_T Gain3_Gain_k;                 /* Expression: 10^6
                                        * Referenced by: '<S19>/Gain3'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S121>/Constant1'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: pi/180
                                        * Referenced by: '<S118>/Gain1'
                                        */
  uint32_T SFunction1_BytesRefNumOf_p; /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S88>/S-Function1'
                                        */
  uint32_T SFunction1_BytesRefNumOf_o; /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S12>/S-Function1'
                                        */
  uint32_T SFunction1_BytesRefNumOf_e; /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S11>/S-Function1'
                                        */
  uint32_T SFunction1_BytesRefNumOf_m; /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S20>/S-Function1'
                                        */
  uint32_T uDLookupTable_maxIndex[2];
                                   /* Computed Parameter: uDLookupTable_maxIndex
                                    * Referenced by: '<S58>/2-D Lookup Table'
                                    */
  uint32_T uDLookupTable_maxIndex_n[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_n
                                  * Referenced by: '<S59>/2-D Lookup Table'
                                  */
  uint32_T uDLookupTable_maxIndex_i[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_i
                                  * Referenced by: '<S60>/2-D Lookup Table'
                                  */
  uint32_T uDLookupTable_maxIndex_d[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_d
                                  * Referenced by: '<S64>/2-D Lookup Table'
                                  */
  uint32_T uDLookupTable_maxIndex_d3[2];
                                /* Computed Parameter: uDLookupTable_maxIndex_d3
                                 * Referenced by: '<S65>/2-D Lookup Table'
                                 */
  uint32_T uDLookupTable_maxIndex_j[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_j
                                  * Referenced by: '<S66>/2-D Lookup Table'
                                  */
  uint32_T uDLookupTable_maxIndex_nw[2];
                                /* Computed Parameter: uDLookupTable_maxIndex_nw
                                 * Referenced by: '<S75>/2-D Lookup Table'
                                 */
  uint32_T uDLookupTable1_maxIndex[2];
                                  /* Computed Parameter: uDLookupTable1_maxIndex
                                   * Referenced by: '<S75>/2-D Lookup Table1'
                                   */
  uint8_T Constant1_Value_p[5];        /* Computed Parameter: Constant1_Value_p
                                        * Referenced by: '<S18>/Constant1'
                                        */
  uint8_T ManualSwitch_4_CurrentSetting;
                            /* Computed Parameter: ManualSwitch_4_CurrentSetting
                             * Referenced by: '<Root>/Manual Switch'
                             */
  uint8_T ManualSwitch_3_CurrentSetting;
                            /* Computed Parameter: ManualSwitch_3_CurrentSetting
                             * Referenced by: '<Root>/Manual Switch'
                             */
  uint8_T ManualSwitch_2_CurrentSetting;
                            /* Computed Parameter: ManualSwitch_2_CurrentSetting
                             * Referenced by: '<Root>/Manual Switch'
                             */
  uint8_T ManualSwitch_1_CurrentSetting;
                            /* Computed Parameter: ManualSwitch_1_CurrentSetting
                             * Referenced by: '<Root>/Manual Switch'
                             */
  uint8_T RateTransition_InitialCondition;
                          /* Computed Parameter: RateTransition_InitialCondition
                           * Referenced by: '<Root>/Rate Transition'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_loaddspace_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_loaddspace_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[21];
  real_T odeF[4][21];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[5];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[6];
  } Timing;
};

/* Block parameters (default storage) */
extern P_loaddspace_T loaddspace_P;

/* Block signals (default storage) */
extern B_loaddspace_T loaddspace_B;

/* Continuous states (default storage) */
extern X_loaddspace_T loaddspace_X;

/* Block states (default storage) */
extern DW_loaddspace_T loaddspace_DW;

/* Model entry point functions */
extern void loaddspace_initialize(void);
extern void loaddspace_output(void);
extern void loaddspace_update(void);
extern void loaddspace_terminate(void);

/* Real-time Model object */
extern RT_MODEL_loaddspace_T *const loaddspace_M;

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
 * '<Root>' : 'loaddspace'
 * '<S1>'   : 'loaddspace/AENEA '
 * '<S2>'   : 'loaddspace/ATTUATORI1'
 * '<S3>'   : 'loaddspace/ATTUATORI2'
 * '<S4>'   : 'loaddspace/Comandi al trim1'
 * '<S5>'   : 'loaddspace/DS2101_B1'
 * '<S6>'   : 'loaddspace/DS4201SER_INT_B1_C1_I1'
 * '<S7>'   : 'loaddspace/DS4201SER_SETUP_B1_C1'
 * '<S8>'   : 'loaddspace/DS4201SER_SETUP_B1_C2'
 * '<S9>'   : 'loaddspace/DS4201SER_SETUP_B1_C3'
 * '<S10>'  : 'loaddspace/DS4201SER_SETUP_B1_C4'
 * '<S11>'  : 'loaddspace/DS4201SER_TX_B1_C3'
 * '<S12>'  : 'loaddspace/DS4201SER_TX_B1_C4'
 * '<S13>'  : 'loaddspace/Function-Call Subsystem'
 * '<S14>'  : 'loaddspace/Parametri Modello A//C'
 * '<S15>'  : 'loaddspace/RTI Data'
 * '<S16>'  : 'loaddspace/Radians to Degrees'
 * '<S17>'  : 'loaddspace/Radians to Degrees1'
 * '<S18>'  : 'loaddspace/SENSORI'
 * '<S19>'  : 'loaddspace/Subsystem1'
 * '<S20>'  : 'loaddspace/_DS4201SER_TX_B1_C2'
 * '<S21>'  : 'loaddspace/scalatura velocità'
 * '<S22>'  : 'loaddspace/AENEA /AENEA II_SITL1'
 * '<S23>'  : 'loaddspace/AENEA /Blocco_Costanti1'
 * '<S24>'  : 'loaddspace/AENEA /ISA Atmosphere Model'
 * '<S25>'  : 'loaddspace/AENEA /toSensors'
 * '<S26>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)'
 * '<S27>'  : 'loaddspace/AENEA /AENEA II_SITL1/Dynamic Pressure'
 * '<S28>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche'
 * '<S29>'  : 'loaddspace/AENEA /AENEA II_SITL1/Gear'
 * '<S30>'  : 'loaddspace/AENEA /AENEA II_SITL1/MATLAB Function'
 * '<S31>'  : 'loaddspace/AENEA /AENEA II_SITL1/Propulsione1'
 * '<S32>'  : 'loaddspace/AENEA /AENEA II_SITL1/Subsystem'
 * '<S33>'  : 'loaddspace/AENEA /AENEA II_SITL1/Subsystem1'
 * '<S34>'  : 'loaddspace/AENEA /AENEA II_SITL1/Velocità1'
 * '<S35>'  : 'loaddspace/AENEA /AENEA II_SITL1/Weight'
 * '<S36>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate DCM & Euler Angles'
 * '<S37>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot'
 * '<S38>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Determine Force,  Mass & Inertia'
 * '<S39>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Vbxw'
 * '<S40>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Velocity Conversion'
 * '<S41>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Velocity Conversion1'
 * '<S42>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Velocity Conversion2'
 * '<S43>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/transform to Inertial axes '
 * '<S44>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix'
 * '<S45>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate DCM & Euler Angles/phidot thetadot psidot'
 * '<S46>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S47>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product'
 * '<S48>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot/I x w'
 * '<S49>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot/I x w1'
 * '<S50>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem'
 * '<S51>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
 * '<S52>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Vbxw/Subsystem'
 * '<S53>'  : 'loaddspace/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Vbxw/Subsystem1'
 * '<S54>'  : 'loaddspace/AENEA /AENEA II_SITL1/Dynamic Pressure/dot'
 * '<S55>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q'
 * '<S56>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/MATLAB Function'
 * '<S57>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din'
 * '<S58>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem'
 * '<S59>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem1'
 * '<S60>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem2'
 * '<S61>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem1/controllo divisione per zero Yp '
 * '<S62>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem1/controllo divisione per zero Yr'
 * '<S63>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem2/controllo divisione per zero Lq '
 * '<S64>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem3'
 * '<S65>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem4'
 * '<S66>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem5'
 * '<S67>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem3/controllo divisione per zero lp '
 * '<S68>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem3/controllo divisione per zero lr '
 * '<S69>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem4/controllo divisione per zero mq '
 * '<S70>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem5/controllo divisione per zero np '
 * '<S71>'  : 'loaddspace/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem5/controllo divisione per zero nr '
 * '<S72>'  : 'loaddspace/AENEA /AENEA II_SITL1/Gear/MATLAB Function'
 * '<S73>'  : 'loaddspace/AENEA /AENEA II_SITL1/Gear/MATLAB Function2'
 * '<S74>'  : 'loaddspace/AENEA /AENEA II_SITL1/Propulsione1/Compare To Constant'
 * '<S75>'  : 'loaddspace/AENEA /AENEA II_SITL1/Propulsione1/LUT ELICA '
 * '<S76>'  : 'loaddspace/AENEA /AENEA II_SITL1/Propulsione1/Subsystem1'
 * '<S77>'  : 'loaddspace/AENEA /AENEA II_SITL1/Velocità1/MATLAB Function'
 * '<S78>'  : 'loaddspace/AENEA /AENEA II_SITL1/Velocità1/controllo divisione per 0 su alpha'
 * '<S79>'  : 'loaddspace/AENEA /AENEA II_SITL1/Velocità1/controllo divisione per 0 su beta'
 * '<S80>'  : 'loaddspace/AENEA /toSensors/Calc_GS'
 * '<S81>'  : 'loaddspace/AENEA /toSensors/Calc_heading'
 * '<S82>'  : 'loaddspace/AENEA /toSensors/MATLAB Function'
 * '<S83>'  : 'loaddspace/AENEA /toSensors/To_Lat_Long_MSL'
 * '<S84>'  : 'loaddspace/AENEA /toSensors/To_Lat_Long_MSL/Latitude Bound'
 * '<S85>'  : 'loaddspace/AENEA /toSensors/To_Lat_Long_MSL/Longitude Bound'
 * '<S86>'  : 'loaddspace/AENEA /toSensors/To_Lat_Long_MSL/Radius at Geocentric Latitude'
 * '<S87>'  : 'loaddspace/AENEA /toSensors/To_Lat_Long_MSL/Radius at Geocentric Latitude/Conversion'
 * '<S88>'  : 'loaddspace/Function-Call Subsystem/DS4201SER_TX_B1_C1'
 * '<S89>'  : 'loaddspace/RTI Data/RTI Data Store'
 * '<S90>'  : 'loaddspace/RTI Data/RTI Data Store/RTI Data Store'
 * '<S91>'  : 'loaddspace/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S92>'  : 'loaddspace/SENSORI/DS4201SER_RX_B1_C3'
 * '<S93>'  : 'loaddspace/SENSORI/Enabled Subsystem'
 * '<S94>'  : 'loaddspace/SENSORI/GPS Venus'
 * '<S95>'  : 'loaddspace/SENSORI/ISA Atmosphere Model'
 * '<S96>'  : 'loaddspace/SENSORI/Pressure Altitude'
 * '<S97>'  : 'loaddspace/SENSORI/Radians to Degrees1'
 * '<S98>'  : 'loaddspace/SENSORI/Radians to Degrees10'
 * '<S99>'  : 'loaddspace/SENSORI/Radians to Degrees2'
 * '<S100>' : 'loaddspace/SENSORI/Radians to Degrees3'
 * '<S101>' : 'loaddspace/SENSORI/Radians to Degrees4'
 * '<S102>' : 'loaddspace/SENSORI/Radians to Degrees9'
 * '<S103>' : 'loaddspace/SENSORI/Subsystem'
 * '<S104>' : 'loaddspace/SENSORI/Subsystem1'
 * '<S105>' : 'loaddspace/SENSORI/trasformazione quota earth-body'
 * '<S106>' : 'loaddspace/SENSORI/Pressure Altitude/Length Conversion'
 * '<S107>' : 'loaddspace/SENSORI/Pressure Altitude/Pressure Conversion'
 * '<S108>' : 'loaddspace/SENSORI/Subsystem1/Subsystem'
 * '<S109>' : 'loaddspace/SENSORI/Subsystem1/Subsystem1'
 * '<S110>' : 'loaddspace/SENSORI/Subsystem1/Subsystem2'
 * '<S111>' : 'loaddspace/SENSORI/Subsystem1/Subsystem2/0-2pi Wrapper'
 * '<S112>' : 'loaddspace/Subsystem1/AILERON'
 * '<S113>' : 'loaddspace/Subsystem1/DS4002PWMTOD'
 * '<S114>' : 'loaddspace/Subsystem1/DS4002PWMTOD1'
 * '<S115>' : 'loaddspace/Subsystem1/DS4002PWMTOD2'
 * '<S116>' : 'loaddspace/Subsystem1/DS4002PWMTOD3'
 * '<S117>' : 'loaddspace/Subsystem1/Degrees to Radians'
 * '<S118>' : 'loaddspace/Subsystem1/Degrees to Radians1'
 * '<S119>' : 'loaddspace/Subsystem1/Degrees to Radians2'
 * '<S120>' : 'loaddspace/Subsystem1/ELEVATOR'
 * '<S121>' : 'loaddspace/Subsystem1/RUDDER'
 * '<S122>' : 'loaddspace/Subsystem1/THROTTLE'
 * '<S123>' : 'loaddspace/Subsystem1/AILERON/MATLAB Function'
 * '<S124>' : 'loaddspace/Subsystem1/ELEVATOR/MATLAB Function'
 * '<S125>' : 'loaddspace/Subsystem1/RUDDER/MATLAB Function'
 * '<S126>' : 'loaddspace/scalatura velocità/MATLAB Function'
 * '<S127>' : 'loaddspace/scalatura velocità/Protezione sovratensione'
 * '<S128>' : 'loaddspace/scalatura velocità/deltaP_to_Volt'
 */
#endif                                 /* RTW_HEADER_loaddspace_h_ */
