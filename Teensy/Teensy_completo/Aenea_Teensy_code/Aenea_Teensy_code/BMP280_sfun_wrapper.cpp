 
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
#include <math.h>
#ifndef MATLAB_MEX_FILE
#include <Wire.h>
#include <Adafruit_BMP280.h>
 
Adafruit_BMP280 bmp; // I2C
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
 
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */
 
/*
 * Start function
 *
 */
extern "C" void BMP280_sfun_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    Serial.begin(9600);
    unsigned status;
    status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
 
    pinMode(13,OUTPUT);
        
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                    Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                    Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
    #endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void BMP280_sfun_Outputs_wrapper(const real32_T *h_ref,
			real32_T *OAT,
			real32_T *BaroPressure,
			real32_T *BaroAlt)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    OAT[0] = bmp.readTemperature();
 /*   Serial.print(F("Temperature = "));
    Serial.print(OAT[0]);
    Serial.println(" *C");*/
    
    BaroPressure[0] = bmp.readPressure();
   /* Serial.print(F("Pressure = "));
    Serial.print(BaroPressure[0]);
    Serial.println(" Pa");*/
 
    BaroAlt[0] = bmp.readAltitude(h_ref[0]/100);
  /*  Serial.print(F("Approx altitude = "));
    Serial.print(BaroAlt[0]); // Adjusted to local forecast! 
    Serial.println(" m");*/
    
    #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
 
/*
 * Terminate function
 *
 */
extern "C" void BMP280_sfun_Terminate_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
    * Custom Terminate code goes here.
    */
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}
 
