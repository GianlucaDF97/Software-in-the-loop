/***************************************************************************

   Source file modello_HITL_SFT_v4_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1006 7.15 (02-Nov-2020)
   Thu Oct 14 16:04:16 2021

   Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "modello_HITL_SFT_v4_trc_ptr.h"
#include "modello_HITL_SFT_v4.h"
#include "modello_HITL_SFT_v4_private.h"

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
volatile real_T *p_0_modello_HITL_SFT_v4_real_T_0 = NULL;
volatile uint32_T *p_0_modello_HITL_SFT_v4_uint32_T_1 = NULL;
volatile real32_T *p_0_modello_HITL_SFT_v4_real32_T_2 = NULL;
volatile int32_T *p_0_modello_HITL_SFT_v4_int32_T_3 = NULL;
volatile uint16_T *p_0_modello_HITL_SFT_v4_uint16_T_4 = NULL;
volatile uint8_T *p_0_modello_HITL_SFT_v4_uint8_T_5 = NULL;
volatile boolean_T *p_0_modello_HITL_SFT_v4_boolean_T_6 = NULL;
volatile real_T *p_0_modello_HITL_SFT_v4_real_T_7 = NULL;
volatile real_T *p_0_modello_HITL_SFT_v4_real_T_8 = NULL;
volatile struct_ckUvIw1SyOAjdVf7lN2sjG
  *p_1_modello_HITL_SFT_v4_struct_ckUvIw1SyOAjdVf7lN2sjG_0 = NULL;
volatile real_T *p_1_modello_HITL_SFT_v4_real_T_1 = NULL;
volatile uint32_T *p_1_modello_HITL_SFT_v4_uint32_T_2 = NULL;
volatile uint8_T *p_1_modello_HITL_SFT_v4_uint8_T_3 = NULL;
volatile real_T *p_2_modello_HITL_SFT_v4_real_T_0 = NULL;
volatile int32_T *p_2_modello_HITL_SFT_v4_int32_T_2 = NULL;
volatile uint32_T *p_2_modello_HITL_SFT_v4_uint32_T_3 = NULL;
volatile int8_T *p_2_modello_HITL_SFT_v4_int8_T_4 = NULL;
volatile uint8_T *p_2_modello_HITL_SFT_v4_uint8_T_5 = NULL;
volatile real_T *p_3_modello_HITL_SFT_v4_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_modello_HITL_SFT_v4_real_T_0 = &modello_HITL_SFT_v4_B.ubvbwb[0];
  p_0_modello_HITL_SFT_v4_uint32_T_1 =
    &modello_HITL_SFT_v4_B.SFunctionBuilder1_o2;
  p_0_modello_HITL_SFT_v4_real32_T_2 =
    &modello_HITL_SFT_v4_B.DataTypeConversion[0];
  p_0_modello_HITL_SFT_v4_int32_T_3 =
    &modello_HITL_SFT_v4_B.DataTypeConversion_l;
  p_0_modello_HITL_SFT_v4_uint16_T_4 =
    &modello_HITL_SFT_v4_B.DataTypeConversion1;
  p_0_modello_HITL_SFT_v4_uint8_T_5 = &modello_HITL_SFT_v4_B.BytePack1[0];
  p_0_modello_HITL_SFT_v4_boolean_T_6 = &modello_HITL_SFT_v4_B.Compare;
  p_0_modello_HITL_SFT_v4_real_T_7 =
    &modello_HITL_SFT_v4_B.sf_MATLABFunction_o.K;
  p_0_modello_HITL_SFT_v4_real_T_8 =
    &modello_HITL_SFT_v4_B.sf_MATLABFunction_i.K;
  p_1_modello_HITL_SFT_v4_struct_ckUvIw1SyOAjdVf7lN2sjG_0 =
    &modello_HITL_SFT_v4_P.State0;
  p_1_modello_HITL_SFT_v4_real_T_1 = &modello_HITL_SFT_v4_P.CD0;
  p_1_modello_HITL_SFT_v4_uint32_T_2 =
    &modello_HITL_SFT_v4_P.SFunction1_BytesRefNumOf_i;
  p_1_modello_HITL_SFT_v4_uint8_T_3 = &modello_HITL_SFT_v4_P.Constant1_Value_p[0];
  p_2_modello_HITL_SFT_v4_real_T_0 =
    &modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE;
  p_2_modello_HITL_SFT_v4_int32_T_2 = &modello_HITL_SFT_v4_DW.Product2_DWORK2[0];
  p_2_modello_HITL_SFT_v4_uint32_T_3 = &modello_HITL_SFT_v4_DW.RandSeed;
  p_2_modello_HITL_SFT_v4_int8_T_4 =
    &modello_HITL_SFT_v4_DW.RateTransition_write_buf;
  p_2_modello_HITL_SFT_v4_uint8_T_5 =
    &modello_HITL_SFT_v4_DW.RateTransition_Buffer0[0];
  p_3_modello_HITL_SFT_v4_real_T_0 = &modello_HITL_SFT_v4_X.ubvbwb_CSTATE[0];
}

void modello_HITL_SFT_v4_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
