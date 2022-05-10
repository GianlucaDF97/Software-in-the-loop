/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: kalman_rasp2.c
 *
 * Code generated for Simulink model 'kalman_rasp2'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 30 16:26:41 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "kalman_rasp2.h"
#include "kalman_rasp2_private.h"

/* Block states (default storage) */
DW_kalman_rasp2_T kalman_rasp2_DW;

/* Real-time model */
static RT_MODEL_kalman_rasp2_T kalman_rasp2_M_;
RT_MODEL_kalman_rasp2_T *const kalman_rasp2_M = &kalman_rasp2_M_;

/* Forward declaration for local functions */
static void kalman_rasp2_SystemCore_setup(codertarget_raspi_internal_SC_T *obj);
static void kalman_rasp2_SystemCore_setup(codertarget_raspi_internal_SC_T *obj)
{
  static const char_T tmp[10] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'S',
    '0' };

  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T TxPinLoc;
  void* SCIModuleVoidPtr;
  int32_T i;
  char_T b_SCIModuleLoc[11];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  TxPinLoc = MW_UNDEFINED_VALUE;
  for (i = 0; i < 10; i++) {
    b_SCIModuleLoc[i] = tmp[i];
  }

  b_SCIModuleLoc[10] = '\x00';
  SCIModuleVoidPtr = (void*)(&b_SCIModuleLoc[0]);
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleVoidPtr, true, RxPinLoc, TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void kalman_rasp2_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_SerialRead_o1[5];
  uint8_T RxDataLocChar[5];

  /* MATLABSystem: '<Root>/Serial Read' */
  if (kalman_rasp2_DW.obj.SampleTime != kalman_rasp2_P.SerialRead_SampleTime) {
    kalman_rasp2_DW.obj.SampleTime = kalman_rasp2_P.SerialRead_SampleTime;
  }

  MW_SCI_Receive(kalman_rasp2_DW.obj.MW_SCIHANDLE, &RxDataLocChar[0], 5U);
  memcpy((void *)&rtb_SerialRead_o1[0], (void *)&RxDataLocChar[0], (uint32_T)
         ((size_t)5 * sizeof(uint8_T)));

  /* End of MATLABSystem: '<Root>/Serial Read' */

  /* ToWorkspace: '<Root>/To Workspace' */
  {
    double locTime = kalman_rasp2_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)
                          kalman_rasp2_DW.ToWorkspace_PWORK.LoggedData, &locTime,
                          &rtb_SerialRead_o1[0]);
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(kalman_rasp2_M->rtwLogInfo,
                      (&kalman_rasp2_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(kalman_rasp2_M)!=-1) &&
        !((rtmGetTFinal(kalman_rasp2_M)-kalman_rasp2_M->Timing.taskTime0) >
          kalman_rasp2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(kalman_rasp2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  kalman_rasp2_M->Timing.taskTime0 =
    ((time_T)(++kalman_rasp2_M->Timing.clockTick0)) *
    kalman_rasp2_M->Timing.stepSize0;
}

/* Model initialize function */
void kalman_rasp2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(kalman_rasp2_M, -1);
  kalman_rasp2_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    kalman_rasp2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(kalman_rasp2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(kalman_rasp2_M->rtwLogInfo, (NULL));
    rtliSetLogT(kalman_rasp2_M->rtwLogInfo, "tout");
    rtliSetLogX(kalman_rasp2_M->rtwLogInfo, "");
    rtliSetLogXFinal(kalman_rasp2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(kalman_rasp2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(kalman_rasp2_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(kalman_rasp2_M->rtwLogInfo, 0);
    rtliSetLogDecimation(kalman_rasp2_M->rtwLogInfo, 1);
    rtliSetLogY(kalman_rasp2_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(kalman_rasp2_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(kalman_rasp2_M->rtwLogInfo, (NULL));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(kalman_rasp2_M->rtwLogInfo, 0.0, rtmGetTFinal
    (kalman_rasp2_M), kalman_rasp2_M->Timing.stepSize0, (&rtmGetErrorStatus
    (kalman_rasp2_M)));

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 5 };

    static int_T rt_ToWksNumDimensions[] = { 2 };

    static int_T rt_ToWksDimensions[] = { 5, 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4, 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_UINT8 };

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

    static const char_T rt_ToWksBlockName[] = "kalman_rasp2/To Workspace";
    kalman_rasp2_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      kalman_rasp2_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(kalman_rasp2_M),
      kalman_rasp2_M->Timing.stepSize0,
      (&rtmGetErrorStatus(kalman_rasp2_M)),
      "kalmanprova",
      1,
      0,
      1,
      0.02,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (kalman_rasp2_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for MATLABSystem: '<Root>/Serial Read' */
  kalman_rasp2_DW.obj.isInitialized = 0;
  kalman_rasp2_DW.obj.matlabCodegenIsDeleted = false;
  kalman_rasp2_DW.obj.SampleTime = kalman_rasp2_P.SerialRead_SampleTime;
  kalman_rasp2_SystemCore_setup(&kalman_rasp2_DW.obj);
}

/* Model terminate function */
void kalman_rasp2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Read' */
  if (!kalman_rasp2_DW.obj.matlabCodegenIsDeleted) {
    kalman_rasp2_DW.obj.matlabCodegenIsDeleted = true;
    if ((kalman_rasp2_DW.obj.isInitialized == 1) &&
        kalman_rasp2_DW.obj.isSetupComplete) {
      MW_SCI_Close(kalman_rasp2_DW.obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Read' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
