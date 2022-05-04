
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
#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int fd;

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
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
void SerialRead_Outputs_wrapper(uint8_T *RX,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==1){
    
    #ifndef MATLAB_MEX_FILE    
    // Returns the next character available on the serial device. 
    // This call will block for up to 10 seconds if no data is available (when it will return -1)
    RX[0] = serialGetchar(fd);
    if (RX[0] == 0)
    {
        printf("No data received to display\n");
    }
    else if (RX[0] <= 0)
    {
        printf("An error has occured\n");
    }
    else
    {
        printf("Data: %c\n", RX[0]);
    }    
    fflush(stdout);    
    #endif

}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void SerialRead_Update_wrapper(uint8_T *RX,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1){
    
    #ifndef MATLAB_MEX_FILE
    fd = serialOpen("/dev/ttyS0", 115200);
    // Check if serial port can be opened   
    if(fd < 0)
    {
        printf (stderr, "Unable to open serial device: %s\n", stderr(errno));
        return;
    }
    #endif
    
    xD[0] = 1;

}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

