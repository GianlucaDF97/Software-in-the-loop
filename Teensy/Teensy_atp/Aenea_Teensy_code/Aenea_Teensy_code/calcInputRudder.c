# ifndef MATLAB_MEX_FILE
#include "calcInputRudder.h"

volatile int16_t nRudderIn = NEUTRAL_RUDDER; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
volatile uint32_t ulStartRudder = 0; // set in the interrupt
volatile int8_t bNewRudderSignal = 0; // set in the interrupt and read in the loop
// we could use nRudderIn = 0 in loop instead of a separate variable, but using bNewRudderSignal to indicate we have a new signal
// is clearer for this first example

void calcInputRudder()
{
   // if the pin is high, its the start of an interrupt
   if(digitalRead(RUDDER_SIGNAL_IN_PIN) == HIGH)
   {
     // get the time using micros - when our code gets really busy this will become inaccurate, but for the current application its
     // easy to understand and works very well
    ulStartRudder = micros();
   }
   else
   {
     // if the pin is low, its the falling edge of the pulse so now we can calculate the pulse duration by subtracting the
     // start time ulStartPeriod from the current time returned by micros()
     if(ulStartRudder && (bNewRudderSignal == 0))
     {
       nRudderIn = (int)(micros() - ulStartRudder);
       ulStartRudder = 0;
 
       // tell loop we have a new signal on the Rudder channel
       // we will not update nRudderIn until loop sets
       // bNewRudderSignal back to false
       bNewRudderSignal = 1;
     }
   }
}

#endif
