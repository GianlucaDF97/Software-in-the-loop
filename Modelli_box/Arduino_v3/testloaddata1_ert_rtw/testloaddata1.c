/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testloaddata1.c
 *
 * Code generated for Simulink model 'testloaddata1'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jul  6 18:41:37 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testloaddata1.h"
#include "testloaddata1_private.h"

/* Block signals (default storage) */
B_testloaddata1_T testloaddata1_B;

/* Block states (default storage) */
DW_testloaddata1_T testloaddata1_DW;

/* Real-time model */
static RT_MODEL_testloaddata1_T testloaddata1_M_;
RT_MODEL_testloaddata1_T *const testloaddata1_M = &testloaddata1_M_;

/* Forward declaration for local functions */
static void testloaddata1_SystemCore_setup(codertarget_raspi_internal_SC_T *obj);
static void testloaddata1_SystemCore_setup(codertarget_raspi_internal_SC_T *obj)
{
  static const char_T tmp[12] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'A',
    'M', 'A', '0' };

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
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 57600U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void testloaddata1_step(void)
{
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
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

  /* MATLABSystem: '<S6>/Serial Read' */
  if (testloaddata1_DW.obj_h.SampleTime != testloaddata1_P.SerialRead_SampleTime)
  {
    testloaddata1_DW.obj_h.SampleTime = testloaddata1_P.SerialRead_SampleTime;
  }

  status = MW_SCI_Receive(testloaddata1_DW.obj_h.MW_SCIHANDLE,
    &testloaddata1_B.RxDataLocChar[0], 63U);
  memcpy((void *)&testloaddata1_B.RxData[0], (void *)
         &testloaddata1_B.RxDataLocChar[0], (uint32_T)((size_t)63 * sizeof
          (uint8_T)));

  /* MATLABSystem: '<S2>/Digital Read' */
  if (testloaddata1_DW.obj_k.SampleTime !=
      testloaddata1_P.DigitalRead_SampleTime) {
    testloaddata1_DW.obj_k.SampleTime = testloaddata1_P.DigitalRead_SampleTime;
  }

  tmp = MW_gpioRead(21U);

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  MATLABSystem: '<S2>/Digital Read'
   */
  if ((!tmp) && (testloaddata1_DW.DiscreteTimeIntegrator_PrevRese == 1)) {
    testloaddata1_DW.DiscreteTimeIntegrator_DSTATE =
      testloaddata1_P.DiscreteTimeIntegrator_IC;
  }

  if (testloaddata1_DW.DiscreteTimeIntegrator_DSTATE >=
      testloaddata1_P.DiscreteTimeIntegrator_UpperSat) {
    testloaddata1_DW.DiscreteTimeIntegrator_DSTATE =
      testloaddata1_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (testloaddata1_DW.DiscreteTimeIntegrator_DSTATE <=
        testloaddata1_P.DiscreteTimeIntegrator_LowerSat) {
      testloaddata1_DW.DiscreteTimeIntegrator_DSTATE =
        testloaddata1_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   *  MATLABSystem: '<S6>/Serial Read'
   */
  for (i = 0; i < 63; i++) {
    testloaddata1_B.messaggio[i] = 0U;
  }

  entrata = true;
  if ((status != 0) || (testloaddata1_DW.DiscreteTimeIntegrator_DSTATE < 1.0)) {
    testloaddata1_DW.start_found = false;
    for (i = 0; i < 63; i++) {
      testloaddata1_DW.message[i] = 0U;
    }

    testloaddata1_DW.counter = 0U;
    entrata = false;
  }

  guard1 = false;
  if ((!testloaddata1_DW.start_found) && entrata) {
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i - 1 < 62)) {
      if ((testloaddata1_B.RxData[(uint8_T)i - 1] == 62) &&
          (testloaddata1_B.RxData[(uint8_T)i] == 255)) {
        loop_ub = 63 - (uint8_T)i;
        for (i_0 = 0; i_0 <= loop_ub; i_0++) {
          testloaddata1_DW.message[i_0] = testloaddata1_B.RxData[((uint8_T)i +
            i_0) - 1];
        }

        testloaddata1_DW.counter = (uint8_T)(64 - (uint8_T)i);
        testloaddata1_DW.start_found = true;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (testloaddata1_DW.counter == 63) {
      for (i = 0; i < 63; i++) {
        testloaddata1_B.messaggio[i] = testloaddata1_DW.message[i];
        testloaddata1_DW.message[i] = 0U;
      }

      testloaddata1_DW.start_found = false;
      testloaddata1_DW.counter = 0U;
      guard1 = true;
    }
  } else {
    if (testloaddata1_DW.start_found) {
      qY = 63U - /*MW:OvSatOk*/ testloaddata1_DW.counter;
      if (63U - testloaddata1_DW.counter > 63U) {
        qY = 0U;
      }

      i_0 = (int32_T)(testloaddata1_DW.counter + 1U);
      if (testloaddata1_DW.counter + 1U > 255U) {
        i_0 = 255;
      }

      if ((uint8_T)i_0 > 63) {
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
        testloaddata1_DW.message[(i + i_0) - 1] = testloaddata1_B.RxData[i_0];
      }

      qY = 63U - /*MW:OvSatOk*/ testloaddata1_DW.counter;
      if (63U - testloaddata1_DW.counter > 63U) {
        qY = 0U;
      }

      testloaddata1_DW.counter = (uint8_T)qY;
      for (i = 0; i < 63; i++) {
        testloaddata1_B.messaggio[i] = testloaddata1_DW.message[i];
        testloaddata1_DW.message[i] = 0U;
      }

      status = testloaddata1_DW.counter;
      do {
        exitg2 = 0;
        if (status < 63) {
          if ((testloaddata1_B.RxData[status - 1] == 62) &&
              (testloaddata1_B.RxData[status] == 255)) {
            loop_ub = 63 - status;
            for (i_0 = 0; i_0 <= loop_ub; i_0++) {
              testloaddata1_DW.message[i_0] = testloaddata1_B.RxData[(status +
                i_0) - 1];
            }

            qY = status - /*MW:OvSatOk*/ 1U;
            if (status - 1U > status) {
              qY = 0U;
            }

            testloaddata1_DW.counter = (uint8_T)(63 - (int32_T)qY);
            testloaddata1_DW.start_found = true;
            guard1 = true;
            exitg2 = 1;
          } else {
            testloaddata1_DW.start_found = false;
            testloaddata1_DW.counter = 0U;
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
    /* Outputs for Enabled SubSystem: '<S16>/Subsystem' incorporates:
     *  EnablePort: '<S18>/Enable'
     */
    /* S-Function (byte2any_svd): '<S18>/Byte Unpack' */

    /* Unpack: <S18>/Byte Unpack */
    {
      uint32_T MW_inputPortOffset = 0;
      uint32_T MW_outputPortWidth = 0;
      uint32_T MW_remainder2 = 0;

      /* Packed input data type - uint8_T */
      /* Unpacking the values to output 1 */
      /* Output data type - uint8_T, size - 2 */
      {
        MW_outputPortWidth = 2 * sizeof(uint8_T);
        memcpy((uint8_T*)&testloaddata1_B.ByteUnpack_o1[0], (uint8_T*)
               &testloaddata1_B.messaggio[0] + MW_inputPortOffset,
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
        memcpy((uint8_T*)&testloaddata1_B.ByteUnpack_o2[0], (uint8_T*)
               &testloaddata1_B.messaggio[0] + MW_inputPortOffset,
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
        memcpy((uint8_T*)&testloaddata1_B.ByteUnpack_o3[0], (uint8_T*)
               &testloaddata1_B.messaggio[0] + MW_inputPortOffset,
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
      /* Output data type - uint16_T, size - 10 */
      {
        MW_outputPortWidth = 10 * sizeof(uint16_T);
        memcpy((uint8_T*)&testloaddata1_B.ByteUnpack_o4[0], (uint8_T*)
               &testloaddata1_B.messaggio[0] + MW_inputPortOffset,
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
      /* Output data type - uint8_T, size - 2 */
      {
        MW_outputPortWidth = 2 * sizeof(uint8_T);
        memcpy((uint8_T*)&testloaddata1_B.ByteUnpack_o5[0], (uint8_T*)
               &testloaddata1_B.messaggio[0] + MW_inputPortOffset,
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
      /* Output data type - uint32_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint32_T);
        memcpy((uint8_T*)&testloaddata1_B.ByteUnpack_o6, (uint8_T*)
               &testloaddata1_B.messaggio[0] + MW_inputPortOffset,
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
      /* Output data type - uint8_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(uint8_T);
        memcpy((uint8_T*)&testloaddata1_B.ByteUnpack_o7, (uint8_T*)
               &testloaddata1_B.messaggio[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }
    }

    /* End of Outputs for SubSystem: '<S16>/Subsystem' */
  }

  /* End of MATLAB Function: '<S16>/MATLAB Function' */
  for (i = 0; i < 10; i++) {
    /* SignalConversion generated from: '<S1>/To Workspace' incorporates:
     *  DataTypeConversion: '<S6>/Data Type  Conversion1'
     */
    testloaddata1_B.TmpSignalConversionAtToWork[i] =
      testloaddata1_B.ByteUnpack_o4[i];
  }

  /* MATLABSystem: '<S3>/Digital Read' */
  if (testloaddata1_DW.obj.SampleTime !=
      testloaddata1_P.DigitalRead_SampleTime_p) {
    testloaddata1_DW.obj.SampleTime = testloaddata1_P.DigitalRead_SampleTime_p;
  }

  entrata = MW_gpioRead(4U);

  /* Logic: '<Root>/NOT1' incorporates:
   *  MATLABSystem: '<S3>/Digital Read'
   */
  entrata = !entrata;

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Memory: '<Root>/Memory1'
   */
  if (entrata && (!testloaddata1_DW.Memory1_PreviousInput)) {
    if (testloaddata1_DW.spento) {
      testloaddata1_DW.status = 1.0;
      testloaddata1_DW.spento = false;
    } else {
      testloaddata1_DW.status = 0.0;
      testloaddata1_DW.spento = true;
    }
  }

  /* Outputs for Enabled SubSystem: '<Root>/ 2' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (testloaddata1_DW.status > 0.0) {
    /* Gain: '<S9>/Gain1' */
    tmp_0 = testloaddata1_B.TmpSignalConversionAtToWork[0];

    /* Gain: '<S6>/Gain3' */
    tmp_1 = testloaddata1_B.TmpSignalConversionAtToWork[9];

    /* Gain: '<S6>/Gain' */
    tmp_2 = testloaddata1_B.TmpSignalConversionAtToWork[1];

    /* SignalConversion generated from: '<S1>/To Workspace' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant2'
     *  DataTypeConversion: '<S6>/Data Type  Conversion2'
     *  DataTypeConversion: '<S6>/Data Type  Conversion3'
     *  Gain: '<S6>/Gain'
     *  Gain: '<S6>/Gain3'
     *  Gain: '<S6>/Knot2m//s'
     *  Gain: '<S7>/Gain1'
     *  Gain: '<S8>/Gain1'
     *  Gain: '<S9>/Gain1'
     */
    testloaddata1_B.TmpSignalConversionAtToWork[0] = testloaddata1_P.Gain1_Gain *
      testloaddata1_B.ByteUnpack_o2[0];
    testloaddata1_B.TmpSignalConversionAtToWork[1] =
      testloaddata1_P.Gain1_Gain_g * testloaddata1_B.ByteUnpack_o2[1];
    testloaddata1_B.TmpSignalConversionAtToWork[2] =
      testloaddata1_B.ByteUnpack_o2[2];
    testloaddata1_B.TmpSignalConversionAtToWork[3] =
      testloaddata1_B.ByteUnpack_o2[3];
    testloaddata1_B.TmpSignalConversionAtToWork[4] =
      testloaddata1_P.Gain1_Gain_p * tmp_0;
    testloaddata1_B.TmpSignalConversionAtToWork[5] =
      testloaddata1_P.Constant_Value;
    testloaddata1_B.TmpSignalConversionAtToWork[6] =
      testloaddata1_B.ByteUnpack_o6;
    testloaddata1_B.TmpSignalConversionAtToWork[7] = testloaddata1_P.Gain3_Gain *
      tmp_1;
    testloaddata1_B.TmpSignalConversionAtToWork[8] = testloaddata1_P.Gain_Gain *
      tmp_2 * testloaddata1_P.Knot2ms_Gain;
    testloaddata1_B.TmpSignalConversionAtToWork[9] =
      testloaddata1_P.Constant2_Value;

    /* ToWorkspace: '<S1>/To Workspace' */
    {
      double locTime = testloaddata1_M->Timing.taskTime0;
      ;
      rt_UpdateStructLogVar((StructLogVar *)
                            testloaddata1_DW.ToWorkspace_PWORK.LoggedData,
                            &locTime,
                            &testloaddata1_B.TmpSignalConversionAtToWork[0]);
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */
  /* End of Outputs for SubSystem: '<Root>/ 2' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/Constant1'
   *  MATLABSystem: '<S2>/Digital Read'
   */
  testloaddata1_DW.DiscreteTimeIntegrator_DSTATE +=
    testloaddata1_P.DiscreteTimeIntegrator_gainval *
    testloaddata1_P.Constant1_Value;
  if (testloaddata1_DW.DiscreteTimeIntegrator_DSTATE >=
      testloaddata1_P.DiscreteTimeIntegrator_UpperSat) {
    testloaddata1_DW.DiscreteTimeIntegrator_DSTATE =
      testloaddata1_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (testloaddata1_DW.DiscreteTimeIntegrator_DSTATE <=
        testloaddata1_P.DiscreteTimeIntegrator_LowerSat) {
      testloaddata1_DW.DiscreteTimeIntegrator_DSTATE =
        testloaddata1_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  testloaddata1_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)tmp;

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */

  /* Update for Memory: '<Root>/Memory1' */
  testloaddata1_DW.Memory1_PreviousInput = entrata;

  /* Matfile logging */
  rt_UpdateTXYLogVars(testloaddata1_M->rtwLogInfo,
                      (&testloaddata1_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(testloaddata1_M)!=-1) &&
        !((rtmGetTFinal(testloaddata1_M)-testloaddata1_M->Timing.taskTime0) >
          testloaddata1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testloaddata1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testloaddata1_M->Timing.taskTime0 =
    ((time_T)(++testloaddata1_M->Timing.clockTick0)) *
    testloaddata1_M->Timing.stepSize0;
}

/* Model initialize function */
void testloaddata1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)testloaddata1_M, 0,
                sizeof(RT_MODEL_testloaddata1_T));
  rtmSetTFinal(testloaddata1_M, -1);
  testloaddata1_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    testloaddata1_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(testloaddata1_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(testloaddata1_M->rtwLogInfo, (NULL));
    rtliSetLogT(testloaddata1_M->rtwLogInfo, "");
    rtliSetLogX(testloaddata1_M->rtwLogInfo, "");
    rtliSetLogXFinal(testloaddata1_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(testloaddata1_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(testloaddata1_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(testloaddata1_M->rtwLogInfo, 0);
    rtliSetLogDecimation(testloaddata1_M->rtwLogInfo, 1);
    rtliSetLogY(testloaddata1_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(testloaddata1_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(testloaddata1_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &testloaddata1_B), 0,
                sizeof(B_testloaddata1_T));

  /* states (dwork) */
  (void) memset((void *)&testloaddata1_DW, 0,
                sizeof(DW_testloaddata1_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(testloaddata1_M->rtwLogInfo, 0.0,
    rtmGetTFinal(testloaddata1_M), testloaddata1_M->Timing.stepSize0,
    (&rtmGetErrorStatus(testloaddata1_M)));

  {
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    testloaddata1_DW.DiscreteTimeIntegrator_DSTATE =
      testloaddata1_P.DiscreteTimeIntegrator_IC;
    testloaddata1_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for Memory: '<Root>/Memory1' */
    testloaddata1_DW.Memory1_PreviousInput =
      testloaddata1_P.Memory1_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S16>/MATLAB Function' */
    testloaddata1_DW.start_found = false;
    testloaddata1_DW.counter = 0U;
    for (i = 0; i < 63; i++) {
      testloaddata1_DW.message[i] = 0U;
    }

    /* End of SystemInitialize for MATLAB Function: '<S16>/MATLAB Function' */

    /* SystemInitialize for Enabled SubSystem: '<S16>/Subsystem' */
    /* SystemInitialize for S-Function (byte2any_svd): '<S18>/Byte Unpack' incorporates:
     *  Outport: '<S18>/Out2'
     */
    testloaddata1_B.ByteUnpack_o2[0] = testloaddata1_P.Out2_Y0;
    testloaddata1_B.ByteUnpack_o2[1] = testloaddata1_P.Out2_Y0;
    testloaddata1_B.ByteUnpack_o2[2] = testloaddata1_P.Out2_Y0;
    testloaddata1_B.ByteUnpack_o2[3] = testloaddata1_P.Out2_Y0;
    for (i = 0; i < 9; i++) {
      /* SystemInitialize for S-Function (byte2any_svd): '<S18>/Byte Unpack' incorporates:
       *  Outport: '<S18>/Out3'
       */
      testloaddata1_B.ByteUnpack_o3[i] = testloaddata1_P.Out3_Y0;
    }

    for (i = 0; i < 10; i++) {
      /* SystemInitialize for S-Function (byte2any_svd): '<S18>/Byte Unpack' incorporates:
       *  Outport: '<S18>/Out4'
       */
      testloaddata1_B.ByteUnpack_o4[i] = testloaddata1_P.Out4_Y0;
    }

    /* SystemInitialize for S-Function (byte2any_svd): '<S18>/Byte Unpack' incorporates:
     *  Outport: '<S18>/pressione'
     */
    testloaddata1_B.ByteUnpack_o6 = testloaddata1_P.pressione_Y0;

    /* End of SystemInitialize for SubSystem: '<S16>/Subsystem' */

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function2' */
    testloaddata1_DW.status = 0.0;
    testloaddata1_DW.spento = true;

    /* SystemInitialize for Enabled SubSystem: '<Root>/ 2' */
    /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
    {
      static int_T rt_ToWksWidths[] = { 10 };

      static int_T rt_ToWksNumDimensions[] = { 1 };

      static int_T rt_ToWksDimensions[] = { 10 };

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

      static const char_T rt_ToWksBlockName[] = "testloaddata1/\n2/To Workspace";
      testloaddata1_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
        testloaddata1_M->rtwLogInfo,
        0.0,
        rtmGetTFinal(testloaddata1_M),
        testloaddata1_M->Timing.stepSize0,
        (&rtmGetErrorStatus(testloaddata1_M)),
        "LOG_data",
        1,
        0,
        1,
        0.02,
        &rt_ToWksSignalInfo,
        rt_ToWksBlockName);
      if (testloaddata1_DW.ToWorkspace_PWORK.LoggedData == (NULL))
        return;
    }

    /* End of SystemInitialize for SubSystem: '<Root>/ 2' */

    /* Start for MATLABSystem: '<S6>/Serial Read' */
    testloaddata1_DW.obj_h.isInitialized = 0;
    testloaddata1_DW.obj_h.matlabCodegenIsDeleted = false;
    testloaddata1_DW.obj_h.SampleTime = testloaddata1_P.SerialRead_SampleTime;
    testloaddata1_SystemCore_setup(&testloaddata1_DW.obj_h);

    /* Start for MATLABSystem: '<S2>/Digital Read' */
    testloaddata1_DW.obj_k.matlabCodegenIsDeleted = false;
    testloaddata1_DW.obj_k.SampleTime = testloaddata1_P.DigitalRead_SampleTime;
    testloaddata1_DW.obj_k.isInitialized = 1;
    MW_gpioInit(21U, false);
    testloaddata1_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Read' */
    testloaddata1_DW.obj.matlabCodegenIsDeleted = false;
    testloaddata1_DW.obj.SampleTime = testloaddata1_P.DigitalRead_SampleTime_p;
    testloaddata1_DW.obj.isInitialized = 1;
    MW_gpioInit(4U, false);
    testloaddata1_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void testloaddata1_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/Serial Read' */
  if (!testloaddata1_DW.obj_h.matlabCodegenIsDeleted) {
    testloaddata1_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((testloaddata1_DW.obj_h.isInitialized == 1) &&
        testloaddata1_DW.obj_h.isSetupComplete) {
      MW_SCI_Close(testloaddata1_DW.obj_h.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Serial Read' */

  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  if (!testloaddata1_DW.obj_k.matlabCodegenIsDeleted) {
    testloaddata1_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((testloaddata1_DW.obj_k.isInitialized == 1) &&
        testloaddata1_DW.obj_k.isSetupComplete) {
      MW_gpioTerminate(21U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Read' */

  /* Terminate for MATLABSystem: '<S3>/Digital Read' */
  if (!testloaddata1_DW.obj.matlabCodegenIsDeleted) {
    testloaddata1_DW.obj.matlabCodegenIsDeleted = true;
    if ((testloaddata1_DW.obj.isInitialized == 1) &&
        testloaddata1_DW.obj.isSetupComplete) {
      MW_gpioTerminate(4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Read' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
