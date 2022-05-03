
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
extern "C" void Read_Mti_Outputs_wrapper(const real_T *inutile,
			uint8_T *Messaggio,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if ( xD[0] == 1 ) {
    
   #ifndef MATLAB_MEX_FILE 
    Serial3.flush() ;
    int req_data[5] = {250,01,52,00,203} ;  // Sono i byte di richiesta del messaggio di output ReqData 
    // controllare sulla documentazione Mti ( low-level communication ) 
    
    for (int j = 0 ; j<5 ;j++) 
        Serial3.write(req_data[j]) ;

    //unsigned long toll =  9000; // microsec di ascolto
    //unsigned long start = micros() ;
    //unsigned long t = 0 ;
    int incomingByte[2] = {0,0} ;   // for incoming serial data
    int len_mex = 41 ;
    //t = 0 ;

    /*while (t <= toll) 
     t = micros() - start ;*/
    if ( Serial3.available() >= 2 ) {
        incomingByte[0] = Serial3.read() ;
        incomingByte[1]  = Serial3.read() ;
    }
        if  ( incomingByte[0] == 250 && incomingByte[1] == 255 ) {
            Messaggio[0] = incomingByte[0] ;
            Messaggio[1] = incomingByte[1]  ;
            for (int i = 2 ; i < len_mex ; i++ ) 
                Messaggio[i] = Serial3.read() ;
        }

    #endif
    
    
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void Read_Mti_Update_wrapper(const real_T *inutile,
			uint8_T *Messaggio,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0] == 0 ) {
    
    #ifndef MATLAB_MEX_FILE 
    Serial3.begin(115200) ;
    #endif
}




xD[0] = 1 ;
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

