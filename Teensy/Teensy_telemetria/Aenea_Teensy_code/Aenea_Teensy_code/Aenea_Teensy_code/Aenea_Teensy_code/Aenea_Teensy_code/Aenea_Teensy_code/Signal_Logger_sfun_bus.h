/* Generated by S-function Builder */
#ifndef _SIGNAL_LOGGER_SFUN_BUS_H_
#define _SIGNAL_LOGGER_SFUN_BUS_H_
/* Read only - STARTS */
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif




#ifndef _DEFINED_TYPEDEF_FOR_BUS_bool_log_t_
#define _DEFINED_TYPEDEF_FOR_BUS_bool_log_t_ 
typedef struct {
  boolean_T dummy15;
  boolean_T dummy16;
} BUS_bool_log_t;
#endif


#ifndef _DEFINED_TYPEDEF_FOR_BUS_uint8_log_t_
#define _DEFINED_TYPEDEF_FOR_BUS_uint8_log_t_ 
typedef struct {
  uint8_T gps_fix;
  uint8_T dummy12;
} BUS_uint8_log_t;
#endif


#ifndef _DEFINED_TYPEDEF_FOR_BUS_int8_log_t_
#define _DEFINED_TYPEDEF_FOR_BUS_int8_log_t_ 
typedef struct {
  int8_T dummy11;
  int8_T dummy12;
} BUS_int8_log_t;
#endif


#ifndef _DEFINED_TYPEDEF_FOR_BUS_uint16_log_t_
#define _DEFINED_TYPEDEF_FOR_BUS_uint16_log_t_ 
typedef struct {
  uint16_T dummy9;
  uint16_T dummy10;
} BUS_uint16_log_t;
#endif


#ifndef _DEFINED_TYPEDEF_FOR_BUS_int16_log_t_
#define _DEFINED_TYPEDEF_FOR_BUS_int16_log_t_ 
typedef struct {
  int16_T manual_throttleCmd_pwm;
  int16_T manual_elevatorCmd_pwm;
  int16_T manual_aileronCmd_pwm;
  int16_T manual_rudderCmd_pwm;
  int16_T throttleCmd_pwm;
  int16_T elevatorCmd_pwm;
  int16_T aileronCmd_pwm;
  int16_T rudderCmd_pwm;
} BUS_int16_log_t;
#endif


#ifndef _DEFINED_TYPEDEF_FOR_BUS_uint32_log_t_
#define _DEFINED_TYPEDEF_FOR_BUS_uint32_log_t_ 
typedef struct {
  uint32_T dummy5;
  uint32_T dummy6;
} BUS_uint32_log_t;
#endif


#ifndef _DEFINED_TYPEDEF_FOR_BUS_int32_log_t_
#define _DEFINED_TYPEDEF_FOR_BUS_int32_log_t_ 
typedef struct {
  int32_T dummy3;
  int32_T dummy4;
} BUS_int32_log_t;
#endif


#ifndef _DEFINED_TYPEDEF_FOR_BUS_single_log_t_
#define _DEFINED_TYPEDEF_FOR_BUS_single_log_t_ 
typedef struct {
  real32_T v_gps_raw;
  real32_T h_gps_raw;
  real32_T heading_raw;
  real32_T acc_x_raw;
  real32_T acc_y_raw;
  real32_T acc_z_raw;
  real32_T p_raw;
  real32_T q_raw;
  real32_T r_raw;
  real32_T phi_raw;
  real32_T theta_raw;
  real32_T psi_raw;
  real32_T v_pitot_raw;
  real32_T dist_lidar_raw;
  real32_T h_baro_raw;
  real32_T press_raw;
  real32_T temp_raw;
  real32_T h_baro_filt;
  real32_T ias_filt;
  real32_T RC_filt;
  real32_T groundspeed_filt;
  real32_T heading_filt;
  real32_T dist_lidar_filt;
  real32_T dp_raw;
} BUS_single_log_t;
#endif


#ifndef _DEFINED_TYPEDEF_FOR_BUS_double_log_t_
#define _DEFINED_TYPEDEF_FOR_BUS_double_log_t_ 
typedef struct {
  real_T time_frame;
  real_T Lat_raw;
  real_T Long_raw;
  real_T Lat;
  real_T Long;
} BUS_double_log_t;
#endif


#ifndef _DEFINED_TYPEDEF_FOR_BUS_log_t_
#define _DEFINED_TYPEDEF_FOR_BUS_log_t_ 
typedef struct {
  BUS_double_log_t double_data;
  BUS_single_log_t single_data;
  BUS_int32_log_t int32_data;
  BUS_uint32_log_t uint32_data;
  BUS_int16_log_t int16_data;
  BUS_uint16_log_t uint16_data;
  BUS_int8_log_t int8_data;
  BUS_uint8_log_t uint8_data;
  BUS_bool_log_t bool_data;
} BUS_log_t;
#endif

/* Read only - ENDS */


#endif
