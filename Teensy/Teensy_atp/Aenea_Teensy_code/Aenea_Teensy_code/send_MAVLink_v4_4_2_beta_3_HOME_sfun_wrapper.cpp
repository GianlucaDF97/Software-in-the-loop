 
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif
 
 
 
/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
#include <Arduino.h>
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
 
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
#include <math.h>
#ifdef Arduino_h
#include "src\include\mavlink_types.h"
#include "src\include\mavlink.h"
#include "src\include\protocol.h"
#include "src\include\checksum.h"
#endif
#endif
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */
 
/*
 * Start function
 *
 */
extern "C" void send_MAVLink_v4_4_2_beta_3_HOME_sfun_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
 
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void send_MAVLink_v4_4_2_beta_3_HOME_sfun_Outputs_wrapper(const uint8_T *iflogic,
			const uint32_T *time_in,
			const uint8_T *AP_SI,
			const uint16_T *GC_req,
			const real32_T *P_val,
			const uint16_T *WP_info,
			const real32_T *WP_param,
			const uint32_T *ss_onboard,
			const uint16_T *ss_LVDE,
			const int16_T *ss_C,
			const int8_T *ss_R,
			const uint32_T *Heartbeat_custom,
			const uint8_T *Heartbeat_data,
			const int16_T *IMU_data,
			const real32_T *attitude,
			const int32_T *lat_long_alt,
			const int16_T *velGPS,
			const uint16_T *hdg,
			const real32_T *VFR_speed,
			const int16_T *VFR_H,
			const uint16_T *VFR_T,
			const uint16_T *Ser_data,
			const uint16_T *prior_in,
			const real32_T *P_refer,
			const uint8_T *Cal_alt,
			const real32_T *T_0,
			const uint8_T *T_int,
			const real32_T *P_RAW,
			const real32_T *deltaP_RAW,
			const int16_T *AB_T,
			const uint8_T *Cal_home,
			const real_T *H_LAT,
			const real_T *H_LONG,
			const real_T *H_ALT,
			const uint16_T *h_lidar,
			uint8_T *enable,
			uint8_T *msg_out,
			uint16_T *Len,
			uint16_T *prior_out)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
// Initialize the required buffers
mavlink_message_t msg;
uint8_t buf[MAVLINK_MAX_PACKET_LEN+1];   
//variabile di appoggio
int ifnum;
//sistema che invia il messaggio e sua parte
uint8_T SI=AP_SI[0];
uint8_T CI=0;
//uint8_T CI1=;
// valori neccessari per l'invio dei parametri
uint16_T p_len=16;//numero parametri
//uint16_T p_len1=;
uint16_T p_n;     //indice dei parametri
uint8_T t_n=9; //tipo del parametro 9=realt32_T
uint16_T max_WP=6; //numero massimo di waypoint
char*   param_id[16]={"I_HDG","I_IAS", "I_ALT","I_RC","I_WP","I_ATO","I_AL",
"V_HDG","V_IAS","V_ALT","V_RC","C_P0","C_T0","H_LAT","H_LONG","H_ALT"}; //label dei parametri
 
//tipo di messaggio che si sta creando
ifnum=iflogic[0];
//comandi per priorità
prior_out[0]=prior_in[0];
//comando di invio 1 se c'è un messaggio da spedire
enable[0]=0; //blocco l'invio di default
 
// priorità ai parametri richiesti dalla stazione di terra
// invia i parametri a terra con (ogni messaggio è inviato in 1/50 secondo)
if (GC_req[0]==1 && (GC_req[1]>0 && GC_req[1]<12)) //aggiorno un singolo dato se richiesto
    //nota: questo if ha priorità sul successivo, perchè se sto inviando tutta la lista e un parametro
    //      non arriva la stazione manda la richiesta di ritrasmissione di un singolo parametro,
    //      per cui bisogna prima rispondergli e poi continuare ad inviare gli altri
{
    p_n=(GC_req[1]-1); //è l'indice del parametro da inviare  -1 visto che in C la prima posizione di un vettore è 0
    
    //     mavlink_msg_param_value_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// 						       const char *param_id, float param_value, uint8_t param_type, uint16_t param_count, uint16_t param_index)
    
    mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[p_n], P_val[p_n], t_n,p_len, p_n);
    enable[0]=1; //permetto l'invio
}
 
 
 
else if (Cal_alt[0] == 1) //parte aggiunta per la calibrazione dell'altimetro quando è ricevuto il messaggio COMMAND_LONG e il comando MAV_CMD_PREFLIGHT_CALIBRATION
 
{
    
    mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[11], P_refer[0], t_n,p_len,11);
    enable[0] = 1; //permetto l'invio
    
}
 
else if (T_int[0] == 1) {
    
    mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[12], T_0[0], t_n,p_len,12);
    enable[0]=1; //permetto l'invio
    
}
 
else if (Cal_home[0] == 1) {
    
    mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[13], H_LAT[0], t_n,p_len,13);
    enable[0]=1;
    
}
 
else if (Cal_home[1] == 1) {
    
    mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[14], H_LONG[0], t_n,p_len,14);
    enable[0]=1; //permetto l'invio
    
}
 
else if (Cal_home[2] == 1) {
    
    mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[15], H_ALT[0], t_n,p_len,15);
    enable[0]=1; //permetto l'invio
    
}
 
 
 
// if (GC_req[0]==1 && GC_req[1]==10) {
//     
//     p_n=(GC_req[1]-1);
//     
//     mavlink_msg_param_value_pack(SI, CI1, &msg,
//             param_id[p_n], P_val[p_n], t_n,p_len1, p_n);
//     enable[0]=1; //permetto l'invio
// }
 
else if((GC_req[0]==1 && GC_req[1]==255) || prior_out[0]>0  ) //richiesta di invio tutti i parametri
{
    p_n=prior_out[0];//pari all'ultimo indice dei parametri che ho inviato
//     mavlink_msg_param_value_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// 						       const char *param_id, float param_value, uint8_t param_type, uint16_t param_count, uint16_t param_index)
    
    if (p_n == 11) {
         mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[p_n], P_refer[0], t_n, p_len, p_n);
    }
    
    else if (p_n == 12) {
        mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[p_n], T_0[0], t_n, p_len, p_n);
    }
    
    else if (p_n == 13) {
        mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[p_n], H_LAT[0], t_n, p_len, p_n);
    }
    
    else if (p_n == 14) {
        mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[p_n], H_LONG[0], t_n, p_len, p_n);
    }
    
    else if (p_n == 15) {
        mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[p_n], H_ALT[0], t_n, p_len, p_n);
    }
    
    else {
         mavlink_msg_param_value_pack(SI, CI, &msg,
            param_id[p_n], P_val[p_n], t_n, p_len, p_n);
    }
    p_n++; //per il prossimo invio
    prior_out[0] = p_n;
    if (prior_out[0] == (p_len)) // non ho altri parametri da inviare.
    {
        prior_out[0] = 0;
        //prior_out[1]+=1; //invio un secondo ciclo per sicurezza (non fondamentale)
    }
    enable[0] = 1; //permetto l'invio
} 
 
// else if((GC_req[0]==1 && GC_req[1]==255) || prior_out[0]>0  ) //richiesta di invio tutti i parametri
// {
//     p_n=prior_out[0];//pari all'ultimo indice dei parametri che ho inviato
// //     mavlink_msg_param_value_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// // 						       const char *param_id, float param_value, uint8_t param_type, uint16_t param_count, uint16_t param_index)
//     
//     mavlink_msg_param_value_pack(SI, CI1, &msg,
//             param_id[p_n], P_val[p_n], t_n, p_len1, p_n);
//     p_n++; //per il prossimo invio
//     prior_out[0]=p_n;
//     if (prior_out[0]==(p_len)) // non ho altri parametri da inviare
//     {
//         prior_out[0]=0;
//         //prior_out[1]+=1; //invio un secondo ciclo per sicurezza (non fondamentale)
//     }
//     enable[0]=1; //permetto l'invio
// }
 
 
///fase invio Waypoint
//prima si invia il cnt e poi item
else if(GC_req[0] == 2 && GC_req[1] == 255) // rispondo al messaggio di richiesta del numero di Waypoint MISSION_REQUEST_LIST
{
//  uint16_t mavlink_msg_mission_count_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// 						       uint8_t target_system, uint8_t target_component, uint16_t count)
    uint16_t cnt = WP_info[0];
    if (cnt > max_WP) //non posso avere più di max_WP waypoints in memoria se è meaggiore c'è stato qualche errore
    {        cnt = max_WP;}
    
    mavlink_msg_mission_count_pack(SI, CI, &msg,
            GC_req[2],0, cnt);
    enable[0] = 1; //permetto l'invio
}
 
else if (GC_req[0] == 2 && GC_req[1] >= 0 && GC_req[1] < max_WP) // rispondo alla richiesta singolo Waypoint MISSION_REQUEST (richiede un particolare waypoint)
{                                                          // GC_req[1] sarebbe WP_request255.seq
    p_n = GC_req[1];
//     uint16_t mavlink_msg_mission_item_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// 						       uint8_t target_system, uint8_t target_component, uint16_t seq,
//        uint8_t frame, uint16_t command, uint8_t current, uint8_t autocontinue, float param1, float param2, float param3, float param4, float x, float y, float z)
     mavlink_msg_mission_item_pack(SI, CI, &msg,
            GC_req[2],0,p_n,
            WP_info[3],WP_info[2],WP_info[4],WP_info[5],
            WP_param[0],WP_param[1],WP_param[2],WP_param[3],WP_param[4],WP_param[5],WP_param[6]);
    enable[0] = 1; //permetto l'invio
    
}
////fase di richiesta dei Waypoint
else if (GC_req[0] == 3) // risposta al messaggio di MISSION_ITEM con la richiesta del prossimo Waypoint che deve mandare QGC 
{   
    uint16_t WP_num = 0; //numero wp da inviare
    enable[0] = 1; //permetto l'invio
    if (WP_info[0] > max_WP) //non ho spazio per salvare tutti i waypoint in arrivo
    {   mavlink_msg_mission_ack_pack(SI, CI, &msg,GC_req[2], 0, 4); }
    if (GC_req[1] < 200) // se si verifica tale condizione vuol dire che il messaggio ricevuto non è MISSION_COUNT in cui GC_req[1] = 200. Quindi 
                       // si tratterà del messaggio di MISSION_ITEM in cui GC_req[1] = WP_item255.seq ovvero il numero del waypoint.
    {
        WP_num = WP_info[1]+1; // ovvero fa WP_num = seq + 1 (seq è il numero del waypoint) perché devo inviare la richiesta per il wp succssivo
    }
    //invio
    if (WP_info[0]<=WP_num || (GC_req[1]==250)) //non devo mandare altri WP
    {      mavlink_msg_mission_ack_pack(SI, CI, &msg,GC_req[2], 0, 0);}
    else
    {
        //mavlink_msg_mission_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// 						       uint8_t target_system, uint8_t target_component, uint16_t seq)
        mavlink_msg_mission_request_pack(SI, CI, &msg,
                255, 0, WP_num);
    }
}
 
else //invio telemetria
{
    if (ifnum == 0) //Heartbeat
    {
        
// mavlink_message_heartbeat_pack(system id, component id, message container, system type, MAV_AUTOPILOT_GENERIC)
        mavlink_msg_heartbeat_pack(SI, CI, &msg,
                Heartbeat_data[0], Heartbeat_data[1],Heartbeat_data[2],
                Heartbeat_custom[0],Heartbeat_data[3]);
        
        enable[0] = 1; //permetto l'invio
    }
    else if (ifnum == 1) //system stauts
    {
//mavlink_msg_sys_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
//    uint32_t onboard_control_sensors_present, uint32_t onboard_control_sensors_enabled, uint32_t onboard_control_sensors_health,
//     uint16_t load, uint16_t voltage_battery,
//    int16_t current_battery, int8_t battery_remaining,
//    uint16_t drop_rate_comm, uint16_t errors_comm, uint16_t errors_count1, uint16_t errors_count2, uint16_t errors_count3, uint16_t errors_count4)
        mavlink_msg_sys_status_pack(SI, CI, &msg,
                ss_onboard[0],ss_onboard[1] ,ss_onboard[2],
                ss_LVDE[0],ss_LVDE[1],
                ss_C[0],ss_R[0],
                ss_LVDE[2],ss_LVDE[3], ss_LVDE[4],ss_LVDE[5],ss_LVDE[6],ss_LVDE[7]);
        
        enable[0] = 1; //permetto l'invio
    }
    
    else if (ifnum == 26) //IMU
    {
//     mavlink_msg_scaled_imu_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// 						       uint32_t time_boot_ms, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag)
        mavlink_msg_scaled_imu_pack(SI, CI, &msg, time_in[0],
                IMU_data[0],IMU_data[1],IMU_data[2],
                IMU_data[3],IMU_data[4],IMU_data[5],
                IMU_data[6], IMU_data[7],IMU_data[8]);
        
        enable[0]=1; //permetto l'invio
    }
    else if (ifnum == 30) //ATT
    {
//  mavlink_msg_attitude_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// 						       uint32_t time_boot_ms, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed)
        mavlink_msg_attitude_pack(SI, CI, &msg, time_in[0],
                attitude[0], attitude[1],attitude[2],
                attitude[3],attitude[4],attitude[5]);
 
        enable[0]=1; //permetto l'invio
    }
    else if (ifnum == 33)  //GLOBAL_POSITION_INT
    {
//  mavlink_msg_global_position_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// 						       uint32_t time_boot_ms, int32_t lat, int32_t lon, int32_t alt, int32_t relative_alt, int16_t vx, int16_t vy, int16_t vz, uint16_t hdg)
        mavlink_msg_global_position_int_pack(SI, CI, &msg, time_in[0],
                lat_long_alt[0],lat_long_alt[1],lat_long_alt[2],lat_long_alt[3],
                velGPS[0],velGPS[1],velGPS[2], hdg[0]);
        
           enable[0] = 1; //permetto l'invio
    }
    
    else if (ifnum == 34)  //GPS_RAW
    {
 /*
        Pack a gps_raw_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param fix_type 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 * @param lat Latitude in 1E7 degrees
 * @param lon Longitude in 1E7 degrees
 * @param alt Altitude in 1E3 meters (millimeters) above MSL
 * @param eph GPS HDOP horizontal dilution of position in cm (m*100). If unknown, set to: 65535
 * @param epv GPS VDOP horizontal dilution of position in cm (m*100). If unknown, set to: 65535
 * @param vel GPS ground speed (m/s * 100). If unknown, set to: 65535
 * @param cog Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: 65535
 * @param satellites_visible Number of satellites visible. If unknown, set to 255
 * @return length of the message in bytes (excluding serial stream start sign)
 
static __inline uint16_t mavlink_msg_gps_raw_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, uint8_t fix_type, int32_t lat, int32_t lon, int32_t alt, uint16_t eph, uint16_t epv, uint16_t vel, uint16_t cog, uint8_t satellites_visible)
*/
        mavlink_msg_gps_raw_int_pack(SI, CI, &msg, time_in[0], 3,
                lat_long_alt[0],lat_long_alt[1],lat_long_alt[2],65535,65535,
                sqrt(pow(velGPS[0],2)+pow(velGPS[1],2)),hdg[0], 255);
        
        
        enable[0]=1; //permetto l'invio
    }
    else if (ifnum == 36) //SERVO_OUTPUT_RAW
    {
//         mavlink_msg_servo_output_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// 						       uint32_t time_usec, uint8_t port, uint16_t servo1_raw, uint16_t servo2_raw, uint16_t servo3_raw, uint16_t servo4_raw, uint16_t servo5_raw, uint16_t servo6_raw, uint16_t servo7_raw, uint16_t servo8_raw)
        mavlink_msg_servo_output_raw_pack(SI, CI, &msg, time_in[0], Ser_data[0],
                Ser_data[1],Ser_data[2],Ser_data[3],Ser_data[4],Ser_data[5],Ser_data[6],Ser_data[7],Ser_data[8]);
//         mavlink_msg_servo_output_raw_pack(SI, CI, &msg, time_in[0],Ser_P[0],
//                 Ser_raw[0],Ser_raw[1], Ser_raw[2],Ser_raw[3],
//                 Ser_raw[4],Ser_raw[5],Ser_raw[6],Ser_raw[7]);
        enable[0]=1; //permetto l'invio
    }
    else if (ifnum == 74) //VFR
    {
//     mavlink_msg_vfr_hud_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
// 						       float airspeed, float groundspeed, int16_t heading, uint16_t throttle, float alt, float climb)
        mavlink_msg_vfr_hud_pack(SI, CI, &msg,
                VFR_speed[0], VFR_speed[1],
                VFR_H[0],VFR_T[0],
                VFR_speed[2],VFR_speed[3]);
        enable[0]=1; //permetto l'invio
    }
    
    else if (ifnum == 29) // SCALED_PRESSURE
    {
        mavlink_msg_scaled_pressure_pack(SI, CI, &msg,
                time_in[0], P_RAW[0], deltaP_RAW[0], AB_T[0]);
        enable[0]=1; //permetto l'invio
    }
    
       
    // AGGIUNTO DA SENSOLINI MISURA LIDAR
    
//    static inline uint16_t mavlink_msg_distance_sensor_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
//                               uint32_t time_boot_ms, uint16_t min_distance, uint16_t max_distance, uint16_t current_distance, uint8_t type, uint8_t id, uint8_t orientation, uint8_t covariance)
    
    
//        else if (ifnum == 100) // LIDAR
//    {
//        mavlink_msg_distance_sensor_pack(SI, CI, &msg,
//                               time_in[0], 0, 4000 , h_lidar[0] , 0, 50 , 0, 255);
//        enable[0]=1; //permetto l'invio
//    } 
    
    else
    {
        enable[0]=0;// non far nulla
   }
}//fine della priorità ad altre azioni
 
// Copy the message to send buffer
Len[0] = mavlink_msg_to_send_buffer(buf, &msg);
//output
memcpy(msg_out, buf,Len[0]);
//terminazione
msg_out[Len[0]]=0;
 
 
 
 
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
 
/*
 * Terminate function
 *
 */
extern "C" void send_MAVLink_v4_4_2_beta_3_HOME_sfun_Terminate_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
#endif
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}
 
