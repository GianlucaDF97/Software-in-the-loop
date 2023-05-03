# ifndef MATLAB_MEX_FILE
# include <Arduino.h>
# endif

//#include "inttypes.h"

#ifndef _CALCINPUTHOME_H_
#define _CALCINPUTHOME_H_

#define HOME_SIGNAL_IN 38 // INTERRUPT 2 = DIGITAL PIN 21 - use the interrupt number in attachInterrupt
#define HOME_SIGNAL_IN_PIN 38
#define NEUTRAL_HOME 0 // this is the duration in microseconds of neutral throttle on an elect1ric RC Car

extern volatile uint32_t ulStartHOME; 

#ifdef __cplusplus
 extern "C" {
#endif
void calcInputHOME();
#ifdef __cplusplus
}
#endif

extern volatile int16_t nHOMEIn; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
extern volatile int8_t bNewHOMESignal; // set in the interrupt and read in the loop

#endif // _CALCINPUTFILE_H_
