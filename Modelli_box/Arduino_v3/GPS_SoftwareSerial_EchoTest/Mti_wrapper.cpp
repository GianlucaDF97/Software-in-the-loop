
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

/*
https://it.mathworks.com/help/simulink/sfg/s-function-builder-dialog-box.html
https://it.mathworks.com/help/simulink/sfg/s-function-builder-dialog-box.html
https://it.mathworks.com/help/simulink/sfg/s-function-builder-dialog-box.html
*/

#include <Arduino.h>
//#include <stdint.h>

#define SERIAL_BAUDRATE 115200        // baudrate della porta seriale
#define SERIAL_OPEN_DELAY 1000        // pausa di attesa dopo l'apertura delle comunicazioni seriali

// IMPORTANTE DIFFERENZA (DA SPIEGARE)
uint8_t go_to_meas[5] = {250, 255, 16, 00, 241};
uint8_t sms_header[4] = {250, 255, 50, 50};
uint8_t inviando[41] = {0xFA, 0xFF, 0x32, 0x24, 0xBE, 0xAB, 0xE3, 0x71, 0xBD, 0xE9, 0xD2, 0xC0, 0x41, 0x1D, 0x11, 0x0D, 0xB9, 0xD6, 0x91, 0xF0, 0xBC, 0x01, 0x90, 0x57, 0xBB, 0x07, 0xA3, 0x35, 0xBF, 0x12, 0x4C, 0x38, 0x3F, 0xF5, 0x11, 0x85, 0xC2, 0xE5, 0x3D, 0x09, 0xE0};
uint8_t tmp_buff[4] = {0,0,0,0};
uint8_t message[41];  // a meno dell'header
uint8_t messaggio[41];
uint8_t inizio[4];                  
uint8_t message_len = 0;
uint8_t pos = 0;
bool header_found = false;

unsigned long bytes_received = 0;
unsigned long header_pos_old = 0;

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
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
extern "C" void Mti_Start_wrapper(real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    
    //Serial.begin(SERIAL_BAUDRATE);
    //delay(SERIAL_OPEN_DELAY);
    
    Serial3.begin(SERIAL_BAUDRATE);
    //delay(SERIAL_OPEN_DELAY);
     Serial3.write(go_to_meas,5);
    //Serial.print(2*SERIAL_OPEN_DELAY);
    //Serial.print(" msec di attesa...");
   // delay(2*SERIAL_OPEN_DELAY);
    //Serial.println("[ OK ]");
//     while (1) {
//      while (Serial3.available()<=0) {
// //         Serial.print("Richiedo le misure all'AHRS ... ");
//         Serial3.write(go_to_meas,5);
//  //       Serial.println(Serial3.read());
//  //       for ( int j = 0; j<41; j++){
//   //          messagge[j] = Serial3.read();
//             //Serial.println(messaggio[j]);
// //        }
// //         Serial.println("[ OK ]");
// //         delay(SERIAL_OPEN_DELAY);
//      }
 //  }
   // Serial.println("Entro in: Mti_Update_wrapper");
    
    #endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void Mti_Outputs_wrapper(uint8_T *messaggio,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0]==1){
    #ifndef MATLAB_MEX_FILE
//     while(Serial3.available()>0){
       
        for (int t = 0; t<41; t++){
            messaggio[t]=Serial3.read();
        }
//     }
 //   Serial.println(Serial3.read());
// // //     if ( Serial3.available() > 0 ) {
// // //            
// // //                 
// // //                 for ( int j = 0; j<41; j++){
// // //                     messaggio[j] = Serial3.read();
// // //                     Serial.println(messaggio[j]);
// // //                    
// // //                 
// // //             }
// // //     }
//         //         Serial.println(Serial3.read());
//         tmp_buff[3] = Serial3.read();
//         bytes_received++;
//         
//         if (tmp_buff[0]==sms_header[0] && tmp_buff[1]==sms_header[1] && tmp_buff[2]==sms_header[2] && tmp_buff[3]==sms_header[3]) {
//             header_found=true;
//             message_len = bytes_received-header_pos_old;
//             header_pos_old=bytes_received;
//         }
//         
//         if (header_found) {
//             message[pos] = tmp_buff[3];
//             if (message_len==54) {
//                 for (int k=1; k<51; k++) {
//                     Serial.println(message[k]);
//                     //                     Serial.print(';');
//                 }
//                 //                 Serial.println("***");
//                 pos=0;
//             }
//             pos++;
//         }
//         
//         // shiftiamo i valori nell'array
//         tmp_buff[0]=tmp_buff[1];
//         tmp_buff[1]=tmp_buff[2];
//         tmp_buff[2]=tmp_buff[3];
//         
  //   }
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void Mti_Update_wrapper(uint8_T *messaggio,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==0) {
    #ifndef MATLAB_MEX_FILE
//     
//     for (int i=0; i<5; i++){
//        // Serial.println(go_to_meas[i]);
//     }
    
     xD[0]=1;
    #endif
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

