/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestSingoloInvio90721.c
 *
 * Code generated for Simulink model 'TestSingoloInvio90721'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jul  9 17:53:27 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestSingoloInvio90721.h"
#include "TestSingoloInvio90721_private.h"

/* Block signals (default storage) */
B_TestSingoloInvio90721_T TestSingoloInvio90721_B;

/* Block states (default storage) */
DW_TestSingoloInvio90721_T TestSingoloInvio90721_DW;

/* Real-time model */
static RT_MODEL_TestSingoloInvio9072_T TestSingoloInvio90721_M_;
RT_MODEL_TestSingoloInvio9072_T *const TestSingoloInvio90721_M =
  &TestSingoloInvio90721_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void TestSingoloInvio90721_step(void)
{
  real_T tmp;
  int32_T i;

  /* DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant24'
   */
  TestSingoloInvio90721_B.DataTypeConversion6[0] = (real32_T)
    TestSingoloInvio90721_P.Constant_Value;
  TestSingoloInvio90721_B.DataTypeConversion6[1] = (real32_T)
    TestSingoloInvio90721_P.Constant1_Value;
  TestSingoloInvio90721_B.DataTypeConversion6[2] = (real32_T)
    TestSingoloInvio90721_P.Constant2_Value;
  TestSingoloInvio90721_B.DataTypeConversion6[3] = (real32_T)
    TestSingoloInvio90721_P.Constant24_Value;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant3_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  TestSingoloInvio90721_B.DataTypeConversion3[0] = (int16_T)(tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant4_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  TestSingoloInvio90721_B.DataTypeConversion3[1] = (int16_T)(tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant9_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  TestSingoloInvio90721_B.DataTypeConversion3[2] = (int16_T)(tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant5_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  TestSingoloInvio90721_B.DataTypeConversion3[3] = (int16_T)(tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant7_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  TestSingoloInvio90721_B.DataTypeConversion3[4] = (int16_T)(tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant6_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  TestSingoloInvio90721_B.DataTypeConversion3[5] = (int16_T)(tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant8_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  TestSingoloInvio90721_B.DataTypeConversion3[6] = (int16_T)(tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant10'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant10_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  TestSingoloInvio90721_B.DataTypeConversion3[7] = (int16_T)(tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant11'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant11_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  TestSingoloInvio90721_B.DataTypeConversion3[8] = (int16_T)(tmp < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant12'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant12_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TestSingoloInvio90721_B.GPSServo[0] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant13'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant13_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TestSingoloInvio90721_B.GPSServo[1] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant14'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant14_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TestSingoloInvio90721_B.GPSServo[2] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant15'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant15_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TestSingoloInvio90721_B.GPSServo[3] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant16'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant16_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TestSingoloInvio90721_B.GPSServo[4] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant17'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant17_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TestSingoloInvio90721_B.GPSServo[5] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant18'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant18_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TestSingoloInvio90721_B.GPSServo[6] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant19'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant19_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TestSingoloInvio90721_B.GPSServo[7] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant20'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant20_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TestSingoloInvio90721_B.GPSServo[8] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant21'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant21_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TestSingoloInvio90721_B.GPSServo[9] = (uint16_T)(tmp < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  Constant: '<Root>/Constant25'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant25_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  TestSingoloInvio90721_B.DataTypeConversion8[0] = (uint8_T)(tmp < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant22'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant22_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  TestSingoloInvio90721_B.DataTypeConversion8[1] = (uint8_T)(tmp < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* DataTypeConversion: '<Root>/Data Type Conversion9' incorporates:
   *  Constant: '<Root>/Constant23'
   */
  tmp = floor(TestSingoloInvio90721_P.Constant23_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  TestSingoloInvio90721_B.pressione = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* S-Function (any2byte_svd): '<Root>/Byte Pack' incorporates:
   *  Constant: '<Root>/Fine MSG1'
   *  Constant: '<Root>/Inizio MSG'
   */

  /* Pack: <Root>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&TestSingoloInvio90721_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &TestSingoloInvio90721_P.InizioMSG_Value[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 2 */
    /* Input data type - real32_T, size - 4 */
    {
      MW_inputPortWidth = 4 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&TestSingoloInvio90721_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &TestSingoloInvio90721_B.DataTypeConversion6[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 3 */
    /* Input data type - int16_T, size - 9 */
    {
      MW_inputPortWidth = 9 * sizeof(int16_T);
      memcpy((uint8_T*)((uint8_T*)&TestSingoloInvio90721_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &TestSingoloInvio90721_B.DataTypeConversion3[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 4 */
    /* Input data type - uint16_T, size - 10 */
    {
      MW_inputPortWidth = 10 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&TestSingoloInvio90721_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &TestSingoloInvio90721_B.GPSServo[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 5 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&TestSingoloInvio90721_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &TestSingoloInvio90721_B.DataTypeConversion8[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 6 */
    /* Input data type - uint32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint32_T);
      memcpy((uint8_T*)((uint8_T*)&TestSingoloInvio90721_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &TestSingoloInvio90721_B.pressione, MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 7 */
    /* Input data type - uint8_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&TestSingoloInvio90721_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &TestSingoloInvio90721_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<Root>/Serial Transmit' */
  if (TestSingoloInvio90721_DW.obj.Protocol !=
      TestSingoloInvio90721_P.SerialTransmit_Protocol) {
    TestSingoloInvio90721_DW.obj.Protocol =
      TestSingoloInvio90721_P.SerialTransmit_Protocol;
  }

  for (i = 0; i < 63; i++) {
    TestSingoloInvio90721_B.dataIn[i] = TestSingoloInvio90721_B.BytePack[i];
  }

  MW_Serial_write(TestSingoloInvio90721_DW.obj.port,
                  &TestSingoloInvio90721_B.dataIn[0], 63.0,
                  TestSingoloInvio90721_DW.obj.dataSizeInBytes,
                  TestSingoloInvio90721_DW.obj.sendModeEnum,
                  TestSingoloInvio90721_DW.obj.dataType,
                  TestSingoloInvio90721_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit' */
}

/* Model initialize function */
void TestSingoloInvio90721_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    TestSingoloInvio90721_DW.obj.matlabCodegenIsDeleted = false;
    TestSingoloInvio90721_DW.obj.Protocol =
      TestSingoloInvio90721_P.SerialTransmit_Protocol;
    TestSingoloInvio90721_DW.obj.isInitialized = 1;
    TestSingoloInvio90721_DW.obj.port = 0.0;
    TestSingoloInvio90721_DW.obj.dataSizeInBytes = 1.0;
    TestSingoloInvio90721_DW.obj.dataType = 0.0;
    TestSingoloInvio90721_DW.obj.sendModeEnum = 0.0;
    TestSingoloInvio90721_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(TestSingoloInvio90721_DW.obj.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    TestSingoloInvio90721_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void TestSingoloInvio90721_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!TestSingoloInvio90721_DW.obj.matlabCodegenIsDeleted) {
    TestSingoloInvio90721_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
