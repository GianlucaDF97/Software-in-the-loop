//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'Aenea_model'.
//
// Model version                  : 1.191
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Tue May  9 15:16:36 2023
//
// Target selection: teensy_ec.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Aenea_model.h"
#include "Arduino.h"

// Overrun counter
static uint8_t uOverrunCounter;
uint8_t GetOverrunCounter(void)
{
  return uOverrunCounter;
}

#define STEP_SIZE                      20000UL                   // Sample Time in microseconds 

unsigned long oldTime;
unsigned long actualTime;
void setup()
{
  // Initialize model
  Aenea_model_initialize();
  oldTime = micros();
}

void loop()
{
  while (1) {
    Aenea_model_step();

    // Get model outputs here
    actualTime = micros();

    // Overrun check
    if ((actualTime - oldTime) >= STEP_SIZE) {
      // We missed our time slot for actual step, report it!
      if (uOverrunCounter < 255U) {
        uOverrunCounter++;
      }

      oldTime = actualTime;            // Update time stamp of last step
      continue;                        // We are late, continue with next step
    }

    // Waiting with pooling method
    while ((actualTime - oldTime) < STEP_SIZE) {
      actualTime = micros();           // Get actual time
    }

    oldTime = actualTime;              // Update time stamp of last step
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
