 
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
# include "calcInputRudder.h"
# endif
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
extern "C" void PWMinterrupt_rudder_sfun_Outputs_wrapper(int16_T *out)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE
// tell the Arduino we want the function calcInput to be called whenever INT0 (digital pin 2) changes from HIGH to LOW or LOW to HIGH
// catching these changes will allow us to calculate how long the input pulse is
attachInterrupt(RUDDER_SIGNAL_IN,calcInputRudder,CHANGE);
 
// if a new throttle signal has been measured, lets print the value to serial, if not our code could carry on with some other processing
if(bNewRudderSignal)
{
 
   out[0]=nRudderIn; 
 
   // set this back to false when we have finished
   // with nRudderIn, while true, calcInput will not update
   // nRudderIn
   bNewRudderSignal = 0;
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
 
 
