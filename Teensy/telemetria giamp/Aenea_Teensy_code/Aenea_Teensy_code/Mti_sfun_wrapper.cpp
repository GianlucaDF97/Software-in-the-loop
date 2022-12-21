 
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
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif
 
#include <math.h>
 
#ifndef MATLAB_MEX_FILE 
#define ahrsReadTimeout 5
 
#include <Arduino.h>
static uint32_t AHRSlastReceiveTime;
unsigned int buff[41];
 int req_data[5] = {250,01,52,00,203} ;
 int auto_start[5]={250, 01,06,00,249};
 
#endif
 
#define u_width 9
#define y_width 1
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
extern "C" void Mti_sfun_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    
    // per printare i valori del debug
  
//     Serial1.begin(57600);
       
    Serial3.begin(115200) ;
    for (int j = 0 ; j<5 ;j++) 
        Serial3.write(auto_start[j]) ;
   
    
    
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void Mti_sfun_Outputs_wrapper(const real_T *debug,
			uint8_T *messaggio)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE 
    
 //   int req_data[5] = {250,01,52,00,203} ;  // Sono i byte di richiesta del messaggio di output ReqData 
    // controllare sulla documentazione Mti ( low-level communication ) 
  
    // per printare i valori del debug
    /*Serial.println("AHRS");
    Serial1.println("AHRS");*/
    for(int t = 0; t<9; t++){
        /*Serial1.println(debug[t]);
        Serial.println(debug[t]);*/
    }
    
    int len_mex = 41 ;
    int i =4;
    bool timeout=false;
 
    
    for (int j = 0 ; j<5 ;j++) 
        Serial3.write(req_data[j]) ;
 
    //Control[0] = 0;
    
    AHRSlastReceiveTime=millis();
 
    
    //Serial1.println(Serial3.available());
    int onebyte=Serial3.read();
    
    if(onebyte==250){
        messaggio[0]=onebyte;
        onebyte=Serial3.read();
        if(onebyte==255){
            messaggio[1]=onebyte;
            onebyte=Serial3.read();
            if(onebyte==50){
              messaggio[2]=onebyte;
              onebyte=Serial3.read();
              if(onebyte==36){
                messaggio[3]=onebyte;
 
               while((i<len_mex) && (!timeout)){
        
                 if(Serial3.available()){
                    messaggio[i]=Serial3.read();
                    i++;
                  }
    
        if(millis()-AHRSlastReceiveTime>=ahrsReadTimeout){
            timeout=true;
        }
        
        //Control[0]=1;
       
    }
              }
 
              
            }
        }
    }
    
    Serial3.flush() ;
    #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
 
/*
 * Terminate function
 *
 */
extern "C" void Mti_sfun_Terminate_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}
 
