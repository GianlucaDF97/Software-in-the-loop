#if !defined(S_FUNCTION_NAME)
#define S_FUNCTION_NAME autopilota_v_15_last_msf
#endif
#define S_FUNCTION_LEVEL 2
#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif
#include <stdio.h>
#include <math.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define rt_logging_h
#include "autopilota_v_15_last_types.h"
#include "autopilota_v_15_last.h"
#include "autopilota_v_15_last_private.h"
real_T rtP_Kd_h_app ; real_T rtP_Kd_h_flare ; real_T rtP_Ki_AP_rotta ; real_T
rtP_Ki_h_app ; real_T rtP_Ki_h_cruise ; real_T rtP_Ki_h_flare ; real_T
rtP_Kp_AP_quota_hold_h ; real_T rtP_Kp_AP_quota_hold_l ; real_T
rtP_Kp_Rotta_ATO ; real_T rtP_Kp_Rotta_psi ; real_T rtP_Kp_comp_h ; real_T
rtP_Kp_h_cruise ; real_T rtP_Kp_h_flare ; real_T rtP_Q1B [ 18 ] ; real_T
rtP_R1B [ 11 ] ; real_T rtP_Sensor_Offsets [ 3 ] ; real_T rtP_V_stall ;
real_T rtP_attuatore_Amax ; real_T rtP_attuatore_Amin ; real_T
rtP_attuatore_Emax ; real_T rtP_attuatore_Emin ; real_T rtP_attuatore_Rmax ;
real_T rtP_attuatore_Rmin ; real_T rtP_attuatore_Tmax ; real_T
rtP_attuatore_Tmin ; real_T rtP_baccxINI ; real_T rtP_baccyINI ; real_T
rtP_bacczINI ; real_T rtP_bias [ 6 ] ; real_T rtP_bpINI ; real_T rtP_bqINI ;
real_T rtP_brINI ; real_T rtP_final_h ; real_T rtP_interventoA_05 ; real_T
rtP_interventoA_1 ; real_T rtP_interventoE_05 ; real_T rtP_interventoE_1 ;
real_T rtP_interventoT ; real_T rtP_inv_A ; real_T rtP_inv_E ; real_T
rtP_inv_R ; real_T rtP_inv_T ; real_T rtP_inv_comp_h ; real_T rtP_safe_V ;
real_T rtP_safe_phi ; real_T rtP_t_AP ; real_T rtP_theta_rot ; real_T
rtP_time_alarm_SAFE ; real_T rtP_vd_ini ; real_T rtP_vel_wp1_al ; real_T
rtP_vel_wp2_al ; real32_T rtP_K_imb_inv ; real32_T rtP_Kd_AP_rotta ; real32_T
rtP_Ki_AP_vel ; real32_T rtP_Ki_becch ; real32_T rtP_Ki_roll ; real32_T
rtP_Kp_AP_rotta ; real32_T rtP_Kp_AP_vel ; real32_T rtP_Kp_becch ; real32_T
rtP_Kp_imb ; real32_T rtP_Kp_p ; real32_T rtP_Kp_q ; real32_T rtP_Kp_roll ;
const char * rt_GetMatSignalLoggingFileName ( void ) { return NULL ; } const
char * rt_GetMatSigLogSelectorFileName ( void ) { return NULL ; } void *
rt_GetOSigstreamManager ( void ) { return NULL ; } void * rt_slioCatalogue (
void ) { return NULL ; } void * rtwGetPointerFromUniquePtr ( void * uniquePtr
) { return NULL ; } void * CreateDiagnosticAsVoidPtr ( const char * id , int
nargs , ... ) { void * voidPtrDiagnostic = NULL ; va_list args ; va_start (
args , nargs ) ; slmrCreateDiagnostic ( id , nargs , args , &
voidPtrDiagnostic ) ; va_end ( args ) ; return voidPtrDiagnostic ; } void
rt_ssSet_slErrMsg ( SimStruct * S , void * diag ) { if ( !
_ssIsErrorStatusAslErrMsg ( S ) ) { _ssSet_slLocalErrMsg ( S , diag ) ; }
else { _ssDiscardDiagnostic ( S , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( SimStruct * S , void * diag ) {
_ssReportDiagnosticAsWarning ( S , diag ) ; } const char *
rt_CreateFullPathToTop ( const char * toppath , const char * subpath ) { char
* fullpath = NULL ; slmrCreateFullPathToTop ( toppath , subpath , & fullpath
) ; return fullpath ; } boolean_T slIsRapidAcceleratorSimulating ( void ) {
return false ; } void rt_RAccelReplaceFromFilename ( const char * blockpath ,
char * fileName ) { ( void ) blockpath ; ( void ) fileName ; } void
rt_RAccelReplaceToFilename ( const char * blockpath , char * fileName ) { (
void ) blockpath ; ( void ) fileName ; }
#define MDL_PROCESS_PARAMETERS
#if defined(MATLAB_MEX_FILE)
static void mdlProcessParameters ( SimStruct * S ) { real_T * GlobalPrm_0 = (
real_T * ) NULL ; real_T * GlobalPrm_1 = ( real_T * ) NULL ; real_T *
GlobalPrm_2 = ( real_T * ) NULL ; real_T * GlobalPrm_3 = ( real_T * ) NULL ;
real_T * GlobalPrm_4 = ( real_T * ) NULL ; real_T * GlobalPrm_5 = ( real_T *
) NULL ; real_T * GlobalPrm_6 = ( real_T * ) NULL ; real_T * GlobalPrm_7 = (
real_T * ) NULL ; real_T * GlobalPrm_8 = ( real_T * ) NULL ; real_T *
GlobalPrm_9 = ( real_T * ) NULL ; real_T * GlobalPrm_10 = ( real_T * ) NULL ;
real_T * GlobalPrm_11 = ( real_T * ) NULL ; real_T * GlobalPrm_12 = ( real_T
* ) NULL ; real_T * GlobalPrm_13 = ( real_T * ) NULL ; real_T * GlobalPrm_14
= ( real_T * ) NULL ; real_T * GlobalPrm_15 = ( real_T * ) NULL ; real_T *
GlobalPrm_16 = ( real_T * ) NULL ; real_T * GlobalPrm_17 = ( real_T * ) NULL
; real_T * GlobalPrm_18 = ( real_T * ) NULL ; real_T * GlobalPrm_19 = (
real_T * ) NULL ; real_T * GlobalPrm_20 = ( real_T * ) NULL ; real_T *
GlobalPrm_21 = ( real_T * ) NULL ; real_T * GlobalPrm_22 = ( real_T * ) NULL
; real_T * GlobalPrm_23 = ( real_T * ) NULL ; real_T * GlobalPrm_24 = (
real_T * ) NULL ; real_T * GlobalPrm_25 = ( real_T * ) NULL ; real_T *
GlobalPrm_26 = ( real_T * ) NULL ; real_T * GlobalPrm_27 = ( real_T * ) NULL
; real_T * GlobalPrm_28 = ( real_T * ) NULL ; real_T * GlobalPrm_29 = (
real_T * ) NULL ; real_T * GlobalPrm_30 = ( real_T * ) NULL ; real_T *
GlobalPrm_31 = ( real_T * ) NULL ; real_T * GlobalPrm_32 = ( real_T * ) NULL
; real_T * GlobalPrm_33 = ( real_T * ) NULL ; real_T * GlobalPrm_34 = (
real_T * ) NULL ; real_T * GlobalPrm_35 = ( real_T * ) NULL ; real_T *
GlobalPrm_36 = ( real_T * ) NULL ; real_T * GlobalPrm_37 = ( real_T * ) NULL
; real_T * GlobalPrm_38 = ( real_T * ) NULL ; real_T * GlobalPrm_39 = (
real_T * ) NULL ; real_T * GlobalPrm_40 = ( real_T * ) NULL ; real_T *
GlobalPrm_41 = ( real_T * ) NULL ; real_T * GlobalPrm_42 = ( real_T * ) NULL
; real_T * GlobalPrm_43 = ( real_T * ) NULL ; real_T * GlobalPrm_44 = (
real_T * ) NULL ; real_T * GlobalPrm_45 = ( real_T * ) NULL ; real_T *
GlobalPrm_46 = ( real_T * ) NULL ; real_T * GlobalPrm_47 = ( real_T * ) NULL
; real_T * GlobalPrm_48 = ( real_T * ) NULL ; real_T * GlobalPrm_49 = (
real_T * ) NULL ; real_T * GlobalPrm_50 = ( real_T * ) NULL ; real32_T *
GlobalPrm_51 = ( real32_T * ) NULL ; real32_T * GlobalPrm_52 = ( real32_T * )
NULL ; real32_T * GlobalPrm_53 = ( real32_T * ) NULL ; real32_T *
GlobalPrm_54 = ( real32_T * ) NULL ; real32_T * GlobalPrm_55 = ( real32_T * )
NULL ; real32_T * GlobalPrm_56 = ( real32_T * ) NULL ; real32_T *
GlobalPrm_57 = ( real32_T * ) NULL ; real32_T * GlobalPrm_58 = ( real32_T * )
NULL ; real32_T * GlobalPrm_59 = ( real32_T * ) NULL ; real32_T *
GlobalPrm_60 = ( real32_T * ) NULL ; real32_T * GlobalPrm_61 = ( real32_T * )
NULL ; real32_T * GlobalPrm_62 = ( real32_T * ) NULL ; if ( !
ssGetModelRefGlobalParamData ( S , 0 , ( void * * ) ( & GlobalPrm_0 ) ) )
return ; if ( GlobalPrm_0 != NULL ) { ( void ) memcpy ( & ( rtP_Kd_h_app ) ,
GlobalPrm_0 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S
, 1 , ( void * * ) ( & GlobalPrm_1 ) ) ) return ; if ( GlobalPrm_1 != NULL )
{ ( void ) memcpy ( & ( rtP_Kd_h_flare ) , GlobalPrm_1 , sizeof ( real_T ) )
; } if ( ! ssGetModelRefGlobalParamData ( S , 2 , ( void * * ) ( &
GlobalPrm_2 ) ) ) return ; if ( GlobalPrm_2 != NULL ) { ( void ) memcpy ( & (
rtP_Ki_AP_rotta ) , GlobalPrm_2 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 3 , ( void * * ) ( & GlobalPrm_3 ) ) )
return ; if ( GlobalPrm_3 != NULL ) { ( void ) memcpy ( & ( rtP_Ki_h_app ) ,
GlobalPrm_3 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S
, 4 , ( void * * ) ( & GlobalPrm_4 ) ) ) return ; if ( GlobalPrm_4 != NULL )
{ ( void ) memcpy ( & ( rtP_Ki_h_cruise ) , GlobalPrm_4 , sizeof ( real_T ) )
; } if ( ! ssGetModelRefGlobalParamData ( S , 5 , ( void * * ) ( &
GlobalPrm_5 ) ) ) return ; if ( GlobalPrm_5 != NULL ) { ( void ) memcpy ( & (
rtP_Ki_h_flare ) , GlobalPrm_5 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 6 , ( void * * ) ( & GlobalPrm_6 ) ) )
return ; if ( GlobalPrm_6 != NULL ) { ( void ) memcpy ( & (
rtP_Kp_AP_quota_hold_h ) , GlobalPrm_6 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 7 , ( void * * ) ( & GlobalPrm_7 ) ) )
return ; if ( GlobalPrm_7 != NULL ) { ( void ) memcpy ( & (
rtP_Kp_AP_quota_hold_l ) , GlobalPrm_7 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 8 , ( void * * ) ( & GlobalPrm_8 ) ) )
return ; if ( GlobalPrm_8 != NULL ) { ( void ) memcpy ( & ( rtP_Kp_Rotta_ATO
) , GlobalPrm_8 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData
( S , 9 , ( void * * ) ( & GlobalPrm_9 ) ) ) return ; if ( GlobalPrm_9 !=
NULL ) { ( void ) memcpy ( & ( rtP_Kp_Rotta_psi ) , GlobalPrm_9 , sizeof (
real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S , 10 , ( void * * ) (
& GlobalPrm_10 ) ) ) return ; if ( GlobalPrm_10 != NULL ) { ( void ) memcpy (
& ( rtP_Kp_comp_h ) , GlobalPrm_10 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 11 , ( void * * ) ( & GlobalPrm_11 ) ) )
return ; if ( GlobalPrm_11 != NULL ) { ( void ) memcpy ( & ( rtP_Kp_h_cruise
) , GlobalPrm_11 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 12 , ( void * * ) ( & GlobalPrm_12 ) ) )
return ; if ( GlobalPrm_12 != NULL ) { ( void ) memcpy ( & ( rtP_Kp_h_flare )
, GlobalPrm_12 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData
( S , 13 , ( void * * ) ( & GlobalPrm_13 ) ) ) return ; if ( GlobalPrm_13 !=
NULL ) { ( void ) memcpy ( & ( rtP_Q1B [ 0 ] ) , GlobalPrm_13 , sizeof (
real_T ) * 18 ) ; } if ( ! ssGetModelRefGlobalParamData ( S , 14 , ( void * *
) ( & GlobalPrm_14 ) ) ) return ; if ( GlobalPrm_14 != NULL ) { ( void )
memcpy ( & ( rtP_R1B [ 0 ] ) , GlobalPrm_14 , sizeof ( real_T ) * 11 ) ; } if
( ! ssGetModelRefGlobalParamData ( S , 15 , ( void * * ) ( & GlobalPrm_15 ) )
) return ; if ( GlobalPrm_15 != NULL ) { ( void ) memcpy ( & (
rtP_Sensor_Offsets [ 0 ] ) , GlobalPrm_15 , sizeof ( real_T ) * 3 ) ; } if (
! ssGetModelRefGlobalParamData ( S , 16 , ( void * * ) ( & GlobalPrm_16 ) ) )
return ; if ( GlobalPrm_16 != NULL ) { ( void ) memcpy ( & ( rtP_V_stall ) ,
GlobalPrm_16 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 17 , ( void * * ) ( & GlobalPrm_17 ) ) ) return ; if ( GlobalPrm_17 !=
NULL ) { ( void ) memcpy ( & ( rtP_attuatore_Amax ) , GlobalPrm_17 , sizeof (
real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S , 18 , ( void * * ) (
& GlobalPrm_18 ) ) ) return ; if ( GlobalPrm_18 != NULL ) { ( void ) memcpy (
& ( rtP_attuatore_Amin ) , GlobalPrm_18 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 19 , ( void * * ) ( & GlobalPrm_19 ) ) )
return ; if ( GlobalPrm_19 != NULL ) { ( void ) memcpy ( & (
rtP_attuatore_Emax ) , GlobalPrm_19 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 20 , ( void * * ) ( & GlobalPrm_20 ) ) )
return ; if ( GlobalPrm_20 != NULL ) { ( void ) memcpy ( & (
rtP_attuatore_Emin ) , GlobalPrm_20 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 21 , ( void * * ) ( & GlobalPrm_21 ) ) )
return ; if ( GlobalPrm_21 != NULL ) { ( void ) memcpy ( & (
rtP_attuatore_Rmax ) , GlobalPrm_21 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 22 , ( void * * ) ( & GlobalPrm_22 ) ) )
return ; if ( GlobalPrm_22 != NULL ) { ( void ) memcpy ( & (
rtP_attuatore_Rmin ) , GlobalPrm_22 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 23 , ( void * * ) ( & GlobalPrm_23 ) ) )
return ; if ( GlobalPrm_23 != NULL ) { ( void ) memcpy ( & (
rtP_attuatore_Tmax ) , GlobalPrm_23 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 24 , ( void * * ) ( & GlobalPrm_24 ) ) )
return ; if ( GlobalPrm_24 != NULL ) { ( void ) memcpy ( & (
rtP_attuatore_Tmin ) , GlobalPrm_24 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 25 , ( void * * ) ( & GlobalPrm_25 ) ) )
return ; if ( GlobalPrm_25 != NULL ) { ( void ) memcpy ( & ( rtP_baccxINI ) ,
GlobalPrm_25 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 26 , ( void * * ) ( & GlobalPrm_26 ) ) ) return ; if ( GlobalPrm_26 !=
NULL ) { ( void ) memcpy ( & ( rtP_baccyINI ) , GlobalPrm_26 , sizeof (
real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S , 27 , ( void * * ) (
& GlobalPrm_27 ) ) ) return ; if ( GlobalPrm_27 != NULL ) { ( void ) memcpy (
& ( rtP_bacczINI ) , GlobalPrm_27 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 28 , ( void * * ) ( & GlobalPrm_28 ) ) )
return ; if ( GlobalPrm_28 != NULL ) { ( void ) memcpy ( & ( rtP_bias [ 0 ] )
, GlobalPrm_28 , sizeof ( real_T ) * 6 ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 29 , ( void * * ) ( & GlobalPrm_29 ) ) )
return ; if ( GlobalPrm_29 != NULL ) { ( void ) memcpy ( & ( rtP_bpINI ) ,
GlobalPrm_29 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 30 , ( void * * ) ( & GlobalPrm_30 ) ) ) return ; if ( GlobalPrm_30 !=
NULL ) { ( void ) memcpy ( & ( rtP_bqINI ) , GlobalPrm_30 , sizeof ( real_T )
) ; } if ( ! ssGetModelRefGlobalParamData ( S , 31 , ( void * * ) ( &
GlobalPrm_31 ) ) ) return ; if ( GlobalPrm_31 != NULL ) { ( void ) memcpy ( &
( rtP_brINI ) , GlobalPrm_31 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 32 , ( void * * ) ( & GlobalPrm_32 ) ) )
return ; if ( GlobalPrm_32 != NULL ) { ( void ) memcpy ( & ( rtP_final_h ) ,
GlobalPrm_32 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 33 , ( void * * ) ( & GlobalPrm_33 ) ) ) return ; if ( GlobalPrm_33 !=
NULL ) { ( void ) memcpy ( & ( rtP_interventoA_05 ) , GlobalPrm_33 , sizeof (
real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S , 34 , ( void * * ) (
& GlobalPrm_34 ) ) ) return ; if ( GlobalPrm_34 != NULL ) { ( void ) memcpy (
& ( rtP_interventoA_1 ) , GlobalPrm_34 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 35 , ( void * * ) ( & GlobalPrm_35 ) ) )
return ; if ( GlobalPrm_35 != NULL ) { ( void ) memcpy ( & (
rtP_interventoE_05 ) , GlobalPrm_35 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 36 , ( void * * ) ( & GlobalPrm_36 ) ) )
return ; if ( GlobalPrm_36 != NULL ) { ( void ) memcpy ( & (
rtP_interventoE_1 ) , GlobalPrm_36 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 37 , ( void * * ) ( & GlobalPrm_37 ) ) )
return ; if ( GlobalPrm_37 != NULL ) { ( void ) memcpy ( & ( rtP_interventoT
) , GlobalPrm_37 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 38 , ( void * * ) ( & GlobalPrm_38 ) ) )
return ; if ( GlobalPrm_38 != NULL ) { ( void ) memcpy ( & ( rtP_inv_A ) ,
GlobalPrm_38 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 39 , ( void * * ) ( & GlobalPrm_39 ) ) ) return ; if ( GlobalPrm_39 !=
NULL ) { ( void ) memcpy ( & ( rtP_inv_E ) , GlobalPrm_39 , sizeof ( real_T )
) ; } if ( ! ssGetModelRefGlobalParamData ( S , 40 , ( void * * ) ( &
GlobalPrm_40 ) ) ) return ; if ( GlobalPrm_40 != NULL ) { ( void ) memcpy ( &
( rtP_inv_R ) , GlobalPrm_40 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 41 , ( void * * ) ( & GlobalPrm_41 ) ) )
return ; if ( GlobalPrm_41 != NULL ) { ( void ) memcpy ( & ( rtP_inv_T ) ,
GlobalPrm_41 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 42 , ( void * * ) ( & GlobalPrm_42 ) ) ) return ; if ( GlobalPrm_42 !=
NULL ) { ( void ) memcpy ( & ( rtP_inv_comp_h ) , GlobalPrm_42 , sizeof (
real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S , 43 , ( void * * ) (
& GlobalPrm_43 ) ) ) return ; if ( GlobalPrm_43 != NULL ) { ( void ) memcpy (
& ( rtP_safe_V ) , GlobalPrm_43 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 44 , ( void * * ) ( & GlobalPrm_44 ) ) )
return ; if ( GlobalPrm_44 != NULL ) { ( void ) memcpy ( & ( rtP_safe_phi ) ,
GlobalPrm_44 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 45 , ( void * * ) ( & GlobalPrm_45 ) ) ) return ; if ( GlobalPrm_45 !=
NULL ) { ( void ) memcpy ( & ( rtP_t_AP ) , GlobalPrm_45 , sizeof ( real_T )
) ; } if ( ! ssGetModelRefGlobalParamData ( S , 46 , ( void * * ) ( &
GlobalPrm_46 ) ) ) return ; if ( GlobalPrm_46 != NULL ) { ( void ) memcpy ( &
( rtP_theta_rot ) , GlobalPrm_46 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 47 , ( void * * ) ( & GlobalPrm_47 ) ) )
return ; if ( GlobalPrm_47 != NULL ) { ( void ) memcpy ( & (
rtP_time_alarm_SAFE ) , GlobalPrm_47 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 48 , ( void * * ) ( & GlobalPrm_48 ) ) )
return ; if ( GlobalPrm_48 != NULL ) { ( void ) memcpy ( & ( rtP_vd_ini ) ,
GlobalPrm_48 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 49 , ( void * * ) ( & GlobalPrm_49 ) ) ) return ; if ( GlobalPrm_49 !=
NULL ) { ( void ) memcpy ( & ( rtP_vel_wp1_al ) , GlobalPrm_49 , sizeof (
real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S , 50 , ( void * * ) (
& GlobalPrm_50 ) ) ) return ; if ( GlobalPrm_50 != NULL ) { ( void ) memcpy (
& ( rtP_vel_wp2_al ) , GlobalPrm_50 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 51 , ( void * * ) ( & GlobalPrm_51 ) ) )
return ; if ( GlobalPrm_51 != NULL ) { ( void ) memcpy ( & ( rtP_K_imb_inv )
, GlobalPrm_51 , sizeof ( real32_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 52 , ( void * * ) ( & GlobalPrm_52 ) ) )
return ; if ( GlobalPrm_52 != NULL ) { ( void ) memcpy ( & ( rtP_Kd_AP_rotta
) , GlobalPrm_52 , sizeof ( real32_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 53 , ( void * * ) ( & GlobalPrm_53 ) ) )
return ; if ( GlobalPrm_53 != NULL ) { ( void ) memcpy ( & ( rtP_Ki_AP_vel )
, GlobalPrm_53 , sizeof ( real32_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 54 , ( void * * ) ( & GlobalPrm_54 ) ) )
return ; if ( GlobalPrm_54 != NULL ) { ( void ) memcpy ( & ( rtP_Ki_becch ) ,
GlobalPrm_54 , sizeof ( real32_T ) ) ; } if ( ! ssGetModelRefGlobalParamData
( S , 55 , ( void * * ) ( & GlobalPrm_55 ) ) ) return ; if ( GlobalPrm_55 !=
NULL ) { ( void ) memcpy ( & ( rtP_Ki_roll ) , GlobalPrm_55 , sizeof (
real32_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S , 56 , ( void * * )
( & GlobalPrm_56 ) ) ) return ; if ( GlobalPrm_56 != NULL ) { ( void ) memcpy
( & ( rtP_Kp_AP_rotta ) , GlobalPrm_56 , sizeof ( real32_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 57 , ( void * * ) ( & GlobalPrm_57 ) ) )
return ; if ( GlobalPrm_57 != NULL ) { ( void ) memcpy ( & ( rtP_Kp_AP_vel )
, GlobalPrm_57 , sizeof ( real32_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 58 , ( void * * ) ( & GlobalPrm_58 ) ) )
return ; if ( GlobalPrm_58 != NULL ) { ( void ) memcpy ( & ( rtP_Kp_becch ) ,
GlobalPrm_58 , sizeof ( real32_T ) ) ; } if ( ! ssGetModelRefGlobalParamData
( S , 59 , ( void * * ) ( & GlobalPrm_59 ) ) ) return ; if ( GlobalPrm_59 !=
NULL ) { ( void ) memcpy ( & ( rtP_Kp_imb ) , GlobalPrm_59 , sizeof (
real32_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S , 60 , ( void * * )
( & GlobalPrm_60 ) ) ) return ; if ( GlobalPrm_60 != NULL ) { ( void ) memcpy
( & ( rtP_Kp_p ) , GlobalPrm_60 , sizeof ( real32_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 61 , ( void * * ) ( & GlobalPrm_61 ) ) )
return ; if ( GlobalPrm_61 != NULL ) { ( void ) memcpy ( & ( rtP_Kp_q ) ,
GlobalPrm_61 , sizeof ( real32_T ) ) ; } if ( ! ssGetModelRefGlobalParamData
( S , 62 , ( void * * ) ( & GlobalPrm_62 ) ) ) return ; if ( GlobalPrm_62 !=
NULL ) { ( void ) memcpy ( & ( rtP_Kp_roll ) , GlobalPrm_62 , sizeof (
real32_T ) ) ; } }
#endif
static void mdlInitializeConditions ( SimStruct * S ) { real_T * o_o_o_B_92_1
= ( real_T * ) ssGetOutputPortSignal ( S , 0 ) ; real_T * o_o_B_92_7 = (
real_T * ) ssGetOutputPortSignal ( S , 6 ) ; hdbdnnc1bw ( o_o_o_B_92_1 ,
o_o_B_92_7 ) ; } static void mdlReset ( SimStruct * S ) { n4k20lums0 ( ) ; }
static void mdlPeriodicOutputUpdate ( SimStruct * S , int_T tid ) { const
real_T * i_lcwcddmbya = ( real_T * ) ssGetInputPortSignal ( S , 0 ) ; const
real_T * i_fd3br4i32c = ( real_T * ) ssGetInputPortSignal ( S , 1 ) ; const
real_T * i_ffkjxqeop1 = ( real_T * ) ssGetInputPortSignal ( S , 2 ) ; const
real_T * i_nanuuj1tnd = ( real_T * ) ssGetInputPortSignal ( S , 3 ) ; const
real_T * i_bxral4hgrz = ( real_T * ) ssGetInputPortSignal ( S , 4 ) ; const
real_T * i_eu21eboubk = ( real_T * ) ssGetInputPortSignal ( S , 5 ) ; const
real_T * i_dwq1mczsmn = ( real_T * ) ssGetInputPortSignal ( S , 6 ) ; const
real_T * i_lvhq4k1eug = ( real_T * ) ssGetInputPortSignal ( S , 7 ) ; const
real_T * i_lm4kmimu1x = ( real_T * ) ssGetInputPortSignal ( S , 8 ) ; const
real_T * i_km1ryrl0pt = ( real_T * ) ssGetInputPortSignal ( S , 9 ) ; const
real_T * i_akbexjfodr = ( real_T * ) ssGetInputPortSignal ( S , 10 ) ; const
real_T * i_o1igehji3g = ( real_T * ) ssGetInputPortSignal ( S , 11 ) ; const
real_T * i_epyl3gvmyu = ( real_T * ) ssGetInputPortSignal ( S , 12 ) ; const
real_T * i_k3pn3kzmcr = ( real_T * ) ssGetInputPortSignal ( S , 13 ) ; const
real_T * i_ivpit4zpgt = ( real_T * ) ssGetInputPortSignal ( S , 14 ) ; const
real_T * i_c3cvgtg0ct = ( real_T * ) ssGetInputPortSignal ( S , 15 ) ; const
real_T * i_ibhkbq4xua = ( real_T * ) ssGetInputPortSignal ( S , 16 ) ; const
real_T * i_ii3u4smzmz = ( real_T * ) ssGetInputPortSignal ( S , 17 ) ; const
real_T * i_ek4meo4qey = ( real_T * ) ssGetInputPortSignal ( S , 18 ) ; const
real_T * i_evaxkrd3tv = ( real_T * ) ssGetInputPortSignal ( S , 19 ) ; const
real_T * i_kgr2gb0jmq = ( real_T * ) ssGetInputPortSignal ( S , 20 ) ; const
real_T * i_b30astadhu = ( real_T * ) ssGetInputPortSignal ( S , 21 ) ; const
real_T * i_n4z4mjt2yn = ( real_T * ) ssGetInputPortSignal ( S , 22 ) ; const
real_T * i_i_jqwslt1tlw = ( real_T * ) ssGetInputPortSignal ( S , 23 ) ;
const real_T * i_i_lvvzbeyfcm = ( real_T * ) ssGetInputPortSignal ( S , 24 )
; const real_T * i_i_mi1crc0chq = ( real_T * ) ssGetInputPortSignal ( S , 25
) ; const real_T * i_i_kuebpi3jox = ( real_T * ) ssGetInputPortSignal ( S ,
26 ) ; const real_T * i_i_kqaxdqvrdg = ( real_T * ) ssGetInputPortSignal ( S
, 27 ) ; const real_T * i_i_d0jgwfjaph = ( real_T * ) ssGetInputPortSignal (
S , 28 ) ; const real_T * i_i_clby42s5l2 = ( real_T * ) ssGetInputPortSignal
( S , 29 ) ; const real_T * i_i_oyogz13iye = ( real_T * )
ssGetInputPortSignal ( S , 30 ) ; const real_T * i_i_dxaha3ieqk = ( real_T *
) ssGetInputPortSignal ( S , 32 ) ; const real_T * i_i_kwvudobtug = ( real_T
* ) ssGetInputPortSignal ( S , 33 ) ; const real_T * i_i_ioh4lthept = (
real_T * ) ssGetInputPortSignal ( S , 34 ) ; const real_T * i_i_dlhgl0hdon =
( real_T * ) ssGetInputPortSignal ( S , 35 ) ; const real_T * i_i_l53ill41px
= ( real_T * ) ssGetInputPortSignal ( S , 36 ) ; const real_T *
i_i_btjcnujjde = ( real_T * ) ssGetInputPortSignal ( S , 37 ) ; const real_T
* i_m4seftq00f = ( real_T * ) ssGetInputPortSignal ( S , 38 ) ; const real_T
* i_cwxykztlav = ( real_T * ) ssGetInputPortSignal ( S , 43 ) ; const real_T
* i_afffgoodhw = ( real_T * ) ssGetInputPortSignal ( S , 44 ) ; real_T *
o_o_o_B_92_1 = ( real_T * ) ssGetOutputPortSignal ( S , 0 ) ; real_T *
o_B_92_2 = ( real_T * ) ssGetOutputPortSignal ( S , 1 ) ; real_T * o_B_92_3 =
( real_T * ) ssGetOutputPortSignal ( S , 2 ) ; real_T * o_B_92_4 = ( real_T *
) ssGetOutputPortSignal ( S , 3 ) ; real_T * o_B_92_5 = ( real_T * )
ssGetOutputPortSignal ( S , 4 ) ; real_T * o_B_92_6 = ( real_T * )
ssGetOutputPortSignal ( S , 5 ) ; real_T * o_o_B_92_7 = ( real_T * )
ssGetOutputPortSignal ( S , 6 ) ; const real_T * i_p5mrrf5qyd = ( real_T * )
ssGetInputPortSignal ( S , 39 ) ; const real_T * i_aj23mpuv25 = ( real_T * )
ssGetInputPortSignal ( S , 40 ) ; const real_T * i_hw25mlmm1i = ( real_T * )
ssGetInputPortSignal ( S , 41 ) ; const real_T * i_key2gsbkm0 = ( real_T * )
ssGetInputPortSignal ( S , 42 ) ; if ( tid == 0 ) { autopilota_v_15_last (
i_lcwcddmbya , i_fd3br4i32c , i_ffkjxqeop1 , i_nanuuj1tnd , i_bxral4hgrz ,
i_eu21eboubk , i_dwq1mczsmn , i_lvhq4k1eug , i_lm4kmimu1x , i_km1ryrl0pt ,
i_akbexjfodr , i_o1igehji3g , i_epyl3gvmyu , i_k3pn3kzmcr , i_ivpit4zpgt ,
i_c3cvgtg0ct , i_ibhkbq4xua , i_ii3u4smzmz , i_ek4meo4qey , i_evaxkrd3tv ,
i_kgr2gb0jmq , i_b30astadhu , i_n4z4mjt2yn , i_i_jqwslt1tlw , i_i_lvvzbeyfcm
, i_i_mi1crc0chq , i_i_kuebpi3jox , i_i_kqaxdqvrdg , i_i_d0jgwfjaph ,
i_i_clby42s5l2 , i_i_oyogz13iye , i_i_dxaha3ieqk , i_i_kwvudobtug ,
i_i_ioh4lthept , i_i_dlhgl0hdon , i_i_l53ill41px , i_i_btjcnujjde ,
i_m4seftq00f , i_cwxykztlav , i_afffgoodhw , o_o_o_B_92_1 , o_B_92_2 ,
o_B_92_3 , o_B_92_4 , o_B_92_5 , o_B_92_6 , o_o_B_92_7 ) ; pjvl4fhogu (
i_i_jqwslt1tlw , i_i_lvvzbeyfcm , i_i_mi1crc0chq , i_i_kuebpi3jox ,
i_i_kqaxdqvrdg , i_i_d0jgwfjaph , i_i_clby42s5l2 , i_i_oyogz13iye ,
i_i_dxaha3ieqk , i_i_kwvudobtug , i_i_ioh4lthept , i_i_dlhgl0hdon ,
i_i_l53ill41px , i_i_btjcnujjde , i_p5mrrf5qyd , i_aj23mpuv25 , i_hw25mlmm1i
, i_key2gsbkm0 ) ; } } static void mdlInitializeSizes ( SimStruct * S ) { if
( ( S -> mdlInfo -> genericFcn != ( NULL ) ) && ( ! ( S -> mdlInfo ->
genericFcn ) ( S , GEN_FCN_CHK_MODELREF_SFUN_HAS_MODEL_BLOCK , - 1 , ( NULL )
) ) ) { return ; } ssSetNumSFcnParams ( S , 0 ) ;
ssFxpSetU32BitRegionCompliant ( S , 1 ) ; rt_InitInfAndNaN ( sizeof ( real_T
) ) ; if ( S -> mdlInfo -> genericFcn != ( NULL ) ) { _GenericFcn fcn = S ->
mdlInfo -> genericFcn ; } ssSetRTWGeneratedSFcn ( S , 2 ) ;
ssSetNumContStates ( S , 0 ) ; ssSetNumDiscStates ( S , 0 ) ;
ssSetSymbolicDimsSupport ( S , true ) ; slmrInitializeIOPortDataVectors ( S ,
45 , 7 ) ; if ( ! ssSetNumInputPorts ( S , 45 ) ) return ; if ( !
ssSetInputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 0 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 0 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 0 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 0 , 1 ) ; ssSetInputPortOptimOpts ( S
, 0 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 0 ,
false ) ; ssSetInputPortSampleTime ( S , 0 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 0 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 1 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 1 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 1 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 1 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 1 , 1 ) ; ssSetInputPortOptimOpts ( S
, 1 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 1 ,
false ) ; ssSetInputPortSampleTime ( S , 1 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 1 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 2 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 2 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 2 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 2 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 2 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 2 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 2 , 1 ) ; ssSetInputPortOptimOpts ( S
, 2 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 2 ,
false ) ; ssSetInputPortSampleTime ( S , 2 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 2 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 3 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 3 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 3 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 3 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 3 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 3 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 3 , 1 ) ; ssSetInputPortOptimOpts ( S
, 3 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 3 ,
false ) ; ssSetInputPortSampleTime ( S , 3 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 3 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 4 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 4 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 4 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 4 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 4 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 4 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 4 , 1 ) ; ssSetInputPortOptimOpts ( S
, 4 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 4 ,
false ) ; ssSetInputPortSampleTime ( S , 4 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 4 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 5 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 5 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 5 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 5 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 5 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 5 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 5 , 1 ) ; ssSetInputPortOptimOpts ( S
, 5 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 5 ,
false ) ; ssSetInputPortSampleTime ( S , 5 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 5 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 6 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 6 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 6 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 6 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 6 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 6 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 6 , 1 ) ; ssSetInputPortOptimOpts ( S
, 6 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 6 ,
false ) ; ssSetInputPortSampleTime ( S , 6 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 6 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 7 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 7 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 7 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 7 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 7 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 7 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 7 , 1 ) ; ssSetInputPortOptimOpts ( S
, 7 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 7 ,
false ) ; ssSetInputPortSampleTime ( S , 7 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 7 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 8 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 8 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 8 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 8 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 8 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 8 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 8 , 1 ) ; ssSetInputPortOptimOpts ( S
, 8 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 8 ,
false ) ; ssSetInputPortSampleTime ( S , 8 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 8 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 9 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 9 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 9 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 9 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 9 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 9 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 9 , 1 ) ; ssSetInputPortOptimOpts ( S
, 9 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 9 ,
false ) ; ssSetInputPortSampleTime ( S , 9 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 9 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 10 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 10 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 10 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 10 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 10 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 10 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 10 , 1 ) ; ssSetInputPortOptimOpts ( S
, 10 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 10 ,
false ) ; ssSetInputPortSampleTime ( S , 10 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 10 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 11 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 11 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 11 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 11 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 11 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 11 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 11 , 1 ) ; ssSetInputPortOptimOpts ( S
, 11 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 11 ,
false ) ; ssSetInputPortSampleTime ( S , 11 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 11 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 12 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 12 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 12 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 12 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 12 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 12 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 12 , 1 ) ; ssSetInputPortOptimOpts ( S
, 12 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 12 ,
false ) ; ssSetInputPortSampleTime ( S , 12 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 12 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 13 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 13 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 13 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 13 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 13 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 13 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 13 , 1 ) ; ssSetInputPortOptimOpts ( S
, 13 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 13 ,
false ) ; ssSetInputPortSampleTime ( S , 13 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 13 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 14 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 14 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 14 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 14 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 14 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 14 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 14 , 1 ) ; ssSetInputPortOptimOpts ( S
, 14 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 14 ,
false ) ; ssSetInputPortSampleTime ( S , 14 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 14 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 15 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 15 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 15 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 15 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 15 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 15 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 15 , 1 ) ; ssSetInputPortOptimOpts ( S
, 15 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 15 ,
false ) ; ssSetInputPortSampleTime ( S , 15 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 15 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 16 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 16 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 16 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 16 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 16 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 16 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 16 , 1 ) ; ssSetInputPortOptimOpts ( S
, 16 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 16 ,
false ) ; ssSetInputPortSampleTime ( S , 16 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 16 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 17 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 17 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 17 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 17 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 17 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 17 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 17 , 1 ) ; ssSetInputPortOptimOpts ( S
, 17 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 17 ,
false ) ; ssSetInputPortSampleTime ( S , 17 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 17 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 18 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 18 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 18 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 18 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 18 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 18 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 18 , 1 ) ; ssSetInputPortOptimOpts ( S
, 18 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 18 ,
false ) ; ssSetInputPortSampleTime ( S , 18 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 18 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 19 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 19 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 19 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 19 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 19 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 19 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 19 , 1 ) ; ssSetInputPortOptimOpts ( S
, 19 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 19 ,
false ) ; ssSetInputPortSampleTime ( S , 19 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 19 , 0.0 ) ; if ( !
ssSetInputPortMatrixDimensions ( S , 20 , 4 , 6 ) ) return ;
ssSetInputPortDimensionsMode ( S , 20 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 20 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 20 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 20 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 20 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 20 , 1 ) ; ssSetInputPortOptimOpts ( S
, 20 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 20 ,
false ) ; ssSetInputPortSampleTime ( S , 20 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 20 , 0.0 ) ; if ( !
ssSetInputPortMatrixDimensions ( S , 21 , 4 , 7 ) ) return ;
ssSetInputPortDimensionsMode ( S , 21 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 21 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 21 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 21 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 21 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 21 , 1 ) ; ssSetInputPortOptimOpts ( S
, 21 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 21 ,
false ) ; ssSetInputPortSampleTime ( S , 21 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 21 , 0.0 ) ; if ( !
ssSetInputPortMatrixDimensions ( S , 22 , 2 , 7 ) ) return ;
ssSetInputPortDimensionsMode ( S , 22 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 22 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 22 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 22 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 22 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 22 , 1 ) ; ssSetInputPortOptimOpts ( S
, 22 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 22 ,
false ) ; ssSetInputPortSampleTime ( S , 22 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 22 , 0.0 ) ; if ( !
ssSetInputPortMatrixDimensions ( S , 23 , 1 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 23 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 23 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 23 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 23 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 23 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 23 , 1 ) ; ssSetInputPortOptimOpts ( S
, 23 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 23 ,
false ) ; ssSetInputPortSampleTime ( S , 23 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 23 , 0.0 ) ; if ( !
ssSetInputPortMatrixDimensions ( S , 24 , 1 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 24 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 24 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 24 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 24 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 24 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 24 , 1 ) ; ssSetInputPortOptimOpts ( S
, 24 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 24 ,
false ) ; ssSetInputPortSampleTime ( S , 24 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 24 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 25 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 25 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 25 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 25 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 25 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 25 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 25 , 1 ) ; ssSetInputPortOptimOpts ( S
, 25 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 25 ,
false ) ; ssSetInputPortSampleTime ( S , 25 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 25 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 26 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 26 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 26 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 26 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 26 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 26 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 26 , 1 ) ; ssSetInputPortOptimOpts ( S
, 26 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 26 ,
false ) ; ssSetInputPortSampleTime ( S , 26 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 26 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 27 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 27 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 27 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 27 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 27 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 27 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 27 , 1 ) ; ssSetInputPortOptimOpts ( S
, 27 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 27 ,
false ) ; ssSetInputPortSampleTime ( S , 27 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 27 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 28 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 28 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 28 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 28 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 28 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 28 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 28 , 1 ) ; ssSetInputPortOptimOpts ( S
, 28 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 28 ,
false ) ; ssSetInputPortSampleTime ( S , 28 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 28 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 29 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 29 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 29 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 29 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 29 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 29 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 29 , 1 ) ; ssSetInputPortOptimOpts ( S
, 29 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 29 ,
false ) ; ssSetInputPortSampleTime ( S , 29 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 29 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 30 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 30 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 30 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 30 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 30 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 30 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 30 , 1 ) ; ssSetInputPortOptimOpts ( S
, 30 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 30 ,
false ) ; ssSetInputPortSampleTime ( S , 30 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 30 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 31 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 31 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 31 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 31 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 31 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 31 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 31 , 1 ) ; ssSetInputPortOptimOpts ( S
, 31 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 31 ,
false ) ; ssSetInputPortSampleTime ( S , 31 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 31 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 32 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 32 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 32 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 32 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 32 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 32 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 32 , 1 ) ; ssSetInputPortOptimOpts ( S
, 32 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 32 ,
false ) ; ssSetInputPortSampleTime ( S , 32 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 32 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 33 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 33 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 33 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 33 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 33 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 33 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 33 , 1 ) ; ssSetInputPortOptimOpts ( S
, 33 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 33 ,
false ) ; ssSetInputPortSampleTime ( S , 33 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 33 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 34 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 34 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 34 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 34 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 34 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 34 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 34 , 1 ) ; ssSetInputPortOptimOpts ( S
, 34 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 34 ,
false ) ; ssSetInputPortSampleTime ( S , 34 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 34 , 0.0 ) ; if ( !
ssSetInputPortMatrixDimensions ( S , 35 , 1 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 35 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 35 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 35 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 35 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 35 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 35 , 1 ) ; ssSetInputPortOptimOpts ( S
, 35 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 35 ,
false ) ; ssSetInputPortSampleTime ( S , 35 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 35 , 0.0 ) ; if ( !
ssSetInputPortMatrixDimensions ( S , 36 , 1 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 36 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 36 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 36 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 36 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 36 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 36 , 1 ) ; ssSetInputPortOptimOpts ( S
, 36 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 36 ,
false ) ; ssSetInputPortSampleTime ( S , 36 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 36 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 37 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 37 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 37 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 37 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 37 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 37 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 37 , 1 ) ; ssSetInputPortOptimOpts ( S
, 37 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 37 ,
false ) ; ssSetInputPortSampleTime ( S , 37 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 37 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 38 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 38 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 38 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 38 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 38 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 38 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 38 , 1 ) ; ssSetInputPortOptimOpts ( S
, 38 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 38 ,
false ) ; ssSetInputPortSampleTime ( S , 38 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 38 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 39 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 39 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 39 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 39 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 39 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 39 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 39 , 1 ) ; ssSetInputPortOptimOpts ( S
, 39 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 39 ,
false ) ; ssSetInputPortSampleTime ( S , 39 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 39 , 0.0 ) ; if ( !
ssSetInputPortMatrixDimensions ( S , 40 , 1 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 40 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 40 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 40 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 40 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 40 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 40 , 1 ) ; ssSetInputPortOptimOpts ( S
, 40 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 40 ,
false ) ; ssSetInputPortSampleTime ( S , 40 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 40 , 0.0 ) ; if ( !
ssSetInputPortMatrixDimensions ( S , 41 , 1 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 41 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 41 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 41 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 41 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 41 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 41 , 1 ) ; ssSetInputPortOptimOpts ( S
, 41 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 41 ,
false ) ; ssSetInputPortSampleTime ( S , 41 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 41 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 42 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 42 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 42 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 42 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 42 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 42 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 42 , 1 ) ; ssSetInputPortOptimOpts ( S
, 42 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 42 ,
false ) ; ssSetInputPortSampleTime ( S , 42 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 42 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 43 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 43 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 43 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 43 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 43 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 43 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 43 , 1 ) ; ssSetInputPortOptimOpts ( S
, 43 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 43 ,
false ) ; ssSetInputPortSampleTime ( S , 43 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 43 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 44 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 44 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 44 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 44 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 44 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 44 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 44 , 1 ) ; ssSetInputPortOptimOpts ( S
, 44 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 44 ,
false ) ; ssSetInputPortSampleTime ( S , 44 , 0.02 ) ;
ssSetInputPortOffsetTime ( S , 44 , 0.0 ) ; if ( ! ssSetNumOutputPorts ( S ,
7 ) ) return ; if ( ! ssSetOutputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 0 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 0 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 0 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 0 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 0 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 0 , SS_NOT_OK_TO_MERGE ) ;
ssSetOutputPortICAttributes ( S , 0 , false , true , true ) ;
ssSetOutputPortOptimOpts ( S , 0 , SS_NOT_REUSABLE_AND_GLOBAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 1 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 1 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 1 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 1 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 1 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 1 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 1 , SS_NOT_OK_TO_MERGE ) ;
ssSetOutputPortICAttributes ( S , 1 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 1 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 2 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 2 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 2 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 2 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 2 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 2 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 2 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 2 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 2 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 2 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 2 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 3 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 3 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 3 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 3 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 3 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 3 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 3 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 3 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 3 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 3 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 3 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 4 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 4 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 4 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 4 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 4 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 4 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 4 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 4 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 4 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 4 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 4 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 5 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 5 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 5 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 5 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 5 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 5 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 5 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 5 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 5 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 5 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 5 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 6 , 3 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 6 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 6 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 6 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 6 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 6 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 6 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 6 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 6 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 6 , false , true , false ) ;
ssSetOutputPortOptimOpts ( S , 6 , SS_NOT_REUSABLE_AND_LOCAL ) ;
ssSetSimStateCompliance ( S , USE_CUSTOM_SIM_STATE ) ;
mr_autopilota_v_15_last_RegisterSimStateChecksum ( S ) ; ssSetNumSampleTimes
( S , 2 ) ; ssSetParameterTuningCompliance ( S , true ) ; ssSetNumRWork ( S ,
0 ) ; ssSetNumIWork ( S , 0 ) ; ssSetNumPWork ( S , 0 ) ; ssSetNumModes ( S ,
0 ) ; { int_T zcsIdx = 0 ; zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ;
ssSetZcSignalWidth ( S , zcsIdx , 1 ) ; ssSetZcSignalName ( S , zcsIdx ,
"Input" ) ; ssSetZcSignalType ( S , zcsIdx , SL_ZCS_TYPE_DISC ) ;
ssSetZcSignalZcEventType ( S , zcsIdx , SL_ZCS_EVENT_ALL_DN ) ;
ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0 ) ; zcsIdx =
ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S , zcsIdx , 1 ) ;
ssSetZcSignalName ( S , zcsIdx , "Trig" ) ; ssSetZcSignalType ( S , zcsIdx ,
SL_ZCS_TYPE_DISC ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL_UP ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0
) ; zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S ,
zcsIdx , 1 ) ; ssSetZcSignalName ( S , zcsIdx , "Trig" ) ; ssSetZcSignalType
( S , zcsIdx , SL_ZCS_TYPE_DISC ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL_UP ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0
) ; zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S ,
zcsIdx , 1 ) ; ssSetZcSignalName ( S , zcsIdx , "Trig" ) ; ssSetZcSignalType
( S , zcsIdx , SL_ZCS_TYPE_DISC ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL_UP ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0
) ; zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S ,
zcsIdx , 1 ) ; ssSetZcSignalName ( S , zcsIdx , "Reset" ) ; ssSetZcSignalType
( S , zcsIdx , SL_ZCS_TYPE_DISC ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL_UP ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0
) ; zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S ,
zcsIdx , 1 ) ; ssSetZcSignalName ( S , zcsIdx , "Reset" ) ; ssSetZcSignalType
( S , zcsIdx , SL_ZCS_TYPE_DISC ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL_UP ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0
) ; zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S ,
zcsIdx , 1 ) ; ssSetZcSignalName ( S , zcsIdx , "Reset" ) ; ssSetZcSignalType
( S , zcsIdx , SL_ZCS_TYPE_DISC ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL_UP ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0
) ; zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S ,
zcsIdx , 1 ) ; ssSetZcSignalName ( S , zcsIdx , "Reset" ) ; ssSetZcSignalType
( S , zcsIdx , SL_ZCS_TYPE_DISC ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL_UP ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0
) ; zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S ,
zcsIdx , 1 ) ; ssSetZcSignalName ( S , zcsIdx , "Reset" ) ; ssSetZcSignalType
( S , zcsIdx , SL_ZCS_TYPE_DISC ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL_UP ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0
) ; zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S ,
zcsIdx , 1 ) ; ssSetZcSignalName ( S , zcsIdx , "Trig" ) ; ssSetZcSignalType
( S , zcsIdx , SL_ZCS_TYPE_DISC ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL_UP ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0
) ; } ssSetOutputPortIsNonContinuous ( S , 0 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 0 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 1 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 1 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 2 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 2 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 3 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 3 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 4 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 4 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 5 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 5 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 6 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 6 , 0 ) ;
ssSetInputPortIsNotDerivPort ( S , 0 , 1 ) ; ssSetInputPortIsNotDerivPort ( S
, 1 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 2 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 3 , 1 ) ; ssSetInputPortIsNotDerivPort ( S
, 4 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 5 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 6 , 1 ) ; ssSetInputPortIsNotDerivPort ( S
, 7 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 8 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 9 , 1 ) ; ssSetInputPortIsNotDerivPort ( S
, 10 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 11 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 12 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 13 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 14 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 15 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 16 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 17 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 18 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 19 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 20 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 21 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 22 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 23 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 24 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 25 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 26 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 27 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 28 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 29 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 30 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 31 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 32 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 33 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 34 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 35 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 36 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 37 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 38 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 39 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 40 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 41 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 42 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 43 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 44 , 1 ) ;
ssSetModelReferenceSampleTimeInheritanceRule ( S ,
DISALLOW_SAMPLE_TIME_INHERITANCE ) ; ssSetAcceptsFcnCallInputs ( S ) ;
ssSetModelReferenceNormalModeSupport ( S ,
MDL_START_AND_MDL_PROCESS_PARAMS_OK ) ; ssSupportsMultipleExecInstances ( S ,
false ) ; ssRegisterMsgForNotSupportingMultiExecInst ( S ,
 "<diag_root><diag id=\"Simulink:blocks:ImplicitIterSS_SignalViewNotSupportedInside\" pr=\"d\"><arguments><arg type=\"numeric\">1</arg><arg type=\"encoded\">YQB1AHQAbwBwAGkAbABvAHQAYQBfAHYAXwAxADUAXwBsAGEAcwB0AC8ATQBJAFMAVQBSAEUAIABEAEEAIABTAEUATgBTAE8AUgBJACAAIABGAEkATABUAFIAQQBUAEUALwBEAGkAcwBjAHIAZQB0AGUAIABWAGEAcgB5AGkAbgBnACAATABvAHcAcABhAHMAcwAAAA==</arg><arg type=\"encoded\">PABfAF8AaQBpAFMAUwBfAF8APgA8AC8AXwBfAGkAaQBTAFMAXwBfAD4AAAA=</arg><arg type=\"encoded\">PABfAF8AaQB0AGUAcgBCAGwAawBfAF8APgA8AC8AXwBfAGkAdABlAHIAQgBsAGsAXwBfAD4AAAA=</arg></arguments><hs><h>AAAACADYyUD+</h></hs></diag></diag_root>"
) ; ssHasStateInsideForEachSS ( S , false ) ; ssSetOptions ( S ,
SS_OPTION_ALLOW_CONSTANT_PORT_SAMPLE_TIME |
SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED | SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES |
SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME | SS_OPTION_EXCEPTION_FREE_CODE |
SS_OPTION_WORKS_WITH_CODE_REUSE ) ;
#if SS_SFCN_FOR_SIM
if ( S -> mdlInfo -> genericFcn != ( NULL ) && ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { int_T retVal = 1 ;
mr_autopilota_v_15_last_MdlInfoRegFcn ( S , "autopilota_v_15_last" , & retVal
) ; if ( ! retVal ) return ; }
#endif
ssSetNumDWork ( S , 0 ) ; slmrRegisterSystemInitializeMethod ( S ,
mdlInitializeConditions ) ; slmrRegisterSystemResetMethod ( S , mdlReset ) ;
slmrRegisterPeriodicOutputUpdateMethod ( S , mdlPeriodicOutputUpdate ) ;
ssSetSimulinkVersionGeneratedIn ( S , "10.2" ) ; ssSetNeedAbsoluteTime ( S ,
1 ) ; } static void mdlInitializeSampleTimes ( SimStruct * S ) {
ssSetSampleTime ( S , 0 , 0.02 ) ; ssSetOffsetTime ( S , 0 , 0 ) ;
ssSetSampleTime ( S , 1 , mxGetInf ( ) ) ; ssSetOffsetTime ( S , 1 , 0 ) ;
return ; }
#define MDL_SET_WORK_WIDTHS
static void mdlSetWorkWidths ( SimStruct * S ) { if ( S -> mdlInfo ->
genericFcn != ( NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ;
ssSetSignalSizesComputeType ( S , SS_VARIABLE_SIZE_FROM_INPUT_VALUE_AND_SIZE
) ; } { static const char * toFileNames [ ] = { "" } ; static const char *
fromFileNames [ ] = { "" } ; if ( ! ssSetModelRefFromFiles ( S , 0 ,
fromFileNames ) ) return ; if ( ! ssSetModelRefToFiles ( S , 0 , toFileNames
) ) return ; } }
#define MDL_SETUP_RUNTIME_RESOURCES
static void mdlSetupRuntimeResources ( SimStruct * S ) { void * sysRanPtr = (
NULL ) ; int sysTid = 0 ; ssGetContextSysRanBCPtr ( S , & sysRanPtr ) ;
ssGetContextSysTid ( S , & sysTid ) ; if ( sysTid == CONSTANT_TID ) { sysTid
= 0 ; } e3vzbqxayt ( S , slmrGetTopTidFromMdlRefChildTid ( S , 0 , false ) ,
slmrGetTopTidFromMdlRefChildTid ( S , 1 , true ) , sysRanPtr , sysTid , (
NULL ) , ( NULL ) , 0 , - 1 ) ; ssSetModelMappingInfoPtr ( S , & ( nkos1yvulp
. rtm . DataMapInfo . mmi ) ) ; if ( S -> mdlInfo -> genericFcn != ( NULL ) )
{ _GenericFcn fcn = S -> mdlInfo -> genericFcn ; } ipqvno13y4 ( ) ; }
#define MDL_START
static void mdlStart ( SimStruct * S ) { mdlProcessParameters ( S ) ;
ijsp4u5kya ( ) ; }
#define RTW_GENERATED_DISABLE
static void mdlDisable ( SimStruct * S ) { real_T * o_o_o_B_92_1 = ( real_T *
) ssGetOutputPortSignal ( S , 0 ) ; lmrkqn5xdk ( o_o_o_B_92_1 ) ; return ; }
static void mdlOutputs ( SimStruct * S , int_T tid ) { const real_T *
i_lcwcddmbya = ( real_T * ) ssGetInputPortSignal ( S , 0 ) ; const real_T *
i_fd3br4i32c = ( real_T * ) ssGetInputPortSignal ( S , 1 ) ; const real_T *
i_ffkjxqeop1 = ( real_T * ) ssGetInputPortSignal ( S , 2 ) ; const real_T *
i_nanuuj1tnd = ( real_T * ) ssGetInputPortSignal ( S , 3 ) ; const real_T *
i_bxral4hgrz = ( real_T * ) ssGetInputPortSignal ( S , 4 ) ; const real_T *
i_eu21eboubk = ( real_T * ) ssGetInputPortSignal ( S , 5 ) ; const real_T *
i_dwq1mczsmn = ( real_T * ) ssGetInputPortSignal ( S , 6 ) ; const real_T *
i_lvhq4k1eug = ( real_T * ) ssGetInputPortSignal ( S , 7 ) ; const real_T *
i_lm4kmimu1x = ( real_T * ) ssGetInputPortSignal ( S , 8 ) ; const real_T *
i_km1ryrl0pt = ( real_T * ) ssGetInputPortSignal ( S , 9 ) ; const real_T *
i_akbexjfodr = ( real_T * ) ssGetInputPortSignal ( S , 10 ) ; const real_T *
i_o1igehji3g = ( real_T * ) ssGetInputPortSignal ( S , 11 ) ; const real_T *
i_epyl3gvmyu = ( real_T * ) ssGetInputPortSignal ( S , 12 ) ; const real_T *
i_k3pn3kzmcr = ( real_T * ) ssGetInputPortSignal ( S , 13 ) ; const real_T *
i_ivpit4zpgt = ( real_T * ) ssGetInputPortSignal ( S , 14 ) ; const real_T *
i_c3cvgtg0ct = ( real_T * ) ssGetInputPortSignal ( S , 15 ) ; const real_T *
i_ibhkbq4xua = ( real_T * ) ssGetInputPortSignal ( S , 16 ) ; const real_T *
i_ii3u4smzmz = ( real_T * ) ssGetInputPortSignal ( S , 17 ) ; const real_T *
i_ek4meo4qey = ( real_T * ) ssGetInputPortSignal ( S , 18 ) ; const real_T *
i_evaxkrd3tv = ( real_T * ) ssGetInputPortSignal ( S , 19 ) ; const real_T *
i_kgr2gb0jmq = ( real_T * ) ssGetInputPortSignal ( S , 20 ) ; const real_T *
i_b30astadhu = ( real_T * ) ssGetInputPortSignal ( S , 21 ) ; const real_T *
i_n4z4mjt2yn = ( real_T * ) ssGetInputPortSignal ( S , 22 ) ; const real_T *
i_i_jqwslt1tlw = ( real_T * ) ssGetInputPortSignal ( S , 23 ) ; const real_T
* i_i_lvvzbeyfcm = ( real_T * ) ssGetInputPortSignal ( S , 24 ) ; const
real_T * i_i_mi1crc0chq = ( real_T * ) ssGetInputPortSignal ( S , 25 ) ;
const real_T * i_i_kuebpi3jox = ( real_T * ) ssGetInputPortSignal ( S , 26 )
; const real_T * i_i_kqaxdqvrdg = ( real_T * ) ssGetInputPortSignal ( S , 27
) ; const real_T * i_i_d0jgwfjaph = ( real_T * ) ssGetInputPortSignal ( S ,
28 ) ; const real_T * i_i_clby42s5l2 = ( real_T * ) ssGetInputPortSignal ( S
, 29 ) ; const real_T * i_i_oyogz13iye = ( real_T * ) ssGetInputPortSignal (
S , 30 ) ; const real_T * i_i_dxaha3ieqk = ( real_T * ) ssGetInputPortSignal
( S , 32 ) ; const real_T * i_i_kwvudobtug = ( real_T * )
ssGetInputPortSignal ( S , 33 ) ; const real_T * i_i_ioh4lthept = ( real_T *
) ssGetInputPortSignal ( S , 34 ) ; const real_T * i_i_dlhgl0hdon = ( real_T
* ) ssGetInputPortSignal ( S , 35 ) ; const real_T * i_i_l53ill41px = (
real_T * ) ssGetInputPortSignal ( S , 36 ) ; const real_T * i_i_btjcnujjde =
( real_T * ) ssGetInputPortSignal ( S , 37 ) ; const real_T * i_m4seftq00f =
( real_T * ) ssGetInputPortSignal ( S , 38 ) ; const real_T * i_cwxykztlav =
( real_T * ) ssGetInputPortSignal ( S , 43 ) ; const real_T * i_afffgoodhw =
( real_T * ) ssGetInputPortSignal ( S , 44 ) ; real_T * o_o_o_B_92_1 = (
real_T * ) ssGetOutputPortSignal ( S , 0 ) ; real_T * o_B_92_2 = ( real_T * )
ssGetOutputPortSignal ( S , 1 ) ; real_T * o_B_92_3 = ( real_T * )
ssGetOutputPortSignal ( S , 2 ) ; real_T * o_B_92_4 = ( real_T * )
ssGetOutputPortSignal ( S , 3 ) ; real_T * o_B_92_5 = ( real_T * )
ssGetOutputPortSignal ( S , 4 ) ; real_T * o_B_92_6 = ( real_T * )
ssGetOutputPortSignal ( S , 5 ) ; real_T * o_o_B_92_7 = ( real_T * )
ssGetOutputPortSignal ( S , 6 ) ; if ( tid == PARAMETER_TUNING_TID ) {
autopilota_v_15_lastTID1 ( ) ; } if ( tid != CONSTANT_TID && tid !=
PARAMETER_TUNING_TID ) { autopilota_v_15_last ( i_lcwcddmbya , i_fd3br4i32c ,
i_ffkjxqeop1 , i_nanuuj1tnd , i_bxral4hgrz , i_eu21eboubk , i_dwq1mczsmn ,
i_lvhq4k1eug , i_lm4kmimu1x , i_km1ryrl0pt , i_akbexjfodr , i_o1igehji3g ,
i_epyl3gvmyu , i_k3pn3kzmcr , i_ivpit4zpgt , i_c3cvgtg0ct , i_ibhkbq4xua ,
i_ii3u4smzmz , i_ek4meo4qey , i_evaxkrd3tv , i_kgr2gb0jmq , i_b30astadhu ,
i_n4z4mjt2yn , i_i_jqwslt1tlw , i_i_lvvzbeyfcm , i_i_mi1crc0chq ,
i_i_kuebpi3jox , i_i_kqaxdqvrdg , i_i_d0jgwfjaph , i_i_clby42s5l2 ,
i_i_oyogz13iye , i_i_dxaha3ieqk , i_i_kwvudobtug , i_i_ioh4lthept ,
i_i_dlhgl0hdon , i_i_l53ill41px , i_i_btjcnujjde , i_m4seftq00f ,
i_cwxykztlav , i_afffgoodhw , o_o_o_B_92_1 , o_B_92_2 , o_B_92_3 , o_B_92_4 ,
o_B_92_5 , o_B_92_6 , o_o_B_92_7 ) ; } }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { const real_T *
i_i_jqwslt1tlw = ( real_T * ) ssGetInputPortSignal ( S , 23 ) ; const real_T
* i_i_lvvzbeyfcm = ( real_T * ) ssGetInputPortSignal ( S , 24 ) ; const
real_T * i_i_mi1crc0chq = ( real_T * ) ssGetInputPortSignal ( S , 25 ) ;
const real_T * i_i_kuebpi3jox = ( real_T * ) ssGetInputPortSignal ( S , 26 )
; const real_T * i_i_kqaxdqvrdg = ( real_T * ) ssGetInputPortSignal ( S , 27
) ; const real_T * i_i_d0jgwfjaph = ( real_T * ) ssGetInputPortSignal ( S ,
28 ) ; const real_T * i_i_clby42s5l2 = ( real_T * ) ssGetInputPortSignal ( S
, 29 ) ; const real_T * i_i_oyogz13iye = ( real_T * ) ssGetInputPortSignal (
S , 30 ) ; const real_T * i_i_dxaha3ieqk = ( real_T * ) ssGetInputPortSignal
( S , 32 ) ; const real_T * i_i_kwvudobtug = ( real_T * )
ssGetInputPortSignal ( S , 33 ) ; const real_T * i_i_ioh4lthept = ( real_T *
) ssGetInputPortSignal ( S , 34 ) ; const real_T * i_i_dlhgl0hdon = ( real_T
* ) ssGetInputPortSignal ( S , 35 ) ; const real_T * i_i_l53ill41px = (
real_T * ) ssGetInputPortSignal ( S , 36 ) ; const real_T * i_i_btjcnujjde =
( real_T * ) ssGetInputPortSignal ( S , 37 ) ; const real_T * i_p5mrrf5qyd =
( real_T * ) ssGetInputPortSignal ( S , 39 ) ; const real_T * i_aj23mpuv25 =
( real_T * ) ssGetInputPortSignal ( S , 40 ) ; const real_T * i_hw25mlmm1i =
( real_T * ) ssGetInputPortSignal ( S , 41 ) ; const real_T * i_key2gsbkm0 =
( real_T * ) ssGetInputPortSignal ( S , 42 ) ; pjvl4fhogu ( i_i_jqwslt1tlw ,
i_i_lvvzbeyfcm , i_i_mi1crc0chq , i_i_kuebpi3jox , i_i_kqaxdqvrdg ,
i_i_d0jgwfjaph , i_i_clby42s5l2 , i_i_oyogz13iye , i_i_dxaha3ieqk ,
i_i_kwvudobtug , i_i_ioh4lthept , i_i_dlhgl0hdon , i_i_l53ill41px ,
i_i_btjcnujjde , i_p5mrrf5qyd , i_aj23mpuv25 , i_hw25mlmm1i , i_key2gsbkm0 )
; return ; } static void mdlTerminate ( SimStruct * S ) { jcsv2oscoq ( ) ;
return ; }
#define MDL_CLEANUP_RUNTIME_RESOURCES
static void mdlCleanupRuntimeResources ( SimStruct * S ) { d4ol3dmeav ( ) ; }
#if !defined(MDL_SIM_STATE)
#define MDL_SIM_STATE
#endif
static mxArray * mdlGetSimState ( SimStruct * S ) { static const char *
simStateFieldNames [ 5 ] = { "localX" , "mdlrefDW" , "disallowedStateData" ,
"tNext" , "tNextTid" , } ; mxArray * ss = mxCreateStructMatrix ( 1 , 1 , 5 ,
simStateFieldNames ) ; { const real_T * localX = ( const real_T * )
ssGetContStates ( S ) ; const int_T numStates = ssGetNumContStates ( S ) ;
const size_t numBytes = numStates * sizeof ( real_T ) ; mxArray * storedX =
mxCreateNumericMatrix ( 1 , numBytes , mxUINT8_CLASS , mxREAL ) ; UINT8_T *
rawData = ( UINT8_T * ) mxGetData ( storedX ) ; memcpy ( & rawData [ 0 ] ,
localX , numBytes ) ; mxSetFieldByNumber ( ss , 0 , 0 , storedX ) ; } {
mxArray * mdlrefDW = mr_autopilota_v_15_last_GetDWork ( ) ;
mxSetFieldByNumber ( ss , 0 , 1 , mdlrefDW ) ; } { mxArray * data =
mr_autopilota_v_15_last_GetSimStateDisallowedBlocks ( ) ; mxSetFieldByNumber
( ss , 0 , 2 , data ) ; } ; mxSetFieldByNumber ( ss , 0 , 3 ,
mxCreateDoubleScalar ( ( double ) ssGetTNext ( S ) ) ) ; mxSetFieldByNumber (
ss , 0 , 4 , mxCreateDoubleScalar ( ( double ) ssGetTNextTid ( S ) ) ) ;
return ss ; }
#if !defined(MDL_SIM_STATE)
#define MDL_SIM_STATE
#endif
static void mdlSetSimState ( SimStruct * S , const mxArray * ss ) { { real_T
* localX = ( real_T * ) ssGetContStates ( S ) ; const int_T numStates =
ssGetNumContStates ( S ) ; const size_t numBytes = numStates * sizeof (
real_T ) ; const mxArray * storedX = mxGetFieldByNumber ( ss , 0 , 0 ) ;
const UINT8_T * rawData = ( const UINT8_T * ) mxGetData ( storedX ) ; memcpy
( localX , & rawData [ 0 ] , numBytes ) ; } mr_autopilota_v_15_last_SetDWork
( mxGetFieldByNumber ( ss , 0 , 1 ) ) ; ssSetTNext ( S , ( time_T )
mxGetScalar ( mxGetFieldByNumber ( ss , 0 , 3 ) ) ) ; ssSetTNextTid ( S , (
int_T ) mxGetScalar ( mxGetFieldByNumber ( ss , 0 , 4 ) ) ) ; }
#ifdef MATLAB_MEX_FILE 
#include "simulink.c"
#include "fixedpoint.c"
#else
#error Assertion failed: file must be compiled as a MEX-file
#endif
