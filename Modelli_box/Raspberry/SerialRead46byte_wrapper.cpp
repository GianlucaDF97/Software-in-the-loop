
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
extern "C" void SerialRead46byte_Outputs_wrapper(uint8_T *RX,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==1){
    
    #ifndef MATLAB_MEX_FILE    
    // Returns the next character available on the serial device. 
    // This call will block for up to 10 seconds if no data is available (when it will return -1)
    
    int buff_len=54;
    int i;
    
    
    
    unsigned char check[2]={0,0};
    int start,finish;
    finish=0;
    
    start=millis();
    if (serialDataAvail(fd)>1){
    while (check[0]!=255 && check[1]!=254 && finish<15){
        finish=millis()-start;
        for (i=0; i<2; i++)
            check[i]=serialGetchar(fd);
    }
    
    if (check[0]==255 && check[1]==254){
        for (i=0; i<buff_len; i++)
            RX[i] = serialGetchar(fd);
    }
    }
    
    serialFlush(fd);
  
    #endif

}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void SerialRead46byte_Update_wrapper(uint8_T *RX,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1){
    
    #ifndef MATLAB_MEX_FILE
    fd = serialOpen("/dev/ttyUSB0", 57600);
    // Check if serial port can be opened   
/*    if(fd < 0)
    {
        printf (stderr, "Unable to open serial device: %s\n", strerror(errno));
        return 1;
    }*/
    #endif
    
    xD[0] = 1;

}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

