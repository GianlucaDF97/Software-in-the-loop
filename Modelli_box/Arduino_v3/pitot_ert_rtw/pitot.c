/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pitot.c
 *
 * Code generated for Simulink model 'pitot'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 25 11:45:26 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pitot.h"
#include "pitot_private.h"

/* Block signals (default storage) */
B_pitot_T pitot_B;

/* Block states (default storage) */
DW_pitot_T pitot_DW;

/* Real-time model */
static RT_MODEL_pitot_T pitot_M_;
RT_MODEL_pitot_T *const pitot_M = &pitot_M_;

/* Model step function */
void pitot_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  f_arduinodriver_ArduinoAnalog_T *obj_0;
  f_arduinodriver_ArduinoAnalog_T *obj_1;
  real_T SampleTime;
  uint16_T tmp;

  /* MATLABSystem: '<S1>/Analog Input' */
  SampleTime = pitot_P.t_AP;
  if (pitot_DW.obj.SampleTime != SampleTime) {
    obj = &pitot_DW.obj;
    obj->SampleTime = SampleTime;
  }

  obj = &pitot_DW.obj;
  obj_0 = &obj->AnalogInDriverObj;
  obj_1 = obj_0;
  obj_1->MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(22UL);
  MW_AnalogInSingle_ReadResult(obj_0->MW_ANALOGIN_HANDLE, &tmp, 3);

  /* MATLABSystem: '<S1>/Analog Input' */
  pitot_B.AnalogInput = tmp;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  pitot_B.DataTypeConversion = pitot_B.AnalogInput;

  /* Gain: '<S2>/Gain3' */
  pitot_B.Gain3 = pitot_P.Gain3_Gain * pitot_B.DataTypeConversion;

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S2>/Constant4'
   */
  pitot_B.Sum1 = pitot_B.Gain3 + pitot_P.Constant4_Value;

  /* MATLAB Function: '<S1>/deltaP to Velocità' */
  /* MATLAB Function 'Velocità indicata/deltaP to Velocità': '<S4>:1' */
  /* '<S4>:1:5' */
  pitot_B.V_anem = 2.0 * fabs(pitot_B.Sum1) / 1.225;
  pitot_B.V_anem = sqrt(pitot_B.V_anem);

  /* S-Function (Risoluzione_12bit): '<S3>/S-Function Builder' */
  Risoluzione_12bit_Outputs_wrapper(&pitot_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (Risoluzione_12bit): '<S3>/S-Function Builder' */

  /* S-Function "Risoluzione_12bit_wrapper" Block: <S3>/S-Function Builder */
  Risoluzione_12bit_Update_wrapper(&pitot_DW.SFunctionBuilder_DSTATE);
}

/* Model initialize function */
void pitot_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(pitot_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &pitot_B), 0,
                sizeof(B_pitot_T));

  /* states (dwork) */
  (void) memset((void *)&pitot_DW, 0,
                sizeof(DW_pitot_T));

  {
    codertarget_arduinobase_inter_T *b_obj;
    codertarget_arduinobase_inter_T *obj;
    f_arduinodriver_ArduinoAnalog_T *obj_0;
    real_T SampleTime;

    /* InitializeConditions for S-Function (Risoluzione_12bit): '<S3>/S-Function Builder' */

    /* S-Function Block: <S3>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          pitot_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* Start for MATLABSystem: '<S1>/Analog Input' */
    pitot_DW.obj.matlabCodegenIsDeleted = true;
    SampleTime = pitot_P.t_AP;
    b_obj = &pitot_DW.obj;
    b_obj->isInitialized = 0L;
    b_obj->SampleTime = -1.0;
    b_obj->matlabCodegenIsDeleted = false;
    pitot_DW.objisempty = true;
    b_obj = &pitot_DW.obj;
    b_obj->SampleTime = SampleTime;
    b_obj = &pitot_DW.obj;
    b_obj->isSetupComplete = false;
    b_obj->isInitialized = 1L;
    obj = b_obj;
    obj_0 = &obj->AnalogInDriverObj;
    obj_0->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(22UL);
    b_obj->isSetupComplete = true;
  }
}

/* Model terminate function */
void pitot_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;
  f_arduinodriver_ArduinoAnalog_T *obj_0;
  f_arduinodriver_ArduinoAnalog_T *obj_1;

  /* Terminate for MATLABSystem: '<S1>/Analog Input' */
  obj = &pitot_DW.obj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
      obj_0 = &obj->AnalogInDriverObj;
      obj_1 = obj_0;
      obj_1->MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(22UL);
      MW_AnalogIn_Close(obj_0->MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Analog Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
