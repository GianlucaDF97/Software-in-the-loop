#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "autopilota_v_15_last_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "autopilota_v_15_last.h"
#include "autopilota_v_15_last_capi.h"
#include "autopilota_v_15_last_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_SignalHierLoggingInfo rtSigHierLoggingInfo [ ] = { { ""
, 16 , 0 } , { "Lat_K" , 0 , - 1 } , { "Long_K" , 0 , - 1 } , { "h_K" , 0 , -
1 } , { "vn_K" , 0 , - 1 } , { "ve_K" , 0 , - 1 } , { "vd_K" , 0 , - 1 } , {
"an_K" , 0 , - 1 } , { "ae_K" , 0 , - 1 } , { "ad_K" , 0 , - 1 } , { "p_K" ,
0 , - 1 } , { "q_K" , 0 , - 1 } , { "r_K" , 0 , - 1 } , { "v_K" , 0 , - 1 } ,
{ "imbardata" , 0 , - 1 } , { "signal15" , 6 , 16 } , { "baccx" , 0 , - 1 } ,
{ "baccy" , 0 , - 1 } , { "baccz" , 0 , - 1 } , { "bp" , 0 , - 1 } , { "bq" ,
0 , - 1 } , { "br" , 0 , - 1 } , { "Cov_est" , 0 , - 1 } , { "" , 19 , 22 } ,
{ "Tas" , 0 , - 1 } , { "Alt" , 0 , - 1 } , { "psi" , 0 , - 1 } , { "AOA" , 0
, - 1 } , { "Beta" , 0 , - 1 } , { "theta" , 0 , - 1 } , { "phi" , 0 , - 1 }
, { "p" , 0 , - 1 } , { "q" , 0 , - 1 } , { "r" , 0 , - 1 } , { "RC" , 0 , -
1 } , { "rho" , 0 , - 1 } , { "w" , 0 , - 1 } , { "omega" , 0 , - 1 } , {
"Lat" , 0 , - 1 } , { "Long" , 0 , - 1 } , { "v" , 0 , - 1 } , { "heading" ,
0 , - 1 } , { "quota_lidar" , 0 , - 1 } } ; static const uint_T
rtSigHierLoggingChildIdxs [ ] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11
, 12 , 13 , 14 , 15 , 22 , 16 , 17 , 18 , 19 , 20 , 21 , 24 , 25 , 26 , 27 ,
28 , 29 , 30 , 31 , 32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 , 40 , 41 , 42 } ;
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , - 1
, TARGET_STRING ( "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay10"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 1
, - 1 , TARGET_STRING (
"autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay11" ) , TARGET_STRING
( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 2 , - 1 ,
TARGET_STRING ( "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay12" )
, TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 3 ,
- 1 , TARGET_STRING (
"autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay13" ) , TARGET_STRING
( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 4 , - 1 ,
TARGET_STRING ( "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay14" )
, TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 5 ,
- 1 , TARGET_STRING (
"autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay15" ) , TARGET_STRING
( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 6 , - 1 ,
TARGET_STRING ( "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay16" )
, TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 7 ,
- 1 , TARGET_STRING (
"autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay17" ) , TARGET_STRING
( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 8 , - 1 ,
TARGET_STRING ( "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay18" )
, TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 9 ,
- 1 , TARGET_STRING (
"autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay19" ) , TARGET_STRING
( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 10 , - 1 ,
TARGET_STRING ( "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay2" )
, TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 11
, - 1 , TARGET_STRING (
"autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay3" ) , TARGET_STRING
( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 12 , - 1 ,
TARGET_STRING ( "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay4" )
, TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 13
, - 1 , TARGET_STRING (
"autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay5" ) , TARGET_STRING
( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 14 , - 1 ,
TARGET_STRING ( "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay6" )
, TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 15
, - 1 , TARGET_STRING (
"autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay7" ) , TARGET_STRING
( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 16 , - 1 ,
TARGET_STRING ( "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay8" )
, TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 17
, - 1 , TARGET_STRING (
"autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Delay9" ) , TARGET_STRING
( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 18 , - 1 ,
TARGET_STRING (
 "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Discrete Varying Lowpass/SOS1/Unit Delay1"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
19 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/MISURE DA SENSORI \nFILTRATE/Discrete Varying Lowpass/SOS1/Unit Delay2"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
20 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/CONTROLLI INTERNI E SWITCH1/Filtro\nWashout1/Discrete\nWashout Filter"
) , TARGET_STRING ( "states" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
21 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/CONTROLLI INTERNI E SWITCH1/manetta - takeoff/Discrete-Time\nIntegrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
22 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/Subsystem1/Subsystem1/APPROACH/Discrete-Time\nIntegrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
23 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Filter/Disc. Forward Euler Filter/Filter"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
24 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/AUTOPILOTI1/CONTROLLORE DI ROTTA/PID Controller1/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
25 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/AUTOPILOTI1/CONTROLLORE DI VELOCITA'/PID Controller/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
26 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/CONTROLLI INTERNI E SWITCH1/Controllore PID/PID Controller/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
27 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/CONTROLLI INTERNI E SWITCH1/Controllore PID1/PID Controller/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
28 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Filter/Disc. Forward Euler Filter/Filter"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
29 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
30 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Filter/Disc. Forward Euler Filter/Filter"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
31 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI Approach1/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
32 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/AUTOPILOTI1/CONTROLLORE DI QUOTA/Controllore di RC1/PI RC saturato/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
33 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Filter/Disc. Forward Euler Filter/Filter"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , {
34 , - 1 , TARGET_STRING (
 "autopilota_v_15_last/Subsystem1/Subsystem1/Subsystem1/INSEGUIMENTO CENTRO PISTA/PID Controller/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , { 0
, - 1 , ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } }
;
#ifndef HOST_CAPI_BUILD
static void autopilota_v_15_last_InitializeDataAddr ( void * dataAddr [ ] ) {
dataAddr [ 0 ] = ( void * ) ( & oglgrr3ye1h . o5kkpvumpl [ 0 ] ) ; dataAddr [
1 ] = ( void * ) ( & oglgrr3ye1h . dqmnthsusm [ 0 ] ) ; dataAddr [ 2 ] = (
void * ) ( & oglgrr3ye1h . owziyeixn3 [ 0 ] ) ; dataAddr [ 3 ] = ( void * ) (
& oglgrr3ye1h . c45yaajshc [ 0 ] ) ; dataAddr [ 4 ] = ( void * ) ( &
oglgrr3ye1h . ftmjyowlt3 [ 0 ] ) ; dataAddr [ 5 ] = ( void * ) ( &
oglgrr3ye1h . eu44ogdptu [ 0 ] ) ; dataAddr [ 6 ] = ( void * ) ( &
oglgrr3ye1h . ciklknloma [ 0 ] ) ; dataAddr [ 7 ] = ( void * ) ( &
oglgrr3ye1h . dx2lrlxy5r [ 0 ] ) ; dataAddr [ 8 ] = ( void * ) ( &
oglgrr3ye1h . jflkmnpydv [ 0 ] ) ; dataAddr [ 9 ] = ( void * ) ( &
oglgrr3ye1h . dpdqccjw4g [ 0 ] ) ; dataAddr [ 10 ] = ( void * ) ( &
oglgrr3ye1h . bqgl5044ys [ 0 ] ) ; dataAddr [ 11 ] = ( void * ) ( &
oglgrr3ye1h . fjcugr03eu [ 0 ] ) ; dataAddr [ 12 ] = ( void * ) ( &
oglgrr3ye1h . oguyx1dafu [ 0 ] ) ; dataAddr [ 13 ] = ( void * ) ( &
oglgrr3ye1h . dmx0nh3d45 [ 0 ] ) ; dataAddr [ 14 ] = ( void * ) ( &
oglgrr3ye1h . mvxa2hv5hn [ 0 ] ) ; dataAddr [ 15 ] = ( void * ) ( &
oglgrr3ye1h . jhflgxiuur [ 0 ] ) ; dataAddr [ 16 ] = ( void * ) ( &
oglgrr3ye1h . c1mlbfpvqi [ 0 ] ) ; dataAddr [ 17 ] = ( void * ) ( &
oglgrr3ye1h . ltt43mjgwg [ 0 ] ) ; dataAddr [ 18 ] = ( void * ) ( &
oglgrr3ye1h . jq540lcfml ) ; dataAddr [ 19 ] = ( void * ) ( & oglgrr3ye1h .
dmmlbnpjdu ) ; dataAddr [ 20 ] = ( void * ) ( & oglgrr3ye1h . mn42l5n3wb ) ;
dataAddr [ 21 ] = ( void * ) ( & oglgrr3ye1h . iyz4qwlchu ) ; dataAddr [ 22 ]
= ( void * ) ( & oglgrr3ye1h . nilep3eihq ) ; dataAddr [ 23 ] = ( void * ) (
& oglgrr3ye1h . kynrzw2ofp ) ; dataAddr [ 24 ] = ( void * ) ( & oglgrr3ye1h .
c3acypmpwn ) ; dataAddr [ 25 ] = ( void * ) ( & oglgrr3ye1h . kebipqswvw ) ;
dataAddr [ 26 ] = ( void * ) ( & oglgrr3ye1h . f0peflpe1c ) ; dataAddr [ 27 ]
= ( void * ) ( & oglgrr3ye1h . oiitntzk3c ) ; dataAddr [ 28 ] = ( void * ) (
& oglgrr3ye1h . kxoxrkpazj ) ; dataAddr [ 29 ] = ( void * ) ( & oglgrr3ye1h .
n1gd3enizc ) ; dataAddr [ 30 ] = ( void * ) ( & oglgrr3ye1h . jeucenmbmt ) ;
dataAddr [ 31 ] = ( void * ) ( & oglgrr3ye1h . bajf1l4tmp ) ; dataAddr [ 32 ]
= ( void * ) ( & oglgrr3ye1h . kbhu2b3s4r ) ; dataAddr [ 33 ] = ( void * ) (
& oglgrr3ye1h . jpbq3tpzxc ) ; dataAddr [ 34 ] = ( void * ) ( & oglgrr3ye1h .
kbce4syljb ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void autopilota_v_15_last_InitializeVarDimsAddr ( int32_T *
vardimsAddr [ ] ) { vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void autopilota_v_15_last_InitializeLoggingFunctions (
RTWLoggingFcnPtr loggingPtrs [ ] ) { loggingPtrs [ 0 ] = ( NULL ) ;
loggingPtrs [ 1 ] = ( NULL ) ; loggingPtrs [ 2 ] = ( NULL ) ; loggingPtrs [ 3
] = ( NULL ) ; loggingPtrs [ 4 ] = ( NULL ) ; loggingPtrs [ 5 ] = ( NULL ) ;
loggingPtrs [ 6 ] = ( NULL ) ; loggingPtrs [ 7 ] = ( NULL ) ; loggingPtrs [ 8
] = ( NULL ) ; loggingPtrs [ 9 ] = ( NULL ) ; loggingPtrs [ 10 ] = ( NULL ) ;
loggingPtrs [ 11 ] = ( NULL ) ; loggingPtrs [ 12 ] = ( NULL ) ; loggingPtrs [
13 ] = ( NULL ) ; loggingPtrs [ 14 ] = ( NULL ) ; loggingPtrs [ 15 ] = ( NULL
) ; loggingPtrs [ 16 ] = ( NULL ) ; loggingPtrs [ 17 ] = ( NULL ) ;
loggingPtrs [ 18 ] = ( NULL ) ; loggingPtrs [ 19 ] = ( NULL ) ; loggingPtrs [
20 ] = ( NULL ) ; loggingPtrs [ 21 ] = ( NULL ) ; loggingPtrs [ 22 ] = ( NULL
) ; loggingPtrs [ 23 ] = ( NULL ) ; loggingPtrs [ 24 ] = ( NULL ) ;
loggingPtrs [ 25 ] = ( NULL ) ; loggingPtrs [ 26 ] = ( NULL ) ; loggingPtrs [
27 ] = ( NULL ) ; loggingPtrs [ 28 ] = ( NULL ) ; loggingPtrs [ 29 ] = ( NULL
) ; loggingPtrs [ 30 ] = ( NULL ) ; loggingPtrs [ 31 ] = ( NULL ) ;
loggingPtrs [ 32 ] = ( NULL ) ; loggingPtrs [ 33 ] = ( NULL ) ; loggingPtrs [
34 ] = ( NULL ) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } } ; static
uint_T rtDimensionArray [ ] = { 2 , 1 , 1 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.02 , 0.0 } ; static rtwCAPI_FixPtMap rtFixPtMap
[ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ;
static rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 ,
0 } } ; static int_T rtContextSystems [ 99 ] ; static rtwCAPI_LoggingMetaInfo
loggingMetaInfo [ ] = { { 0 , 0 , "" , 0 } } ; static
rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 99 ,
rtContextSystems , loggingMetaInfo , 0 , NULL , { 43 , rtSigHierLoggingInfo ,
rtSigHierLoggingChildIdxs } , 0 , ( NULL ) } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 0 , ( NULL )
, 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockStates , 35
} , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap ,
rtSampleTimeMap , rtDimensionArray } , "float" , { 2098868253U , 2293853137U
, 535171205U , 1696243120U } , & mmiStaticInfoLogging , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * autopilota_v_15_last_GetCAPIStaticMap ( void
) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void autopilota_v_15_last_InitializeSystemRan ( jywahqwvru * const
gdpbrj5obc , sysRanDType * systemRan [ ] , int_T systemTid [ ] , void *
rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER ( gdpbrj5obc ) ; systemRan [
0 ] = ( sysRanDType * ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ;
systemRan [ 2 ] = ( NULL ) ; systemRan [ 3 ] = ( sysRanDType * ) &
oglgrr3ye1h . arz05ugsx2 ; systemRan [ 4 ] = ( NULL ) ; systemRan [ 5 ] = (
NULL ) ; systemRan [ 6 ] = ( NULL ) ; systemRan [ 7 ] = ( NULL ) ; systemRan
[ 8 ] = ( NULL ) ; systemRan [ 9 ] = ( NULL ) ; systemRan [ 10 ] = ( NULL ) ;
systemRan [ 11 ] = ( NULL ) ; systemRan [ 12 ] = ( NULL ) ; systemRan [ 13 ]
= ( NULL ) ; systemRan [ 14 ] = ( NULL ) ; systemRan [ 15 ] = ( NULL ) ;
systemRan [ 16 ] = ( NULL ) ; systemRan [ 17 ] = ( NULL ) ; systemRan [ 18 ]
= ( NULL ) ; systemRan [ 19 ] = ( NULL ) ; systemRan [ 20 ] = ( NULL ) ;
systemRan [ 21 ] = ( NULL ) ; systemRan [ 22 ] = ( sysRanDType * ) &
oglgrr3ye1h . ekdnl51mfa ; systemRan [ 23 ] = ( NULL ) ; systemRan [ 24 ] = (
NULL ) ; systemRan [ 25 ] = ( NULL ) ; systemRan [ 26 ] = ( NULL ) ;
systemRan [ 27 ] = ( NULL ) ; systemRan [ 28 ] = ( NULL ) ; systemRan [ 29 ]
= ( NULL ) ; systemRan [ 30 ] = ( NULL ) ; systemRan [ 31 ] = ( NULL ) ;
systemRan [ 32 ] = ( NULL ) ; systemRan [ 33 ] = ( NULL ) ; systemRan [ 34 ]
= ( NULL ) ; systemRan [ 35 ] = ( NULL ) ; systemRan [ 36 ] = ( NULL ) ;
systemRan [ 37 ] = ( NULL ) ; systemRan [ 38 ] = ( NULL ) ; systemRan [ 39 ]
= ( NULL ) ; systemRan [ 40 ] = ( NULL ) ; systemRan [ 41 ] = ( NULL ) ;
systemRan [ 42 ] = ( NULL ) ; systemRan [ 43 ] = ( NULL ) ; systemRan [ 44 ]
= ( NULL ) ; systemRan [ 45 ] = ( NULL ) ; systemRan [ 46 ] = ( NULL ) ;
systemRan [ 47 ] = ( NULL ) ; systemRan [ 48 ] = ( NULL ) ; systemRan [ 49 ]
= ( NULL ) ; systemRan [ 50 ] = ( NULL ) ; systemRan [ 51 ] = ( NULL ) ;
systemRan [ 52 ] = ( NULL ) ; systemRan [ 53 ] = ( sysRanDType * ) &
oglgrr3ye1h . mjuxyoaa0mz . kledswthwx ; systemRan [ 54 ] = ( NULL ) ;
systemRan [ 55 ] = ( sysRanDType * ) & oglgrr3ye1h . bktohg4em1 . kledswthwx
; systemRan [ 56 ] = ( NULL ) ; systemRan [ 57 ] = ( sysRanDType * ) &
oglgrr3ye1h . kxbvi3u1rvx . fe1s22yq5q ; systemRan [ 58 ] = ( NULL ) ;
systemRan [ 59 ] = ( sysRanDType * ) & oglgrr3ye1h . mcanjxzmcw . fe1s22yq5q
; systemRan [ 60 ] = ( NULL ) ; systemRan [ 61 ] = ( NULL ) ; systemRan [ 62
] = ( NULL ) ; systemRan [ 63 ] = ( sysRanDType * ) & oglgrr3ye1h .
jpki55thm5 ; systemRan [ 64 ] = ( NULL ) ; systemRan [ 65 ] = ( NULL ) ;
systemRan [ 66 ] = ( NULL ) ; systemRan [ 67 ] = ( NULL ) ; systemRan [ 68 ]
= ( NULL ) ; systemRan [ 69 ] = ( sysRanDType * ) & oglgrr3ye1h . n1pnu1nol1
; systemRan [ 70 ] = ( sysRanDType * ) & oglgrr3ye1h . nmxve1xb0l ; systemRan
[ 71 ] = ( sysRanDType * ) & oglgrr3ye1h . pq0jmtvde5 ; systemRan [ 72 ] = (
NULL ) ; systemRan [ 73 ] = ( sysRanDType * ) & oglgrr3ye1h . ofua1wvq0o ;
systemRan [ 74 ] = ( NULL ) ; systemRan [ 75 ] = ( NULL ) ; systemRan [ 76 ]
= ( sysRanDType * ) & oglgrr3ye1h . lkv1q3ycjb ; systemRan [ 77 ] = ( NULL )
; systemRan [ 78 ] = ( NULL ) ; systemRan [ 79 ] = ( NULL ) ; systemRan [ 80
] = ( NULL ) ; systemRan [ 81 ] = ( sysRanDType * ) & oglgrr3ye1h .
fm30ckykmx ; systemRan [ 82 ] = ( sysRanDType * ) & oglgrr3ye1h . buia5ekwhx
; systemRan [ 83 ] = ( NULL ) ; systemRan [ 84 ] = ( NULL ) ; systemRan [ 85
] = ( NULL ) ; systemRan [ 86 ] = ( NULL ) ; systemRan [ 87 ] = ( NULL ) ;
systemRan [ 88 ] = ( NULL ) ; systemRan [ 89 ] = ( sysRanDType * ) &
oglgrr3ye1h . d2egajzdqa ; systemRan [ 90 ] = ( NULL ) ; systemRan [ 91 ] = (
NULL ) ; systemRan [ 92 ] = ( NULL ) ; systemRan [ 93 ] = ( sysRanDType * ) &
oglgrr3ye1h . gldq551xqr ; systemRan [ 94 ] = ( NULL ) ; systemRan [ 95 ] = (
sysRanDType * ) & oglgrr3ye1h . py3wr44hyb ; systemRan [ 96 ] = ( NULL ) ;
systemRan [ 97 ] = ( sysRanDType * ) & oglgrr3ye1h . dulatia2da ; systemRan [
98 ] = ( NULL ) ; systemTid [ 1 ] = howtympnvp [ 0 ] ; systemTid [ 2 ] =
howtympnvp [ 0 ] ; systemTid [ 3 ] = howtympnvp [ 0 ] ; systemTid [ 4 ] =
howtympnvp [ 0 ] ; systemTid [ 5 ] = howtympnvp [ 0 ] ; systemTid [ 6 ] =
howtympnvp [ 0 ] ; systemTid [ 7 ] = howtympnvp [ 0 ] ; systemTid [ 8 ] =
howtympnvp [ 0 ] ; systemTid [ 9 ] = howtympnvp [ 0 ] ; systemTid [ 10 ] =
howtympnvp [ 0 ] ; systemTid [ 11 ] = howtympnvp [ 0 ] ; systemTid [ 12 ] =
howtympnvp [ 0 ] ; systemTid [ 13 ] = howtympnvp [ 0 ] ; systemTid [ 14 ] =
howtympnvp [ 0 ] ; systemTid [ 15 ] = howtympnvp [ 0 ] ; systemTid [ 16 ] =
howtympnvp [ 0 ] ; systemTid [ 17 ] = howtympnvp [ 0 ] ; systemTid [ 18 ] =
howtympnvp [ 0 ] ; systemTid [ 19 ] = howtympnvp [ 0 ] ; systemTid [ 20 ] =
howtympnvp [ 0 ] ; systemTid [ 21 ] = howtympnvp [ 0 ] ; systemTid [ 22 ] =
howtympnvp [ 0 ] ; systemTid [ 23 ] = howtympnvp [ 0 ] ; systemTid [ 24 ] =
howtympnvp [ 0 ] ; systemTid [ 25 ] = howtympnvp [ 0 ] ; systemTid [ 26 ] =
howtympnvp [ 0 ] ; systemTid [ 27 ] = howtympnvp [ 0 ] ; systemTid [ 28 ] =
howtympnvp [ 0 ] ; systemTid [ 29 ] = howtympnvp [ 0 ] ; systemTid [ 30 ] =
howtympnvp [ 0 ] ; systemTid [ 31 ] = howtympnvp [ 0 ] ; systemTid [ 32 ] =
howtympnvp [ 0 ] ; systemTid [ 33 ] = howtympnvp [ 0 ] ; systemTid [ 34 ] =
howtympnvp [ 0 ] ; systemTid [ 35 ] = howtympnvp [ 0 ] ; systemTid [ 36 ] =
howtympnvp [ 0 ] ; systemTid [ 37 ] = howtympnvp [ 0 ] ; systemTid [ 38 ] =
howtympnvp [ 0 ] ; systemTid [ 39 ] = howtympnvp [ 0 ] ; systemTid [ 40 ] =
howtympnvp [ 0 ] ; systemTid [ 41 ] = howtympnvp [ 0 ] ; systemTid [ 42 ] =
howtympnvp [ 0 ] ; systemTid [ 43 ] = howtympnvp [ 0 ] ; systemTid [ 44 ] =
howtympnvp [ 0 ] ; systemTid [ 45 ] = howtympnvp [ 0 ] ; systemTid [ 46 ] =
howtympnvp [ 0 ] ; systemTid [ 47 ] = howtympnvp [ 0 ] ; systemTid [ 48 ] =
howtympnvp [ 0 ] ; systemTid [ 49 ] = howtympnvp [ 0 ] ; systemTid [ 50 ] =
howtympnvp [ 0 ] ; systemTid [ 51 ] = howtympnvp [ 0 ] ; systemTid [ 52 ] =
howtympnvp [ 0 ] ; systemTid [ 53 ] = howtympnvp [ 0 ] ; systemTid [ 55 ] =
howtympnvp [ 0 ] ; systemTid [ 54 ] = howtympnvp [ 0 ] ; systemTid [ 56 ] =
howtympnvp [ 0 ] ; systemTid [ 58 ] = howtympnvp [ 0 ] ; systemTid [ 60 ] =
howtympnvp [ 0 ] ; systemTid [ 64 ] = howtympnvp [ 0 ] ; systemTid [ 57 ] =
howtympnvp [ 0 ] ; systemTid [ 59 ] = howtympnvp [ 0 ] ; systemTid [ 61 ] =
howtympnvp [ 0 ] ; systemTid [ 62 ] = howtympnvp [ 0 ] ; systemTid [ 63 ] =
howtympnvp [ 0 ] ; systemTid [ 65 ] = howtympnvp [ 0 ] ; systemTid [ 66 ] =
howtympnvp [ 0 ] ; systemTid [ 67 ] = howtympnvp [ 0 ] ; systemTid [ 68 ] =
howtympnvp [ 0 ] ; systemTid [ 69 ] = howtympnvp [ 0 ] ; systemTid [ 70 ] =
howtympnvp [ 0 ] ; systemTid [ 71 ] = howtympnvp [ 0 ] ; systemTid [ 72 ] =
howtympnvp [ 0 ] ; systemTid [ 73 ] = howtympnvp [ 0 ] ; systemTid [ 74 ] =
howtympnvp [ 0 ] ; systemTid [ 75 ] = howtympnvp [ 0 ] ; systemTid [ 76 ] =
howtympnvp [ 0 ] ; systemTid [ 77 ] = howtympnvp [ 0 ] ; systemTid [ 78 ] =
howtympnvp [ 0 ] ; systemTid [ 79 ] = howtympnvp [ 0 ] ; systemTid [ 80 ] =
howtympnvp [ 0 ] ; systemTid [ 81 ] = howtympnvp [ 0 ] ; systemTid [ 82 ] =
howtympnvp [ 0 ] ; systemTid [ 83 ] = howtympnvp [ 0 ] ; systemTid [ 84 ] =
howtympnvp [ 0 ] ; systemTid [ 85 ] = howtympnvp [ 0 ] ; systemTid [ 86 ] =
howtympnvp [ 0 ] ; systemTid [ 87 ] = howtympnvp [ 0 ] ; systemTid [ 88 ] =
howtympnvp [ 0 ] ; systemTid [ 89 ] = howtympnvp [ 0 ] ; systemTid [ 90 ] =
howtympnvp [ 0 ] ; systemTid [ 91 ] = howtympnvp [ 0 ] ; systemTid [ 92 ] =
howtympnvp [ 0 ] ; systemTid [ 93 ] = howtympnvp [ 0 ] ; systemTid [ 94 ] =
howtympnvp [ 0 ] ; systemTid [ 95 ] = howtympnvp [ 0 ] ; systemTid [ 96 ] =
howtympnvp [ 0 ] ; systemTid [ 97 ] = howtympnvp [ 0 ] ; systemTid [ 98 ] =
howtympnvp [ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] = 0 ;
rtContextSystems [ 1 ] = 0 ; rtContextSystems [ 2 ] = 3 ; rtContextSystems [
3 ] = 3 ; rtContextSystems [ 4 ] = 0 ; rtContextSystems [ 5 ] = 0 ;
rtContextSystems [ 6 ] = 0 ; rtContextSystems [ 7 ] = 0 ; rtContextSystems [
8 ] = 0 ; rtContextSystems [ 9 ] = 0 ; rtContextSystems [ 10 ] = 0 ;
rtContextSystems [ 11 ] = 0 ; rtContextSystems [ 12 ] = 0 ; rtContextSystems
[ 13 ] = 0 ; rtContextSystems [ 14 ] = 0 ; rtContextSystems [ 15 ] = 0 ;
rtContextSystems [ 16 ] = 0 ; rtContextSystems [ 17 ] = 0 ; rtContextSystems
[ 18 ] = 0 ; rtContextSystems [ 19 ] = 0 ; rtContextSystems [ 20 ] = 0 ;
rtContextSystems [ 21 ] = 0 ; rtContextSystems [ 22 ] = 22 ; rtContextSystems
[ 23 ] = 0 ; rtContextSystems [ 24 ] = 0 ; rtContextSystems [ 25 ] = 0 ;
rtContextSystems [ 26 ] = 0 ; rtContextSystems [ 27 ] = 0 ; rtContextSystems
[ 28 ] = 0 ; rtContextSystems [ 29 ] = 0 ; rtContextSystems [ 30 ] = 0 ;
rtContextSystems [ 31 ] = 0 ; rtContextSystems [ 32 ] = 0 ; rtContextSystems
[ 33 ] = 0 ; rtContextSystems [ 34 ] = 0 ; rtContextSystems [ 35 ] = 0 ;
rtContextSystems [ 36 ] = 0 ; rtContextSystems [ 37 ] = 0 ; rtContextSystems
[ 38 ] = 0 ; rtContextSystems [ 39 ] = 0 ; rtContextSystems [ 40 ] = 0 ;
rtContextSystems [ 41 ] = 0 ; rtContextSystems [ 42 ] = 0 ; rtContextSystems
[ 43 ] = 0 ; rtContextSystems [ 44 ] = 0 ; rtContextSystems [ 45 ] = 0 ;
rtContextSystems [ 46 ] = 0 ; rtContextSystems [ 47 ] = 0 ; rtContextSystems
[ 48 ] = 0 ; rtContextSystems [ 49 ] = 0 ; rtContextSystems [ 50 ] = 0 ;
rtContextSystems [ 51 ] = 0 ; rtContextSystems [ 52 ] = 0 ; rtContextSystems
[ 53 ] = 53 ; rtContextSystems [ 54 ] = 0 ; rtContextSystems [ 55 ] = 55 ;
rtContextSystems [ 56 ] = 0 ; rtContextSystems [ 57 ] = 57 ; rtContextSystems
[ 58 ] = 0 ; rtContextSystems [ 59 ] = 59 ; rtContextSystems [ 60 ] = 0 ;
rtContextSystems [ 61 ] = 0 ; rtContextSystems [ 62 ] = 0 ; rtContextSystems
[ 63 ] = 63 ; rtContextSystems [ 64 ] = 0 ; rtContextSystems [ 65 ] = 0 ;
rtContextSystems [ 66 ] = 0 ; rtContextSystems [ 67 ] = 0 ; rtContextSystems
[ 68 ] = 71 ; rtContextSystems [ 69 ] = 69 ; rtContextSystems [ 70 ] = 70 ;
rtContextSystems [ 71 ] = 71 ; rtContextSystems [ 72 ] = 73 ;
rtContextSystems [ 73 ] = 73 ; rtContextSystems [ 74 ] = 93 ;
rtContextSystems [ 75 ] = 76 ; rtContextSystems [ 76 ] = 76 ;
rtContextSystems [ 77 ] = 93 ; rtContextSystems [ 78 ] = 93 ;
rtContextSystems [ 79 ] = 93 ; rtContextSystems [ 80 ] = 93 ;
rtContextSystems [ 81 ] = 81 ; rtContextSystems [ 82 ] = 82 ;
rtContextSystems [ 83 ] = 93 ; rtContextSystems [ 84 ] = 93 ;
rtContextSystems [ 85 ] = 93 ; rtContextSystems [ 86 ] = 93 ;
rtContextSystems [ 87 ] = 93 ; rtContextSystems [ 88 ] = 93 ;
rtContextSystems [ 89 ] = 89 ; rtContextSystems [ 90 ] = 93 ;
rtContextSystems [ 91 ] = 93 ; rtContextSystems [ 92 ] = 93 ;
rtContextSystems [ 93 ] = 93 ; rtContextSystems [ 94 ] = 95 ;
rtContextSystems [ 95 ] = 95 ; rtContextSystems [ 96 ] = 97 ;
rtContextSystems [ 97 ] = 97 ; rtContextSystems [ 98 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void autopilota_v_15_last_InitializeDataMapInfo ( jywahqwvru * const
gdpbrj5obc , void * sysRanPtr , int contextTid ) { rtwCAPI_SetVersion (
gdpbrj5obc -> DataMapInfo . mmi , 1 ) ; rtwCAPI_SetStaticMap ( gdpbrj5obc ->
DataMapInfo . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( gdpbrj5obc
-> DataMapInfo . mmi , & mmiStaticInfoLogging ) ;
autopilota_v_15_last_InitializeDataAddr ( gdpbrj5obc -> DataMapInfo .
dataAddress ) ; rtwCAPI_SetDataAddressMap ( gdpbrj5obc -> DataMapInfo . mmi ,
gdpbrj5obc -> DataMapInfo . dataAddress ) ;
autopilota_v_15_last_InitializeVarDimsAddr ( gdpbrj5obc -> DataMapInfo .
vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap ( gdpbrj5obc -> DataMapInfo .
mmi , gdpbrj5obc -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetPath (
gdpbrj5obc -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath (
gdpbrj5obc -> DataMapInfo . mmi , ( NULL ) ) ;
autopilota_v_15_last_InitializeLoggingFunctions ( gdpbrj5obc -> DataMapInfo .
loggingPtrs ) ; rtwCAPI_SetLoggingPtrs ( gdpbrj5obc -> DataMapInfo . mmi ,
gdpbrj5obc -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetInstanceLoggingInfo (
gdpbrj5obc -> DataMapInfo . mmi , & gdpbrj5obc -> DataMapInfo .
mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray ( gdpbrj5obc -> DataMapInfo .
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( gdpbrj5obc -> DataMapInfo .
mmi , 0 ) ; autopilota_v_15_last_InitializeSystemRan ( gdpbrj5obc ,
gdpbrj5obc -> DataMapInfo . systemRan , gdpbrj5obc -> DataMapInfo . systemTid
, sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( gdpbrj5obc -> DataMapInfo
. mmi , gdpbrj5obc -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid (
gdpbrj5obc -> DataMapInfo . mmi , gdpbrj5obc -> DataMapInfo . systemTid ) ;
rtwCAPI_SetGlobalTIDMap ( gdpbrj5obc -> DataMapInfo . mmi , & howtympnvp [ 0
] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void autopilota_v_15_last_host_InitializeDataMapInfo (
autopilota_v_15_last_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
