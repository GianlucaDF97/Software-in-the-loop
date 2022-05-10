/***************************************************************************

   Source file loaddspace_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1006 7.15 (02-Nov-2020)
   Mon Oct 25 15:41:33 2021

   Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "loaddspace_trc_ptr.h"
#include "loaddspace.h"
#include "loaddspace_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_loaddspace_real_T_0 = NULL;
volatile uint32_T *p_0_loaddspace_uint32_T_1 = NULL;
volatile real32_T *p_0_loaddspace_real32_T_2 = NULL;
volatile int32_T *p_0_loaddspace_int32_T_3 = NULL;
volatile uint16_T *p_0_loaddspace_uint16_T_4 = NULL;
volatile uint8_T *p_0_loaddspace_uint8_T_5 = NULL;
volatile boolean_T *p_0_loaddspace_boolean_T_6 = NULL;
volatile real_T *p_0_loaddspace_real_T_7 = NULL;
volatile real_T *p_0_loaddspace_real_T_8 = NULL;
volatile struct_ckUvIw1SyOAjdVf7lN2sjG
  *p_1_loaddspace_struct_ckUvIw1SyOAjdVf7lN2sjG_0 = NULL;
volatile real_T *p_1_loaddspace_real_T_1 = NULL;
volatile uint32_T *p_1_loaddspace_uint32_T_2 = NULL;
volatile uint8_T *p_1_loaddspace_uint8_T_3 = NULL;
volatile real_T *p_2_loaddspace_real_T_0 = NULL;
volatile int32_T *p_2_loaddspace_int32_T_1 = NULL;
volatile uint32_T *p_2_loaddspace_uint32_T_2 = NULL;
volatile int8_T *p_2_loaddspace_int8_T_3 = NULL;
volatile uint8_T *p_2_loaddspace_uint8_T_4 = NULL;
volatile real_T *p_3_loaddspace_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_loaddspace_real_T_0 = &loaddspace_B.ubvbwb[0];
  p_0_loaddspace_uint32_T_1 = &loaddspace_B.SFunctionBuilder1_o2;
  p_0_loaddspace_real32_T_2 = &loaddspace_B.DataTypeConversion[0];
  p_0_loaddspace_int32_T_3 = &loaddspace_B.DataTypeConversion_m;
  p_0_loaddspace_uint16_T_4 = &loaddspace_B.DataTypeConversion1;
  p_0_loaddspace_uint8_T_5 = &loaddspace_B.BytePack1[0];
  p_0_loaddspace_boolean_T_6 = &loaddspace_B.Compare;
  p_0_loaddspace_real_T_7 = &loaddspace_B.sf_MATLABFunction_j.K;
  p_0_loaddspace_real_T_8 = &loaddspace_B.sf_MATLABFunction_b.K;
  p_1_loaddspace_struct_ckUvIw1SyOAjdVf7lN2sjG_0 = &loaddspace_P.State0;
  p_1_loaddspace_real_T_1 = &loaddspace_P.CD0;
  p_1_loaddspace_uint32_T_2 = &loaddspace_P.SFunction1_BytesRefNumOf_p;
  p_1_loaddspace_uint8_T_3 = &loaddspace_P.Constant1_Value_p[0];
  p_2_loaddspace_real_T_0 = &loaddspace_DW.DiscreteTimeIntegrator_DSTATE;
  p_2_loaddspace_int32_T_1 = &loaddspace_DW.Product2_DWORK2[0];
  p_2_loaddspace_uint32_T_2 = &loaddspace_DW.RandSeed;
  p_2_loaddspace_int8_T_3 = &loaddspace_DW.RateTransition_write_buf;
  p_2_loaddspace_uint8_T_4 = &loaddspace_DW.RateTransition_Buffer0[0];
  p_3_loaddspace_real_T_0 = &loaddspace_X.ubvbwb_CSTATE[0];
}

void loaddspace_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
