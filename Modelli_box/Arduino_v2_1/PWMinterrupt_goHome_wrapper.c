
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
# include "calcInput_go_Home.h"
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
void PWMinterrupt_goHome_Outputs_wrapper(int16_T *out)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE
// tell the Arduino we want the function calcInput to be called whenever INT0 (digital pin 2) changes from HIGH to LOW or LOW to HIGH
// catching these changes will allow us to calculate how long the input pulse is
attachInterrupt(digitalPinToInterrupt(HOME_SIGNAL_IN),calcInputHOME,CHANGE);

// if a new throttle signal has been measured, lets print the value to serial, if not our code could carry on with some other processing
if(bNewHOMESignal)
{

   out[0]=nHOMEIn; 

   // set this back to false when we have finished
   // with nAileronIn, while true, calcInput will not update
   // nAileronIn
   bNewHOMESignal = 0;
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


