# ifndef MATLAB_MEX_FILE
# include <Arduino.h>
# endif

//#include "inttypes.h"

#ifndef _CALCINPUTELEVATOR_H_
#define _CALCINPUTELEVATOR_H_

#define ELEVATOR_SIGNAL_IN 40 // INTERRUPT 1 = DIGITAL PIN 3 - use the interrupt number in attachInterrupt
#define ELEVATOR_SIGNAL_IN_PIN 40 // INTERRUPT 1 = DIGITAL PIN 3 - use the PIN number in digitalRead
#define NEUTRAL_ELEVATOR 1500 // this is the duration in microseconds of neutral throttle on an elect1ric RC Car

extern volatile uint32_t ulStartElevator; 
extern void calcInputElevator();

extern volatile int16_t nElevatorIn; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
extern volatile int8_t bNewElevatorSignal; // set in the interrupt and read in the loop

#endif // _CALCINPUTELEVATOR_H_
