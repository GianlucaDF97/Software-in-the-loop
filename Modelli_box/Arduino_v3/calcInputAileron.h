# ifndef MATLAB_MEX_FILE
# include <Arduino.h>
# endif

//#include "inttypes.h"

#ifndef _CALCINPUTAILERON_H_
#define _CALCINPUTAILERON_H_

#define AILERON_SIGNAL_IN 32 // INTERRUPT 2 = DIGITAL PIN 21 - use the interrupt number in attachInterrupt
#define AILERON_SIGNAL_IN_PIN 32 // INTERRUPT 2 = DIGITAL PIN 21 - use the PIN number in digitalRead
#define NEUTRAL_AILERON 1500 // this is the duration in microseconds of neutral throttle on an elect1ric RC Car

extern volatile uint32_t ulStartAileron; 
extern void calcInputAileron();

extern volatile int16_t nAileronIn; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
extern volatile int8_t bNewAileronSignal; // set in the interrupt and read in the loop

#endif // _CALCINPUTFILE_H_
