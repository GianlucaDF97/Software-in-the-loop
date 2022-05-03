
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
#include <stdio.h>
#include <string.h>
#include <stdint.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 6
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
void outputStream_v1_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */

/*
    * Custom Start code goes here.
    */
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void outputStream_v1_Outputs_wrapper(const real_T *u0,
			uint8_T *txBuf,
			uint32_T *length)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */

int j;
    
    memset(txBuf,0x00,64);
    
    sprintf(txBuf,"%11.6f %11.6f %7.2f %9.5f %9.5f %10.5f\n",u0[0],u0[1],u0[2],u0[3],u0[4],u0[5]);
    
    
    for( j=0; j<64; j++ ) {
        if ( txBuf[j]==10 ){
            length[0]=j+1;
        }
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Terminate function
 *
 */
void outputStream_v1_Terminate_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */

/*
    * Custom Terminate code goes here.
    */
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

