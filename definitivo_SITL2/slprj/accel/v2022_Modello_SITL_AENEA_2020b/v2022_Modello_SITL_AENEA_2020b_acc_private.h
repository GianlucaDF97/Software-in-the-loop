#ifndef RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_private_h_
#define RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "v2022_Modello_SITL_AENEA_2020b_acc.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
void v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Init ( SimStruct * S ,
B_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localB ,
P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localP ,
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localX ) ; void
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Reset ( SimStruct * S ,
P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localP ,
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localX ) ; void
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Deriv ( SimStruct * S ,
real_T rtu_V , DW_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T *
localDW , P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localP ,
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localX ,
XDot_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localXdot ) ; void
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Disable ( SimStruct * S ,
DW_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localDW ) ; void
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty ( SimStruct * S , boolean_T
rtu_Enable , B_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localB ,
DW_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localDW ,
P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localP ,
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localX ) ; void
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Term ( SimStruct * const S )
;
#endif
