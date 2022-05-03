
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
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void Seriale_mav_Outputs_wrapper(const uint8_T *inutile,
			uint8_T *Messaggio,
			int32_T *serial_available,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if ( xD[0] == 1 ) {
    
#ifndef MATLAB_MEX_FILE 
serial_available[0] = 0;    
    
for(int j=0; j<100;j++)
Messaggio[j] = 0;    

serial_available[0] = Serial2.available();

int i = 0;
while (Serial2.available() > 0) {
Messaggio[i] = Serial2.read();
if (i == 100)
   break;
i++;

}
 

#endif
    
    
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void Seriale_mav_Update_wrapper(const uint8_T *inutile,
			uint8_T *Messaggio,
			int32_T *serial_available,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0] == 0 ) {
    
    #ifndef MATLAB_MEX_FILE 
    Serial2.begin(57600) ;
    
    #endif
}




xD[0] = 1 ;
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

