# ifndef MATLAB_MEX_FILE
#include "calcInputThrottle.h"

volatile int16_t nThrottleIn = NEUTRAL_THROTTLE; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
volatile uint32_t ulStartThrottle = 0; // set in the interrupt
volatile int8_t bNewThrottleSignal = 0; // set in the interrupt and read in the loop
// we could use nThrottleIn = 0 in loop instead of a separate variable, but using bNewThrottleSignal to indicate we have a new signal
// is clearer for this first example

void calcInputThrottle()
{
   // if the pin is high, its the start of an interrupt
   if(digitalRead(THROTTLE_SIGNAL_IN_PIN) == HIGH)
   {
     // get the time using micros - when our code gets really busy this will become inaccurate, but for the current application its
     // easy to understand and works very well
    ulStartThrottle = micros();
   }
   else
   {
     // if the pin is low, its the falling edge of the pulse so now we can calculate the pulse duration by subtracting the
     // start time ulStartPeriod from the current time returned by micros()
     if(ulStartThrottle && (bNewThrottleSignal == 0))
     {
       nThrottleIn = (int)(micros() - ulStartThrottle);
       ulStartThrottle = 0;
 
       // tell loop we have a new signal on the throttle channel
       // we will not update nThrottleIn until loop sets
       // bNewThrottleSignal back to false
       bNewThrottleSignal = 1;
     }
   }
}

#endif
