/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_3_of_provaLOG_09_28_BUONO.c
 *
 * Code generated for Simulink model 'Copy_3_of_provaLOG_09_28_BUONO'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 25 12:49:50 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Copy_3_of_provaLOG_09_28_BUONO.h"
#include "Copy_3_of_provaLOG_09_28_BUONO_private.h"

const uint16_T Copy_3_of_provaLOG_09_28_BUONO_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_Copy_3_of_provaLOG_09_28_BU_T Copy_3_of_provaLOG_09_28_BUON_B;

/* Block states (default storage) */
DW_Copy_3_of_provaLOG_09_28_B_T Copy_3_of_provaLOG_09_28_BUO_DW;

/* Real-time model */
static RT_MODEL_Copy_3_of_provaLOG_0_T Copy_3_of_provaLOG_09_28_BUO_M_;
RT_MODEL_Copy_3_of_provaLOG_0_T *const Copy_3_of_provaLOG_09_28_BUO_M =
  &Copy_3_of_provaLOG_09_28_BUO_M_;

/* Forward declaration for local functions */
static void Copy_3_of_provaLOG_09__find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter);
static boolean_T Copy_3_of_provaLOG__ifWhileCond(const boolean_T x[100]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Copy_3_of_provaLOG_09_28_BUONO_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Copy_3_of_provaLOG_09_28_BUO_M, 1));
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
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Copy_3_of_provaLOG_09_28_BUO_M->Timing.TaskCounters.TID[1])++;
  if ((Copy_3_of_provaLOG_09_28_BUO_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    Copy_3_of_provaLOG_09_28_BUO_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void Copy_3_of_provaLOG_09__find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter)
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
static boolean_T Copy_3_of_provaLOG__ifWhileCond(const boolean_T x[100])
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
void Copy_3_of_provaLOG_09_28_BUONO_step0(void) /* Sample time: [0.02s, 0.0s] */
{
  real_T rtb_RateTransition;
  int32_T caso;
  int32_T exitg3;
  int32_T f;
  int32_T g;
  int32_T status;
  int32_T x;
  real32_T tmp;
  real32_T tmp_0;
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
  Seriale_mav_Outputs_wrapper(&Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_i,
    &Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[0],
    &Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2,
    &Copy_3_of_provaLOG_09_28_BUO_DW.SFunctionBuilder_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  status = 0;
  caso = 0;
  memset(&Copy_3_of_provaLOG_09_28_BUON_B.messaggio[0], 0, 100U * sizeof(uint8_T));
  memset(&Copy_3_of_provaLOG_09_28_BUON_B.messaggio_2[0], 0, 100U * sizeof
         (uint8_T));
  Copy_3_of_provaLOG_09__find_254
    (Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1,
     Copy_3_of_provaLOG_09_28_BUON_B.poss_254,
     &Copy_3_of_provaLOG_09_28_BUON_B.num_254);
  if (Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz &&
      (Copy_3_of_provaLOG_09_28_BUON_B.num_254 == 1.0)) {
    f = (int32_T)(Copy_3_of_provaLOG_09_28_BUO_DW.counter_m + 1U);
    if (Copy_3_of_provaLOG_09_28_BUO_DW.counter_m + 1U > 255U) {
      f = 255;
    }

    if (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[0] != f) {
      Copy_3_of_provaLOG_09_28_BUON_B.num_254 = 0.0;
    }
  }

  y = !Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz;
  if ((Copy_3_of_provaLOG_09_28_BUON_B.num_254 == 1.0) && y) {
    caso = 1;
  } else if ((Copy_3_of_provaLOG_09_28_BUON_B.num_254 == 0.0) &&
             Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz) {
    caso = 2;
  } else if ((Copy_3_of_provaLOG_09_28_BUON_B.num_254 == 1.0) &&
             Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz) {
    caso = 3;
  } else {
    if ((Copy_3_of_provaLOG_09_28_BUON_B.num_254 == 2.0) && y) {
      caso = 4;
    }
  }

  switch (caso) {
   case 1:
    rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUON_B.poss_254[(int32_T)
      Copy_3_of_provaLOG_09_28_BUON_B.num_254 - 1];
    if (rtb_RateTransition == 100.0) {
      Copy_3_of_provaLOG_09_28_BUO_DW.message[0] =
        Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[99];
      Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = true;
    } else if (Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[(int32_T)
               (rtb_RateTransition + 1.0) - 1] <= 100) {
      f = (int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[(int32_T)
                    (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[0] + 1.0) - 1] +
                    8U);
      g = f;
      if ((uint32_T)f > 255U) {
        g = 255;
      }

      if (g == Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2) {
        Copy_3_of_provaLOG_09_28_BUON_B.num_254 = rt_roundd_snf
          (rtb_RateTransition);
        if (Copy_3_of_provaLOG_09_28_BUON_B.num_254 < 256.0) {
          if (Copy_3_of_provaLOG_09_28_BUON_B.num_254 >= 0.0) {
            counter = (uint8_T)Copy_3_of_provaLOG_09_28_BUON_B.num_254;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        f = (int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1
                      [(int32_T)(rtb_RateTransition + 1.0) - 1] + 7U);
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
          Copy_3_of_provaLOG_09_28_BUO_DW.message[f] =
            Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[status + f];
        }

        status = 1;
        for (caso = 0; caso < 100; caso++) {
          Copy_3_of_provaLOG_09_28_BUON_B.messaggio[caso] =
            Copy_3_of_provaLOG_09_28_BUO_DW.message[caso];
          Copy_3_of_provaLOG_09_28_BUO_DW.message[caso] = 0U;
        }

        Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
        Copy_3_of_provaLOG_09_28_BUO_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)f > 255U) {
          f = 255;
        }

        if (f > Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2) {
          Copy_3_of_provaLOG_09_28_BUO_DW.mess_len =
            Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2;
          if (rtb_RateTransition > Copy_3_of_provaLOG_09_28_BUO_DW.mess_len) {
            g = 0;
            f = 0;
          } else {
            g = (int32_T)rtb_RateTransition - 1;
            f = (int32_T)Copy_3_of_provaLOG_09_28_BUO_DW.mess_len;
          }

          caso = f - g;
          for (f = 0; f < caso; f++) {
            Copy_3_of_provaLOG_09_28_BUO_DW.message[f] =
              Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[g + f];
          }

          f = (int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1
                        [(int32_T)(rtb_RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)f > 255U) {
            f = 255;
          }

          rtb_RateTransition = rt_roundd_snf((real_T)f -
            Copy_3_of_provaLOG_09_28_BUO_DW.mess_len);
          if (rtb_RateTransition < 256.0) {
            if (rtb_RateTransition >= 0.0) {
              Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = (uint8_T)
                rtb_RateTransition;
            } else {
              Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
            }
          } else {
            Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = MAX_uint8_T;
          }

          Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = true;
        }
      }
    } else {
      Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = false;
      memset(&Copy_3_of_provaLOG_09_28_BUO_DW.message[0], 0, 100U * sizeof
             (uint8_T));
      Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
      Copy_3_of_provaLOG_09_28_BUO_DW.mess_len = 0.0;
      status = 1;
    }
    break;

   case 2:
    for (f = 0; f < 100; f++) {
      Copy_3_of_provaLOG_09_28_BUON_B.x[f] =
        (Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[f] != 0);
    }

    if (Copy_3_of_provaLOG__ifWhileCond(Copy_3_of_provaLOG_09_28_BUON_B.x)) {
      rtb_RateTransition = rt_roundd_snf
        (Copy_3_of_provaLOG_09_28_BUO_DW.mess_len + 1.0);
      if (rtb_RateTransition < 256.0) {
        if (rtb_RateTransition >= 0.0) {
          c = (uint8_T)rtb_RateTransition;
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      rtb_RateTransition = rt_roundd_snf
        (Copy_3_of_provaLOG_09_28_BUO_DW.mess_len + (real_T)
         Copy_3_of_provaLOG_09_28_BUO_DW.counter_m);
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

      if (1 > Copy_3_of_provaLOG_09_28_BUO_DW.counter_m) {
        caso = -1;
      } else {
        caso = Copy_3_of_provaLOG_09_28_BUO_DW.counter_m - 1;
      }

      for (f = 0; f <= caso; f++) {
        Copy_3_of_provaLOG_09_28_BUO_DW.message[(status + f) - 1] =
          Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[f];
      }

      Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = false;
      status = 1;
      for (caso = 0; caso < 100; caso++) {
        Copy_3_of_provaLOG_09_28_BUON_B.messaggio[caso] =
          Copy_3_of_provaLOG_09_28_BUO_DW.message[caso];
        Copy_3_of_provaLOG_09_28_BUO_DW.message[caso] = 0U;
      }

      Copy_3_of_provaLOG_09_28_BUO_DW.mess_len = 0.0;
      Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
    } else {
      Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = false;
      status = 1;
      memset(&Copy_3_of_provaLOG_09_28_BUO_DW.message[0], 0, 100U * sizeof
             (uint8_T));
      Copy_3_of_provaLOG_09_28_BUO_DW.mess_len = 0.0;
      Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
    }
    break;

   case 3:
    rtb_RateTransition = rt_roundd_snf(Copy_3_of_provaLOG_09_28_BUO_DW.mess_len
      + 1.0);
    if (rtb_RateTransition < 256.0) {
      if (rtb_RateTransition >= 0.0) {
        c = (uint8_T)rtb_RateTransition;
      } else {
        c = 0U;
      }
    } else {
      c = MAX_uint8_T;
    }

    rtb_RateTransition = rt_roundd_snf(Copy_3_of_provaLOG_09_28_BUO_DW.mess_len
      + (real_T)Copy_3_of_provaLOG_09_28_BUO_DW.counter_m);
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

    if (1 > Copy_3_of_provaLOG_09_28_BUO_DW.counter_m) {
      caso = -1;
    } else {
      caso = Copy_3_of_provaLOG_09_28_BUO_DW.counter_m - 1;
    }

    for (f = 0; f <= caso; f++) {
      Copy_3_of_provaLOG_09_28_BUO_DW.message[(status + f) - 1] =
        Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[f];
    }

    Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = false;
    status = 1;
    for (caso = 0; caso < 100; caso++) {
      Copy_3_of_provaLOG_09_28_BUON_B.messaggio[caso] =
        Copy_3_of_provaLOG_09_28_BUO_DW.message[caso];
      Copy_3_of_provaLOG_09_28_BUO_DW.message[caso] = 0U;
    }

    Copy_3_of_provaLOG_09_28_BUO_DW.mess_len = 0.0;
    Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
    f = (int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.poss_254[(int32_T)
                  Copy_3_of_provaLOG_09_28_BUON_B.num_254 - 1] + 1.0) - 1;
    if (Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[f] <= 100) {
      g = (int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[(int32_T)
                    (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[0] + 1.0) - 1] +
                    8U);
      if ((uint32_T)g > 255U) {
        g = 255;
      }

      caso = Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2;
      if (Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2 < 0) {
        caso = 0;
      } else {
        if (Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2 > 255) {
          caso = 255;
        }
      }

      if (g == caso) {
        rtb_RateTransition = rt_roundd_snf
          (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[(int32_T)
           Copy_3_of_provaLOG_09_28_BUON_B.num_254 - 1]);
        if (rtb_RateTransition < 256.0) {
          if (rtb_RateTransition >= 0.0) {
            counter = (uint8_T)rtb_RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        f = (int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[f] +
                      7U);
        if ((uint32_T)f > 255U) {
          f = 255;
        }

        rtb_RateTransition = rt_roundd_snf
          (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[(int32_T)
           Copy_3_of_provaLOG_09_28_BUON_B.num_254 - 1] + (real_T)f);
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
          Copy_3_of_provaLOG_09_28_BUO_DW.message[f] =
            Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[g + f];
        }

        for (caso = 0; caso < 100; caso++) {
          Copy_3_of_provaLOG_09_28_BUON_B.messaggio_2[caso] =
            Copy_3_of_provaLOG_09_28_BUO_DW.message[caso];
          Copy_3_of_provaLOG_09_28_BUO_DW.message[caso] = 0U;
        }

        Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
        Copy_3_of_provaLOG_09_28_BUO_DW.mess_len = 0.0;
      } else {
        g = (int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1
                      [(int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.poss_254[0] +
          1.0) - 1] + 8U);
        if ((uint32_T)g > 255U) {
          g = 255;
        }

        caso = Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2;
        if (Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2 < 0) {
          caso = 0;
        } else {
          if (Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2 > 255) {
            caso = 255;
          }
        }

        if (g > caso) {
          Copy_3_of_provaLOG_09_28_BUO_DW.mess_len =
            Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2;
          if (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[(int32_T)
              Copy_3_of_provaLOG_09_28_BUON_B.num_254 - 1] >
              Copy_3_of_provaLOG_09_28_BUO_DW.mess_len) {
            x = 0;
            caso = 0;
          } else {
            x = (int32_T)Copy_3_of_provaLOG_09_28_BUON_B.poss_254[(int32_T)
              Copy_3_of_provaLOG_09_28_BUON_B.num_254 - 1] - 1;
            caso = (int32_T)Copy_3_of_provaLOG_09_28_BUO_DW.mess_len;
          }

          caso -= x;
          for (g = 0; g < caso; g++) {
            Copy_3_of_provaLOG_09_28_BUO_DW.message[g] =
              Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[x + g];
          }

          f = (int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[f] +
                        8U);
          if ((uint32_T)f > 255U) {
            f = 255;
          }

          rtb_RateTransition = rt_roundd_snf((real_T)f -
            Copy_3_of_provaLOG_09_28_BUO_DW.mess_len);
          if (rtb_RateTransition < 256.0) {
            if (rtb_RateTransition >= 0.0) {
              Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = (uint8_T)
                rtb_RateTransition;
            } else {
              Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
            }
          } else {
            Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = MAX_uint8_T;
          }

          Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = true;
        }
      }
    } else {
      Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = false;
      memset(&Copy_3_of_provaLOG_09_28_BUON_B.messaggio[0], 0, 100U * sizeof
             (uint8_T));
      memset(&Copy_3_of_provaLOG_09_28_BUO_DW.message[0], 0, 100U * sizeof
             (uint8_T));
      Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
      Copy_3_of_provaLOG_09_28_BUO_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[(int32_T)
        (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[0] + 1.0) - 1] <= 100) {
      rtb_RateTransition = rt_roundd_snf
        (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[0]);
      if (rtb_RateTransition < 256.0) {
        if (rtb_RateTransition >= 0.0) {
          counter = (uint8_T)rtb_RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      f = (int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[(int32_T)
                    (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[0] + 1.0) - 1] +
                    7U);
      if ((uint32_T)f > 255U) {
        f = 255;
      }

      rtb_RateTransition = rt_roundd_snf
        (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[0] + (real_T)f);
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
        Copy_3_of_provaLOG_09_28_BUON_B.messaggio[f] =
          Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[status + f];
      }
    } else {
      Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = false;
      memset(&Copy_3_of_provaLOG_09_28_BUO_DW.message[0], 0, 100U * sizeof
             (uint8_T));
    }

    status = 1;
    if ((Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[(int32_T)
         (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[1] -
         Copy_3_of_provaLOG_09_28_BUON_B.poss_254[0] > 3.0)) {
      rtb_RateTransition = rt_roundd_snf((real_T)
        Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2 -
        Copy_3_of_provaLOG_09_28_BUON_B.poss_254[1]);
      qY = Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[(int32_T)
        (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[1] + 1.0) - 1];
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
        rtb_RateTransition = rt_roundd_snf
          (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[1]);
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

        rtb_RateTransition = rt_roundd_snf
          (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[1] + (real_T)f);
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
          Copy_3_of_provaLOG_09_28_BUO_DW.message[f] =
            Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[status + f];
        }

        status = 2;
        for (caso = 0; caso < 100; caso++) {
          Copy_3_of_provaLOG_09_28_BUON_B.messaggio_2[caso] =
            Copy_3_of_provaLOG_09_28_BUO_DW.message[caso];
          Copy_3_of_provaLOG_09_28_BUO_DW.message[caso] = 0U;
        }

        Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
        Copy_3_of_provaLOG_09_28_BUO_DW.mess_len = 0.0;
      } else {
        rtb_RateTransition = rt_roundd_snf
          (Copy_3_of_provaLOG_09_28_BUON_B.poss_254[1]);
        if (rtb_RateTransition < 2.147483648E+9) {
          if (rtb_RateTransition >= -2.147483648E+9) {
            f = (int32_T)rtb_RateTransition;
          } else {
            f = MIN_int32_T;
          }
        } else {
          f = MAX_int32_T;
        }

        if (f > Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2) {
          f = -1;
          caso = 0;
        } else {
          f -= 2;
          caso = Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2;
        }

        Copy_3_of_provaLOG_09_28_BUO_DW.mess_len = (int8_T)((caso - f) - 1);
        if (rtb_RateTransition < 2.147483648E+9) {
          if (rtb_RateTransition >= -2.147483648E+9) {
            f = (int32_T)rtb_RateTransition;
          } else {
            f = MIN_int32_T;
          }
        } else {
          f = MAX_int32_T;
        }

        if (f > Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2) {
          g = 0;
          f = 0;
        } else {
          g = f - 1;
          f = Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2;
        }

        caso = f - g;
        for (f = 0; f < caso; f++) {
          Copy_3_of_provaLOG_09_28_BUO_DW.message[f] =
            Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[g + f];
        }

        f = (int32_T)(qY + 8U);
        if (qY + 8U > 255U) {
          f = 255;
        }

        rtb_RateTransition = rt_roundd_snf((real_T)f -
          Copy_3_of_provaLOG_09_28_BUO_DW.mess_len);
        if (rtb_RateTransition < 256.0) {
          if (rtb_RateTransition >= 0.0) {
            Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = (uint8_T)
              rtb_RateTransition;
          } else {
            Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
          }
        } else {
          Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = MAX_uint8_T;
        }

        Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = true;
      }
    } else {
      Copy_3_of_provaLOG_09_28_BUO_DW.Interr_parz = false;
      memset(&Copy_3_of_provaLOG_09_28_BUO_DW.message[0], 0, 100U * sizeof
             (uint8_T));
      Copy_3_of_provaLOG_09_28_BUO_DW.counter_m = 0U;
      Copy_3_of_provaLOG_09_28_BUO_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&Copy_3_of_provaLOG_09_28_BUON_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (f = 0; f < 100; f++) {
    Copy_3_of_provaLOG_09_28_BUON_B.buffer[3 * f] = 0U;
  }

  for (f = 0; f < 100; f++) {
    for (caso = 0; caso < 2; caso++) {
      g = 3 * f + caso;
      Copy_3_of_provaLOG_09_28_BUON_B.buffer[g + 1] =
        Copy_3_of_provaLOG_09_28_BUO_DW.Memory4_PreviousInput[g];
    }
  }

  caso = 3;
  exitg1 = false;
  while ((!exitg1) && (caso >= 1)) {
    for (f = 0; f < 100; f++) {
      Copy_3_of_provaLOG_09_28_BUON_B.x[f] =
        (Copy_3_of_provaLOG_09_28_BUON_B.buffer[(3 * f + caso) - 1] == 0);
    }

    y = true;
    f = 0;
    exitg2 = false;
    while ((!exitg2) && (f < 100)) {
      if (!Copy_3_of_provaLOG_09_28_BUON_B.x[f]) {
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
      Copy_3_of_provaLOG_09_28_BUON_B.buffer[(counter + 3 * f) - 1] =
        Copy_3_of_provaLOG_09_28_BUON_B.messaggio[f];
    }
  } else if (status == 2) {
    qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      qY = 0U;
    }

    for (f = 0; f < 100; f++) {
      Copy_3_of_provaLOG_09_28_BUON_B.buffer[(counter + 3 * f) - 1] =
        Copy_3_of_provaLOG_09_28_BUON_B.messaggio[f];
      Copy_3_of_provaLOG_09_28_BUON_B.buffer[((int32_T)qY + 3 * f) - 1] =
        Copy_3_of_provaLOG_09_28_BUON_B.messaggio_2[f];
    }
  } else {
    for (f = 0; f < 100; f++) {
      Copy_3_of_provaLOG_09_28_BUON_B.buffer[(counter + 3 * f) - 1] = 0U;
    }
  }

  for (f = 0; f < 100; f++) {
    Copy_3_of_provaLOG_09_28_BUON_B.mess_out[f] =
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory4_PreviousInput[3 * f + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.Add =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory4_PreviousInput[5] +
    Copy_3_of_provaLOG_09_28_BUON_P.Constant_Value_i;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_B.mess_out[2] !=
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory5_PreviousInput[2]) {
    for (f = 0; f < 100; f++) {
      Copy_3_of_provaLOG_09_28_BUON_B.x[f] =
        (Copy_3_of_provaLOG_09_28_BUON_B.mess_out[f] != 0);
    }

    y = true;
    f = 0;
    exitg1 = false;
    while ((!exitg1) && (f < 100)) {
      if (!Copy_3_of_provaLOG_09_28_BUON_B.x[f]) {
        y = false;
        exitg1 = true;
      } else {
        f++;
      }
    }

    if (!y) {
      if (Copy_3_of_provaLOG_09_28_BUO_DW.counter > 100) {
        Copy_3_of_provaLOG_09_28_BUO_DW.counter = 0U;
      }

      qY = Copy_3_of_provaLOG_09_28_BUO_DW.counter + 1U;
      if (Copy_3_of_provaLOG_09_28_BUO_DW.counter + 1U > 65535U) {
        qY = 65535U;
      }

      Copy_3_of_provaLOG_09_28_BUO_DW.counter = (uint16_T)qY;
    }
  }

  Copy_3_of_provaLOG_09_28_BUON_B.new_mex =
    Copy_3_of_provaLOG_09_28_BUO_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  Copy_3_of_provaLOG_09_28_BUON_B.Memory1[0] =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0];
  Copy_3_of_provaLOG_09_28_BUON_B.Memory1[1] =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1];

  /* Memory: '<Root>/Memory' */
  Copy_3_of_provaLOG_09_28_BUON_B.Memory_p[0] =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[0];
  Copy_3_of_provaLOG_09_28_BUON_B.Memory_p[1] =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[1];
  Copy_3_of_provaLOG_09_28_BUON_B.Memory_p[2] =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[2];
  Copy_3_of_provaLOG_09_28_BUON_B.Memory_p[3] =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[3];

  /* Memory: '<S1>/Memory3' */
  Copy_3_of_provaLOG_09_28_BUON_B.Memory3 =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput;
  for (caso = 0; caso < 8; caso++) {
    /* Memory: '<S1>/Memory' */
    Copy_3_of_provaLOG_09_28_BUON_B.Memory[caso] =
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_g[caso];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&Copy_3_of_provaLOG_09_28_BUON_B.mess_out[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.Add,
     &Copy_3_of_provaLOG_09_28_BUON_B.new_mex,
     &Copy_3_of_provaLOG_09_28_BUON_P.SIUAVuint8_Value,
     &Copy_3_of_provaLOG_09_28_BUON_B.Memory[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.Memory1[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.Memory_p[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.Memory3,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o1[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o2,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o3_m,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o4_n[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o5[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o6,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o7[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o8,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o9[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o10[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o12,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o13,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o14,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o15,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o16,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o17, 100);

  /* Memory: '<S1>/Memory2' */
  for (caso = 0; caso < 9; caso++) {
    Copy_3_of_provaLOG_09_28_BUON_B.Memory2[caso] =
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput_c[caso];
  }

  /* End of Memory: '<S1>/Memory2' */

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (caso = 0; caso < 6; caso++) {
    Copy_3_of_provaLOG_09_28_BUON_B.WP_info_in[caso] =
      Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o9[caso];
  }

  if ((!Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbP_not_empty) ||
      ((Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o7[0] == 3) &&
       (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o7[1] == 250))) {
    memset(&Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbP_not_empty = true;
    memset(&Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbP_AL_not_empty) ||
      ((Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o7[0] == 3) &&
       (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o7[1] == 250))) {
    memset(&Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbP_AL[0], 0, 42U * sizeof
           (real32_T));
    Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbP_AL_not_empty = true;
  }

  Copy_3_of_provaLOG_09_28_BUON_B.GC_info[0] =
    Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o7[0];
  Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] =
    Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o7[1];
  Copy_3_of_provaLOG_09_28_BUON_B.GC_info[2] =
    Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[0];
  if (Copy_3_of_provaLOG_09_28_BUON_B.GC_info[0] == 1) {
    if ((Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] > 0) &&
        (Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] <= 7)) {
      if ((real32_T)fabs(Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o8) > 0.0F) {
        Copy_3_of_provaLOG_09_28_BUO_DW.riferimenti[Copy_3_of_provaLOG_09_28_BUON_B.GC_info
          [1] - 1] = 1.0F;
      } else {
        if (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o8 == 0.0F) {
          Copy_3_of_provaLOG_09_28_BUO_DW.riferimenti[Copy_3_of_provaLOG_09_28_BUON_B.GC_info
            [1] - 1] = 0.0F;
        }
      }
    } else {
      if ((Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] > 7) &&
          (Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] < 12)) {
        Copy_3_of_provaLOG_09_28_BUO_DW.riferimenti[Copy_3_of_provaLOG_09_28_BUON_B.GC_info
          [1] - 1] = Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o8;
      }
    }
  }

  if (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o12 == 13) {
    Copy_3_of_provaLOG_09_28_BUO_DW.riferimenti[Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o12
      - 1] = Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o13;
  }

  memcpy(&Copy_3_of_provaLOG_09_28_BUON_B.Val_out_MAV[0],
         &Copy_3_of_provaLOG_09_28_BUO_DW.riferimenti[0], sizeof(real32_T) << 4U);
  if ((Copy_3_of_provaLOG_09_28_BUON_B.GC_info[0] == 3) &&
      (Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] == 200)) {
    if (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o9[0] > 6) {
      Copy_3_of_provaLOG_09_28_BUON_B.WP_info_in[0] = 6U;
    }

    for (f = 0; f < 6; f++) {
      Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbI[f] =
        Copy_3_of_provaLOG_09_28_BUON_B.WP_info_in[0];
    }
  }

  if ((Copy_3_of_provaLOG_09_28_BUON_B.GC_info[0] == 3) &&
      (Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] < 200)) {
    if (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o10[1] == 0.0F) {
      qY = Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o9[1] + 1U;
      if (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (f = 0; f < 7; f++) {
        Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbP[((int32_T)qY + 6 * f) - 1] =
          Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o10[f];
      }

      qY = Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o9[1] + 1U;
      if (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (f = 0; f < 6; f++) {
        Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbI[((int32_T)qY + 6 * (f + 1)) - 1] =
          Copy_3_of_provaLOG_09_28_BUON_B.WP_info_in[f + 1];
      }
    } else {
      f = (int32_T)(Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o10[0] + 1.0F);
      for (g = 0; g < 7; g++) {
        Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbP_AL[(f + 6 * g) - 1] =
          Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o10[g];
      }

      qY = Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o9[1] + 1U;
      if (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (f = 0; f < 6; f++) {
        Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbI[((int32_T)qY + 6 * (f + 1)) - 1] =
          Copy_3_of_provaLOG_09_28_BUON_B.WP_info_in[f + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  if ((Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o6 == 0) &&
      (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o3_m == 0)) {
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 0U;
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput = 0U;
  } else if ((Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o6 == 0) &&
             (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o3_m == 3)) {
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 0U;
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput = 0U;
    Copy_3_of_provaLOG_09_28_BUO_DW.test1 = 0.0;
  } else if ((Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o6 == 0) &&
             (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o3_m == 2)) {
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 0U;
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput = 0U;
    Copy_3_of_provaLOG_09_28_BUO_DW.test1 = 0.0;
  } else if ((Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o6 == 0) &&
             (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o3_m == 1)) {
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 0U;
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput = 0U;
    Copy_3_of_provaLOG_09_28_BUO_DW.test1 = 1.0;
  } else {
    switch (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o6) {
     case 192:
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 192U;
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 208U;
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o6 == 220) &&
          (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o3_m != 5)) {
        if ((Copy_3_of_provaLOG_09_28_BUON_B.Memory2[0] == 0) &&
            (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[1] == 0) &&
            ((Copy_3_of_provaLOG_09_28_BUON_B.Memory2[2] == 1) ||
             (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[3] == 1) ||
             (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[4] == 1) ||
             (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[5] == 1) ||
             (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[6] == 1) ||
             (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[7] == 1))) {
          Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 220U;
          Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput = 220U;
        } else if ((Copy_3_of_provaLOG_09_28_BUON_B.Memory2[0] == 0) &&
                   (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[1] == 1) &&
                   ((Copy_3_of_provaLOG_09_28_BUON_B.Memory2[2] == 1) ||
                    (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[3] == 1) ||
                    (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[4] == 1) ||
                    (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[5] == 1) ||
                    (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[6] == 1) ||
                    (Copy_3_of_provaLOG_09_28_BUON_B.Memory2[7] == 1))) {
          Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 220U;
          Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput = 220U;
        } else {
          Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 208U;
          Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput = 208U;
        }
      } else if (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o3_m == 5) {
        Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 220U;
        Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] = 192U;
        Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  qY = 100U * Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[5];
  if (qY > 65535U) {
    qY = 65535U;
  }

  if (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[4] == 0) {
    if ((uint16_T)qY == 0) {
      z = 0U;
    } else {
      z = MAX_uint16_T;
    }
  } else {
    z = (uint16_T)(Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[4] == 0U ?
                   MAX_uint32_T : (uint32_T)(uint16_T)qY /
                   Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[4]);
    x_0 = (uint16_T)((uint32_T)(uint16_T)qY - (uint16_T)((uint32_T)z *
      Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[4]));
    if ((x_0 > 0) && (x_0 >= (int32_T)((uint32_T)
          Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[4] >> 1) +
                      (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[4] & 1))) {
      z++;
    }
  }

  /* RateTransition: '<S21>/Rate Transition' */
  rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUO_DW.RateTransition_Buffer0;

  /* Sum: '<S21>/Add1' incorporates:
   *  Constant: '<S21>/Constant2'
   *  Constant: '<S21>/Constant3'
   *  Memory: '<S21>/Memory1'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.num_254 =
    (Copy_3_of_provaLOG_09_28_BUON_P.Constant2_Value_j +
     Copy_3_of_provaLOG_09_28_BUON_P.Constant3_Value_k) +
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput;

  /* Switch: '<S21>/Switch' */
  if (Copy_3_of_provaLOG_09_28_BUON_B.num_254 >
      Copy_3_of_provaLOG_09_28_BUON_P.Switch_Threshold) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S21>/Constant2'
     */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput =
      Copy_3_of_provaLOG_09_28_BUON_P.Constant2_Value_j;
  } else {
    /* Switch: '<S21>/Switch' */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput =
      Copy_3_of_provaLOG_09_28_BUON_B.num_254;
  }

  /* End of Switch: '<S21>/Switch' */

  /* MATLAB Function: '<S11>/iflogic_function' */
  if ((Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 1.0) ||
      (Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 3.0)) {
    Copy_3_of_provaLOG_09_28_BUON_B.iflogic = 26U;
  } else if ((Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 2.0) ||
             (Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 4.0)) {
    Copy_3_of_provaLOG_09_28_BUON_B.iflogic = 30U;
  } else if ((Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 2.0)) {
    Copy_3_of_provaLOG_09_28_BUON_B.iflogic = 33U;
  } else if ((Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 6.0)) {
    Copy_3_of_provaLOG_09_28_BUON_B.iflogic = 34U;
  } else if ((Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 0.0)) {
    Copy_3_of_provaLOG_09_28_BUON_B.iflogic = 0U;
  } else if ((Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 0.0) &&
             ((rtb_RateTransition == 1.0) || (rtb_RateTransition == 5.0) ||
              (rtb_RateTransition == 9.0))) {
    Copy_3_of_provaLOG_09_28_BUON_B.iflogic = 1U;
  } else if ((Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 0.0) &&
             ((rtb_RateTransition == 3.0) || (rtb_RateTransition == 8.0))) {
    Copy_3_of_provaLOG_09_28_BUON_B.iflogic = 74U;
  } else if ((Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 7.0)) {
    Copy_3_of_provaLOG_09_28_BUON_B.iflogic = 36U;
  } else if ((Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 4.0)) {
    Copy_3_of_provaLOG_09_28_BUON_B.iflogic = 29U;
  } else {
    Copy_3_of_provaLOG_09_28_BUON_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S11>/iflogic_function' */

  /* Sum: '<S21>/Add' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/Constant1'
   *  Memory: '<S21>/Memory'
   */
  Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput +=
    Copy_3_of_provaLOG_09_28_BUON_P.Constant_Value_m +
    Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_l;

  /* Gain: '<S11>/Gain' */
  rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain *
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput;

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
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3 = rtb_RateTransition < 0.0
    ? (uint32_T)-(int32_T)(uint32_T)-rtb_RateTransition : (uint32_T)
    rtb_RateTransition;

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (f = 0; f < 6; f++) {
    Copy_3_of_provaLOG_09_28_BUON_B.WP_info[f] =
      Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbI[6 * f];
  }

  for (f = 0; f < 7; f++) {
    Copy_3_of_provaLOG_09_28_BUON_B.WP_param[f] =
      Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbP[6 * f];
  }

  if ((Copy_3_of_provaLOG_09_28_BUON_B.GC_info[0] == 2) &&
      (Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] < 6)) {
    qY = Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] + 1U;
    if (Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (f = 0; f < 6; f++) {
      Copy_3_of_provaLOG_09_28_BUON_B.WP_info[f] =
        Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbI[(6 * f + (int32_T)qY) - 1];
    }

    qY = Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] + 1U;
    if (Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (f = 0; f < 7; f++) {
      Copy_3_of_provaLOG_09_28_BUON_B.WP_param[f] =
        Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbP[(6 * f + (int32_T)qY) - 1];
    }
  }

  if ((Copy_3_of_provaLOG_09_28_BUON_B.GC_info[0] == 3) &&
      (Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] < 200)) {
    qY = Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] + 1U;
    if (Copy_3_of_provaLOG_09_28_BUON_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (f = 0; f < 6; f++) {
      Copy_3_of_provaLOG_09_28_BUON_B.WP_info[f] =
        Copy_3_of_provaLOG_09_28_BUO_DW.WP_dbI[(6 * f + (int32_T)qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S15>/MATLAB Function' */

  /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
   *  Constant: '<S13>/onboard_control_sensor_present uint32'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.onboard[0] =
    Copy_3_of_provaLOG_09_28_BUON_P.onboard_control_sensor_presentu[0];
  Copy_3_of_provaLOG_09_28_BUON_B.onboard[1] =
    Copy_3_of_provaLOG_09_28_BUON_P.onboard_control_sensor_presentu[1];
  Copy_3_of_provaLOG_09_28_BUON_B.onboard[2] =
    Copy_3_of_provaLOG_09_28_BUON_P.onboard_control_sensor_presentu[2];

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain_f *
    Copy_3_of_provaLOG_09_28_BUON_P.Constant_Value_e);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  Constant: '<S13>/load uint16'
   *  Gain: '<S13>/Gain'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.LVDE[0] =
    Copy_3_of_provaLOG_09_28_BUON_P.loaduint16_Value;
  Copy_3_of_provaLOG_09_28_BUON_B.LVDE[1] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  qY = 10U * z;
  if (qY > 65535U) {
    qY = 65535U;
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  Constant: '<S13>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.LVDE[2] = (uint16_T)qY;
  Copy_3_of_provaLOG_09_28_BUON_B.LVDE[3] =
    Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[6];
  Copy_3_of_provaLOG_09_28_BUON_B.LVDE[4] =
    Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[2];
  Copy_3_of_provaLOG_09_28_BUON_B.LVDE[5] =
    Copy_3_of_provaLOG_09_28_BUON_P._Value;

  /* DataTypeConversion: '<S13>/Data Type Conversion4' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_k[0]);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion4'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.LVDE[6] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S13>/Data Type Conversion4' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_k[1]);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion4'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.LVDE[7] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* Gain: '<S13>/Gain2' incorporates:
   *  Constant: '<S13>/Constant3'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Gain2_Gain *
    Copy_3_of_provaLOG_09_28_BUON_P.Constant3_Value_g);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Gain: '<S13>/Gain1'
   *  Gain: '<S13>/Gain2'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.B_Current = (int16_T)(((rtb_RateTransition <
    0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition) *
    Copy_3_of_provaLOG_09_28_BUON_P.Gain1_Gain_f) >> 18);

  /* DataTypeConversion: '<S13>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant2_Value_g);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.B_Remaining = (int8_T)(rtb_RateTransition <
    0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-rtb_RateTransition : (int32_T)
    (int8_T)(uint8_T)rtb_RateTransition);

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Constant: '<S9>/Constant'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant_Value_n);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion = rtb_RateTransition < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-rtb_RateTransition : (uint32_T)
    rtb_RateTransition;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
   *  MATLAB Function: '<S9>/Alarm set'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[2] =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0];
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[3] =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1];

  /* MATLAB Function: '<S9>/Alarm set' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_g[0] == 1.0) {
    /* DataTypeConversion: '<S9>/Data Type Conversion1' */
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[2] = 220U;
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[3] = 5U;
  }

  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_g[1] == 1.0) {
    /* DataTypeConversion: '<S9>/Data Type Conversion1' */
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[2] = 216U;
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[3] = 4U;
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
   *  Constant: '<S9>/Type fixed_wing Autopilot generic'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[0] =
    Copy_3_of_provaLOG_09_28_BUON_P.Typefixed_wingAutopilotgeneric_[0];
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[1] =
    Copy_3_of_provaLOG_09_28_BUON_P.Typefixed_wingAutopilotgeneric_[1];

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant6'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant6_Value < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_P.Constant6_Value);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant6_Value);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[0] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant7'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant7_Value < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_P.Constant7_Value);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant7_Value);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[1] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant8'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant8_Value < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_P.Constant8_Value);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant8_Value);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[2] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant9'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant9_Value < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_P.Constant9_Value);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant9_Value);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[3] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant10'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant10_Value < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_P.Constant10_Value);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant10_Value);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[4] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant11'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant11_Value < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_P.Constant11_Value);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant11_Value);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[5] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value[0] < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value[0]);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value[0]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[6] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value[1] < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value[1]);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value[1]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[7] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value[2] < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value[2]);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value[2]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[8] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion4' incorporates:
   *  Constant: '<S10>/Constant10'
   *  Constant: '<S10>/Constant11'
   *  Constant: '<S10>/Constant12'
   *  Constant: '<S10>/Constant13'
   *  Constant: '<S10>/Constant14'
   *  Constant: '<S10>/Constant9'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4[0] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant12_Value;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4[1] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant13_Value;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4[2] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant14_Value;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4[3] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant9_Value;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4[4] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant10_Value;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4[5] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant11_Value;

  /* Sum: '<S18>/Sum' incorporates:
   *  Constant: '<S18>/Constant3'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.quota =
    Copy_3_of_provaLOG_09_28_BUON_P.Constant3_Value_b -
    Copy_3_of_provaLOG_09_28_BUON_B.Switch;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain_i[0] *
    Copy_3_of_provaLOG_09_28_BUON_P.Constant2_Value_e;

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
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion_j[0] = rtb_RateTransition <
    0.0 ? -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain_i[1] *
    Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_d;

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
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion_j[1] = rtb_RateTransition <
    0.0 ? -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S8>/Gain' */
  rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain_i[2] *
    Copy_3_of_provaLOG_09_28_BUON_B.quota;

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
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion_j[2] = rtb_RateTransition <
    0.0 ? -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/alt_r'
   */
  rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain_i[3] *
    Copy_3_of_provaLOG_09_28_BUON_P.alt_r_Value;

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
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion_j[3] = rtb_RateTransition <
    0.0 ? -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S18>/Constant'
   */
  rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUON_P.Gain1_Gain *
    Copy_3_of_provaLOG_09_28_BUON_P.Constant_Value_mi;

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
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_k[0] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/vel y'
   */
  rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUON_P.Gain1_Gain *
    Copy_3_of_provaLOG_09_28_BUON_P.vely_Value;

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
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_k[1] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/RC Simulated'
   */
  rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUON_P.Gain1_Gain *
    Copy_3_of_provaLOG_09_28_BUON_P.RCSimulated_Value;

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
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_k[2] = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* Gain: '<S8>/Gain2' incorporates:
   *  Constant: '<S18>/Constant4'
   */
  rtb_RateTransition = Copy_3_of_provaLOG_09_28_BUON_P.Gain2_Gain_o *
    Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value_g;

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
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion2 = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S14>/RC simulated'
   *  Constant: '<S14>/TAS simulated'
   *  Constant: '<S14>/v simulated'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_a[0] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.TASsimulated_Value;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_a[1] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.vsimulated_Value;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_a[2] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant6_Value_j;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_a[3] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.RCsimulated_Value;

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  Constant: '<S14>/ Heading simulated'
   */
  rtb_RateTransition = floor
    (Copy_3_of_provaLOG_09_28_BUON_P.Headingsimulated_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion4' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4_o = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S14>/Data Type Conversion5' incorporates:
   *  Constant: '<S14>/Rpm simulated'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Rpmsimulated_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion5' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion5 = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* Gain: '<S23>/Gain2' incorporates:
   *  Constant: '<S12>/Manetta Simulated'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.Gain2 =
    Copy_3_of_provaLOG_09_28_BUON_P.Gain2_Gain_f *
    Copy_3_of_provaLOG_09_28_BUON_P.ManettaSimulated_Value;

  /* Sum: '<S23>/Sum' incorporates:
   *  Constant: '<S12>/Equilibratore Simulated'
   *  Constant: '<S23>/Constant2'
   *  Gain: '<S24>/Gain'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.Sum =
    Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain_d *
    Copy_3_of_provaLOG_09_28_BUON_P.EquilibratoreSimulated_Value +
    Copy_3_of_provaLOG_09_28_BUON_P.Constant2_Value_l;

  /* Sum: '<S23>/Sum1' incorporates:
   *  Constant: '<S12>/Alettoni Simulated'
   *  Constant: '<S23>/Constant2'
   *  Gain: '<S25>/Gain'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.num_254 =
    Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain_n *
    Copy_3_of_provaLOG_09_28_BUON_P.AlettoniSimulated_Value +
    Copy_3_of_provaLOG_09_28_BUON_P.Constant2_Value_l;

  /* Sum: '<S23>/Sum2' incorporates:
   *  Constant: '<S12>/Timone Simulated'
   *  Constant: '<S23>/Constant2'
   *  Gain: '<S26>/Gain'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.Gain3 =
    Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain_p *
    Copy_3_of_provaLOG_09_28_BUON_P.TimoneSimulated_Value +
    Copy_3_of_provaLOG_09_28_BUON_P.Constant2_Value_l;

  /* Gain: '<S12>/Gain' incorporates:
   *  Constant: '<S12>/Constant2'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.PatohPa =
    Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain_g *
    Copy_3_of_provaLOG_09_28_BUON_P.Constant2_Value_i;

  /* Saturate: '<S12>/Saturation' */
  if (Copy_3_of_provaLOG_09_28_BUON_B.PatohPa >
      Copy_3_of_provaLOG_09_28_BUON_P.Saturation_UpperSat) {
    Copy_3_of_provaLOG_09_28_BUON_B.PatohPa =
      Copy_3_of_provaLOG_09_28_BUON_P.Saturation_UpperSat;
  } else {
    if (Copy_3_of_provaLOG_09_28_BUON_B.PatohPa <
        Copy_3_of_provaLOG_09_28_BUON_P.Saturation_LowerSat) {
      Copy_3_of_provaLOG_09_28_BUON_B.PatohPa =
        Copy_3_of_provaLOG_09_28_BUON_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant_Value_c < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_P.Constant_Value_c);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant_Value_c);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  Copy_3_of_provaLOG_09_28_BUON_B.Heading[0] = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (Copy_3_of_provaLOG_09_28_BUON_B.Gain2 < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_B.Gain2);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_B.Gain2);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  Copy_3_of_provaLOG_09_28_BUON_B.Heading[1] = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (Copy_3_of_provaLOG_09_28_BUON_B.Sum < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_B.Sum);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_B.Sum);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  Copy_3_of_provaLOG_09_28_BUON_B.Heading[2] = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (Copy_3_of_provaLOG_09_28_BUON_B.num_254 < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_B.num_254);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_B.num_254);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  Copy_3_of_provaLOG_09_28_BUON_B.Heading[3] = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (Copy_3_of_provaLOG_09_28_BUON_B.Gain3 < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_B.Gain3);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_B.Gain3);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  Copy_3_of_provaLOG_09_28_BUON_B.Heading[4] = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_gk[0] < 0.0) {
    rtb_RateTransition = ceil
      (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_gk[0]);
  } else {
    rtb_RateTransition = floor
      (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_gk[0]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  Copy_3_of_provaLOG_09_28_BUON_B.Heading[5] = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_gk[1] < 0.0) {
    rtb_RateTransition = ceil
      (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_gk[1]);
  } else {
    rtb_RateTransition = floor
      (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_gk[1]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  Copy_3_of_provaLOG_09_28_BUON_B.Heading[6] = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_gk[2] < 0.0) {
    rtb_RateTransition = ceil
      (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_gk[2]);
  } else {
    rtb_RateTransition = floor
      (Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_gk[2]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  Copy_3_of_provaLOG_09_28_BUON_B.Heading[7] = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  if (Copy_3_of_provaLOG_09_28_BUON_B.PatohPa < 0.0) {
    rtb_RateTransition = ceil(Copy_3_of_provaLOG_09_28_BUON_B.PatohPa);
  } else {
    rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_B.PatohPa);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  Copy_3_of_provaLOG_09_28_BUON_B.Heading[8] = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* Memory: '<S2>/Memory' */
  Copy_3_of_provaLOG_09_28_BUON_B.Memory_e =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_n;

  /* DataTypeConversion: '<S2>/Data Type Conversion17' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion17 = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant7_Value_f;

  /* DataTypeConversion: '<S2>/Data Type Conversion4' incorporates:
   *  Constant: '<Root>/Constant10'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4_g = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant10_Value_g;

  /* Gain: '<S2>/Pa to hPa' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.PatohPa =
    Copy_3_of_provaLOG_09_28_BUON_P.PatohPa_Gain *
    Copy_3_of_provaLOG_09_28_BUON_P.Constant8_Value_a;

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion_a = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_B.PatohPa;

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1 = (real32_T)
    (Copy_3_of_provaLOG_09_28_BUON_P.PatohPa1_Gain *
     Copy_3_of_provaLOG_09_28_BUON_P.Constant2_Value_a);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant9_Value_k);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion2_c = (int16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(int16_T)(uint16_T)rtb_RateTransition);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper
    (&Copy_3_of_provaLOG_09_28_BUON_B.iflogic,
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3,
     &Copy_3_of_provaLOG_09_28_BUON_P.SIUAVuint8_Value,
     &Copy_3_of_provaLOG_09_28_BUON_B.GC_info[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.Val_out_MAV[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.WP_info[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.WP_param[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.onboard[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.LVDE[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.B_Current,
     &Copy_3_of_provaLOG_09_28_BUON_B.B_Remaining,
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion,
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion_j[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_k[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion2,
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_a[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4_o,
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion5,
     &Copy_3_of_provaLOG_09_28_BUON_B.Heading[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.Memory_e,
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion17,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o14,
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4_g,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o15,
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion_a,
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1,
     &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion2_c,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o5[0],
     &Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value_j,
     &Copy_3_of_provaLOG_09_28_BUON_P.Constant5_Value_f,
     &Copy_3_of_provaLOG_09_28_BUON_P.Constant10_Value_p, ((const uint16_T*)
      &Copy_3_of_provaLOG_09_28_BUONO_U16GND),
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o1_m,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o2_n[0],
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o3,
     &Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o1_m > 0) {
    /* Chart: '<S7>/Chart' */
    if (Copy_3_of_provaLOG_09_28_BUO_DW.is_active_c9_Copy_3_of_provaLOG == 0U) {
      Copy_3_of_provaLOG_09_28_BUO_DW.is_active_c9_Copy_3_of_provaLOG = 1U;
      Copy_3_of_provaLOG_09_28_BUO_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.Protocol !=
            Copy_3_of_provaLOG_09_28_BUON_P.SerialTransmit_Protocol) {
          Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.Protocol =
            Copy_3_of_provaLOG_09_28_BUON_P.SerialTransmit_Protocol;
        }

        counter =
          Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o2_n[Copy_3_of_provaLOG_09_28_BUO_DW.i
          - 1];
        MW_Serial_write(Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.port, &counter,
                        1.0,
                        Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.dataSizeInBytes,
                        Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.sendModeEnum,
                        Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.dataType,
                        Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.sendFormatEnum,
                        2.0, '\x00');
        if (Copy_3_of_provaLOG_09_28_BUO_DW.i <
            Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o3) {
          f = Copy_3_of_provaLOG_09_28_BUO_DW.i + 1;
          if (Copy_3_of_provaLOG_09_28_BUO_DW.i + 1 > 255) {
            f = 255;
          }

          Copy_3_of_provaLOG_09_28_BUO_DW.i = (uint8_T)f;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      Copy_3_of_provaLOG_09_28_BUO_DW.i = 1U;
    }

    /* End of Chart: '<S7>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* DataTypeConversion: '<S2>/Data Type Conversion6' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S18>/Constant1'
   *  Constant: '<S18>/Constant2'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion6[0] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant2_Value_e;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion6[1] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_d;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion6[2] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_B.quota;
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion6[3] = (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_P.Constant6_Value_j;

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  tmp = (real32_T)floor(Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4[0]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* Gain: '<S2>/Gain' */
  tmp_0 = (real32_T)Copy_3_of_provaLOG_09_28_BUON_P.Gain_Gain_e * 0.00390625F;

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion9'
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)fmod((real32_T)floor(tmp_0 * (real32_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp)),
                       65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_p[0] = (int16_T)(tmp <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)
    (uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  tmp = (real32_T)floor(Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4[1]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion9'
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)fmod((real32_T)floor(tmp_0 * (real32_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp)),
                       65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_p[1] = (int16_T)(tmp <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)
    (uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  tmp = (real32_T)floor(Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion4[2]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion9'
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)fmod((real32_T)floor(tmp_0 * (real32_T)(tmp < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp)),
                       65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_p[2] = (int16_T)(tmp <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)
    (uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  tmp = (real32_T)fmod((real32_T)floor(tmp_0 * (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[3]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_p[3] = (int16_T)(tmp <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)
    (uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  tmp = (real32_T)fmod((real32_T)floor(tmp_0 * (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[4]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_p[4] = (int16_T)(tmp <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)
    (uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  tmp = (real32_T)fmod((real32_T)floor(tmp_0 * (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[5]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_p[5] = (int16_T)(tmp <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)
    (uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  tmp = (real32_T)fmod((real32_T)floor(tmp_0 * (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[0]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_p[6] = (int16_T)(tmp <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)
    (uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  tmp = (real32_T)fmod((real32_T)floor(tmp_0 * (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[1]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_p[7] = (int16_T)(tmp <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)
    (uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   *  SignalConversion generated from: '<S2>/Gain'
   */
  tmp = (real32_T)fmod((real32_T)floor(tmp_0 * (real32_T)
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_m[2]), 65536.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_p[8] = (int16_T)(tmp <
    0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)
    (uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion10' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion10 =
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion2;

  /* DataTypeConversion: '<S2>/Data Type Conversion11' incorporates:
   *  Gain: '<S2>/Gain2'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion11[0] = (uint16_T)
    ((Copy_3_of_provaLOG_09_28_BUON_P.Gain2_Gain_n *
      Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_k[0]) >> 8);
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion11[1] = (uint16_T)
    ((Copy_3_of_provaLOG_09_28_BUON_P.Gain2_Gain_n *
      Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_k[1]) >> 8);
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion11[2] = (uint16_T)
    ((Copy_3_of_provaLOG_09_28_BUON_P.Gain2_Gain_n *
      Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_k[2]) >> 8);

  /* DataTypeConversion: '<S2>/Data Type Conversion12' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant_Value_ez);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion12' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion12 = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion13' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant3_Value_o);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion13' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion13 = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion14' incorporates:
   *  Constant: '<S2>/Constant7'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant7_Value_m);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion14' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion14 = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion15' incorporates:
   *  Constant: '<S2>/Constant8'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant8_Value_g);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion15' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion15 = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion21' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant9_Value_j);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion21' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion21 = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion20' incorporates:
   *  Constant: '<S2>/Constant6'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant6_Value_l);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion20' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion20 = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion19' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_b);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion19' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion19 = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion18' incorporates:
   *  Constant: '<Root>/Constant9'
   *  Gain: '<S2>/Gain3'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Gain3_Gain *
    Copy_3_of_provaLOG_09_28_BUON_P.Constant9_Value_k);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion18' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion18 = (uint16_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -rtb_RateTransition : (int32_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion7' incorporates:
   *  Constant: '<S18>/Constant5'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant5_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion7'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion8[0] = (uint8_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)
     -rtb_RateTransition : (int32_T)(uint8_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion5' incorporates:
   *  Constant: '<S18>/Constant6'
   */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_P.Constant6_Value_g);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion5'
   */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion8[1] = (uint8_T)
    (rtb_RateTransition < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)
     -rtb_RateTransition : (int32_T)(uint8_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion16' */
  rtb_RateTransition = floor(Copy_3_of_provaLOG_09_28_BUON_B.PatohPa);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion16' */
  Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion16 = rtb_RateTransition <
    0.0 ? (uint32_T)-(int32_T)(uint32_T)-rtb_RateTransition : (uint32_T)
    rtb_RateTransition;

  /* S-Function (any2byte_svd): '<S2>/Byte Pack' incorporates:
   *  Constant: '<S2>/Fine MSG1'
   *  Constant: '<S2>/Inizio MSG'
   */

  /* Pack: <S2>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_P.InizioMSG_Value[0],
             MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion6[0],
             MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion3_p[0],
             MW_inputPortWidth);
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
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion10,
             MW_inputPortWidth);
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
    /* Input data type - uint16_T, size - 3 */
    {
      MW_inputPortWidth = 3 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion11[0],
             MW_inputPortWidth);
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
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion12,
             MW_inputPortWidth);
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
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion13,
             MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 8 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion14,
             MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 9 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion15,
             MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 10 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion21,
             MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 11 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion20,
             MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 12 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion19,
             MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 13 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion18,
             MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 14 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion8[0],
             MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 15 */
    /* Input data type - uint32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint32_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion16,
             MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 16 */
    /* Input data type - uint8_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &Copy_3_of_provaLOG_09_28_BUON_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S2>/Serial Transmit1' */
  if (Copy_3_of_provaLOG_09_28_BUO_DW.obj.Protocol !=
      Copy_3_of_provaLOG_09_28_BUON_P.SerialTransmit1_Protocol) {
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.Protocol =
      Copy_3_of_provaLOG_09_28_BUON_P.SerialTransmit1_Protocol;
  }

  memcpy(&Copy_3_of_provaLOG_09_28_BUON_B.dataIn[0],
         &Copy_3_of_provaLOG_09_28_BUON_B.BytePack[0], 67U * sizeof(uint8_T));
  MW_Serial_write(Copy_3_of_provaLOG_09_28_BUO_DW.obj.port,
                  &Copy_3_of_provaLOG_09_28_BUON_B.dataIn[0], 67.0,
                  Copy_3_of_provaLOG_09_28_BUO_DW.obj.dataSizeInBytes,
                  Copy_3_of_provaLOG_09_28_BUO_DW.obj.sendModeEnum,
                  Copy_3_of_provaLOG_09_28_BUO_DW.obj.dataType,
                  Copy_3_of_provaLOG_09_28_BUO_DW.obj.sendFormatEnum, 2.0,
                  '\x00');

  /* End of MATLABSystem: '<S2>/Serial Transmit1' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&Copy_3_of_provaLOG_09_28_BUO_DW.Memory4_PreviousInput[0],
         &Copy_3_of_provaLOG_09_28_BUON_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&Copy_3_of_provaLOG_09_28_BUON_P.Constant1_Value_i,
    &Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o1[0],
    &Copy_3_of_provaLOG_09_28_BUON_B.SFunctionBuilder_o2,
    &Copy_3_of_provaLOG_09_28_BUO_DW.SFunctionBuilder_DSTATE);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&Copy_3_of_provaLOG_09_28_BUO_DW.Memory5_PreviousInput[0],
         &Copy_3_of_provaLOG_09_28_BUON_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[0] =
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[0];
  Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[1] =
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[1];
  Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[2] =
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[2];
  Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[3] =
    Copy_3_of_provaLOG_09_28_BUON_B.DataTypeConversion1_n[3];

  /* Update for Memory: '<S1>/Memory' */
  for (caso = 0; caso < 8; caso++) {
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_g[caso] =
      Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o11[caso];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput_c[0] = (uint8_T)
    AP_mode_idx_0;
  Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput_c[1] = (uint8_T)
    AP_mode_idx_1;
  for (caso = 0; caso < 7; caso++) {
    tmp = rt_roundf_snf(Copy_3_of_provaLOG_09_28_BUO_DW.riferimenti[caso]);
    if (tmp < 256.0F) {
      if (tmp >= 0.0F) {
        Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput_c[caso + 2] =
          (uint8_T)tmp;
      } else {
        Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput_c[caso + 2] = 0U;
      }
    } else {
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput_c[caso + 2] =
        MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for Memory: '<S2>/Memory' */
  Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_n =
    Copy_3_of_provaLOG_09_28_BUON_B.SFunction_o4;
}

/* Model step function for TID1 */
void Copy_3_of_provaLOG_09_28_BUONO_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S21>/Add2' incorporates:
   *  Constant: '<S21>/Constant4'
   *  Constant: '<S21>/Constant5'
   *  Memory: '<S21>/Memory2'
   */
  Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput +=
    Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value_d +
    Copy_3_of_provaLOG_09_28_BUON_P.Constant5_Value_k;

  /* Switch: '<S21>/Switch1' */
  if (Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput >
      Copy_3_of_provaLOG_09_28_BUON_P.Switch1_Threshold) {
    /* Sum: '<S21>/Add2' incorporates:
     *  Constant: '<S21>/Constant4'
     */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput =
      Copy_3_of_provaLOG_09_28_BUON_P.Constant4_Value_d;
  }

  /* End of Switch: '<S21>/Switch1' */

  /* RateTransition: '<S21>/Rate Transition' */
  Copy_3_of_provaLOG_09_28_BUO_DW.RateTransition_Buffer0 =
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void Copy_3_of_provaLOG_09_28_BUONO_initialize(void)
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

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&Copy_3_of_provaLOG_09_28_BUO_DW.Memory4_PreviousInput[0],
           &Copy_3_of_provaLOG_09_28_BUON_P.Memory4_InitialCondition[0], 300U *
           sizeof(uint8_T));

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Copy_3_of_provaLOG_09_28_BUO_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory5_PreviousInput[i] =
        Copy_3_of_provaLOG_09_28_BUON_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[0] =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory1_InitialCondition_l;
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput_j[1] =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory1_InitialCondition_l;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[0] =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory_InitialCondition_f;
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[1] =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory_InitialCondition_f;
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[2] =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory_InitialCondition_f;
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_m[3] =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory_InitialCondition_f;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory3_PreviousInput =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_g[i] =
        Copy_3_of_provaLOG_09_28_BUON_P.Memory_InitialCondition_o;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput_c[i] =
        Copy_3_of_provaLOG_09_28_BUON_P.Memory2_InitialCondition_j[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S21>/Rate Transition' */
    Copy_3_of_provaLOG_09_28_BUO_DW.RateTransition_Buffer0 =
      Copy_3_of_provaLOG_09_28_BUON_P.RateTransition_InitialCondition;

    /* InitializeConditions for Switch: '<S21>/Switch' incorporates:
     *  Memory: '<S21>/Memory1'
     */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory1_PreviousInput =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S21>/Add' incorporates:
     *  Memory: '<S21>/Memory'
     */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory_PreviousInput_n =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory_InitialCondition_d;

    /* InitializeConditions for Sum: '<S21>/Add2' incorporates:
     *  Memory: '<S21>/Memory2'
     */
    Copy_3_of_provaLOG_09_28_BUO_DW.Memory2_PreviousInput =
      Copy_3_of_provaLOG_09_28_BUON_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&Copy_3_of_provaLOG_09_28_BUO_DW.riferimenti[0], &tmp[0], sizeof
           (real32_T) << 4U);

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S7>/Chart' incorporates:
     *  SubSystem: '<S16>/sendbyte'
     */
    /* Start for MATLABSystem: '<S17>/Serial Transmit' */
    Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.matlabCodegenIsDeleted = false;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.Protocol =
      Copy_3_of_provaLOG_09_28_BUON_P.SerialTransmit_Protocol;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.isInitialized = 1;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.port = 2.0;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.dataSizeInBytes = 1.0;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.dataType = 0.0;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.sendModeEnum = 0.0;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.port);
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
    Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S17>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* SystemInitialize for Enabled SubSystem: '<S18>/Subsystem1' */
    /* SystemInitialize for Switch: '<S19>/Switch' incorporates:
     *  Outport: '<S19>/h_to_subtract'
     */
    Copy_3_of_provaLOG_09_28_BUON_B.Switch =
      Copy_3_of_provaLOG_09_28_BUON_P.h_to_subtract_Y0;

    /* End of SystemInitialize for SubSystem: '<S18>/Subsystem1' */

    /* Start for MATLABSystem: '<S2>/Serial Transmit1' */
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.matlabCodegenIsDeleted = false;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.Protocol =
      Copy_3_of_provaLOG_09_28_BUON_P.SerialTransmit1_Protocol;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.isInitialized = 1;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.port = 0.0;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.dataSizeInBytes = 1.0;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.dataType = 0.0;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.sendModeEnum = 0.0;
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(Copy_3_of_provaLOG_09_28_BUO_DW.obj.port);
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
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/Serial Transmit1' */
  }
}

/* Model terminate function */
void Copy_3_of_provaLOG_09_28_BUONO_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S7>/Chart' incorporates:
   *  SubSystem: '<S16>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S17>/Serial Transmit' */
  if (!Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.matlabCodegenIsDeleted) {
    Copy_3_of_provaLOG_09_28_BUO_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S17>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S2>/Serial Transmit1' */
  if (!Copy_3_of_provaLOG_09_28_BUO_DW.obj.matlabCodegenIsDeleted) {
    Copy_3_of_provaLOG_09_28_BUO_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
