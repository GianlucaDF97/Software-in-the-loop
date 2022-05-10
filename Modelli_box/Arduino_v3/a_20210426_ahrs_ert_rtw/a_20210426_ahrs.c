/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210426_ahrs.c
 *
 * Code generated for Simulink model 'a_20210426_ahrs'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Apr 27 15:03:02 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "a_20210426_ahrs.h"
#include "a_20210426_ahrs_private.h"

/* Block signals (default storage) */
B_a_20210426_ahrs_T a_20210426_ahrs_B;

/* Block states (default storage) */
DW_a_20210426_ahrs_T a_20210426_ahrs_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_a_20210426_ahrs_T a_20210426_ahrs_Y;

/* Real-time model */
static RT_MODEL_a_20210426_ahrs_T a_20210426_ahrs_M_;
RT_MODEL_a_20210426_ahrs_T *const a_20210426_ahrs_M = &a_20210426_ahrs_M_;
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
void a_20210426_ahrs_step(void)
{
  real_T checksum;
  real_T olddi;
  int32_T b_k;
  int32_T c_k;
  int32_T idx;
  int32_T npad;
  char_T hex_checksum_data[17];
  uint8_T dataIn[5];
  uint8_T b_v;
  boolean_T exitg1;

  /* S-Function (Mti): '<Root>/S-Function Builder' */
  Mti_Outputs_wrapper(&a_20210426_ahrs_B.SFunctionBuilder_o1[0],
                      &a_20210426_ahrs_B.SFunctionBuilder_o2,
                      &a_20210426_ahrs_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  checksum = a_20210426_ahrs_B.SFunctionBuilder_o1[1];
  for (idx = 0; idx < 39; idx++) {
    checksum += (real_T)a_20210426_ahrs_B.SFunctionBuilder_o1[idx + 2];
  }

  for (idx = 0; idx < 64; idx++) {
    a_20210426_ahrs_B.sfull[idx] = '0';
  }

  idx = 64;
  exitg1 = false;
  while ((!exitg1) && (idx > 0)) {
    olddi = checksum;
    checksum = floor(checksum / 2.0);
    if (2.0 * checksum < olddi) {
      a_20210426_ahrs_B.sfull[idx - 1] = '1';
    }

    if (!(checksum > 0.0)) {
      exitg1 = true;
    } else {
      idx--;
    }
  }

  idx = 0;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 64)) {
    if (a_20210426_ahrs_B.sfull[b_k] == '1') {
      idx = b_k + 1;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (idx == 0) {
    idx = 64;
  }

  if (4 >= 65 - idx) {
    b_k = 4;
  } else {
    b_k = 65 - idx;
  }

  if (65 - idx < 4) {
    npad = idx;
    for (c_k = 0; c_k <= idx - 62; c_k++) {
      a_20210426_ahrs_B.b_data[c_k] = '0';
    }
  } else {
    npad = 61;
  }

  for (c_k = -1; c_k < 64 - idx; c_k++) {
    a_20210426_ahrs_B.b_data[(npad + c_k) - 60] = a_20210426_ahrs_B.sfull[idx +
      c_k];
  }

  idx = b_k >> 2;
  npad = b_k - (idx << 2);
  if (npad == 0) {
    for (npad = 0; npad < idx; npad++) {
      b_k = npad << 2;
      if (a_20210426_ahrs_B.b_data[b_k + 3] == '1') {
        b_v = 1U;
      } else {
        b_v = 0U;
      }

      if (a_20210426_ahrs_B.b_data[b_k + 2] == '1') {
        b_v = (uint8_T)(b_v + 2);
      }

      if (a_20210426_ahrs_B.b_data[b_k + 1] == '1') {
        b_v = (uint8_T)(b_v + 4);
      }

      if (a_20210426_ahrs_B.b_data[b_k] == '1') {
        b_v = (uint8_T)(b_v + 8);
      }

      if (b_v > 9) {
        hex_checksum_data[npad] = (int8_T)(b_v + 55);
      } else {
        hex_checksum_data[npad] = (int8_T)(b_v + 48);
      }
    }
  } else {
    for (c_k = 0; c_k < idx; c_k++) {
      b_k = (c_k << 2) + npad;
      if (a_20210426_ahrs_B.b_data[b_k + 3] == '1') {
        b_v = 1U;
      } else {
        b_v = 0U;
      }

      if (a_20210426_ahrs_B.b_data[b_k + 2] == '1') {
        b_v = (uint8_T)(b_v + 2);
      }

      if (a_20210426_ahrs_B.b_data[b_k + 1] == '1') {
        b_v = (uint8_T)(b_v + 4);
      }

      if (a_20210426_ahrs_B.b_data[b_k] == '1') {
        b_v = (uint8_T)(b_v + 8);
      }

      if (b_v > 9) {
        hex_checksum_data[c_k + 1] = (int8_T)(b_v + 55);
      } else {
        hex_checksum_data[c_k + 1] = (int8_T)(b_v + 48);
      }
    }
  }

  if ((hex_checksum_data[2] == '0') && (hex_checksum_data[3] == '0')) {
    for (idx = 0; idx < 41; idx++) {
      a_20210426_ahrs_B.Mex_out[idx] = a_20210426_ahrs_B.SFunctionBuilder_o1[idx];
    }
  } else {
    for (idx = 0; idx < 41; idx++) {
      a_20210426_ahrs_B.Mex_out[idx] = a_20210426_ahrs_DW.Delay_DSTATE[idx];
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* S-Function (byte2any_svd): '<Root>/Byte Unpack' */

  /* Unpack: <Root>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&a_20210426_ahrs_B.ByteUnpack_o1[0], (uint8_T*)
             &a_20210426_ahrs_B.Mex_out[0] + MW_inputPortOffset,
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
    /* Output data type - real32_T, size - 9 */
    {
      MW_outputPortWidth = 9 * sizeof(real32_T);
      memcpy((uint8_T*)&a_20210426_ahrs_B.ByteUnpack_o2[0], (uint8_T*)
             &a_20210426_ahrs_B.Mex_out[0] + MW_inputPortOffset,
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
    /* Output data type - uint8_T, size - 1 */
    {
      MW_outputPortWidth = 1 * sizeof(uint8_T);
      memcpy((uint8_T*)&a_20210426_ahrs_B.ByteUnpack_o3, (uint8_T*)
             &a_20210426_ahrs_B.Mex_out[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<Root>/Byte Reversal' incorporates:
   *  Outport: '<Root>/Misure_MTi'
   */

  /* ReverseEndian: <Root>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &a_20210426_ahrs_B.ByteUnpack_o2[0];
    real32_T *y0 = &a_20210426_ahrs_Y.Misure_MTi[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* MATLABSystem: '<Root>/Serial Transmit' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (a_20210426_ahrs_DW.obj.Protocol !=
      a_20210426_ahrs_P.SerialTransmit_Protocol) {
    a_20210426_ahrs_DW.obj.Protocol = a_20210426_ahrs_P.SerialTransmit_Protocol;
  }

  for (idx = 0; idx < 5; idx++) {
    dataIn[idx] = a_20210426_ahrs_P.Constant_Value[idx];
  }

  MW_Serial_write(a_20210426_ahrs_DW.obj.port, &dataIn[0], 5.0,
                  a_20210426_ahrs_DW.obj.dataSizeInBytes,
                  a_20210426_ahrs_DW.obj.sendModeEnum,
                  a_20210426_ahrs_DW.obj.dataType,
                  a_20210426_ahrs_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<Root>/Serial Transmit' */

  /* Update for S-Function (Mti): '<Root>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <Root>/S-Function Builder */
  Mti_Update_wrapper(&a_20210426_ahrs_B.SFunctionBuilder_o1[0],
                     &a_20210426_ahrs_B.SFunctionBuilder_o2,
                     &a_20210426_ahrs_DW.SFunctionBuilder_DSTATE);

  /* Update for Delay: '<Root>/Delay' */
  for (idx = 0; idx < 41; idx++) {
    a_20210426_ahrs_DW.Delay_DSTATE[idx] =
      a_20210426_ahrs_B.SFunctionBuilder_o1[idx];
  }

  /* End of Update for Delay: '<Root>/Delay' */
}

/* Model initialize function */
void a_20210426_ahrs_initialize(void)
{
  {
    real_T tmp;
    int32_T i;
    uint8_T tmp_0;

    /* InitializeConditions for S-Function (Mti): '<Root>/S-Function Builder' */

    /* S-Function Block: <Root>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          a_20210426_ahrs_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Delay: '<Root>/Delay' */
    for (i = 0; i < 41; i++) {
      a_20210426_ahrs_DW.Delay_DSTATE[i] =
        a_20210426_ahrs_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay' */

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    a_20210426_ahrs_DW.obj.matlabCodegenIsDeleted = false;
    a_20210426_ahrs_DW.obj.Protocol = a_20210426_ahrs_P.SerialTransmit_Protocol;
    a_20210426_ahrs_DW.obj.isInitialized = 1;
    a_20210426_ahrs_DW.obj.port = 3.0;
    a_20210426_ahrs_DW.obj.dataSizeInBytes = 1.0;
    a_20210426_ahrs_DW.obj.dataType = 0.0;
    a_20210426_ahrs_DW.obj.sendModeEnum = 0.0;
    a_20210426_ahrs_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(a_20210426_ahrs_DW.obj.port);
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
    a_20210426_ahrs_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void a_20210426_ahrs_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!a_20210426_ahrs_DW.obj.matlabCodegenIsDeleted) {
    a_20210426_ahrs_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
