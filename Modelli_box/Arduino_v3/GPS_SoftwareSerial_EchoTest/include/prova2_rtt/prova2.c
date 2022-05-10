/*
 * File: prova2.c
 *
 * Code generated for Simulink model 'prova2'.
 *
 * Model version                  : 1.285
 * Simulink Coder version         : 8.2 (R2012a) 29-Dec-2011
 * TLC version                    : 8.2 (Dec 29 2011)
 * C/C++ source code generated on : Sat Jan 19 14:27:22 2013
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prova2.h"
#include "prova2_private.h"
#include "prova2_dt.h"

/* Block signals (auto storage) */
BlockIO_prova2 prova2_B;

/* Real-time model */
RT_MODEL_prova2 prova2_M_;
RT_MODEL_prova2 *const prova2_M = &prova2_M_;

/* Model output function */
void prova2_output(void)
{
  /* S-Function (prova19gennaio): '<Root>/S-Function Builder' */
  prova19gennaio_Outputs_wrapper(&prova2_P.Customcode_Value,
    prova2_P.TypeAutopilotBaseModeSystemStat, prova2_B.SFunctionBuilder_o1,
    &prova2_B.SFunctionBuilder_o2 );
}

/* Model update function */
void prova2_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(prova2_M)!=-1) &&
        !((rtmGetTFinal(prova2_M)-prova2_M->Timing.taskTime0) >
          prova2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(prova2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(prova2_M)) {
      rtmSetErrorStatus(prova2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  prova2_M->Timing.taskTime0 =
    (++prova2_M->Timing.clockTick0) * prova2_M->Timing.stepSize0;
}

/* Model initialize function */
void prova2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)prova2_M, 0,
                sizeof(RT_MODEL_prova2));
  rtmSetTFinal(prova2_M, -1);
  prova2_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  prova2_M->Sizes.checksums[0] = (2760538163U);
  prova2_M->Sizes.checksums[1] = (2011084286U);
  prova2_M->Sizes.checksums[2] = (65878827U);
  prova2_M->Sizes.checksums[3] = (1885054988U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    prova2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(prova2_M->extModeInfo,
      &prova2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(prova2_M->extModeInfo, prova2_M->Sizes.checksums);
    rteiSetTPtr(prova2_M->extModeInfo, rtmGetTPtr(prova2_M));
  }

  /* block I/O */
  (void) memset(((void *) &prova2_B), 0,
                sizeof(BlockIO_prova2));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    prova2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void prova2_terminate(void)
{
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
