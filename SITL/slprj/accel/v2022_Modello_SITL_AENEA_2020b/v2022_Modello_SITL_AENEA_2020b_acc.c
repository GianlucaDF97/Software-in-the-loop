#include <math.h>
#include "v2022_Modello_SITL_AENEA_2020b_acc.h"
#include "v2022_Modello_SITL_AENEA_2020b_acc_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf.h"
#include "v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate.h"
#include "intrp2d_la_pw.h"
#include "look2_binlxpw.h"
#include "plook_bincpa.h"
#include "rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf.h"
#include "rt_nrand_Upu32_Yd_f_pw_snf.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
static void v2022_Modello_SITL_AENEA_2020b_oorCheck ( uint8_T diagSetting ,
real_T u , real_T bp0 , real_T bpn , const char_T * extrapMsgId , const
char_T * blockPath , SimStruct * S ) ; void rt_ssGetBlockPath ( SimStruct * S
, int_T sysIdx , int_T blkIdx , char_T * * path ) { _ssGetBlockPath ( S ,
sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg ( SimStruct * S , void *
diag ) { if ( ! _ssIsErrorStatusAslErrMsg ( S ) ) { _ssSet_slErrMsg ( S ,
diag ) ; } else { _ssDiscardDiagnostic ( S , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( SimStruct * S , void * diag ) {
_ssReportDiagnosticAsWarning ( S , diag ) ; } void
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Init ( SimStruct * S ,
B_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localB ,
P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localP ,
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localX ) { localX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE = localP -> P_1 ; localB ->
B_20_0_0 = localP -> P_0 ; } void
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Reset ( SimStruct * S ,
P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localP ,
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localX ) { localX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE = localP -> P_1 ; } void
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Disable ( SimStruct * S ,
DW_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localDW ) { localDW
-> Distanceintogusty_MODE = false ; } void
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty ( SimStruct * S , boolean_T
rtu_Enable , B_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localB ,
DW_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localDW ,
P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localP ,
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localX ) { int32_T
isHit ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && (
ssIsMajorTimeStep ( S ) != 0 ) ) { if ( rtu_Enable ) { if ( ! localDW ->
Distanceintogusty_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S )
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Reset ( S , localP , localX
) ; localDW -> Distanceintogusty_MODE = true ; } } else { if ( localDW ->
Distanceintogusty_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Disable ( S , localDW ) ; }
} } if ( localDW -> Distanceintogusty_MODE ) { if ( ssIsMajorTimeStep ( S )
!= 0 ) { if ( localX -> DistanceintoGustxLimitedtogustlengthd_CSTATE >=
localP -> P_2 ) { if ( localX -> DistanceintoGustxLimitedtogustlengthd_CSTATE
!= localP -> P_2 ) { localX -> DistanceintoGustxLimitedtogustlengthd_CSTATE =
localP -> P_2 ; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } } else {
if ( ( localX -> DistanceintoGustxLimitedtogustlengthd_CSTATE <= localP ->
P_3 ) && ( localX -> DistanceintoGustxLimitedtogustlengthd_CSTATE != localP
-> P_3 ) ) { localX -> DistanceintoGustxLimitedtogustlengthd_CSTATE = localP
-> P_3 ; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } } localB ->
B_20_0_0 = localX -> DistanceintoGustxLimitedtogustlengthd_CSTATE ;
srUpdateBC ( localDW -> Distanceintogusty_SubsysRanBC ) ; } else if ( localX
-> DistanceintoGustxLimitedtogustlengthd_CSTATE >= localP -> P_2 ) { localB
-> B_20_0_0 = localP -> P_2 ; } else if ( localX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE <= localP -> P_3 ) { localB ->
B_20_0_0 = localP -> P_3 ; } else { localB -> B_20_0_0 = localX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE ; } } } void
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Deriv ( SimStruct * S ,
real_T rtu_V , DW_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T *
localDW , P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localP ,
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localX ,
XDot_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T * localXdot ) { if (
localDW -> Distanceintogusty_MODE ) { if ( ( ( localX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE > localP -> P_3 ) && ( localX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE < localP -> P_2 ) ) || ( (
localX -> DistanceintoGustxLimitedtogustlengthd_CSTATE <= localP -> P_3 ) &&
( rtu_V > 0.0 ) ) || ( ( localX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE >= localP -> P_2 ) && ( rtu_V <
0.0 ) ) ) { localXdot -> DistanceintoGustxLimitedtogustlengthd_CSTATE = rtu_V
; } else { localXdot -> DistanceintoGustxLimitedtogustlengthd_CSTATE = 0.0 ;
} } else { localXdot -> DistanceintoGustxLimitedtogustlengthd_CSTATE = 0.0 ;
} } void v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Term ( SimStruct *
const S ) { } static void v2022_Modello_SITL_AENEA_2020b_oorCheck ( uint8_T
diagSetting , real_T u , real_T bp0 , real_T bpn , const char_T * extrapMsgId
, const char_T * blockPath , SimStruct * S ) { SimStruct * S_0 ; void * diag
; if ( ( diagSetting != 0 ) && ( ( u < bp0 ) || ( u > bpn ) ) ) { if (
diagSetting == 2 ) { S_0 = S ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:PreLookupOutofRangeInputError" , 1 , 3 , blockPath ) ;
rt_ssSet_slErrMsg ( S_0 , diag ) ; } else { S_0 = S ; diag =
CreateDiagnosticAsVoidPtr ( extrapMsgId , 1 , 3 , blockPath ) ;
rt_ssReportDiagnosticAsWarning ( S_0 , diag ) ; } } } static void mdlOutputs
( SimStruct * S , int_T tid ) { real_T B_51_714_0 ; real_T B_51_765_0 ;
real_T B_51_774_0 ; real_T B_51_815_0 ; real_T B_51_819_0 ; real_T B_51_825_0
; real_T B_51_835_0 ; real_T B_51_848_0 ; real_T B_51_856_0 ; real_T
B_51_864_0 ; real_T B_51_872_0 ; real_T B_51_882_0 ; real_T B_51_892_0 ;
real_T B_51_919_0 [ 3 ] ; B_v2022_Modello_SITL_AENEA_2020b_T * _rtB ;
DW_v2022_Modello_SITL_AENEA_2020b_T * _rtDW ;
P_v2022_Modello_SITL_AENEA_2020b_T * _rtP ;
X_v2022_Modello_SITL_AENEA_2020b_T * _rtX ; real_T rtb_B_51_12_0 [ 9 ] ;
real_T rtb_B_51_195_0 [ 9 ] ; real_T tmp [ 9 ] ; real_T tmp_0 [ 9 ] ; real_T
tmp_1 [ 9 ] ; real_T rtb_B_51_112_0 [ 6 ] ; real_T rtb_B_31_6_0 [ 3 ] ;
real_T rtb_B_51_1_0 [ 3 ] ; real_T rtb_B_51_2_1 [ 3 ] ; real_T rtb_B_51_56_0
[ 3 ] ; real_T frac [ 2 ] ; real_T rtb_B_51_18_0 ; real_T rtb_B_51_37_0 ;
real_T rtb_B_51_38_0 ; real_T rtb_B_51_39_0 ; real_T rtb_B_51_42_0 ; real_T
rtb_B_51_44_0 ; real_T rtb_B_51_797_0 ; real_T rtb_B_51_801_0 ; real_T
rtb_B_51_81_0 ; real_T rtb_B_51_84_0 ; real_T rtb_B_51_91_0 ; int32_T isHit ;
uint32_T bpIndex [ 2 ] ; int8_T rtAction ; _rtDW = ( (
DW_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetRootDWork ( S ) ) ; _rtX = ( (
X_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetContStates ( S ) ) ; _rtP = ( (
P_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_v2022_Modello_SITL_AENEA_2020b_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB ->
B_51_0_0 [ 0 ] = _rtX -> phithetapsi_CSTATE [ 0 ] ; _rtB -> B_51_0_0 [ 1 ] =
_rtX -> phithetapsi_CSTATE [ 1 ] ; _rtB -> B_51_0_0 [ 2 ] = _rtX ->
phithetapsi_CSTATE [ 2 ] ; rtb_B_51_1_0 [ 1 ] = _rtB -> B_51_0_0 [ 1 ] ;
rtb_B_51_1_0 [ 2 ] = _rtB -> B_51_0_0 [ 0 ] ; muDoubleScalarSinCos ( _rtB ->
B_51_0_0 [ 2 ] , & rtb_B_51_1_0 [ 0 ] , & rtb_B_51_2_1 [ 0 ] ) ;
muDoubleScalarSinCos ( rtb_B_51_1_0 [ 1 ] , & rtb_B_51_1_0 [ 1 ] , &
rtb_B_51_2_1 [ 1 ] ) ; muDoubleScalarSinCos ( rtb_B_51_1_0 [ 2 ] , &
rtb_B_51_38_0 , & rtb_B_51_2_1 [ 2 ] ) ; rtb_B_51_12_0 [ 0 ] = rtb_B_51_2_1 [
1 ] * rtb_B_51_2_1 [ 0 ] ; rtb_B_51_12_0 [ 1 ] = rtb_B_51_38_0 * rtb_B_51_1_0
[ 1 ] * rtb_B_51_2_1 [ 0 ] - rtb_B_51_2_1 [ 2 ] * rtb_B_51_1_0 [ 0 ] ;
rtb_B_51_12_0 [ 2 ] = rtb_B_51_2_1 [ 2 ] * rtb_B_51_1_0 [ 1 ] * rtb_B_51_2_1
[ 0 ] + rtb_B_51_38_0 * rtb_B_51_1_0 [ 0 ] ; rtb_B_51_12_0 [ 3 ] =
rtb_B_51_2_1 [ 1 ] * rtb_B_51_1_0 [ 0 ] ; rtb_B_51_12_0 [ 4 ] = rtb_B_51_38_0
* rtb_B_51_1_0 [ 1 ] * rtb_B_51_1_0 [ 0 ] + rtb_B_51_2_1 [ 2 ] * rtb_B_51_2_1
[ 0 ] ; rtb_B_51_12_0 [ 5 ] = rtb_B_51_2_1 [ 2 ] * rtb_B_51_1_0 [ 1 ] *
rtb_B_51_1_0 [ 0 ] - rtb_B_51_38_0 * rtb_B_51_2_1 [ 0 ] ; rtb_B_51_12_0 [ 6 ]
= - rtb_B_51_1_0 [ 1 ] ; rtb_B_51_12_0 [ 7 ] = rtb_B_51_38_0 * rtb_B_51_2_1 [
1 ] ; rtb_B_51_12_0 [ 8 ] = rtb_B_51_2_1 [ 2 ] * rtb_B_51_2_1 [ 1 ] ; _rtB ->
B_51_13_0 [ 0 ] = _rtX -> xeyeze_CSTATE [ 0 ] ; _rtB -> B_51_13_0 [ 1 ] =
_rtX -> xeyeze_CSTATE [ 1 ] ; _rtB -> B_51_13_0 [ 2 ] = _rtX -> xeyeze_CSTATE
[ 2 ] ; rtb_B_51_38_0 = 3.280839895013123 * _rtB -> B_51_13_0 [ 2 ] ; if (
rtb_B_51_38_0 > _rtP -> P_52 ) { rtb_B_51_38_0 = _rtP -> P_52 ; } else { if (
rtb_B_51_38_0 < _rtP -> P_53 ) { rtb_B_51_38_0 = _rtP -> P_53 ; } }
rtb_B_51_18_0 = muDoubleScalarLog ( _rtP -> P_54 * rtb_B_51_38_0 ) / _rtB ->
B_51_113_0 ; rtb_B_51_1_0 [ 0 ] = rtb_B_51_18_0 * _rtB -> B_51_111_0_g [ 0 ]
; rtb_B_51_1_0 [ 1 ] = rtb_B_51_18_0 * _rtB -> B_51_111_0_g [ 1 ] ;
rtb_B_51_1_0 [ 2 ] = rtb_B_51_18_0 * _rtB -> B_51_111_0_g [ 2 ] ;
rtb_B_51_18_0 = ( ssGetT ( S ) >= _rtB -> B_51_79_0 ) ; _rtB -> B_51_23_0_l =
( ( rtb_B_51_18_0 != 0.0 ) && ( _rtB -> B_51_76_0 != 0.0 ) ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S
) != 0 ) ) { if ( _rtB -> B_51_23_0_l ) { if ( ! _rtDW ->
Distanceintogustx_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S )
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f = _rtP -> P_1 ; _rtDW ->
Distanceintogustx_MODE = true ; } } else { if ( _rtDW ->
Distanceintogustx_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
_rtDW -> Distanceintogustx_MODE = false ; } } } if ( _rtDW ->
Distanceintogustx_MODE ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f >= _rtP -> P_2 ) { if ( _rtX
-> DistanceintoGustxLimitedtogustlengthd_CSTATE_f != _rtP -> P_2 ) { _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f = _rtP -> P_2 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } } else { if ( ( _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f <= _rtP -> P_3 ) && ( _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f != _rtP -> P_3 ) ) { _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f = _rtP -> P_3 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } } _rtB -> B_19_0_0 =
_rtX -> DistanceintoGustxLimitedtogustlengthd_CSTATE_f ; srUpdateBC ( _rtDW
-> Distanceintogustx_SubsysRanBC ) ; } else if ( _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f >= _rtP -> P_2 ) { _rtB ->
B_19_0_0 = _rtP -> P_2 ; } else if ( _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f <= _rtP -> P_3 ) { _rtB ->
B_19_0_0 = _rtP -> P_3 ; } else { _rtB -> B_19_0_0 = _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f ; } } _rtB -> B_51_25_0_o = (
( rtb_B_51_18_0 != 0.0 ) && ( _rtB -> B_51_77_0 != 0.0 ) ) ;
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty ( S , _rtB -> B_51_25_0_o ,
& _rtB -> Distanceintogusty , & _rtDW -> Distanceintogusty , & _rtP ->
Distanceintogusty , & _rtX -> Distanceintogusty ) ; _rtB -> B_51_27_0 = ( (
rtb_B_51_18_0 != 0.0 ) && ( _rtB -> B_51_78_0 != 0.0 ) ) ;
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty ( S , _rtB -> B_51_27_0 , &
_rtB -> Distanceintogustz , & _rtDW -> Distanceintogustz , & _rtP ->
Distanceintogustz , & _rtX -> Distanceintogustz ) ; rtb_B_51_38_0 = ( _rtB ->
B_51_75_0_c - muDoubleScalarCos ( _rtP -> P_55 [ 0 ] * _rtB -> B_19_0_0 ) ) *
_rtP -> P_56 [ 0 ] ; rtb_B_51_42_0 = ( _rtB -> B_51_75_0_c -
muDoubleScalarCos ( _rtP -> P_55 [ 1 ] * _rtB -> Distanceintogusty . B_20_0_0
) ) * _rtP -> P_56 [ 1 ] ; rtb_B_51_39_0 = ( _rtB -> B_51_75_0_c -
muDoubleScalarCos ( _rtP -> P_55 [ 2 ] * _rtB -> Distanceintogustz . B_20_0_0
) ) * _rtP -> P_56 [ 2 ] ; rtb_B_51_18_0 = 3.280839895013123 * _rtB ->
B_51_13_0 [ 2 ] ; for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { _rtB ->
B_51_35_0 [ isHit ] = _rtX -> ubvbwb_CSTATE [ isHit ] ; rtb_B_51_2_1 [ isHit
] = rtb_B_51_12_0 [ isHit + 6 ] * rtb_B_51_39_0 + ( rtb_B_51_12_0 [ isHit + 3
] * rtb_B_51_42_0 + rtb_B_51_12_0 [ isHit ] * rtb_B_51_38_0 ) ; }
ssCallAccelRunBlock ( S , 35 , 0 , SS_CALL_MDL_OUTPUTS ) ; rtb_B_51_37_0 =
3.280839895013123 * _rtB -> B_35_0_1 ; if ( rtb_B_51_18_0 > _rtP -> P_58 ) {
rtb_B_51_38_0 = _rtP -> P_58 ; } else if ( rtb_B_51_18_0 < _rtP -> P_59 ) {
rtb_B_51_38_0 = _rtP -> P_59 ; } else { rtb_B_51_38_0 = rtb_B_51_18_0 ; }
rtb_B_51_42_0 = 0.000823 * rtb_B_51_38_0 + 0.177 ; if ( rtb_B_51_42_0 < 0.0 )
{ rtb_B_51_42_0 = - muDoubleScalarPower ( - rtb_B_51_42_0 , 1.2 ) ; } else {
rtb_B_51_42_0 = muDoubleScalarPower ( rtb_B_51_42_0 , 1.2 ) ; } rtb_B_51_39_0
= rtb_B_51_38_0 / rtb_B_51_42_0 ; if ( rtb_B_51_18_0 > _rtP -> P_60 ) {
rtb_B_51_44_0 = _rtP -> P_60 ; } else if ( rtb_B_51_18_0 < _rtP -> P_61 ) {
rtb_B_51_44_0 = _rtP -> P_61 ; } else { rtb_B_51_44_0 = rtb_B_51_18_0 ; }
rtb_B_51_42_0 = 0.000823 * rtb_B_51_44_0 + 0.177 ; if ( rtb_B_51_42_0 < 0.0 )
{ rtb_B_51_42_0 = - muDoubleScalarPower ( - rtb_B_51_42_0 , 0.4 ) ; } else {
rtb_B_51_42_0 = muDoubleScalarPower ( rtb_B_51_42_0 , 0.4 ) ; } rtb_B_51_42_0
= 1.0 / rtb_B_51_42_0 * _rtB -> B_51_87_0 ;
v2022_Modello_SITL_AENEA_2020b_oorCheck ( _rtP -> P_557 , rtb_B_51_18_0 ,
_rtP -> P_62 [ 0 ] , _rtP -> P_62 [ 11 ] ,
"Simulink:blocks:PreLookupOutofRangeInputWarn_Clip" ,
 "v2022_Modello_SITL_AENEA_2020b/AENEA /AENEA II_SITL1/Velocit\3401/Dryden Wind Turbulence Model  (Continuous (-q +r))/RMS turbulence  intensities/High Altitude Intensity/PreLook-Up Index Search  (altitude)"
, S ) ; bpIndex [ 0 ] = plook_bincpa ( rtb_B_51_18_0 , _rtP -> P_62 , 11U , &
frac [ 0 ] , & _rtDW -> PreLookUpIndexSearchaltitude_DWORK1 ) ; frac [ 1 ] =
_rtB -> B_51_99_1 ; bpIndex [ 1 ] = _rtB -> B_51_99_0 ; rtb_B_51_44_0 =
intrp2d_la_pw ( bpIndex , frac , _rtP -> P_63 , 12U , _rtP -> P_550 ) ; isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_46_0 [ 0 ] =
_rtB -> B_51_106_0_g [ 0 ] * _rtDW -> NextOutput [ 0 ] ; _rtB -> B_51_46_0 [
1 ] = _rtB -> B_51_106_0_g [ 1 ] * _rtDW -> NextOutput [ 1 ] ; _rtB ->
B_51_46_0 [ 2 ] = _rtB -> B_51_106_0_g [ 2 ] * _rtDW -> NextOutput [ 2 ] ;
_rtB -> B_51_46_0 [ 3 ] = _rtB -> B_51_106_0_g [ 3 ] * _rtDW -> NextOutput [
3 ] ; if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( _rtB -> B_51_93_0 > 0.0 ) {
if ( ! _rtDW -> Hugws_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart (
S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtX ->
ug_p_CSTATE [ 0 ] = _rtP -> P_17 ; _rtX -> ug_p_CSTATE [ 1 ] = _rtP -> P_17 ;
_rtDW -> Hugws_MODE = true ; } } else { if ( _rtDW -> Hugws_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB -> B_25_7_0 [ 0 ] =
_rtP -> P_15 ; _rtB -> B_25_7_0 [ 1 ] = _rtP -> P_15 ; _rtDW -> Hugws_MODE =
false ; } } } } if ( _rtDW -> Hugws_MODE ) { frac [ 0 ] = rtb_B_51_39_0 /
rtb_B_51_37_0 ; frac [ 1 ] = _rtB -> B_51_95_0 / rtb_B_51_37_0 ; _rtB ->
B_25_6_0 [ 0 ] = ( muDoubleScalarSqrt ( _rtP -> P_16 * frac [ 0 ] ) * _rtB ->
B_51_46_0 [ 0 ] - _rtX -> ug_p_CSTATE [ 0 ] ) / frac [ 0 ] ; _rtB -> B_25_6_0
[ 1 ] = ( muDoubleScalarSqrt ( _rtP -> P_16 * frac [ 1 ] ) * _rtB ->
B_51_46_0 [ 0 ] - _rtX -> ug_p_CSTATE [ 1 ] ) / frac [ 1 ] ; _rtB -> B_25_7_0
[ 0 ] = _rtX -> ug_p_CSTATE [ 0 ] * rtb_B_51_42_0 ; _rtB -> B_25_7_0 [ 1 ] =
_rtX -> ug_p_CSTATE [ 1 ] * rtb_B_51_44_0 ; if ( ssIsMajorTimeStep ( S ) != 0
) { srUpdateBC ( _rtDW -> Hugws_SubsysRanBC ) ; } } frac [ 0 ] = _rtP -> P_67
* rtb_B_51_39_0 ; frac [ 1 ] = _rtP -> P_67 * _rtB -> B_51_95_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S
) != 0 ) ) { if ( _rtB -> B_51_93_0 > 0.0 ) { if ( ! _rtDW -> Hvgws_MODE ) {
if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtX -> vg_p1_CSTATE [ 0
] = _rtP -> P_20 ; _rtX -> vgw_p2_CSTATE [ 0 ] = _rtP -> P_21 ; _rtX ->
vg_p1_CSTATE [ 1 ] = _rtP -> P_20 ; _rtX -> vgw_p2_CSTATE [ 1 ] = _rtP ->
P_21 ; _rtDW -> Hvgws_MODE = true ; } } else { if ( _rtDW -> Hvgws_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB -> B_26_12_0 [ 0 ] =
_rtP -> P_18 ; _rtB -> B_26_12_0 [ 1 ] = _rtP -> P_18 ; _rtDW -> Hvgws_MODE =
false ; } } } if ( _rtDW -> Hvgws_MODE ) { rtb_B_51_39_0 = frac [ 0 ] /
rtb_B_51_37_0 ; _rtB -> B_26_6_0 [ 0 ] = ( muDoubleScalarSqrt ( _rtP -> P_19
* rtb_B_51_39_0 ) * _rtB -> B_51_46_0 [ 1 ] - _rtX -> vg_p1_CSTATE [ 0 ] ) /
rtb_B_51_39_0 ; _rtB -> B_26_11_0 [ 0 ] = ( _rtB -> B_26_6_0 [ 0 ] *
rtb_B_51_39_0 * _rtP -> P_22 + ( _rtX -> vg_p1_CSTATE [ 0 ] - _rtX ->
vgw_p2_CSTATE [ 0 ] ) ) / rtb_B_51_39_0 ; rtb_B_51_39_0 = frac [ 1 ] /
rtb_B_51_37_0 ; _rtB -> B_26_6_0 [ 1 ] = ( muDoubleScalarSqrt ( _rtP -> P_19
* rtb_B_51_39_0 ) * _rtB -> B_51_46_0 [ 1 ] - _rtX -> vg_p1_CSTATE [ 1 ] ) /
rtb_B_51_39_0 ; _rtB -> B_26_11_0 [ 1 ] = ( _rtB -> B_26_6_0 [ 1 ] *
rtb_B_51_39_0 * _rtP -> P_22 + ( _rtX -> vg_p1_CSTATE [ 1 ] - _rtX ->
vgw_p2_CSTATE [ 1 ] ) ) / rtb_B_51_39_0 ; _rtB -> B_26_12_0 [ 0 ] =
rtb_B_51_42_0 * _rtX -> vgw_p2_CSTATE [ 0 ] ; _rtB -> B_26_12_0 [ 1 ] =
rtb_B_51_44_0 * _rtX -> vgw_p2_CSTATE [ 1 ] ; if ( ssIsMajorTimeStep ( S ) !=
0 ) { srUpdateBC ( _rtDW -> Hvgws_SubsysRanBC ) ; } } frac [ 0 ] = _rtP ->
P_68 * rtb_B_51_38_0 ; frac [ 1 ] = _rtP -> P_68 * _rtB -> B_51_95_0 ; isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep (
S ) != 0 ) ) { if ( _rtB -> B_51_93_0 > 0.0 ) { if ( ! _rtDW -> Hwgws_MODE )
{ if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtX -> wg_p1_CSTATE [ 0
] = _rtP -> P_25 ; _rtX -> wg_p2_CSTATE [ 0 ] = _rtP -> P_26 ; _rtX ->
wg_p1_CSTATE [ 1 ] = _rtP -> P_25 ; _rtX -> wg_p2_CSTATE [ 1 ] = _rtP -> P_26
; _rtDW -> Hwgws_MODE = true ; } } else { if ( _rtDW -> Hwgws_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB -> B_27_9_0 [ 0 ] =
_rtP -> P_23 ; _rtB -> B_27_9_0 [ 1 ] = _rtP -> P_23 ; _rtDW -> Hwgws_MODE =
false ; } } } if ( _rtDW -> Hwgws_MODE ) { _rtB -> B_27_9_0 [ 0 ] = _rtB ->
B_51_87_0 * _rtX -> wg_p2_CSTATE [ 0 ] ; _rtB -> B_27_9_0 [ 1 ] =
rtb_B_51_44_0 * _rtX -> wg_p2_CSTATE [ 1 ] ; rtb_B_51_38_0 = frac [ 0 ] /
rtb_B_51_37_0 ; _rtB -> B_27_6_0 [ 0 ] = ( muDoubleScalarSqrt ( _rtP -> P_24
* rtb_B_51_38_0 ) * _rtB -> B_51_46_0 [ 2 ] - _rtX -> wg_p1_CSTATE [ 0 ] ) /
rtb_B_51_38_0 ; _rtB -> B_27_11_0 [ 0 ] = ( _rtB -> B_27_6_0 [ 0 ] * _rtB ->
B_27_1_0 * rtb_B_51_38_0 + ( _rtX -> wg_p1_CSTATE [ 0 ] - _rtX ->
wg_p2_CSTATE [ 0 ] ) ) / rtb_B_51_38_0 ; rtb_B_51_38_0 = frac [ 1 ] /
rtb_B_51_37_0 ; _rtB -> B_27_6_0 [ 1 ] = ( muDoubleScalarSqrt ( _rtP -> P_24
* rtb_B_51_38_0 ) * _rtB -> B_51_46_0 [ 2 ] - _rtX -> wg_p1_CSTATE [ 1 ] ) /
rtb_B_51_38_0 ; _rtB -> B_27_11_0 [ 1 ] = ( _rtB -> B_27_6_0 [ 1 ] * _rtB ->
B_27_1_0 * rtb_B_51_38_0 + ( _rtX -> wg_p1_CSTATE [ 1 ] - _rtX ->
wg_p2_CSTATE [ 1 ] ) ) / rtb_B_51_38_0 ; if ( ssIsMajorTimeStep ( S ) != 0 )
{ srUpdateBC ( _rtDW -> Hwgws_SubsysRanBC ) ; } } if ( ssIsMajorTimeStep ( S
) != 0 ) { if ( rtb_B_51_18_0 <= 1000.0 ) { rtAction = 0 ; } else if (
rtb_B_51_18_0 >= 2000.0 ) { rtAction = 1 ; } else { rtAction = 2 ; } _rtDW ->
ifHeightMaxlowaltitudeelseifHeightMinisotropicaltitude_ActiveSubsystem =
rtAction ; } else { rtAction = _rtDW ->
ifHeightMaxlowaltitudeelseifHeightMinisotropicaltitude_ActiveSubsystem ; }
switch ( rtAction ) { case 0 : rtb_B_31_6_0 [ 2 ] = _rtB -> B_27_9_0 [ 0 ] ;
muDoubleScalarSinCos ( _rtB -> B_51_81_0 , & rtb_B_51_42_0 , & rtb_B_51_38_0
) ; rtb_B_31_6_0 [ 0 ] = _rtB -> B_25_7_0 [ 0 ] * rtb_B_51_38_0 -
rtb_B_51_42_0 * _rtB -> B_26_12_0 [ 0 ] ; rtb_B_31_6_0 [ 1 ] = _rtB ->
B_26_12_0 [ 0 ] * rtb_B_51_38_0 + rtb_B_51_42_0 * _rtB -> B_25_7_0 [ 0 ] ;
for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { rtb_B_51_56_0 [ isHit ] =
rtb_B_51_12_0 [ isHit + 6 ] * rtb_B_31_6_0 [ 2 ] + ( rtb_B_51_12_0 [ isHit +
3 ] * rtb_B_31_6_0 [ 1 ] + rtb_B_51_12_0 [ isHit ] * rtb_B_31_6_0 [ 0 ] ) ; }
if ( ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW ->
Lowaltitudevelocities_SubsysRanBC ) ; } break ; case 1 : rtb_B_51_56_0 [ 0 ]
= _rtP -> P_31 * _rtB -> B_25_7_0 [ 1 ] ; rtb_B_51_56_0 [ 1 ] = _rtP -> P_31
* _rtB -> B_26_12_0 [ 1 ] ; rtb_B_51_56_0 [ 2 ] = _rtP -> P_31 * _rtB ->
B_27_9_0 [ 1 ] ; if ( ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW ->
MediumHighaltitudevelocities_SubsysRanBC ) ; } break ; case 2 :
muDoubleScalarSinCos ( _rtB -> B_51_81_0 , & rtb_B_51_42_0 , & rtb_B_51_38_0
) ; rtb_B_51_56_0 [ 0 ] = _rtB -> B_25_7_0 [ 0 ] * rtb_B_51_38_0 -
rtb_B_51_42_0 * _rtB -> B_26_12_0 [ 0 ] ; rtb_B_51_56_0 [ 1 ] = _rtB ->
B_26_12_0 [ 0 ] * rtb_B_51_38_0 + rtb_B_51_42_0 * _rtB -> B_25_7_0 [ 0 ] ;
rtb_B_51_56_0 [ 2 ] = _rtB -> B_27_9_0 [ 0 ] ; for ( isHit = 0 ; isHit < 3 ;
isHit ++ ) { rtb_B_31_6_0 [ isHit ] = rtb_B_51_12_0 [ isHit + 6 ] *
rtb_B_51_56_0 [ 2 ] + ( rtb_B_51_12_0 [ isHit + 3 ] * rtb_B_51_56_0 [ 1 ] +
rtb_B_51_12_0 [ isHit ] * rtb_B_51_56_0 [ 0 ] ) ; } rtb_B_51_42_0 =
rtb_B_51_18_0 - _rtB -> B_33_0_0 ; rtb_B_51_56_0 [ 0 ] = ( _rtB -> B_25_7_0 [
1 ] - rtb_B_31_6_0 [ 0 ] ) * rtb_B_51_42_0 / _rtB -> B_33_2_0 + rtb_B_31_6_0
[ 0 ] ; rtb_B_51_56_0 [ 1 ] = ( _rtB -> B_26_12_0 [ 1 ] - rtb_B_31_6_0 [ 1 ]
) * rtb_B_51_42_0 / _rtB -> B_33_2_0 + rtb_B_31_6_0 [ 1 ] ; rtb_B_51_56_0 [ 2
] = ( _rtB -> B_27_9_0 [ 1 ] - rtb_B_31_6_0 [ 2 ] ) * rtb_B_51_42_0 / _rtB ->
B_33_2_0 + rtb_B_31_6_0 [ 2 ] ; if ( ssIsMajorTimeStep ( S ) != 0 ) {
srUpdateBC ( _rtDW -> Interpolatevelocities_SubsysRanBC ) ; } break ; } for (
isHit = 0 ; isHit < 3 ; isHit ++ ) { rtb_B_51_91_0 = rtb_B_51_12_0 [ isHit ]
; rtb_B_51_81_0 = rtb_B_51_91_0 * rtb_B_51_1_0 [ 0 ] ; rtb_B_51_38_0 =
rtb_B_51_91_0 * _rtB -> B_51_135_0 [ 0 ] ; rtb_B_51_91_0 = rtb_B_51_12_0 [
isHit + 3 ] ; rtb_B_51_81_0 += rtb_B_51_91_0 * rtb_B_51_1_0 [ 1 ] ;
rtb_B_51_38_0 += rtb_B_51_91_0 * _rtB -> B_51_135_0 [ 1 ] ; rtb_B_51_91_0 =
rtb_B_51_12_0 [ isHit + 6 ] ; rtb_B_51_81_0 += rtb_B_51_91_0 * rtb_B_51_1_0 [
2 ] ; rtb_B_51_38_0 += rtb_B_51_91_0 * _rtB -> B_51_135_0 [ 2 ] ; if ( _rtB
-> B_51_35_0 [ isHit ] > _rtP -> P_69 ) { rtb_B_51_42_0 = 0.3048 *
rtb_B_51_56_0 [ isHit ] ; } else { rtb_B_51_42_0 = _rtB -> B_51_74_0 [ isHit
] ; } _rtB -> B_51_60_0 [ isHit ] = ( ( rtb_B_51_81_0 + rtb_B_51_2_1 [ isHit
] ) + rtb_B_51_42_0 ) + rtb_B_51_38_0 ; _rtB -> B_51_61_0 [ isHit ] = _rtB ->
B_51_35_0 [ isHit ] - _rtB -> B_51_60_0 [ isHit ] ; } _rtB -> B_36_0_0 [ 0 ]
= _rtB -> B_51_61_0 [ 2 ] ; _rtB -> B_36_0_0 [ 1 ] = _rtB -> B_51_61_0 [ 0 ]
; ssCallAccelRunBlock ( S , 36 , 1 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_51_63_0 = muDoubleScalarAtan ( _rtB -> B_36_1_1 ) ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_63_0 + 0 ) ; } } }
ssCallAccelRunBlock ( S , 34 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_37_0_0 [
0 ] = _rtB -> B_51_61_0 [ 1 ] ; _rtB -> B_37_0_0 [ 1 ] = _rtB -> B_34_0_1 ;
ssCallAccelRunBlock ( S , 37 , 1 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
B_37_1_1 > 1.0 ) { rtb_B_51_38_0 = 1.0 ; } else if ( _rtB -> B_37_1_1 < - 1.0
) { rtb_B_51_38_0 = - 1.0 ; } else { rtb_B_51_38_0 = _rtB -> B_37_1_1 ; }
_rtB -> B_51_67_0 = muDoubleScalarAsin ( rtb_B_51_38_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_1_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_1_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_67_0 + 0 ) ; } } } _rtB
-> B_51_69_0 [ 0 ] = _rtX -> pqr_CSTATE [ 0 ] ; _rtB -> B_51_69_0 [ 1 ] =
_rtX -> pqr_CSTATE [ 1 ] ; _rtB -> B_51_69_0 [ 2 ] = _rtX -> pqr_CSTATE [ 2 ]
; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_10_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_10_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_69_0 [ 1 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_11_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_11_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_69_0 [ 2 ] + 0 ) ; } } }
for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { _rtB -> B_51_72_0 [ isHit ] = 0.0
; _rtB -> B_51_72_0 [ isHit ] += rtb_B_51_12_0 [ isHit ] * _rtB ->
B_51_114_0_m [ 0 ] ; _rtB -> B_51_72_0 [ isHit ] += rtb_B_51_12_0 [ isHit + 3
] * _rtB -> B_51_114_0_m [ 1 ] ; _rtB -> B_51_72_0 [ isHit ] += rtb_B_51_12_0
[ isHit + 6 ] * _rtB -> B_51_114_0_m [ 2 ] ; } ssCallAccelRunBlock ( S , 3 ,
0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_51_75_0 = look2_binlxpw ( _rtB ->
B_51_63_0 , _rtB -> B_51_67_0 , _rtP -> P_72 , _rtP -> P_73 , _rtP -> P_71 ,
_rtP -> P_551 , 13U ) + _rtB -> B_51_116_0_n ; rtb_B_51_42_0 = _rtP -> P_74 *
_rtB -> B_51_75_0 ; rtb_B_51_38_0 = look2_binlxpw ( _rtB -> B_51_63_0 , _rtB
-> B_51_67_0 , _rtP -> P_76 , _rtP -> P_77 , _rtP -> P_75 , _rtP -> P_552 ,
13U ) ; if ( rtb_B_51_38_0 > _rtP -> P_78 ) { rtb_B_51_38_0 = _rtP -> P_78 ;
} else { if ( rtb_B_51_38_0 < _rtP -> P_79 ) { rtb_B_51_38_0 = _rtP -> P_79 ;
} } _rtB -> B_0_0_0 [ 0 ] = _rtB -> B_51_7_0 ; _rtB -> B_0_0_0 [ 1 ] = _rtB
-> B_51_69_0 [ 0 ] ; _rtB -> B_0_0_0 [ 2 ] = _rtB -> B_51_8_0 ; _rtB ->
B_0_0_0 [ 3 ] = _rtB -> B_34_0_1 ; ssCallAccelRunBlock ( S , 0 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_1_0_0 [ 0 ] = _rtB -> B_51_69_0 [ 2 ] ;
_rtB -> B_1_0_0 [ 1 ] = _rtB -> B_51_8_0 ; _rtB -> B_1_0_0 [ 2 ] = _rtB ->
B_51_10_0 ; _rtB -> B_1_0_0 [ 3 ] = _rtB -> B_34_0_1 ; ssCallAccelRunBlock (
S , 1 , 1 , SS_CALL_MDL_OUTPUTS ) ; rtb_B_51_81_0 = _rtP -> P_82 * _rtX ->
StateSpace2_CSTATE ; if ( rtb_B_51_81_0 > _rtP -> P_84 ) { _rtB -> B_51_82_0
= _rtP -> P_84 ; } else if ( rtb_B_51_81_0 < _rtP -> P_85 ) { _rtB ->
B_51_82_0 = _rtP -> P_85 ; } else { _rtB -> B_51_82_0 = rtb_B_51_81_0 ; }
rtb_B_51_84_0 = _rtP -> P_88 * _rtX -> StateSpace1_CSTATE ; if (
rtb_B_51_84_0 > _rtP -> P_90 ) { _rtB -> B_51_85_0 = _rtP -> P_90 ; } else if
( rtb_B_51_84_0 < _rtP -> P_91 ) { _rtB -> B_51_85_0 = _rtP -> P_91 ; } else
{ _rtB -> B_51_85_0 = rtb_B_51_84_0 ; } rtb_B_51_81_0 = ( ( ( rtb_B_51_38_0 +
_rtB -> B_0_1_1 ) + _rtB -> B_1_1_1 ) + _rtB -> B_51_119_0_j * _rtB ->
B_51_82_0 ) + _rtB -> B_51_118_0_l * _rtB -> B_51_85_0 ; rtb_B_51_84_0 =
look2_binlxpw ( _rtB -> B_51_63_0 , _rtB -> B_51_67_0 , _rtP -> P_93 , _rtP
-> P_94 , _rtP -> P_92 , _rtP -> P_553 , 13U ) ; _rtB -> B_2_0_0 [ 0 ] = _rtB
-> B_51_12_0 ; _rtB -> B_2_0_0 [ 1 ] = _rtB -> B_51_69_0 [ 1 ] ; _rtB ->
B_2_0_0 [ 2 ] = _rtB -> B_51_13_0_m ; _rtB -> B_2_0_0 [ 3 ] = _rtP -> P_95 *
_rtB -> B_34_0_1 ; ssCallAccelRunBlock ( S , 2 , 1 , SS_CALL_MDL_OUTPUTS ) ;
rtb_B_51_91_0 = _rtP -> P_98 * _rtX -> StateSpace_CSTATE ; if ( rtb_B_51_91_0
> _rtP -> P_100 ) { _rtB -> B_51_92_0 = _rtP -> P_100 ; } else if (
rtb_B_51_91_0 < _rtP -> P_101 ) { _rtB -> B_51_92_0 = _rtP -> P_101 ; } else
{ _rtB -> B_51_92_0 = rtb_B_51_91_0 ; } rtb_B_51_91_0 = ( ( _rtB -> B_51_61_0
[ 0 ] * _rtB -> B_51_61_0 [ 0 ] + _rtB -> B_51_61_0 [ 1 ] * _rtB -> B_51_61_0
[ 1 ] ) + _rtB -> B_51_61_0 [ 2 ] * _rtB -> B_51_61_0 [ 2 ] ) * _rtB ->
B_51_136_0 * _rtP -> P_103 ; rtb_B_51_38_0 = ( ( rtb_B_51_84_0 + _rtB ->
B_2_1_1 ) + _rtB -> B_51_117_0_p * _rtB -> B_51_92_0 ) * _rtP -> P_102 ; for
( isHit = 0 ; isHit < 3 ; isHit ++ ) { rtb_B_51_56_0 [ isHit ] = _rtB ->
B_51_127_0 * ( _rtB -> B_3_0_1 [ isHit + 6 ] * rtb_B_51_38_0 + ( _rtB ->
B_3_0_1 [ isHit + 3 ] * rtb_B_51_81_0 + _rtB -> B_3_0_1 [ isHit ] *
rtb_B_51_42_0 ) ) * rtb_B_51_91_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_51_105_0 = _rtDW -> UnitDelay_DSTATE ; _rtB ->
B_51_106_0 = _rtP -> P_105 * _rtB -> B_51_105_0 ; if ( ( _rtB -> B_51_106_0 <
0.0 ) && ( _rtB -> B_51_26_0 > muDoubleScalarFloor ( _rtB -> B_51_26_0 ) ) )
{ _rtB -> B_51_107_0 = - muDoubleScalarPower ( - _rtB -> B_51_106_0 , _rtB ->
B_51_26_0 ) ; } else { _rtB -> B_51_107_0 = muDoubleScalarPower ( _rtB ->
B_51_106_0 , _rtB -> B_51_26_0 ) ; } } _rtB -> B_51_108_0 = 1.0 / _rtB ->
B_51_106_0 * _rtB -> B_34_0_1 / _rtB -> B_51_32_0 ; ssCallAccelRunBlock ( S ,
10 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_51_110_0 = _rtB -> B_51_107_0 *
_rtB -> B_51_33_0 * _rtB -> B_51_136_0 * _rtB -> B_10_0_1 ; _rtB ->
B_51_111_0 [ 0 ] = ( _rtB -> B_51_72_0 [ 0 ] + rtb_B_51_56_0 [ 0 ] ) + _rtB
-> B_51_110_0 ; _rtB -> B_51_111_0 [ 1 ] = ( _rtB -> B_51_72_0 [ 1 ] +
rtb_B_51_56_0 [ 1 ] ) + _rtB -> B_51_35_0_c ; _rtB -> B_51_111_0 [ 2 ] = (
_rtB -> B_51_72_0 [ 2 ] + rtb_B_51_56_0 [ 2 ] ) + _rtB -> B_51_35_0_c ; _rtB
-> B_51_114_0 [ 0 ] = ( _rtB -> B_51_126_0 [ 1 ] * _rtB -> B_51_69_0 [ 2 ] -
_rtB -> B_51_126_0 [ 2 ] * _rtB -> B_51_69_0 [ 1 ] ) + _rtB -> B_51_35_0 [ 0
] ; _rtB -> B_51_114_0 [ 1 ] = ( _rtB -> B_51_126_0 [ 2 ] * _rtB -> B_51_69_0
[ 0 ] - _rtB -> B_51_126_0 [ 0 ] * _rtB -> B_51_69_0 [ 2 ] ) + _rtB ->
B_51_35_0 [ 1 ] ; _rtB -> B_51_114_0 [ 2 ] = ( _rtB -> B_51_126_0 [ 0 ] *
_rtB -> B_51_69_0 [ 1 ] - _rtB -> B_51_126_0 [ 1 ] * _rtB -> B_51_69_0 [ 0 ]
) + _rtB -> B_51_35_0 [ 2 ] ; _rtB -> B_51_116_0 = muDoubleScalarAtan ( _rtB
-> B_51_114_0 [ 1 ] / _rtB -> B_51_114_0 [ 0 ] ) ; isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_117_0 = _rtDW ->
Memory_PreviousInput ; if ( ( _rtB -> B_51_106_0 < 0.0 ) && ( _rtB ->
B_51_28_0 > muDoubleScalarFloor ( _rtB -> B_51_28_0 ) ) ) { _rtB ->
B_51_118_0 = - muDoubleScalarPower ( - _rtB -> B_51_106_0 , _rtB -> B_51_28_0
) ; } else { _rtB -> B_51_118_0 = muDoubleScalarPower ( _rtB -> B_51_106_0 ,
_rtB -> B_51_28_0 ) ; } } _rtB -> B_51_119_0 = _rtB -> B_10_0_2 * _rtB ->
B_51_136_0 * _rtB -> B_51_34_0 * _rtB -> B_51_118_0 ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_120_0 = _rtP -> P_107 * _rtB
-> B_51_106_0 ; } rtb_B_51_81_0 = _rtB -> B_51_119_0 / _rtB -> B_51_120_0 *
_rtP -> P_108 ; rtb_B_51_84_0 = _rtB -> B_51_130_0 * _rtB -> B_51_110_0 ;
rtb_B_51_42_0 = _rtP -> P_112 * look2_binlxpw ( _rtB -> B_51_63_0 , _rtB ->
B_51_67_0 , _rtP -> P_110 , _rtP -> P_111 , _rtP -> P_109 , _rtP -> P_554 ,
13U ) ; _rtB -> B_4_0_0 [ 0 ] = _rtB -> B_51_15_0 ; _rtB -> B_4_0_0 [ 1 ] =
_rtB -> B_51_69_0 [ 0 ] ; _rtB -> B_4_0_0 [ 2 ] = _rtB -> B_51_8_0 ; _rtB ->
B_4_0_0 [ 3 ] = _rtB -> B_34_0_1 ; ssCallAccelRunBlock ( S , 4 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_5_0_0 [ 0 ] = _rtB -> B_51_17_0 ; _rtB ->
B_5_0_0 [ 1 ] = _rtB -> B_51_8_0 ; _rtB -> B_5_0_0 [ 2 ] = _rtB -> B_51_69_0
[ 2 ] ; _rtB -> B_5_0_0 [ 3 ] = _rtB -> B_34_0_1 ; ssCallAccelRunBlock ( S ,
5 , 1 , SS_CALL_MDL_OUTPUTS ) ; rtb_B_51_42_0 = ( ( ( ( rtb_B_51_42_0 + _rtB
-> B_4_1_1 ) + _rtB -> B_5_1_1 ) + _rtB -> B_51_120_0_d * _rtB -> B_51_85_0 )
+ _rtB -> B_51_121_0 * _rtB -> B_51_82_0 ) * _rtB -> B_51_128_0 ;
rtb_B_51_38_0 = look2_binlxpw ( _rtB -> B_51_63_0 , _rtB -> B_51_67_0 , _rtP
-> P_114 , _rtP -> P_115 , _rtP -> P_113 , _rtP -> P_555 , 13U ) ; _rtB ->
B_6_0_0 [ 0 ] = _rtB -> B_51_19_0 ; _rtB -> B_6_0_0 [ 1 ] = _rtB -> B_51_69_0
[ 1 ] ; _rtB -> B_6_0_0 [ 2 ] = _rtB -> B_51_13_0_m ; _rtB -> B_6_0_0 [ 3 ] =
_rtP -> P_116 * _rtB -> B_34_0_1 ; ssCallAccelRunBlock ( S , 6 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; rtb_B_51_38_0 = ( ( rtb_B_51_38_0 + _rtB -> B_6_1_1 )
+ _rtB -> B_51_122_0 * _rtB -> B_51_92_0 ) * _rtB -> B_51_129_0 ;
rtb_B_51_39_0 = look2_binlxpw ( _rtB -> B_51_63_0 , _rtB -> B_51_67_0 , _rtP
-> P_118 , _rtP -> P_119 , _rtP -> P_117 , _rtP -> P_556 , 13U ) ; _rtB ->
B_7_0_0 [ 0 ] = _rtB -> B_51_21_0 ; _rtB -> B_7_0_0 [ 1 ] = _rtB -> B_51_69_0
[ 0 ] ; _rtB -> B_7_0_0 [ 2 ] = _rtB -> B_51_8_0 ; _rtB -> B_7_0_0 [ 3 ] =
_rtB -> B_34_0_1 ; ssCallAccelRunBlock ( S , 7 , 1 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> B_8_0_0 [ 0 ] = _rtB -> B_51_23_0 ; _rtB -> B_8_0_0 [ 1 ] = _rtB ->
B_51_69_0 [ 2 ] ; _rtB -> B_8_0_0 [ 2 ] = _rtB -> B_51_8_0 ; _rtB -> B_8_0_0
[ 3 ] = _rtB -> B_34_0_1 ; ssCallAccelRunBlock ( S , 8 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_51_146_0 [ 0 ] = rtb_B_51_81_0 +
rtb_B_51_91_0 * rtb_B_51_42_0 ; _rtB -> B_51_146_0 [ 1 ] = rtb_B_51_84_0 +
rtb_B_51_91_0 * rtb_B_51_38_0 ; _rtB -> B_51_146_0 [ 2 ] = _rtB -> B_51_36_0
+ ( ( ( ( rtb_B_51_39_0 + _rtB -> B_7_1_1 ) + _rtB -> B_8_1_1 ) + _rtB ->
B_51_123_0 * _rtB -> B_51_85_0 ) + _rtB -> B_51_124_0 * _rtB -> B_51_82_0 ) *
_rtB -> B_51_128_0 * rtb_B_51_91_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_51_147_0 = _rtDW -> Memory1_PreviousInput ; switch
( ( int32_T ) _rtB -> B_51_117_0 ) { case 0 : _rtB -> B_51_148_0 = _rtB ->
B_51_41_0 ; break ; case 1 : _rtB -> B_51_148_0 = _rtB -> B_51_41_0 ; break ;
case 2 : _rtB -> B_51_148_0 = _rtB -> B_51_41_0 ; break ; case 3 : _rtB ->
B_51_148_0 = _rtB -> B_51_41_0 ; break ; case 4 : _rtB -> B_51_148_0 = _rtB
-> B_51_44_0 ; break ; default : _rtB -> B_51_148_0 = _rtB -> B_51_41_0 ;
break ; } } rtb_B_51_195_0 [ 0 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ]
) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 1 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) ; rtb_B_51_195_0 [ 2 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 3 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 4 ] =
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) +
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 5 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) - muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 6 ] = _rtP -> P_121 * muDoubleScalarSin ( _rtB -> B_51_0_0 [
1 ] ) ; rtb_B_51_195_0 [ 7 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 8 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) ; for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { rtb_B_51_2_1 [
isHit ] = rtb_B_51_195_0 [ 3 * isHit + 2 ] * _rtB -> B_51_126_0 [ 2 ] + (
rtb_B_51_195_0 [ 3 * isHit + 1 ] * _rtB -> B_51_126_0 [ 1 ] + rtb_B_51_195_0
[ 3 * isHit ] * _rtB -> B_51_126_0 [ 0 ] ) ; } _rtB -> B_51_199_0 = ( (
rtb_B_51_2_1 [ 2 ] - _rtB -> B_51_73_0 ) + _rtB -> B_51_13_0 [ 2 ] ) + _rtB
-> B_51_148_0 ; rtb_B_51_195_0 [ 0 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [
1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 1 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) ; rtb_B_51_195_0 [ 2 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 3 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 4 ] =
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) +
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 5 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) - muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 6 ] = _rtP -> P_122 * muDoubleScalarSin ( _rtB -> B_51_0_0 [
1 ] ) ; rtb_B_51_195_0 [ 7 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 8 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) ; for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { _rtB ->
B_51_248_0 [ isHit ] = 0.0 ; _rtB -> B_51_248_0 [ isHit ] += rtb_B_51_195_0 [
3 * isHit ] * _rtB -> B_51_114_0 [ 0 ] ; _rtB -> B_51_248_0 [ isHit ] +=
rtb_B_51_195_0 [ 3 * isHit + 1 ] * _rtB -> B_51_114_0 [ 1 ] ; _rtB ->
B_51_248_0 [ isHit ] += rtb_B_51_195_0 [ 3 * isHit + 2 ] * _rtB -> B_51_114_0
[ 2 ] ; } if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( ( _rtB -> B_51_199_0 !=
0.0 ) || ( _rtDW -> Integrator_IWORK != 0 ) ) { _rtX -> Integrator_CSTATE =
_rtB -> B_51_248_0 [ 2 ] ; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
} _rtB -> B_51_249_0 = _rtX -> Integrator_CSTATE ; } else { _rtB ->
B_51_249_0 = _rtX -> Integrator_CSTATE ; } _rtB -> B_51_250_0 = _rtB ->
B_51_249_0 * 0.0 ; if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( ( _rtB ->
B_51_199_0 != 0.0 ) || ( _rtDW -> Integrator1_IWORK != 0 ) ) { _rtX ->
Integrator1_CSTATE = _rtB -> B_51_199_0 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtB -> B_51_251_0 =
_rtX -> Integrator1_CSTATE ; } else { _rtB -> B_51_251_0 = _rtX ->
Integrator1_CSTATE ; } if ( _rtB -> B_51_251_0 > _rtP -> P_123 ) {
rtb_B_51_38_0 = _rtP -> P_123 ; } else if ( _rtB -> B_51_251_0 < _rtP ->
P_124 ) { rtb_B_51_38_0 = _rtP -> P_124 ; } else { rtb_B_51_38_0 = _rtB ->
B_51_251_0 ; } _rtB -> B_51_255_0 = rtb_B_51_38_0 * 0.0 ; _rtB -> B_51_256_0
= ( _rtB -> B_51_251_0 - _rtB -> B_51_40_0 ) * _rtB -> B_51_39_0 + _rtB ->
B_51_255_0 ; rtb_B_51_38_0 = _rtB -> B_51_250_0 + _rtB -> B_51_256_0 ; isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { switch ( ( int32_T ) _rtB
-> B_51_117_0 ) { case 0 : _rtB -> B_51_259_0 = _rtB -> B_51_42_0 ; break ;
case 1 : _rtB -> B_51_259_0 = _rtB -> B_51_42_0 ; break ; case 2 : _rtB ->
B_51_259_0 = _rtB -> B_51_42_0 ; break ; case 3 : _rtB -> B_51_259_0 = _rtB
-> B_51_43_0 ; break ; case 4 : _rtB -> B_51_259_0 = _rtB -> B_51_42_0 ;
break ; default : _rtB -> B_51_259_0 = _rtB -> B_51_42_0 ; break ; } } if (
rtb_B_51_38_0 > _rtP -> P_125 ) { rtb_B_51_38_0 = _rtP -> P_125 ; } else { if
( rtb_B_51_38_0 < _rtP -> P_126 ) { rtb_B_51_38_0 = _rtP -> P_126 ; } } _rtB
-> B_51_260_0 = rtb_B_51_38_0 * _rtB -> B_51_259_0 ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { switch ( ( int32_T ) _rtB -> B_51_117_0 ) {
case 0 : _rtB -> B_51_261_0 = _rtB -> B_51_47_0 ; break ; case 1 : _rtB ->
B_51_261_0 = _rtB -> B_51_47_0 ; break ; case 2 : _rtB -> B_51_261_0 = _rtB
-> B_51_47_0 ; break ; case 3 : _rtB -> B_51_261_0 = _rtB -> B_51_47_0 ;
break ; case 4 : _rtB -> B_51_261_0 = _rtB -> B_51_50_0 ; break ; default :
_rtB -> B_51_261_0 = _rtB -> B_51_47_0 ; break ; } } rtb_B_51_195_0 [ 0 ] =
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 1 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) - muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ;
rtb_B_51_195_0 [ 2 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) + muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 3 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 4 ] = muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 5 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) - muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 6 ] = _rtP ->
P_127 * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 7 ] =
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 8 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ;
rtb_B_51_112_0 [ 0 ] = _rtB -> B_51_70_0 [ 1 ] * _rtB -> B_51_69_0 [ 2 ] ;
rtb_B_51_112_0 [ 1 ] = _rtB -> B_51_70_0 [ 2 ] * _rtB -> B_51_69_0 [ 0 ] ;
rtb_B_51_112_0 [ 2 ] = _rtB -> B_51_70_0 [ 0 ] * _rtB -> B_51_69_0 [ 1 ] ;
rtb_B_51_112_0 [ 3 ] = _rtB -> B_51_70_0 [ 2 ] * _rtB -> B_51_69_0 [ 1 ] ;
rtb_B_51_112_0 [ 4 ] = _rtB -> B_51_70_0 [ 0 ] * _rtB -> B_51_69_0 [ 2 ] ;
rtb_B_51_112_0 [ 5 ] = _rtB -> B_51_70_0 [ 1 ] * _rtB -> B_51_69_0 [ 0 ] ;
for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { rtb_B_51_1_0 [ isHit ] = (
rtb_B_51_112_0 [ isHit ] - rtb_B_51_112_0 [ isHit + 3 ] ) + _rtB -> B_51_35_0
[ isHit ] ; rtb_B_51_2_1 [ isHit ] = rtb_B_51_195_0 [ 3 * isHit + 2 ] * _rtB
-> B_51_70_0 [ 2 ] + ( rtb_B_51_195_0 [ 3 * isHit + 1 ] * _rtB -> B_51_70_0 [
1 ] + rtb_B_51_195_0 [ 3 * isHit ] * _rtB -> B_51_70_0 [ 0 ] ) ; } _rtB ->
B_51_312_0 = ( ( rtb_B_51_2_1 [ 2 ] - _rtB -> B_51_73_0 ) + _rtB -> B_51_13_0
[ 2 ] ) + _rtB -> B_51_261_0 ; rtb_B_51_195_0 [ 0 ] = muDoubleScalarSin (
_rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 1 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) - muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ; rtb_B_51_195_0 [ 2 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) +
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 3 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 4 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) + muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 5 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 6 ] = _rtP -> P_128 * muDoubleScalarSin (
_rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 7 ] = muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) ;
rtb_B_51_195_0 [ 8 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ; for ( isHit = 0 ; isHit < 3 ;
isHit ++ ) { _rtB -> B_51_364_0 [ isHit ] = 0.0 ; _rtB -> B_51_364_0 [ isHit
] += rtb_B_51_195_0 [ 3 * isHit ] * rtb_B_51_1_0 [ 0 ] ; _rtB -> B_51_364_0 [
isHit ] += rtb_B_51_195_0 [ 3 * isHit + 1 ] * rtb_B_51_1_0 [ 1 ] ; _rtB ->
B_51_364_0 [ isHit ] += rtb_B_51_195_0 [ 3 * isHit + 2 ] * rtb_B_51_1_0 [ 2 ]
; } if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( ( _rtB -> B_51_312_0 != 0.0 )
|| ( _rtDW -> Integrator_IWORK_d != 0 ) ) { _rtX -> Integrator_CSTATE_m =
_rtB -> B_51_364_0 [ 2 ] ; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
} _rtB -> B_51_365_0 = _rtX -> Integrator_CSTATE_m ; } else { _rtB ->
B_51_365_0 = _rtX -> Integrator_CSTATE_m ; } _rtB -> B_51_366_0 = _rtB ->
B_51_365_0 * _rtB -> B_51_133_0 ; if ( ssIsMajorTimeStep ( S ) != 0 ) { if (
( _rtB -> B_51_312_0 != 0.0 ) || ( _rtDW -> Integrator1_IWORK_n != 0 ) ) {
_rtX -> Integrator1_CSTATE_a = _rtB -> B_51_312_0 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } rtb_B_51_91_0 = _rtX ->
Integrator1_CSTATE_a ; } else { rtb_B_51_91_0 = _rtX -> Integrator1_CSTATE_a
; } if ( rtb_B_51_91_0 > _rtP -> P_129 ) { rtb_B_51_81_0 = _rtP -> P_129 ; }
else if ( rtb_B_51_91_0 < _rtP -> P_130 ) { rtb_B_51_81_0 = _rtP -> P_130 ; }
else { rtb_B_51_81_0 = rtb_B_51_91_0 ; } _rtB -> B_51_371_0 = rtb_B_51_81_0 *
_rtB -> B_51_131_0 ; rtb_B_51_38_0 = ( ( rtb_B_51_91_0 - _rtB -> B_51_46_0_k
) * _rtB -> B_51_45_0 + _rtB -> B_51_371_0 ) + _rtB -> B_51_366_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { switch ( ( int32_T ) _rtB
-> B_51_117_0 ) { case 0 : _rtB -> B_51_375_0 = _rtB -> B_51_48_0 ; break ;
case 1 : _rtB -> B_51_375_0 = _rtB -> B_51_48_0 ; break ; case 2 : _rtB ->
B_51_375_0 = _rtB -> B_51_48_0 ; break ; case 3 : _rtB -> B_51_375_0 = _rtB
-> B_51_49_0 ; break ; case 4 : _rtB -> B_51_375_0 = _rtB -> B_51_48_0 ;
break ; default : _rtB -> B_51_375_0 = _rtB -> B_51_48_0 ; break ; } } if (
rtb_B_51_38_0 > _rtP -> P_131 ) { rtb_B_51_38_0 = _rtP -> P_131 ; } else { if
( rtb_B_51_38_0 < _rtP -> P_132 ) { rtb_B_51_38_0 = _rtP -> P_132 ; } } _rtB
-> B_51_376_0 = rtb_B_51_38_0 * _rtB -> B_51_375_0 ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { switch ( ( int32_T ) _rtB -> B_51_117_0 ) {
case 0 : _rtB -> B_51_377_0 = _rtB -> B_51_53_0 ; break ; case 1 : _rtB ->
B_51_377_0 = _rtB -> B_51_53_0 ; break ; case 2 : _rtB -> B_51_377_0 = _rtB
-> B_51_53_0 ; break ; case 3 : _rtB -> B_51_377_0 = _rtB -> B_51_53_0 ;
break ; case 4 : _rtB -> B_51_377_0 = _rtB -> B_51_56_0 ; break ; default :
_rtB -> B_51_377_0 = _rtB -> B_51_53_0 ; break ; } } rtb_B_51_195_0 [ 0 ] =
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 1 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) - muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ;
rtb_B_51_195_0 [ 2 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) + muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 3 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 4 ] = muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 5 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) - muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 6 ] = _rtP ->
P_133 * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 7 ] =
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 8 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ;
rtb_B_51_112_0 [ 0 ] = _rtB -> B_51_71_0 [ 1 ] * _rtB -> B_51_69_0 [ 2 ] ;
rtb_B_51_112_0 [ 1 ] = _rtB -> B_51_71_0 [ 2 ] * _rtB -> B_51_69_0 [ 0 ] ;
rtb_B_51_112_0 [ 2 ] = _rtB -> B_51_71_0 [ 0 ] * _rtB -> B_51_69_0 [ 1 ] ;
rtb_B_51_112_0 [ 3 ] = _rtB -> B_51_71_0 [ 2 ] * _rtB -> B_51_69_0 [ 1 ] ;
rtb_B_51_112_0 [ 4 ] = _rtB -> B_51_71_0 [ 0 ] * _rtB -> B_51_69_0 [ 2 ] ;
rtb_B_51_112_0 [ 5 ] = _rtB -> B_51_71_0 [ 1 ] * _rtB -> B_51_69_0 [ 0 ] ;
for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { rtb_B_51_56_0 [ isHit ] = (
rtb_B_51_112_0 [ isHit ] - rtb_B_51_112_0 [ isHit + 3 ] ) + _rtB -> B_51_35_0
[ isHit ] ; rtb_B_51_2_1 [ isHit ] = rtb_B_51_195_0 [ 3 * isHit + 2 ] * _rtB
-> B_51_71_0 [ 2 ] + ( rtb_B_51_195_0 [ 3 * isHit + 1 ] * _rtB -> B_51_71_0 [
1 ] + rtb_B_51_195_0 [ 3 * isHit ] * _rtB -> B_51_71_0 [ 0 ] ) ; } _rtB ->
B_51_428_0 = ( ( rtb_B_51_2_1 [ 2 ] - _rtB -> B_51_73_0 ) + _rtB -> B_51_13_0
[ 2 ] ) + _rtB -> B_51_377_0 ; rtb_B_51_195_0 [ 0 ] = muDoubleScalarSin (
_rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 1 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) - muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ; rtb_B_51_195_0 [ 2 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) +
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 3 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 4 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) + muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 5 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 6 ] = _rtP -> P_134 * muDoubleScalarSin (
_rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 7 ] = muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) ;
rtb_B_51_195_0 [ 8 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ; for ( isHit = 0 ; isHit < 3 ;
isHit ++ ) { _rtB -> B_51_480_0 [ isHit ] = 0.0 ; _rtB -> B_51_480_0 [ isHit
] += rtb_B_51_195_0 [ 3 * isHit ] * rtb_B_51_56_0 [ 0 ] ; _rtB -> B_51_480_0
[ isHit ] += rtb_B_51_195_0 [ 3 * isHit + 1 ] * rtb_B_51_56_0 [ 1 ] ; _rtB ->
B_51_480_0 [ isHit ] += rtb_B_51_195_0 [ 3 * isHit + 2 ] * rtb_B_51_56_0 [ 2
] ; } if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( ( _rtB -> B_51_428_0 != 0.0
) || ( _rtDW -> Integrator_IWORK_g != 0 ) ) { _rtX -> Integrator_CSTATE_md =
_rtB -> B_51_480_0 [ 2 ] ; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
} _rtB -> B_51_481_0 = _rtX -> Integrator_CSTATE_md ; } else { _rtB ->
B_51_481_0 = _rtX -> Integrator_CSTATE_md ; } _rtB -> B_51_482_0 = _rtB ->
B_51_481_0 * _rtB -> B_51_132_0 ; if ( ssIsMajorTimeStep ( S ) != 0 ) { if (
( _rtB -> B_51_428_0 != 0.0 ) || ( _rtDW -> Integrator1_IWORK_f != 0 ) ) {
_rtX -> Integrator1_CSTATE_n = _rtB -> B_51_428_0 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } rtb_B_51_91_0 = _rtX ->
Integrator1_CSTATE_n ; } else { rtb_B_51_91_0 = _rtX -> Integrator1_CSTATE_n
; } if ( rtb_B_51_91_0 > _rtP -> P_135 ) { rtb_B_51_81_0 = _rtP -> P_135 ; }
else if ( rtb_B_51_91_0 < _rtP -> P_136 ) { rtb_B_51_81_0 = _rtP -> P_136 ; }
else { rtb_B_51_81_0 = rtb_B_51_91_0 ; } _rtB -> B_51_487_0 = rtb_B_51_81_0 *
_rtB -> B_51_134_0 ; rtb_B_51_38_0 = ( ( rtb_B_51_91_0 - _rtB -> B_51_52_0 )
* _rtB -> B_51_51_0 + _rtB -> B_51_487_0 ) + _rtB -> B_51_482_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { switch ( ( int32_T ) _rtB
-> B_51_117_0 ) { case 0 : _rtB -> B_51_491_0 = _rtB -> B_51_54_0 ; break ;
case 1 : _rtB -> B_51_491_0 = _rtB -> B_51_54_0 ; break ; case 2 : _rtB ->
B_51_491_0 = _rtB -> B_51_54_0 ; break ; case 3 : _rtB -> B_51_491_0 = _rtB
-> B_51_55_0 ; break ; case 4 : _rtB -> B_51_491_0 = _rtB -> B_51_54_0 ;
break ; default : _rtB -> B_51_491_0 = _rtB -> B_51_54_0 ; break ; } } if (
rtb_B_51_38_0 > _rtP -> P_137 ) { rtb_B_51_38_0 = _rtP -> P_137 ; } else { if
( rtb_B_51_38_0 < _rtP -> P_138 ) { rtb_B_51_38_0 = _rtP -> P_138 ; } } _rtB
-> B_51_492_0 = rtb_B_51_38_0 * _rtB -> B_51_491_0 ; if ( ssGetTaskTime ( S ,
0 ) < _rtP -> P_139 ) { rtb_B_51_38_0 = _rtP -> P_140 ; } else {
rtb_B_51_38_0 = _rtP -> P_141 ; } _rtB -> B_51_497_0 = ( ssGetT ( S ) - _rtB
-> B_51_57_0 ) * rtb_B_51_38_0 + _rtB -> B_51_58_0 ; ssCallAccelRunBlock ( S
, 18 , 0 , SS_CALL_MDL_OUTPUTS ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_51_499_0 = _rtDW -> Memory2_PreviousInput ; }
ssCallAccelRunBlock ( S , 17 , 0 , SS_CALL_MDL_OUTPUTS ) ; switch ( ( int32_T
) _rtB -> B_51_117_0 ) { case 0 : rtb_B_51_91_0 = _rtB -> B_51_37_0 ; break ;
case 1 : rtb_B_51_91_0 = _rtB -> B_51_37_0 ; break ; case 2 : rtb_B_51_91_0 =
_rtB -> B_51_37_0 ; break ; case 3 : rtb_B_51_91_0 = _rtB -> B_18_0_2 ; break
; case 4 : rtb_B_51_91_0 = _rtB -> B_17_0_2 ; break ; default : rtb_B_51_91_0
= _rtB -> B_51_37_0 ; break ; } _rtB -> B_51_502_0 = rtb_B_51_91_0 * _rtB ->
B_51_38_0 ; ssCallAccelRunBlock ( S , 12 , 0 , SS_CALL_MDL_OUTPUTS ) ; if (
_rtB -> B_12_0_1 > _rtP -> P_143 ) { _rtB -> B_51_504_0 = _rtP -> P_143 ; }
else if ( _rtB -> B_12_0_1 < _rtP -> P_144 ) { _rtB -> B_51_504_0 = _rtP ->
P_144 ; } else { _rtB -> B_51_504_0 = _rtB -> B_12_0_1 ; }
ssCallAccelRunBlock ( S , 11 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_51_506_0
= _rtP -> P_145 * _rtB -> B_11_0_1 ; rtb_B_51_195_0 [ 0 ] = muDoubleScalarSin
( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 1 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) - muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ; rtb_B_51_195_0 [ 2 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) +
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 3 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 4 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) + muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 5 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 6 ] = _rtP -> P_146 * muDoubleScalarSin (
_rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 7 ] = muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) ;
rtb_B_51_195_0 [ 8 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ; rtb_B_51_39_0 = _rtP -> P_147
* rtb_B_51_91_0 ; for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { _rtB ->
B_51_556_0 [ isHit ] = 0.0 ; _rtB -> B_51_556_0 [ isHit ] += rtb_B_51_195_0 [
isHit ] * _rtB -> B_51_59_0 ; _rtB -> B_51_556_0 [ isHit ] += rtb_B_51_195_0
[ isHit + 3 ] * _rtB -> B_51_59_0 ; _rtB -> B_51_556_0 [ isHit ] +=
rtb_B_51_195_0 [ isHit + 6 ] * rtb_B_51_39_0 ; } _rtB -> B_51_558_0 =
muDoubleScalarAtan ( rtb_B_51_1_0 [ 1 ] / rtb_B_51_1_0 [ 0 ] ) ; switch ( (
int32_T ) _rtB -> B_51_117_0 ) { case 0 : rtb_B_51_91_0 = _rtB -> B_51_37_0 ;
break ; case 1 : rtb_B_51_91_0 = _rtB -> B_51_37_0 ; break ; case 2 :
rtb_B_51_91_0 = _rtB -> B_51_37_0 ; break ; case 3 : rtb_B_51_91_0 = _rtB ->
B_18_0_3 ; break ; case 4 : rtb_B_51_91_0 = _rtB -> B_17_0_3 ; break ;
default : rtb_B_51_91_0 = _rtB -> B_51_37_0 ; break ; } _rtB -> B_51_560_0 =
rtb_B_51_91_0 * _rtB -> B_51_38_0 ; ssCallAccelRunBlock ( S , 14 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> B_14_0_1 > _rtP -> P_148 ) { _rtB ->
B_51_562_0 = _rtP -> P_148 ; } else if ( _rtB -> B_14_0_1 < _rtP -> P_149 ) {
_rtB -> B_51_562_0 = _rtP -> P_149 ; } else { _rtB -> B_51_562_0 = _rtB ->
B_14_0_1 ; } ssCallAccelRunBlock ( S , 13 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> B_51_564_0 = _rtP -> P_150 * _rtB -> B_13_0_1 ; rtb_B_51_195_0 [ 0 ] =
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 1 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) - muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ;
rtb_B_51_195_0 [ 2 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) + muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 3 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 4 ] = muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 5 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) - muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 6 ] = _rtP ->
P_151 * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 7 ] =
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 8 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ;
rtb_B_51_39_0 = _rtP -> P_152 * rtb_B_51_91_0 ; for ( isHit = 0 ; isHit < 3 ;
isHit ++ ) { _rtB -> B_51_614_0 [ isHit ] = 0.0 ; _rtB -> B_51_614_0 [ isHit
] += rtb_B_51_195_0 [ isHit ] * _rtB -> B_51_62_0 ; _rtB -> B_51_614_0 [
isHit ] += rtb_B_51_195_0 [ isHit + 3 ] * _rtB -> B_51_62_0 ; _rtB ->
B_51_614_0 [ isHit ] += rtb_B_51_195_0 [ isHit + 6 ] * rtb_B_51_39_0 ; } _rtB
-> B_51_616_0 = muDoubleScalarAtan ( rtb_B_51_56_0 [ 1 ] / rtb_B_51_56_0 [ 0
] ) ; switch ( ( int32_T ) _rtB -> B_51_117_0 ) { case 0 : rtb_B_51_91_0 =
_rtB -> B_51_37_0 ; break ; case 1 : rtb_B_51_91_0 = _rtB -> B_51_37_0 ;
break ; case 2 : rtb_B_51_91_0 = _rtB -> B_51_37_0 ; break ; case 3 :
rtb_B_51_91_0 = _rtB -> B_18_0_1 ; break ; case 4 : rtb_B_51_91_0 = _rtB ->
B_17_0_1 ; break ; default : rtb_B_51_91_0 = _rtB -> B_51_37_0 ; break ; }
_rtB -> B_51_618_0 = rtb_B_51_91_0 * _rtB -> B_51_38_0 ; ssCallAccelRunBlock
( S , 16 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> B_16_0_1 > _rtP -> P_153
) { _rtB -> B_51_620_0 = _rtP -> P_153 ; } else if ( _rtB -> B_16_0_1 < _rtP
-> P_154 ) { _rtB -> B_51_620_0 = _rtP -> P_154 ; } else { _rtB -> B_51_620_0
= _rtB -> B_16_0_1 ; } ssCallAccelRunBlock ( S , 15 , 0 , SS_CALL_MDL_OUTPUTS
) ; _rtB -> B_51_622_0 = _rtP -> P_155 * _rtB -> B_15_0_1 ; rtb_B_51_195_0 [
0 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB
-> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 1 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) - muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ;
rtb_B_51_195_0 [ 2 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) + muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 3 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 4 ] = muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ;
rtb_B_51_195_0 [ 5 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) - muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_195_0 [ 6 ] = _rtP ->
P_156 * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 7 ] =
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) ; rtb_B_51_195_0 [ 8 ] = muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ;
rtb_B_51_39_0 = _rtP -> P_157 * rtb_B_51_91_0 ; for ( isHit = 0 ; isHit < 3 ;
isHit ++ ) { _rtB -> B_51_672_0 [ isHit ] = 0.0 ; _rtB -> B_51_672_0 [ isHit
] += rtb_B_51_195_0 [ isHit ] * _rtB -> B_51_65_0 ; _rtB -> B_51_672_0 [
isHit ] += rtb_B_51_195_0 [ isHit + 3 ] * _rtB -> B_51_65_0 ; _rtB ->
B_51_672_0 [ isHit ] += rtb_B_51_195_0 [ isHit + 6 ] * rtb_B_51_39_0 ; } _rtB
-> B_51_673_0 [ 0 ] = ( _rtB -> B_51_506_0 + _rtB -> B_51_564_0 ) + _rtB ->
B_51_622_0 ; _rtB -> B_51_673_0 [ 1 ] = ( _rtB -> B_11_0_2 + _rtB -> B_13_0_2
) + _rtB -> B_15_0_2 ; _rtB -> B_51_673_0 [ 2 ] = ( _rtB -> B_51_556_0 [ 2 ]
+ _rtB -> B_51_614_0 [ 2 ] ) + _rtB -> B_51_672_0 [ 2 ] ; _rtB -> B_51_683_0
[ 0 ] = ( _rtB -> B_51_111_0 [ 0 ] + _rtB -> B_51_673_0 [ 0 ] ) / _rtB ->
B_51_6_0 + ( _rtB -> B_51_35_0 [ 1 ] * _rtB -> B_51_69_0 [ 2 ] - _rtB ->
B_51_35_0 [ 2 ] * _rtB -> B_51_69_0 [ 1 ] ) ; _rtB -> B_51_683_0 [ 1 ] = (
_rtB -> B_51_111_0 [ 1 ] + _rtB -> B_51_673_0 [ 1 ] ) / _rtB -> B_51_6_0 + (
_rtB -> B_51_35_0 [ 2 ] * _rtB -> B_51_69_0 [ 0 ] - _rtB -> B_51_35_0 [ 0 ] *
_rtB -> B_51_69_0 [ 2 ] ) ; _rtB -> B_51_683_0 [ 2 ] = ( _rtB -> B_51_111_0 [
2 ] + _rtB -> B_51_673_0 [ 2 ] ) / _rtB -> B_51_6_0 + ( _rtB -> B_51_35_0 [ 0
] * _rtB -> B_51_69_0 [ 1 ] - _rtB -> B_51_35_0 [ 1 ] * _rtB -> B_51_69_0 [ 0
] ) ; for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { _rtB -> B_51_685_0 [ isHit ]
= _rtB -> B_51_683_0 [ isHit ] - ( ( rtb_B_51_12_0 [ isHit + 3 ] * _rtB ->
B_51_141_0 [ 1 ] + rtb_B_51_12_0 [ isHit ] * _rtB -> B_51_141_0 [ 0 ] ) +
rtb_B_51_12_0 [ isHit + 6 ] * _rtB -> B_51_141_0 [ 2 ] ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_12_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_12_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_685_0 [ 0 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_13_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_13_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_685_0 [ 1 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_14_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_14_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_685_0 [ 2 ] + 0 ) ; } } }
for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { _rtB -> B_51_690_0 [ isHit ] = 0.0
; _rtB -> B_51_690_0 [ isHit ] += rtb_B_51_12_0 [ 3 * isHit ] * _rtB ->
B_51_35_0 [ 0 ] ; _rtB -> B_51_690_0 [ isHit ] += rtb_B_51_12_0 [ 3 * isHit +
1 ] * _rtB -> B_51_35_0 [ 1 ] ; _rtB -> B_51_690_0 [ isHit ] += rtb_B_51_12_0
[ 3 * isHit + 2 ] * _rtB -> B_51_35_0 [ 2 ] ; } _rtB -> B_51_691_0 =
muDoubleScalarAtan2 ( _rtB -> B_51_690_0 [ 1 ] , _rtB -> B_51_690_0 [ 0 ] ) ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_15_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_15_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_691_0 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_16_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_16_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_690_0 [ 0 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_17_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_17_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_690_0 [ 1 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_18_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_18_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_690_0 [ 2 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_2_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_2_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_34_0_1 + 0 ) ; } } } _rtB ->
B_51_697_0 [ 0 ] = _rtX -> PositionIntegrator2_CSTATE [ 0 ] ; _rtB ->
B_51_697_0 [ 1 ] = _rtX -> PositionIntegrator2_CSTATE [ 1 ] ; _rtB ->
B_51_697_0 [ 2 ] = _rtX -> PositionIntegrator2_CSTATE [ 2 ] ; rtb_B_51_91_0 =
_rtB -> B_51_697_0 [ 0 ] + _rtB -> B_51_145_0 ; if ( muDoubleScalarMod (
rtb_B_51_91_0 , _rtB -> B_51_143_0 ) >= _rtP -> P_159 ) { _rtB -> B_51_703_0
= ( muDoubleScalarMod ( rtb_B_51_91_0 , _rtB -> B_51_144_0 ) - _rtB ->
B_51_145_0 ) * _rtP -> P_34 ; } else { _rtB -> B_51_703_0 = muDoubleScalarMod
( rtb_B_51_91_0 , _rtB -> B_51_144_0 ) - _rtB -> B_51_145_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_3_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_3_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_703_0 + 0 ) ; } } } _rtB
-> B_51_707_0 = muDoubleScalarMod ( _rtB -> B_51_697_0 [ 1 ] + _rtB ->
B_51_147_0_l , _rtB -> B_51_146_0_g ) - _rtB -> B_51_147_0_l ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_4_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_4_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_707_0 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_5_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_5_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_697_0 [ 2 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_6_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_6_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_0_0 [ 0 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_7_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_7_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_0_0 [ 1 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_8_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_8_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_0_0 [ 2 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_BusSelector_at_outport_9_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_BusSelector_at_outport_9_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_69_0 [ 0 ] + 0 ) ; } }
B_51_714_0 = _rtP -> P_160 * _rtB -> B_51_106_0 ; } rtb_B_51_91_0 = _rtP ->
P_161 * _rtB -> B_51_13_0 [ 2 ] ; if ( rtb_B_51_91_0 > _rtP -> P_162 ) {
rtb_B_51_81_0 = _rtP -> P_162 ; } else if ( rtb_B_51_91_0 < _rtP -> P_163 ) {
rtb_B_51_81_0 = _rtP -> P_163 ; } else { rtb_B_51_81_0 = rtb_B_51_91_0 ; }
rtb_B_51_81_0 = _rtB -> B_51_140_0 - _rtP -> P_164 * rtb_B_51_81_0 ;
rtb_B_51_84_0 = _rtP -> P_165 * rtb_B_51_81_0 ; rtb_B_51_38_0 = _rtB ->
B_51_138_0 - rtb_B_51_91_0 ; if ( ( rtb_B_51_84_0 < 0.0 ) && ( _rtB ->
B_51_139_0 > muDoubleScalarFloor ( _rtB -> B_51_139_0 ) ) ) { rtb_B_51_91_0 =
- muDoubleScalarPower ( - rtb_B_51_84_0 , _rtB -> B_51_139_0 ) ; } else {
rtb_B_51_91_0 = muDoubleScalarPower ( rtb_B_51_84_0 , _rtB -> B_51_139_0 ) ;
} if ( rtb_B_51_38_0 > _rtP -> P_167 ) { rtb_B_51_38_0 = _rtP -> P_167 ; }
else { if ( rtb_B_51_38_0 < _rtP -> P_168 ) { rtb_B_51_38_0 = _rtP -> P_168 ;
} } _rtB -> B_51_728_0 = rtb_B_51_91_0 / rtb_B_51_84_0 * _rtP -> P_166 *
muDoubleScalarExp ( 1.0 / rtb_B_51_81_0 * ( _rtP -> P_169 * rtb_B_51_38_0 ) )
; _rtB -> B_51_732_0 = muDoubleScalarSqrt ( _rtB -> B_51_690_0 [ 0 ] * _rtB
-> B_51_690_0 [ 0 ] + _rtB -> B_51_690_0 [ 1 ] * _rtB -> B_51_690_0 [ 1 ] ) ;
_rtB -> B_51_734_0 = _rtB -> B_51_728_0 * _rtB -> B_51_137_0 * ( _rtB ->
B_34_0_1 * _rtB -> B_34_0_1 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 0 ] &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 0 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_35_0 [ 2 ] + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 1 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_63_0
+ 0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 2 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_67_0 + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 3 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_34_0_1 +
0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 4 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_703_0 + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 5 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_707_0
+ 0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 6 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_697_0 [ 2 ] + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 7 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_0_0 [
0 ] + 0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 8 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_0_0 [ 1 ] + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 9 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_0_0 [
2 ] + 0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 10 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_69_0 [ 0 ] + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 11 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_69_0
[ 1 ] + 0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 12 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_69_0 [ 2 ] + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 13 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB ->
B_51_685_0 [ 0 ] + 0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 14 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_685_0 [ 1 ] + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 15 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB ->
B_51_685_0 [ 2 ] + 0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 16 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_691_0 + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 17 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB ->
B_51_690_0 [ 0 ] + 0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 18 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_690_0 [ 1 ] + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 19 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB ->
B_51_690_0 [ 2 ] + 0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 20 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & B_51_714_0 + 0 ) ; sdiWriteSignal (
_rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 21
] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_728_0 + 0 ) ;
sdiWriteSignal ( _rtDW -> TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK
. AQHandles [ 22 ] , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB ->
B_51_732_0 + 0 ) ; sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK . AQHandles [ 23 ] ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_734_0 + 0 ) ; } } } _rtB
-> B_51_736_0 = _rtP -> P_170 * _rtB -> B_51_707_0 ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_RadianstoDegrees1_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_RadianstoDegrees1_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_736_0 + 0 ) ; } } } _rtB
-> B_51_738_0 = _rtP -> P_171 * _rtB -> B_51_703_0 ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_RadianstoDegrees_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_RadianstoDegrees_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_738_0 + 0 ) ; } } } isHit
= ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_740_0 = _rtP
-> P_172 ; _rtB -> B_51_741_0 = _rtP -> P_173 ; _rtB -> B_51_742_0 = _rtP ->
P_174 ; _rtB -> B_51_743_0 = _rtP -> P_175 ; } _rtB -> B_51_744_0 = ssGetT (
S ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 41 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtP -> P_558
== 1 ) { _rtB -> B_51_746_0 = _rtB -> B_41_0_1 ; } else { _rtB -> B_51_746_0
= _rtB -> B_51_163_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { if ( _rtP -> P_559 == 1 ) { _rtB -> B_51_747_0 = _rtB -> B_51_164_0
; } else { _rtB -> B_51_747_0 = _rtB -> B_51_165_0 ; } if ( _rtP -> P_560 ==
1 ) { _rtB -> B_51_748_0 = _rtB -> B_51_166_0 ; } else { _rtB -> B_51_748_0 =
_rtB -> B_51_167_0 ; } if ( _rtP -> P_561 == 1 ) { _rtB -> B_51_749_0 = _rtB
-> B_51_160_0 ; } else { _rtB -> B_51_749_0 = _rtB -> B_51_161_0 ; } if (
_rtP -> P_562 == 1 ) { _rtB -> B_51_750_0 = _rtB -> B_51_169_0 ; } else {
_rtB -> B_51_750_0 = _rtB -> B_51_170_0 ; } if ( _rtP -> P_563 == 1 ) { _rtB
-> B_51_751_0 = _rtB -> B_51_171_0 ; } else { _rtB -> B_51_751_0 = _rtB ->
B_51_174_0 ; } } _rtB -> B_51_752_0 = ssGetT ( S ) ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 42 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit !=
0 ) { if ( _rtP -> P_564 == 1 ) { _rtB -> B_51_754_0 = _rtB -> B_51_159_0 ; }
else { _rtB -> B_51_754_0 = _rtB -> B_51_162_0 ; } } _rtB -> B_51_755_0 =
ssGetT ( S ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 40 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtP -> P_565
== 1 ) { _rtB -> B_51_757_0 = _rtB -> B_40_0_1 ; } else { _rtB -> B_51_757_0
= _rtB -> B_51_172_0 ; } } _rtB -> B_51_758_0 = ssGetT ( S ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
44 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtP -> P_566 == 1 ) { _rtB ->
B_51_760_0 = _rtB -> B_44_0_1 ; } else { _rtB -> B_51_760_0 = _rtB ->
B_51_177_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { if
( _rtP -> P_567 == 1 ) { _rtB -> B_51_761_0 = 0.0 ; } else { _rtB ->
B_51_761_0 = _rtB -> B_51_178_0 ; } } _rtB -> B_51_762_0 = ssGetT ( S ) ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock
( S , 43 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtP -> P_568 == 1 ) { _rtB ->
B_51_764_0 = _rtB -> B_43_0_1 ; } else { _rtB -> B_51_764_0 = _rtB ->
B_51_175_0 ; } } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
Delay_gps_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) &
_rtDW -> Delay_gps_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S )
; real_T tMinusDelay = simTime - _rtP -> P_176 ; if ( _rtP -> P_176 == 0.0 )
B_51_765_0 = _rtB -> B_51_703_0 ; else B_51_765_0 =
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 ,
* tBuffer , * uBuffer , _rtDW -> Delay_gps_IWORK . CircularBufSize , & _rtDW
-> Delay_gps_IWORK . Last , _rtDW -> Delay_gps_IWORK . Tail , _rtDW ->
Delay_gps_IWORK . Head , _rtP -> P_177 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_51_91_0 = _rtX -> Integrator_CSTATE_j ; _rtB -> B_51_767_0 =
B_51_765_0 + _rtX -> Integrator_CSTATE_j ; isHit = ssIsSampleHit ( S , 3 , 0
) ; if ( isHit != 0 ) { _rtB -> B_51_768_0 = _rtB -> B_51_767_0 ; _rtB ->
B_51_772_0 = ( real32_T ) ( _rtP -> P_179 * _rtB -> B_51_768_0 ) * _rtP ->
P_180 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_51_773_0 = _rtB -> B_51_772_0 ; } { real_T * * uBuffer = ( real_T * * ) &
_rtDW -> Delay_gps_PWORK_k . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = (
real_T * * ) & _rtDW -> Delay_gps_PWORK_k . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_181 ; if (
_rtP -> P_181 == 0.0 ) B_51_774_0 = _rtB -> B_51_707_0 ; else B_51_774_0 =
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 ,
* tBuffer , * uBuffer , _rtDW -> Delay_gps_IWORK_b . CircularBufSize , &
_rtDW -> Delay_gps_IWORK_b . Last , _rtDW -> Delay_gps_IWORK_b . Tail , _rtDW
-> Delay_gps_IWORK_b . Head , _rtP -> P_182 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } _rtB -> B_51_775_0 = _rtX -> Integrator_CSTATE_k ; _rtB -> B_51_776_0 =
B_51_774_0 + _rtB -> B_51_775_0 ; isHit = ssIsSampleHit ( S , 3 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_51_777_0 = _rtB -> B_51_776_0 ; _rtB -> B_51_781_0 =
( real32_T ) ( _rtP -> P_184 * _rtB -> B_51_777_0 ) * _rtP -> P_185 ; } isHit
= ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_782_0 = _rtB
-> B_51_781_0 ; } _rtB -> B_51_783_0 = _rtB -> B_51_697_0 [ 2 ] + _rtB ->
B_51_188_0 ; { real_T * * uBuffer = ( real_T * * ) & _rtDW -> Delay_bmp_PWORK
. TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
Delay_bmp_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; real_T
tMinusDelay = simTime - _rtP -> P_186 ; if ( _rtP -> P_186 == 0.0 ) _rtB ->
B_51_784_0 = _rtB -> B_51_783_0 ; else _rtB -> B_51_784_0 =
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 ,
* tBuffer , * uBuffer , _rtDW -> Delay_bmp_IWORK . CircularBufSize , & _rtDW
-> Delay_bmp_IWORK . Last , _rtDW -> Delay_bmp_IWORK . Tail , _rtDW ->
Delay_bmp_IWORK . Head , _rtP -> P_187 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } ssCallAccelRunBlock ( S , 46 , 0 , SS_CALL_MDL_OUTPUTS ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_786_0 = _rtDW
-> NextOutput_l ; } _rtB -> B_51_787_0 = _rtB -> B_46_0_1 + _rtB ->
B_51_786_0 ; ssCallAccelRunBlock ( S , 47 , 0 , SS_CALL_MDL_OUTPUTS ) ; isHit
= ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_789_0 = _rtB
-> B_47_0_1 ; _rtB -> B_51_791_0 = ( real32_T ) _rtB -> B_51_789_0 ; } {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> Delay_gps_PWORK_l .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
Delay_gps_PWORK_l . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_191 ; if ( _rtP -> P_191 == 0.0 )
_rtB -> B_51_792_0 = _rtB -> B_51_732_0 ; else _rtB -> B_51_792_0 =
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 ,
* tBuffer , * uBuffer , _rtDW -> Delay_gps_IWORK_l . CircularBufSize , &
_rtDW -> Delay_gps_IWORK_l . Last , _rtDW -> Delay_gps_IWORK_l . Tail , _rtDW
-> Delay_gps_IWORK_l . Head , _rtP -> P_192 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_51_793_0 = _rtB -> B_51_792_0 ; } isHit = ssIsSampleHit ( S , 3 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_51_794_0 = _rtDW -> NextOutput_m ; _rtB ->
B_51_795_0 = _rtDW -> NextOutput_j ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { if ( _rtB -> B_51_793_0 > _rtP -> P_199 ) { _rtB ->
B_51_796_0 = _rtB -> B_51_794_0 ; } else { _rtB -> B_51_796_0 = _rtB ->
B_51_795_0 ; } rtb_B_51_797_0 = _rtB -> B_51_793_0 + _rtB -> B_51_796_0 ; if
( _rtB -> B_51_793_0 > _rtP -> P_206 ) { rtb_B_51_801_0 = _rtB -> B_51_193_0
/ _rtB -> B_51_793_0 * _rtDW -> NextOutput_f ; } else { rtb_B_51_801_0 =
_rtDW -> NextOutput_fh ; } } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
Delay_gps1_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) &
_rtDW -> Delay_gps1_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S
) ; real_T tMinusDelay = simTime - _rtP -> P_207 ; if ( _rtP -> P_207 == 0.0
) _rtB -> B_51_802_0 = _rtB -> B_51_691_0 ; else _rtB -> B_51_802_0 =
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 ,
* tBuffer , * uBuffer , _rtDW -> Delay_gps1_IWORK . CircularBufSize , & _rtDW
-> Delay_gps1_IWORK . Last , _rtDW -> Delay_gps1_IWORK . Tail , _rtDW ->
Delay_gps1_IWORK . Head , _rtP -> P_208 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_51_803_0 = _rtB -> B_51_802_0 ; _rtB -> B_51_804_0 = rtb_B_51_801_0 + _rtB
-> B_51_803_0 ; ssCallAccelRunBlock ( S , 49 , 0 , SS_CALL_MDL_OUTPUTS ) ; if
( _rtB -> B_51_793_0 > _rtP -> P_209 ) { _rtB -> B_51_806_0 = _rtB ->
B_49_0_1 ; } else { _rtB -> B_51_806_0 = _rtB -> B_51_191_0 ; } _rtB ->
B_51_808_0 = rtb_B_51_797_0 * muDoubleScalarCos ( _rtB -> B_51_806_0 ) ;
isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_809_0
= _rtB -> B_51_808_0 ; } _rtB -> B_51_810_0 = _rtB -> B_51_809_0 ; _rtB ->
B_51_812_0 = rtb_B_51_797_0 * muDoubleScalarSin ( _rtB -> B_51_806_0 ) ;
isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_813_0
= _rtB -> B_51_812_0 ; } _rtB -> B_51_814_0 = _rtB -> B_51_813_0 ; } { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs1_PWORK . TUbufferPtrs [ 0
] ; real_T * * tBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs1_PWORK .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_210 ; if ( _rtP -> P_210 == 0.0 ) B_51_815_0 = _rtB ->
B_51_0_0 [ 0 ] ; else B_51_815_0 =
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 ,
* tBuffer , * uBuffer , _rtDW -> Delay_ahrs1_IWORK . CircularBufSize , &
_rtDW -> Delay_ahrs1_IWORK . Last , _rtDW -> Delay_ahrs1_IWORK . Tail , _rtDW
-> Delay_ahrs1_IWORK . Head , _rtP -> P_211 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_51_81_0 = _rtX -> Integrator2_CSTATE ; _rtB -> B_51_817_0 =
B_51_815_0 + _rtX -> Integrator2_CSTATE ; isHit = ssIsSampleHit ( S , 2 , 0 )
; if ( isHit != 0 ) { _rtB -> B_51_818_0 = _rtB -> B_51_817_0 ; B_51_819_0 =
_rtP -> P_213 * _rtB -> B_51_818_0 ; rtb_B_51_38_0 = muDoubleScalarFloor (
_rtP -> P_214 * B_51_819_0 ) ; if ( muDoubleScalarIsNaN ( rtb_B_51_38_0 ) ||
muDoubleScalarIsInf ( rtb_B_51_38_0 ) ) { rtb_B_51_38_0 = 0.0 ; } else {
rtb_B_51_38_0 = muDoubleScalarRem ( rtb_B_51_38_0 , 65536.0 ) ; } _rtB ->
B_51_824_0 = ( real_T ) ( rtb_B_51_38_0 < 0.0 ? ( int32_T ) ( int16_T ) - (
int16_T ) ( uint16_T ) - rtb_B_51_38_0 : ( int32_T ) ( int16_T ) ( uint16_T )
rtb_B_51_38_0 ) * _rtP -> P_215 * _rtP -> P_216 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> Delay_ahrs2_PWORK . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs2_PWORK . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_217
; if ( _rtP -> P_217 == 0.0 ) B_51_825_0 = _rtB -> B_51_0_0 [ 1 ] ; else
B_51_825_0 = v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> Delay_ahrs2_IWORK .
CircularBufSize , & _rtDW -> Delay_ahrs2_IWORK . Last , _rtDW ->
Delay_ahrs2_IWORK . Tail , _rtDW -> Delay_ahrs2_IWORK . Head , _rtP -> P_218
, 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S
) == ssGetT ( S ) ) ) ) ; } rtb_B_51_801_0 = _rtX -> Integrator1_CSTATE_h ;
_rtB -> B_51_827_0 = B_51_825_0 + _rtX -> Integrator1_CSTATE_h ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_828_0 = _rtB
-> B_51_827_0 ; rtb_B_51_38_0 = muDoubleScalarFloor ( _rtP -> P_220 * _rtB ->
B_51_828_0 * _rtP -> P_221 ) ; if ( muDoubleScalarIsNaN ( rtb_B_51_38_0 ) ||
muDoubleScalarIsInf ( rtb_B_51_38_0 ) ) { rtb_B_51_38_0 = 0.0 ; } else {
rtb_B_51_38_0 = muDoubleScalarRem ( rtb_B_51_38_0 , 65536.0 ) ; } _rtB ->
B_51_834_0 = ( real_T ) ( rtb_B_51_38_0 < 0.0 ? ( int32_T ) ( int16_T ) - (
int16_T ) ( uint16_T ) - rtb_B_51_38_0 : ( int32_T ) ( int16_T ) ( uint16_T )
rtb_B_51_38_0 ) * _rtP -> P_222 * _rtP -> P_223 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> Delay_ahrs3_PWORK . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs3_PWORK . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_224
; if ( _rtP -> P_224 == 0.0 ) B_51_835_0 = _rtB -> B_51_0_0 [ 2 ] ; else
B_51_835_0 = v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> Delay_ahrs3_IWORK .
CircularBufSize , & _rtDW -> Delay_ahrs3_IWORK . Last , _rtDW ->
Delay_ahrs3_IWORK . Tail , _rtDW -> Delay_ahrs3_IWORK . Head , _rtP -> P_225
, 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S
) == ssGetT ( S ) ) ) ) ; } rtb_B_51_797_0 = _rtX -> Integrator_CSTATE_d ;
_rtB -> B_51_837_0 = B_51_835_0 + _rtX -> Integrator_CSTATE_d ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_838_0 = _rtB
-> B_51_837_0 ; rtb_B_51_38_0 = muDoubleScalarFloor ( _rtP -> P_227 * _rtB ->
B_51_838_0 * _rtP -> P_228 ) ; if ( muDoubleScalarIsNaN ( rtb_B_51_38_0 ) ||
muDoubleScalarIsInf ( rtb_B_51_38_0 ) ) { rtb_B_51_38_0 = 0.0 ; } else {
rtb_B_51_38_0 = muDoubleScalarRem ( rtb_B_51_38_0 , 65536.0 ) ; } _rtB ->
B_51_844_0 = ( real_T ) ( rtb_B_51_38_0 < 0.0 ? ( int32_T ) ( int16_T ) - (
int16_T ) ( uint16_T ) - rtb_B_51_38_0 : ( int32_T ) ( int16_T ) ( uint16_T )
rtb_B_51_38_0 ) * _rtP -> P_229 * _rtP -> P_230 ; } isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_845_0 = _rtDW ->
Memory2_PreviousInput_k ; ssCallAccelRunBlock ( S , 48 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0
) { _rtB -> B_51_847_0 = _rtB -> B_48_0_1 ; } } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> Delay_ahrs_PWORK . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs_PWORK . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_232
; if ( _rtP -> P_232 == 0.0 ) B_51_848_0 = _rtB -> B_51_685_0 [ 0 ] ; else
B_51_848_0 = v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> Delay_ahrs_IWORK .
CircularBufSize , & _rtDW -> Delay_ahrs_IWORK . Last , _rtDW ->
Delay_ahrs_IWORK . Tail , _rtDW -> Delay_ahrs_IWORK . Head , _rtP -> P_233 ,
0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S )
== ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_51_849_0 = _rtDW -> NextOutput_b ; } _rtB -> B_51_850_0 =
B_51_848_0 + _rtB -> B_51_849_0 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_51_851_0 = _rtB -> B_51_850_0 ; rtb_B_51_38_0 =
muDoubleScalarFloor ( _rtP -> P_237 * _rtB -> B_51_851_0 ) ; if (
muDoubleScalarIsNaN ( rtb_B_51_38_0 ) || muDoubleScalarIsInf ( rtb_B_51_38_0
) ) { rtb_B_51_38_0 = 0.0 ; } else { rtb_B_51_38_0 = muDoubleScalarRem (
rtb_B_51_38_0 , 65536.0 ) ; } _rtB -> B_51_855_0 = ( real_T ) ( rtb_B_51_38_0
< 0.0 ? ( int32_T ) ( int16_T ) - ( int16_T ) ( uint16_T ) - rtb_B_51_38_0 :
( int32_T ) ( int16_T ) ( uint16_T ) rtb_B_51_38_0 ) * _rtP -> P_238 ; } {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs5_PWORK .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
Delay_ahrs5_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_239 ; if ( _rtP -> P_239 == 0.0 )
B_51_856_0 = _rtB -> B_51_685_0 [ 1 ] ; else B_51_856_0 =
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 ,
* tBuffer , * uBuffer , _rtDW -> Delay_ahrs5_IWORK . CircularBufSize , &
_rtDW -> Delay_ahrs5_IWORK . Last , _rtDW -> Delay_ahrs5_IWORK . Tail , _rtDW
-> Delay_ahrs5_IWORK . Head , _rtP -> P_240 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_51_857_0 = _rtDW -> NextOutput_e ; } _rtB -> B_51_858_0 = B_51_856_0 + _rtB
-> B_51_857_0 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_51_859_0 = _rtB -> B_51_858_0 ; rtb_B_51_38_0 = muDoubleScalarFloor
( _rtP -> P_244 * _rtB -> B_51_859_0 ) ; if ( muDoubleScalarIsNaN (
rtb_B_51_38_0 ) || muDoubleScalarIsInf ( rtb_B_51_38_0 ) ) { rtb_B_51_38_0 =
0.0 ; } else { rtb_B_51_38_0 = muDoubleScalarRem ( rtb_B_51_38_0 , 65536.0 )
; } _rtB -> B_51_863_0 = ( real_T ) ( rtb_B_51_38_0 < 0.0 ? ( int32_T ) (
int16_T ) - ( int16_T ) ( uint16_T ) - rtb_B_51_38_0 : ( int32_T ) ( int16_T
) ( uint16_T ) rtb_B_51_38_0 ) * _rtP -> P_245 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> Delay_ahrs4_PWORK . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs4_PWORK . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_246
; if ( _rtP -> P_246 == 0.0 ) B_51_864_0 = _rtB -> B_51_685_0 [ 2 ] ; else
B_51_864_0 = v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> Delay_ahrs4_IWORK .
CircularBufSize , & _rtDW -> Delay_ahrs4_IWORK . Last , _rtDW ->
Delay_ahrs4_IWORK . Tail , _rtDW -> Delay_ahrs4_IWORK . Head , _rtP -> P_247
, 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S
) == ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_51_865_0 = _rtDW -> NextOutput_mv ; } _rtB -> B_51_866_0 =
B_51_864_0 + _rtB -> B_51_865_0 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_51_867_0 = _rtB -> B_51_866_0 ; rtb_B_51_38_0 =
muDoubleScalarFloor ( _rtP -> P_251 * _rtB -> B_51_867_0 ) ; if (
muDoubleScalarIsNaN ( rtb_B_51_38_0 ) || muDoubleScalarIsInf ( rtb_B_51_38_0
) ) { rtb_B_51_38_0 = 0.0 ; } else { rtb_B_51_38_0 = muDoubleScalarRem (
rtb_B_51_38_0 , 65536.0 ) ; } _rtB -> B_51_871_0 = ( real_T ) ( rtb_B_51_38_0
< 0.0 ? ( int32_T ) ( int16_T ) - ( int16_T ) ( uint16_T ) - rtb_B_51_38_0 :
( int32_T ) ( int16_T ) ( uint16_T ) rtb_B_51_38_0 ) * _rtP -> P_252 ; } {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs6_PWORK .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
Delay_ahrs6_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_253 ; if ( _rtP -> P_253 == 0.0 )
B_51_872_0 = _rtB -> B_51_69_0 [ 0 ] ; else B_51_872_0 =
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 ,
* tBuffer , * uBuffer , _rtDW -> Delay_ahrs6_IWORK . CircularBufSize , &
_rtDW -> Delay_ahrs6_IWORK . Last , _rtDW -> Delay_ahrs6_IWORK . Tail , _rtDW
-> Delay_ahrs6_IWORK . Head , _rtP -> P_254 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_51_873_0 = _rtDW -> NextOutput_p ; } _rtB -> B_51_874_0 = B_51_872_0 + _rtB
-> B_51_873_0 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_51_875_0 = _rtB -> B_51_874_0 ; rtb_B_51_38_0 = muDoubleScalarFloor
( _rtP -> P_258 * _rtB -> B_51_875_0 * _rtP -> P_259 ) ; if (
muDoubleScalarIsNaN ( rtb_B_51_38_0 ) || muDoubleScalarIsInf ( rtb_B_51_38_0
) ) { rtb_B_51_38_0 = 0.0 ; } else { rtb_B_51_38_0 = muDoubleScalarRem (
rtb_B_51_38_0 , 65536.0 ) ; } _rtB -> B_51_881_0 = ( real_T ) ( rtb_B_51_38_0
< 0.0 ? ( int32_T ) ( int16_T ) - ( int16_T ) ( uint16_T ) - rtb_B_51_38_0 :
( int32_T ) ( int16_T ) ( uint16_T ) rtb_B_51_38_0 ) * _rtP -> P_260 * _rtP
-> P_261 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
Delay_ahrs7_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& _rtDW -> Delay_ahrs7_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
S ) ; real_T tMinusDelay = simTime - _rtP -> P_262 ; if ( _rtP -> P_262 ==
0.0 ) B_51_882_0 = _rtB -> B_51_69_0 [ 1 ] ; else B_51_882_0 =
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 ,
* tBuffer , * uBuffer , _rtDW -> Delay_ahrs7_IWORK . CircularBufSize , &
_rtDW -> Delay_ahrs7_IWORK . Last , _rtDW -> Delay_ahrs7_IWORK . Tail , _rtDW
-> Delay_ahrs7_IWORK . Head , _rtP -> P_263 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_51_883_0 = _rtDW -> NextOutput_bz ; } _rtB -> B_51_884_0 = B_51_882_0 +
_rtB -> B_51_883_0 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 )
{ _rtB -> B_51_885_0 = _rtB -> B_51_884_0 ; rtb_B_51_38_0 =
muDoubleScalarFloor ( _rtP -> P_267 * _rtB -> B_51_885_0 * _rtP -> P_268 ) ;
if ( muDoubleScalarIsNaN ( rtb_B_51_38_0 ) || muDoubleScalarIsInf (
rtb_B_51_38_0 ) ) { rtb_B_51_38_0 = 0.0 ; } else { rtb_B_51_38_0 =
muDoubleScalarRem ( rtb_B_51_38_0 , 65536.0 ) ; } _rtB -> B_51_891_0 = (
real_T ) ( rtb_B_51_38_0 < 0.0 ? ( int32_T ) ( int16_T ) - ( int16_T ) (
uint16_T ) - rtb_B_51_38_0 : ( int32_T ) ( int16_T ) ( uint16_T )
rtb_B_51_38_0 ) * _rtP -> P_269 * _rtP -> P_270 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> Delay_ahrs8_PWORK . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs8_PWORK . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_271
; if ( _rtP -> P_271 == 0.0 ) B_51_892_0 = _rtB -> B_51_69_0 [ 2 ] ; else
B_51_892_0 = v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> Delay_ahrs8_IWORK .
CircularBufSize , & _rtDW -> Delay_ahrs8_IWORK . Last , _rtDW ->
Delay_ahrs8_IWORK . Tail , _rtDW -> Delay_ahrs8_IWORK . Head , _rtP -> P_272
, 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S
) == ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_51_893_0 = _rtDW -> NextOutput_fy ; } _rtB -> B_51_894_0 =
B_51_892_0 + _rtB -> B_51_893_0 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_51_895_0 = _rtB -> B_51_894_0 ; rtb_B_51_38_0 =
muDoubleScalarFloor ( _rtP -> P_276 * _rtB -> B_51_895_0 * _rtP -> P_277 ) ;
if ( muDoubleScalarIsNaN ( rtb_B_51_38_0 ) || muDoubleScalarIsInf (
rtb_B_51_38_0 ) ) { rtb_B_51_38_0 = 0.0 ; } else { rtb_B_51_38_0 =
muDoubleScalarRem ( rtb_B_51_38_0 , 65536.0 ) ; } _rtB -> B_51_901_0 = (
real_T ) ( rtb_B_51_38_0 < 0.0 ? ( int32_T ) ( int16_T ) - ( int16_T ) (
uint16_T ) - rtb_B_51_38_0 : ( int32_T ) ( int16_T ) ( uint16_T )
rtb_B_51_38_0 ) * _rtP -> P_278 * _rtP -> P_279 ; _rtB -> B_51_902_0 = _rtDW
-> NextOutput_o ; } _rtB -> B_51_903_0 = _rtB -> B_51_902_0 + _rtB ->
B_34_0_1 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_51_904_0 = _rtB -> B_51_903_0 ; } _rtB -> B_51_906_0 = _rtB -> B_51_697_0 [
2 ] ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_51_907_0 = _rtB -> B_51_906_0 ; _rtB -> B_51_908_0 = _rtDW -> NextOutput_a
; } _rtB -> B_51_909_0 = _rtB -> B_51_908_0 + _rtB -> B_51_734_0 ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_910_0 = _rtB
-> B_51_909_0 ; _rtB -> B_51_913_0 = muDoubleScalarSqrt ( _rtB -> B_51_194_0
* _rtB -> B_51_910_0 / _rtB -> B_51_195_0 ) ; ssCallAccelRunBlock ( S , 51 ,
914 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 51 , 915 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 51 , 916 ,
SS_CALL_MDL_OUTPUTS ) ; } for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { _rtB ->
B_51_917_0 [ isHit ] = 0.0 ; _rtB -> B_51_917_0 [ isHit ] += rtb_B_51_12_0 [
isHit ] * _rtB -> B_51_690_0 [ 0 ] ; _rtB -> B_51_917_0 [ isHit ] +=
rtb_B_51_12_0 [ isHit + 3 ] * _rtB -> B_51_690_0 [ 1 ] ; _rtB -> B_51_917_0 [
isHit ] += rtb_B_51_12_0 [ isHit + 6 ] * _rtB -> B_51_690_0 [ 2 ] ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
51 , 918 , SS_CALL_MDL_OUTPUTS ) ; B_51_919_0 [ 0 ] = _rtB -> B_51_110_0 ;
B_51_919_0 [ 1 ] = _rtB -> B_51_35_0_c ; B_51_919_0 [ 2 ] = _rtB ->
B_51_35_0_c ; { if ( _rtDW ->
TAQSigLogging_InsertedFor_Propulsione1_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Propulsione1_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & B_51_919_0 [ 0 ] + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_SubsystemReference_at_outport_0_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_SubsystemReference_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_673_0 [ 0 ] + 0 ) ; } } }
muDoubleScalarSinCos ( _rtB -> B_51_0_0 [ 0 ] , & rtb_B_51_1_0 [ 0 ] , &
rtb_B_51_56_0 [ 0 ] ) ; muDoubleScalarSinCos ( _rtB -> B_51_0_0 [ 1 ] , &
rtb_B_51_1_0 [ 1 ] , & rtb_B_51_56_0 [ 1 ] ) ; muDoubleScalarSinCos ( _rtB ->
B_51_0_0 [ 2 ] , & rtb_B_51_1_0 [ 2 ] , & rtb_B_51_56_0 [ 2 ] ) ; _rtB ->
B_51_926_0 [ 0 ] = ( _rtB -> B_51_69_0 [ 1 ] * rtb_B_51_1_0 [ 0 ] + _rtB ->
B_51_69_0 [ 2 ] * rtb_B_51_56_0 [ 0 ] ) * ( rtb_B_51_1_0 [ 1 ] /
rtb_B_51_56_0 [ 1 ] ) + _rtB -> B_51_69_0 [ 0 ] ; _rtB -> B_51_926_0 [ 1 ] =
_rtB -> B_51_69_0 [ 1 ] * rtb_B_51_56_0 [ 0 ] - _rtB -> B_51_69_0 [ 2 ] *
rtb_B_51_1_0 [ 0 ] ; rtb_B_51_112_0 [ 0 ] = _rtB -> B_51_126_0 [ 1 ] * _rtB
-> B_51_556_0 [ 2 ] ; rtb_B_51_112_0 [ 1 ] = _rtB -> B_51_126_0 [ 2 ] * _rtB
-> B_51_506_0 ; rtb_B_51_112_0 [ 2 ] = _rtB -> B_51_126_0 [ 0 ] * _rtB ->
B_11_0_2 ; rtb_B_51_112_0 [ 3 ] = _rtB -> B_51_126_0 [ 2 ] * _rtB -> B_11_0_2
; rtb_B_51_112_0 [ 4 ] = _rtB -> B_51_126_0 [ 0 ] * _rtB -> B_51_556_0 [ 2 ]
; rtb_B_51_112_0 [ 5 ] = _rtB -> B_51_126_0 [ 1 ] * _rtB -> B_51_506_0 ; for
( isHit = 0 ; isHit < 3 ; isHit ++ ) { rtb_B_51_38_0 = rtb_B_51_1_0 [ isHit ]
; rtb_B_51_42_0 = rtb_B_51_56_0 [ isHit ] ; rtb_B_51_12_0 [ isHit ] = _rtB ->
B_51_69_0 [ isHit ] ; rtb_B_51_12_0 [ isHit + 3 ] = rtb_B_51_38_0 ;
rtb_B_51_12_0 [ isHit + 6 ] = rtb_B_51_42_0 ; rtb_B_51_195_0 [ isHit ] = _rtB
-> B_51_69_0 [ isHit ] ; rtb_B_51_195_0 [ isHit + 3 ] = rtb_B_51_38_0 ;
rtb_B_51_195_0 [ isHit + 6 ] = rtb_B_51_42_0 ; tmp [ isHit ] = _rtB ->
B_51_69_0 [ isHit ] ; tmp [ isHit + 3 ] = rtb_B_51_38_0 ; tmp [ isHit + 6 ] =
rtb_B_51_42_0 ; tmp_0 [ isHit ] = _rtB -> B_51_69_0 [ isHit ] ; tmp_0 [ isHit
+ 3 ] = rtb_B_51_38_0 ; tmp_0 [ isHit + 6 ] = rtb_B_51_42_0 ; tmp_1 [ isHit ]
= _rtB -> B_51_69_0 [ isHit ] ; tmp_1 [ isHit + 3 ] = rtb_B_51_38_0 ; tmp_1 [
isHit + 6 ] = rtb_B_51_42_0 ; _rtB -> B_51_937_0 [ isHit ] = rtb_B_51_112_0 [
isHit ] - rtb_B_51_112_0 [ isHit + 3 ] ; rtb_B_51_1_0 [ isHit ] = _rtB ->
B_51_3_0 [ isHit + 6 ] * _rtB -> B_51_69_0 [ 2 ] + ( _rtB -> B_51_3_0 [ isHit
+ 3 ] * _rtB -> B_51_69_0 [ 1 ] + _rtB -> B_51_3_0 [ isHit ] * _rtB ->
B_51_69_0 [ 0 ] ) ; } _rtB -> B_51_926_0 [ 2 ] = ( rtb_B_51_12_0 [ 1 ] *
rtb_B_51_195_0 [ 3 ] + tmp [ 2 ] * tmp_0 [ 6 ] ) / tmp_1 [ 7 ] ; _rtB ->
B_51_939_0 [ 0 ] = _rtB -> B_51_70_0 [ 1 ] * _rtB -> B_51_614_0 [ 2 ] - _rtB
-> B_51_70_0 [ 2 ] * _rtB -> B_13_0_2 ; _rtB -> B_51_939_0 [ 1 ] = _rtB ->
B_51_70_0 [ 2 ] * _rtB -> B_51_564_0 - _rtB -> B_51_70_0 [ 0 ] * _rtB ->
B_51_614_0 [ 2 ] ; _rtB -> B_51_939_0 [ 2 ] = _rtB -> B_51_70_0 [ 0 ] * _rtB
-> B_13_0_2 - _rtB -> B_51_70_0 [ 1 ] * _rtB -> B_51_564_0 ; rtb_B_51_112_0 [
0 ] = _rtB -> B_51_71_0 [ 1 ] * _rtB -> B_51_672_0 [ 2 ] ; rtb_B_51_112_0 [ 1
] = _rtB -> B_51_71_0 [ 2 ] * _rtB -> B_51_622_0 ; rtb_B_51_112_0 [ 2 ] =
_rtB -> B_51_71_0 [ 0 ] * _rtB -> B_15_0_2 ; rtb_B_51_112_0 [ 3 ] = _rtB ->
B_51_71_0 [ 2 ] * _rtB -> B_15_0_2 ; rtb_B_51_112_0 [ 4 ] = _rtB -> B_51_71_0
[ 0 ] * _rtB -> B_51_672_0 [ 2 ] ; rtb_B_51_112_0 [ 5 ] = _rtB -> B_51_71_0 [
1 ] * _rtB -> B_51_622_0 ; rtb_B_51_56_0 [ 0 ] = _rtB -> B_51_69_0 [ 1 ] *
rtb_B_51_1_0 [ 2 ] ; rtb_B_51_56_0 [ 1 ] = _rtB -> B_51_69_0 [ 2 ] *
rtb_B_51_1_0 [ 0 ] ; rtb_B_51_56_0 [ 2 ] = _rtB -> B_51_69_0 [ 0 ] *
rtb_B_51_1_0 [ 1 ] ; rtb_B_51_2_1 [ 0 ] = _rtB -> B_51_69_0 [ 2 ] *
rtb_B_51_1_0 [ 1 ] ; rtb_B_51_2_1 [ 1 ] = _rtB -> B_51_69_0 [ 0 ] *
rtb_B_51_1_0 [ 2 ] ; rtb_B_51_2_1 [ 2 ] = _rtB -> B_51_69_0 [ 1 ] *
rtb_B_51_1_0 [ 0 ] ; for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { _rtB ->
B_51_941_0 [ isHit ] = rtb_B_51_112_0 [ isHit ] - rtb_B_51_112_0 [ isHit + 3
] ; rtb_B_51_1_0 [ isHit ] = ( ( ( ( _rtB -> B_51_937_0 [ isHit ] + _rtB ->
B_51_939_0 [ isHit ] ) + _rtB -> B_51_941_0 [ isHit ] ) + _rtB -> B_51_146_0
[ isHit ] ) - ( _rtB -> B_51_4_0 [ isHit + 6 ] * _rtB -> B_51_69_0 [ 2 ] + (
_rtB -> B_51_4_0 [ isHit + 3 ] * _rtB -> B_51_69_0 [ 1 ] + _rtB -> B_51_4_0 [
isHit ] * _rtB -> B_51_69_0 [ 0 ] ) ) ) - ( rtb_B_51_56_0 [ isHit ] -
rtb_B_51_2_1 [ isHit ] ) ; } rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf (
rtb_B_51_1_0 , _rtB -> B_51_5_0 , _rtB -> B_51_945_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
51 , 946 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 51 , 947 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 9 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { ssCallAccelRunBlock ( S , 51 , 949 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 51 , 950 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 51 , 951 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 51 , 952 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 51 , 953 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 51 , 954 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
B_51_955_0 = _rtP -> P_337 * _rtB -> B_51_119_0 ; isHit = ssIsSampleHit ( S ,
1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 51 , 956 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 51 , 957 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_51_958_0 = ( _rtB -> B_51_955_0 >= _rtB
-> B_51_25_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) &&
_rtB -> B_51_958_0 ) { ssSetStopRequested ( S , 1 ) ; } isHit = ssIsSampleHit
( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_960_0 = _rtDW ->
Delay_DSTATE [ 0 ] ; _rtB -> B_51_961_0 = _rtDW -> Delay1_DSTATE [ 0 ] ; _rtB
-> B_51_962_0 = _rtDW -> Delay2_DSTATE [ 0 ] ; _rtB -> B_51_963_0 = _rtDW ->
Delay3_DSTATE [ 0 ] ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { rtb_B_51_84_0 = _rtP -> P_35 * _rtB -> B_51_960_0 - _rtB -> B_45_0_0 ; if
( rtb_B_51_84_0 > _rtP -> P_36 ) { _rtB -> B_45_2_0 = rtb_B_51_84_0 ; } else
{ _rtB -> B_45_2_0 = _rtB -> B_45_1_0 ; } ssCallAccelRunBlock ( S , 45 , 3 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_45_6_0 = ( _rtP -> P_37 * _rtB ->
B_51_961_0 - _rtB -> B_45_2_0_d ) * _rtP -> P_38 ; ssCallAccelRunBlock ( S ,
45 , 7 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 45 , 8 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_45_11_0 = ( _rtP -> P_39 * _rtB ->
B_51_962_0 - _rtB -> B_45_3_0 ) * _rtP -> P_40 ; ssCallAccelRunBlock ( S , 45
, 12 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_45_15_0 = ( _rtP -> P_41 * _rtB ->
B_51_963_0 - _rtB -> B_45_4_0 ) * _rtP -> P_42 ; ssCallAccelRunBlock ( S , 45
, 16 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_51_965_0 = _rtB -> B_45_2_0 ; if (
_rtB -> B_51_965_0 > _rtP -> P_342 ) { rtb_B_51_38_0 = _rtP -> P_342 ; } else
if ( _rtB -> B_51_965_0 < _rtP -> P_343 ) { rtb_B_51_38_0 = _rtP -> P_343 ; }
else { rtb_B_51_38_0 = _rtB -> B_51_965_0 ; } _rtB -> B_51_968_0 = _rtP ->
P_344 * rtb_B_51_38_0 + 1.0 ; { if ( _rtDW ->
TAQSigLogging_InsertedFor_J_at_outport_0_PWORK . AQHandles && ssGetLogOutput
( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_J_at_outport_0_PWORK . AQHandles , ssGetTaskTime (
S , 1 ) , ( char * ) & _rtB -> B_51_108_0 + 0 ) ; } } { if ( _rtDW ->
TAQSigLogging_InsertedFor_MATLABFunction_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_MATLABFunction_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_10_0_1 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_MATLABFunction_at_outport_1_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_MATLABFunction_at_outport_1_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_10_0_2 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_RPM_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_RPM_at_outport_0_PWORK . AQHandles , ssGetTaskTime
( S , 1 ) , ( char * ) & _rtB -> B_51_105_0 + 0 ) ; } } ssCallAccelRunBlock (
S , 51 , 973 , SS_CALL_MDL_OUTPUTS ) ; { if ( _rtDW ->
TAQSigLogging_InsertedFor_Fase_Ato_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Fase_Ato_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_147_0 + 0 ) ; } }
B_51_919_0 [ 0 ] = _rtB -> B_51_564_0 ; B_51_919_0 [ 1 ] = _rtB -> B_13_0_2 ;
B_51_919_0 [ 2 ] = _rtB -> B_51_614_0 [ 2 ] ; { if ( _rtDW ->
TAQSigLogging_InsertedFor_Subsystem1_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Subsystem1_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & B_51_919_0 [ 0 ] + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_Subsystem1_at_outport_1_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Subsystem1_at_outport_1_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_939_0 [ 0 ] + 0 ) ; } }
B_51_919_0 [ 0 ] = _rtB -> B_51_622_0 ; B_51_919_0 [ 1 ] = _rtB -> B_15_0_2 ;
B_51_919_0 [ 2 ] = _rtB -> B_51_672_0 [ 2 ] ; { if ( _rtDW ->
TAQSigLogging_InsertedFor_Subsystem2_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Subsystem2_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & B_51_919_0 [ 0 ] + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_Subsystem2_at_outport_1_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Subsystem2_at_outport_1_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_941_0 [ 0 ] + 0 ) ; } }
B_51_919_0 [ 0 ] = _rtB -> B_51_506_0 ; B_51_919_0 [ 1 ] = _rtB -> B_11_0_2 ;
B_51_919_0 [ 2 ] = _rtB -> B_51_556_0 [ 2 ] ; { if ( _rtDW ->
TAQSigLogging_InsertedFor_Subsystem_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Subsystem_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & B_51_919_0 [ 0 ] + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_Subsystem_at_outport_1_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Subsystem_at_outport_1_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_937_0 [ 0 ] + 0 ) ; } } {
if ( _rtDW -> TAQSigLogging_InsertedFor_modoautopilota_at_outport_0_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_modoautopilota_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_117_0 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_selector_AL_at_outport_0_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_selector_AL_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_499_0 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_Integrator1_at_outport_0_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Integrator1_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_251_0 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_Integrator_at_outport_0_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Integrator_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_249_0 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_Sum2_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Sum2_at_outport_0_PWORK . AQHandles , ssGetTaskTime
( S , 1 ) , ( char * ) & _rtB -> B_51_256_0 + 0 ) ; } } { if ( _rtDW ->
TAQSigLogging_InsertedFor_hkmmolla_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_hkmmolla_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_255_0 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_vcmdsmorzamento_at_outport_0_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_vcmdsmorzamento_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_250_0 + 0 ) ; } } }
rtb_B_51_12_0 [ 0 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 1 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) ; rtb_B_51_12_0 [ 2 ] = muDoubleScalarCos ( _rtB -> B_51_0_0
[ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos (
_rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 3 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 4 ] = muDoubleScalarSin ( _rtB -> B_51_0_0
[ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin (
_rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 5 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 6 ] = _rtP -> P_345 * muDoubleScalarSin (
_rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_12_0 [ 7 ] = muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) ;
rtb_B_51_12_0 [ 8 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ; rtb_B_51_38_0 = ( _rtB ->
B_51_126_0 [ 1 ] * _rtB -> B_51_945_0 [ 2 ] - _rtB -> B_51_126_0 [ 2 ] * _rtB
-> B_51_945_0 [ 1 ] ) + _rtB -> B_51_683_0 [ 0 ] ; rtb_B_51_42_0 = ( _rtB ->
B_51_126_0 [ 2 ] * _rtB -> B_51_945_0 [ 0 ] - _rtB -> B_51_126_0 [ 0 ] * _rtB
-> B_51_945_0 [ 2 ] ) + _rtB -> B_51_683_0 [ 1 ] ; rtb_B_51_39_0 = ( _rtB ->
B_51_126_0 [ 0 ] * _rtB -> B_51_945_0 [ 1 ] - _rtB -> B_51_126_0 [ 1 ] * _rtB
-> B_51_945_0 [ 0 ] ) + _rtB -> B_51_683_0 [ 2 ] ; for ( isHit = 0 ; isHit <
3 ; isHit ++ ) { rtb_B_51_1_0 [ isHit ] = rtb_B_51_12_0 [ 3 * isHit + 2 ] *
rtb_B_51_39_0 + ( rtb_B_51_12_0 [ 3 * isHit + 1 ] * rtb_B_51_42_0 +
rtb_B_51_12_0 [ 3 * isHit ] * rtb_B_51_38_0 ) ; } _rtB -> B_51_1044_0 =
rtb_B_51_1_0 [ 2 ] - _rtB -> B_51_260_0 / _rtB -> B_51_69_0_p ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_Sum1_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Sum1_at_outport_0_PWORK . AQHandles , ssGetTaskTime
( S , 1 ) , ( char * ) & _rtB -> B_51_114_0 [ 0 ] + 0 ) ; } } { if ( _rtDW ->
TAQSigLogging_InsertedFor_hkmmolla_at_outport_0_PWORK_o . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_hkmmolla_at_outport_0_PWORK_o . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_371_0 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_vcmdsmorzamento_at_outport_0_PWORK_f .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_vcmdsmorzamento_at_outport_0_PWORK_f . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_366_0 + 0 ) ; } } }
rtb_B_51_12_0 [ 0 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 1 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) ; rtb_B_51_12_0 [ 2 ] = muDoubleScalarCos ( _rtB -> B_51_0_0
[ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos (
_rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 3 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 4 ] = muDoubleScalarSin ( _rtB -> B_51_0_0
[ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin (
_rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 5 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 6 ] = _rtP -> P_346 * muDoubleScalarSin (
_rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_12_0 [ 7 ] = muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) ;
rtb_B_51_12_0 [ 8 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ; rtb_B_51_38_0 = ( _rtB ->
B_51_70_0 [ 1 ] * _rtB -> B_51_945_0 [ 2 ] - _rtB -> B_51_70_0 [ 2 ] * _rtB
-> B_51_945_0 [ 1 ] ) + _rtB -> B_51_683_0 [ 0 ] ; rtb_B_51_42_0 = ( _rtB ->
B_51_70_0 [ 2 ] * _rtB -> B_51_945_0 [ 0 ] - _rtB -> B_51_70_0 [ 0 ] * _rtB
-> B_51_945_0 [ 2 ] ) + _rtB -> B_51_683_0 [ 1 ] ; rtb_B_51_39_0 = ( _rtB ->
B_51_70_0 [ 0 ] * _rtB -> B_51_945_0 [ 1 ] - _rtB -> B_51_70_0 [ 1 ] * _rtB
-> B_51_945_0 [ 0 ] ) + _rtB -> B_51_683_0 [ 2 ] ; for ( isHit = 0 ; isHit <
3 ; isHit ++ ) { rtb_B_51_1_0 [ isHit ] = rtb_B_51_12_0 [ 3 * isHit + 2 ] *
rtb_B_51_39_0 + ( rtb_B_51_12_0 [ 3 * isHit + 1 ] * rtb_B_51_42_0 +
rtb_B_51_12_0 [ 3 * isHit ] * rtb_B_51_38_0 ) ; } _rtB -> B_51_1101_0 =
rtb_B_51_1_0 [ 2 ] - _rtB -> B_51_376_0 / _rtB -> B_51_69_0_p ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_hknmolla_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_hknmolla_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_487_0 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_vcndsmorzamento_at_outport_0_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_vcndsmorzamento_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_51_482_0 + 0 ) ; } } }
rtb_B_51_12_0 [ 0 ] = muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 1 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 0 ] ) ; rtb_B_51_12_0 [ 2 ] = muDoubleScalarCos ( _rtB -> B_51_0_0
[ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarCos (
_rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 3 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 4 ] = muDoubleScalarSin ( _rtB -> B_51_0_0
[ 0 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 1 ] ) * muDoubleScalarSin (
_rtB -> B_51_0_0 [ 2 ] ) + muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 5 ] =
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 1 ] ) * muDoubleScalarSin ( _rtB -> B_51_0_0 [ 2 ] ) -
muDoubleScalarSin ( _rtB -> B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB ->
B_51_0_0 [ 2 ] ) ; rtb_B_51_12_0 [ 6 ] = _rtP -> P_347 * muDoubleScalarSin (
_rtB -> B_51_0_0 [ 1 ] ) ; rtb_B_51_12_0 [ 7 ] = muDoubleScalarSin ( _rtB ->
B_51_0_0 [ 0 ] ) * muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) ;
rtb_B_51_12_0 [ 8 ] = muDoubleScalarCos ( _rtB -> B_51_0_0 [ 1 ] ) *
muDoubleScalarCos ( _rtB -> B_51_0_0 [ 0 ] ) ; rtb_B_51_38_0 = ( _rtB ->
B_51_71_0 [ 1 ] * _rtB -> B_51_945_0 [ 2 ] - _rtB -> B_51_71_0 [ 2 ] * _rtB
-> B_51_945_0 [ 1 ] ) + _rtB -> B_51_683_0 [ 0 ] ; rtb_B_51_42_0 = ( _rtB ->
B_51_71_0 [ 2 ] * _rtB -> B_51_945_0 [ 0 ] - _rtB -> B_51_71_0 [ 0 ] * _rtB
-> B_51_945_0 [ 2 ] ) + _rtB -> B_51_683_0 [ 1 ] ; rtb_B_51_39_0 = ( _rtB ->
B_51_71_0 [ 0 ] * _rtB -> B_51_945_0 [ 1 ] - _rtB -> B_51_71_0 [ 1 ] * _rtB
-> B_51_945_0 [ 0 ] ) + _rtB -> B_51_683_0 [ 2 ] ; for ( isHit = 0 ; isHit <
3 ; isHit ++ ) { rtb_B_51_1_0 [ isHit ] = rtb_B_51_12_0 [ 3 * isHit + 2 ] *
rtb_B_51_39_0 + ( rtb_B_51_12_0 [ 3 * isHit + 1 ] * rtb_B_51_42_0 +
rtb_B_51_12_0 [ 3 * isHit ] * rtb_B_51_38_0 ) ; } _rtB -> B_51_1157_0 =
rtb_B_51_1_0 [ 2 ] - _rtB -> B_51_492_0 / _rtB -> B_51_68_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
51 , 1158 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsMajorTimeStep ( S ) != 0 ) { if
( _rtB -> B_51_82_0_f > 0.0 ) { if ( ! _rtDW -> Hpgw_MODE ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtX -> pgw_p_CSTATE [ 0
] = _rtP -> P_5 ; _rtX -> pgw_p_CSTATE [ 1 ] = _rtP -> P_5 ; _rtDW ->
Hpgw_MODE = true ; } } else { if ( _rtDW -> Hpgw_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB -> B_22_7_0 [ 0 ] =
_rtP -> P_4 ; _rtB -> B_22_7_0 [ 1 ] = _rtP -> P_4 ; _rtDW -> Hpgw_MODE =
false ; } } } } if ( _rtDW -> Hpgw_MODE ) { rtb_B_51_42_0 = 0.8 /
rtb_B_51_37_0 ; if ( rtb_B_51_42_0 < 0.0 ) { rtb_B_51_42_0 = -
muDoubleScalarSqrt ( - rtb_B_51_42_0 ) ; } else { rtb_B_51_42_0 =
muDoubleScalarSqrt ( rtb_B_51_42_0 ) ; } _rtB -> B_22_7_0 [ 0 ] = _rtB ->
B_51_87_0 * _rtX -> pgw_p_CSTATE [ 0 ] ; _rtB -> B_22_7_0 [ 1 ] =
rtb_B_51_44_0 * _rtX -> pgw_p_CSTATE [ 1 ] ; rtb_B_51_44_0 = rtb_B_51_37_0 *
_rtB -> B_22_3_0 ; if ( ( frac [ 0 ] < 0.0 ) && ( _rtB -> B_22_0_0 >
muDoubleScalarFloor ( _rtB -> B_22_0_0 ) ) ) { rtb_B_51_39_0 = -
muDoubleScalarPower ( - frac [ 0 ] , _rtB -> B_22_0_0 ) ; } else {
rtb_B_51_39_0 = muDoubleScalarPower ( frac [ 0 ] , _rtB -> B_22_0_0 ) ; }
_rtB -> B_22_9_0 [ 0 ] = ( rtb_B_51_42_0 / rtb_B_51_39_0 * _rtB -> B_22_4_0 *
_rtB -> B_51_46_0 [ 3 ] - _rtX -> pgw_p_CSTATE [ 0 ] ) * rtb_B_51_44_0 ; if (
( frac [ 1 ] < 0.0 ) && ( _rtB -> B_22_0_0 > muDoubleScalarFloor ( _rtB ->
B_22_0_0 ) ) ) { rtb_B_51_39_0 = - muDoubleScalarPower ( - frac [ 1 ] , _rtB
-> B_22_0_0 ) ; } else { rtb_B_51_39_0 = muDoubleScalarPower ( frac [ 1 ] ,
_rtB -> B_22_0_0 ) ; } _rtB -> B_22_9_0 [ 1 ] = ( rtb_B_51_42_0 /
rtb_B_51_39_0 * _rtB -> B_22_4_0 * _rtB -> B_51_46_0 [ 3 ] - _rtX ->
pgw_p_CSTATE [ 1 ] ) * rtb_B_51_44_0 ; if ( ssIsMajorTimeStep ( S ) != 0 ) {
srUpdateBC ( _rtDW -> Hpgw_SubsysRanBC ) ; } } isHit = ssIsSampleHit ( S , 1
, 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S ) != 0 ) ) { if ( _rtB
-> B_51_83_0 > 0.0 ) { if ( ! _rtDW -> Hqgw_MODE ) { if ( ssGetTaskTime ( S ,
1 ) != ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S )
; } _rtX -> qgw_p_CSTATE [ 0 ] = _rtP -> P_10 ; _rtX -> qgw_p_CSTATE [ 1 ] =
_rtP -> P_10 ; _rtDW -> Hqgw_MODE = true ; } } else { if ( _rtDW -> Hqgw_MODE
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB -> B_23_5_0 [ 0 ]
= _rtP -> P_9 ; _rtB -> B_23_5_0 [ 1 ] = _rtP -> P_9 ; _rtDW -> Hqgw_MODE =
false ; } } } if ( _rtDW -> Hqgw_MODE ) { rtb_B_51_44_0 = _rtP -> P_11 *
rtb_B_51_37_0 ; _rtB -> B_23_4_0 [ 0 ] = ( _rtB -> B_27_9_0 [ 0 ] /
rtb_B_51_37_0 - _rtX -> qgw_p_CSTATE [ 0 ] ) * ( rtb_B_51_44_0 / _rtB ->
B_51_89_0 ) ; _rtB -> B_23_5_0 [ 0 ] = - _rtB -> B_23_4_0 [ 0 ] ; _rtB ->
B_23_4_0 [ 1 ] = ( _rtB -> B_27_9_0 [ 1 ] / rtb_B_51_37_0 - _rtX ->
qgw_p_CSTATE [ 1 ] ) * ( rtb_B_51_44_0 / _rtB -> B_51_89_0 ) ; _rtB ->
B_23_5_0 [ 1 ] = - _rtB -> B_23_4_0 [ 1 ] ; if ( ssIsMajorTimeStep ( S ) != 0
) { srUpdateBC ( _rtDW -> Hqgw_SubsysRanBC ) ; } } isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S ) != 0 ) ) { if (
_rtB -> B_51_84_0 > 0.0 ) { if ( ! _rtDW -> Hrgw_MODE ) { if ( ssGetTaskTime
( S , 1 ) != ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep
( S ) ; } _rtX -> rgw_p_CSTATE [ 0 ] = _rtP -> P_13 ; _rtX -> rgw_p_CSTATE [
1 ] = _rtP -> P_13 ; _rtDW -> Hrgw_MODE = true ; } } else { if ( _rtDW ->
Hrgw_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB ->
B_24_4_0 [ 0 ] = _rtP -> P_12 ; _rtB -> B_24_4_0 [ 1 ] = _rtP -> P_12 ; _rtDW
-> Hrgw_MODE = false ; } } } if ( _rtDW -> Hrgw_MODE ) { rtb_B_51_44_0 = _rtP
-> P_14 * rtb_B_51_37_0 ; _rtB -> B_24_4_0 [ 0 ] = ( _rtB -> B_26_12_0 [ 0 ]
/ rtb_B_51_37_0 - _rtX -> rgw_p_CSTATE [ 0 ] ) * ( rtb_B_51_44_0 / _rtB ->
B_51_89_0 ) ; _rtB -> B_24_4_0 [ 1 ] = ( _rtB -> B_26_12_0 [ 1 ] /
rtb_B_51_37_0 - _rtX -> rgw_p_CSTATE [ 1 ] ) * ( rtb_B_51_44_0 / _rtB ->
B_51_89_0 ) ; if ( ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW ->
Hrgw_SubsysRanBC ) ; } } if ( ssIsMajorTimeStep ( S ) != 0 ) { if (
rtb_B_51_18_0 <= 1000.0 ) { rtAction = 0 ; } else if ( rtb_B_51_18_0 >=
2000.0 ) { rtAction = 1 ; } else { rtAction = 2 ; } _rtDW ->
ifHeightMaxlowaltitudeelseifHeightMinisotropicaltitude_ActiveSubsystem_d =
rtAction ; } else { rtAction = _rtDW ->
ifHeightMaxlowaltitudeelseifHeightMinisotropicaltitude_ActiveSubsystem_d ; }
switch ( rtAction ) { case 0 : muDoubleScalarSinCos ( _rtB -> B_51_81_0 , &
rtb_B_51_18_0 , & rtb_B_51_37_0 ) ; if ( ssIsMajorTimeStep ( S ) != 0 ) {
srUpdateBC ( _rtDW -> Lowaltituderates_SubsysRanBC ) ; } break ; case 1 : if
( ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW ->
MediumHighaltituderates_SubsysRanBC ) ; } break ; case 2 :
muDoubleScalarSinCos ( _rtB -> B_51_81_0 , & rtb_B_51_18_0 , & rtb_B_51_37_0
) ; if ( ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW ->
Interpolaterates_SubsysRanBC ) ; } break ; } isHit = ssIsSampleHit ( S , 1 ,
0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 51 , 1167 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 51 , 1168 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 51 , 1169 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_38_0_0 [ 0 ] = _rtB -> B_51_69_0 [ 0 ] ;
_rtB -> B_38_0_0 [ 3 ] = _rtB -> B_51_125_0 [ 0 ] ; _rtB -> B_38_0_0 [ 1 ] =
_rtB -> B_51_69_0 [ 1 ] ; _rtB -> B_38_0_0 [ 4 ] = _rtB -> B_51_125_0 [ 1 ] ;
_rtB -> B_38_0_0 [ 2 ] = _rtB -> B_51_69_0 [ 2 ] ; _rtB -> B_38_0_0 [ 5 ] =
_rtB -> B_51_125_0 [ 2 ] ; ssCallAccelRunBlock ( S , 38 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; rtb_B_51_18_0 = muDoubleScalarSin (
0.017453292519943295 * _rtB -> B_51_703_0 ) ; rtb_B_51_18_0 =
muDoubleScalarSqrt ( _rtB -> B_51_153_0 * _rtB -> B_51_153_0 / (
rtb_B_51_18_0 * rtb_B_51_18_0 * _rtB -> B_51_154_0 + _rtB -> B_51_148_0_d ) )
; _rtB -> B_51_1183_0 [ 0 ] = _rtB -> B_51_690_0 [ 0 ] / ( rtb_B_51_18_0 +
_rtB -> B_51_697_0 [ 2 ] ) ; _rtB -> B_51_1183_0 [ 1 ] = _rtB -> B_51_690_0 [
1 ] / ( rtb_B_51_18_0 + _rtB -> B_51_697_0 [ 2 ] ) / muDoubleScalarCos ( _rtB
-> B_51_703_0 ) ; _rtB -> B_51_1183_0 [ 2 ] = _rtP -> P_348 * _rtB ->
B_51_690_0 [ 2 ] ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_51_1184_0 = _rtP -> P_349 * _rtB -> B_45_6_0 ; } _rtB ->
B_51_1185_0 = _rtP -> P_350 * _rtB -> B_51_92_0 ; isHit = ssIsSampleHit ( S ,
1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 51 , 1186 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_51_1187_0 = _rtP -> P_351 * _rtB ->
B_45_11_0 ; } _rtB -> B_51_1188_0 = _rtP -> P_352 * _rtB -> B_51_85_0 ; isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
51 , 1189 , SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_51_1190_0 = _rtP -> P_353 *
_rtB -> B_51_82_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_51_1191_0 = _rtP -> P_354 * _rtB -> B_45_15_0 ; ssCallAccelRunBlock
( S , 51 , 1192 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 51 , 1193
, SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 51 , 1194 ,
SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_51_1196_0 = _rtDW -> NextOutput_p2 ; } _rtB -> B_51_1197_0 =
_rtB -> B_51_1196_0 - _rtP -> P_355 * rtb_B_51_81_0 ; isHit = ssIsSampleHit (
S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_1199_0 = _rtDW ->
NextOutput_p1 ; } _rtB -> B_51_1200_0 = _rtB -> B_51_1199_0 - _rtP -> P_359 *
rtb_B_51_801_0 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_51_1202_0 = _rtDW -> NextOutput_me ; } _rtB -> B_51_1203_0 = _rtB
-> B_51_1202_0 - _rtP -> P_363 * rtb_B_51_797_0 ; isHit = ssIsSampleHit ( S ,
3 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_1206_0 = _rtDW -> NextOutput_bl ;
} _rtB -> B_51_1208_0 = B_51_765_0 * _rtB -> B_51_189_0 * _rtB -> B_51_1206_0
- _rtP -> P_367 * rtb_B_51_91_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { ssCallAccelRunBlock ( S , 51 , 1209 , SS_CALL_MDL_OUTPUTS ) ;
} isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_51_1212_0 = _rtDW -> NextOutput_n ; } _rtB -> B_51_1214_0 = B_51_774_0 *
_rtB -> B_51_190_0 * _rtB -> B_51_1212_0 - _rtP -> P_371 * _rtB -> B_51_775_0
; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_51_1216_0 = _rtB -> B_51_793_0 * muDoubleScalarCos ( _rtB -> B_51_803_0 ) ;
isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_1217_0
= _rtB -> B_51_1216_0 ; _rtB -> B_51_1218_0 = _rtB -> B_51_808_0 ; } } isHit
= ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
51 , 1219 , SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_51_1223_0 = muDoubleScalarSqrt ( _rtB ->
B_51_812_0 * _rtB -> B_51_812_0 + _rtB -> B_51_808_0 * _rtB -> B_51_808_0 ) ;
ssCallAccelRunBlock ( S , 51 , 1224 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 51 , 1225 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 51 , 1226 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 51 , 1227 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_51_1229_0 = _rtB -> B_51_793_0 * muDoubleScalarSin ( _rtB -> B_51_803_0 ) ;
ssCallAccelRunBlock ( S , 51 , 1230 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 51 , 1231 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 51 , 1232 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_51_1233_0 = _rtDW -> NextOutput_a1 ; } _rtB -> B_51_1234_0 = _rtB ->
B_51_1233_0 + _rtB -> B_51_728_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> RateTransition24_Buffer = _rtB -> B_51_1234_0 ; } } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_1235_0 = _rtDW
-> RateTransition24_Buffer ; _rtB -> B_51_1236_0 = _rtDW -> NextOutput_mr ; }
_rtB -> B_51_1237_0 = _rtB -> B_51_1236_0 + _rtB -> B_51_35_0 [ 2 ] ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { isHit = ssIsSampleHit ( S ,
2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> RateTransition25_Buffer = _rtB ->
B_51_1237_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_51_1238_0 = _rtDW -> RateTransition25_Buffer ; _rtB -> B_51_1239_0
= _rtDW -> NextOutput_o2 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit
!= 0 ) { isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
RateTransition26_Buffer = _rtB -> B_51_1239_0 + B_51_714_0 ; } } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_51_1241_0 = _rtDW
-> RateTransition26_Buffer ; _rtB -> B_51_1242_0 = _rtDW -> NextOutput_ej ; }
_rtB -> B_51_1243_0 = _rtB -> B_51_1242_0 + _rtB -> B_51_67_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { isHit = ssIsSampleHit ( S ,
2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> RateTransition27_Buffer = _rtB ->
B_51_1243_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_51_1244_0 = _rtDW -> RateTransition27_Buffer ; { if ( _rtDW ->
TAQSigLogging_InsertedFor_RadianstoDegrees_at_outport_0_PWORK_d . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_RadianstoDegrees_at_outport_0_PWORK_d . AQHandles ,
ssGetTaskTime ( S , 2 ) , ( char * ) & B_51_819_0 + 0 ) ; } } }
ssCallAccelRunBlock ( S , 51 , 1246 , SS_CALL_MDL_OUTPUTS ) ;
UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID4 ( SimStruct * S ,
int_T tid ) { B_v2022_Modello_SITL_AENEA_2020b_T * _rtB ;
DW_v2022_Modello_SITL_AENEA_2020b_T * _rtDW ;
P_v2022_Modello_SITL_AENEA_2020b_T * _rtP ; real_T rtb_B_51_2_0 [ 18 ] ;
real_T rtb_B_51_109_1 ; real_T rtb_B_51_98_0 ; int32_T i ; _rtDW = ( (
DW_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( (
P_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_v2022_Modello_SITL_AENEA_2020b_T * ) _ssGetModelBlockIO ( S ) ) ; for ( i =
0 ; i < 3 ; i ++ ) { rtb_B_51_2_0 [ 6 * i ] = _rtP -> P_387 [ 3 * i ] ;
rtb_B_51_2_0 [ 6 * i + 3 ] = _rtP -> P_388 [ 3 * i ] ; _rtB -> B_51_3_0 [ 3 *
i ] = rtb_B_51_2_0 [ 6 * i ] ; _rtB -> B_51_4_0 [ 3 * i ] = rtb_B_51_2_0 [ 6
* i + 3 ] ; _rtB -> B_51_5_0 [ 3 * i ] = rtb_B_51_2_0 [ 6 * i ] ;
rtb_B_51_2_0 [ 6 * i + 1 ] = _rtP -> P_387 [ 3 * i + 1 ] ; rtb_B_51_2_0 [ 6 *
i + 4 ] = _rtP -> P_388 [ 3 * i + 1 ] ; _rtB -> B_51_3_0 [ 3 * i + 1 ] =
rtb_B_51_2_0 [ 6 * i + 1 ] ; _rtB -> B_51_4_0 [ 3 * i + 1 ] = rtb_B_51_2_0 [
6 * i + 4 ] ; _rtB -> B_51_5_0 [ 3 * i + 1 ] = rtb_B_51_2_0 [ 6 * i + 1 ] ;
rtb_B_51_2_0 [ 6 * i + 2 ] = _rtP -> P_387 [ 3 * i + 2 ] ; rtb_B_51_2_0 [ 6 *
i + 5 ] = _rtP -> P_388 [ 3 * i + 2 ] ; _rtB -> B_51_3_0 [ 3 * i + 2 ] =
rtb_B_51_2_0 [ 6 * i + 2 ] ; _rtB -> B_51_4_0 [ 3 * i + 2 ] = rtb_B_51_2_0 [
6 * i + 5 ] ; _rtB -> B_51_5_0 [ 3 * i + 2 ] = rtb_B_51_2_0 [ 6 * i + 2 ] ; }
_rtB -> B_51_6_0 = _rtP -> P_389 ; _rtB -> B_51_7_0 = _rtP -> P_390 ; _rtB ->
B_51_8_0 = _rtP -> P_391 ; _rtB -> B_51_10_0 = _rtP -> P_392 ; _rtB ->
B_51_12_0 = _rtP -> P_393 ; _rtB -> B_51_13_0_m = _rtP -> P_394 ; _rtB ->
B_51_15_0 = _rtP -> P_395 ; _rtB -> B_51_17_0 = _rtP -> P_396 ; _rtB ->
B_51_19_0 = _rtP -> P_397 ; _rtB -> B_51_21_0 = _rtP -> P_398 ; _rtB ->
B_51_23_0 = _rtP -> P_399 ; _rtB -> B_51_25_0 = _rtP -> P_400 ; _rtB ->
B_51_26_0 = _rtP -> P_401 ; _rtB -> B_51_28_0 = _rtP -> P_403 ; memcpy ( &
_rtB -> B_51_30_0 [ 0 ] , & _rtP -> P_405 [ 0 ] , 126U * sizeof ( real_T ) )
; _rtB -> B_51_32_0 = _rtP -> P_406 ; if ( ( _rtB -> B_51_32_0 < 0.0 ) && (
_rtP -> P_402 > muDoubleScalarFloor ( _rtP -> P_402 ) ) ) { _rtB -> B_51_33_0
= - muDoubleScalarPower ( - _rtB -> B_51_32_0 , _rtP -> P_402 ) ; } else {
_rtB -> B_51_33_0 = muDoubleScalarPower ( _rtB -> B_51_32_0 , _rtP -> P_402 )
; } if ( ( _rtB -> B_51_32_0 < 0.0 ) && ( _rtP -> P_404 > muDoubleScalarFloor
( _rtP -> P_404 ) ) ) { _rtB -> B_51_34_0 = - muDoubleScalarPower ( - _rtB ->
B_51_32_0 , _rtP -> P_404 ) ; } else { _rtB -> B_51_34_0 =
muDoubleScalarPower ( _rtB -> B_51_32_0 , _rtP -> P_404 ) ; } _rtB ->
B_51_35_0_c = _rtP -> P_407 ; _rtB -> B_51_36_0 = _rtP -> P_408 ; _rtB ->
B_51_37_0 = _rtP -> P_409 ; _rtB -> B_51_38_0 = _rtP -> P_410 ; _rtB ->
B_51_39_0 = _rtP -> P_411 ; _rtB -> B_51_40_0 = _rtP -> P_412 ; _rtB ->
B_51_41_0 = _rtP -> P_413 ; _rtB -> B_51_42_0 = _rtP -> P_414 ; _rtB ->
B_51_43_0 = _rtP -> P_415 ; _rtB -> B_51_44_0 = _rtP -> P_416 ; _rtB ->
B_51_45_0 = _rtP -> P_417 ; _rtB -> B_51_46_0_k = _rtP -> P_418 ; _rtB ->
B_51_47_0 = _rtP -> P_419 ; _rtB -> B_51_48_0 = _rtP -> P_420 ; _rtB ->
B_51_49_0 = _rtP -> P_421 ; _rtB -> B_51_50_0 = _rtP -> P_422 ; _rtB ->
B_51_51_0 = _rtP -> P_423 ; _rtB -> B_51_52_0 = _rtP -> P_424 ; _rtB ->
B_51_53_0 = _rtP -> P_425 ; _rtB -> B_51_54_0 = _rtP -> P_426 ; _rtB ->
B_51_55_0 = _rtP -> P_427 ; _rtB -> B_51_56_0 = _rtP -> P_428 ; _rtB ->
B_51_57_0 = _rtP -> P_429 ; _rtB -> B_51_58_0 = _rtP -> P_430 ; _rtB ->
B_51_59_0 = _rtP -> P_431 ; _rtB -> B_51_62_0 = _rtP -> P_433 ; _rtB ->
B_51_65_0 = _rtP -> P_435 ; _rtB -> B_51_60_0_c [ 0 ] = _rtP -> P_432 [ 0 ] ;
_rtB -> B_51_63_0_b [ 0 ] = _rtP -> P_434 [ 0 ] ; _rtB -> B_51_66_0 [ 0 ] =
_rtP -> P_436 [ 0 ] ; _rtB -> B_51_60_0_c [ 1 ] = _rtP -> P_432 [ 1 ] ; _rtB
-> B_51_63_0_b [ 1 ] = _rtP -> P_434 [ 1 ] ; _rtB -> B_51_66_0 [ 1 ] = _rtP
-> P_436 [ 1 ] ; _rtB -> B_51_60_0_c [ 2 ] = _rtP -> P_432 [ 2 ] ; _rtB ->
B_51_63_0_b [ 2 ] = _rtP -> P_434 [ 2 ] ; _rtB -> B_51_66_0 [ 2 ] = _rtP ->
P_436 [ 2 ] ; _rtB -> B_51_60_0_c [ 3 ] = _rtP -> P_432 [ 3 ] ; _rtB ->
B_51_63_0_b [ 3 ] = _rtP -> P_434 [ 3 ] ; _rtB -> B_51_66_0 [ 3 ] = _rtP ->
P_436 [ 3 ] ; _rtB -> B_51_68_0 = _rtP -> P_437 ; _rtB -> B_51_69_0_p = _rtP
-> P_438 ; _rtB -> B_51_73_0 = _rtP -> P_441 ; _rtB -> B_51_70_0 [ 0 ] = _rtP
-> P_439 [ 0 ] ; _rtB -> B_51_71_0 [ 0 ] = _rtP -> P_440 [ 0 ] ; _rtB ->
B_51_74_0 [ 0 ] = _rtP -> P_442 [ 0 ] ; _rtB -> B_51_70_0 [ 1 ] = _rtP ->
P_439 [ 1 ] ; _rtB -> B_51_71_0 [ 1 ] = _rtP -> P_440 [ 1 ] ; _rtB ->
B_51_74_0 [ 1 ] = _rtP -> P_442 [ 1 ] ; _rtB -> B_51_70_0 [ 2 ] = _rtP ->
P_439 [ 2 ] ; _rtB -> B_51_71_0 [ 2 ] = _rtP -> P_440 [ 2 ] ; _rtB ->
B_51_74_0 [ 2 ] = _rtP -> P_442 [ 2 ] ; _rtB -> B_51_75_0_c = _rtP -> P_443 ;
_rtB -> B_51_76_0 = _rtP -> P_444 ; _rtB -> B_51_77_0 = _rtP -> P_445 ; _rtB
-> B_51_78_0 = _rtP -> P_446 ; _rtB -> B_51_79_0 = _rtP -> P_447 ; _rtB ->
B_51_81_0 = 0.017453292519943295 * _rtP -> P_448 ; _rtB -> B_51_82_0_f = _rtP
-> P_449 ; _rtB -> B_51_83_0 = _rtP -> P_450 ; _rtB -> B_51_84_0 = _rtP ->
P_451 ; _rtB -> B_51_87_0 = 3.280839895013123 * _rtP -> P_452 * _rtP -> P_453
; _rtB -> B_51_89_0 = 3.280839895013123 * _rtP -> P_454 ; _rtB -> B_22_0_0 =
_rtP -> P_6 ; _rtB -> B_22_3_0 = _rtP -> P_8 / _rtB -> B_51_89_0 ; if ( (
_rtB -> B_22_3_0 < 0.0 ) && ( _rtP -> P_7 > muDoubleScalarFloor ( _rtP -> P_7
) ) ) { _rtB -> B_22_4_0 = - muDoubleScalarPower ( - _rtB -> B_22_3_0 , _rtP
-> P_7 ) ; } else { _rtB -> B_22_4_0 = muDoubleScalarPower ( _rtB -> B_22_3_0
, _rtP -> P_7 ) ; } if ( ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW
-> Hpgw_SubsysRanBC ) ; } _rtB -> B_51_93_0 = _rtP -> P_455 ; _rtB ->
B_51_95_0 = 3.280839895013123 * _rtP -> P_456 ; _rtB -> B_27_1_0 =
muDoubleScalarSqrt ( _rtP -> P_27 ) ; if ( ssIsMajorTimeStep ( S ) != 0 ) {
srUpdateBC ( _rtDW -> Hwgws_SubsysRanBC ) ; } rtb_B_51_98_0 = _rtP -> P_457 ;
v2022_Modello_SITL_AENEA_2020b_oorCheck ( _rtP -> P_569 , _rtP -> P_457 ,
_rtP -> P_458 [ 0 ] , _rtP -> P_458 [ 6 ] ,
"Simulink:blocks:PreLookupOutofRangeInputWarn_Clip" ,
 "v2022_Modello_SITL_AENEA_2020b/AENEA /AENEA II_SITL1/Velocit\3401/Dryden Wind Turbulence Model  (Continuous (-q +r))/RMS turbulence  intensities/High Altitude Intensity/PreLook-Up Index Search  (prob of exceed)"
, S ) ; _rtB -> B_51_99_0 = plook_bincpa ( rtb_B_51_98_0 , _rtP -> P_458 , 6U
, & _rtB -> B_51_99_1 , & _rtDW -> PreLookUpIndexSearchprobofexceed_DWORK1 )
; rtb_B_51_98_0 = muDoubleScalarSqrt ( _rtP -> P_460 ) ; _rtB -> B_51_106_0_g
[ 0 ] = muDoubleScalarSqrt ( _rtP -> P_459 [ 0 ] ) / rtb_B_51_98_0 ; _rtB ->
B_51_106_0_g [ 1 ] = muDoubleScalarSqrt ( _rtP -> P_459 [ 1 ] ) /
rtb_B_51_98_0 ; _rtB -> B_51_106_0_g [ 2 ] = muDoubleScalarSqrt ( _rtP ->
P_459 [ 2 ] ) / rtb_B_51_98_0 ; _rtB -> B_51_106_0_g [ 3 ] =
muDoubleScalarSqrt ( _rtP -> P_459 [ 3 ] ) / rtb_B_51_98_0 ;
muDoubleScalarSinCos ( 0.017453292519943295 * _rtP -> P_461 , & rtb_B_51_98_0
, & rtb_B_51_109_1 ) ; _rtB -> B_51_111_0_g [ 0 ] = _rtP -> P_463 *
rtb_B_51_109_1 ; _rtB -> B_51_111_0_g [ 1 ] = _rtP -> P_463 * rtb_B_51_98_0 ;
_rtB -> B_51_111_0_g [ 2 ] = _rtP -> P_463 * _rtP -> P_462 ; _rtB ->
B_51_113_0 = muDoubleScalarLog ( _rtP -> P_464 ) ; ssCallAccelRunBlock ( S ,
51 , 1342 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_51_116_0_n = _rtP -> P_466 ;
_rtB -> B_51_117_0_p = _rtP -> P_467 ; _rtB -> B_51_118_0_l = _rtP -> P_468 ;
_rtB -> B_51_119_0_j = _rtP -> P_469 ; _rtB -> B_51_120_0_d = _rtP -> P_470 ;
_rtB -> B_51_121_0 = _rtP -> P_471 ; _rtB -> B_51_122_0 = _rtP -> P_472 ;
_rtB -> B_51_123_0 = _rtP -> P_473 ; _rtB -> B_51_124_0 = _rtP -> P_474 ;
_rtB -> B_51_127_0 = _rtP -> P_477 ; _rtB -> B_51_128_0 = _rtP -> P_478 ;
_rtB -> B_51_129_0 = _rtP -> P_479 ; _rtB -> B_51_130_0 = _rtP -> P_480 ;
_rtB -> B_51_131_0 = _rtP -> P_481 ; _rtB -> B_51_132_0 = _rtP -> P_482 ;
_rtB -> B_51_133_0 = _rtP -> P_483 ; _rtB -> B_51_134_0 = _rtP -> P_484 ;
_rtB -> B_51_136_0 = _rtP -> P_486 ; _rtB -> B_51_137_0 = _rtP -> P_487 ;
_rtB -> B_51_138_0 = _rtP -> P_488 ; _rtB -> B_51_139_0 = _rtP -> P_489 ;
_rtB -> B_51_140_0 = _rtP -> P_490 ; _rtB -> B_51_114_0_m [ 0 ] = _rtP ->
P_465 [ 0 ] ; _rtB -> B_51_125_0 [ 0 ] = _rtP -> P_475 [ 0 ] ; _rtB ->
B_51_126_0 [ 0 ] = _rtP -> P_476 [ 0 ] ; _rtB -> B_51_135_0 [ 0 ] = _rtP ->
P_485 [ 0 ] ; _rtB -> B_51_141_0 [ 0 ] = _rtP -> P_491 [ 0 ] ; _rtB ->
B_51_114_0_m [ 1 ] = _rtP -> P_465 [ 1 ] ; _rtB -> B_51_125_0 [ 1 ] = _rtP ->
P_475 [ 1 ] ; _rtB -> B_51_126_0 [ 1 ] = _rtP -> P_476 [ 1 ] ; _rtB ->
B_51_135_0 [ 1 ] = _rtP -> P_485 [ 1 ] ; _rtB -> B_51_141_0 [ 1 ] = _rtP ->
P_491 [ 1 ] ; _rtB -> B_51_114_0_m [ 2 ] = _rtP -> P_465 [ 2 ] ; _rtB ->
B_51_125_0 [ 2 ] = _rtP -> P_475 [ 2 ] ; _rtB -> B_51_126_0 [ 2 ] = _rtP ->
P_476 [ 2 ] ; _rtB -> B_51_135_0 [ 2 ] = _rtP -> P_485 [ 2 ] ; _rtB ->
B_51_141_0 [ 2 ] = _rtP -> P_491 [ 2 ] ; _rtB -> B_51_143_0 = _rtP -> P_492 ;
_rtB -> B_51_144_0 = _rtP -> P_493 ; _rtB -> B_51_145_0 = _rtP -> P_494 ;
_rtB -> B_51_146_0_g = _rtP -> P_495 ; _rtB -> B_51_147_0_l = _rtP -> P_496 ;
_rtB -> B_51_148_0_d = _rtP -> P_497 ; rtb_B_51_98_0 = _rtB -> B_51_148_0_d -
_rtP -> P_498 ; _rtB -> B_51_153_0 = _rtP -> P_499 ; _rtB -> B_51_154_0 =
_rtB -> B_51_148_0_d / ( rtb_B_51_98_0 * rtb_B_51_98_0 ) - _rtB ->
B_51_148_0_d ; if ( _rtP -> P_502 > _rtP -> P_503 ) { _rtB -> B_51_158_0 =
_rtP -> P_500 ; } else { _rtB -> B_51_158_0 = _rtP -> P_501 ; } _rtB ->
B_51_159_0 = _rtP -> P_504 ; _rtB -> B_51_160_0 = _rtP -> P_505 ; _rtB ->
B_51_161_0 = _rtP -> P_506 ; _rtB -> B_51_162_0 = _rtP -> P_507 ; _rtB ->
B_51_163_0 = _rtP -> P_508 ; _rtB -> B_51_164_0 = _rtP -> P_509 ; _rtB ->
B_51_165_0 = _rtP -> P_510 ; _rtB -> B_51_166_0 = _rtP -> P_511 ; _rtB ->
B_51_167_0 = _rtP -> P_512 ; _rtB -> B_51_168_0 = _rtP -> P_513 ; _rtB ->
B_51_169_0 = _rtP -> P_514 ; _rtB -> B_51_170_0 = _rtP -> P_515 ; _rtB ->
B_51_171_0 = _rtP -> P_516 ; _rtB -> B_51_172_0 = _rtP -> P_517 ; _rtB ->
B_51_173_0 = _rtP -> P_518 ; _rtB -> B_51_174_0 = _rtP -> P_519 ; _rtB ->
B_51_175_0 = _rtP -> P_520 ; _rtB -> B_51_177_0 = _rtP -> P_522 ; _rtB ->
B_51_178_0 = _rtP -> P_523 ; memcpy ( & _rtB -> B_51_179_0 [ 0 ] , & _rtP ->
P_524 [ 0 ] , 14U * sizeof ( real_T ) ) ; memcpy ( & _rtB -> B_51_180_0 [ 0 ]
, & _rtP -> P_525 [ 0 ] , 24U * sizeof ( real_T ) ) ; memcpy ( & _rtB ->
B_51_181_0 [ 0 ] , & _rtP -> P_526 [ 0 ] , 28U * sizeof ( real_T ) ) ; _rtB
-> B_51_182_0 = _rtP -> P_527 * _rtP -> P_521 ; _rtB -> B_45_0_0 = _rtP ->
P_43 ; _rtB -> B_45_1_0 = _rtP -> P_44 ; _rtB -> B_45_2_0_d = _rtP -> P_45 ;
_rtB -> B_45_3_0 = _rtP -> P_46 ; _rtB -> B_45_4_0 = _rtP -> P_47 ; _rtB ->
B_51_184_0 = _rtP -> P_528 ; _rtB -> B_51_185_0 = _rtP -> P_529 ; _rtB ->
B_51_188_0 = _rtP -> P_530 ; _rtB -> B_51_189_0 = _rtP -> P_531 ; _rtB ->
B_51_190_0 = _rtP -> P_532 ; _rtB -> B_51_191_0 = _rtP -> P_533 ; _rtB ->
B_51_193_0 = _rtP -> P_535 * _rtP -> P_534 ; _rtB -> B_51_194_0 = _rtP ->
P_536 ; _rtB -> B_51_195_0 = _rtP -> P_537 ; ssCallAccelRunBlock ( S , 51 ,
914 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_33_0_0 = _rtP -> P_32 ; _rtB ->
B_33_2_0 = _rtP -> P_33 - _rtB -> B_33_0_0 ; _rtB -> B_30_0_0 = _rtP -> P_29
; _rtB -> B_30_2_0 = _rtP -> P_30 - _rtB -> B_30_0_0 ; UNUSED_PARAMETER ( tid
) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) {
B_v2022_Modello_SITL_AENEA_2020b_T * _rtB ;
DW_v2022_Modello_SITL_AENEA_2020b_T * _rtDW ;
P_v2022_Modello_SITL_AENEA_2020b_T * _rtP ; int32_T isHit ; _rtDW = ( (
DW_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( (
P_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_v2022_Modello_SITL_AENEA_2020b_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput [ 0 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed [ 0 ] ) * _rtP -> P_65 +
_rtP -> P_64 ; _rtDW -> NextOutput [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( &
_rtDW -> RandSeed [ 1 ] ) * _rtP -> P_65 + _rtP -> P_64 ; _rtDW -> NextOutput
[ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed [ 2 ] ) * _rtP ->
P_65 + _rtP -> P_64 ; _rtDW -> NextOutput [ 3 ] = rt_nrand_Upu32_Yd_f_pw_snf
( & _rtDW -> RandSeed [ 3 ] ) * _rtP -> P_65 + _rtP -> P_64 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> UnitDelay_DSTATE =
_rtB -> B_51_968_0 ; _rtDW -> Memory_PreviousInput = _rtB -> B_51_914_6 [ 0 ]
; _rtDW -> Memory1_PreviousInput = _rtB -> B_51_914_6 [ 1 ] ; } _rtDW ->
Integrator_IWORK = 0 ; _rtDW -> Integrator1_IWORK = 0 ; _rtDW ->
Integrator_IWORK_d = 0 ; _rtDW -> Integrator1_IWORK_n = 0 ; _rtDW ->
Integrator_IWORK_g = 0 ; _rtDW -> Integrator1_IWORK_f = 0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory2_PreviousInput = _rtB -> B_51_914_6 [ 2 ] ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> Delay_gps_PWORK . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> Delay_gps_PWORK . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; _rtDW -> Delay_gps_IWORK . Head = ( ( _rtDW
-> Delay_gps_IWORK . Head < ( _rtDW -> Delay_gps_IWORK . CircularBufSize - 1
) ) ? ( _rtDW -> Delay_gps_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
Delay_gps_IWORK . Head == _rtDW -> Delay_gps_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_gps_IWORK . CircularBufSize , & _rtDW -> Delay_gps_IWORK . Tail , &
_rtDW -> Delay_gps_IWORK . Head , & _rtDW -> Delay_gps_IWORK . Last , simTime
- _rtP -> P_176 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , &
_rtDW -> Delay_gps_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
Delay_gps_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW -> Delay_gps_IWORK
. Head ] = _rtB -> B_51_703_0 ; } { real_T * * uBuffer = ( real_T * * ) &
_rtDW -> Delay_gps_PWORK_k . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = (
real_T * * ) & _rtDW -> Delay_gps_PWORK_k . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> Delay_gps_IWORK_b . Head = ( ( _rtDW ->
Delay_gps_IWORK_b . Head < ( _rtDW -> Delay_gps_IWORK_b . CircularBufSize - 1
) ) ? ( _rtDW -> Delay_gps_IWORK_b . Head + 1 ) : 0 ) ; if ( _rtDW ->
Delay_gps_IWORK_b . Head == _rtDW -> Delay_gps_IWORK_b . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_gps_IWORK_b . CircularBufSize , & _rtDW -> Delay_gps_IWORK_b . Tail , &
_rtDW -> Delay_gps_IWORK_b . Head , & _rtDW -> Delay_gps_IWORK_b . Last ,
simTime - _rtP -> P_181 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_gps_IWORK_b . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_gps_IWORK_b . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_gps_IWORK_b . Head ] = _rtB -> B_51_707_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> Delay_bmp_PWORK . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> Delay_bmp_PWORK . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; _rtDW -> Delay_bmp_IWORK . Head = ( ( _rtDW
-> Delay_bmp_IWORK . Head < ( _rtDW -> Delay_bmp_IWORK . CircularBufSize - 1
) ) ? ( _rtDW -> Delay_bmp_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
Delay_bmp_IWORK . Head == _rtDW -> Delay_bmp_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_bmp_IWORK . CircularBufSize , & _rtDW -> Delay_bmp_IWORK . Tail , &
_rtDW -> Delay_bmp_IWORK . Head , & _rtDW -> Delay_bmp_IWORK . Last , simTime
- _rtP -> P_186 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , &
_rtDW -> Delay_bmp_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
Delay_bmp_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW -> Delay_bmp_IWORK
. Head ] = _rtB -> B_51_783_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if (
isHit != 0 ) { _rtDW -> NextOutput_l = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW
-> RandSeed_e ) * _rtP -> P_189 + _rtP -> P_188 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> Delay_gps_PWORK_l . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> Delay_gps_PWORK_l . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; _rtDW -> Delay_gps_IWORK_l . Head = ( ( _rtDW
-> Delay_gps_IWORK_l . Head < ( _rtDW -> Delay_gps_IWORK_l . CircularBufSize
- 1 ) ) ? ( _rtDW -> Delay_gps_IWORK_l . Head + 1 ) : 0 ) ; if ( _rtDW ->
Delay_gps_IWORK_l . Head == _rtDW -> Delay_gps_IWORK_l . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_gps_IWORK_l . CircularBufSize , & _rtDW -> Delay_gps_IWORK_l . Tail , &
_rtDW -> Delay_gps_IWORK_l . Head , & _rtDW -> Delay_gps_IWORK_l . Last ,
simTime - _rtP -> P_191 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_gps_IWORK_l . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_gps_IWORK_l . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_gps_IWORK_l . Head ] = _rtB -> B_51_732_0 ; } isHit = ssIsSampleHit ( S
, 3 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_m =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_b ) * _rtP -> P_194 + _rtP
-> P_193 ; _rtDW -> NextOutput_j = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
RandSeed_g ) * _rtP -> P_197 + _rtP -> P_196 ; } isHit = ssIsSampleHit ( S ,
2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_f =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_ec ) * _rtP -> P_201 + _rtP
-> P_200 ; _rtDW -> NextOutput_fh = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
RandSeed_m ) * _rtP -> P_204 + _rtP -> P_203 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> Delay_gps1_PWORK . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> Delay_gps1_PWORK . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; _rtDW -> Delay_gps1_IWORK . Head = ( ( _rtDW
-> Delay_gps1_IWORK . Head < ( _rtDW -> Delay_gps1_IWORK . CircularBufSize -
1 ) ) ? ( _rtDW -> Delay_gps1_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
Delay_gps1_IWORK . Head == _rtDW -> Delay_gps1_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_gps1_IWORK . CircularBufSize , & _rtDW -> Delay_gps1_IWORK . Tail , &
_rtDW -> Delay_gps1_IWORK . Head , & _rtDW -> Delay_gps1_IWORK . Last ,
simTime - _rtP -> P_207 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_gps1_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_gps1_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_gps1_IWORK . Head ] = _rtB -> B_51_691_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> Delay_ahrs1_PWORK . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs1_PWORK . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; _rtDW -> Delay_ahrs1_IWORK . Head = ( ( _rtDW
-> Delay_ahrs1_IWORK . Head < ( _rtDW -> Delay_ahrs1_IWORK . CircularBufSize
- 1 ) ) ? ( _rtDW -> Delay_ahrs1_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
Delay_ahrs1_IWORK . Head == _rtDW -> Delay_ahrs1_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_ahrs1_IWORK . CircularBufSize , & _rtDW -> Delay_ahrs1_IWORK . Tail , &
_rtDW -> Delay_ahrs1_IWORK . Head , & _rtDW -> Delay_ahrs1_IWORK . Last ,
simTime - _rtP -> P_210 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_ahrs1_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_ahrs1_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_ahrs1_IWORK . Head ] = _rtB -> B_51_0_0 [ 0 ] ; } { real_T * * uBuffer
= ( real_T * * ) & _rtDW -> Delay_ahrs2_PWORK . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs2_PWORK . TUbufferPtrs [ 1 ]
; real_T simTime = ssGetT ( S ) ; _rtDW -> Delay_ahrs2_IWORK . Head = ( (
_rtDW -> Delay_ahrs2_IWORK . Head < ( _rtDW -> Delay_ahrs2_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> Delay_ahrs2_IWORK . Head + 1 ) : 0 ) ;
if ( _rtDW -> Delay_ahrs2_IWORK . Head == _rtDW -> Delay_ahrs2_IWORK . Tail )
{ if ( ! v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> Delay_ahrs2_IWORK . CircularBufSize , & _rtDW -> Delay_ahrs2_IWORK .
Tail , & _rtDW -> Delay_ahrs2_IWORK . Head , & _rtDW -> Delay_ahrs2_IWORK .
Last , simTime - _rtP -> P_217 , tBuffer , uBuffer , ( NULL ) , ( boolean_T )
0 , false , & _rtDW -> Delay_ahrs2_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
tBuffer ) [ _rtDW -> Delay_ahrs2_IWORK . Head ] = simTime ; ( * uBuffer ) [
_rtDW -> Delay_ahrs2_IWORK . Head ] = _rtB -> B_51_0_0 [ 1 ] ; } { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs3_PWORK . TUbufferPtrs [ 0 ] ;
real_T * * tBuffer = ( real_T * * ) & _rtDW -> Delay_ahrs3_PWORK .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
Delay_ahrs3_IWORK . Head = ( ( _rtDW -> Delay_ahrs3_IWORK . Head < ( _rtDW ->
Delay_ahrs3_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW -> Delay_ahrs3_IWORK .
Head + 1 ) : 0 ) ; if ( _rtDW -> Delay_ahrs3_IWORK . Head == _rtDW ->
Delay_ahrs3_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_ahrs3_IWORK . CircularBufSize , & _rtDW -> Delay_ahrs3_IWORK . Tail , &
_rtDW -> Delay_ahrs3_IWORK . Head , & _rtDW -> Delay_ahrs3_IWORK . Last ,
simTime - _rtP -> P_224 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_ahrs3_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_ahrs3_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_ahrs3_IWORK . Head ] = _rtB -> B_51_0_0 [ 2 ] ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory2_PreviousInput_k = _rtB
-> B_51_844_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
Delay_ahrs_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) &
_rtDW -> Delay_ahrs_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S
) ; _rtDW -> Delay_ahrs_IWORK . Head = ( ( _rtDW -> Delay_ahrs_IWORK . Head <
( _rtDW -> Delay_ahrs_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
Delay_ahrs_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> Delay_ahrs_IWORK . Head
== _rtDW -> Delay_ahrs_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_ahrs_IWORK . CircularBufSize , & _rtDW -> Delay_ahrs_IWORK . Tail , &
_rtDW -> Delay_ahrs_IWORK . Head , & _rtDW -> Delay_ahrs_IWORK . Last ,
simTime - _rtP -> P_232 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_ahrs_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_ahrs_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_ahrs_IWORK . Head ] = _rtB -> B_51_685_0 [ 0 ] ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_b =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_a ) * _rtP -> P_235 + _rtP
-> P_234 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
Delay_ahrs5_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& _rtDW -> Delay_ahrs5_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
S ) ; _rtDW -> Delay_ahrs5_IWORK . Head = ( ( _rtDW -> Delay_ahrs5_IWORK .
Head < ( _rtDW -> Delay_ahrs5_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
Delay_ahrs5_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> Delay_ahrs5_IWORK . Head
== _rtDW -> Delay_ahrs5_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_ahrs5_IWORK . CircularBufSize , & _rtDW -> Delay_ahrs5_IWORK . Tail , &
_rtDW -> Delay_ahrs5_IWORK . Head , & _rtDW -> Delay_ahrs5_IWORK . Last ,
simTime - _rtP -> P_239 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_ahrs5_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_ahrs5_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_ahrs5_IWORK . Head ] = _rtB -> B_51_685_0 [ 1 ] ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_e =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_gc ) * _rtP -> P_242 + _rtP
-> P_241 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
Delay_ahrs4_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& _rtDW -> Delay_ahrs4_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
S ) ; _rtDW -> Delay_ahrs4_IWORK . Head = ( ( _rtDW -> Delay_ahrs4_IWORK .
Head < ( _rtDW -> Delay_ahrs4_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
Delay_ahrs4_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> Delay_ahrs4_IWORK . Head
== _rtDW -> Delay_ahrs4_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_ahrs4_IWORK . CircularBufSize , & _rtDW -> Delay_ahrs4_IWORK . Tail , &
_rtDW -> Delay_ahrs4_IWORK . Head , & _rtDW -> Delay_ahrs4_IWORK . Last ,
simTime - _rtP -> P_246 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_ahrs4_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_ahrs4_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_ahrs4_IWORK . Head ] = _rtB -> B_51_685_0 [ 2 ] ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_mv =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_n ) * _rtP -> P_249 + _rtP
-> P_248 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
Delay_ahrs6_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& _rtDW -> Delay_ahrs6_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
S ) ; _rtDW -> Delay_ahrs6_IWORK . Head = ( ( _rtDW -> Delay_ahrs6_IWORK .
Head < ( _rtDW -> Delay_ahrs6_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
Delay_ahrs6_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> Delay_ahrs6_IWORK . Head
== _rtDW -> Delay_ahrs6_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_ahrs6_IWORK . CircularBufSize , & _rtDW -> Delay_ahrs6_IWORK . Tail , &
_rtDW -> Delay_ahrs6_IWORK . Head , & _rtDW -> Delay_ahrs6_IWORK . Last ,
simTime - _rtP -> P_253 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_ahrs6_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_ahrs6_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_ahrs6_IWORK . Head ] = _rtB -> B_51_69_0 [ 0 ] ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_p =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_k ) * _rtP -> P_256 + _rtP
-> P_255 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
Delay_ahrs7_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& _rtDW -> Delay_ahrs7_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
S ) ; _rtDW -> Delay_ahrs7_IWORK . Head = ( ( _rtDW -> Delay_ahrs7_IWORK .
Head < ( _rtDW -> Delay_ahrs7_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
Delay_ahrs7_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> Delay_ahrs7_IWORK . Head
== _rtDW -> Delay_ahrs7_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_ahrs7_IWORK . CircularBufSize , & _rtDW -> Delay_ahrs7_IWORK . Tail , &
_rtDW -> Delay_ahrs7_IWORK . Head , & _rtDW -> Delay_ahrs7_IWORK . Last ,
simTime - _rtP -> P_262 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_ahrs7_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_ahrs7_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_ahrs7_IWORK . Head ] = _rtB -> B_51_69_0 [ 1 ] ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_bz =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_mj ) * _rtP -> P_265 + _rtP
-> P_264 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
Delay_ahrs8_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& _rtDW -> Delay_ahrs8_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
S ) ; _rtDW -> Delay_ahrs8_IWORK . Head = ( ( _rtDW -> Delay_ahrs8_IWORK .
Head < ( _rtDW -> Delay_ahrs8_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
Delay_ahrs8_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> Delay_ahrs8_IWORK . Head
== _rtDW -> Delay_ahrs8_IWORK . Tail ) { if ( !
v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
Delay_ahrs8_IWORK . CircularBufSize , & _rtDW -> Delay_ahrs8_IWORK . Tail , &
_rtDW -> Delay_ahrs8_IWORK . Head , & _rtDW -> Delay_ahrs8_IWORK . Last ,
simTime - _rtP -> P_271 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> Delay_ahrs8_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus (
S , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW
-> Delay_ahrs8_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
Delay_ahrs8_IWORK . Head ] = _rtB -> B_51_69_0 [ 2 ] ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_fy =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_mf ) * _rtP -> P_274 + _rtP
-> P_273 ; _rtDW -> NextOutput_o = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
RandSeed_h ) * _rtP -> P_281 + _rtP -> P_280 ; _rtDW -> NextOutput_a =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_l ) * _rtP -> P_284 + _rtP
-> P_283 ; ssCallAccelRunBlock ( S , 51 , 914 , SS_CALL_MDL_UPDATE ) ; _rtDW
-> Delay_DSTATE [ 0U ] = _rtDW -> Delay_DSTATE [ 1U ] ; _rtDW -> Delay_DSTATE
[ 1 ] = _rtB -> B_51_914_2 ; _rtDW -> Delay1_DSTATE [ 0U ] = _rtDW ->
Delay1_DSTATE [ 1U ] ; _rtDW -> Delay1_DSTATE [ 1 ] = _rtB -> B_51_914_3 ;
_rtDW -> Delay2_DSTATE [ 0U ] = _rtDW -> Delay2_DSTATE [ 1U ] ; _rtDW ->
Delay2_DSTATE [ 1 ] = _rtB -> B_51_914_4 ; _rtDW -> Delay3_DSTATE [ 0U ] =
_rtDW -> Delay3_DSTATE [ 1U ] ; _rtDW -> Delay3_DSTATE [ 1 ] = _rtB ->
B_51_914_5 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> NextOutput_p2 = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_c )
* _rtP -> P_357 + _rtP -> P_356 ; _rtDW -> NextOutput_p1 =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_p ) * _rtP -> P_361 + _rtP
-> P_360 ; _rtDW -> NextOutput_me = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
RandSeed_pa ) * _rtP -> P_365 + _rtP -> P_364 ; } isHit = ssIsSampleHit ( S ,
3 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_bl =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_d ) * _rtP -> P_369 + _rtP
-> P_368 ; _rtDW -> NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
RandSeed_hk ) * _rtP -> P_373 + _rtP -> P_372 ; } isHit = ssIsSampleHit ( S ,
2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_a1 =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_f ) * _rtP -> P_376 + _rtP
-> P_375 ; _rtDW -> NextOutput_mr = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
RandSeed_gu ) * _rtP -> P_379 + _rtP -> P_378 ; _rtDW -> NextOutput_o2 =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_d3 ) * _rtP -> P_382 + _rtP
-> P_381 ; _rtDW -> NextOutput_ej = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
RandSeed_p0 ) * _rtP -> P_385 + _rtP -> P_384 ; } UNUSED_PARAMETER ( tid ) ;
}
#define MDL_UPDATE
static void mdlUpdateTID4 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) {
B_v2022_Modello_SITL_AENEA_2020b_T * _rtB ;
DW_v2022_Modello_SITL_AENEA_2020b_T * _rtDW ;
P_v2022_Modello_SITL_AENEA_2020b_T * _rtP ;
XDis_v2022_Modello_SITL_AENEA_2020b_T * _rtXdis ;
XDot_v2022_Modello_SITL_AENEA_2020b_T * _rtXdot ;
X_v2022_Modello_SITL_AENEA_2020b_T * _rtX ; _rtDW = ( (
DW_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetRootDWork ( S ) ) ; _rtXdis = (
( XDis_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetContStateDisabled ( S ) ) ;
_rtXdot = ( ( XDot_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetdX ( S ) ) ;
_rtX = ( ( X_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetContStates ( S ) ) ;
_rtP = ( ( P_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( B_v2022_Modello_SITL_AENEA_2020b_T * ) _ssGetModelBlockIO ( S ) )
; _rtXdot -> phithetapsi_CSTATE [ 0 ] = _rtB -> B_51_926_0 [ 0 ] ; _rtXdot ->
xeyeze_CSTATE [ 0 ] = _rtB -> B_51_690_0 [ 0 ] ; _rtXdot ->
phithetapsi_CSTATE [ 1 ] = _rtB -> B_51_926_0 [ 1 ] ; _rtXdot ->
xeyeze_CSTATE [ 1 ] = _rtB -> B_51_690_0 [ 1 ] ; _rtXdot ->
phithetapsi_CSTATE [ 2 ] = _rtB -> B_51_926_0 [ 2 ] ; _rtXdot ->
xeyeze_CSTATE [ 2 ] = _rtB -> B_51_690_0 [ 2 ] ; if ( _rtDW ->
Distanceintogustx_MODE ) { if ( ( ( _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f > _rtP -> P_3 ) && ( _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f < _rtP -> P_2 ) ) || ( ( _rtX
-> DistanceintoGustxLimitedtogustlengthd_CSTATE_f <= _rtP -> P_3 ) && ( _rtB
-> B_35_0_1 > 0.0 ) ) || ( ( _rtX ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f >= _rtP -> P_2 ) && ( _rtB ->
B_35_0_1 < 0.0 ) ) ) { _rtXdot ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f = _rtB -> B_35_0_1 ; } else {
_rtXdot -> DistanceintoGustxLimitedtogustlengthd_CSTATE_f = 0.0 ; } } else {
( ( XDot_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetdX ( S ) ) ->
DistanceintoGustxLimitedtogustlengthd_CSTATE_f = 0.0 ; }
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Deriv ( S , _rtB -> B_35_0_1
, & _rtDW -> Distanceintogusty , & _rtP -> Distanceintogusty , & _rtX ->
Distanceintogusty , & _rtXdot -> Distanceintogusty ) ;
v2022_Modello_SITL_AENEA_2020b_Distanceintogusty_Deriv ( S , _rtB -> B_35_0_1
, & _rtDW -> Distanceintogustz , & _rtP -> Distanceintogustz , & _rtX ->
Distanceintogustz , & _rtXdot -> Distanceintogustz ) ; _rtXdot ->
ubvbwb_CSTATE [ 0 ] = _rtB -> B_51_683_0 [ 0 ] ; _rtXdot -> ubvbwb_CSTATE [ 1
] = _rtB -> B_51_683_0 [ 1 ] ; _rtXdot -> ubvbwb_CSTATE [ 2 ] = _rtB ->
B_51_683_0 [ 2 ] ; if ( _rtDW -> Hugws_MODE ) { _rtXdot -> ug_p_CSTATE [ 0 ]
= _rtB -> B_25_6_0 [ 0 ] ; _rtXdot -> ug_p_CSTATE [ 1 ] = _rtB -> B_25_6_0 [
1 ] ; } else { { real_T * dx ; int_T i ; dx = & ( ( (
XDot_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetdX ( S ) ) -> ug_p_CSTATE [ 0
] ) ; for ( i = 0 ; i < 2 ; i ++ ) { dx [ i ] = 0.0 ; } } } if ( _rtDW ->
Hvgws_MODE ) { _rtXdot -> vg_p1_CSTATE [ 0 ] = _rtB -> B_26_6_0 [ 0 ] ;
_rtXdot -> vgw_p2_CSTATE [ 0 ] = _rtB -> B_26_11_0 [ 0 ] ; _rtXdot ->
vg_p1_CSTATE [ 1 ] = _rtB -> B_26_6_0 [ 1 ] ; _rtXdot -> vgw_p2_CSTATE [ 1 ]
= _rtB -> B_26_11_0 [ 1 ] ; } else { { real_T * dx ; int_T i ; dx = & ( ( (
XDot_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetdX ( S ) ) -> vg_p1_CSTATE [ 0
] ) ; for ( i = 0 ; i < 4 ; i ++ ) { dx [ i ] = 0.0 ; } } } if ( _rtDW ->
Hwgws_MODE ) { _rtXdot -> wg_p1_CSTATE [ 0 ] = _rtB -> B_27_6_0 [ 0 ] ;
_rtXdot -> wg_p2_CSTATE [ 0 ] = _rtB -> B_27_11_0 [ 0 ] ; _rtXdot ->
wg_p1_CSTATE [ 1 ] = _rtB -> B_27_6_0 [ 1 ] ; _rtXdot -> wg_p2_CSTATE [ 1 ] =
_rtB -> B_27_11_0 [ 1 ] ; } else { { real_T * dx ; int_T i ; dx = & ( ( (
XDot_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetdX ( S ) ) -> wg_p1_CSTATE [ 0
] ) ; for ( i = 0 ; i < 4 ; i ++ ) { dx [ i ] = 0.0 ; } } } _rtXdot ->
StateSpace2_CSTATE = 0.0 ; _rtXdot -> StateSpace2_CSTATE += _rtP -> P_80 *
_rtX -> StateSpace2_CSTATE ; _rtXdot -> StateSpace2_CSTATE += _rtP -> P_81 *
_rtB -> B_45_15_0 ; _rtXdot -> StateSpace1_CSTATE = 0.0 ; _rtXdot ->
StateSpace1_CSTATE += _rtP -> P_86 * _rtX -> StateSpace1_CSTATE ; _rtXdot ->
StateSpace1_CSTATE += _rtP -> P_87 * _rtB -> B_45_11_0 ; _rtXdot ->
StateSpace_CSTATE = 0.0 ; _rtXdot -> StateSpace_CSTATE += _rtP -> P_96 * _rtX
-> StateSpace_CSTATE ; _rtXdot -> StateSpace_CSTATE += _rtP -> P_97 * _rtB ->
B_45_6_0 ; if ( _rtXdis -> Integrator_CSTATE ) { _rtXdot -> Integrator_CSTATE
= 0.0 ; } else if ( _rtB -> B_51_199_0 != 0.0 ) { _rtXdot ->
Integrator_CSTATE = 0.0 ; } else { _rtXdot -> Integrator_CSTATE = _rtB ->
B_51_1044_0 ; } if ( _rtXdis -> Integrator1_CSTATE ) { _rtXdot ->
Integrator1_CSTATE = 0.0 ; } else if ( _rtB -> B_51_199_0 != 0.0 ) { _rtXdot
-> Integrator1_CSTATE = 0.0 ; } else { _rtXdot -> Integrator1_CSTATE = _rtB
-> B_51_249_0 ; } if ( _rtXdis -> Integrator_CSTATE_m ) { _rtXdot ->
Integrator_CSTATE_m = 0.0 ; } else if ( _rtB -> B_51_312_0 != 0.0 ) { _rtXdot
-> Integrator_CSTATE_m = 0.0 ; } else { _rtXdot -> Integrator_CSTATE_m = _rtB
-> B_51_1101_0 ; } if ( _rtXdis -> Integrator1_CSTATE_a ) { _rtXdot ->
Integrator1_CSTATE_a = 0.0 ; } else if ( _rtB -> B_51_312_0 != 0.0 ) {
_rtXdot -> Integrator1_CSTATE_a = 0.0 ; } else { _rtXdot ->
Integrator1_CSTATE_a = _rtB -> B_51_365_0 ; } if ( _rtXdis ->
Integrator_CSTATE_md ) { _rtXdot -> Integrator_CSTATE_md = 0.0 ; } else if (
_rtB -> B_51_428_0 != 0.0 ) { _rtXdot -> Integrator_CSTATE_md = 0.0 ; } else
{ _rtXdot -> Integrator_CSTATE_md = _rtB -> B_51_1157_0 ; } if ( _rtXdis ->
Integrator1_CSTATE_n ) { _rtXdot -> Integrator1_CSTATE_n = 0.0 ; } else if (
_rtB -> B_51_428_0 != 0.0 ) { _rtXdot -> Integrator1_CSTATE_n = 0.0 ; } else
{ _rtXdot -> Integrator1_CSTATE_n = _rtB -> B_51_481_0 ; } _rtXdot ->
pqr_CSTATE [ 0 ] = _rtB -> B_51_945_0 [ 0 ] ; _rtXdot ->
PositionIntegrator2_CSTATE [ 0 ] = _rtB -> B_51_1183_0 [ 0 ] ; _rtXdot ->
pqr_CSTATE [ 1 ] = _rtB -> B_51_945_0 [ 1 ] ; _rtXdot ->
PositionIntegrator2_CSTATE [ 1 ] = _rtB -> B_51_1183_0 [ 1 ] ; _rtXdot ->
pqr_CSTATE [ 2 ] = _rtB -> B_51_945_0 [ 2 ] ; _rtXdot ->
PositionIntegrator2_CSTATE [ 2 ] = _rtB -> B_51_1183_0 [ 2 ] ; _rtXdot ->
Integrator_CSTATE_j = _rtB -> B_51_1208_0 ; _rtXdot -> Integrator_CSTATE_k =
_rtB -> B_51_1214_0 ; _rtXdot -> Integrator2_CSTATE = _rtB -> B_51_1197_0 ;
_rtXdot -> Integrator1_CSTATE_h = _rtB -> B_51_1200_0 ; _rtXdot ->
Integrator_CSTATE_d = _rtB -> B_51_1203_0 ; if ( _rtDW -> Hpgw_MODE ) {
_rtXdot -> pgw_p_CSTATE [ 0 ] = _rtB -> B_22_9_0 [ 0 ] ; _rtXdot ->
pgw_p_CSTATE [ 1 ] = _rtB -> B_22_9_0 [ 1 ] ; } else { { real_T * dx ; int_T
i ; dx = & ( ( ( XDot_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetdX ( S ) ) ->
pgw_p_CSTATE [ 0 ] ) ; for ( i = 0 ; i < 2 ; i ++ ) { dx [ i ] = 0.0 ; } } }
if ( _rtDW -> Hqgw_MODE ) { _rtXdot -> qgw_p_CSTATE [ 0 ] = _rtB -> B_23_4_0
[ 0 ] ; _rtXdot -> qgw_p_CSTATE [ 1 ] = _rtB -> B_23_4_0 [ 1 ] ; } else { {
real_T * dx ; int_T i ; dx = & ( ( ( XDot_v2022_Modello_SITL_AENEA_2020b_T *
) ssGetdX ( S ) ) -> qgw_p_CSTATE [ 0 ] ) ; for ( i = 0 ; i < 2 ; i ++ ) { dx
[ i ] = 0.0 ; } } } if ( _rtDW -> Hrgw_MODE ) { _rtXdot -> rgw_p_CSTATE [ 0 ]
= _rtB -> B_24_4_0 [ 0 ] ; _rtXdot -> rgw_p_CSTATE [ 1 ] = _rtB -> B_24_4_0 [
1 ] ; } else { { real_T * dx ; int_T i ; dx = & ( ( (
XDot_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetdX ( S ) ) -> rgw_p_CSTATE [ 0
] ) ; for ( i = 0 ; i < 2 ; i ++ ) { dx [ i ] = 0.0 ; } } } } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 605443097U
) ; ssSetChecksumVal ( S , 1 , 3599613794U ) ; ssSetChecksumVal ( S , 2 ,
3664027465U ) ; ssSetChecksumVal ( S , 3 , 1150382535U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "10.2" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( DW_v2022_Modello_SITL_AENEA_2020b_T ) ) { ssSetErrorStatus (
S , "Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_v2022_Modello_SITL_AENEA_2020b_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_v2022_Modello_SITL_AENEA_2020b_T ) ) { static char msg [ 256 ] ; sprintf (
msg , "Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & v2022_Modello_SITL_AENEA_2020b_DefaultP ) ; rt_InitInfAndNaN ( sizeof (
real_T ) ) ; ( ( P_v2022_Modello_SITL_AENEA_2020b_T * ) ssGetModelRtp ( S ) )
-> P_52 = rtInf ; } static void mdlInitializeSampleTimes ( SimStruct * S ) {
{ SimStruct * childS ; SysOutputFcn * callSysFcns ; childS = ssGetSFunction (
S , 0 ) ; callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns
[ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ;
callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ]
= ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 3 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 4 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 5 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 6 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 7 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 8 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 9 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 10 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 11 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 12 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 13 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 14 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 15 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 16 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 17 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 18 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 19 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 20 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 21 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 22 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 23 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 24 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 25 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 26 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 27 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 28 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 29 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 30 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 31 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 32 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID4 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
