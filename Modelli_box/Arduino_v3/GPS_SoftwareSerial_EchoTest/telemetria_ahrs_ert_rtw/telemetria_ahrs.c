/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: telemetria_ahrs.c
 *
 * Code generated for Simulink model 'telemetria_ahrs'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jul 15 09:05:09 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "telemetria_ahrs.h"
#include "telemetria_ahrs_private.h"

const uint16_T telemetria_ahrs_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_telemetria_ahrs_T telemetria_ahrs_B;

/* Block states (default storage) */
DW_telemetria_ahrs_T telemetria_ahrs_DW;

/* Real-time model */
static RT_MODEL_telemetria_ahrs_T telemetria_ahrs_M_;
RT_MODEL_telemetria_ahrs_T *const telemetria_ahrs_M = &telemetria_ahrs_M_;

/* Forward declaration for local functions */
static void telemetria_ahrs_find_254(const uint8_T pack[100], real_T position[3],
  real_T *counter);
static boolean_T telemetria_ahrs_ifWhileCond(const boolean_T x[100]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void telemetria_ahrs_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(telemetria_ahrs_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(telemetria_ahrs_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 2 */
  telemetria_ahrs_M->Timing.RateInteraction.TID0_2 =
    (telemetria_ahrs_M->Timing.TaskCounters.TID[2] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (telemetria_ahrs_M->Timing.TaskCounters.TID[1])++;
  if ((telemetria_ahrs_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    telemetria_ahrs_M->Timing.TaskCounters.TID[1] = 0;
  }

  (telemetria_ahrs_M->Timing.TaskCounters.TID[2])++;
  if ((telemetria_ahrs_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [1.0s, 0.0s] */
    telemetria_ahrs_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void telemetria_ahrs_find_254(const uint8_T pack[100], real_T position[3],
  real_T *counter)
{
  int32_T i;
  int32_T tmp;
  uint8_T tmp_0;
  position[0] = 0.0;
  position[1] = 0.0;
  position[2] = 0.0;
  *counter = 0.0;
  for (i = 0; i < 100; i++) {
    if (pack[i] == 254) {
      (*counter)++;
      position[(int32_T)*counter - 1] = (real_T)i + 1.0;
    }
  }

  if (*counter > 1.0) {
    i = (int32_T)position[0];
    tmp = (int32_T)(pack[i] + 8U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    i += tmp;
    if (i < 256) {
      tmp_0 = (uint8_T)i;
    } else {
      tmp_0 = MAX_uint8_T;
    }

    if ((pack[tmp_0 - 1] != 254) && (position[0] != 0.0)) {
      *counter = 1.0;
      position[1] = 0.0;
    }
  }
}

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

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static boolean_T telemetria_ahrs_ifWhileCond(const boolean_T x[100])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 100)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void telemetria_ahrs_step0(void)       /* Sample time: [0.02s, 0.0s] */
{
  real_T rtb_Gain2;
  real_T rtb_RateTransition;
  int32_T caso;
  int32_T exitg3;
  int32_T f;
  int32_T g;
  int32_T status;
  int32_T x;
  real32_T tmp;
  uint32_T qY;
  uint16_T x_0;
  uint16_T z;
  int8_T AP_mode_idx_0;
  int8_T AP_mode_idx_1;
  uint8_T c;
  uint8_T counter;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T y;

  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&telemetria_ahrs_P.Constant1_Value_fl,
    &telemetria_ahrs_B.SFunctionBuilder_o1[0],
    &telemetria_ahrs_B.SFunctionBuilder_o2,
    &telemetria_ahrs_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  status = 0;
  caso = 0;
  memset(&telemetria_ahrs_B.messaggio[0], 0, 100U * sizeof(uint8_T));
  memset(&telemetria_ahrs_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  telemetria_ahrs_find_254(telemetria_ahrs_B.SFunctionBuilder_o1,
    telemetria_ahrs_B.poss_254, &telemetria_ahrs_B.num_254);
  if (telemetria_ahrs_DW.Interr_parz && (telemetria_ahrs_B.num_254 == 1.0)) {
    f = (int32_T)(telemetria_ahrs_DW.counter_e + 1U);
    if (telemetria_ahrs_DW.counter_e + 1U > 255U) {
      f = 255;
    }

    if (telemetria_ahrs_B.poss_254[0] != f) {
      telemetria_ahrs_B.num_254 = 0.0;
    }
  }

  y = !telemetria_ahrs_DW.Interr_parz;
  if ((telemetria_ahrs_B.num_254 == 1.0) && y) {
    caso = 1;
  } else if ((telemetria_ahrs_B.num_254 == 0.0) &&
             telemetria_ahrs_DW.Interr_parz) {
    caso = 2;
  } else if ((telemetria_ahrs_B.num_254 == 1.0) &&
             telemetria_ahrs_DW.Interr_parz) {
    caso = 3;
  } else {
    if ((telemetria_ahrs_B.num_254 == 2.0) && y) {
      caso = 4;
    }
  }

  switch (caso) {
   case 1:
    rtb_RateTransition = telemetria_ahrs_B.poss_254[(int32_T)
      telemetria_ahrs_B.num_254 - 1];
    if (rtb_RateTransition == 100.0) {
      telemetria_ahrs_DW.message[0] = telemetria_ahrs_B.SFunctionBuilder_o1[99];
      telemetria_ahrs_DW.Interr_parz = true;
    } else if (telemetria_ahrs_B.SFunctionBuilder_o1[(int32_T)
               (rtb_RateTransition + 1.0) - 1] <= 100) {
      f = (int32_T)(telemetria_ahrs_B.SFunctionBuilder_o1[(int32_T)
                    (telemetria_ahrs_B.poss_254[0] + 1.0) - 1] + 8U);
      g = f;
      if ((uint32_T)f > 255U) {
        g = 255;
      }

      if (g == telemetria_ahrs_B.SFunctionBuilder_o2) {
        telemetria_ahrs_B.num_254 = rt_roundd_snf(rtb_RateTransition);
        if (telemetria_ahrs_B.num_254 < 256.0) {
          if (telemetria_ahrs_B.num_254 >= 0.0) {
            counter = (uint8_T)telemetria_ahrs_B.num_254;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        f = (int32_T)(telemetria_ahrs_B.SFunctionBuilder_o1[(int32_T)
                      (rtb_RateTransition + 1.0) - 1] + 7U);
        if ((uint32_T)f > 255U) {
          f = 255;
        }

        rtb_RateTransition = rt_roundd_snf(rtb_RateTransition + (real_T)f);
        if (rtb_RateTransition < 256.0) {
          if (rtb_RateTransition >= 0.0) {
            c = (uint8_T)rtb_RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          status = 0;
          f = 0;
        } else {
          status = counter - 1;
          f = c;
        }

        caso = f - status;
        for (f = 0; f < caso; f++) {
          telemetria_ahrs_DW.message[f] =
            telemetria_ahrs_B.SFunctionBuilder_o1[status + f];
        }

        status = 1;
        for (caso = 0; caso < 100; caso++) {
          telemetria_ahrs_B.messaggio[caso] = telemetria_ahrs_DW.message[caso];
          telemetria_ahrs_DW.message[caso] = 0U;
        }

        telemetria_ahrs_DW.counter_e = 0U;
        telemetria_ahrs_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)f > 255U) {
          f = 255;
        }

        if (f > telemetria_ahrs_B.SFunctionBuilder_o2) {
          telemetria_ahrs_DW.mess_len = telemetria_ahrs_B.SFunctionBuilder_o2;
          if (rtb_RateTransition > telemetria_ahrs_DW.mess_len) {
            g = 0;
            f = 0;
          } else {
            g = (int32_T)rtb_RateTransition - 1;
            f = (int32_T)telemetria_ahrs_DW.mess_len;
          }

          caso = f - g;
          for (f = 0; f < caso; f++) {
            telemetria_ahrs_DW.message[f] =
              telemetria_ahrs_B.SFunctionBuilder_o1[g + f];
          }

          f = (int32_T)(telemetria_ahrs_B.SFunctionBuilder_o1[(int32_T)
                        (rtb_RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)f > 255U) {
            f = 255;
          }

          rtb_RateTransition = rt_roundd_snf((real_T)f -
            telemetria_ahrs_DW.mess_len);
          if (rtb_RateTransition < 256.0) {
            if (rtb_RateTransition >= 0.0) {
              telemetria_ahrs_DW.counter_e = (uint8_T)rtb_RateTransition;
            } else {
              telemetria_ahrs_DW.counter_e = 0U;
            }
          } else {
            telemetria_ahrs_DW.counter_e = MAX_uint8_T;
          }

          telemetria_ahrs_DW.Interr_parz = true;
        }
      }
    } else {
      telemetria_ahrs_DW.Interr_parz = false;
      memset(&telemetria_ahrs_DW.message[0], 0, 100U * sizeof(uint8_T));
      telemetria_ahrs_DW.counter_e = 0U;
      telemetria_ahrs_DW.mess_len = 0.0;
      status = 1;
    }
    break;

   case 2:
    for (f = 0; f < 100; f++) {
      telemetria_ahrs_B.x[f] = (telemetria_ahrs_B.SFunctionBuilder_o1[f] != 0);
    }

    if (telemetria_ahrs_ifWhileCond(telemetria_ahrs_B.x)) {
      rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_DW.mess_len + 1.0);
      if (rtb_RateTransition < 256.0) {
        if (rtb_RateTransition >= 0.0) {
          c = (uint8_T)rtb_RateTransition;
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_DW.mess_len + (real_T)
        telemetria_ahrs_DW.counter_e);
      if (rtb_RateTransition < 256.0) {
        if (rtb_RateTransition >= 0.0) {
          counter = (uint8_T)rtb_RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      if (c > counter) {
        status = 1;
      } else {
        status = c;
      }

      if (1 > telemetria_ahrs_DW.counter_e) {
        caso = -1;
      } else {
        caso = telemetria_ahrs_DW.counter_e - 1;
      }

      for (f = 0; f <= caso; f++) {
        telemetria_ahrs_DW.message[(status + f) - 1] =
          telemetria_ahrs_B.SFunctionBuilder_o1[f];
      }

      telemetria_ahrs_DW.Interr_parz = false;
      status = 1;
      for (caso = 0; caso < 100; caso++) {
        telemetria_ahrs_B.messaggio[caso] = telemetria_ahrs_DW.message[caso];
        telemetria_ahrs_DW.message[caso] = 0U;
      }

      telemetria_ahrs_DW.mess_len = 0.0;
      telemetria_ahrs_DW.counter_e = 0U;
    } else {
      telemetria_ahrs_DW.Interr_parz = false;
      status = 1;
      memset(&telemetria_ahrs_DW.message[0], 0, 100U * sizeof(uint8_T));
      telemetria_ahrs_DW.mess_len = 0.0;
      telemetria_ahrs_DW.counter_e = 0U;
    }
    break;

   case 3:
    rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_DW.mess_len + 1.0);
    if (rtb_RateTransition < 256.0) {
      if (rtb_RateTransition >= 0.0) {
        c = (uint8_T)rtb_RateTransition;
      } else {
        c = 0U;
      }
    } else {
      c = MAX_uint8_T;
    }

    rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_DW.mess_len + (real_T)
      telemetria_ahrs_DW.counter_e);
    if (rtb_RateTransition < 256.0) {
      if (rtb_RateTransition >= 0.0) {
        counter = (uint8_T)rtb_RateTransition;
      } else {
        counter = 0U;
      }
    } else {
      counter = MAX_uint8_T;
    }

    if (c > counter) {
      status = 1;
    } else {
      status = c;
    }

    if (1 > telemetria_ahrs_DW.counter_e) {
      caso = -1;
    } else {
      caso = telemetria_ahrs_DW.counter_e - 1;
    }

    for (f = 0; f <= caso; f++) {
      telemetria_ahrs_DW.message[(status + f) - 1] =
        telemetria_ahrs_B.SFunctionBuilder_o1[f];
    }

    telemetria_ahrs_DW.Interr_parz = false;
    status = 1;
    for (caso = 0; caso < 100; caso++) {
      telemetria_ahrs_B.messaggio[caso] = telemetria_ahrs_DW.message[caso];
      telemetria_ahrs_DW.message[caso] = 0U;
    }

    telemetria_ahrs_DW.mess_len = 0.0;
    telemetria_ahrs_DW.counter_e = 0U;
    f = (int32_T)(telemetria_ahrs_B.poss_254[(int32_T)telemetria_ahrs_B.num_254
                  - 1] + 1.0) - 1;
    if (telemetria_ahrs_B.SFunctionBuilder_o1[f] <= 100) {
      g = (int32_T)(telemetria_ahrs_B.SFunctionBuilder_o1[(int32_T)
                    (telemetria_ahrs_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)g > 255U) {
        g = 255;
      }

      caso = telemetria_ahrs_B.SFunctionBuilder_o2;
      if (telemetria_ahrs_B.SFunctionBuilder_o2 < 0) {
        caso = 0;
      } else {
        if (telemetria_ahrs_B.SFunctionBuilder_o2 > 255) {
          caso = 255;
        }
      }

      if (g == caso) {
        rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_B.poss_254[(int32_T)
          telemetria_ahrs_B.num_254 - 1]);
        if (rtb_RateTransition < 256.0) {
          if (rtb_RateTransition >= 0.0) {
            counter = (uint8_T)rtb_RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        f = (int32_T)(telemetria_ahrs_B.SFunctionBuilder_o1[f] + 7U);
        if ((uint32_T)f > 255U) {
          f = 255;
        }

        rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_B.poss_254[(int32_T)
          telemetria_ahrs_B.num_254 - 1] + (real_T)f);
        if (rtb_RateTransition < 256.0) {
          if (rtb_RateTransition >= 0.0) {
            c = (uint8_T)rtb_RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          g = 0;
          f = 0;
        } else {
          g = counter - 1;
          f = c;
        }

        caso = f - g;
        for (f = 0; f < caso; f++) {
          telemetria_ahrs_DW.message[f] =
            telemetria_ahrs_B.SFunctionBuilder_o1[g + f];
        }

        for (caso = 0; caso < 100; caso++) {
          telemetria_ahrs_B.messaggio_2[caso] = telemetria_ahrs_DW.message[caso];
          telemetria_ahrs_DW.message[caso] = 0U;
        }

        telemetria_ahrs_DW.counter_e = 0U;
        telemetria_ahrs_DW.mess_len = 0.0;
      } else {
        g = (int32_T)(telemetria_ahrs_B.SFunctionBuilder_o1[(int32_T)
                      (telemetria_ahrs_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)g > 255U) {
          g = 255;
        }

        caso = telemetria_ahrs_B.SFunctionBuilder_o2;
        if (telemetria_ahrs_B.SFunctionBuilder_o2 < 0) {
          caso = 0;
        } else {
          if (telemetria_ahrs_B.SFunctionBuilder_o2 > 255) {
            caso = 255;
          }
        }

        if (g > caso) {
          telemetria_ahrs_DW.mess_len = telemetria_ahrs_B.SFunctionBuilder_o2;
          if (telemetria_ahrs_B.poss_254[(int32_T)telemetria_ahrs_B.num_254 - 1]
              > telemetria_ahrs_DW.mess_len) {
            x = 0;
            caso = 0;
          } else {
            x = (int32_T)telemetria_ahrs_B.poss_254[(int32_T)
              telemetria_ahrs_B.num_254 - 1] - 1;
            caso = (int32_T)telemetria_ahrs_DW.mess_len;
          }

          caso -= x;
          for (g = 0; g < caso; g++) {
            telemetria_ahrs_DW.message[g] =
              telemetria_ahrs_B.SFunctionBuilder_o1[x + g];
          }

          f = (int32_T)(telemetria_ahrs_B.SFunctionBuilder_o1[f] + 8U);
          if ((uint32_T)f > 255U) {
            f = 255;
          }

          rtb_RateTransition = rt_roundd_snf((real_T)f -
            telemetria_ahrs_DW.mess_len);
          if (rtb_RateTransition < 256.0) {
            if (rtb_RateTransition >= 0.0) {
              telemetria_ahrs_DW.counter_e = (uint8_T)rtb_RateTransition;
            } else {
              telemetria_ahrs_DW.counter_e = 0U;
            }
          } else {
            telemetria_ahrs_DW.counter_e = MAX_uint8_T;
          }

          telemetria_ahrs_DW.Interr_parz = true;
        }
      }
    } else {
      telemetria_ahrs_DW.Interr_parz = false;
      memset(&telemetria_ahrs_B.messaggio[0], 0, 100U * sizeof(uint8_T));
      memset(&telemetria_ahrs_DW.message[0], 0, 100U * sizeof(uint8_T));
      telemetria_ahrs_DW.counter_e = 0U;
      telemetria_ahrs_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (telemetria_ahrs_B.SFunctionBuilder_o1[(int32_T)
        (telemetria_ahrs_B.poss_254[0] + 1.0) - 1] <= 100) {
      rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_B.poss_254[0]);
      if (rtb_RateTransition < 256.0) {
        if (rtb_RateTransition >= 0.0) {
          counter = (uint8_T)rtb_RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      f = (int32_T)(telemetria_ahrs_B.SFunctionBuilder_o1[(int32_T)
                    (telemetria_ahrs_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)f > 255U) {
        f = 255;
      }

      rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_B.poss_254[0] + (real_T)
        f);
      if (rtb_RateTransition < 256.0) {
        if (rtb_RateTransition >= 0.0) {
          c = (uint8_T)rtb_RateTransition;
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      if (counter > c) {
        status = 0;
        f = 0;
      } else {
        status = counter - 1;
        f = c;
      }

      caso = f - status;
      for (f = 0; f < caso; f++) {
        telemetria_ahrs_B.messaggio[f] =
          telemetria_ahrs_B.SFunctionBuilder_o1[status + f];
      }
    } else {
      telemetria_ahrs_DW.Interr_parz = false;
      memset(&telemetria_ahrs_DW.message[0], 0, 100U * sizeof(uint8_T));
    }

    status = 1;
    if ((telemetria_ahrs_B.SFunctionBuilder_o1[(int32_T)
         (telemetria_ahrs_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (telemetria_ahrs_B.poss_254[1] - telemetria_ahrs_B.poss_254[0] > 3.0)) {
      rtb_RateTransition = rt_roundd_snf((real_T)
        telemetria_ahrs_B.SFunctionBuilder_o2 - telemetria_ahrs_B.poss_254[1]);
      qY = telemetria_ahrs_B.SFunctionBuilder_o1[(int32_T)
        (telemetria_ahrs_B.poss_254[1] + 1.0) - 1];
      f = (int32_T)(qY + 7U);
      if (qY + 7U > 255U) {
        f = 255;
      }

      if (rtb_RateTransition < 2.147483648E+9) {
        if (rtb_RateTransition >= -2.147483648E+9) {
          g = (int32_T)rtb_RateTransition;
        } else {
          g = MIN_int32_T;
        }
      } else {
        g = MAX_int32_T;
      }

      if (g == f) {
        rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_B.poss_254[1]);
        if (rtb_RateTransition < 256.0) {
          if (rtb_RateTransition >= 0.0) {
            counter = (uint8_T)rtb_RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        f = (int32_T)(qY + 7U);
        if (qY + 7U > 255U) {
          f = 255;
        }

        rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_B.poss_254[1] +
          (real_T)f);
        if (rtb_RateTransition < 256.0) {
          if (rtb_RateTransition >= 0.0) {
            c = (uint8_T)rtb_RateTransition;
          } else {
            c = 0U;
          }
        } else {
          c = MAX_uint8_T;
        }

        if (counter > c) {
          status = 0;
          f = 0;
        } else {
          status = counter - 1;
          f = c;
        }

        caso = f - status;
        for (f = 0; f < caso; f++) {
          telemetria_ahrs_DW.message[f] =
            telemetria_ahrs_B.SFunctionBuilder_o1[status + f];
        }

        status = 2;
        for (caso = 0; caso < 100; caso++) {
          telemetria_ahrs_B.messaggio_2[caso] = telemetria_ahrs_DW.message[caso];
          telemetria_ahrs_DW.message[caso] = 0U;
        }

        telemetria_ahrs_DW.counter_e = 0U;
        telemetria_ahrs_DW.mess_len = 0.0;
      } else {
        rtb_RateTransition = rt_roundd_snf(telemetria_ahrs_B.poss_254[1]);
        if (rtb_RateTransition < 2.147483648E+9) {
          if (rtb_RateTransition >= -2.147483648E+9) {
            f = (int32_T)rtb_RateTransition;
          } else {
            f = MIN_int32_T;
          }
        } else {
          f = MAX_int32_T;
        }

        if (f > telemetria_ahrs_B.SFunctionBuilder_o2) {
          f = -1;
          caso = 0;
        } else {
          f -= 2;
          caso = telemetria_ahrs_B.SFunctionBuilder_o2;
        }

        telemetria_ahrs_DW.mess_len = (int8_T)((caso - f) - 1);
        if (rtb_RateTransition < 2.147483648E+9) {
          if (rtb_RateTransition >= -2.147483648E+9) {
            f = (int32_T)rtb_RateTransition;
          } else {
            f = MIN_int32_T;
          }
        } else {
          f = MAX_int32_T;
        }

        if (f > telemetria_ahrs_B.SFunctionBuilder_o2) {
          g = 0;
          f = 0;
        } else {
          g = f - 1;
          f = telemetria_ahrs_B.SFunctionBuilder_o2;
        }

        caso = f - g;
        for (f = 0; f < caso; f++) {
          telemetria_ahrs_DW.message[f] =
            telemetria_ahrs_B.SFunctionBuilder_o1[g + f];
        }

        f = (int32_T)(qY + 8U);
        if (qY + 8U > 255U) {
          f = 255;
        }

        rtb_RateTransition = rt_roundd_snf((real_T)f -
          telemetria_ahrs_DW.mess_len);
        if (rtb_RateTransition < 256.0) {
          if (rtb_RateTransition >= 0.0) {
            telemetria_ahrs_DW.counter_e = (uint8_T)rtb_RateTransition;
          } else {
            telemetria_ahrs_DW.counter_e = 0U;
          }
        } else {
          telemetria_ahrs_DW.counter_e = MAX_uint8_T;
        }

        telemetria_ahrs_DW.Interr_parz = true;
      }
    } else {
      telemetria_ahrs_DW.Interr_parz = false;
      memset(&telemetria_ahrs_DW.message[0], 0, 100U * sizeof(uint8_T));
      telemetria_ahrs_DW.counter_e = 0U;
      telemetria_ahrs_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&telemetria_ahrs_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (f = 0; f < 100; f++) {
    telemetria_ahrs_B.buffer[3 * f] = 0U;
  }

  for (f = 0; f < 100; f++) {
    for (caso = 0; caso < 2; caso++) {
      g = 3 * f + caso;
      telemetria_ahrs_B.buffer[g + 1] =
        telemetria_ahrs_DW.Memory4_PreviousInput[g];
    }
  }

  caso = 3;
  exitg1 = false;
  while ((!exitg1) && (caso >= 1)) {
    for (f = 0; f < 100; f++) {
      telemetria_ahrs_B.x[f] = (telemetria_ahrs_B.buffer[(3 * f + caso) - 1] ==
        0);
    }

    y = true;
    f = 0;
    exitg2 = false;
    while ((!exitg2) && (f < 100)) {
      if (!telemetria_ahrs_B.x[f]) {
        y = false;
        exitg2 = true;
      } else {
        f++;
      }
    }

    if (y) {
      counter = (uint8_T)caso;
      exitg1 = true;
    } else {
      caso--;
    }
  }

  if (status == 1) {
    for (f = 0; f < 100; f++) {
      telemetria_ahrs_B.buffer[(counter + 3 * f) - 1] =
        telemetria_ahrs_B.messaggio[f];
    }
  } else if (status == 2) {
    qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      qY = 0U;
    }

    for (f = 0; f < 100; f++) {
      telemetria_ahrs_B.buffer[(counter + 3 * f) - 1] =
        telemetria_ahrs_B.messaggio[f];
      telemetria_ahrs_B.buffer[((int32_T)qY + 3 * f) - 1] =
        telemetria_ahrs_B.messaggio_2[f];
    }
  } else {
    for (f = 0; f < 100; f++) {
      telemetria_ahrs_B.buffer[(counter + 3 * f) - 1] = 0U;
    }
  }

  for (f = 0; f < 100; f++) {
    telemetria_ahrs_B.mess_out[f] = telemetria_ahrs_DW.Memory4_PreviousInput[3 *
      f + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  telemetria_ahrs_B.Add = telemetria_ahrs_DW.Memory4_PreviousInput[5] +
    telemetria_ahrs_P.Constant_Value_i;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (telemetria_ahrs_B.mess_out[2] != telemetria_ahrs_DW.Memory5_PreviousInput
      [2]) {
    for (f = 0; f < 100; f++) {
      telemetria_ahrs_B.x[f] = (telemetria_ahrs_B.mess_out[f] != 0);
    }

    y = true;
    f = 0;
    exitg1 = false;
    while ((!exitg1) && (f < 100)) {
      if (!telemetria_ahrs_B.x[f]) {
        y = false;
        exitg1 = true;
      } else {
        f++;
      }
    }

    if (!y) {
      if (telemetria_ahrs_DW.counter > 100) {
        telemetria_ahrs_DW.counter = 0U;
      }

      qY = telemetria_ahrs_DW.counter + 1U;
      if (telemetria_ahrs_DW.counter + 1U > 65535U) {
        qY = 65535U;
      }

      telemetria_ahrs_DW.counter = (uint16_T)qY;
    }
  }

  telemetria_ahrs_B.new_mex = telemetria_ahrs_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  telemetria_ahrs_B.Memory1[0] = telemetria_ahrs_DW.Memory1_PreviousInput_e[0];
  telemetria_ahrs_B.Memory1[1] = telemetria_ahrs_DW.Memory1_PreviousInput_e[1];

  /* Memory: '<Root>/Memory' */
  telemetria_ahrs_B.Memory_o[0] = telemetria_ahrs_DW.Memory_PreviousInput_oi[0];
  telemetria_ahrs_B.Memory_o[1] = telemetria_ahrs_DW.Memory_PreviousInput_oi[1];
  telemetria_ahrs_B.Memory_o[2] = telemetria_ahrs_DW.Memory_PreviousInput_oi[2];
  telemetria_ahrs_B.Memory_o[3] = telemetria_ahrs_DW.Memory_PreviousInput_oi[3];

  /* Memory: '<S1>/Memory3' */
  telemetria_ahrs_B.Memory3 = telemetria_ahrs_DW.Memory3_PreviousInput;
  for (caso = 0; caso < 8; caso++) {
    /* Memory: '<S1>/Memory' */
    telemetria_ahrs_B.Memory[caso] =
      telemetria_ahrs_DW.Memory_PreviousInput_o[caso];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&telemetria_ahrs_B.mess_out[0], &telemetria_ahrs_B.Add,
     &telemetria_ahrs_B.new_mex, &telemetria_ahrs_P.SIUAVuint8_Value,
     &telemetria_ahrs_B.Memory[0], &telemetria_ahrs_B.Memory1[0],
     &telemetria_ahrs_B.Memory_o[0], &telemetria_ahrs_B.Memory3,
     &telemetria_ahrs_B.SFunction_o1[0], &telemetria_ahrs_B.SFunction_o2,
     &telemetria_ahrs_B.SFunction_o3_d, &telemetria_ahrs_B.SFunction_o4_e[0],
     &telemetria_ahrs_B.SFunction_o5[0], &telemetria_ahrs_B.SFunction_o6,
     &telemetria_ahrs_B.SFunction_o7[0], &telemetria_ahrs_B.SFunction_o8,
     &telemetria_ahrs_B.SFunction_o9[0], &telemetria_ahrs_B.SFunction_o10[0],
     &telemetria_ahrs_B.SFunction_o11[0], &telemetria_ahrs_B.SFunction_o12,
     &telemetria_ahrs_B.SFunction_o13, &telemetria_ahrs_B.SFunction_o14,
     &telemetria_ahrs_B.SFunction_o15, &telemetria_ahrs_B.SFunction_o16,
     &telemetria_ahrs_B.SFunction_o17, 100);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (caso = 0; caso < 6; caso++) {
    telemetria_ahrs_B.WP_info_in[caso] = telemetria_ahrs_B.SFunction_o9[caso];
  }

  if ((!telemetria_ahrs_DW.WP_dbP_not_empty) ||
      ((telemetria_ahrs_B.SFunction_o7[0] == 3) &&
       (telemetria_ahrs_B.SFunction_o7[1] == 250))) {
    memset(&telemetria_ahrs_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    telemetria_ahrs_DW.WP_dbP_not_empty = true;
    memset(&telemetria_ahrs_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!telemetria_ahrs_DW.WP_dbP_AL_not_empty) ||
      ((telemetria_ahrs_B.SFunction_o7[0] == 3) &&
       (telemetria_ahrs_B.SFunction_o7[1] == 250))) {
    telemetria_ahrs_DW.WP_dbP_AL_not_empty = true;
  }

  telemetria_ahrs_B.GC_info[0] = telemetria_ahrs_B.SFunction_o7[0];
  telemetria_ahrs_B.GC_info[1] = telemetria_ahrs_B.SFunction_o7[1];
  telemetria_ahrs_B.GC_info[2] = telemetria_ahrs_B.SFunction_o11[0];
  if (telemetria_ahrs_B.GC_info[0] == 1) {
    if ((telemetria_ahrs_B.GC_info[1] > 0) && (telemetria_ahrs_B.GC_info[1] <= 7))
    {
      if ((real32_T)fabs(telemetria_ahrs_B.SFunction_o8) > 0.0F) {
        telemetria_ahrs_DW.riferimenti[telemetria_ahrs_B.GC_info[1] - 1] = 1.0F;
      } else {
        if (telemetria_ahrs_B.SFunction_o8 == 0.0F) {
          telemetria_ahrs_DW.riferimenti[telemetria_ahrs_B.GC_info[1] - 1] =
            0.0F;
        }
      }
    } else {
      if ((telemetria_ahrs_B.GC_info[1] > 7) && (telemetria_ahrs_B.GC_info[1] <
           12)) {
        telemetria_ahrs_DW.riferimenti[telemetria_ahrs_B.GC_info[1] - 1] =
          telemetria_ahrs_B.SFunction_o8;
      }
    }
  }

  if (telemetria_ahrs_B.SFunction_o12 == 13) {
    telemetria_ahrs_DW.riferimenti[telemetria_ahrs_B.SFunction_o12 - 1] =
      telemetria_ahrs_B.SFunction_o13;
  }

  memcpy(&telemetria_ahrs_B.Val_out_MAV[0], &telemetria_ahrs_DW.riferimenti[0],
         sizeof(real32_T) << 4U);
  if ((telemetria_ahrs_B.GC_info[0] == 3) && (telemetria_ahrs_B.GC_info[1] ==
       200)) {
    if (telemetria_ahrs_B.SFunction_o9[0] > 6) {
      telemetria_ahrs_B.WP_info_in[0] = 6U;
    }

    for (f = 0; f < 6; f++) {
      telemetria_ahrs_DW.WP_dbI[f] = telemetria_ahrs_B.WP_info_in[0];
    }
  }

  if ((telemetria_ahrs_B.GC_info[0] == 3) && (telemetria_ahrs_B.GC_info[1] < 200))
  {
    if (telemetria_ahrs_B.SFunction_o10[1] == 0.0F) {
      qY = telemetria_ahrs_B.SFunction_o9[1] + 1U;
      if (telemetria_ahrs_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (f = 0; f < 7; f++) {
        telemetria_ahrs_DW.WP_dbP[((int32_T)qY + 6 * f) - 1] =
          telemetria_ahrs_B.SFunction_o10[f];
      }

      qY = telemetria_ahrs_B.SFunction_o9[1] + 1U;
      if (telemetria_ahrs_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (f = 0; f < 6; f++) {
        telemetria_ahrs_DW.WP_dbI[((int32_T)qY + 6 * (f + 1)) - 1] =
          telemetria_ahrs_B.WP_info_in[f + 1];
      }
    } else {
      qY = telemetria_ahrs_B.SFunction_o9[1] + 1U;
      if (telemetria_ahrs_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (f = 0; f < 6; f++) {
        telemetria_ahrs_DW.WP_dbI[((int32_T)qY + 6 * (f + 1)) - 1] =
          telemetria_ahrs_B.WP_info_in[f + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  telemetria_ahrs_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Memory: '<S1>/Memory2'
   */
  if ((telemetria_ahrs_B.SFunction_o6 == 0) && (telemetria_ahrs_B.SFunction_o3_d
       == 0)) {
    telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 0U;
    telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    telemetria_ahrs_DW.Memory3_PreviousInput = 0U;
  } else if ((telemetria_ahrs_B.SFunction_o6 == 0) &&
             (telemetria_ahrs_B.SFunction_o3_d == 3)) {
    telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 0U;
    telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    telemetria_ahrs_DW.Memory3_PreviousInput = 0U;
  } else if ((telemetria_ahrs_B.SFunction_o6 == 0) &&
             (telemetria_ahrs_B.SFunction_o3_d == 2)) {
    telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 0U;
    telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    telemetria_ahrs_DW.Memory3_PreviousInput = 0U;
  } else if ((telemetria_ahrs_B.SFunction_o6 == 0) &&
             (telemetria_ahrs_B.SFunction_o3_d == 1)) {
    telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 0U;
    telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    telemetria_ahrs_DW.Memory3_PreviousInput = 0U;
  } else {
    switch (telemetria_ahrs_B.SFunction_o6) {
     case 192:
      telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 192U;
      telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      telemetria_ahrs_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 208U;
      telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      telemetria_ahrs_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((telemetria_ahrs_B.SFunction_o6 == 220) &&
          (telemetria_ahrs_B.SFunction_o3_d != 5)) {
        if ((telemetria_ahrs_DW.Memory2_PreviousInput_k[0] == 0) &&
            (telemetria_ahrs_DW.Memory2_PreviousInput_k[1] == 0) &&
            ((telemetria_ahrs_DW.Memory2_PreviousInput_k[2] == 1) ||
             (telemetria_ahrs_DW.Memory2_PreviousInput_k[3] == 1) ||
             (telemetria_ahrs_DW.Memory2_PreviousInput_k[4] == 1) ||
             (telemetria_ahrs_DW.Memory2_PreviousInput_k[5] == 1) ||
             (telemetria_ahrs_DW.Memory2_PreviousInput_k[6] == 1) ||
             (telemetria_ahrs_DW.Memory2_PreviousInput_k[7] == 1))) {
          telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 220U;
          telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          telemetria_ahrs_DW.Memory3_PreviousInput = 220U;
        } else if ((telemetria_ahrs_DW.Memory2_PreviousInput_k[0] == 0) &&
                   (telemetria_ahrs_DW.Memory2_PreviousInput_k[1] == 1) &&
                   ((telemetria_ahrs_DW.Memory2_PreviousInput_k[2] == 1) ||
                    (telemetria_ahrs_DW.Memory2_PreviousInput_k[3] == 1) ||
                    (telemetria_ahrs_DW.Memory2_PreviousInput_k[4] == 1) ||
                    (telemetria_ahrs_DW.Memory2_PreviousInput_k[5] == 1) ||
                    (telemetria_ahrs_DW.Memory2_PreviousInput_k[6] == 1) ||
                    (telemetria_ahrs_DW.Memory2_PreviousInput_k[7] == 1))) {
          telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 220U;
          telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          telemetria_ahrs_DW.Memory3_PreviousInput = 220U;
        } else {
          telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 208U;
          telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          telemetria_ahrs_DW.Memory3_PreviousInput = 208U;
        }
      } else if (telemetria_ahrs_B.SFunction_o3_d == 5) {
        telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 220U;
        telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        telemetria_ahrs_DW.Memory1_PreviousInput_e[0] = 192U;
        telemetria_ahrs_DW.Memory1_PreviousInput_e[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  qY = 100U * telemetria_ahrs_B.SFunction_o11[5];
  if (qY > 65535U) {
    qY = 65535U;
  }

  if (telemetria_ahrs_B.SFunction_o11[4] == 0) {
    if ((uint16_T)qY == 0) {
      z = 0U;
    } else {
      z = MAX_uint16_T;
    }
  } else {
    z = (uint16_T)(telemetria_ahrs_B.SFunction_o11[4] == 0U ? MAX_uint32_T :
                   (uint32_T)(uint16_T)qY / telemetria_ahrs_B.SFunction_o11[4]);
    x_0 = (uint16_T)((uint32_T)(uint16_T)qY - (uint16_T)((uint32_T)z *
      telemetria_ahrs_B.SFunction_o11[4]));
    if ((x_0 > 0) && (x_0 >= (int32_T)((uint32_T)
          telemetria_ahrs_B.SFunction_o11[4] >> 1) +
                      (telemetria_ahrs_B.SFunction_o11[4] & 1))) {
      z++;
    }
  }

  telemetria_ahrs_B.T_0 = telemetria_ahrs_DW.riferimenti[12];

  /* RateTransition: '<S21>/Rate Transition' */
  rtb_RateTransition = telemetria_ahrs_DW.RateTransition_Buffer0;

  /* Sum: '<S21>/Add1' incorporates:
   *  Constant: '<S21>/Constant2'
   *  Constant: '<S21>/Constant3'
   *  Memory: '<S21>/Memory1'
   */
  telemetria_ahrs_B.num_254 = (telemetria_ahrs_P.Constant2_Value +
    telemetria_ahrs_P.Constant3_Value) +
    telemetria_ahrs_DW.Memory1_PreviousInput;

  /* Switch: '<S21>/Switch' */
  if (telemetria_ahrs_B.num_254 > telemetria_ahrs_P.Switch_Threshold) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S21>/Constant2'
     */
    telemetria_ahrs_DW.Memory1_PreviousInput = telemetria_ahrs_P.Constant2_Value;
  } else {
    /* Switch: '<S21>/Switch' */
    telemetria_ahrs_DW.Memory1_PreviousInput = telemetria_ahrs_B.num_254;
  }

  /* End of Switch: '<S21>/Switch' */

  /* MATLAB Function: '<S11>/iflogic_function' */
  if ((telemetria_ahrs_DW.Memory1_PreviousInput == 1.0) ||
      (telemetria_ahrs_DW.Memory1_PreviousInput == 3.0)) {
    telemetria_ahrs_B.iflogic = 26U;
  } else if ((telemetria_ahrs_DW.Memory1_PreviousInput == 2.0) ||
             (telemetria_ahrs_DW.Memory1_PreviousInput == 4.0)) {
    telemetria_ahrs_B.iflogic = 30U;
  } else if ((telemetria_ahrs_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 2.0)) {
    telemetria_ahrs_B.iflogic = 33U;
  } else if ((telemetria_ahrs_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 6.0)) {
    telemetria_ahrs_B.iflogic = 34U;
  } else if ((telemetria_ahrs_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 0.0)) {
    telemetria_ahrs_B.iflogic = 0U;
  } else if ((telemetria_ahrs_DW.Memory1_PreviousInput == 0.0) &&
             ((rtb_RateTransition == 1.0) || (rtb_RateTransition == 5.0) ||
              (rtb_RateTransition == 9.0))) {
    telemetria_ahrs_B.iflogic = 1U;
  } else if ((telemetria_ahrs_DW.Memory1_PreviousInput == 0.0) &&
             ((rtb_RateTransition == 3.0) || (rtb_RateTransition == 8.0))) {
    telemetria_ahrs_B.iflogic = 74U;
  } else if ((telemetria_ahrs_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 7.0)) {
    telemetria_ahrs_B.iflogic = 36U;
  } else if ((telemetria_ahrs_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 4.0)) {
    telemetria_ahrs_B.iflogic = 29U;
  } else {
    telemetria_ahrs_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S11>/iflogic_function' */

  /* Sum: '<S21>/Add' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/Constant1'
   *  Memory: '<S21>/Memory'
   */
  telemetria_ahrs_DW.Memory_PreviousInput += telemetria_ahrs_P.Constant_Value +
    telemetria_ahrs_P.Constant1_Value;

  /* Gain: '<S11>/Gain' */
  rtb_RateTransition = telemetria_ahrs_P.Gain_Gain *
    telemetria_ahrs_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  if (rtb_RateTransition < 0.0) {
    rtb_RateTransition = ceil(rtb_RateTransition);
  } else {
    rtb_RateTransition = floor(rtb_RateTransition);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  telemetria_ahrs_B.DataTypeConversion3 = rtb_RateTransition < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-rtb_RateTransition : (uint32_T)rtb_RateTransition;

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (f = 0; f < 6; f++) {
    telemetria_ahrs_B.WP_info[f] = telemetria_ahrs_DW.WP_dbI[6 * f];
  }

  for (f = 0; f < 7; f++) {
    telemetria_ahrs_B.WP_param[f] = telemetria_ahrs_DW.WP_dbP[6 * f];
  }

  if ((telemetria_ahrs_B.GC_info[0] == 2) && (telemetria_ahrs_B.GC_info[1] < 6))
  {
    qY = telemetria_ahrs_B.GC_info[1] + 1U;
    if (telemetria_ahrs_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (f = 0; f < 6; f++) {
      telemetria_ahrs_B.WP_info[f] = telemetria_ahrs_DW.WP_dbI[(6 * f + (int32_T)
        qY) - 1];
    }

    qY = telemetria_ahrs_B.GC_info[1] + 1U;
    if (telemetria_ahrs_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (f = 0; f < 7; f++) {
      telemetria_ahrs_B.WP_param[f] = telemetria_ahrs_DW.WP_dbP[(6 * f +
        (int32_T)qY) - 1];
    }
  }

  if ((telemetria_ahrs_B.GC_info[0] == 3) && (telemetria_ahrs_B.GC_info[1] < 200))
  {
    qY = telemetria_ahrs_B.GC_info[1] + 1U;
    if (telemetria_ahrs_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (f = 0; f < 6; f++) {
      telemetria_ahrs_B.WP_info[f] = telemetria_ahrs_DW.WP_dbI[(6 * f + (int32_T)
        qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S15>/MATLAB Function' */

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant'
   */
  rtb_RateTransition = floor(telemetria_ahrs_P.Gain_Gain_l *
    telemetria_ahrs_P.Constant_Value_g);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S13>/load uint16'
   *  Gain: '<S13>/Gain'
   */
  telemetria_ahrs_B.TmpSignalConversionAtSFunctionI[0] =
    telemetria_ahrs_P.loaduint16_Value;
  telemetria_ahrs_B.TmpSignalConversionAtSFunctionI[1] = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  qY = 10U * z;
  if (qY > 65535U) {
    qY = 65535U;
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S13>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  telemetria_ahrs_B.TmpSignalConversionAtSFunctionI[2] = (uint16_T)qY;
  telemetria_ahrs_B.TmpSignalConversionAtSFunctionI[3] =
    telemetria_ahrs_B.SFunction_o11[6];
  telemetria_ahrs_B.TmpSignalConversionAtSFunctionI[4] =
    telemetria_ahrs_B.SFunction_o11[2];
  telemetria_ahrs_B.TmpSignalConversionAtSFunctionI[5] =
    telemetria_ahrs_P._Value;

  /* Gain: '<S13>/Gain2' incorporates:
   *  Constant: '<S13>/Constant3'
   */
  rtb_RateTransition = floor(telemetria_ahrs_P.Gain2_Gain *
    telemetria_ahrs_P.Constant3_Value_d);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* Gain: '<S13>/Gain1' incorporates:
   *  Gain: '<S13>/Gain2'
   */
  telemetria_ahrs_B.Gain1 = (int16_T)(((rtb_RateTransition < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(int16_T)
    (uint16_T)rtb_RateTransition) * telemetria_ahrs_P.Gain1_Gain_i) >> 18);

  /* DataTypeConversion: '<S13>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/Constant4'
   */
  rtb_RateTransition = floor(telemetria_ahrs_P.Constant4_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion3' */
  telemetria_ahrs_B.B_Remaining = (int8_T)(rtb_RateTransition < 0.0 ? (int32_T)
    (int8_T)-(int8_T)(uint8_T)-rtb_RateTransition : (int32_T)(int8_T)(uint8_T)
    rtb_RateTransition);

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Constant: '<S9>/Constant'
   */
  rtb_RateTransition = floor(telemetria_ahrs_P.Constant_Value_d);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  telemetria_ahrs_B.DataTypeConversion = rtb_RateTransition < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-rtb_RateTransition : (uint32_T)rtb_RateTransition;

  /* DataTypeConversion: '<S13>/Data Type Conversion4' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  rtb_RateTransition = floor(telemetria_ahrs_P.Constant1_Value_e[0]);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion4'
   */
  telemetria_ahrs_B.TmpSignalConversionAtSFunctionI[6] = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  MATLAB Function: '<S9>/Alarm set'
   */
  telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[2] =
    telemetria_ahrs_DW.Memory1_PreviousInput_e[0];

  /* DataTypeConversion: '<S13>/Data Type Conversion4' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  rtb_RateTransition = floor(telemetria_ahrs_P.Constant1_Value_e[1]);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion4'
   */
  telemetria_ahrs_B.TmpSignalConversionAtSFunctionI[7] = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  MATLAB Function: '<S9>/Alarm set'
   */
  telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[3] =
    telemetria_ahrs_DW.Memory1_PreviousInput_e[1];

  /* MATLAB Function: '<S9>/Alarm set' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  if (telemetria_ahrs_P.Constant1_Value_h[0] == 1.0) {
    /* SignalConversion generated from: '<S2>/S-Function' */
    telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[2] = 220U;
    telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[3] = 5U;
  }

  if (telemetria_ahrs_P.Constant1_Value_h[1] == 1.0) {
    /* SignalConversion generated from: '<S2>/S-Function' */
    telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[2] = 216U;
    telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[3] = 4U;
  }

  /* SignalConversion generated from: '<S2>/S-Function' incorporates:
   *  Constant: '<S9>/Type fixed_wing Autopilot generic'
   */
  telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[0] =
    telemetria_ahrs_P.Typefixed_wingAutopilotgeneric_[0];
  telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[1] =
    telemetria_ahrs_P.Typefixed_wingAutopilotgeneric_[1];

  /* RateTransition generated from: '<S2>/S-Function' */
  if (telemetria_ahrs_M->Timing.RateInteraction.TID0_2) {
    /* RateTransition generated from: '<S2>/S-Function' */
    for (caso = 0; caso < 9; caso++) {
      telemetria_ahrs_B.TmpRTBAtSFunctionInport14[caso] =
        telemetria_ahrs_DW.TmpRTBAtSFunctionInport14_Buffe[caso];
    }

    /* End of RateTransition generated from: '<S2>/S-Function' */
    for (caso = 0; caso < 6; caso++) {
      /* RateTransition generated from: '<S2>/S-Function' */
      telemetria_ahrs_B.TmpRTBAtSFunctionInport15[caso] =
        telemetria_ahrs_DW.TmpRTBAtSFunctionInport15_Buffe[caso];
    }
  }

  /* End of RateTransition generated from: '<S2>/S-Function' */

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/Lat Simulated'
   *  Gain: '<S18>/Gain'
   */
  rtb_RateTransition = telemetria_ahrs_P.Gain_Gain_e *
    telemetria_ahrs_P.LatSimulated_Value * telemetria_ahrs_P.Gain_Gain_h[0];

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_RateTransition < 0.0) {
    rtb_RateTransition = ceil(rtb_RateTransition);
  } else {
    rtb_RateTransition = floor(rtb_RateTransition);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  telemetria_ahrs_B.DataTypeConversion_c[0] = rtb_RateTransition < 0.0 ?
    -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/Long Simulated'
   *  Gain: '<S19>/Gain'
   */
  rtb_RateTransition = telemetria_ahrs_P.Gain_Gain_m *
    telemetria_ahrs_P.LongSimulated_Value * telemetria_ahrs_P.Gain_Gain_h[1];

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_RateTransition < 0.0) {
    rtb_RateTransition = ceil(rtb_RateTransition);
  } else {
    rtb_RateTransition = floor(rtb_RateTransition);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  telemetria_ahrs_B.DataTypeConversion_c[1] = rtb_RateTransition < 0.0 ?
    -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/Alt Simulated'
   */
  rtb_RateTransition = telemetria_ahrs_P.Gain_Gain_h[2] *
    telemetria_ahrs_P.AltSimulated_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_RateTransition < 0.0) {
    rtb_RateTransition = ceil(rtb_RateTransition);
  } else {
    rtb_RateTransition = floor(rtb_RateTransition);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  telemetria_ahrs_B.DataTypeConversion_c[2] = rtb_RateTransition < 0.0 ?
    -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/alt_r'
   */
  rtb_RateTransition = telemetria_ahrs_P.Gain_Gain_h[3] *
    telemetria_ahrs_P.alt_r_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_RateTransition < 0.0) {
    rtb_RateTransition = ceil(rtb_RateTransition);
  } else {
    rtb_RateTransition = floor(rtb_RateTransition);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  telemetria_ahrs_B.DataTypeConversion_c[3] = rtb_RateTransition < 0.0 ?
    -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/v Simulated1'
   */
  rtb_RateTransition = telemetria_ahrs_P.Gain1_Gain *
    telemetria_ahrs_P.vSimulated1_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  if (rtb_RateTransition < 0.0) {
    rtb_RateTransition = ceil(rtb_RateTransition);
  } else {
    rtb_RateTransition = floor(rtb_RateTransition);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  telemetria_ahrs_B.DataTypeConversion1_m[0] = (int16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition);

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/vel y'
   */
  rtb_RateTransition = telemetria_ahrs_P.Gain1_Gain *
    telemetria_ahrs_P.vely_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  if (rtb_RateTransition < 0.0) {
    rtb_RateTransition = ceil(rtb_RateTransition);
  } else {
    rtb_RateTransition = floor(rtb_RateTransition);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  telemetria_ahrs_B.DataTypeConversion1_m[1] = (int16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition);

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/RC Simulated'
   */
  rtb_RateTransition = telemetria_ahrs_P.Gain1_Gain *
    telemetria_ahrs_P.RCSimulated_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  if (rtb_RateTransition < 0.0) {
    rtb_RateTransition = ceil(rtb_RateTransition);
  } else {
    rtb_RateTransition = floor(rtb_RateTransition);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  telemetria_ahrs_B.DataTypeConversion1_m[2] = (int16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition);

  /* Gain: '<S8>/Gain2' incorporates:
   *  Constant: '<S8>/Heading simulated'
   */
  rtb_RateTransition = telemetria_ahrs_P.Gain2_Gain_h *
    telemetria_ahrs_P.Headingsimulated_Value;

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  if (rtb_RateTransition < 0.0) {
    rtb_RateTransition = ceil(rtb_RateTransition);
  } else {
    rtb_RateTransition = floor(rtb_RateTransition);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  telemetria_ahrs_B.DataTypeConversion2 = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
   *  Constant: '<S14>/Alt simulated'
   *  Constant: '<S14>/RC simulated'
   *  Constant: '<S14>/TAS simulated'
   *  Constant: '<S14>/v simulated'
   */
  telemetria_ahrs_B.DataTypeConversion3_b[0] = (real32_T)
    telemetria_ahrs_P.TASsimulated_Value;
  telemetria_ahrs_B.DataTypeConversion3_b[1] = (real32_T)
    telemetria_ahrs_P.vsimulated_Value;
  telemetria_ahrs_B.DataTypeConversion3_b[2] = (real32_T)
    telemetria_ahrs_P.Altsimulated_Value;
  telemetria_ahrs_B.DataTypeConversion3_b[3] = (real32_T)
    telemetria_ahrs_P.RCsimulated_Value;

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Constant: '<S14>/ Heading simulated'
   */
  rtb_RateTransition = floor(telemetria_ahrs_P.Headingsimulated_Value_g);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion4' */
  telemetria_ahrs_B.DataTypeConversion4 = (int16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S14>/Data Type Conversion5' incorporates:
   *  Constant: '<S14>/Rpm simulated'
   */
  rtb_RateTransition = floor(telemetria_ahrs_P.Rpmsimulated_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion5' */
  telemetria_ahrs_B.DataTypeConversion5 = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* Gain: '<S23>/Gain2' incorporates:
   *  Constant: '<S12>/Manetta Simulated'
   */
  rtb_Gain2 = telemetria_ahrs_P.Gain2_Gain_p *
    telemetria_ahrs_P.ManettaSimulated_Value;

  /* Sum: '<S23>/Sum' incorporates:
   *  Constant: '<S12>/Equilibratore Simulated'
   *  Constant: '<S23>/Constant2'
   *  Gain: '<S24>/Gain'
   */
  telemetria_ahrs_B.num_254 = telemetria_ahrs_P.Gain_Gain_mr *
    telemetria_ahrs_P.EquilibratoreSimulated_Value +
    telemetria_ahrs_P.Constant2_Value_g;

  /* Sum: '<S23>/Sum1' incorporates:
   *  Constant: '<S12>/Alettoni Simulated'
   *  Constant: '<S23>/Constant2'
   *  Gain: '<S25>/Gain'
   */
  telemetria_ahrs_B.Sum1 = telemetria_ahrs_P.Gain_Gain_hs *
    telemetria_ahrs_P.AlettoniSimulated_Value +
    telemetria_ahrs_P.Constant2_Value_g;

  /* Sum: '<S23>/Sum2' incorporates:
   *  Constant: '<S12>/Timone Simulated'
   *  Constant: '<S23>/Constant2'
   *  Gain: '<S26>/Gain'
   */
  telemetria_ahrs_B.Sum2 = telemetria_ahrs_P.Gain_Gain_f *
    telemetria_ahrs_P.TimoneSimulated_Value +
    telemetria_ahrs_P.Constant2_Value_g;

  /* Gain: '<S12>/Gain' incorporates:
   *  Constant: '<S12>/Constant2'
   */
  telemetria_ahrs_B.PatohPa1 = telemetria_ahrs_P.Gain_Gain_k *
    telemetria_ahrs_P.Constant2_Value_j;

  /* Saturate: '<S12>/Saturation' */
  if (telemetria_ahrs_B.PatohPa1 > telemetria_ahrs_P.Saturation_UpperSat) {
    telemetria_ahrs_B.PatohPa1 = telemetria_ahrs_P.Saturation_UpperSat;
  } else {
    if (telemetria_ahrs_B.PatohPa1 < telemetria_ahrs_P.Saturation_LowerSat) {
      telemetria_ahrs_B.PatohPa1 = telemetria_ahrs_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant'
   */
  if (telemetria_ahrs_P.Constant_Value_l < 0.0) {
    rtb_RateTransition = ceil(telemetria_ahrs_P.Constant_Value_l);
  } else {
    rtb_RateTransition = floor(telemetria_ahrs_P.Constant_Value_l);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  telemetria_ahrs_B.Heading[0] = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (rtb_Gain2 < 0.0) {
    rtb_RateTransition = ceil(rtb_Gain2);
  } else {
    rtb_RateTransition = floor(rtb_Gain2);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  telemetria_ahrs_B.Heading[1] = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (telemetria_ahrs_B.num_254 < 0.0) {
    rtb_RateTransition = ceil(telemetria_ahrs_B.num_254);
  } else {
    rtb_RateTransition = floor(telemetria_ahrs_B.num_254);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  telemetria_ahrs_B.Heading[2] = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (telemetria_ahrs_B.Sum1 < 0.0) {
    rtb_RateTransition = ceil(telemetria_ahrs_B.Sum1);
  } else {
    rtb_RateTransition = floor(telemetria_ahrs_B.Sum1);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  telemetria_ahrs_B.Heading[3] = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (telemetria_ahrs_B.Sum2 < 0.0) {
    rtb_RateTransition = ceil(telemetria_ahrs_B.Sum2);
  } else {
    rtb_RateTransition = floor(telemetria_ahrs_B.Sum2);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  telemetria_ahrs_B.Heading[4] = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (telemetria_ahrs_P.Constant1_Value_f[0] < 0.0) {
    rtb_RateTransition = ceil(telemetria_ahrs_P.Constant1_Value_f[0]);
  } else {
    rtb_RateTransition = floor(telemetria_ahrs_P.Constant1_Value_f[0]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  telemetria_ahrs_B.Heading[5] = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (telemetria_ahrs_P.Constant1_Value_f[1] < 0.0) {
    rtb_RateTransition = ceil(telemetria_ahrs_P.Constant1_Value_f[1]);
  } else {
    rtb_RateTransition = floor(telemetria_ahrs_P.Constant1_Value_f[1]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  telemetria_ahrs_B.Heading[6] = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (telemetria_ahrs_P.Constant1_Value_f[2] < 0.0) {
    rtb_RateTransition = ceil(telemetria_ahrs_P.Constant1_Value_f[2]);
  } else {
    rtb_RateTransition = floor(telemetria_ahrs_P.Constant1_Value_f[2]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  telemetria_ahrs_B.Heading[7] = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (telemetria_ahrs_B.PatohPa1 < 0.0) {
    rtb_RateTransition = ceil(telemetria_ahrs_B.PatohPa1);
  } else {
    rtb_RateTransition = floor(telemetria_ahrs_B.PatohPa1);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  telemetria_ahrs_B.Heading[8] = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* Memory: '<S2>/Memory' */
  telemetria_ahrs_B.Memory_h = telemetria_ahrs_DW.Memory_PreviousInput_p;

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  telemetria_ahrs_B.DataTypeConversion3_d = (real32_T)
    telemetria_ahrs_P.Constant1_Value_n;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<S2>/Constant6'
   *  Gain: '<S2>/Pa to hPa'
   */
  telemetria_ahrs_B.DataTypeConversion_m = (real32_T)
    (telemetria_ahrs_P.PatohPa_Gain * telemetria_ahrs_P.Constant6_Value);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  telemetria_ahrs_B.DataTypeConversion1 = (real32_T)
    (telemetria_ahrs_P.PatohPa1_Gain * telemetria_ahrs_P.Constant2_Value_d);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  rtb_RateTransition = floor(telemetria_ahrs_P.Constant3_Value_f);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  telemetria_ahrs_B.DataTypeConversion2_b = (int16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S13>/onboard_control_sensor_present uint32'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper(&telemetria_ahrs_B.iflogic,
    &telemetria_ahrs_B.DataTypeConversion3, &telemetria_ahrs_P.SIUAVuint8_Value,
    &telemetria_ahrs_B.GC_info[0], &telemetria_ahrs_B.Val_out_MAV[0],
    &telemetria_ahrs_B.WP_info[0], &telemetria_ahrs_B.WP_param[0],
    &telemetria_ahrs_P.onboard_control_sensor_presentu[0],
    &telemetria_ahrs_B.TmpSignalConversionAtSFunctionI[0],
    &telemetria_ahrs_B.Gain1, &telemetria_ahrs_B.B_Remaining,
    &telemetria_ahrs_B.DataTypeConversion,
    &telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[0],
    &telemetria_ahrs_B.TmpRTBAtSFunctionInport14[0],
    &telemetria_ahrs_B.TmpRTBAtSFunctionInport15[0],
    &telemetria_ahrs_B.DataTypeConversion_c[0],
    &telemetria_ahrs_B.DataTypeConversion1_m[0],
    &telemetria_ahrs_B.DataTypeConversion2,
    &telemetria_ahrs_B.DataTypeConversion3_b[0],
    &telemetria_ahrs_B.DataTypeConversion4,
    &telemetria_ahrs_B.DataTypeConversion5, &telemetria_ahrs_B.Heading[0],
    &telemetria_ahrs_B.Memory_h, &telemetria_ahrs_B.DataTypeConversion3_d,
    &telemetria_ahrs_B.SFunction_o14, &telemetria_ahrs_B.T_0,
    &telemetria_ahrs_B.SFunction_o15, &telemetria_ahrs_B.DataTypeConversion_m,
    &telemetria_ahrs_B.DataTypeConversion1,
    &telemetria_ahrs_B.DataTypeConversion2_b, &telemetria_ahrs_B.SFunction_o5[0],
    &telemetria_ahrs_P.Constant4_Value_i, &telemetria_ahrs_P.Constant5_Value,
    &telemetria_ahrs_P.Constant10_Value, ((const uint16_T*)
    &telemetria_ahrs_U16GND), &telemetria_ahrs_B.SFunction_o1_m,
    &telemetria_ahrs_B.SFunction_o2_a[0], &telemetria_ahrs_B.SFunction_o3,
    &telemetria_ahrs_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (telemetria_ahrs_B.SFunction_o1_m > 0) {
    /* Chart: '<S7>/Chart' */
    if (telemetria_ahrs_DW.is_active_c9_telemetria_ahrs == 0U) {
      telemetria_ahrs_DW.is_active_c9_telemetria_ahrs = 1U;
      telemetria_ahrs_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (telemetria_ahrs_DW.obj.Protocol !=
            telemetria_ahrs_P.SerialTransmit_Protocol) {
          telemetria_ahrs_DW.obj.Protocol =
            telemetria_ahrs_P.SerialTransmit_Protocol;
        }

        counter = telemetria_ahrs_B.SFunction_o2_a[telemetria_ahrs_DW.i - 1];
        MW_Serial_write(telemetria_ahrs_DW.obj.port, &counter, 1.0,
                        telemetria_ahrs_DW.obj.dataSizeInBytes,
                        telemetria_ahrs_DW.obj.sendModeEnum,
                        telemetria_ahrs_DW.obj.dataType,
                        telemetria_ahrs_DW.obj.sendFormatEnum, 2.0, '\x00');
        if (telemetria_ahrs_DW.i < telemetria_ahrs_B.SFunction_o3) {
          f = telemetria_ahrs_DW.i + 1;
          if (telemetria_ahrs_DW.i + 1 > 255) {
            f = 255;
          }

          telemetria_ahrs_DW.i = (uint8_T)f;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      telemetria_ahrs_DW.i = 1U;
    }

    /* End of Chart: '<S7>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&telemetria_ahrs_DW.Memory4_PreviousInput[0],
         &telemetria_ahrs_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&telemetria_ahrs_P.Constant1_Value_fl,
    &telemetria_ahrs_B.SFunctionBuilder_o1[0],
    &telemetria_ahrs_B.SFunctionBuilder_o2,
    &telemetria_ahrs_DW.SFunctionBuilder_DSTATE);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&telemetria_ahrs_DW.Memory5_PreviousInput[0],
         &telemetria_ahrs_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  telemetria_ahrs_DW.Memory_PreviousInput_oi[0] =
    telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[0];
  telemetria_ahrs_DW.Memory_PreviousInput_oi[1] =
    telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[1];
  telemetria_ahrs_DW.Memory_PreviousInput_oi[2] =
    telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[2];
  telemetria_ahrs_DW.Memory_PreviousInput_oi[3] =
    telemetria_ahrs_B.TmpSignalConversionAtSFunctio_m[3];

  /* Update for Memory: '<S1>/Memory' */
  for (caso = 0; caso < 8; caso++) {
    telemetria_ahrs_DW.Memory_PreviousInput_o[caso] =
      telemetria_ahrs_B.SFunction_o11[caso];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  telemetria_ahrs_DW.Memory2_PreviousInput_k[0] = (uint8_T)AP_mode_idx_0;
  telemetria_ahrs_DW.Memory2_PreviousInput_k[1] = (uint8_T)AP_mode_idx_1;
  for (caso = 0; caso < 7; caso++) {
    tmp = rt_roundf_snf(telemetria_ahrs_DW.riferimenti[caso]);
    if (tmp < 256.0F) {
      if (tmp >= 0.0F) {
        telemetria_ahrs_DW.Memory2_PreviousInput_k[caso + 2] = (uint8_T)tmp;
      } else {
        telemetria_ahrs_DW.Memory2_PreviousInput_k[caso + 2] = 0U;
      }
    } else {
      telemetria_ahrs_DW.Memory2_PreviousInput_k[caso + 2] = MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for Memory: '<S2>/Memory' */
  telemetria_ahrs_DW.Memory_PreviousInput_p = telemetria_ahrs_B.SFunction_o4;
}

/* Model step function for TID1 */
void telemetria_ahrs_step1(void)       /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S21>/Add2' incorporates:
   *  Constant: '<S21>/Constant4'
   *  Constant: '<S21>/Constant5'
   *  Memory: '<S21>/Memory2'
   */
  telemetria_ahrs_DW.Memory2_PreviousInput +=
    telemetria_ahrs_P.Constant4_Value_c + telemetria_ahrs_P.Constant5_Value_d;

  /* Switch: '<S21>/Switch1' */
  if (telemetria_ahrs_DW.Memory2_PreviousInput >
      telemetria_ahrs_P.Switch1_Threshold) {
    /* Sum: '<S21>/Add2' incorporates:
     *  Constant: '<S21>/Constant4'
     */
    telemetria_ahrs_DW.Memory2_PreviousInput =
      telemetria_ahrs_P.Constant4_Value_c;
  }

  /* End of Switch: '<S21>/Switch1' */

  /* RateTransition: '<S21>/Rate Transition' */
  telemetria_ahrs_DW.RateTransition_Buffer0 =
    telemetria_ahrs_DW.Memory2_PreviousInput;
}

/* Model step function for TID2 */
void telemetria_ahrs_step2(void)       /* Sample time: [1.0s, 0.0s] */
{
  int32_T i;
  real32_T tmp;
  int16_T rtb_DataTypeConversion[9];

  /* S-Function (Mti): '<Root>/S-Function Builder' */
  Mti_Outputs_wrapper(&telemetria_ahrs_B.SFunctionBuilder[0],
                      &telemetria_ahrs_DW.SFunctionBuilder_DSTATE_h);

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
      memcpy((uint8_T*)&telemetria_ahrs_B.ByteUnpack_o1[0], (uint8_T*)
             &telemetria_ahrs_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&telemetria_ahrs_B.ByteUnpack_o2[0], (uint8_T*)
             &telemetria_ahrs_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&telemetria_ahrs_B.ByteUnpack_o3, (uint8_T*)
             &telemetria_ahrs_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<Root>/Byte Reversal' */

  /* ReverseEndian: <Root>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &telemetria_ahrs_B.ByteUnpack_o2[0];
    real32_T *y0 = &telemetria_ahrs_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S10>/Constant'
   *  DataTypeConversion: '<S10>/Data Type Conversion2'
   */
  for (i = 0; i < 6; i++) {
    tmp = (real32_T)floor(telemetria_ahrs_B.ByteReversal[i]);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0);
    }

    rtb_DataTypeConversion[i] = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  tmp = (real32_T)floor((real32_T)telemetria_ahrs_P.Constant_Value_n[0]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion[6] = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  tmp = (real32_T)floor((real32_T)telemetria_ahrs_P.Constant_Value_n[1]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion[7] = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  tmp = (real32_T)floor((real32_T)telemetria_ahrs_P.Constant_Value_n[2]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion[8] = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S10>/Data Type Conversion' */

  /* RateTransition generated from: '<S2>/S-Function' */
  for (i = 0; i < 9; i++) {
    telemetria_ahrs_DW.TmpRTBAtSFunctionInport14_Buffe[i] =
      rtb_DataTypeConversion[i];
  }

  /* End of RateTransition generated from: '<S2>/S-Function' */

  /* RateTransition generated from: '<S2>/S-Function' */
  telemetria_ahrs_DW.TmpRTBAtSFunctionInport15_Buffe[0] =
    telemetria_ahrs_B.ByteReversal[6];
  telemetria_ahrs_DW.TmpRTBAtSFunctionInport15_Buffe[3] =
    telemetria_ahrs_B.ByteReversal[3];
  telemetria_ahrs_DW.TmpRTBAtSFunctionInport15_Buffe[1] =
    telemetria_ahrs_B.ByteReversal[7];
  telemetria_ahrs_DW.TmpRTBAtSFunctionInport15_Buffe[4] =
    telemetria_ahrs_B.ByteReversal[4];
  telemetria_ahrs_DW.TmpRTBAtSFunctionInport15_Buffe[2] =
    telemetria_ahrs_B.ByteReversal[8];
  telemetria_ahrs_DW.TmpRTBAtSFunctionInport15_Buffe[5] =
    telemetria_ahrs_B.ByteReversal[5];

  /* Update for S-Function (Mti): '<Root>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <Root>/S-Function Builder */
  Mti_Update_wrapper(&telemetria_ahrs_B.SFunctionBuilder[0],
                     &telemetria_ahrs_DW.SFunctionBuilder_DSTATE_h);
}

/* Model initialize function */
void telemetria_ahrs_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const real32_T tmp[16] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 20.0F, 100.0F, 2.0F, 101325.0F, 15.0F, 0.0F, 0.0F, 0.0F };

    real_T tmp_0;
    int32_T i;
    uint8_T tmp_1;
    for (i = 0; i < 9; i++) {
      /* Start for RateTransition generated from: '<S2>/S-Function' */
      telemetria_ahrs_B.TmpRTBAtSFunctionInport14[i] =
        telemetria_ahrs_P.TmpRTBAtSFunctionInport14_Initi;
    }

    for (i = 0; i < 6; i++) {
      /* Start for RateTransition generated from: '<S2>/S-Function' */
      telemetria_ahrs_B.TmpRTBAtSFunctionInport15[i] =
        telemetria_ahrs_P.TmpRTBAtSFunctionInport15_Initi;
    }

    /* Start for S-Function (Mti): '<Root>/S-Function Builder' */

    /* S-Function Block: <Root>/S-Function Builder */
    Mti_Start_wrapper(&telemetria_ahrs_DW.SFunctionBuilder_DSTATE_h);

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&telemetria_ahrs_DW.Memory4_PreviousInput[0],
           &telemetria_ahrs_P.Memory4_InitialCondition[0], 300U * sizeof(uint8_T));

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          telemetria_ahrs_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      telemetria_ahrs_DW.Memory5_PreviousInput[i] =
        telemetria_ahrs_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    telemetria_ahrs_DW.Memory1_PreviousInput_e[0] =
      telemetria_ahrs_P.Memory1_InitialCondition_g;
    telemetria_ahrs_DW.Memory1_PreviousInput_e[1] =
      telemetria_ahrs_P.Memory1_InitialCondition_g;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    telemetria_ahrs_DW.Memory_PreviousInput_oi[0] =
      telemetria_ahrs_P.Memory_InitialCondition_i;
    telemetria_ahrs_DW.Memory_PreviousInput_oi[1] =
      telemetria_ahrs_P.Memory_InitialCondition_i;
    telemetria_ahrs_DW.Memory_PreviousInput_oi[2] =
      telemetria_ahrs_P.Memory_InitialCondition_i;
    telemetria_ahrs_DW.Memory_PreviousInput_oi[3] =
      telemetria_ahrs_P.Memory_InitialCondition_i;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    telemetria_ahrs_DW.Memory3_PreviousInput =
      telemetria_ahrs_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      telemetria_ahrs_DW.Memory_PreviousInput_o[i] =
        telemetria_ahrs_P.Memory_InitialCondition_b;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      telemetria_ahrs_DW.Memory2_PreviousInput_k[i] =
        telemetria_ahrs_P.Memory2_InitialCondition_c[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S21>/Rate Transition' */
    telemetria_ahrs_DW.RateTransition_Buffer0 =
      telemetria_ahrs_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S21>/Switch' incorporates:
     *  Memory: '<S21>/Memory1'
     */
    telemetria_ahrs_DW.Memory1_PreviousInput =
      telemetria_ahrs_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S21>/Add' incorporates:
     *  Memory: '<S21>/Memory'
     */
    telemetria_ahrs_DW.Memory_PreviousInput =
      telemetria_ahrs_P.Memory_InitialCondition;

    /* InitializeConditions for RateTransition generated from: '<S2>/S-Function' */
    for (i = 0; i < 9; i++) {
      telemetria_ahrs_DW.TmpRTBAtSFunctionInport14_Buffe[i] =
        telemetria_ahrs_P.TmpRTBAtSFunctionInport14_Initi;
    }

    /* End of InitializeConditions for RateTransition generated from: '<S2>/S-Function' */

    /* InitializeConditions for RateTransition generated from: '<S2>/S-Function' */
    for (i = 0; i < 6; i++) {
      telemetria_ahrs_DW.TmpRTBAtSFunctionInport15_Buffe[i] =
        telemetria_ahrs_P.TmpRTBAtSFunctionInport15_Initi;
    }

    /* End of InitializeConditions for RateTransition generated from: '<S2>/S-Function' */

    /* InitializeConditions for Memory: '<S2>/Memory' */
    telemetria_ahrs_DW.Memory_PreviousInput_p =
      telemetria_ahrs_P.Memory_InitialCondition_g;

    /* InitializeConditions for Sum: '<S21>/Add2' incorporates:
     *  Memory: '<S21>/Memory2'
     */
    telemetria_ahrs_DW.Memory2_PreviousInput =
      telemetria_ahrs_P.Memory2_InitialCondition;

    /* InitializeConditions for S-Function (Mti): '<Root>/S-Function Builder' */

    /* S-Function Block: <Root>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          telemetria_ahrs_DW.SFunctionBuilder_DSTATE_h = initVector[0];
        }
      }
    }

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&telemetria_ahrs_DW.riferimenti[0], &tmp[0], sizeof(real32_T) << 4U);

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S7>/Chart' incorporates:
     *  SubSystem: '<S16>/sendbyte'
     */
    /* Start for MATLABSystem: '<S17>/Serial Transmit' */
    telemetria_ahrs_DW.obj.matlabCodegenIsDeleted = false;
    telemetria_ahrs_DW.obj.Protocol = telemetria_ahrs_P.SerialTransmit_Protocol;
    telemetria_ahrs_DW.obj.isInitialized = 1;
    telemetria_ahrs_DW.obj.port = 2.0;
    telemetria_ahrs_DW.obj.dataSizeInBytes = 1.0;
    telemetria_ahrs_DW.obj.dataType = 0.0;
    telemetria_ahrs_DW.obj.sendModeEnum = 0.0;
    telemetria_ahrs_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(telemetria_ahrs_DW.obj.port);
    if (tmp_0 < 256.0) {
      if (tmp_0 >= 0.0) {
        tmp_1 = (uint8_T)tmp_0;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_1);
    telemetria_ahrs_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S17>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */
  }
}

/* Model terminate function */
void telemetria_ahrs_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S7>/Chart' incorporates:
   *  SubSystem: '<S16>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S17>/Serial Transmit' */
  if (!telemetria_ahrs_DW.obj.matlabCodegenIsDeleted) {
    telemetria_ahrs_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S17>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
