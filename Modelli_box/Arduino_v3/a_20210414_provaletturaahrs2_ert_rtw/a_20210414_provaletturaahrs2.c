/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a_20210414_provaletturaahrs2.c
 *
 * Code generated for Simulink model 'a_20210414_provaletturaahrs2'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May  4 18:36:06 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "a_20210414_provaletturaahrs2.h"
#include "a_20210414_provaletturaahrs2_private.h"

/* Block signals (default storage) */
B_a_20210414_provaletturaahrs_T a_20210414_provaletturaahrs2_B;

/* Block states (default storage) */
DW_a_20210414_provaletturaahr_T a_20210414_provaletturaahrs2_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_a_20210414_provaletturaa_T a_20210414_provaletturaahrs2_Y;

/* Real-time model */
static RT_MODEL_a_20210414_provalett_T a_20210414_provaletturaahrs2_M_;
RT_MODEL_a_20210414_provalett_T *const a_20210414_provaletturaahrs2_M =
  &a_20210414_provaletturaahrs2_M_;

/* Model step function */
void a_20210414_provaletturaahrs2_step(void)
{
  real_T checksum;
  real_T olddi;
  int32_T b_k;
  int32_T c_k;
  int32_T idx;
  int32_T npad;
  char_T hex_checksum_data[17];
  uint8_T b_v;
  boolean_T exitg1;

  /* S-Function (Mti): '<Root>/S-Function Builder' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Mti_Outputs_wrapper(&a_20210414_provaletturaahrs2_P.Constant1_Value,
                      &a_20210414_provaletturaahrs2_B.SFunctionBuilder_o1[0],
                      &a_20210414_provaletturaahrs2_B.SFunctionBuilder_o2,
                      &a_20210414_provaletturaahrs2_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  checksum = a_20210414_provaletturaahrs2_B.SFunctionBuilder_o1[1];
  for (idx = 0; idx < 39; idx++) {
    checksum += (real_T)a_20210414_provaletturaahrs2_B.SFunctionBuilder_o1[idx +
      2];
  }

  for (idx = 0; idx < 64; idx++) {
    a_20210414_provaletturaahrs2_B.sfull[idx] = '0';
  }

  idx = 64;
  exitg1 = false;
  while ((!exitg1) && (idx > 0)) {
    olddi = checksum;
    checksum = floor(checksum / 2.0);
    if (2.0 * checksum < olddi) {
      a_20210414_provaletturaahrs2_B.sfull[idx - 1] = '1';
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
    if (a_20210414_provaletturaahrs2_B.sfull[b_k] == '1') {
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
      a_20210414_provaletturaahrs2_B.b_data[c_k] = '0';
    }
  } else {
    npad = 61;
  }

  for (c_k = -1; c_k < 64 - idx; c_k++) {
    a_20210414_provaletturaahrs2_B.b_data[(npad + c_k) - 60] =
      a_20210414_provaletturaahrs2_B.sfull[idx + c_k];
  }

  idx = b_k >> 2;
  npad = b_k - (idx << 2);
  if (npad == 0) {
    for (npad = 0; npad < idx; npad++) {
      b_k = npad << 2;
      if (a_20210414_provaletturaahrs2_B.b_data[b_k + 3] == '1') {
        b_v = 1U;
      } else {
        b_v = 0U;
      }

      if (a_20210414_provaletturaahrs2_B.b_data[b_k + 2] == '1') {
        b_v = (uint8_T)(b_v + 2);
      }

      if (a_20210414_provaletturaahrs2_B.b_data[b_k + 1] == '1') {
        b_v = (uint8_T)(b_v + 4);
      }

      if (a_20210414_provaletturaahrs2_B.b_data[b_k] == '1') {
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
      if (a_20210414_provaletturaahrs2_B.b_data[b_k + 3] == '1') {
        b_v = 1U;
      } else {
        b_v = 0U;
      }

      if (a_20210414_provaletturaahrs2_B.b_data[b_k + 2] == '1') {
        b_v = (uint8_T)(b_v + 2);
      }

      if (a_20210414_provaletturaahrs2_B.b_data[b_k + 1] == '1') {
        b_v = (uint8_T)(b_v + 4);
      }

      if (a_20210414_provaletturaahrs2_B.b_data[b_k] == '1') {
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
    for (idx = 0; idx < 54; idx++) {
      a_20210414_provaletturaahrs2_B.Mex_out[idx] =
        a_20210414_provaletturaahrs2_B.SFunctionBuilder_o1[idx];
    }
  } else {
    for (idx = 0; idx < 54; idx++) {
      a_20210414_provaletturaahrs2_B.Mex_out[idx] =
        a_20210414_provaletturaahrs2_DW.Delay_DSTATE[idx];
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
      memcpy((uint8_T*)&a_20210414_provaletturaahrs2_B.ByteUnpack_o1[0],
             (uint8_T*)&a_20210414_provaletturaahrs2_B.Mex_out[0] +
             MW_inputPortOffset, MW_outputPortWidth);
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
    /* Output data type - real32_T, size - 12 */
    {
      MW_outputPortWidth = 12 * sizeof(real32_T);
      memcpy((uint8_T*)&a_20210414_provaletturaahrs2_B.ByteUnpack_o2[0],
             (uint8_T*)&a_20210414_provaletturaahrs2_B.Mex_out[0] +
             MW_inputPortOffset, MW_outputPortWidth);
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
    /* Output data type - uint8_T, size - 2 */
    {
      MW_outputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)&a_20210414_provaletturaahrs2_B.ByteUnpack_o3[0],
             (uint8_T*)&a_20210414_provaletturaahrs2_B.Mex_out[0] +
             MW_inputPortOffset, MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<Root>/Byte Reversal' incorporates:
   *  Outport: '<Root>/Misure_MTi'
   */

  /* ReverseEndian: <Root>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &a_20210414_provaletturaahrs2_B.ByteUnpack_o2[0];
    real32_T *y0 = &a_20210414_provaletturaahrs2_Y.Misure_MTi[0];
    for (i1=0; i1 < 12; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* Update for Delay: '<Root>/Delay' */
  for (idx = 0; idx < 54; idx++) {
    a_20210414_provaletturaahrs2_DW.Delay_DSTATE[idx] =
      a_20210414_provaletturaahrs2_B.SFunctionBuilder_o1[idx];
  }

  /* End of Update for Delay: '<Root>/Delay' */

  /* Update for S-Function (Mti): '<Root>/S-Function Builder' incorporates:
   *  Constant: '<Root>/Constant1'
   */

  /* S-Function "Mti_wrapper" Block: <Root>/S-Function Builder */
  Mti_Update_wrapper(&a_20210414_provaletturaahrs2_P.Constant1_Value,
                     &a_20210414_provaletturaahrs2_B.SFunctionBuilder_o1[0],
                     &a_20210414_provaletturaahrs2_B.SFunctionBuilder_o2,
                     &a_20210414_provaletturaahrs2_DW.SFunctionBuilder_DSTATE);
}

/* Model initialize function */
void a_20210414_provaletturaahrs2_initialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    for (i = 0; i < 54; i++) {
      a_20210414_provaletturaahrs2_DW.Delay_DSTATE[i] =
        a_20210414_provaletturaahrs2_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay' */

    /* InitializeConditions for S-Function (Mti): '<Root>/S-Function Builder' incorporates:
     *  Constant: '<Root>/Constant1'
     */

    /* S-Function Block: <Root>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          a_20210414_provaletturaahrs2_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }
  }
}

/* Model terminate function */
void a_20210414_provaletturaahrs2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
