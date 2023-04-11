# ifndef MATLAB_MEX_FILE
# include <Arduino.h>
# endif

//#include "inttypes.h"

#ifndef _CALCINPUTTHROTTLE_H_
#define _CALCINPUTTHROTTLE_H_

#define THROTTLE_SIGNAL_IN 50 // INTERRUPT 0 = DIGITAL PIN 2 - use the interrupt number in attachInterrupt
#define THROTTLE_SIGNAL_IN_PIN 50 // INTERRUPT 0 = DIGITAL PIN 2 - use the PIN number in digitalRead
#define NEUTRAL_THROTTLE 1500 // this is the duration in microseconds of neutral throttle on an elect1ric RC Car

extern volatile uint32_t ulStartThrottle; 

#ifdef __cplusplus
 extern "C" {
#endif
void calcInputThrottle();
#ifdef __cplusplus
}
#endif

extern volatile int16_t nThrottleIn; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
extern volatile int8_t bNewThrottleSignal; // set in the interrupt and read in the loop

#endif // _CALCINPUTFILE_H_
