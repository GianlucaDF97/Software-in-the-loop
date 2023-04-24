# ifndef MATLAB_MEX_FILE
#include "calcInputAileron.h"

volatile int16_t nAileronIn = NEUTRAL_AILERON; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
volatile uint32_t ulStartAileron = 0; // set in the interrupt
volatile int8_t bNewAileronSignal = 0; // set in the interrupt and read in the loop
// we could use nAileronIn = 0 in loop instead of a separate variable, but using bNewAileronSignal to indicate we have a new signal
// is clearer for this first example

void calcInputAileron()
{
   // if the pin is high, its the start of an interrupt
   if(digitalRead(AILERON_SIGNAL_IN_PIN) == HIGH)
   {
     // get the time using micros - when our code gets really busy this will become inaccurate, but for the current application its
     // easy to understand and works very well
    ulStartAileron = micros();
   }
   else
   {
     // if the pin is low, its the falling edge of the pulse so now we can calculate the pulse duration by subtracting the
     // start time ulStartPeriod from the current time returned by micros()
     if(ulStartAileron && (bNewAileronSignal == 0))
     {
       nAileronIn = (int)(micros() - ulStartAileron);
       ulStartAileron = 0;
 
       // tell loop we have a new signal on the throttle channel
       // we will not update nAileronIn until loop sets
       // bNewAileronSignal back to false
       bNewAileronSignal = 1;
     }
   }
}

#endif
