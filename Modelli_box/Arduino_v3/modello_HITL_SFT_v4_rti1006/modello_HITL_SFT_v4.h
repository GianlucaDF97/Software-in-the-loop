/*
 * modello_HITL_SFT_v4.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modello_HITL_SFT_v4".
 *
 * Model version              : 5.53
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 *
 */

#ifndef RTW_HEADER_modello_HITL_SFT_v4_h_
#define RTW_HEADER_modello_HITL_SFT_v4_h_
#include <string.h>
#include <math.h>
#include <float.h>
#ifndef modello_HITL_SFT_v4_COMMON_INCLUDES_
#define modello_HITL_SFT_v4_COMMON_INCLUDES_
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
#endif                                /* modello_HITL_SFT_v4_COMMON_INCLUDES_ */

#include "modello_HITL_SFT_v4_types.h"

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

/* Block signals for system '<S88>/MATLAB Function' */
typedef struct {
  real_T K;                            /* '<S88>/MATLAB Function' */
  real_T C;                            /* '<S88>/MATLAB Function' */
} B_MATLABFunction_modello_HITL_SFT_v4_T;

/* Block signals (default storage) */
typedef struct {
  real_T ubvbwb[3];                    /* '<S26>/ub,vb,wb' */
  real_T UnitConversion[3];            /* '<S40>/Unit Conversion' */
  real_T Va[3];                        /* '<S34>/Sum2' */
  real_T Switch1;                      /* '<S127>/Switch1' */
  real_T m_deltaP_to_volt;             /* '<S128>/m_deltaP_to_volt' */
  real_T Sum;                          /* '<S128>/Sum' */
  real_T Gain;                         /* '<S21>/Gain' */
  real_T White_press;                  /* '<S19>/White_press' */
  real_T PositionIntegrator2[3];       /* '<S83>/Position Integrator2' */
  real_T Limitaltitudetotroposhere;/* '<S109>/Limit  altitude  to troposhere' */
  real_T LapseRate;                    /* '<S109>/Lapse Rate' */
  real_T Sum1;                         /* '<S109>/Sum1' */
  real_T uT0;                          /* '<S109>/1//T0' */
  real_T TT0gLR;                       /* '<S109>/(T//T0)^(g//LR) ' */
  real_T P0;                           /* '<S109>/P0' */
  real_T Sum_k;                        /* '<S109>/Sum' */
  real_T LimitaltitudetoStratosphere;
                                 /* '<S109>/Limit  altitude  to Stratosphere' */
  real_T gR;                           /* '<S109>/g//R' */
  real_T Product1;                     /* '<S109>/Product1' */
  real_T StratosphereModel;            /* '<S109>/Stratosphere Model' */
  real_T Product2;                     /* '<S109>/Product2' */
  real_T RateTransition;               /* '<S19>/Rate Transition' */
  real_T Sum13;                        /* '<S19>/Sum13' */
  real_T uDLookupTable;                /* '<S19>/1-D Lookup Table' */
  real_T WhiteNoise4;                  /* '<S19>/White Noise4' */
  real_T phithetapsi[3];               /* '<S36>/phi theta psi' */
  real_T h_ground;                     /* '<S19>/Byte Unpack' */
  real_T Sum_l;                        /* '<S19>/Sum' */
  real_T Gain_n;                       /* '<S19>/Gain' */
  real_T Saturation3;                  /* '<S19>/Saturation3' */
  real_T Sum14;                        /* '<S19>/Sum14' */
  real_T RateTransition1;              /* '<S19>/Rate Transition1' */
  real_T RateTransition2;              /* '<S19>/Rate Transition2' */
  real_T MathFunction;                 /* '<S19>/Math Function' */
  real_T Gain3;                        /* '<S19>/Gain3' */
  real_T Divide;                       /* '<S19>/Divide' */
  real_T Gain4;                        /* '<S19>/Gain4' */
  real_T Sum2;                         /* '<S85>/Sum2' */
  real_T MathFunction_o;               /* '<S85>/Math Function' */
  real_T Sum1_f;                       /* '<S85>/Sum1' */
  real_T Gain_h;                       /* '<S17>/Gain' */
  real_T Sum2_o;                       /* '<S84>/Sum2' */
  real_T MathFunction_l;               /* '<S84>/Math Function' */
  real_T Sum1_i;                       /* '<S84>/Sum1' */
  real_T ChSign;                       /* '<S84>/ChSign' */
  real_T MathFunction1;                /* '<S84>/Math Function1' */
  real_T Switch;                       /* '<S84>/Switch' */
  real_T Gain_f;                       /* '<S18>/Gain' */
  real_T TmpSignalConversionAtSFunctionBuilder1Inport1[6];/* '<Root>/Mux' */
  real_T DiscreteTimeIntegrator;       /* '<S122>/Discrete-Time Integrator' */
  real_T Sum1_e;                       /* '<S122>/Sum1' */
  real_T ZeroOrderHold;                /* '<S118>/Zero-Order Hold' */
  real_T Gain_g;                       /* '<S113>/Gain' */
  real_T DiscreteTimeIntegrator_f;     /* '<S123>/Discrete-Time Integrator' */
  real_T Sum1_p;                       /* '<S123>/Sum1' */
  real_T ZeroOrderHold1;               /* '<S118>/Zero-Order Hold1' */
  real_T Gain_fx;                      /* '<S114>/Gain' */
  real_T TmpSignalConversionAtsincosInport1[3];/* '<S44>/In1' */
  real_T sincos_o1[3];                 /* '<S44>/sincos' */
  real_T sincos_o2[3];                 /* '<S44>/sincos' */
  real_T VectorConcatenate[9];         /* '<S46>/Vector Concatenate' */
  real_T Reshape9to3x3columnmajor[9];
                                 /* '<S46>/Reshape (9) to [3x3] column-major' */
  real_T Transpose[9];                 /* '<S26>/Transpose' */
  real_T Reshape1[3];                  /* '<S43>/Reshape1' */
  real_T Product[3];                   /* '<S43>/Product' */
  real_T Reshape2[3];                  /* '<S43>/Reshape2' */
  real_T UnitConversion_g[3];          /* '<S41>/Unit Conversion' */
  real_T Square2;                      /* '<S80>/Square2' */
  real_T Square1;                      /* '<S80>/Square1' */
  real_T Add;                          /* '<S80>/Add' */
  real_T Sqrt;                         /* '<S80>/Sqrt' */
  real_T ZeroOrderHold2;               /* '<S124>/Zero-Order Hold2' */
  real_T NoiseV_hor;                   /* '<S124>/Noise V_hor' */
  real_T noiseterraV_hor1;             /* '<S124>/noise terra V_hor1' */
  real_T Abs;                          /* '<S124>/Abs' */
  real_T Switch4;                      /* '<S124>/Switch4' */
  real_T Sum5;                         /* '<S124>/Sum5' */
  real_T ZeroOrderHold4;               /* '<S118>/Zero-Order Hold4' */
  real_T Gain5;                        /* '<S19>/Gain5' */
  real_T Atan2;                        /* '<S81>/Atan2' */
  real_T ZeroOrderHold_d;              /* '<S124>/Zero-Order Hold' */
  real_T Rumorebianco;                 /* '<S124>/Rumore bianco' */
  real_T Divide2;                      /* '<S124>/Divide2' */
  real_T Multiply5;                    /* '<S124>/Multiply5' */
  real_T Noiseterracourse;             /* '<S124>/Noise terra course' */
  real_T Switch3;                      /* '<S124>/Switch3' */
  real_T Course_sporco;                /* '<S124>/Add' */
  real_T Switch1_a;                    /* '<S124>/Switch1' */
  real_T ZeroOrderHold5;               /* '<S118>/Zero-Order Hold5' */
  real_T Gain_m;                       /* '<S111>/Gain' */
  real_T ZeroOrderHold6;               /* '<S118>/Zero-Order Hold6' */
  real_T u;                            /* '<S34>/Trigonometric Function1' */
  real_T u_n;                          /* '<S34>/Trigonometric Function2' */
  real_T uDLookupTable_n;              /* '<S58>/2-D Lookup Table' */
  real_T Sum1_fc;                      /* '<S58>/Sum1' */
  real_T CD;                           /* '<S55>/Gain4' */
  real_T uDLookupTable_e;              /* '<S59>/2-D Lookup Table' */
  real_T Saturation;                   /* '<S59>/Saturation' */
  real_T pqr[3];                       /* '<S26>/p,q,r ' */
  real_T Timone;                       /* '<S2>/State-Space2' */
  real_T deltaR;                       /* '<S2>/Saturation3' */
  real_T Timone_l;                     /* '<S3>/State-Space2' */
  real_T deltaR_i;                     /* '<S3>/Saturation3' */
  real_T deltaR_d;                     /* '<Root>/Switch' */
  real_T Product_f;                    /* '<S59>/Product' */
  real_T Alettoni;                     /* '<S2>/State-Space1' */
  real_T deltaA;                       /* '<S2>/Saturation2' */
  real_T Alettoni_p;                   /* '<S3>/State-Space1' */
  real_T deltaA_g;                     /* '<S3>/Saturation2' */
  real_T deltaA_gw;                    /* '<Root>/Switch' */
  real_T Product3;                     /* '<S59>/Product3' */
  real_T Sum_o;                        /* '<S59>/Sum' */
  real_T uDLookupTable_g;              /* '<S60>/2-D Lookup Table' */
  real_T Gain1;                        /* '<S60>/Gain1' */
  real_T Equilibratore;                /* '<S2>/State-Space' */
  real_T deltaE;                       /* '<S2>/Saturation1' */
  real_T Equilibratore_n;              /* '<S3>/State-Space' */
  real_T deltaE_h;                     /* '<S3>/Saturation1' */
  real_T deltaE_k;                     /* '<Root>/Switch' */
  real_T Product4;                     /* '<S60>/Product4' */
  real_T Sum_h;                        /* '<S60>/Sum' */
  real_T CL;                           /* '<S55>/Gain5' */
  real_T TmpSignalConversionAtMatrixMultiplyInport2[3];/* '<S28>/Forze assi vento//q' */
  real_T FA_Bq[3];                     /* '<S28>/Matrix Multiply' */
  real_T Product_j;                    /* '<S54>/Product' */
  real_T Product1_i;                   /* '<S54>/Product1' */
  real_T Product2_k;                   /* '<S54>/Product2' */
  real_T Sum_e;                        /* '<S54>/Sum' */
  real_T xeyeze[3];                    /* '<S26>/xe,ye,ze' */
  real_T Gain_a;                       /* '<S1>/Gain' */
  real_T Limitaltitudetotroposhere_n;
                                    /* '<S24>/Limit  altitude  to troposhere' */
  real_T LapseRate_f;                  /* '<S24>/Lapse Rate' */
  real_T Sum1_b;                       /* '<S24>/Sum1' */
  real_T uT0_m;                        /* '<S24>/1//T0' */
  real_T TT0gLR_m;                     /* '<S24>/(T//T0)^(g//LR) ' */
  real_T Product_d;                    /* '<S24>/Product' */
  real_T rho0;                         /* '<S24>/rho0' */
  real_T Sum_d;                        /* '<S24>/Sum' */
  real_T LimitaltitudetoStratosphere_e;
                                  /* '<S24>/Limit  altitude  to Stratosphere' */
  real_T gR_a;                         /* '<S24>/g//R' */
  real_T Product1_j;                   /* '<S24>/Product1' */
  real_T StratosphereModel_e;          /* '<S24>/Stratosphere Model' */
  real_T Product3_c;                   /* '<S24>/Product3' */
  real_T Product2_c;                   /* '<S27>/Product2' */
  real_T u2rhoV2;                      /* '<S27>/1//2rhoV^2' */
  real_T Product_jt[3];                /* '<S28>/Product' */
  real_T uDLookupTable_h;              /* '<S64>/2-D Lookup Table' */
  real_T Gain4_p;                      /* '<S64>/Gain4' */
  real_T Product2_d;                   /* '<S64>/Product2' */
  real_T Product3_f;                   /* '<S64>/Product3' */
  real_T Sum_p;                        /* '<S64>/Sum' */
  real_T Cl;                           /* '<S57>/Product' */
  real_T uDLookupTable_d;              /* '<S65>/2-D Lookup Table' */
  real_T Gain1_h;                      /* '<S65>/Gain1' */
  real_T Product2_kw;                  /* '<S65>/Product2' */
  real_T Sum_g;                        /* '<S65>/Sum' */
  real_T Cm;                           /* '<S57>/Product1' */
  real_T uDLookupTable_l;              /* '<S66>/2-D Lookup Table' */
  real_T Product2_m;                   /* '<S66>/Product2' */
  real_T Product3_fd;                  /* '<S66>/Product3' */
  real_T Sum_lc;                       /* '<S66>/Sum' */
  real_T Cn;                           /* '<S57>/Product3' */
  real_T Product2_f[3];                /* '<S28>/Product2' */
  real_T Product3_j[3];                /* '<S35>/Product3' */
  real_T UnitDelay;                    /* '<S31>/Unit Delay' */
  real_T RPMRPs;                       /* '<S31>/RPM->RPs' */
  real_T MathFunction3;                /* '<S31>/Math Function3' */
  real_T MathFunction_g;               /* '<S31>/Math Function' */
  real_T Product1_d;                   /* '<S31>/Product1' */
  real_T uDLookupTable_et;             /* '<S75>/2-D Lookup Table' */
  real_T Product2_h;                   /* '<S31>/Product2' */
  real_T F[3];                         /* '<S22>/Sum' */
  real_T sincos_o1_p[3];               /* '<S45>/sincos' */
  real_T sincos_o2_m[3];               /* '<S45>/sincos' */
  real_T phidot;                       /* '<S45>/phidot' */
  real_T thetadot;                     /* '<S45>/thetadot' */
  real_T psidot;                       /* '<S45>/psidot' */
  real_T TmpSignalConversionAtphithetapsiInport1[3];/* '<S36>/phidot thetadot psidot' */
  real_T VectorConcatenate_i[18];      /* '<S38>/Vector Concatenate' */
  real_T Selector[9];                  /* '<S37>/Selector' */
  real_T Reshape1_k[3];                /* '<S48>/Reshape1' */
  real_T Product_l[3];                 /* '<S48>/Product' */
  real_T Reshape2_d[3];                /* '<S48>/Reshape2' */
  real_T ixj;                          /* '<S50>/i x j' */
  real_T jxk;                          /* '<S50>/j x k' */
  real_T kxi;                          /* '<S50>/k x i' */
  real_T ixk;                          /* '<S51>/i x k' */
  real_T jxi;                          /* '<S51>/j x i' */
  real_T kxj;                          /* '<S51>/k x j' */
  real_T Sum_n[3];                     /* '<S47>/Sum' */
  real_T Selector1[9];                 /* '<S37>/Selector1' */
  real_T Reshape1_d[3];                /* '<S49>/Reshape1' */
  real_T Product_jg[3];                /* '<S49>/Product' */
  real_T Reshape2_o[3];                /* '<S49>/Reshape2' */
  real_T uDLookupTable1;               /* '<S75>/2-D Lookup Table1' */
  real_T MathFunction2;                /* '<S31>/Math Function2' */
  real_T MathFunction1_h;              /* '<S31>/Math Function1' */
  real_T Product3_o;                   /* '<S31>/Product3' */
  real_T Gain_a3;                      /* '<S76>/Gain' */
  real_T Divide_e;                     /* '<S76>/Divide' */
  real_T Gain1_b;                      /* '<S76>/Gain1' */
  real_T Divide1;                      /* '<S76>/Divide1' */
  real_T Sum1_n[3];                    /* '<S22>/Sum1' */
  real_T DiscreteTimeIntegrator_p;     /* '<S19>/Discrete-Time Integrator' */
  real_T Switch_g;                     /* '<S19>/Switch' */
  real_T Sum3[3];                      /* '<S22>/Sum3' */
  real_T Sum2_m[3];                    /* '<S37>/Sum2' */
  real_T Reshape1_m[3];                /* '<S37>/Reshape1' */
  real_T Selector2[9];                 /* '<S37>/Selector2' */
  real_T Product2_l[3];                /* '<S37>/Product2' */
  real_T Reshape[3];                   /* '<S37>/Reshape' */
  real_T F_m[3];                       /* '<S22>/Sum2' */
  real_T Product_m[3];                 /* '<S26>/Product' */
  real_T jxk_d;                        /* '<S52>/j x k' */
  real_T kxi_o;                        /* '<S52>/k x i' */
  real_T ixj_o;                        /* '<S52>/i x j' */
  real_T kxj_j;                        /* '<S53>/k x j' */
  real_T ixk_p;                        /* '<S53>/i x k' */
  real_T jxi_k;                        /* '<S53>/j x i' */
  real_T Sum_a[3];                     /* '<S39>/Sum' */
  real_T Sum_h2[3];                    /* '<S26>/Sum' */
  real_T UnitConversion_m;             /* '<S42>/Unit Conversion' */
  real_T Gain1_k;                      /* '<S22>/Gain1' */
  real_T Product_c;                    /* '<S22>/Product' */
  real_T Product1_l[3];                /* '<S22>/Product1' */
  real_T Gain_c;                       /* '<S31>/Gain' */
  real_T SFunction_o1;                 /* '<S89>/S-Function' */
  real_T SFunction_o2;                 /* '<S89>/S-Function' */
  real_T Divide_a;                     /* '<S5>/Divide' */
  real_T Gain_o;                       /* '<S5>/Gain' */
  real_T Gain1_g;                      /* '<S98>/Gain1' */
  real_T Sum2_g;                       /* '<S98>/Sum2' */
  real_T Manetta;                      /* '<Root>/Switch' */
  real_T Saturation_b;                 /* '<S31>/Saturation' */
  real_T LUTMOTORE;                    /* '<S31>/LUT MOTORE' */
  real_T Fcn;                          /* '<S31>/Fcn' */
  real_T RPsrads;                      /* '<S31>/RPs->rad//s' */
  real_T u_h;                          /* '<S22>/Trigonometric Function' */
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
  real_T P0_n;                         /* '<S24>/P0' */
  real_T Product2_fr;                  /* '<S24>/Product2' */
  real_T gammaR;                       /* '<S24>/gamma*R' */
  real_T a;                            /* '<S24>/a' */
  real_T Product_k[3];                 /* '<S25>/Product' */
  real_T Sum1_d[3];                    /* '<S25>/Sum1' */
  real_T Sum_dn[3];                    /* '<S25>/Sum' */
  real_T Gain_fl;                      /* '<S83>/Gain' */
  real_T UnitConversion_gt;            /* '<S87>/Unit Conversion' */
  real_T Sum_i;                        /* '<S86>/Sum' */
  real_T Product4_p;                   /* '<S86>/Product4' */
  real_T Product1_o;                   /* '<S86>/Product1' */
  real_T TrigonometricFunction;        /* '<S86>/Trigonometric Function' */
  real_T Sum1_a;                       /* '<S86>/Sum1' */
  real_T Product2_i;                   /* '<S86>/Product2' */
  real_T Sum2_e;                       /* '<S86>/Sum2' */
  real_T Product3_p;                   /* '<S86>/Product3' */
  real_T sqrt_n;                       /* '<S86>/sqrt' */
  real_T Sum_j;                        /* '<S83>/Sum' */
  real_T Sum1_ba;                      /* '<S83>/Sum1' */
  real_T VnRmh;                        /* '<S83>/Vn//(Rm+h)' */
  real_T cosphi;                       /* '<S83>/cos(phi)' */
  real_T VeRnhcosphi;                  /* '<S83>/Ve//(Rn+h)cos(phi)' */
  real_T TmpSignalConversionAtPositionIntegrator2Inport1[3];/* '<S83>/Mux' */
  real_T SFunction_o1_j;               /* '<S90>/S-Function' */
  real_T SFunction_o2_i;               /* '<S90>/S-Function' */
  real_T Divide1_k;                    /* '<S5>/Divide1' */
  real_T Gain1_hj;                     /* '<S5>/Gain1' */
  real_T Product_e;                    /* '<S96>/Product' */
  real_T Add_b;                        /* '<S96>/Add' */
  real_T Gain1_n;                      /* '<S93>/Gain1' */
  real_T SFunction_o1_k;               /* '<S91>/S-Function' */
  real_T SFunction_o2_l;               /* '<S91>/S-Function' */
  real_T Divide2_c;                    /* '<S5>/Divide2' */
  real_T Gain2;                        /* '<S5>/Gain2' */
  real_T Product_m4;                   /* '<S88>/Product' */
  real_T Add_m;                        /* '<S88>/Add' */
  real_T Gain1_m;                      /* '<S95>/Gain1' */
  real_T SFunction_o1_c;               /* '<S92>/S-Function' */
  real_T SFunction_o2_d;               /* '<S92>/S-Function' */
  real_T Divide3;                      /* '<S5>/Divide3' */
  real_T Gain3_c;                      /* '<S5>/Gain3' */
  real_T Product_g;                    /* '<S97>/Product' */
  real_T Add_h;                        /* '<S97>/Add' */
  real_T Gain1_gb;                     /* '<S94>/Gain1' */
  real_T DiscreteTimeIntegrator3;      /* '<S117>/Discrete-Time Integrator3' */
  real_T Sum12;                        /* '<S117>/Sum12' */
  real_T ZeroOrderHold9;               /* '<S117>/Zero-Order Hold9' */
  real_T Gain_k;                       /* '<S116>/Gain' */
  real_T Saturation5;                  /* '<S19>/Saturation5' */
  real_T DiscreteTimeIntegrator4;      /* '<S117>/Discrete-Time Integrator4' */
  real_T Sum16;                        /* '<S117>/Sum16' */
  real_T ZeroOrderHold10;              /* '<S117>/Zero-Order Hold10' */
  real_T Gain_l;                       /* '<S112>/Gain' */
  real_T Saturation6;                  /* '<S19>/Saturation6' */
  real_T DiscreteTimeIntegrator5;      /* '<S117>/Discrete-Time Integrator5' */
  real_T Sum18;                        /* '<S117>/Sum18' */
  real_T ZeroOrderHold11;              /* '<S117>/Zero-Order Hold11' */
  real_T Gain_b;                       /* '<S115>/Gain' */
  real_T Saturation4;                  /* '<S19>/Saturation4' */
  real_T RandomNumber6;                /* '<S117>/Random Number6' */
  real_T Sum23;                        /* '<S117>/Sum23' */
  real_T ZeroOrderHold15;              /* '<S117>/Zero-Order Hold15' */
  real_T RandomNumber7;                /* '<S117>/Random Number7' */
  real_T Sum14_c;                      /* '<S117>/Sum14' */
  real_T ZeroOrderHold16;              /* '<S117>/Zero-Order Hold16' */
  real_T RandomNumber8;                /* '<S117>/Random Number8' */
  real_T Sum15;                        /* '<S117>/Sum15' */
  real_T ZeroOrderHold17;              /* '<S117>/Zero-Order Hold17' */
  real_T RandomNumber3;                /* '<S117>/Random Number3' */
  real_T Sum20;                        /* '<S117>/Sum20' */
  real_T ZeroOrderHold12;              /* '<S117>/Zero-Order Hold12' */
  real_T RandomNumber4;                /* '<S117>/Random Number4' */
  real_T Sum21;                        /* '<S117>/Sum21' */
  real_T ZeroOrderHold13;              /* '<S117>/Zero-Order Hold13' */
  real_T RandomNumber5;                /* '<S117>/Random Number5' */
  real_T Sum22;                        /* '<S117>/Sum22' */
  real_T ZeroOrderHold14;              /* '<S117>/Zero-Order Hold14' */
  real_T Product_a;                    /* '<S109>/Product' */
  real_T rho0_m;                       /* '<S109>/rho0' */
  real_T Product3_cn;                  /* '<S109>/Product3' */
  real_T gammaR_f;                     /* '<S109>/gamma*R' */
  real_T a_b;                          /* '<S109>/a' */
  real_T UnitConversion_gp;            /* '<S121>/Unit Conversion' */
  real_T SFunction;                    /* '<S110>/S-Function' */
  real_T UnitConversion_ge;            /* '<S120>/Unit Conversion' */
  real_T Gain3_f;                      /* '<S117>/Gain3' */
  real_T RandomNumber;                 /* '<S117>/Random Number' */
  real_T Sum13_a;                      /* '<S117>/Sum13' */
  real_T Gain4_k;                      /* '<S117>/Gain4' */
  real_T RandomNumber1;                /* '<S117>/Random Number1' */
  real_T Sum17;                        /* '<S117>/Sum17' */
  real_T Gain5_a;                      /* '<S117>/Gain5' */
  real_T RandomNumber2;                /* '<S117>/Random Number2' */
  real_T Sum19;                        /* '<S117>/Sum19' */
  real_T Gain_l4;                      /* '<S122>/Gain' */
  real_T WhiteNoiseLat;                /* '<S122>/White Noise Lat' */
  real_T Sum_gh;                       /* '<S122>/Sum' */
  real_T Gain_ai;                      /* '<S123>/Gain' */
  real_T WhiteNoise;                   /* '<S123>/White Noise' */
  real_T Sum_ic;                       /* '<S123>/Sum' */
  real_T Cos1;                         /* '<S124>/Cos1' */
  real_T V_n;                          /* '<S124>/Multiply6' */
  real_T Sin1;                         /* '<S124>/Sin1' */
  real_T V_e;                          /* '<S124>/Multiply7' */
  real_T ZeroOrderHold2_m;             /* '<S118>/Zero-Order Hold2' */
  real_T ZeroOrderHold3;               /* '<S118>/Zero-Order Hold3' */
  real_T deltaP;                       /* '<S21>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctionInport4[3];
                                   /* '<S19>/trasformazione quota earth-body' */
  real_T h_lidar;                  /* '<S19>/trasformazione quota earth-body' */
  real_T y;                            /* '<S124>/0-2pi Wrapper' */
  real_T K;                            /* '<S96>/MATLAB Function' */
  real_T C;                            /* '<S96>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctionInport1[6];/* '<S25>/MATLAB Function' */
  real_T y_p[3];                       /* '<S25>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctionInport1_n[2];
                                 /* '<S34>/controllo divisione per 0 su beta' */
  real_T y_m;                    /* '<S34>/controllo divisione per 0 su beta' */
  real_T TmpSignalConversionAtSFunctionInport1_ny[2];
                                /* '<S34>/controllo divisione per 0 su alpha' */
  real_T y_j;                   /* '<S34>/controllo divisione per 0 su alpha' */
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
  real_T TmpSignalConversionAtSFunctionInport1_b[4];
                                  /* '<S66>/controllo divisione per zero nr ' */
  real_T y_c;                     /* '<S66>/controllo divisione per zero nr ' */
  real_T TmpSignalConversionAtSFunctionInport1_a[4];
                                  /* '<S66>/controllo divisione per zero np ' */
  real_T y_l;                     /* '<S66>/controllo divisione per zero np ' */
  real_T TmpSignalConversionAtSFunctionInport1_k[4];
                                  /* '<S65>/controllo divisione per zero mq ' */
  real_T y_g;                     /* '<S65>/controllo divisione per zero mq ' */
  real_T TmpSignalConversionAtSFunctionInport1_c[4];
                                  /* '<S64>/controllo divisione per zero lr ' */
  real_T y_o;                     /* '<S64>/controllo divisione per zero lr ' */
  real_T TmpSignalConversionAtSFunctionInport1_n4[4];
                                  /* '<S64>/controllo divisione per zero lp ' */
  real_T y_k;                     /* '<S64>/controllo divisione per zero lp ' */
  real_T Lbw[9];                       /* '<S28>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctionInport1_p[4];
                                  /* '<S60>/controllo divisione per zero Lq ' */
  real_T y_g1;                    /* '<S60>/controllo divisione per zero Lq ' */
  real_T TmpSignalConversionAtSFunctionInport1_ks[4];
                                   /* '<S59>/controllo divisione per zero Yr' */
  real_T y_b;                      /* '<S59>/controllo divisione per zero Yr' */
  real_T TmpSignalConversionAtSFunctionInport1_g[4];
                                  /* '<S59>/controllo divisione per zero Yp ' */
  real_T y_gq;                    /* '<S59>/controllo divisione per zero Yp ' */
  uint32_T SFunctionBuilder1_o2;       /* '<Root>/S-Function Builder1' */
  uint32_T SFunction1_o1;              /* '<S12>/S-Function1' */
  real32_T DataTypeConversion[9];      /* '<S107>/Data Type Conversion' */
  real32_T SFunctionBuilder1_o3[9];    /* '<S107>/S-Function Builder1' */
  int32_T DataTypeConversion_l;        /* '<S19>/Data Type Conversion' */
  int32_T DataTypeConversion2;         /* '<S19>/Data Type Conversion2' */
  int32_T SFunction1_o2;               /* '<S12>/S-Function1' */
  int32_T SFunctionBuilder1_o2_o;      /* '<S107>/S-Function Builder1' */
  uint16_T DataTypeConversion1;        /* '<S19>/Data Type Conversion1' */
  uint8_T BytePack1[4];                /* '<S19>/Byte Pack1' */
  uint8_T SFunction1[8];               /* '<S106>/S-Function1' */
  uint8_T BytePack[2];                 /* '<S19>/Byte Pack' */
  uint8_T BytePack2[4];                /* '<S19>/Byte Pack2' */
  uint8_T SFunctionBuilder1_o1[64];    /* '<Root>/S-Function Builder1' */
  uint8_T SFunctionBuilder1[131];      /* '<S108>/S-Function Builder1' */
  uint8_T RateTransition_c[41];        /* '<Root>/Rate Transition' */
  uint8_T SFunctionBuilder1_o1_j[41];  /* '<S107>/S-Function Builder1' */
  boolean_T Compare;                   /* '<S74>/Compare' */
  B_MATLABFunction_modello_HITL_SFT_v4_T sf_MATLABFunction_o;/* '<S97>/MATLAB Function' */
  B_MATLABFunction_modello_HITL_SFT_v4_T sf_MATLABFunction_i;/* '<S88>/MATLAB Function' */
} B_modello_HITL_SFT_v4_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S122>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S123>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S31>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S19>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S117>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator4_DSTATE;/* '<S117>/Discrete-Time Integrator4' */
  real_T DiscreteTimeIntegrator5_DSTATE;/* '<S117>/Discrete-Time Integrator5' */
  real_T NextOutput;                   /* '<S19>/White_press' */
  real_T RateTransition_Buffer;        /* '<S19>/Rate Transition' */
  real_T NextOutput_p;                 /* '<S19>/White Noise4' */
  real_T RateTransition1_Buffer;       /* '<S19>/Rate Transition1' */
  real_T RateTransition2_Buffer;       /* '<S19>/Rate Transition2' */
  real_T NextOutput_c;                 /* '<S124>/Noise V_hor' */
  real_T NextOutput_m;                 /* '<S124>/noise terra V_hor1' */
  real_T NextOutput_d;                 /* '<S124>/Rumore bianco' */
  real_T NextOutput_c2;                /* '<S124>/Noise terra course' */
  real_T Product2_DWORK1[9];           /* '<S37>/Product2' */
  real_T Product2_DWORK3[9];           /* '<S37>/Product2' */
  real_T Product2_DWORK4[9];           /* '<S37>/Product2' */
  real_T Product2_DWORK5[9];           /* '<S37>/Product2' */
  real_T NextOutput_n;                 /* '<S117>/Random Number6' */
  real_T NextOutput_b;                 /* '<S117>/Random Number7' */
  real_T NextOutput_h;                 /* '<S117>/Random Number8' */
  real_T NextOutput_na;                /* '<S117>/Random Number3' */
  real_T NextOutput_o;                 /* '<S117>/Random Number4' */
  real_T NextOutput_a;                 /* '<S117>/Random Number5' */
  real_T SFunction_temp_table[8];      /* '<S110>/S-Function' */
  real_T SFunction_pres_table[8];      /* '<S110>/S-Function' */
  real_T NextOutput_i;                 /* '<S117>/Random Number' */
  real_T NextOutput_e;                 /* '<S117>/Random Number1' */
  real_T NextOutput_or;                /* '<S117>/Random Number2' */
  real_T NextOutput_as;                /* '<S122>/White Noise Lat' */
  real_T NextOutput_f;                 /* '<S123>/White Noise' */
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S22>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S22>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S55>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_j;                     /* '<S34>/Scope' */

  struct {
    void *LoggedData;
  } ciao_PWORK;                        /* '<S19>/ciao' */

  int32_T Product2_DWORK2[3];          /* '<S37>/Product2' */
  uint32_T RandSeed;                   /* '<S19>/White_press' */
  uint32_T RandSeed_i;                 /* '<S19>/White Noise4' */
  uint32_T RandSeed_f;                 /* '<S124>/Noise V_hor' */
  uint32_T RandSeed_j;                 /* '<S124>/noise terra V_hor1' */
  uint32_T RandSeed_d;                 /* '<S124>/Rumore bianco' */
  uint32_T RandSeed_h;                 /* '<S124>/Noise terra course' */
  uint32_T RandSeed_l;                 /* '<S117>/Random Number6' */
  uint32_T RandSeed_js;                /* '<S117>/Random Number7' */
  uint32_T RandSeed_hb;                /* '<S117>/Random Number8' */
  uint32_T RandSeed_e;                 /* '<S117>/Random Number3' */
  uint32_T RandSeed_le;                /* '<S117>/Random Number4' */
  uint32_T RandSeed_d0;                /* '<S117>/Random Number5' */
  uint32_T RandSeed_ej;                /* '<S117>/Random Number' */
  uint32_T RandSeed_ix;                /* '<S117>/Random Number1' */
  uint32_T RandSeed_n;                 /* '<S117>/Random Number2' */
  uint32_T RandSeed_o;                 /* '<S122>/White Noise Lat' */
  uint32_T RandSeed_ou;                /* '<S123>/White Noise' */
  volatile int8_T RateTransition_write_buf;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition_read_buf;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition_last_buf_wr;/* '<Root>/Rate Transition' */
  volatile uint8_T RateTransition_Buffer0[41];/* '<Root>/Rate Transition' */
  volatile uint8_T RateTransition_Buffer1[41];/* '<Root>/Rate Transition' */
} DW_modello_HITL_SFT_v4_T;

/* Continuous states (default storage) */
typedef struct {
  real_T ubvbwb_CSTATE[3];             /* '<S26>/ub,vb,wb' */
  real_T PositionIntegrator2_CSTATE[3];/* '<S83>/Position Integrator2' */
  real_T phithetapsi_CSTATE[3];        /* '<S36>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S26>/p,q,r ' */
  real_T StateSpace2_CSTATE;           /* '<S2>/State-Space2' */
  real_T StateSpace2_CSTATE_b;         /* '<S3>/State-Space2' */
  real_T StateSpace1_CSTATE;           /* '<S2>/State-Space1' */
  real_T StateSpace1_CSTATE_b;         /* '<S3>/State-Space1' */
  real_T StateSpace_CSTATE;            /* '<S2>/State-Space' */
  real_T StateSpace_CSTATE_p;          /* '<S3>/State-Space' */
  real_T xeyeze_CSTATE[3];             /* '<S26>/xe,ye,ze' */
} X_modello_HITL_SFT_v4_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_modello_HITL_SFT_v4_T[3];
typedef real_T PeriodicRngX_modello_HITL_SFT_v4_T[6];

/* State derivatives (default storage) */
typedef struct {
  real_T ubvbwb_CSTATE[3];             /* '<S26>/ub,vb,wb' */
  real_T PositionIntegrator2_CSTATE[3];/* '<S83>/Position Integrator2' */
  real_T phithetapsi_CSTATE[3];        /* '<S36>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S26>/p,q,r ' */
  real_T StateSpace2_CSTATE;           /* '<S2>/State-Space2' */
  real_T StateSpace2_CSTATE_b;         /* '<S3>/State-Space2' */
  real_T StateSpace1_CSTATE;           /* '<S2>/State-Space1' */
  real_T StateSpace1_CSTATE_b;         /* '<S3>/State-Space1' */
  real_T StateSpace_CSTATE;            /* '<S2>/State-Space' */
  real_T StateSpace_CSTATE_p;          /* '<S3>/State-Space' */
  real_T xeyeze_CSTATE[3];             /* '<S26>/xe,ye,ze' */
} XDot_modello_HITL_SFT_v4_T;

/* State disabled  */
typedef struct {
  boolean_T ubvbwb_CSTATE[3];          /* '<S26>/ub,vb,wb' */
  boolean_T PositionIntegrator2_CSTATE[3];/* '<S83>/Position Integrator2' */
  boolean_T phithetapsi_CSTATE[3];     /* '<S36>/phi theta psi' */
  boolean_T pqr_CSTATE[3];             /* '<S26>/p,q,r ' */
  boolean_T StateSpace2_CSTATE;        /* '<S2>/State-Space2' */
  boolean_T StateSpace2_CSTATE_b;      /* '<S3>/State-Space2' */
  boolean_T StateSpace1_CSTATE;        /* '<S2>/State-Space1' */
  boolean_T StateSpace1_CSTATE_b;      /* '<S3>/State-Space1' */
  boolean_T StateSpace_CSTATE;         /* '<S2>/State-Space' */
  boolean_T StateSpace_CSTATE_p;       /* '<S3>/State-Space' */
  boolean_T xeyeze_CSTATE[3];          /* '<S26>/xe,ye,ze' */
} XDis_modello_HITL_SFT_v4_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (default storage) */
struct P_modello_HITL_SFT_v4_T_ {
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
                                        * Referenced by: '<S124>/Std_vel'
                                        */
  real_T Ta_lat;                       /* Variable: Ta_lat
                                        * Referenced by: '<S122>/Gain'
                                        */
  real_T Ta_long;                      /* Variable: Ta_long
                                        * Referenced by: '<S123>/Gain'
                                        */
  real_T U0[4];                        /* Variable: U0
                                        * Referenced by:
                                        *   '<S4>/A'
                                        *   '<S4>/E'
                                        *   '<S4>/R'
                                        *   '<S4>/T'
                                        */
  real_T Var_V_hor_static;             /* Variable: Var_V_hor_static
                                        * Referenced by: '<S124>/noise terra V_hor1'
                                        */
  real_T Var_heading_static;           /* Variable: Var_heading_static
                                        * Referenced by: '<S124>/Noise terra course'
                                        */
  real_T W[3];                         /* Variable: W
                                        * Referenced by: '<S23>/W'
                                        */
  real_T White_ax;                     /* Variable: White_ax
                                        * Referenced by: '<S117>/Random Number3'
                                        */
  real_T White_ay;                     /* Variable: White_ay
                                        * Referenced by: '<S117>/Random Number4'
                                        */
  real_T White_az;                     /* Variable: White_az
                                        * Referenced by: '<S117>/Random Number5'
                                        */
  real_T White_gm_phi;                 /* Variable: White_gm_phi
                                        * Referenced by: '<S117>/Random Number'
                                        */
  real_T White_gm_psi;                 /* Variable: White_gm_psi
                                        * Referenced by: '<S117>/Random Number2'
                                        */
  real_T White_gm_theta;               /* Variable: White_gm_theta
                                        * Referenced by: '<S117>/Random Number1'
                                        */
  real_T White_p;                      /* Variable: White_p
                                        * Referenced by: '<S117>/Random Number6'
                                        */
  real_T White_pressione;              /* Variable: White_pressione
                                        * Referenced by: '<S19>/White_press'
                                        */
  real_T White_q;                      /* Variable: White_q
                                        * Referenced by: '<S117>/Random Number7'
                                        */
  real_T White_r;                      /* Variable: White_r
                                        * Referenced by: '<S117>/Random Number8'
                                        */
  real_T Zeng;                         /* Variable: Zeng
                                        * Referenced by: '<S23>/Zeng'
                                        */
  real_T adc_P_bmp[16363];             /* Variable: adc_P_bmp
                                        * Referenced by: '<S19>/1-D Lookup Table'
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
                                        * Referenced by: '<S117>/Gain3'
                                        */
  real_T beta_psi;                     /* Variable: beta_psi
                                        * Referenced by: '<S117>/Gain5'
                                        */
  real_T beta_theta;                   /* Variable: beta_theta
                                        * Referenced by: '<S117>/Gain4'
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
                                        * Referenced by: '<S88>/Constant5'
                                        */
  real_T degree_elevator[15];          /* Variable: degree_elevator
                                        * Referenced by: '<S96>/Constant5'
                                        */
  real_T degree_rudder[43];            /* Variable: degree_rudder
                                        * Referenced by: '<S97>/Constant6'
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
                                        * Referenced by: '<S117>/Random Number3'
                                        */
  real_T mean_ay;                      /* Variable: mean_ay
                                        * Referenced by: '<S117>/Random Number4'
                                        */
  real_T mean_az;                      /* Variable: mean_az
                                        * Referenced by: '<S117>/Random Number5'
                                        */
  real_T mean_p;                       /* Variable: mean_p
                                        * Referenced by: '<S117>/Random Number6'
                                        */
  real_T mean_q;                       /* Variable: mean_q
                                        * Referenced by: '<S117>/Random Number7'
                                        */
  real_T mean_r;                       /* Variable: mean_r
                                        * Referenced by: '<S117>/Random Number8'
                                        */
  real_T microsec_aileron[43];         /* Variable: microsec_aileron
                                        * Referenced by: '<S88>/Constant4'
                                        */
  real_T microsec_elevator[15];        /* Variable: microsec_elevator
                                        * Referenced by: '<S96>/Constant4'
                                        */
  real_T microsec_rudder[43];          /* Variable: microsec_rudder
                                        * Referenced by: '<S97>/Constant5'
                                        */
  real_T p_bmp[16363];                 /* Variable: p_bmp
                                        * Referenced by: '<S19>/1-D Lookup Table'
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
                                        *   '<S117>/Random Number'
                                        *   '<S117>/Random Number1'
                                        *   '<S117>/Random Number2'
                                        *   '<S117>/Random Number3'
                                        *   '<S117>/Random Number4'
                                        *   '<S117>/Random Number5'
                                        *   '<S117>/Random Number6'
                                        *   '<S117>/Random Number7'
                                        *   '<S117>/Random Number8'
                                        */
  real_T seed_baro;                    /* Variable: seed_baro
                                        * Referenced by: '<S19>/White_press'
                                        */
  real_T seed_gps;                     /* Variable: seed_gps
                                        * Referenced by:
                                        *   '<S124>/Noise V_hor'
                                        *   '<S124>/Noise terra course'
                                        *   '<S124>/Rumore bianco'
                                        *   '<S124>/noise terra V_hor1'
                                        */
  real_T wind_constant[3];             /* Variable: wind_constant
                                        * Referenced by: '<S15>/Winds'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S74>/Constant'
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
                                        * Referenced by: '<S19>/White_press'
                                        */
  real_T SeaLevelTemperature_Value;    /* Expression: T0
                                        * Referenced by: '<S109>/Sea Level  Temperature'
                                        */
  real_T PositionIntegrator2_IC[3];
                              /* Expression: [latitudineINI longitudineINI HINI]
                               * Referenced by: '<S83>/Position Integrator2'
                               */
  real_T Limitaltitudetotroposhere_UpperSat;/* Expression: h_trop
                                             * Referenced by: '<S109>/Limit  altitude  to troposhere'
                                             */
  real_T Limitaltitudetotroposhere_LowerSat;/* Expression: h0
                                             * Referenced by: '<S109>/Limit  altitude  to troposhere'
                                             */
  real_T LapseRate_Gain;               /* Expression: L
                                        * Referenced by: '<S109>/Lapse Rate'
                                        */
  real_T uT0_Gain;                     /* Expression: 1/T0
                                        * Referenced by: '<S109>/1//T0'
                                        */
  real_T Constant_Value;               /* Expression: g/(L*R)
                                        * Referenced by: '<S109>/Constant'
                                        */
  real_T P0_Gain;                      /* Expression: P0
                                        * Referenced by: '<S109>/P0'
                                        */
  real_T AltitudeofTroposphere_Value;  /* Expression: h_trop
                                        * Referenced by: '<S109>/Altitude of Troposphere'
                                        */
  real_T LimitaltitudetoStratosphere_UpperSat;/* Expression: 0
                                               * Referenced by: '<S109>/Limit  altitude  to Stratosphere'
                                               */
  real_T LimitaltitudetoStratosphere_LowerSat;/* Expression: h_trop-h_strat
                                               * Referenced by: '<S109>/Limit  altitude  to Stratosphere'
                                               */
  real_T gR_Gain;                      /* Expression: g/R
                                        * Referenced by: '<S109>/g//R'
                                        */
  real_T WhiteNoise4_Mean;             /* Expression: 0
                                        * Referenced by: '<S19>/White Noise4'
                                        */
  real_T WhiteNoise4_StdDev;           /* Computed Parameter: WhiteNoise4_StdDev
                                        * Referenced by: '<S19>/White Noise4'
                                        */
  real_T WhiteNoise4_Seed;             /* Expression: [23341]
                                        * Referenced by: '<S19>/White Noise4'
                                        */
  real_T phithetapsi_WrappedStateUpperValue;/* Expression: pi
                                             * Referenced by: '<S36>/phi theta psi'
                                             */
  real_T phithetapsi_WrappedStateLowerValue;/* Expression: -pi
                                             * Referenced by: '<S36>/phi theta psi'
                                             */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T SFunction1_BytesRefNumOf;     /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S106>/S-Function1'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 100
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 4000
                                        * Referenced by: '<S19>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S19>/Saturation3'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1.225
                                        * Referenced by: '<S19>/Gain3'
                                        */
  real_T Constant2_Value;              /* Expression: 2
                                        * Referenced by: '<S19>/Constant2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 100
                                        * Referenced by: '<S19>/Gain4'
                                        */
  real_T pi_Value;                     /* Expression: pi
                                        * Referenced by: '<S85>/pi'
                                        */
  real_T upi_Value;                    /* Expression: 2*pi
                                        * Referenced by: '<S85>/2pi'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 180/pi
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T pi2_Value;                    /* Expression: pi/2
                                        * Referenced by: '<S84>/pi//2'
                                        */
  real_T pi_Value_h;                   /* Expression: pi
                                        * Referenced by: '<S84>/pi'
                                        */
  real_T ChSign_Gain;                  /* Expression: -1
                                        * Referenced by: '<S84>/ChSign'
                                        */
  real_T upi_Value_j;                  /* Expression: 2*pi
                                        * Referenced by: '<S84>/2pi'
                                        */
  real_T Switch_Threshold;             /* Expression: pi
                                        * Referenced by: '<S84>/Switch'
                                        */
  real_T Gain_Gain_jh;                 /* Expression: 180/pi
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S122>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S122>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 180/pi
                                        * Referenced by: '<S113>/Gain'
                                        */
  real_T DiscreteTimeIntegrator_gainval_p;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_p
                          * Referenced by: '<S123>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_p;  /* Expression: 0
                                        * Referenced by: '<S123>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S114>/Gain'
                                        */
  real_T NoiseV_hor_Mean;              /* Expression: 0
                                        * Referenced by: '<S124>/Noise V_hor'
                                        */
  real_T NoiseV_hor_StdDev;            /* Computed Parameter: NoiseV_hor_StdDev
                                        * Referenced by: '<S124>/Noise V_hor'
                                        */
  real_T noiseterraV_hor1_Mean;        /* Expression: 0
                                        * Referenced by: '<S124>/noise terra V_hor1'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0.3
                                        * Referenced by: '<S124>/Switch4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1.94384
                                        * Referenced by: '<S19>/Gain5'
                                        */
  real_T Rumorebianco_Mean;            /* Expression: 0
                                        * Referenced by: '<S124>/Rumore bianco'
                                        */
  real_T Rumorebianco_StdDev;         /* Computed Parameter: Rumorebianco_StdDev
                                       * Referenced by: '<S124>/Rumore bianco'
                                       */
  real_T Noiseterracourse_Mean;        /* Expression: 0
                                        * Referenced by: '<S124>/Noise terra course'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S124>/Switch3'
                                        */
  real_T Constant_Value_l;             /* Expression: 2*pi
                                        * Referenced by: '<S124>/Constant'
                                        */
  real_T Switch1_Threshold_g;          /* Expression: 0.3
                                        * Referenced by: '<S124>/Switch1'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S111>/Gain'
                                        */
  real_T uDLookupTable_tableData[91];  /* Expression: CD(2:end,2:end)
                                        * Referenced by: '<S58>/2-D Lookup Table'
                                        */
  real_T Gain4_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S55>/Gain4'
                                        */
  real_T uDLookupTable_tableData_o[91];/* Expression: CY(2:end,2:end)
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
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T StateSpace2_A_e;              /* Computed Parameter: StateSpace2_A_e
                                        * Referenced by: '<S3>/State-Space2'
                                        */
  real_T StateSpace2_B_c;              /* Computed Parameter: StateSpace2_B_c
                                        * Referenced by: '<S3>/State-Space2'
                                        */
  real_T StateSpace2_C_g;              /* Computed Parameter: StateSpace2_C_g
                                        * Referenced by: '<S3>/State-Space2'
                                        */
  real_T Switch_4_Threshold;           /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
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
  real_T StateSpace1_A_k;              /* Computed Parameter: StateSpace1_A_k
                                        * Referenced by: '<S3>/State-Space1'
                                        */
  real_T StateSpace1_B_g;              /* Computed Parameter: StateSpace1_B_g
                                        * Referenced by: '<S3>/State-Space1'
                                        */
  real_T StateSpace1_C_h;              /* Computed Parameter: StateSpace1_C_h
                                        * Referenced by: '<S3>/State-Space1'
                                        */
  real_T Switch_3_Threshold;           /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T uDLookupTable_tableData_e[91];/* Expression: CL(2:end,2:end)
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
  real_T StateSpace_A_p;               /* Computed Parameter: StateSpace_A_p
                                        * Referenced by: '<S3>/State-Space'
                                        */
  real_T StateSpace_B_m;               /* Computed Parameter: StateSpace_B_m
                                        * Referenced by: '<S3>/State-Space'
                                        */
  real_T StateSpace_C_d;               /* Computed Parameter: StateSpace_C_d
                                        * Referenced by: '<S3>/State-Space'
                                        */
  real_T Switch_2_Threshold;           /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Gain5_Gain_h;                 /* Expression: -1
                                        * Referenced by: '<S55>/Gain5'
                                        */
  real_T SeaLevelTemperature_Value_b;  /* Expression: T0
                                        * Referenced by: '<S24>/Sea Level  Temperature'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Limitaltitudetotroposhere_UpperSat_d;/* Expression: h_trop
                                               * Referenced by: '<S24>/Limit  altitude  to troposhere'
                                               */
  real_T Limitaltitudetotroposhere_LowerSat_c;/* Expression: h0
                                               * Referenced by: '<S24>/Limit  altitude  to troposhere'
                                               */
  real_T LapseRate_Gain_g;             /* Expression: L
                                        * Referenced by: '<S24>/Lapse Rate'
                                        */
  real_T uT0_Gain_h;                   /* Expression: 1/T0
                                        * Referenced by: '<S24>/1//T0'
                                        */
  real_T Constant_Value_i;             /* Expression: g/(L*R)
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T rho0_Gain;                    /* Expression: rho0
                                        * Referenced by: '<S24>/rho0'
                                        */
  real_T AltitudeofTroposphere_Value_i;/* Expression: h_trop
                                        * Referenced by: '<S24>/Altitude of Troposphere'
                                        */
  real_T LimitaltitudetoStratosphere_UpperSat_c;/* Expression: 0
                                                 * Referenced by: '<S24>/Limit  altitude  to Stratosphere'
                                                 */
  real_T LimitaltitudetoStratosphere_LowerSat_f;/* Expression: h_trop-h_strat
                                                 * Referenced by: '<S24>/Limit  altitude  to Stratosphere'
                                                 */
  real_T gR_Gain_c;                    /* Expression: g/R
                                        * Referenced by: '<S24>/g//R'
                                        */
  real_T u2rhoV2_Gain;                 /* Expression: 1/2
                                        * Referenced by: '<S27>/1//2rhoV^2'
                                        */
  real_T uDLookupTable_tableData_n[91];/* Expression: Cl(2:end,2:end)
                                        * Referenced by: '<S64>/2-D Lookup Table'
                                        */
  real_T Gain4_Gain_d;                 /* Expression: 1.5
                                        * Referenced by: '<S64>/Gain4'
                                        */
  real_T uDLookupTable_tableData_k[91];/* Expression: Cm(2:end,2:end)
                                        * Referenced by: '<S65>/2-D Lookup Table'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S65>/Gain1'
                                        */
  real_T uDLookupTable_tableData_kg[91];/* Expression: Cn(2:end,2:end)
                                         * Referenced by: '<S66>/2-D Lookup Table'
                                         */
  real_T RPMRPs_Gain;                  /* Expression: 1/60
                                        * Referenced by: '<S31>/RPM->RPs'
                                        */
  real_T Constant_Value_p;             /* Expression: 2
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 4
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T uDLookupTable_tableData_od[330];/* Expression: Ct(2:end,2:end)
                                          * Referenced by: '<S75>/2-D Lookup Table'
                                          */
  real_T uDLookupTable_bp02Data[11];   /* Expression: RPM_vec(2:end)
                                        * Referenced by: '<S75>/2-D Lookup Table'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S76>/Constant'
                                        */
  real_T Constant2_Value_f[9];         /* Expression: zeros(3)
                                        * Referenced by: '<S38>/Constant2'
                                        */
  real_T uDLookupTable1_tableData[330];/* Expression: Cp(2:end,2:end)
                                        * Referenced by: '<S75>/2-D Lookup Table1'
                                        */
  real_T uDLookupTable1_bp02Data[11];  /* Expression: RPM_vec(2:end)
                                        * Referenced by: '<S75>/2-D Lookup Table1'
                                        */
  real_T Constant3_Value_l;            /* Expression: 5
                                        * Referenced by: '<S31>/Constant3'
                                        */
  real_T Constant2_Value_j;            /* Expression: 3
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Gain_Gain_ai;                 /* Expression: 2*pi
                                        * Referenced by: '<S76>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S76>/Gain1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S76>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainval_n;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_n
                          * Referenced by: '<S19>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_b;  /* Expression: 0
                                        * Referenced by: '<S19>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 11
                                          * Referenced by: '<S19>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S19>/Discrete-Time Integrator'
                                          */
  real_T Constant3_Value_f;            /* Expression: 2.4
                                        * Referenced by: '<S19>/Constant3'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 10
                                        * Referenced by: '<S19>/Switch'
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
  real_T Gain1_Gain_b;                 /* Expression: -1
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1/(0.8*37)
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 10^6
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 1/(1800-1450)
                                        * Referenced by: '<S98>/Gain1'
                                        */
  real_T Constant2_Value_e;            /* Expression: (1/350)*1450
                                        * Referenced by: '<S98>/Constant2'
                                        */
  real_T Switch_1_Threshold;           /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: 1
                                        * Referenced by: '<S31>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: 0
                                        * Referenced by: '<S31>/Saturation'
                                        */
  real_T LUTMOTORE_Gain;               /* Expression: 7400
                                        * Referenced by: '<S31>/LUT MOTORE'
                                        */
  real_T RPsrads_Gain;                 /* Expression: 2*pi
                                        * Referenced by: '<S31>/RPs->rad//s'
                                        */
  real_T P0_Gain_e;                    /* Expression: P0
                                        * Referenced by: '<S24>/P0'
                                        */
  real_T gammaR_Gain;                  /* Expression: gamma*R
                                        * Referenced by: '<S24>/gamma*R'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S83>/Gain'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S86>/Constant'
                                        */
  real_T f_Value;                      /* Expression: F
                                        * Referenced by: '<S86>/f'
                                        */
  real_T Re_Value;                     /* Expression: R
                                        * Referenced by: '<S86>/Re'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: 10^6
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S96>/Constant1'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: pi/180
                                        * Referenced by: '<S93>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 10^6
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S88>/Constant1'
                                        */
  real_T Gain1_Gain_b0;                /* Expression: pi/180
                                        * Referenced by: '<S95>/Gain1'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: 10^6
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S97>/Constant1'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: pi/180
                                        * Referenced by: '<S94>/Gain1'
                                        */
  real_T DiscreteTimeIntegrator3_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator3_gainval
                           * Referenced by: '<S117>/Discrete-Time Integrator3'
                           */
  real_T DiscreteTimeIntegrator3_IC;   /* Expression: 0
                                        * Referenced by: '<S117>/Discrete-Time Integrator3'
                                        */
  real_T Gain_Gain_cg;                 /* Expression: 180/pi
                                        * Referenced by: '<S116>/Gain'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: 180
                                        * Referenced by: '<S19>/Saturation5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -180
                                        * Referenced by: '<S19>/Saturation5'
                                        */
  real_T DiscreteTimeIntegrator4_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator4_gainval
                           * Referenced by: '<S117>/Discrete-Time Integrator4'
                           */
  real_T DiscreteTimeIntegrator4_IC;   /* Expression: 0
                                        * Referenced by: '<S117>/Discrete-Time Integrator4'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S112>/Gain'
                                        */
  real_T Saturation6_UpperSat;         /* Expression: 90
                                        * Referenced by: '<S19>/Saturation6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -90
                                        * Referenced by: '<S19>/Saturation6'
                                        */
  real_T DiscreteTimeIntegrator5_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator5_gainval
                           * Referenced by: '<S117>/Discrete-Time Integrator5'
                           */
  real_T DiscreteTimeIntegrator5_IC;   /* Expression: 0
                                        * Referenced by: '<S117>/Discrete-Time Integrator5'
                                        */
  real_T Gain_Gain_ki;                 /* Expression: 180/pi
                                        * Referenced by: '<S115>/Gain'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 180
                                        * Referenced by: '<S19>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -180
                                        * Referenced by: '<S19>/Saturation4'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S19>/Constant4'
                                        */
  real_T rho0_Gain_e;                  /* Expression: rho0
                                        * Referenced by: '<S109>/rho0'
                                        */
  real_T gammaR_Gain_c;                /* Expression: gamma*R
                                        * Referenced by: '<S109>/gamma*R'
                                        */
  real_T RandomNumber_Mean;            /* Expression: 0
                                        * Referenced by: '<S117>/Random Number'
                                        */
  real_T RandomNumber1_Mean;           /* Expression: 0
                                        * Referenced by: '<S117>/Random Number1'
                                        */
  real_T RandomNumber2_Mean;           /* Expression: 0
                                        * Referenced by: '<S117>/Random Number2'
                                        */
  real_T WhiteNoiseLat_Mean;           /* Expression: 0
                                        * Referenced by: '<S122>/White Noise Lat'
                                        */
  real_T WhiteNoiseLat_StdDev;       /* Computed Parameter: WhiteNoiseLat_StdDev
                                      * Referenced by: '<S122>/White Noise Lat'
                                      */
  real_T WhiteNoiseLat_Seed;           /* Expression: 0
                                        * Referenced by: '<S122>/White Noise Lat'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S123>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S123>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: 0
                                        * Referenced by: '<S123>/White Noise'
                                        */
  uint32_T SFunction1_BytesRefNumOf_i; /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S102>/S-Function1'
                                        */
  uint32_T SFunction1_BytesRefNumOf_n; /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S13>/S-Function1'
                                        */
  uint32_T SFunction1_BytesRefNumOf_j; /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S12>/S-Function1'
                                        */
  uint32_T SFunction1_BytesRefNumOf_l; /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S20>/S-Function1'
                                        */
  uint32_T uDLookupTable_maxIndex[2];
                                   /* Computed Parameter: uDLookupTable_maxIndex
                                    * Referenced by: '<S58>/2-D Lookup Table'
                                    */
  uint32_T uDLookupTable_maxIndex_c[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_c
                                  * Referenced by: '<S59>/2-D Lookup Table'
                                  */
  uint32_T uDLookupTable_maxIndex_o[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_o
                                  * Referenced by: '<S60>/2-D Lookup Table'
                                  */
  uint32_T uDLookupTable_maxIndex_cp[2];
                                /* Computed Parameter: uDLookupTable_maxIndex_cp
                                 * Referenced by: '<S64>/2-D Lookup Table'
                                 */
  uint32_T uDLookupTable_maxIndex_h[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_h
                                  * Referenced by: '<S65>/2-D Lookup Table'
                                  */
  uint32_T uDLookupTable_maxIndex_j[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_j
                                  * Referenced by: '<S66>/2-D Lookup Table'
                                  */
  uint32_T uDLookupTable_maxIndex_p[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_p
                                  * Referenced by: '<S75>/2-D Lookup Table'
                                  */
  uint32_T uDLookupTable1_maxIndex[2];
                                  /* Computed Parameter: uDLookupTable1_maxIndex
                                   * Referenced by: '<S75>/2-D Lookup Table1'
                                   */
  uint8_T Constant1_Value_p[5];        /* Computed Parameter: Constant1_Value_p
                                        * Referenced by: '<S19>/Constant1'
                                        */
  uint8_T RateTransition_InitialCondition;
                          /* Computed Parameter: RateTransition_InitialCondition
                           * Referenced by: '<Root>/Rate Transition'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_modello_HITL_SFT_v4_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_modello_HITL_SFT_v4_T *contStates;
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
extern P_modello_HITL_SFT_v4_T modello_HITL_SFT_v4_P;

/* Block signals (default storage) */
extern B_modello_HITL_SFT_v4_T modello_HITL_SFT_v4_B;

/* Continuous states (default storage) */
extern X_modello_HITL_SFT_v4_T modello_HITL_SFT_v4_X;

/* Block states (default storage) */
extern DW_modello_HITL_SFT_v4_T modello_HITL_SFT_v4_DW;

/* Model entry point functions */
extern void modello_HITL_SFT_v4_initialize(void);
extern void modello_HITL_SFT_v4_output(void);
extern void modello_HITL_SFT_v4_update(void);
extern void modello_HITL_SFT_v4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_modello_HITL_SFT_v4_T *const modello_HITL_SFT_v4_M;

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
 * '<Root>' : 'modello_HITL_SFT_v4'
 * '<S1>'   : 'modello_HITL_SFT_v4/AENEA '
 * '<S2>'   : 'modello_HITL_SFT_v4/ATTUATORI'
 * '<S3>'   : 'modello_HITL_SFT_v4/ATTUATORI1'
 * '<S4>'   : 'modello_HITL_SFT_v4/Comandi al trim'
 * '<S5>'   : 'modello_HITL_SFT_v4/Comandi da ARDUINO'
 * '<S6>'   : 'modello_HITL_SFT_v4/DS2101_B1'
 * '<S7>'   : 'modello_HITL_SFT_v4/DS4201SER_INT_B1_C1_I1'
 * '<S8>'   : 'modello_HITL_SFT_v4/DS4201SER_SETUP_B1_C1'
 * '<S9>'   : 'modello_HITL_SFT_v4/DS4201SER_SETUP_B1_C2'
 * '<S10>'  : 'modello_HITL_SFT_v4/DS4201SER_SETUP_B1_C3'
 * '<S11>'  : 'modello_HITL_SFT_v4/DS4201SER_SETUP_B1_C4'
 * '<S12>'  : 'modello_HITL_SFT_v4/DS4201SER_TX_B1_C3'
 * '<S13>'  : 'modello_HITL_SFT_v4/DS4201SER_TX_B1_C4'
 * '<S14>'  : 'modello_HITL_SFT_v4/Function-Call Subsystem'
 * '<S15>'  : 'modello_HITL_SFT_v4/Parametri Modello A//C'
 * '<S16>'  : 'modello_HITL_SFT_v4/RTI Data'
 * '<S17>'  : 'modello_HITL_SFT_v4/Radians to Degrees'
 * '<S18>'  : 'modello_HITL_SFT_v4/Radians to Degrees1'
 * '<S19>'  : 'modello_HITL_SFT_v4/SENSORI'
 * '<S20>'  : 'modello_HITL_SFT_v4/_DS4201SER_TX_B1_C2'
 * '<S21>'  : 'modello_HITL_SFT_v4/scalatura velocità'
 * '<S22>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1'
 * '<S23>'  : 'modello_HITL_SFT_v4/AENEA /Blocco_Costanti1'
 * '<S24>'  : 'modello_HITL_SFT_v4/AENEA /ISA Atmosphere Model'
 * '<S25>'  : 'modello_HITL_SFT_v4/AENEA /toSensors'
 * '<S26>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)'
 * '<S27>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Dynamic Pressure'
 * '<S28>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche'
 * '<S29>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Gear'
 * '<S30>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/MATLAB Function'
 * '<S31>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Propulsione1'
 * '<S32>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Subsystem'
 * '<S33>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Subsystem1'
 * '<S34>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Velocità1'
 * '<S35>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Weight'
 * '<S36>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate DCM & Euler Angles'
 * '<S37>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot'
 * '<S38>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Determine Force,  Mass & Inertia'
 * '<S39>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Vbxw'
 * '<S40>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Velocity Conversion'
 * '<S41>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Velocity Conversion1'
 * '<S42>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Velocity Conversion2'
 * '<S43>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/transform to Inertial axes '
 * '<S44>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix'
 * '<S45>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate DCM & Euler Angles/phidot thetadot psidot'
 * '<S46>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S47>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product'
 * '<S48>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot/I x w'
 * '<S49>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot/I x w1'
 * '<S50>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem'
 * '<S51>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
 * '<S52>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Vbxw/Subsystem'
 * '<S53>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/6DOF (Euler Angles)/Vbxw/Subsystem1'
 * '<S54>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Dynamic Pressure/dot'
 * '<S55>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q'
 * '<S56>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/MATLAB Function'
 * '<S57>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din'
 * '<S58>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem'
 * '<S59>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem1'
 * '<S60>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem2'
 * '<S61>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem1/controllo divisione per zero Yp '
 * '<S62>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem1/controllo divisione per zero Yr'
 * '<S63>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem2/controllo divisione per zero Lq '
 * '<S64>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem3'
 * '<S65>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem4'
 * '<S66>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem5'
 * '<S67>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem3/controllo divisione per zero lp '
 * '<S68>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem3/controllo divisione per zero lr '
 * '<S69>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem4/controllo divisione per zero mq '
 * '<S70>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem5/controllo divisione per zero np '
 * '<S71>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem5/controllo divisione per zero nr '
 * '<S72>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Gear/MATLAB Function'
 * '<S73>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Gear/MATLAB Function2'
 * '<S74>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Propulsione1/Compare To Constant'
 * '<S75>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Propulsione1/LUT ELICA '
 * '<S76>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Propulsione1/Subsystem1'
 * '<S77>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Velocità1/MATLAB Function'
 * '<S78>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Velocità1/controllo divisione per 0 su alpha'
 * '<S79>'  : 'modello_HITL_SFT_v4/AENEA /AENEA II_SITL1/Velocità1/controllo divisione per 0 su beta'
 * '<S80>'  : 'modello_HITL_SFT_v4/AENEA /toSensors/Calc_GS'
 * '<S81>'  : 'modello_HITL_SFT_v4/AENEA /toSensors/Calc_heading'
 * '<S82>'  : 'modello_HITL_SFT_v4/AENEA /toSensors/MATLAB Function'
 * '<S83>'  : 'modello_HITL_SFT_v4/AENEA /toSensors/To_Lat_Long_MSL'
 * '<S84>'  : 'modello_HITL_SFT_v4/AENEA /toSensors/To_Lat_Long_MSL/Latitude Bound'
 * '<S85>'  : 'modello_HITL_SFT_v4/AENEA /toSensors/To_Lat_Long_MSL/Longitude Bound'
 * '<S86>'  : 'modello_HITL_SFT_v4/AENEA /toSensors/To_Lat_Long_MSL/Radius at Geocentric Latitude'
 * '<S87>'  : 'modello_HITL_SFT_v4/AENEA /toSensors/To_Lat_Long_MSL/Radius at Geocentric Latitude/Conversion'
 * '<S88>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/AILERON'
 * '<S89>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/DS4002PWMTOD'
 * '<S90>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/DS4002PWMTOD1'
 * '<S91>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/DS4002PWMTOD2'
 * '<S92>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/DS4002PWMTOD3'
 * '<S93>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/Degrees to Radians'
 * '<S94>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/Degrees to Radians1'
 * '<S95>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/Degrees to Radians2'
 * '<S96>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/ELEVATOR'
 * '<S97>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/RUDDER'
 * '<S98>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/THROTTLE'
 * '<S99>'  : 'modello_HITL_SFT_v4/Comandi da ARDUINO/AILERON/MATLAB Function'
 * '<S100>' : 'modello_HITL_SFT_v4/Comandi da ARDUINO/ELEVATOR/MATLAB Function'
 * '<S101>' : 'modello_HITL_SFT_v4/Comandi da ARDUINO/RUDDER/MATLAB Function'
 * '<S102>' : 'modello_HITL_SFT_v4/Function-Call Subsystem/DS4201SER_TX_B1_C1'
 * '<S103>' : 'modello_HITL_SFT_v4/RTI Data/RTI Data Store'
 * '<S104>' : 'modello_HITL_SFT_v4/RTI Data/RTI Data Store/RTI Data Store'
 * '<S105>' : 'modello_HITL_SFT_v4/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S106>' : 'modello_HITL_SFT_v4/SENSORI/DS4201SER_RX_B1_C3'
 * '<S107>' : 'modello_HITL_SFT_v4/SENSORI/Enabled Subsystem'
 * '<S108>' : 'modello_HITL_SFT_v4/SENSORI/GPS Venus'
 * '<S109>' : 'modello_HITL_SFT_v4/SENSORI/ISA Atmosphere Model'
 * '<S110>' : 'modello_HITL_SFT_v4/SENSORI/Pressure Altitude'
 * '<S111>' : 'modello_HITL_SFT_v4/SENSORI/Radians to Degrees1'
 * '<S112>' : 'modello_HITL_SFT_v4/SENSORI/Radians to Degrees10'
 * '<S113>' : 'modello_HITL_SFT_v4/SENSORI/Radians to Degrees2'
 * '<S114>' : 'modello_HITL_SFT_v4/SENSORI/Radians to Degrees3'
 * '<S115>' : 'modello_HITL_SFT_v4/SENSORI/Radians to Degrees4'
 * '<S116>' : 'modello_HITL_SFT_v4/SENSORI/Radians to Degrees9'
 * '<S117>' : 'modello_HITL_SFT_v4/SENSORI/Subsystem'
 * '<S118>' : 'modello_HITL_SFT_v4/SENSORI/Subsystem1'
 * '<S119>' : 'modello_HITL_SFT_v4/SENSORI/trasformazione quota earth-body'
 * '<S120>' : 'modello_HITL_SFT_v4/SENSORI/Pressure Altitude/Length Conversion'
 * '<S121>' : 'modello_HITL_SFT_v4/SENSORI/Pressure Altitude/Pressure Conversion'
 * '<S122>' : 'modello_HITL_SFT_v4/SENSORI/Subsystem1/Subsystem'
 * '<S123>' : 'modello_HITL_SFT_v4/SENSORI/Subsystem1/Subsystem1'
 * '<S124>' : 'modello_HITL_SFT_v4/SENSORI/Subsystem1/Subsystem2'
 * '<S125>' : 'modello_HITL_SFT_v4/SENSORI/Subsystem1/Subsystem2/0-2pi Wrapper'
 * '<S126>' : 'modello_HITL_SFT_v4/scalatura velocità/MATLAB Function'
 * '<S127>' : 'modello_HITL_SFT_v4/scalatura velocità/Protezione sovratensione'
 * '<S128>' : 'modello_HITL_SFT_v4/scalatura velocità/deltaP_to_Volt'
 */
#endif                                 /* RTW_HEADER_modello_HITL_SFT_v4_h_ */
