# ifndef RUDDER
# include <Arduino.h>
# endif

//#include "inttypes.h"

#ifndef _CALCINPUTRUDDER_H_
#define _CALCINPUTRUDDER_H_

#define RUDDER_SIGNAL_IN 37 // INTERRUPT 3 = DIGITAL PIN 20 - use the interrupt number in attachInterrupt
#define RUDDER_SIGNAL_IN_PIN 37 // INTERRUPT 3 = DIGITAL PIN 20 - use the PIN number in digitalRead
#define NEUTRAL_RUDDER 1500 // this is the duration in microseconds of neutral throttle on an elect1ric RC Car
//Timone ha il canale 3
//L'uscita ha il pin 4

extern volatile uint32_t ulStartRudder; 

#ifdef __cplusplus
 extern "C" {
#endif
void calcInputRudder();
#ifdef __cplusplus
}
#endif

extern volatile int16_t nRudderIn; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
extern volatile int8_t bNewRudderSignal; // set in the interrupt and read in the loop

#endif // _CALCINPUTFILE_H_
