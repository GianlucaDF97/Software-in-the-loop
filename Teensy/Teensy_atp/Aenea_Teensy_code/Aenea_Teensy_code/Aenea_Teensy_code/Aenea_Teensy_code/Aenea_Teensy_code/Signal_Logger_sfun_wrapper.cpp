 
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
 
#include "Signal_Logger_sfun_bus.h"
 
/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
 
#ifndef MATLAB_MEX_FILE
#include "Arduino.h"
#define SD_FAT_TYPE 3
#include "SdFat.h"
#include "RingBuf.h"
 
 
// Use Teensy SDIO
#define SD_CONFIG SdioConfig(FIFO_SDIO)
 
// Size to log 1000 byte lines at 50 Hz for more than 60 minutes.
#define LOG_FILE_SIZE 1000 * 50 * 3600  // 180,000,000 bytes.
 
// Space to hold data in ring buf.
#define RING_BUF_CAPACITY 4 * 512
#define LOG_FILENAME "FlightLog.bin"
 
SdFs sd;
FsFile file;
 
// RingBuf for File type FsFile.
RingBuf<FsFile, RING_BUF_CAPACITY> rb;
 
bool do_flag = false;
bool SDnotFound = false;
 
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
 
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
extern "C" void Signal_Logger_sfun_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    Serial.begin(9600);
    
    if (!sd.begin(SD_CONFIG)) {
        SDnotFound = true;
        return;
    }
    if (sd.exists(LOG_FILENAME)) {
        sd.remove(LOG_FILENAME);
        //Serial.println("file removed\n");
    }
    
    // Open or create file - truncate existing file.
    if (!file.open(LOG_FILENAME, O_RDWR | O_CREAT | O_TRUNC)) {
        //Serial.println("open failed\n");
        //return;
    }
    // File must be pre-allocated to avoid huge
    // delays searching for free clusters.
    if (!file.preAllocate(LOG_FILE_SIZE)) {
        //Serial.println("preAllocate failed\n");
        file.close();
        //return;
    }
    // initialize the RingBuf.
    rb.begin(&file);
    #endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void Signal_Logger_sfun_Outputs_wrapper(const BUS_log_t *flightData,
			const boolean_T *sec_flag)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    if (!SDnotFound){
        
        if (do_flag) {
            // Open or create file - truncate existing file.
            if (!file.open(LOG_FILENAME, FILE_WRITE)) {
                //Serial.println("open failed\n");
                return;
            }
            file.seek(EOF);
            
            do_flag = false;
        }
        
        // Amount of data in ringBuf.
        size_t n = rb.bytesUsed();
        //Serial.println(n);
        if ((n + file.curPosition()) > (LOG_FILE_SIZE - 20)) {
            //Serial.println("File full - quitting.");
        }
        
        if (n >= 512 && !file.isBusy()) {
            //Serial.println("writeout");
            // Not busy only allows one sector before possible busy wait.
            // Write one sector from RingBuf to file.
            if (512 != rb.writeOut(512)) {
                //Serial.println("writeOut failed");
            }
        }
        // Print data into RingBuf.
        
        rb.write((byte *)&flightData[0], sizeof(flightData[0]));
        rb.write('\r');
        
        //Serial.write('\r');
        if (rb.getWriteError()) {
            // Error caused by too few free bytes in RingBuf.
            //Serial.println("WriteError");
            return;
        }
        
        if (sec_flag[0]) {
            //rb.sync();
            //file.truncate();
            //file.rewind();
            file.close();
            do_flag = true;
        }
    }
    else {
        return;
    }
    #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
 
 
