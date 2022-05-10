/*********************** dSPACE target specific file *************************

   Include file modello_HITL_SFT_v4_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1006 7.15 (02-Nov-2020)
   Thu Oct 14 16:04:16 2021

   Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "modello_HITL_SFT_v4.h"
#include "modello_HITL_SFT_v4_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             modello_HITL_SFT_v4_B
#define RTP_STRUCTURE_NAME             modello_HITL_SFT_v4_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <ds2101.h>
#include <ds4002.h>
#include <ds4201s.h>
#include <dsser.h>
#ifndef dsRtmGetNumSampleTimes
# define dsRtmGetNumSampleTimes(rtm)   6
#endif

#ifndef dsRtmGetTPtr
# define dsRtmGetTPtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef dsRtmSetTaskTime
# define dsRtmSetTaskTime(rtm, sti, val) (dsRtmGetTPtr((rtm))[sti] = (val))
#endif

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/****** Definitions: task functions for HW interrupts *******************/

/* HW Interrupt: <Root>/DS4201SER_INT_B1_C1_I1 */
static void rti_4201SB1I0S0(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  {
    int32_T i;

    /* {S!d5516}RateTransition: '<Root>/Rate Transition' */
    switch (modello_HITL_SFT_v4_DW.RateTransition_write_buf) {
     case 0:
      modello_HITL_SFT_v4_DW.RateTransition_read_buf = 1;
      break;

     case 1:
      modello_HITL_SFT_v4_DW.RateTransition_read_buf = 0;
      break;

     default:
      modello_HITL_SFT_v4_DW.RateTransition_read_buf =
        modello_HITL_SFT_v4_DW.RateTransition_last_buf_wr;
      break;
    }

    if (modello_HITL_SFT_v4_DW.RateTransition_read_buf != 0) {
      for (i = 0; i < 41; i++) {
        modello_HITL_SFT_v4_B.RateTransition_c[i] =
          modello_HITL_SFT_v4_DW.RateTransition_Buffer1[i];
      }
    } else {
      for (i = 0; i < 41; i++) {
        modello_HITL_SFT_v4_B.RateTransition_c[i] =
          modello_HITL_SFT_v4_DW.RateTransition_Buffer0[i];
      }
    }

    modello_HITL_SFT_v4_DW.RateTransition_read_buf = -1;

    /* {E!d5516}End of RateTransition: '<Root>/Rate Transition' */

    /* {S!d5513}S-Function (rti_commonblock): '<S7>/S-Function1' */
    modello_HITL_SFT_v4_FunctionCallSubsystem();

    /* {E!d5513}End of Outputs for S-Function (rti_commonblock): '<S7>/S-Function1' */
  }

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */

/* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
dsserChannel *rtiDS4201SER_B1_Ser[4];

/* ===== Definition of interface functions for simulation engine =========== */
#if GRTINTERFACE == 1
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#else
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

# define dsIsSampleHit(RTM,sti)        rtmStepTask(RTM, sti)
#endif

#undef __INLINE
#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

/*Define additional variables*/
static time_T dsTFinal = -1.0;

#define dsGetTFinal(rtm)               (dsTFinal)

static time_T dsStepSize = 0.01;

# define dsGetStepSize(rtm)            (dsStepSize)

static void rti_mdl_initialize_host_services(void)
{
  ts_timestamp_type ts = { 0, 0 };

  host_service(1, &ts);
  DsDaq_Init(0, 32, 1);
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1006, (void *) 0,
                        VCM_TXT_RTI1006, 7, 15, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 9, 9, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 10, 2, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 9, 4, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW, msg_mod_ptr,
                          VCM_TXT_STATEFLOW, 10, 3, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW_CODER, msg_mod_ptr,
                          VCM_TXT_STATEFLOW_CODER, 9, 4, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS2101 #1 */
  ds2101_init(DS2101_1_BASE);

  /* dSPACE I/O Board DS2101 #1 Unit:DAC Group:CHANNEL2 */
  ds2101_set_range(DS2101_1_BASE, 2, DS2101_RNG5);
  ds2101_set_errmode(DS2101_1_BASE, 2, DS2101_KEEP);

  /* dSPACE I/O Board DS4002 #1 */
  ds4002_init(DS4002_1_BASE);

  /* dSPACE I/O Board DS4002 #1 Unit:TIMER */
  ds4002_pwm2d_init(DS4002_1_BASE, 1, 0, 0);
  ds4002_pwm2d_init(DS4002_1_BASE, 3, 0, 0);
  ds4002_pwm2d_init(DS4002_1_BASE, 5, 0, 0);
  ds4002_pwm2d_init(DS4002_1_BASE, 7, 0, 0);

  /* dSPACE I/O Board DS4201S #1 */
  ds4201s_init(DS4201S_1_BASE);
}

static void rti_mdl_slave_load(void)
{
  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  rtiDS4201SER_B1_Ser[0] = dsser_init(DS4201S_1_BASE,0,64);

  {
    UInt32 QuartzFrequency = 1843200;
    dsser_set(rtiDS4201SER_B1_Ser[0],DSSER_SET_UART_FREQUENCY, (void*)
              &QuartzFrequency);
  }

  dsser_config(rtiDS4201SER_B1_Ser[0],6, 115200, 8, DSSER_1_STOPBIT,
               DSSER_NO_PARITY, DSSER_4_BYTE_TRIGGER_LEVEL,5, (DSSER_RS232 |
    DSSER_AUTOFLOW_DISABLE));
  rtiDS4201SER_B1_Ser[1] = dsser_init(DS4201S_1_BASE,1,256);

  {
    UInt32 QuartzFrequency = 1843200;
    dsser_set(rtiDS4201SER_B1_Ser[1],DSSER_SET_UART_FREQUENCY, (void*)
              &QuartzFrequency);
  }

  dsser_config(rtiDS4201SER_B1_Ser[1],0, 9600, 8, DSSER_1_STOPBIT,
               DSSER_NO_PARITY, DSSER_14_BYTE_TRIGGER_LEVEL,0, (DSSER_RS232 |
    DSSER_AUTOFLOW_DISABLE));
  rtiDS4201SER_B1_Ser[2] = dsser_init(DS4201S_1_BASE,2,256);

  {
    UInt32 QuartzFrequency = 1843200;
    dsser_set(rtiDS4201SER_B1_Ser[2],DSSER_SET_UART_FREQUENCY, (void*)
              &QuartzFrequency);
  }

  dsser_config(rtiDS4201SER_B1_Ser[2],0, 115200, 8, DSSER_1_STOPBIT,
               DSSER_NO_PARITY, DSSER_8_BYTE_TRIGGER_LEVEL,0, (DSSER_RS232 |
    DSSER_AUTOFLOW_DISABLE));
  rtiDS4201SER_B1_Ser[3] = dsser_init(DS4201S_1_BASE,3,256);

  {
    UInt32 QuartzFrequency = 1843200;
    dsser_set(rtiDS4201SER_B1_Ser[3],DSSER_SET_UART_FREQUENCY, (void*)
              &QuartzFrequency);
  }

  dsser_config(rtiDS4201SER_B1_Ser[3],1, 9600, 8, DSSER_1_STOPBIT,
               DSSER_NO_PARITY, DSSER_8_BYTE_TRIGGER_LEVEL,0, (DSSER_RS232 |
    DSSER_AUTOFLOW_DISABLE));
  RTLIB_SLAVE_LOAD_ACKNOWLEDGE();
}

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  dsser_enable(rtiDS4201SER_B1_Ser[0]);
  dsser_enable(rtiDS4201SER_B1_Ser[1]);
  dsser_enable(rtiDS4201SER_B1_Ser[2]);
  dsser_enable(rtiDS4201SER_B1_Ser[3]);
}

static void rti_mdl_acknowledge_interrupts(void)
{
  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS4201SER_B1_Ser[0]);
  dsser_enable(rtiDS4201SER_B1_Ser[0]);
  dsser_disable(rtiDS4201SER_B1_Ser[1]);
  dsser_enable(rtiDS4201SER_B1_Ser[1]);
  dsser_disable(rtiDS4201SER_B1_Ser[2]);
  dsser_enable(rtiDS4201SER_B1_Ser[2]);
  dsser_disable(rtiDS4201SER_B1_Ser[3]);
  dsser_enable(rtiDS4201SER_B1_Ser[3]);
}

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

static void rti_mdl_background(void)
{
  /* DsDaq background call */
  DsDaq_Background(0);
}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.01, 0] */
  /* dSPACE I/O Board DS4002 #1 Unit:TIMER */
  {
    long periodsNumOf = 1;
    long actualPeriodsNumOf;
    ds4002_pwm2d_overl(DS4002_1_BASE, 1, periodsNumOf, &actualPeriodsNumOf,
                       &modello_HITL_SFT_v4_B.SFunction_o1,
                       &modello_HITL_SFT_v4_B.SFunction_o2);
  }

  {
    long periodsNumOf = 1;
    long actualPeriodsNumOf;
    ds4002_pwm2d_overl(DS4002_1_BASE, 3, periodsNumOf, &actualPeriodsNumOf,
                       &modello_HITL_SFT_v4_B.SFunction_o1_j,
                       &modello_HITL_SFT_v4_B.SFunction_o2_i);
  }

  {
    long periodsNumOf = 1;
    long actualPeriodsNumOf;
    ds4002_pwm2d_overl(DS4002_1_BASE, 5, periodsNumOf, &actualPeriodsNumOf,
                       &modello_HITL_SFT_v4_B.SFunction_o1_k,
                       &modello_HITL_SFT_v4_B.SFunction_o2_l);
  }

  {
    long periodsNumOf = 1;
    long actualPeriodsNumOf;
    ds4002_pwm2d_overl(DS4002_1_BASE, 7, periodsNumOf, &actualPeriodsNumOf,
                       &modello_HITL_SFT_v4_B.SFunction_o1_c,
                       &modello_HITL_SFT_v4_B.SFunction_o2_d);
  }
}

static void rti_mdl_daq_service()
{
  /* dSPACE Host Service */
  host_service(1, rtk_current_task_absolute_time_ptr_get());
  DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                rtk_current_task_absolute_time_ptr_get());
}

#undef __INLINE

/****** [EOF] ****************************************************************/
