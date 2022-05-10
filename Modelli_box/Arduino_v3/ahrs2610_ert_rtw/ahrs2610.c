/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ahrs2610.c
 *
 * Code generated for Simulink model 'ahrs2610'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct 28 13:11:55 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ahrs2610.h"
#include "ahrs2610_private.h"

/* Block signals (default storage) */
B_ahrs2610_T ahrs2610_B;

/* Block states (default storage) */
DW_ahrs2610_T ahrs2610_DW;

/* Real-time model */
static RT_MODEL_ahrs2610_T ahrs2610_M_;
RT_MODEL_ahrs2610_T *const ahrs2610_M = &ahrs2610_M_;
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
void ahrs2610_step(void)
{
  int32_T i;
  uint8_T dataIn[41];

  /* S-Function (Mti): '<S1>/S-Function Builder' */
  Mti_Outputs_wrapper(&ahrs2610_B.SFunctionBuilder[0],
                      &ahrs2610_DW.SFunctionBuilder_DSTATE);

  /* MATLABSystem: '<S1>/Serial Transmit1' */
  if (ahrs2610_DW.obj.Protocol != ahrs2610_P.SerialTransmit1_Protocol) {
    ahrs2610_DW.obj.Protocol = ahrs2610_P.SerialTransmit1_Protocol;
  }

  for (i = 0; i < 41; i++) {
    dataIn[i] = ahrs2610_B.SFunctionBuilder[i];
  }

  MW_Serial_write(ahrs2610_DW.obj.port, &dataIn[0], 41.0,
                  ahrs2610_DW.obj.dataSizeInBytes, ahrs2610_DW.obj.sendModeEnum,
                  ahrs2610_DW.obj.dataType, ahrs2610_DW.obj.sendFormatEnum, 2.0,
                  '\x00');

  /* End of MATLABSystem: '<S1>/Serial Transmit1' */

  /* S-Function (byte2any_svd): '<S1>/Byte Unpack' */

  /* Unpack: <S1>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&ahrs2610_B.ByteUnpack_o1[0], (uint8_T*)
             &ahrs2610_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&ahrs2610_B.ByteUnpack_o2[0], (uint8_T*)
             &ahrs2610_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&ahrs2610_B.ByteUnpack_o3, (uint8_T*)
             &ahrs2610_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S1>/Byte Reversal' */

  /* ReverseEndian: <S1>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &ahrs2610_B.ByteUnpack_o2[0];
    real32_T *y0 = &ahrs2610_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* Update for S-Function (Mti): '<S1>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S1>/S-Function Builder */
  Mti_Update_wrapper(&ahrs2610_B.SFunctionBuilder[0],
                     &ahrs2610_DW.SFunctionBuilder_DSTATE);
}

/* Model initialize function */
void ahrs2610_initialize(void)
{
  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for S-Function (Mti): '<S1>/S-Function Builder' */

    /* S-Function Block: <S1>/S-Function Builder */
    Mti_Start_wrapper(&ahrs2610_DW.SFunctionBuilder_DSTATE);

    /* InitializeConditions for S-Function (Mti): '<S1>/S-Function Builder' */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          ahrs2610_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* Start for MATLABSystem: '<S1>/Serial Transmit1' */
    ahrs2610_DW.obj.matlabCodegenIsDeleted = false;
    ahrs2610_DW.obj.Protocol = ahrs2610_P.SerialTransmit1_Protocol;
    ahrs2610_DW.obj.isInitialized = 1;
    ahrs2610_DW.obj.port = 0.0;
    ahrs2610_DW.obj.dataSizeInBytes = 1.0;
    ahrs2610_DW.obj.dataType = 0.0;
    ahrs2610_DW.obj.sendModeEnum = 2.0;
    ahrs2610_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(ahrs2610_DW.obj.port);
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
    ahrs2610_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S1>/Serial Transmit1' */
  }
}

/* Model terminate function */
void ahrs2610_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Serial Transmit1' */
  if (!ahrs2610_DW.obj.matlabCodegenIsDeleted) {
    ahrs2610_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Serial Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
