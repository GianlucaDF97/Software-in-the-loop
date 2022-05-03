
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
# ifndef MATLAB_MEX_FILE
# include <Arduino.h>
# include "calcInputThrottle.h"
# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void PWMinterrupt_throttle_v4_4_Outputs_wrapper(int16_T *out)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE
// tell the Arduino we want the function calcInput to be called whenever INT0 (digital pin 2) changes from HIGH to LOW or LOW to HIGH
// catching these changes will allow us to calculate how long the input pulse is
attachInterrupt(THROTTLE_SIGNAL_IN,calcInputThrottle,CHANGE);

// if a new throttle signal has been measured, lets print the value to serial, if not our code could carry on with some other processing
if(bNewThrottleSignal)
{

   out[0]=nThrottleIn; 

   // set this back to false when we have finished
   // with nThrottleIn, while true, calcInput will not update
   // nThrottleIn
   bNewThrottleSignal = 0;
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


