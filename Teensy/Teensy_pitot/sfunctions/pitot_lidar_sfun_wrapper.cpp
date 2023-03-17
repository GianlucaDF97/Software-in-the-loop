 
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
 
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1
 
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE 
 
#endif
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */
 
/*
 * Start function
 *
 */
extern "C" void pitot_lidar_sfun_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE    
    
     Serial2.begin(9600);
    Serial.begin(9600);
    
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void pitot_lidar_sfun_Outputs_wrapper(real_T *velocity,
			real_T *distance,
			real_T *dp)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE  
  Serial2.write(104); //byte di richiesta dati 
   //Serial.println("inizio comunicazione print 1");
   //Serial.print("print dell'available:");
   //Serial.println(Serial2.available());
   if(Serial2.available()==10){
        //Serial.println("inizio comunicazione print 2");
        uint8_t onebyte=Serial2.read();
Serial.print("onebyte 1:");
        Serial.println(onebyte);
        if(onebyte==254){
            onebyte=Serial2.read();
Serial.print("onebyte 2:");
            Serial.println(onebyte);
            if(onebyte==255){
                uint16_t Hvelocity=Serial2.read();
                uint16_t Lvelocity=Serial2.read();
                Serial.print("Hvelocity non shift:");
                Serial.println(Hvelocity,BIN);               
                Hvelocity=Hvelocity<<8;
 
                //Serial.print("Hvelocity shift:");
                //Serial.println(Hvelocity,BIN);               
                //Serial.print("Lvelocity:");
                //Serial.println(Lvelocity,BIN);
                //Serial.println(Hvelocity | Lvelocity, BIN);
                V=(int16_t)(Hvelocity | Lvelocity);
                velocity[0]=(double)V/100;
                Serial.print("velocità:");
                Serial.println(velocity[0]);
                
                uint16_t Hdist=Serial2.read();
                uint16_t Ldist=Serial2.read();
                Hdist=Hdist<<8;
                distance[0]=(double)(Hdist | Ldist);
                Serial.print("distanza:");
                Serial.println(distance[0]);
                
                uint32_t HHP=Serial2.read();
                uint32_t HhP=Serial2.read();
                uint32_t LlP=Serial2.read();
                uint32_t LLP=Serial2.read();
                HHP=HHP<<24;
                HhP=HhP<<16;
                LlP=LlP<<8;
                dp[0]=(double)(HHP | HhP | LlP | LLP)/100;
                Serial.print("dp:");
                Serial.println(dp[0]);
 
 
                
            }
        }
    }
   
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
 
 
