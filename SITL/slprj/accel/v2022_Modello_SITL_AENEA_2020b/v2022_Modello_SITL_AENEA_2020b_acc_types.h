#ifndef RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_types_h_
#define RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_slBus4_manuali_
#define DEFINED_TYPEDEF_FOR_slBus4_manuali_
typedef struct { real_T Manual_Elevator ; real_T Manual_Aileron ; real_T
Manual_Rudder ; real_T Manual_Throttle ; real_T Go_Home ; } slBus4_manuali ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_slBus8_sensori2_
#define DEFINED_TYPEDEF_FOR_slBus8_sensori2_
typedef struct { real_T Lat ; real_T Long ; real_T Alt ; real_T vn ; real_T
ve ; real_T phi ; real_T theta ; real_T psi ; real_T psi_c ; real_T ax ;
real_T ay ; real_T az ; real_T p ; real_T q ; real_T r ; real_T Tas ; real_T
rho ; real_T w ; real_T omega ; real_T Beta ; real_T quota_lidar ; real_T Ias
; } slBus8_sensori2 ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_slBus5_Interruttori_
#define DEFINED_TYPEDEF_FOR_slBus5_Interruttori_
typedef struct { real_T Manuale ; real_T Ingaggio_AP ; real_T HDG ; real_T
IAS ; real_T ALT ; real_T RC ; real_T WP_nav ; real_T GC_info ; real_T ATO ;
real_T AL ; real_T test ; } slBus5_Interruttori ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_slBus6_Riferimenti_
#define DEFINED_TYPEDEF_FOR_slBus6_Riferimenti_
typedef struct { real_T ROTTA ; real_T VELOCITA ; real_T QUOTA ; real_T RC ;
real_T WP_db_info [ 24 ] ; real_T WP_db_param [ 28 ] ; real_T WP_AL [ 14 ] ;
} slBus6_Riferimenti ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_slBus8_comandi_
#define DEFINED_TYPEDEF_FOR_slBus8_comandi_
typedef struct { real_T Manetta ; real_T Equilibratore ; real_T Alettoni ;
real_T Timone ; } slBus8_comandi ;
#endif
typedef struct P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T_
P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T ; typedef struct
P_v2022_Modello_SITL_AENEA_2020b_T_ P_v2022_Modello_SITL_AENEA_2020b_T ;
#endif
