/*
 * loaddspace_types.h
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

#ifndef RTW_HEADER_loaddspace_types_h_
#define RTW_HEADER_loaddspace_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_ckUvIw1SyOAjdVf7lN2sjG_
#define DEFINED_TYPEDEF_FOR_struct_ckUvIw1SyOAjdVf7lN2sjG_

typedef struct {
  real_T Pos0[3];
  real_T PHI0[3];
  real_T Vb0[3];
  real_T Omega0[3];
  real_T Ail0;
  real_T Rud0;
  real_T Ele0;
} struct_ckUvIw1SyOAjdVf7lN2sjG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_dZjXwTiylTPloSUBFpnHJB_
#define DEFINED_TYPEDEF_FOR_struct_dZjXwTiylTPloSUBFpnHJB_

typedef struct {
  int32_T InputPortsWidth;
} struct_dZjXwTiylTPloSUBFpnHJB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_isB4Cw3Ovpp8VfzP6RUqbD_
#define DEFINED_TYPEDEF_FOR_struct_isB4Cw3Ovpp8VfzP6RUqbD_

typedef struct {
  int32_T OutputPortsWidth;
} struct_isB4Cw3Ovpp8VfzP6RUqbD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_6Hj7z6Di1PEUr8TFSJkHvD_
#define DEFINED_TYPEDEF_FOR_struct_6Hj7z6Di1PEUr8TFSJkHvD_

typedef struct {
  int32_T OutputPortsWidth[2];
} struct_6Hj7z6Di1PEUr8TFSJkHvD;

#endif

/* Parameters (default storage) */
typedef struct P_loaddspace_T_ P_loaddspace_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_loaddspace_T RT_MODEL_loaddspace_T;

#endif                                 /* RTW_HEADER_loaddspace_types_h_ */
