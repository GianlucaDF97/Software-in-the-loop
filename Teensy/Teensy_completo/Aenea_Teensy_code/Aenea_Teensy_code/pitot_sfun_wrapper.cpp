 
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
float V_0 = 5.0; // supply voltage to the pressure sensor
float rho = 1.204; // density of air 
int val = 0; 
int analogPin = 0;  
int Pmin=-1244.2;
int Pmax=1244.2;
 
// parameters for averaging and offset
int offset = 0;
int offset_size = 500;
int veloc_mean_size = 1000;
int zero_span = 2;
int count = 0;
// setup and calculate offset
#endif
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */
 
/*
 * Start function
 *
 */
extern "C" void pitot_sfun_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE    
    
Serial.begin(9600);
  for (int ii=0;ii<offset_size;ii++){
    offset += analogRead(A15)-512;
  }
  offset /= offset_size;      
    
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void pitot_sfun_Outputs_wrapper(real_T *velocity)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE  
    
  float adc_avg = 0; float veloc = 0.0; 
  float dp=0;
  
// average a few ADC readings for stability
  for (int ii=0;ii<veloc_mean_size;ii++){
    adc_avg+= analogRead(A15)-offset;
    }  
  adc_avg/=veloc_mean_size; 
    
  if(adc_avg>=512){
    dp=((adc_avg)/1024-0.1)*(Pmax-Pmin)/0.8+Pmin;
    *velocity = sqrt(2*dp/rho);
  }else{
    dp=((adc_avg)/1024-0.1)*(Pmax-Pmin)/0.8+Pmin;
    *velocity = -sqrt(-2*dp/rho);
  }
 
  /*
  dp=((Pmax-Pmin)*((adc_avg*0.001)-(0.1*V_0))/(0.8*V_0))+Pmin;
  *velocity = +sqrt(2*dp/rho); */
 
  Serial.println(*velocity); // print velocity
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
 
 
