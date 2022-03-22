#ifndef RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_h_
#define RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_h_
#include <stddef.h>
#include <string.h>
#ifndef v2022_Modello_SITL_AENEA_2020b_acc_COMMON_INCLUDES_
#define v2022_Modello_SITL_AENEA_2020b_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "v2022_Modello_SITL_AENEA_2020b_acc_types.h"
#include "multiword_types.h"
#define autopilota_v_15_last_MDLREF_HIDE_CHILD_
#include "autopilota_v_15_last.h"
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T B_20_0_0 ; }
B_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T ; typedef struct {
int32_T Distanceintogusty_sysIdxToRun ; int8_T Distanceintogusty_SubsysRanBC
; boolean_T Distanceintogusty_MODE ; char_T pad_Distanceintogusty_MODE [ 2 ]
; } DW_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T ; typedef struct {
real_T DistanceintoGustxLimitedtogustlengthd_CSTATE ; }
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T ; typedef struct {
real_T DistanceintoGustxLimitedtogustlengthd_CSTATE ; }
XDot_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T ; typedef struct {
boolean_T DistanceintoGustxLimitedtogustlengthd_CSTATE ; }
XDis_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T ; typedef struct {
real_T B_51_0_0 [ 3 ] ; real_T B_51_13_0 [ 3 ] ; real_T B_51_35_0 [ 3 ] ;
real_T B_51_46_0 [ 4 ] ; real_T B_51_60_0 [ 3 ] ; real_T B_51_61_0 [ 3 ] ;
real_T B_51_63_0 ; real_T B_51_67_0 ; real_T B_51_69_0 [ 3 ] ; real_T
B_51_72_0 [ 3 ] ; real_T B_51_75_0 ; real_T B_51_82_0 ; real_T B_51_85_0 ;
real_T B_51_92_0 ; real_T B_51_105_0 ; real_T B_51_106_0 ; real_T B_51_107_0
; real_T B_51_108_0 ; real_T B_51_110_0 ; real_T B_51_111_0 [ 3 ] ; real_T
B_51_114_0 [ 3 ] ; real_T B_51_116_0 ; real_T B_51_117_0 ; real_T B_51_118_0
; real_T B_51_119_0 ; real_T B_51_120_0 ; real_T B_51_146_0 [ 3 ] ; real_T
B_51_147_0 ; real_T B_51_148_0 ; real_T B_51_199_0 ; real_T B_51_248_0 [ 3 ]
; real_T B_51_249_0 ; real_T B_51_250_0 ; real_T B_51_251_0 ; real_T
B_51_255_0 ; real_T B_51_256_0 ; real_T B_51_259_0 ; real_T B_51_260_0 ;
real_T B_51_261_0 ; real_T B_51_312_0 ; real_T B_51_364_0 [ 3 ] ; real_T
B_51_365_0 ; real_T B_51_366_0 ; real_T B_51_371_0 ; real_T B_51_375_0 ;
real_T B_51_376_0 ; real_T B_51_377_0 ; real_T B_51_428_0 ; real_T B_51_480_0
[ 3 ] ; real_T B_51_481_0 ; real_T B_51_482_0 ; real_T B_51_487_0 ; real_T
B_51_491_0 ; real_T B_51_492_0 ; real_T B_51_497_0 ; real_T B_51_499_0 ;
real_T B_51_502_0 ; real_T B_51_504_0 ; real_T B_51_506_0 ; real_T B_51_556_0
[ 3 ] ; real_T B_51_558_0 ; real_T B_51_560_0 ; real_T B_51_562_0 ; real_T
B_51_564_0 ; real_T B_51_614_0 [ 3 ] ; real_T B_51_616_0 ; real_T B_51_618_0
; real_T B_51_620_0 ; real_T B_51_622_0 ; real_T B_51_672_0 [ 3 ] ; real_T
B_51_673_0 [ 3 ] ; real_T B_51_683_0 [ 3 ] ; real_T B_51_685_0 [ 3 ] ; real_T
B_51_690_0 [ 3 ] ; real_T B_51_691_0 ; real_T B_51_697_0 [ 3 ] ; real_T
B_51_703_0 ; real_T B_51_707_0 ; real_T B_51_728_0 ; real_T B_51_732_0 ;
real_T B_51_734_0 ; real_T B_51_736_0 ; real_T B_51_738_0 ; real_T B_51_740_0
; real_T B_51_741_0 ; real_T B_51_742_0 ; real_T B_51_743_0 ; real_T
B_51_744_0 ; real_T B_51_746_0 ; real_T B_51_747_0 ; real_T B_51_748_0 ;
real_T B_51_749_0 ; real_T B_51_750_0 ; real_T B_51_751_0 ; real_T B_51_752_0
; real_T B_51_754_0 ; real_T B_51_755_0 ; real_T B_51_757_0 ; real_T
B_51_758_0 ; real_T B_51_760_0 ; real_T B_51_761_0 ; real_T B_51_762_0 ;
real_T B_51_764_0 ; real_T B_51_767_0 ; real_T B_51_768_0 ; real_T B_51_772_0
; real_T B_51_773_0 ; real_T B_51_775_0 ; real_T B_51_776_0 ; real_T
B_51_777_0 ; real_T B_51_781_0 ; real_T B_51_782_0 ; real_T B_51_783_0 ;
real_T B_51_784_0 ; real_T B_51_786_0 ; real_T B_51_787_0 ; real_T B_51_789_0
; real_T B_51_791_0 ; real_T B_51_792_0 ; real_T B_51_793_0 ; real_T
B_51_794_0 ; real_T B_51_795_0 ; real_T B_51_796_0 ; real_T B_51_802_0 ;
real_T B_51_803_0 ; real_T B_51_804_0 ; real_T B_51_806_0 ; real_T B_51_808_0
; real_T B_51_809_0 ; real_T B_51_810_0 ; real_T B_51_812_0 ; real_T
B_51_813_0 ; real_T B_51_814_0 ; real_T B_51_817_0 ; real_T B_51_818_0 ;
real_T B_51_824_0 ; real_T B_51_827_0 ; real_T B_51_828_0 ; real_T B_51_834_0
; real_T B_51_837_0 ; real_T B_51_838_0 ; real_T B_51_844_0 ; real_T
B_51_845_0 ; real_T B_51_847_0 ; real_T B_51_849_0 ; real_T B_51_850_0 ;
real_T B_51_851_0 ; real_T B_51_855_0 ; real_T B_51_857_0 ; real_T B_51_858_0
; real_T B_51_859_0 ; real_T B_51_863_0 ; real_T B_51_865_0 ; real_T
B_51_866_0 ; real_T B_51_867_0 ; real_T B_51_871_0 ; real_T B_51_873_0 ;
real_T B_51_874_0 ; real_T B_51_875_0 ; real_T B_51_881_0 ; real_T B_51_883_0
; real_T B_51_884_0 ; real_T B_51_885_0 ; real_T B_51_891_0 ; real_T
B_51_893_0 ; real_T B_51_894_0 ; real_T B_51_895_0 ; real_T B_51_901_0 ;
real_T B_51_902_0 ; real_T B_51_903_0 ; real_T B_51_904_0 ; real_T B_51_906_0
; real_T B_51_907_0 ; real_T B_51_908_0 ; real_T B_51_909_0 ; real_T
B_51_910_0 ; real_T B_51_913_0 ; real_T B_51_914_0 ; real_T B_51_914_1 ;
real_T B_51_914_2 ; real_T B_51_914_3 ; real_T B_51_914_4 ; real_T B_51_914_5
; real_T B_51_914_6 [ 3 ] ; real_T B_51_917_0 ; real_T B_51_918_0 ; real_T
B_51_919_0 ; real_T B_51_920_0 ; real_T B_51_923_0 [ 3 ] ; real_T B_51_932_0
[ 3 ] ; real_T B_51_943_0 [ 3 ] ; real_T B_51_945_0 [ 3 ] ; real_T B_51_947_0
[ 3 ] ; real_T B_51_951_0 [ 3 ] ; real_T B_51_961_0 ; real_T B_51_968_0 ;
real_T B_51_1044_0 ; real_T B_51_1101_0 ; real_T B_51_1157_0 ; real_T
B_51_1183_0 [ 3 ] ; real_T B_51_1184_0 ; real_T B_51_1185_0 ; real_T
B_51_1187_0 ; real_T B_51_1188_0 ; real_T B_51_1190_0 ; real_T B_51_1191_0 ;
real_T B_51_1198_0 ; real_T B_51_1199_0 ; real_T B_51_1201_0 ; real_T
B_51_1202_0 ; real_T B_51_1204_0 ; real_T B_51_1205_0 ; real_T B_51_1208_0 ;
real_T B_51_1210_0 ; real_T B_51_1214_0 ; real_T B_51_1216_0 ; real_T
B_51_1218_0 ; real_T B_51_1219_0 ; real_T B_51_1220_0 ; real_T B_51_1225_0 ;
real_T B_51_1231_0 ; real_T B_51_1235_0 ; real_T B_51_1236_0 ; real_T
B_51_1237_0 ; real_T B_51_1238_0 ; real_T B_51_1239_0 ; real_T B_51_1240_0 ;
real_T B_51_1241_0 ; real_T B_51_1243_0 ; real_T B_51_1244_0 ; real_T
B_51_1245_0 ; real_T B_51_1246_0 ; real_T B_51_3_0 [ 9 ] ; real_T B_51_4_0 [
9 ] ; real_T B_51_5_0 [ 9 ] ; real_T B_51_6_0 ; real_T B_51_7_0 ; real_T
B_51_8_0 ; real_T B_51_10_0 ; real_T B_51_12_0 ; real_T B_51_13_0_m ; real_T
B_51_15_0 ; real_T B_51_17_0 ; real_T B_51_19_0 ; real_T B_51_21_0 ; real_T
B_51_23_0 ; real_T B_51_25_0 ; real_T B_51_26_0 ; real_T B_51_28_0 ; real_T
B_51_30_0 [ 126 ] ; real_T B_51_32_0 ; real_T B_51_33_0 ; real_T B_51_34_0 ;
real_T B_51_35_0_c ; real_T B_51_36_0 ; real_T B_51_37_0 ; real_T B_51_38_0 ;
real_T B_51_39_0 ; real_T B_51_40_0 ; real_T B_51_41_0 ; real_T B_51_42_0 ;
real_T B_51_43_0 ; real_T B_51_44_0 ; real_T B_51_45_0 ; real_T B_51_46_0_k ;
real_T B_51_47_0 ; real_T B_51_48_0 ; real_T B_51_49_0 ; real_T B_51_50_0 ;
real_T B_51_51_0 ; real_T B_51_52_0 ; real_T B_51_53_0 ; real_T B_51_54_0 ;
real_T B_51_55_0 ; real_T B_51_56_0 ; real_T B_51_57_0 ; real_T B_51_58_0 ;
real_T B_51_59_0 ; real_T B_51_60_0_c [ 4 ] ; real_T B_51_62_0 ; real_T
B_51_63_0_b [ 4 ] ; real_T B_51_65_0 ; real_T B_51_66_0 [ 4 ] ; real_T
B_51_68_0 ; real_T B_51_69_0_p ; real_T B_51_70_0 [ 3 ] ; real_T B_51_71_0 [
3 ] ; real_T B_51_73_0 ; real_T B_51_74_0 [ 3 ] ; real_T B_51_75_0_c ; real_T
B_51_76_0 ; real_T B_51_77_0 ; real_T B_51_78_0 ; real_T B_51_79_0 ; real_T
B_51_81_0 ; real_T B_51_82_0_f ; real_T B_51_83_0 ; real_T B_51_84_0 ; real_T
B_51_87_0 ; real_T B_51_89_0 ; real_T B_51_93_0 ; real_T B_51_95_0 ; real_T
B_51_99_1 ; real_T B_51_106_0_g [ 4 ] ; real_T B_51_111_0_g [ 3 ] ; real_T
B_51_113_0 ; real_T B_51_114_0_m [ 3 ] ; real_T B_51_116_0_n ; real_T
B_51_117_0_p ; real_T B_51_118_0_l ; real_T B_51_119_0_j ; real_T
B_51_120_0_d ; real_T B_51_121_0 ; real_T B_51_122_0 ; real_T B_51_123_0 ;
real_T B_51_124_0 ; real_T B_51_125_0 [ 3 ] ; real_T B_51_126_0 [ 3 ] ;
real_T B_51_127_0 ; real_T B_51_128_0 ; real_T B_51_129_0 ; real_T B_51_130_0
; real_T B_51_131_0 ; real_T B_51_132_0 ; real_T B_51_133_0 ; real_T
B_51_134_0 ; real_T B_51_135_0 [ 3 ] ; real_T B_51_136_0 ; real_T B_51_137_0
; real_T B_51_138_0 ; real_T B_51_139_0 ; real_T B_51_140_0 ; real_T
B_51_141_0 [ 3 ] ; real_T B_51_143_0 ; real_T B_51_144_0 ; real_T B_51_145_0
; real_T B_51_146_0_g ; real_T B_51_147_0_l ; real_T B_51_148_0_d ; real_T
B_51_153_0 ; real_T B_51_154_0 ; real_T B_51_158_0 ; real_T B_51_159_0 ;
real_T B_51_160_0 ; real_T B_51_161_0 ; real_T B_51_162_0 ; real_T B_51_163_0
; real_T B_51_164_0 ; real_T B_51_165_0 ; real_T B_51_166_0 ; real_T
B_51_167_0 ; real_T B_51_168_0 ; real_T B_51_169_0 ; real_T B_51_170_0 ;
real_T B_51_171_0 ; real_T B_51_172_0 ; real_T B_51_173_0 ; real_T B_51_174_0
; real_T B_51_175_0 ; real_T B_51_177_0 ; real_T B_51_178_0 ; real_T
B_51_179_0 [ 14 ] ; real_T B_51_180_0 [ 24 ] ; real_T B_51_181_0 [ 28 ] ;
real_T B_51_182_0 ; real_T B_51_184_0 ; real_T B_51_185_0 ; real_T B_51_188_0
; real_T B_51_189_0 ; real_T B_51_190_0 ; real_T B_51_191_0 ; real_T
B_51_193_0 ; real_T B_51_194_0 ; real_T B_51_195_0 ; real_T B_49_0_1 ; real_T
B_48_0_1 ; real_T B_47_0_1 ; real_T B_46_0_1 ; real_T B_45_2_0 ; real_T
B_45_6_0 ; real_T B_45_11_0 ; real_T B_45_15_0 ; real_T B_45_0_0 ; real_T
B_45_1_0 ; real_T B_45_2_0_d ; real_T B_45_3_0 ; real_T B_45_4_0 ; real_T
B_44_0_1 ; real_T B_43_0_1 ; real_T B_42_0_1 ; real_T B_41_0_1 ; real_T
B_40_0_1 ; real_T B_38_0_0 [ 6 ] ; real_T B_38_1_1 [ 3 ] ; real_T B_37_0_0 [
2 ] ; real_T B_37_1_1 ; real_T B_36_0_0 [ 2 ] ; real_T B_36_1_1 ; real_T
B_35_0_1 ; real_T B_34_0_1 ; real_T B_33_0_0 ; real_T B_33_2_0 ; real_T
B_30_0_0 ; real_T B_30_2_0 ; real_T B_27_6_0 [ 2 ] ; real_T B_27_9_0 [ 2 ] ;
real_T B_27_11_0 [ 2 ] ; real_T B_27_1_0 ; real_T B_26_6_0 [ 2 ] ; real_T
B_26_11_0 [ 2 ] ; real_T B_26_12_0 [ 2 ] ; real_T B_25_6_0 [ 2 ] ; real_T
B_25_7_0 [ 2 ] ; real_T B_24_4_0 [ 2 ] ; real_T B_23_4_0 [ 2 ] ; real_T
B_23_5_0 [ 2 ] ; real_T B_22_7_0 [ 2 ] ; real_T B_22_9_0 [ 2 ] ; real_T
B_22_0_0 ; real_T B_22_3_0 ; real_T B_22_4_0 ; real_T B_19_0_0 ; real_T
B_18_0_1 ; real_T B_18_0_2 ; real_T B_18_0_3 ; real_T B_17_0_1 ; real_T
B_17_0_2 ; real_T B_17_0_3 ; real_T B_16_0_1 ; real_T B_15_0_1 ; real_T
B_15_0_2 ; real_T B_14_0_1 ; real_T B_13_0_1 ; real_T B_13_0_2 ; real_T
B_12_0_1 ; real_T B_11_0_1 ; real_T B_11_0_2 ; real_T B_10_0_1 ; real_T
B_10_0_2 ; real_T B_9_0_1 [ 9 ] ; real_T B_8_0_0 [ 4 ] ; real_T B_8_1_1 ;
real_T B_7_0_0 [ 4 ] ; real_T B_7_1_1 ; real_T B_6_0_0 [ 4 ] ; real_T B_6_1_1
; real_T B_5_0_0 [ 4 ] ; real_T B_5_1_1 ; real_T B_4_0_0 [ 4 ] ; real_T
B_4_1_1 ; real_T B_3_0_1 [ 9 ] ; real_T B_2_0_0 [ 4 ] ; real_T B_2_1_1 ;
real_T B_1_0_0 [ 4 ] ; real_T B_1_1_1 ; real_T B_0_0_0 [ 4 ] ; real_T B_0_1_1
; uint32_T B_51_99_0 ; boolean_T B_51_23_0_l ; boolean_T B_51_25_0_o ;
boolean_T B_51_27_0 ; boolean_T B_51_964_0 ;
B_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogustz ;
B_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogusty ; }
B_v2022_Modello_SITL_AENEA_2020b_T ; typedef struct { real_T UnitDelay_DSTATE
; real_T Delay_DSTATE [ 2 ] ; real_T Delay1_DSTATE [ 2 ] ; real_T
Delay2_DSTATE [ 2 ] ; real_T Delay3_DSTATE [ 2 ] ; real_T NextOutput [ 4 ] ;
real_T Memory_PreviousInput ; real_T Memory1_PreviousInput ; real_T
Memory2_PreviousInput ; real_T NextOutput_l ; real_T NextOutput_m ; real_T
NextOutput_j ; real_T NextOutput_f ; real_T NextOutput_fh ; real_T
Memory2_PreviousInput_k ; real_T NextOutput_b ; real_T NextOutput_e ; real_T
NextOutput_mv ; real_T NextOutput_p ; real_T NextOutput_bz ; real_T
NextOutput_fy ; real_T NextOutput_o ; real_T NextOutput_a ; real_T
Product2_DWORK1 [ 9 ] ; real_T Product2_DWORK3 [ 9 ] ; real_T Product2_DWORK4
[ 9 ] ; real_T Product2_DWORK5 [ 9 ] ; real_T NextOutput_p2 ; real_T
NextOutput_p1 ; real_T NextOutput_me ; real_T NextOutput_bl ; real_T
NextOutput_n ; real_T NextOutput_a1 ; real_T RateTransition24_Buffer ; real_T
NextOutput_mr ; real_T RateTransition25_Buffer ; real_T NextOutput_o2 ;
real_T RateTransition26_Buffer ; real_T NextOutput_ej ; real_T
RateTransition27_Buffer ; struct { real_T modelTStart ; } Delay_gps_RWORK ;
struct { real_T modelTStart ; } Delay_gps_RWORK_i ; struct { real_T
modelTStart ; } Delay_bmp_RWORK ; struct { real_T modelTStart ; }
Delay_gps_RWORK_f ; struct { real_T modelTStart ; } Delay_gps1_RWORK ; struct
{ real_T modelTStart ; } Delay_ahrs1_RWORK ; struct { real_T modelTStart ; }
Delay_ahrs2_RWORK ; struct { real_T modelTStart ; } Delay_ahrs3_RWORK ;
struct { real_T modelTStart ; } Delay_ahrs_RWORK ; struct { real_T
modelTStart ; } Delay_ahrs5_RWORK ; struct { real_T modelTStart ; }
Delay_ahrs4_RWORK ; struct { real_T modelTStart ; } Delay_ahrs6_RWORK ;
struct { real_T modelTStart ; } Delay_ahrs7_RWORK ; struct { real_T
modelTStart ; } Delay_ahrs8_RWORK ; struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_BusSelector_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_BusSelector_at_outport_1_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_BusSelector_at_outport_10_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_BusSelector_at_outport_11_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_BusSelector_at_outport_12_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_BusSelector_at_outport_13_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_BusSelector_at_outport_14_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_BusSelector_at_outport_15_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_BusSelector_at_outport_16_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_BusSelector_at_outport_17_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_BusSelector_at_outport_18_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_BusSelector_at_outport_2_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_BusSelector_at_outport_3_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_BusSelector_at_outport_4_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_BusSelector_at_outport_5_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_BusSelector_at_outport_6_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_BusSelector_at_outport_7_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_BusSelector_at_outport_8_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_BusSelector_at_outport_9_PWORK ; struct { void *
AQHandles [ 24 ] ; } TAQSigLogging_InsertedFor_In1_at_outport_0_1_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_RadianstoDegrees1_at_outport_0_PWORK ; struct {
void * AQHandles ; }
TAQSigLogging_InsertedFor_RadianstoDegrees_at_outport_0_PWORK ; struct { void
* TUbufferPtrs [ 2 ] ; } Delay_gps_PWORK ; struct { void * TUbufferPtrs [ 2 ]
; } Delay_gps_PWORK_k ; struct { void * TUbufferPtrs [ 2 ] ; }
Delay_bmp_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; } Delay_gps_PWORK_l ;
struct { void * TUbufferPtrs [ 2 ] ; } Delay_gps1_PWORK ; struct { void *
TUbufferPtrs [ 2 ] ; } Delay_ahrs1_PWORK ; struct { void * TUbufferPtrs [ 2 ]
; } Delay_ahrs2_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
Delay_ahrs3_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; } Delay_ahrs_PWORK ;
struct { void * TUbufferPtrs [ 2 ] ; } Delay_ahrs5_PWORK ; struct { void *
TUbufferPtrs [ 2 ] ; } Delay_ahrs4_PWORK ; struct { void * TUbufferPtrs [ 2 ]
; } Delay_ahrs6_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
Delay_ahrs7_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; } Delay_ahrs8_PWORK
; void * Scope_PWORK ; void * Scope9_PWORK [ 2 ] ; struct { void * AQHandles
; } TAQSigLogging_InsertedFor_Propulsione1_at_outport_0_PWORK ; struct { void
* AQHandles ; }
TAQSigLogging_InsertedFor_SubsystemReference_at_outport_0_PWORK ; void *
Scope_PWORK_p ; void * Scope_PWORK_m ; struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_J_at_outport_0_PWORK ; struct { void * AQHandles ;
} TAQSigLogging_InsertedFor_MATLABFunction_at_outport_0_PWORK ; struct { void
* AQHandles ; } TAQSigLogging_InsertedFor_MATLABFunction_at_outport_1_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_RPM_at_outport_0_PWORK ; void * Scope_PWORK_b ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Fase_Ato_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_Subsystem1_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Subsystem1_at_outport_1_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_Subsystem2_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Subsystem2_at_outport_1_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_Subsystem_at_outport_0_PWORK ; struct
{ void * AQHandles ; } TAQSigLogging_InsertedFor_Subsystem_at_outport_1_PWORK
; struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_modoautopilota_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_selector_AL_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Integrator1_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_Integrator_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Sum2_at_outport_0_PWORK ; struct { void * AQHandles
; } TAQSigLogging_InsertedFor_hkmmolla_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_vcmdsmorzamento_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Sum1_at_outport_0_PWORK ; struct { void * AQHandles
; } TAQSigLogging_InsertedFor_hkmmolla_at_outport_0_PWORK_o ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_vcmdsmorzamento_at_outport_0_PWORK_f
; struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_hknmolla_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_vcndsmorzamento_at_outport_0_PWORK ;
void * Scope_PWORK_p4 ; void * Scope_PWORK_k ; void * Scope_PWORK_j ; void *
Scope_PWORK_mg [ 2 ] ; void * Scope1_PWORK [ 2 ] ; void * Scope2_PWORK [ 2 ]
; void * Scope4_PWORK [ 4 ] ; void * Scope_PWORK_n ; void * Scope1_PWORK_l ;
void * ToWorkspace_PWORK ; void * Scope_PWORK_pe [ 2 ] ; void *
ToWorkspace_PWORK_c ; void * ToWorkspace1_PWORK ; void * ToWorkspace2_PWORK ;
void * ToWorkspace5_PWORK ; void * ToWorkspace6_PWORK ; void *
ToWorkspace7_PWORK ; void * ToWorkspace9_PWORK ; struct { void * AQHandles ;
} TAQSigLogging_InsertedFor_RadianstoDegrees_at_outport_0_PWORK_d ; void *
Scope2_PWORK_g [ 2 ] ; void * Scope_PWORK_nc [ 2 ] ; void * Scope1_PWORK_h ;
void * Scope3_PWORK ; void * Scope4_PWORK_p ; int32_T Product2_DWORK2 [ 3 ] ;
int32_T TmpAtomicSubsysAtSwitch3Inport1_sysIdxToRun ; int32_T
u2piWrapper_sysIdxToRun ; int32_T CorrezionePSI_sysIdxToRun ; int32_T
MATLABFunction3_sysIdxToRun ; int32_T MATLABFunction1_sysIdxToRun ; int32_T
Subsystem1_sysIdxToRun ; int32_T Chart2_sysIdxToRun ; int32_T
Chart1_sysIdxToRun ; int32_T Chart5_sysIdxToRun ; int32_T Chart4_sysIdxToRun
; int32_T Chart2_sysIdxToRun_h ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
MATLABFunction_sysIdxToRun ; int32_T controllodivisioneper0subeta_sysIdxToRun
; int32_T controllodivisioneper0sualpha_sysIdxToRun ; int32_T
MATLABFunction1_sysIdxToRun_o ; int32_T MATLABFunction_sysIdxToRun_b ;
int32_T Interpolatevelocities_sysIdxToRun ; int32_T
MediumHighaltitudevelocities_sysIdxToRun ; int32_T
Lowaltitudevelocities_sysIdxToRun ; int32_T Interpolaterates_sysIdxToRun ;
int32_T MediumHighaltituderates_sysIdxToRun ; int32_T
Lowaltituderates_sysIdxToRun ; int32_T Hwgws_sysIdxToRun ; int32_T
Hvgws_sysIdxToRun ; int32_T Hugws_sysIdxToRun ; int32_T Hrgw_sysIdxToRun ;
int32_T Hqgw_sysIdxToRun ; int32_T Hpgw_sysIdxToRun ; int32_T
Distanceintogustx_sysIdxToRun ; int32_T new_ATO_sysIdxToRun ; int32_T
new_AL_sysIdxToRun ; int32_T MATLABFunction3_sysIdxToRun_c ; int32_T
MATLABFunction1_sysIdxToRun_c ; int32_T MATLABFunction3_sysIdxToRun_h ;
int32_T MATLABFunction1_sysIdxToRun_cc ; int32_T
MATLABFunction3_sysIdxToRun_e ; int32_T MATLABFunction1_sysIdxToRun_b ;
int32_T MATLABFunction_sysIdxToRun_o ; int32_T MATLABFunction_sysIdxToRun_m ;
int32_T controllodivisioneperzeronr_sysIdxToRun ; int32_T
controllodivisioneperzeronp_sysIdxToRun ; int32_T
controllodivisioneperzeromq_sysIdxToRun ; int32_T
controllodivisioneperzerolr_sysIdxToRun ; int32_T
controllodivisioneperzerolp_sysIdxToRun ; int32_T
MATLABFunction_sysIdxToRun_d ; int32_T
controllodivisioneperzeroLq_sysIdxToRun ; int32_T
controllodivisioneperzeroYr_sysIdxToRun ; int32_T
controllodivisioneperzeroYp_sysIdxToRun ; uint32_T
PreLookUpIndexSearchaltitude_DWORK1 ; uint32_T RandSeed [ 4 ] ; uint32_T
RandSeed_e ; uint32_T RandSeed_b ; uint32_T RandSeed_g ; uint32_T RandSeed_ec
; uint32_T RandSeed_m ; uint32_T RandSeed_a ; uint32_T RandSeed_gc ; uint32_T
RandSeed_n ; uint32_T RandSeed_k ; uint32_T RandSeed_mj ; uint32_T
RandSeed_mf ; uint32_T RandSeed_h ; uint32_T RandSeed_l ; uint32_T RandSeed_c
; uint32_T RandSeed_p ; uint32_T RandSeed_pa ; uint32_T RandSeed_d ; uint32_T
RandSeed_hk ; uint32_T RandSeed_f ; uint32_T RandSeed_gu ; uint32_T
RandSeed_d3 ; uint32_T RandSeed_p0 ; uint32_T
PreLookUpIndexSearchprobofexceed_DWORK1 ; int_T Integrator_IWORK ; int_T
Integrator1_IWORK ; int_T Integrator_IWORK_d ; int_T Integrator1_IWORK_n ;
int_T Integrator_IWORK_g ; int_T Integrator1_IWORK_f ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
Delay_gps_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } Delay_gps_IWORK_b ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } Delay_bmp_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } Delay_gps_IWORK_l ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } Delay_gps1_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } Delay_ahrs1_IWORK ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } Delay_ahrs2_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } Delay_ahrs3_IWORK ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } Delay_ahrs_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } Delay_ahrs5_IWORK ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } Delay_ahrs4_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } Delay_ahrs6_IWORK ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } Delay_ahrs7_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } Delay_ahrs8_IWORK ; int8_T
ifHeightMaxlowaltitudeelseifHeightMinisotropicaltitude_ActiveSubsystem ;
int8_T
ifHeightMaxlowaltitudeelseifHeightMinisotropicaltitude_ActiveSubsystem_d ;
int8_T Interpolatevelocities_SubsysRanBC ; int8_T
MediumHighaltitudevelocities_SubsysRanBC ; int8_T
Lowaltitudevelocities_SubsysRanBC ; int8_T Interpolaterates_SubsysRanBC ;
int8_T MediumHighaltituderates_SubsysRanBC ; int8_T
Lowaltituderates_SubsysRanBC ; int8_T Hwgws_SubsysRanBC ; int8_T
Hvgws_SubsysRanBC ; int8_T Hugws_SubsysRanBC ; int8_T Hrgw_SubsysRanBC ;
int8_T Hqgw_SubsysRanBC ; int8_T Hpgw_SubsysRanBC ; int8_T
Distanceintogustx_SubsysRanBC ; boolean_T Hwgws_MODE ; boolean_T Hvgws_MODE ;
boolean_T Hugws_MODE ; boolean_T Hrgw_MODE ; boolean_T Hqgw_MODE ; boolean_T
Hpgw_MODE ; boolean_T Distanceintogustx_MODE ; char_T
pad_Distanceintogustx_MODE [ 2 ] ;
DW_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogustz ;
DW_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogusty ; }
DW_v2022_Modello_SITL_AENEA_2020b_T ; typedef struct { real_T
phithetapsi_CSTATE [ 3 ] ; real_T xeyeze_CSTATE [ 3 ] ; real_T ubvbwb_CSTATE
[ 3 ] ; real_T pqr_CSTATE [ 3 ] ; real_T StateSpace2_CSTATE ; real_T
StateSpace1_CSTATE ; real_T StateSpace_CSTATE ; real_T Integrator_CSTATE ;
real_T Integrator1_CSTATE ; real_T Integrator_CSTATE_m ; real_T
Integrator1_CSTATE_a ; real_T Integrator_CSTATE_md ; real_T
Integrator1_CSTATE_n ; real_T PositionIntegrator2_CSTATE [ 3 ] ; real_T
Integrator_CSTATE_j ; real_T Integrator_CSTATE_k ; real_T Integrator2_CSTATE
; real_T Integrator1_CSTATE_h ; real_T Integrator_CSTATE_d ; real_T
wg_p1_CSTATE [ 2 ] ; real_T wg_p2_CSTATE [ 2 ] ; real_T vg_p1_CSTATE [ 2 ] ;
real_T vgw_p2_CSTATE [ 2 ] ; real_T ug_p_CSTATE [ 2 ] ; real_T rgw_p_CSTATE [
2 ] ; real_T qgw_p_CSTATE [ 2 ] ; real_T pgw_p_CSTATE [ 2 ] ;
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogustz ;
X_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogusty ;
real_T DistanceintoGustxLimitedtogustlengthd_CSTATE_f ; }
X_v2022_Modello_SITL_AENEA_2020b_T ; typedef int_T
PeriodicIndX_v2022_Modello_SITL_AENEA_2020b_T [ 3 ] ; typedef real_T
PeriodicRngX_v2022_Modello_SITL_AENEA_2020b_T [ 6 ] ; typedef struct { real_T
phithetapsi_CSTATE [ 3 ] ; real_T xeyeze_CSTATE [ 3 ] ; real_T ubvbwb_CSTATE
[ 3 ] ; real_T pqr_CSTATE [ 3 ] ; real_T StateSpace2_CSTATE ; real_T
StateSpace1_CSTATE ; real_T StateSpace_CSTATE ; real_T Integrator_CSTATE ;
real_T Integrator1_CSTATE ; real_T Integrator_CSTATE_m ; real_T
Integrator1_CSTATE_a ; real_T Integrator_CSTATE_md ; real_T
Integrator1_CSTATE_n ; real_T PositionIntegrator2_CSTATE [ 3 ] ; real_T
Integrator_CSTATE_j ; real_T Integrator_CSTATE_k ; real_T Integrator2_CSTATE
; real_T Integrator1_CSTATE_h ; real_T Integrator_CSTATE_d ; real_T
wg_p1_CSTATE [ 2 ] ; real_T wg_p2_CSTATE [ 2 ] ; real_T vg_p1_CSTATE [ 2 ] ;
real_T vgw_p2_CSTATE [ 2 ] ; real_T ug_p_CSTATE [ 2 ] ; real_T rgw_p_CSTATE [
2 ] ; real_T qgw_p_CSTATE [ 2 ] ; real_T pgw_p_CSTATE [ 2 ] ;
XDot_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogustz ;
XDot_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogusty ;
real_T DistanceintoGustxLimitedtogustlengthd_CSTATE_f ; }
XDot_v2022_Modello_SITL_AENEA_2020b_T ; typedef struct { boolean_T
phithetapsi_CSTATE [ 3 ] ; boolean_T xeyeze_CSTATE [ 3 ] ; boolean_T
ubvbwb_CSTATE [ 3 ] ; boolean_T pqr_CSTATE [ 3 ] ; boolean_T
StateSpace2_CSTATE ; boolean_T StateSpace1_CSTATE ; boolean_T
StateSpace_CSTATE ; boolean_T Integrator_CSTATE ; boolean_T
Integrator1_CSTATE ; boolean_T Integrator_CSTATE_m ; boolean_T
Integrator1_CSTATE_a ; boolean_T Integrator_CSTATE_md ; boolean_T
Integrator1_CSTATE_n ; boolean_T PositionIntegrator2_CSTATE [ 3 ] ; boolean_T
Integrator_CSTATE_j ; boolean_T Integrator_CSTATE_k ; boolean_T
Integrator2_CSTATE ; boolean_T Integrator1_CSTATE_h ; boolean_T
Integrator_CSTATE_d ; boolean_T wg_p1_CSTATE [ 2 ] ; boolean_T wg_p2_CSTATE [
2 ] ; boolean_T vg_p1_CSTATE [ 2 ] ; boolean_T vgw_p2_CSTATE [ 2 ] ;
boolean_T ug_p_CSTATE [ 2 ] ; boolean_T rgw_p_CSTATE [ 2 ] ; boolean_T
qgw_p_CSTATE [ 2 ] ; boolean_T pgw_p_CSTATE [ 2 ] ;
XDis_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogustz ;
XDis_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogusty ;
boolean_T DistanceintoGustxLimitedtogustlengthd_CSTATE_f ; }
XDis_v2022_Modello_SITL_AENEA_2020b_T ; typedef struct { ZCSigState
Integrator_Reset_ZCE ; ZCSigState Integrator1_Reset_ZCE ; ZCSigState
Integrator_Reset_ZCE_f ; ZCSigState Integrator1_Reset_ZCE_e ; ZCSigState
Integrator_Reset_ZCE_p ; ZCSigState Integrator1_Reset_ZCE_el ; ZCSigState
autopilota_v_15_last_Input_ZCE ; ZCSigState autopilota_v_15_last_Trig_ZCE ;
ZCSigState autopilota_v_15_last_Trig_ZCE_n ; ZCSigState
autopilota_v_15_last_Trig_ZCE_nx ; ZCSigState autopilota_v_15_last_Reset_ZCE
; ZCSigState autopilota_v_15_last_Reset_ZCE_j ; ZCSigState
autopilota_v_15_last_Reset_ZCE_jd ; ZCSigState
autopilota_v_15_last_Reset_ZCE_jdz ; ZCSigState
autopilota_v_15_last_Reset_ZCE_jdzw ; ZCSigState
autopilota_v_15_last_Trig_ZCE_nxz ; }
PrevZCX_v2022_Modello_SITL_AENEA_2020b_T ; struct
P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T_ { real_T P_0 ; real_T
P_1 ; real_T P_2 ; real_T P_3 ; } ; struct
P_v2022_Modello_SITL_AENEA_2020b_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ;
real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ;
real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T
P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ;
real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T
P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ;
real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T
P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ;
real_T P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 ; real_T
P_47 ; real_T P_48 [ 3 ] ; real_T P_49 ; real_T P_50 ; real_T P_51 [ 3 ] ;
real_T P_52 ; real_T P_53 ; real_T P_54 ; real_T P_55 [ 3 ] ; real_T P_56 [ 3
] ; real_T P_57 [ 3 ] ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61
; real_T P_62 [ 12 ] ; real_T P_63 [ 84 ] ; real_T P_64 ; real_T P_65 ;
real_T P_66 [ 4 ] ; real_T P_67 ; real_T P_68 ; real_T P_69 ; real_T P_70 [ 3
] ; real_T P_71 [ 91 ] ; real_T P_72 [ 13 ] ; real_T P_73 [ 7 ] ; real_T P_74
; real_T P_75 [ 91 ] ; real_T P_76 [ 13 ] ; real_T P_77 [ 7 ] ; real_T P_78 ;
real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T P_83 ; real_T
P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ; real_T P_89 ;
real_T P_90 ; real_T P_91 ; real_T P_92 [ 91 ] ; real_T P_93 [ 13 ] ; real_T
P_94 [ 7 ] ; real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ; real_T
P_99 ; real_T P_100 ; real_T P_101 ; real_T P_102 ; real_T P_103 ; real_T
P_104 ; real_T P_105 ; real_T P_106 ; real_T P_107 ; real_T P_108 ; real_T
P_109 [ 91 ] ; real_T P_110 [ 13 ] ; real_T P_111 [ 7 ] ; real_T P_112 ;
real_T P_113 [ 91 ] ; real_T P_114 [ 13 ] ; real_T P_115 [ 7 ] ; real_T P_116
; real_T P_117 [ 91 ] ; real_T P_118 [ 13 ] ; real_T P_119 [ 7 ] ; real_T
P_120 ; real_T P_121 ; real_T P_122 ; real_T P_123 ; real_T P_124 ; real_T
P_125 ; real_T P_126 ; real_T P_127 ; real_T P_128 ; real_T P_129 ; real_T
P_130 ; real_T P_131 ; real_T P_132 ; real_T P_133 ; real_T P_134 ; real_T
P_135 ; real_T P_136 ; real_T P_137 ; real_T P_138 ; real_T P_139 ; real_T
P_140 ; real_T P_141 ; real_T P_142 ; real_T P_143 ; real_T P_144 ; real_T
P_145 ; real_T P_146 ; real_T P_147 ; real_T P_148 ; real_T P_149 ; real_T
P_150 ; real_T P_151 ; real_T P_152 ; real_T P_153 ; real_T P_154 ; real_T
P_155 ; real_T P_156 ; real_T P_157 ; real_T P_158 [ 3 ] ; real_T P_159 ;
real_T P_160 ; real_T P_161 ; real_T P_162 ; real_T P_163 ; real_T P_164 ;
real_T P_165 ; real_T P_166 ; real_T P_167 ; real_T P_168 ; real_T P_169 ;
real_T P_170 ; real_T P_171 ; real_T P_172 ; real_T P_173 ; real_T P_174 ;
real_T P_175 ; real_T P_176 ; real_T P_177 ; real_T P_178 ; real_T P_179 ;
real_T P_180 ; real_T P_181 ; real_T P_182 ; real_T P_183 ; real_T P_184 ;
real_T P_185 ; real_T P_186 ; real_T P_187 ; real_T P_188 ; real_T P_189 ;
real_T P_190 ; real_T P_191 ; real_T P_192 ; real_T P_193 ; real_T P_194 ;
real_T P_195 ; real_T P_196 ; real_T P_197 ; real_T P_198 ; real_T P_199 ;
real_T P_200 ; real_T P_201 ; real_T P_202 ; real_T P_203 ; real_T P_204 ;
real_T P_205 ; real_T P_206 ; real_T P_207 ; real_T P_208 ; real_T P_209 ;
real_T P_210 ; real_T P_211 ; real_T P_212 ; real_T P_213 ; real_T P_214 ;
real_T P_215 ; real_T P_216 ; real_T P_217 ; real_T P_218 ; real_T P_219 ;
real_T P_220 ; real_T P_221 ; real_T P_222 ; real_T P_223 ; real_T P_224 ;
real_T P_225 ; real_T P_226 ; real_T P_227 ; real_T P_228 ; real_T P_229 ;
real_T P_230 ; real_T P_231 ; real_T P_232 ; real_T P_233 ; real_T P_234 ;
real_T P_235 ; real_T P_236 ; real_T P_237 ; real_T P_238 ; real_T P_239 ;
real_T P_240 ; real_T P_241 ; real_T P_242 ; real_T P_243 ; real_T P_244 ;
real_T P_245 ; real_T P_246 ; real_T P_247 ; real_T P_248 ; real_T P_249 ;
real_T P_250 ; real_T P_251 ; real_T P_252 ; real_T P_253 ; real_T P_254 ;
real_T P_255 ; real_T P_256 ; real_T P_257 ; real_T P_258 ; real_T P_259 ;
real_T P_260 ; real_T P_261 ; real_T P_262 ; real_T P_263 ; real_T P_264 ;
real_T P_265 ; real_T P_266 ; real_T P_267 ; real_T P_268 ; real_T P_269 ;
real_T P_270 ; real_T P_271 ; real_T P_272 ; real_T P_273 ; real_T P_274 ;
real_T P_275 ; real_T P_276 ; real_T P_277 ; real_T P_278 ; real_T P_279 ;
real_T P_280 ; real_T P_281 ; real_T P_282 ; real_T P_283 ; real_T P_284 ;
real_T P_285 ; real_T P_286 ; real_T P_287 ; real_T P_288 ; real_T P_289 ;
real_T P_290 ; real_T P_291 ; real_T P_292 ; real_T P_293 ; real_T P_294 ;
real_T P_295 ; real_T P_296 ; real_T P_297 ; real_T P_298 ; real_T P_299 [ 18
] ; real_T P_300 [ 11 ] ; real_T P_301 [ 3 ] ; real_T P_302 ; real_T P_303 ;
real_T P_304 ; real_T P_305 ; real_T P_306 ; real_T P_307 ; real_T P_308 ;
real_T P_309 ; real_T P_310 ; real_T P_311 ; real_T P_312 ; real_T P_313 ;
real_T P_314 [ 6 ] ; real_T P_315 ; real_T P_316 ; real_T P_317 ; real_T
P_318 ; real_T P_319 ; real_T P_320 ; real_T P_321 ; real_T P_322 ; real_T
P_323 ; real_T P_324 ; real_T P_325 ; real_T P_326 ; real_T P_327 ; real_T
P_328 ; real_T P_329 ; real_T P_330 ; real_T P_331 ; real_T P_332 ; real_T
P_333 ; real_T P_334 ; real_T P_335 ; real_T P_336 ; real_T P_337 ; real_T
P_338 ; real_T P_339 ; real_T P_340 ; real_T P_341 ; real_T P_342 ; real_T
P_343 ; real_T P_344 ; real_T P_345 ; real_T P_346 ; real_T P_347 ; real_T
P_348 ; real_T P_349 ; real_T P_350 ; real_T P_351 ; real_T P_352 ; real_T
P_353 ; real_T P_354 ; real_T P_355 ; real_T P_356 ; real_T P_357 ; real_T
P_358 ; real_T P_359 ; real_T P_360 ; real_T P_361 ; real_T P_362 ; real_T
P_363 ; real_T P_364 ; real_T P_365 ; real_T P_366 ; real_T P_367 ; real_T
P_368 ; real_T P_369 ; real_T P_370 ; real_T P_371 ; real_T P_372 ; real_T
P_373 ; real_T P_374 ; real_T P_375 ; real_T P_376 ; real_T P_377 ; real_T
P_378 ; real_T P_379 ; real_T P_380 ; real_T P_381 ; real_T P_382 ; real_T
P_383 ; real_T P_384 ; real_T P_385 ; real_T P_386 ; real_T P_387 [ 9 ] ;
real_T P_388 [ 9 ] ; real_T P_389 ; real_T P_390 ; real_T P_391 ; real_T
P_392 ; real_T P_393 ; real_T P_394 ; real_T P_395 ; real_T P_396 ; real_T
P_397 ; real_T P_398 ; real_T P_399 ; real_T P_400 ; real_T P_401 ; real_T
P_402 ; real_T P_403 ; real_T P_404 ; real_T P_405 [ 126 ] ; real_T P_406 ;
real_T P_407 ; real_T P_408 ; real_T P_409 ; real_T P_410 ; real_T P_411 ;
real_T P_412 ; real_T P_413 ; real_T P_414 ; real_T P_415 ; real_T P_416 ;
real_T P_417 ; real_T P_418 ; real_T P_419 ; real_T P_420 ; real_T P_421 ;
real_T P_422 ; real_T P_423 ; real_T P_424 ; real_T P_425 ; real_T P_426 ;
real_T P_427 ; real_T P_428 ; real_T P_429 ; real_T P_430 ; real_T P_431 ;
real_T P_432 [ 4 ] ; real_T P_433 ; real_T P_434 [ 4 ] ; real_T P_435 ;
real_T P_436 [ 4 ] ; real_T P_437 ; real_T P_438 ; real_T P_439 [ 3 ] ;
real_T P_440 [ 3 ] ; real_T P_441 ; real_T P_442 [ 3 ] ; real_T P_443 ;
real_T P_444 ; real_T P_445 ; real_T P_446 ; real_T P_447 ; real_T P_448 ;
real_T P_449 ; real_T P_450 ; real_T P_451 ; real_T P_452 ; real_T P_453 ;
real_T P_454 ; real_T P_455 ; real_T P_456 ; real_T P_457 ; real_T P_458 [ 7
] ; real_T P_459 [ 4 ] ; real_T P_460 ; real_T P_461 ; real_T P_462 ; real_T
P_463 ; real_T P_464 ; real_T P_465 [ 3 ] ; real_T P_466 ; real_T P_467 ;
real_T P_468 ; real_T P_469 ; real_T P_470 ; real_T P_471 ; real_T P_472 ;
real_T P_473 ; real_T P_474 ; real_T P_475 [ 3 ] ; real_T P_476 [ 3 ] ;
real_T P_477 ; real_T P_478 ; real_T P_479 ; real_T P_480 ; real_T P_481 ;
real_T P_482 ; real_T P_483 ; real_T P_484 ; real_T P_485 [ 3 ] ; real_T
P_486 ; real_T P_487 ; real_T P_488 ; real_T P_489 ; real_T P_490 ; real_T
P_491 [ 3 ] ; real_T P_492 ; real_T P_493 ; real_T P_494 ; real_T P_495 ;
real_T P_496 ; real_T P_497 ; real_T P_498 ; real_T P_499 ; real_T P_500 ;
real_T P_501 ; real_T P_502 ; real_T P_503 ; real_T P_504 ; real_T P_505 ;
real_T P_506 ; real_T P_507 ; real_T P_508 ; real_T P_509 ; real_T P_510 ;
real_T P_511 ; real_T P_512 ; real_T P_513 ; real_T P_514 ; real_T P_515 ;
real_T P_516 ; real_T P_517 ; real_T P_518 ; real_T P_519 ; real_T P_520 ;
real_T P_521 ; real_T P_522 ; real_T P_523 ; real_T P_524 [ 14 ] ; real_T
P_525 [ 24 ] ; real_T P_526 [ 28 ] ; real_T P_527 ; real_T P_528 ; real_T
P_529 ; real_T P_530 ; real_T P_531 ; real_T P_532 ; real_T P_533 ; real_T
P_534 ; real_T P_535 ; real_T P_536 ; real_T P_537 ; real32_T P_538 ;
real32_T P_539 ; real32_T P_540 ; real32_T P_541 ; real32_T P_542 ; real32_T
P_543 ; real32_T P_544 ; real32_T P_545 ; real32_T P_546 ; real32_T P_547 ;
real32_T P_548 ; real32_T P_549 ; uint32_T P_550 [ 2 ] ; uint32_T P_551 [ 2 ]
; uint32_T P_552 [ 2 ] ; uint32_T P_553 [ 2 ] ; uint32_T P_554 [ 2 ] ;
uint32_T P_555 [ 2 ] ; uint32_T P_556 [ 2 ] ; uint8_T P_557 ; uint8_T P_558 ;
uint8_T P_559 ; uint8_T P_560 ; uint8_T P_561 ; uint8_T P_562 ; uint8_T P_563
; uint8_T P_564 ; uint8_T P_565 ; uint8_T P_566 ; uint8_T P_567 ; uint8_T
P_568 ; uint8_T P_569 ; char_T pad_P_569 [ 3 ] ;
P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogustz ;
P_Distanceintogusty_v2022_Modello_SITL_AENEA_2020b_T Distanceintogusty ; } ;
extern P_v2022_Modello_SITL_AENEA_2020b_T
v2022_Modello_SITL_AENEA_2020b_DefaultP ;
#endif
