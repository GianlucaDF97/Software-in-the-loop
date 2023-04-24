# ifndef MATLAB_MEX_FILE
#include "calcInputElevator.h"

volatile int16_t nElevatorIn = NEUTRAL_ELEVATOR; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
volatile uint32_t ulStartElevator = 0; // set in the interrupt
volatile int8_t bNewElevatorSignal = 0; // set in the interrupt and read in the loop
// we could use nElevatorIn = 0 in loop instead of a separate variable, but using bNewThrottleSignal to indicate we have a new signal
// is clearer for this first example

void calcInputElevator()
{
   // if the pin is high, its the start of an interrupt
   if(digitalRead(ELEVATOR_SIGNAL_IN_PIN) == HIGH)
   {
     // get the time using micros - when our code gets really busy this will become inaccurate, but for the current application its
     // easy to understand and works very well
    ulStartElevator = micros();
   }
   else
   {
     // if the pin is low, its the falling edge of the pulse so now we can calculate the pulse duration by subtracting the
     // start time ulStartElevator from the current time returned by micros()
     if(ulStartElevator && (bNewElevatorSignal == 0))
     {
       nElevatorIn = (int)(micros() - ulStartElevator);
       ulStartElevator = 0;
 
       // tell loop we have a new signal on the Elevator channel
       // we will not update nElevatorIn until loop sets
       // bNewElevatorSignal back to false
       bNewElevatorSignal = 1;
     }
   }
}

#endif
