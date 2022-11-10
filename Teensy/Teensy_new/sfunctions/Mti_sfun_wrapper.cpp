
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
//#include <stdint.h>

#define SERIAL_BAUDRATE 115200        // baudrate della porta seriale
#define SERIAL_OPEN_DELAY 1000        // pausa di attesa dopo l'apertura delle comunicazioni seriali

// IMPORTANTE DIFFERENZA (DA SPIEGARE)
uint8_t go_to_meas[5] = {250, 255, 16, 00, 241};
uint8_t req_data[5] = {250, 01, 52, 00, 203};
uint8_t sms_header[4] = {250, 255, 50, 50};
uint8_t tmp_buff[3] = {0,0,0};
uint8_t messaggio[41];  
uint8_t messold[38];                


#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 9
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void Mti_sfun_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    Serial.begin(9600);
    Serial2.begin(57600);
    
    pinMode(13,OUTPUT);  // per testare il sensore
      
    Serial3.begin(SERIAL_BAUDRATE);
    //delay(SERIAL_OPEN_DELAY);
//     Serial3.write(go_to_meas,5);
    
    #endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void Mti_sfun_Outputs_wrapper(const real_T *debug,
			uint8_T *messaggio)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
//     for (int r = 0; r<3; r++){
//         tmp_buff[r] = Serial3.read();
//     }
//     if (tmp_buff[0]==sms_header[0] && tmp_buff[1]==sms_header[1] && tmp_buff[2]==sms_header[2]){
    Serial2.println("AHRS");
    for(int t = 0; t<9; t++){
        Serial2.println(debug[t]);
        Serial.println(debug[t]);
    }
    for(int w = 0; w<5; w++){
        Serial3.write(req_data[w]);
    }
    int len = 41;
    if (Serial3.available() == 41){
            
        for (int t = 0; t<len; t++){
            messaggio[t]=Serial3.read();
            //messold[t]=Serial3.read();
        }
    }
//     else
//     {
//         Serial3.end();
//         Serial3.begin(115200);
//     }
   // Serial3.flush();
    
//     }
//     else
//     {
//             for (int t = 0; t<38; t++){
//             messaggio[t]=messold[t];
//         }
//     }
    #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


