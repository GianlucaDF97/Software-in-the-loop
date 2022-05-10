/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testloaddata_09_27.c
 *
 * Code generated for Simulink model 'testloaddata_09_27'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Sep 27 14:18:56 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testloaddata_09_27.h"
#include "testloaddata_09_27_private.h"

/* Block signals (default storage) */
B_testloaddata_09_27_T testloaddata_09_27_B;

/* Block states (default storage) */
DW_testloaddata_09_27_T testloaddata_09_27_DW;

/* Real-time model */
static RT_MODEL_testloaddata_09_27_T testloaddata_09_27_M_;
RT_MODEL_testloaddata_09_27_T *const testloaddata_09_27_M =
  &testloaddata_09_27_M_;

/* Forward declaration for local functions */
static void testloaddata_0_SystemCore_setup(codertarget_raspi_internal_SC_T *obj);
static void testloaddata_0_SystemCore_setup(codertarget_raspi_internal_SC_T *obj)
{
  static const char_T tmp[12] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'A',
    'C', 'M', '0' };

  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T TxPinLoc;
  void* SCIModuleVoidPtr;
  int32_T i;
  char_T b_SCIModuleLoc[13];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  TxPinLoc = MW_UNDEFINED_VALUE;
  for (i = 0; i < 12; i++) {
    b_SCIModuleLoc[i] = tmp[i];
  }

  b_SCIModuleLoc[12] = '\x00';
  SCIModuleVoidPtr = (void*)(&b_SCIModuleLoc[0]);
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleVoidPtr, true, RxPinLoc, TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void testloaddata_09_27_step(void)
{
  int32_T exitg2;
  int32_T i;
  int32_T i_0;
  int32_T loop_ub;
  uint32_T qY;
  uint8_T status;
  boolean_T entrata;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T tmp;

  /* MATLABSystem: '<S4>/Serial Read' */
  if (testloaddata_09_27_DW.obj_h.SampleTime !=
      testloaddata_09_27_P.SerialRead_SampleTime) {
    testloaddata_09_27_DW.obj_h.SampleTime =
      testloaddata_09_27_P.SerialRead_SampleTime;
  }

  status = MW_SCI_Receive(testloaddata_09_27_DW.obj_h.MW_SCIHANDLE,
    &testloaddata_09_27_B.RxDataLocChar[0], 67U);
  memcpy((void *)&testloaddata_09_27_B.RxData[0], (void *)
         &testloaddata_09_27_B.RxDataLocChar[0], (uint32_T)((size_t)67 * sizeof
          (uint8_T)));

  /* MATLABSystem: '<S2>/Digital Read' */
  if (testloaddata_09_27_DW.obj.SampleTime !=
      testloaddata_09_27_P.DigitalRead_SampleTime) {
    testloaddata_09_27_DW.obj.SampleTime =
      testloaddata_09_27_P.DigitalRead_SampleTime;
  }

  tmp = MW_gpioRead(21U);

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  MATLABSystem: '<S2>/Digital Read'
   */
  if ((!tmp) && (testloaddata_09_27_DW.DiscreteTimeIntegrator_PrevRese == 1)) {
    testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE =
      testloaddata_09_27_P.DiscreteTimeIntegrator_IC;
  }

  if (testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE >=
      testloaddata_09_27_P.DiscreteTimeIntegrator_UpperSat) {
    testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE =
      testloaddata_09_27_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE <=
        testloaddata_09_27_P.DiscreteTimeIntegrator_LowerSat) {
      testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE =
        testloaddata_09_27_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   *  MATLABSystem: '<S4>/Serial Read'
   */
  memset(&testloaddata_09_27_B.messaggio[0], 0, 67U * sizeof(uint8_T));
  entrata = true;
  if ((status != 0) || (testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE <
                        1.0)) {
    testloaddata_09_27_DW.start_found = false;
    memset(&testloaddata_09_27_DW.message[0], 0, 67U * sizeof(uint8_T));
    testloaddata_09_27_DW.counter = 0U;
    entrata = false;
  }

  guard1 = false;
  if ((!testloaddata_09_27_DW.start_found) && entrata) {
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i - 1 < 66)) {
      if ((testloaddata_09_27_B.RxData[(uint8_T)i - 1] == 62) &&
          (testloaddata_09_27_B.RxData[(uint8_T)i] == 255)) {
        loop_ub = 67 - (uint8_T)i;
        for (i_0 = 0; i_0 <= loop_ub; i_0++) {
          testloaddata_09_27_DW.message[i_0] = testloaddata_09_27_B.RxData
            [((uint8_T)i + i_0) - 1];
        }

        testloaddata_09_27_DW.counter = (uint8_T)(68 - (uint8_T)i);
        testloaddata_09_27_DW.start_found = true;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (testloaddata_09_27_DW.counter == 67) {
      for (i = 0; i < 67; i++) {
        testloaddata_09_27_B.messaggio[i] = testloaddata_09_27_DW.message[i];
        testloaddata_09_27_DW.message[i] = 0U;
      }

      testloaddata_09_27_DW.start_found = false;
      testloaddata_09_27_DW.counter = 0U;
      guard1 = true;
    }
  } else {
    if (testloaddata_09_27_DW.start_found) {
      qY = 67U - /*MW:OvSatOk*/ testloaddata_09_27_DW.counter;
      if (67U - testloaddata_09_27_DW.counter > 67U) {
        qY = 0U;
      }

      i_0 = (int32_T)(testloaddata_09_27_DW.counter + 1U);
      if (testloaddata_09_27_DW.counter + 1U > 255U) {
        i_0 = 255;
      }

      if ((uint8_T)i_0 > 67) {
        i = 1;
      } else {
        i = (uint8_T)i_0;
      }

      if (1 > (uint8_T)qY) {
        loop_ub = -1;
      } else {
        loop_ub = (uint8_T)qY - 1;
      }

      for (i_0 = 0; i_0 <= loop_ub; i_0++) {
        testloaddata_09_27_DW.message[(i + i_0) - 1] =
          testloaddata_09_27_B.RxData[i_0];
      }

      qY = 67U - /*MW:OvSatOk*/ testloaddata_09_27_DW.counter;
      if (67U - testloaddata_09_27_DW.counter > 67U) {
        qY = 0U;
      }

      testloaddata_09_27_DW.counter = (uint8_T)qY;
      for (i = 0; i < 67; i++) {
        testloaddata_09_27_B.messaggio[i] = testloaddata_09_27_DW.message[i];
        testloaddata_09_27_DW.message[i] = 0U;
      }

      status = testloaddata_09_27_DW.counter;
      do {
        exitg2 = 0;
        if (status < 67) {
          if ((testloaddata_09_27_B.RxData[status - 1] == 62) &&
              (testloaddata_09_27_B.RxData[status] == 255)) {
            loop_ub = 67 - status;
            for (i_0 = 0; i_0 <= loop_ub; i_0++) {
              testloaddata_09_27_DW.message[i_0] = testloaddata_09_27_B.RxData
                [(status + i_0) - 1];
            }

            qY = status - /*MW:OvSatOk*/ 1U;
            if (status - 1U > status) {
              qY = 0U;
            }

            testloaddata_09_27_DW.counter = (uint8_T)(67 - (int32_T)qY);
            testloaddata_09_27_DW.start_found = true;
            guard1 = true;
            exitg2 = 1;
          } else {
            testloaddata_09_27_DW.start_found = false;
            testloaddata_09_27_DW.counter = 0U;
            status++;
          }
        } else {
          guard1 = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
  }

  if (guard1) {
    /* Outputs for Enabled SubSystem: '<S14>/Subsystem' incorporates:
     *  EnablePort: '<S16>/Enable'
     */
    /* S-Function (byte2any_svd): '<S16>/Byte Unpack' */

    /* Unpack: <S16>/Byte Unpack */
    {
      uint32_T MW_inputPortOffset = 0;
      uint32_T MW_outputPortWidth = 0;
      uint32_T MW_remainder2 = 0;

      /* Packed input data type - uint8_T */
      /* Unpacking the values to output 1 */
      /* Output data type - uint8_T, size - 2 */
      {
        MW_outputPortWidth = 2 * sizeof(uint8_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o1[0], (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 2 */
      /* Output data type - real32_T, size - 4 */
      {
        MW_outputPortWidth = 4 * sizeof(real32_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o2[0], (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 3 */
      /* Output data type - int16_T, size - 9 */
      {
        MW_outputPortWidth = 9 * sizeof(int16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o3[0], (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 4 */
      /* Output data type - uint16_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o4, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 5 */
      /* Output data type - uint16_T, size - 3 */
      {
        MW_outputPortWidth = 3 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o5[0], (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 6 */
      /* Output data type - uint16_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o6, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 7 */
      /* Output data type - uint16_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o7, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 8 */
      /* Output data type - uint16_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o8, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 9 */
      /* Output data type - uint16_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o9, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 10 */
      /* Output data type - uint16_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o10, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 11 */
      /* Output data type - uint16_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o11, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 12 */
      /* Output data type - uint16_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o12, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 13 */
      /* Output data type - uint16_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o13, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 14 */
      /* Output data type - uint8_T, size - 2 */
      {
        MW_outputPortWidth = 2 * sizeof(uint8_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o14[0], (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 15 */
      /* Output data type - uint32_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint32_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o15, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }

      /* Offset calculations based on alignemnt for packing next input */
      MW_remainder2 = MW_outputPortWidth % 1;
      if (MW_remainder2 == 0) {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth;
      } else {
        MW_inputPortOffset = MW_inputPortOffset + MW_outputPortWidth + (1 -
          MW_remainder2);
      }

      /* Unpacking the values to output 16 */
      /* Output data type - uint8_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint8_T);
        memcpy((uint8_T*)&testloaddata_09_27_B.ByteUnpack_o16, (uint8_T*)
               &testloaddata_09_27_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }
    }

    /* End of Outputs for SubSystem: '<S14>/Subsystem' */
  }

  /* End of MATLAB Function: '<S14>/MATLAB Function' */

  /* Gain: '<S4>/Gain2' incorporates:
   *  DataTypeConversion: '<S4>/Data Type  Conversion'
   */
  for (i = 0; i < 9; i++) {
    testloaddata_09_27_B.Gain2[i] = testloaddata_09_27_P.Gain2_Gain * (real_T)
      testloaddata_09_27_B.ByteUnpack_o3[i];
  }

  /* End of Gain: '<S4>/Gain2' */

  /* Outputs for Enabled SubSystem: '<Root>/ 2' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  /* Constant: '<Root>/Constant3' */
  if (testloaddata_09_27_P.Constant3_Value > 0.0) {
    /* SignalConversion generated from: '<S1>/To Workspace' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant2'
     *  DataTypeConversion: '<S4>/Data Type  Conversion1'
     *  DataTypeConversion: '<S4>/Data Type  Conversion12'
     *  DataTypeConversion: '<S4>/Data Type  Conversion2'
     *  DataTypeConversion: '<S4>/Data Type  Conversion3'
     *  DataTypeConversion: '<S4>/Data Type  Conversion4'
     *  Gain: '<S10>/Gain1'
     *  Gain: '<S4>/Gain3'
     *  Gain: '<S4>/Knot2m//s*0.01'
     *  Gain: '<S5>/Gain1'
     *  Gain: '<S6>/Gain1'
     *  Gain: '<S7>/Gain1'
     *  Gain: '<S8>/Gain1'
     *  Gain: '<S9>/Gain1'
     */
    testloaddata_09_27_B.TmpSignalConversionAtToWork[0] =
      testloaddata_09_27_P.Gain1_Gain * testloaddata_09_27_B.ByteUnpack_o2[0];
    testloaddata_09_27_B.TmpSignalConversionAtToWork[1] =
      testloaddata_09_27_P.Gain1_Gain_g * testloaddata_09_27_B.ByteUnpack_o2[1];
    testloaddata_09_27_B.TmpSignalConversionAtToWork[2] =
      testloaddata_09_27_B.ByteUnpack_o2[2];
    testloaddata_09_27_B.TmpSignalConversionAtToWork[3] =
      testloaddata_09_27_P.Gain1_Gain_l * testloaddata_09_27_B.Gain2[0];
    testloaddata_09_27_B.TmpSignalConversionAtToWork[4] =
      testloaddata_09_27_P.Gain1_Gain_d * testloaddata_09_27_B.Gain2[1];
    testloaddata_09_27_B.TmpSignalConversionAtToWork[5] =
      testloaddata_09_27_P.Gain1_Gain_df * testloaddata_09_27_B.Gain2[2];
    testloaddata_09_27_B.TmpSignalConversionAtToWork[6] =
      testloaddata_09_27_B.ByteUnpack_o2[3];
    testloaddata_09_27_B.TmpSignalConversionAtToWork[7] =
      testloaddata_09_27_P.Gain1_Gain_p * (real_T)
      testloaddata_09_27_B.ByteUnpack_o4;
    testloaddata_09_27_B.TmpSignalConversionAtToWork[8] =
      testloaddata_09_27_P.Constant_Value;
    testloaddata_09_27_B.TmpSignalConversionAtToWork[9] =
      testloaddata_09_27_B.ByteUnpack_o15;
    testloaddata_09_27_B.TmpSignalConversionAtToWork[10] =
      testloaddata_09_27_P.Gain3_Gain * (real_T)
      testloaddata_09_27_B.ByteUnpack_o13;
    testloaddata_09_27_B.TmpSignalConversionAtToWork[11] =
      testloaddata_09_27_P.Knot2ms001_Gain * (real_T)
      testloaddata_09_27_B.ByteUnpack_o5[0];
    testloaddata_09_27_B.TmpSignalConversionAtToWork[12] =
      testloaddata_09_27_P.Knot2ms001_Gain * (real_T)
      testloaddata_09_27_B.ByteUnpack_o5[1];
    testloaddata_09_27_B.TmpSignalConversionAtToWork[13] =
      testloaddata_09_27_P.Knot2ms001_Gain * (real_T)
      testloaddata_09_27_B.ByteUnpack_o5[2];
    testloaddata_09_27_B.TmpSignalConversionAtToWork[14] =
      testloaddata_09_27_P.Constant2_Value;

    /* ToWorkspace: '<S1>/To Workspace' */
    {
      double locTime = testloaddata_09_27_M->Timing.taskTime0;
      ;
      rt_UpdateStructLogVar((StructLogVar *)
                            testloaddata_09_27_DW.ToWorkspace_PWORK.LoggedData,
                            &locTime,
                            &testloaddata_09_27_B.TmpSignalConversionAtToWork[0]);
    }
  }

  /* End of Constant: '<Root>/Constant3' */
  /* End of Outputs for SubSystem: '<Root>/ 2' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/Constant1'
   *  MATLABSystem: '<S2>/Digital Read'
   */
  testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE +=
    testloaddata_09_27_P.DiscreteTimeIntegrator_gainval *
    testloaddata_09_27_P.Constant1_Value;
  if (testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE >=
      testloaddata_09_27_P.DiscreteTimeIntegrator_UpperSat) {
    testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE =
      testloaddata_09_27_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE <=
        testloaddata_09_27_P.DiscreteTimeIntegrator_LowerSat) {
      testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE =
        testloaddata_09_27_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  testloaddata_09_27_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)tmp;

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(testloaddata_09_27_M->rtwLogInfo,
                      (&testloaddata_09_27_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(testloaddata_09_27_M)!=-1) &&
        !((rtmGetTFinal(testloaddata_09_27_M)-
           testloaddata_09_27_M->Timing.taskTime0) >
          testloaddata_09_27_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testloaddata_09_27_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testloaddata_09_27_M->Timing.taskTime0 =
    ((time_T)(++testloaddata_09_27_M->Timing.clockTick0)) *
    testloaddata_09_27_M->Timing.stepSize0;
}

/* Model initialize function */
void testloaddata_09_27_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)testloaddata_09_27_M, 0,
                sizeof(RT_MODEL_testloaddata_09_27_T));
  rtmSetTFinal(testloaddata_09_27_M, -1);
  testloaddata_09_27_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    testloaddata_09_27_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(testloaddata_09_27_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(testloaddata_09_27_M->rtwLogInfo, (NULL));
    rtliSetLogT(testloaddata_09_27_M->rtwLogInfo, "");
    rtliSetLogX(testloaddata_09_27_M->rtwLogInfo, "");
    rtliSetLogXFinal(testloaddata_09_27_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(testloaddata_09_27_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(testloaddata_09_27_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(testloaddata_09_27_M->rtwLogInfo, 0);
    rtliSetLogDecimation(testloaddata_09_27_M->rtwLogInfo, 1);
    rtliSetLogY(testloaddata_09_27_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(testloaddata_09_27_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(testloaddata_09_27_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &testloaddata_09_27_B), 0,
                sizeof(B_testloaddata_09_27_T));

  /* states (dwork) */
  (void) memset((void *)&testloaddata_09_27_DW, 0,
                sizeof(DW_testloaddata_09_27_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(testloaddata_09_27_M->rtwLogInfo, 0.0,
    rtmGetTFinal(testloaddata_09_27_M), testloaddata_09_27_M->Timing.stepSize0,
    (&rtmGetErrorStatus(testloaddata_09_27_M)));

  {
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    testloaddata_09_27_DW.DiscreteTimeIntegrator_DSTATE =
      testloaddata_09_27_P.DiscreteTimeIntegrator_IC;
    testloaddata_09_27_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* SystemInitialize for MATLAB Function: '<S14>/MATLAB Function' */
    testloaddata_09_27_DW.start_found = false;
    testloaddata_09_27_DW.counter = 0U;
    memset(&testloaddata_09_27_DW.message[0], 0, 67U * sizeof(uint8_T));

    /* SystemInitialize for Enabled SubSystem: '<S14>/Subsystem' */
    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/Out2'
     */
    testloaddata_09_27_B.ByteUnpack_o2[0] = testloaddata_09_27_P.Out2_Y0;
    testloaddata_09_27_B.ByteUnpack_o2[1] = testloaddata_09_27_P.Out2_Y0;
    testloaddata_09_27_B.ByteUnpack_o2[2] = testloaddata_09_27_P.Out2_Y0;
    testloaddata_09_27_B.ByteUnpack_o2[3] = testloaddata_09_27_P.Out2_Y0;
    for (i = 0; i < 9; i++) {
      /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
       *  Outport: '<S16>/Out3'
       */
      testloaddata_09_27_B.ByteUnpack_o3[i] = testloaddata_09_27_P.Out3_Y0;
    }

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/hdg'
     */
    testloaddata_09_27_B.ByteUnpack_o4 = testloaddata_09_27_P.hdg_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/Output'
     */
    testloaddata_09_27_B.ByteUnpack_o5[0] = testloaddata_09_27_P.Output_Y0;
    testloaddata_09_27_B.ByteUnpack_o5[1] = testloaddata_09_27_P.Output_Y0;
    testloaddata_09_27_B.ByteUnpack_o5[2] = testloaddata_09_27_P.Output_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/Output1'
     */
    testloaddata_09_27_B.ByteUnpack_o6 = testloaddata_09_27_P.Output1_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/Output2'
     */
    testloaddata_09_27_B.ByteUnpack_o7 = testloaddata_09_27_P.Output2_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/Output3'
     */
    testloaddata_09_27_B.ByteUnpack_o8 = testloaddata_09_27_P.Output3_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/Output4'
     */
    testloaddata_09_27_B.ByteUnpack_o9 = testloaddata_09_27_P.Output4_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/Output5'
     */
    testloaddata_09_27_B.ByteUnpack_o10 = testloaddata_09_27_P.Output5_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/Output6'
     */
    testloaddata_09_27_B.ByteUnpack_o11 = testloaddata_09_27_P.Output6_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/Output7'
     */
    testloaddata_09_27_B.ByteUnpack_o12 = testloaddata_09_27_P.Output7_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/T'
     */
    testloaddata_09_27_B.ByteUnpack_o13 = testloaddata_09_27_P.T_Y0;

    /* SystemInitialize for S-Function (byte2any_svd): '<S16>/Byte Unpack' incorporates:
     *  Outport: '<S16>/pressione'
     */
    testloaddata_09_27_B.ByteUnpack_o15 = testloaddata_09_27_P.pressione_Y0;

    /* End of SystemInitialize for SubSystem: '<S14>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/ 2' */
    /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
    {
      static int_T rt_ToWksWidths[] = { 15 };

      static int_T rt_ToWksNumDimensions[] = { 1 };

      static int_T rt_ToWksDimensions[] = { 15 };

      static boolean_T rt_ToWksIsVarDims[] = { 0 };

      static void *rt_ToWksCurrSigDims[] = { (NULL) };

      static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

      static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

      static int_T rt_ToWksComplexSignals[] = { 0 };

      static int_T rt_ToWksFrameData[] = { 0 };

      static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
        (NULL)
      };

      static const char_T *rt_ToWksLabels[] = { "" };

      static RTWLogSignalInfo rt_ToWksSignalInfo = {
        1,
        rt_ToWksWidths,
        rt_ToWksNumDimensions,
        rt_ToWksDimensions,
        rt_ToWksIsVarDims,
        rt_ToWksCurrSigDims,
        rt_ToWksCurrSigDimsSize,
        rt_ToWksDataTypeIds,
        rt_ToWksComplexSignals,
        rt_ToWksFrameData,
        rt_ToWksLoggingPreprocessingFcnPtrs,

        { rt_ToWksLabels },
        (NULL),
        (NULL),
        (NULL),

        { (NULL) },

        { (NULL) },
        (NULL),
        (NULL)
      };

      static const char_T rt_ToWksBlockName[] =
        "testloaddata_09_27/\n2/To Workspace";
      testloaddata_09_27_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar
        (
         testloaddata_09_27_M->rtwLogInfo,
         0.0,
         rtmGetTFinal(testloaddata_09_27_M),
         testloaddata_09_27_M->Timing.stepSize0,
         (&rtmGetErrorStatus(testloaddata_09_27_M)),
         "LOG_data",
         1,
         0,
         1,
         0.02,
         &rt_ToWksSignalInfo,
         rt_ToWksBlockName);
      if (testloaddata_09_27_DW.ToWorkspace_PWORK.LoggedData == (NULL))
        return;
    }

    /* End of SystemInitialize for SubSystem: '<Root>/ 2' */

    /* Start for MATLABSystem: '<S4>/Serial Read' */
    testloaddata_09_27_DW.obj_h.isInitialized = 0;
    testloaddata_09_27_DW.obj_h.matlabCodegenIsDeleted = false;
    testloaddata_09_27_DW.obj_h.SampleTime =
      testloaddata_09_27_P.SerialRead_SampleTime;
    testloaddata_0_SystemCore_setup(&testloaddata_09_27_DW.obj_h);

    /* Start for MATLABSystem: '<S2>/Digital Read' */
    testloaddata_09_27_DW.obj.matlabCodegenIsDeleted = false;
    testloaddata_09_27_DW.obj.SampleTime =
      testloaddata_09_27_P.DigitalRead_SampleTime;
    testloaddata_09_27_DW.obj.isInitialized = 1;
    MW_gpioInit(21U, false);
    testloaddata_09_27_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void testloaddata_09_27_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Serial Read' */
  if (!testloaddata_09_27_DW.obj_h.matlabCodegenIsDeleted) {
    testloaddata_09_27_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((testloaddata_09_27_DW.obj_h.isInitialized == 1) &&
        testloaddata_09_27_DW.obj_h.isSetupComplete) {
      MW_SCI_Close(testloaddata_09_27_DW.obj_h.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Serial Read' */

  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  if (!testloaddata_09_27_DW.obj.matlabCodegenIsDeleted) {
    testloaddata_09_27_DW.obj.matlabCodegenIsDeleted = true;
    if ((testloaddata_09_27_DW.obj.isInitialized == 1) &&
        testloaddata_09_27_DW.obj.isSetupComplete) {
      MW_gpioTerminate(21U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Read' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
