/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: kalman_rasp.c
 *
 * Code generated for Simulink model 'kalman_rasp'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 30 15:49:59 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "kalman_rasp.h"
#include "kalman_rasp_private.h"

/* Block signals (default storage) */
B_kalman_rasp_T kalman_rasp_B;

/* Block states (default storage) */
DW_kalman_rasp_T kalman_rasp_DW;

/* Real-time model */
static RT_MODEL_kalman_rasp_T kalman_rasp_M_;
RT_MODEL_kalman_rasp_T *const kalman_rasp_M = &kalman_rasp_M_;

/* Forward declaration for local functions */
static void kalman_rasp_SystemCore_setup(codertarget_raspi_internal_SC_T *obj);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

static void kalman_rasp_SystemCore_setup(codertarget_raspi_internal_SC_T *obj)
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
void kalman_rasp_step(void)
{
  int32_T i;
  uint8_T RxData[10];
  uint8_T RxDataLocChar[10];

  /* MATLABSystem: '<Root>/Serial Read' */
  if (kalman_rasp_DW.obj.SampleTime != kalman_rasp_P.SerialRead_SampleTime) {
    kalman_rasp_DW.obj.SampleTime = kalman_rasp_P.SerialRead_SampleTime;
  }

  MW_SCI_Receive(kalman_rasp_DW.obj.MW_SCIHANDLE, &RxDataLocChar[0], 10U);
  memcpy((void *)&RxData[0], (void *)&RxDataLocChar[0], (uint32_T)((size_t)10 *
          sizeof(uint8_T)));
  for (i = 0; i < 10; i++) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  MATLABSystem: '<Root>/Serial Read'
     */
    kalman_rasp_B.DataTypeConversion[i] = RxData[i];
  }

  /* ToFile: '<Root>/To File' */
  {
    if (!(++kalman_rasp_DW.ToFile_IWORK.Decimation % 1) &&
        (kalman_rasp_DW.ToFile_IWORK.Count * (10 + 1)) + 1 < 100000000 ) {
      FILE *fp = (FILE *) kalman_rasp_DW.ToFile_PWORK.FilePtr;
      if (fp != (NULL)) {
        real_T u[10 + 1];
        kalman_rasp_DW.ToFile_IWORK.Decimation = 0;
        u[0] = kalman_rasp_M->Timing.taskTime0;
        u[1] = kalman_rasp_B.DataTypeConversion[0];
        u[2] = kalman_rasp_B.DataTypeConversion[1];
        u[3] = kalman_rasp_B.DataTypeConversion[2];
        u[4] = kalman_rasp_B.DataTypeConversion[3];
        u[5] = kalman_rasp_B.DataTypeConversion[4];
        u[6] = kalman_rasp_B.DataTypeConversion[5];
        u[7] = kalman_rasp_B.DataTypeConversion[6];
        u[8] = kalman_rasp_B.DataTypeConversion[7];
        u[9] = kalman_rasp_B.DataTypeConversion[8];
        u[10] = kalman_rasp_B.DataTypeConversion[9];
        if (fwrite(u, sizeof(real_T), 10 + 1, fp) != 10 + 1) {
          rtmSetErrorStatus(kalman_rasp_M, "Error writing to MAT-file kal.mat");
          return;
        }

        if (((++kalman_rasp_DW.ToFile_IWORK.Count) * (10 + 1))+1 >= 100000000) {
          (void)fprintf(stdout,
                        "*** The ToFile block will stop logging data before\n"
                        "    the simulation has ended, because it has reached\n"
                        "    the maximum number of elements (100000000)\n"
                        "    allowed in MAT-file kal.mat.\n");
        }
      }
    }
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(kalman_rasp_M->rtwLogInfo,
                      (&kalman_rasp_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(kalman_rasp_M)!=-1) &&
        !((rtmGetTFinal(kalman_rasp_M)-kalman_rasp_M->Timing.taskTime0) >
          kalman_rasp_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(kalman_rasp_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  kalman_rasp_M->Timing.taskTime0 =
    ((time_T)(++kalman_rasp_M->Timing.clockTick0)) *
    kalman_rasp_M->Timing.stepSize0;
}

/* Model initialize function */
void kalman_rasp_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(kalman_rasp_M, -1);
  kalman_rasp_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    kalman_rasp_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(kalman_rasp_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(kalman_rasp_M->rtwLogInfo, (NULL));
    rtliSetLogT(kalman_rasp_M->rtwLogInfo, "tout");
    rtliSetLogX(kalman_rasp_M->rtwLogInfo, "");
    rtliSetLogXFinal(kalman_rasp_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(kalman_rasp_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(kalman_rasp_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(kalman_rasp_M->rtwLogInfo, 0);
    rtliSetLogDecimation(kalman_rasp_M->rtwLogInfo, 1);
    rtliSetLogY(kalman_rasp_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(kalman_rasp_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(kalman_rasp_M->rtwLogInfo, (NULL));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(kalman_rasp_M->rtwLogInfo, 0.0, rtmGetTFinal
    (kalman_rasp_M), kalman_rasp_M->Timing.stepSize0, (&rtmGetErrorStatus
    (kalman_rasp_M)));

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "kal.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(kalman_rasp_M, "Error creating .mat file kal.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 10 + 1, 0, "ans")) {
      rtmSetErrorStatus(kalman_rasp_M,
                        "Error writing mat file header to file kal.mat");
      return;
    }

    kalman_rasp_DW.ToFile_IWORK.Count = 0;
    kalman_rasp_DW.ToFile_IWORK.Decimation = -1;
    kalman_rasp_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for MATLABSystem: '<Root>/Serial Read' */
  kalman_rasp_DW.obj.isInitialized = 0;
  kalman_rasp_DW.obj.matlabCodegenIsDeleted = false;
  kalman_rasp_DW.obj.SampleTime = kalman_rasp_P.SerialRead_SampleTime;
  kalman_rasp_SystemCore_setup(&kalman_rasp_DW.obj);
}

/* Model terminate function */
void kalman_rasp_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Read' */
  if (!kalman_rasp_DW.obj.matlabCodegenIsDeleted) {
    kalman_rasp_DW.obj.matlabCodegenIsDeleted = true;
    if ((kalman_rasp_DW.obj.isInitialized == 1) &&
        kalman_rasp_DW.obj.isSetupComplete) {
      MW_SCI_Close(kalman_rasp_DW.obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Read' */

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) kalman_rasp_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "kal.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(kalman_rasp_M, "Error closing MAT-file kal.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(kalman_rasp_M, "Error reopening MAT-file kal.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 10 + 1, kalman_rasp_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(kalman_rasp_M,
                          "Error writing header for ans to MAT-file kal.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(kalman_rasp_M, "Error closing MAT-file kal.mat");
        return;
      }

      kalman_rasp_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
