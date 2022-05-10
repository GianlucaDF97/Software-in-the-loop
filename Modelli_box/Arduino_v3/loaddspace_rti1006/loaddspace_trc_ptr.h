/*********************** dSPACE target specific file *************************

   Header file loaddspace_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1006 7.15 (02-Nov-2020)
   Mon Oct 25 15:41:33 2021

   Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_loaddspace_trc_ptr_h_
#define RTI_HEADER_loaddspace_trc_ptr_h_

/* Include the model header file. */
#include "loaddspace.h"
#include "loaddspace_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_loaddspace_real_T_0;
EXTERN_C volatile uint32_T *p_0_loaddspace_uint32_T_1;
EXTERN_C volatile real32_T *p_0_loaddspace_real32_T_2;
EXTERN_C volatile int32_T *p_0_loaddspace_int32_T_3;
EXTERN_C volatile uint16_T *p_0_loaddspace_uint16_T_4;
EXTERN_C volatile uint8_T *p_0_loaddspace_uint8_T_5;
EXTERN_C volatile boolean_T *p_0_loaddspace_boolean_T_6;
EXTERN_C volatile real_T *p_0_loaddspace_real_T_7;
EXTERN_C volatile real_T *p_0_loaddspace_real_T_8;
EXTERN_C volatile struct_ckUvIw1SyOAjdVf7lN2sjG
  *p_1_loaddspace_struct_ckUvIw1SyOAjdVf7lN2sjG_0;
EXTERN_C volatile real_T *p_1_loaddspace_real_T_1;
EXTERN_C volatile uint32_T *p_1_loaddspace_uint32_T_2;
EXTERN_C volatile uint8_T *p_1_loaddspace_uint8_T_3;
EXTERN_C volatile real_T *p_2_loaddspace_real_T_0;
EXTERN_C volatile int32_T *p_2_loaddspace_int32_T_1;
EXTERN_C volatile uint32_T *p_2_loaddspace_uint32_T_2;
EXTERN_C volatile int8_T *p_2_loaddspace_int8_T_3;
EXTERN_C volatile uint8_T *p_2_loaddspace_uint8_T_4;
EXTERN_C volatile real_T *p_3_loaddspace_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void loaddspace_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_loaddspace_trc_ptr_h_ */
