/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: prova_LOG_AHRS_09_23.c
 *
 * Code generated for Simulink model 'prova_LOG_AHRS_09_23'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Sep 23 17:53:09 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "prova_LOG_AHRS_09_23.h"
#include "prova_LOG_AHRS_09_23_private.h"

const uint16_T prova_LOG_AHRS_09_23_U16GND = 0U;/* uint16_T ground */

/* Block signals (default storage) */
B_prova_LOG_AHRS_09_23_T prova_LOG_AHRS_09_23_B;

/* Block states (default storage) */
DW_prova_LOG_AHRS_09_23_T prova_LOG_AHRS_09_23_DW;

/* Real-time model */
static RT_MODEL_prova_LOG_AHRS_09_23_T prova_LOG_AHRS_09_23_M_;
RT_MODEL_prova_LOG_AHRS_09_23_T *const prova_LOG_AHRS_09_23_M =
  &prova_LOG_AHRS_09_23_M_;

/* Forward declaration for local functions */
static void prova_LOG_AHRS_09_23_find_254(const uint8_T pack[100], real_T
  position[3], real_T *counter);
static boolean_T prova_LOG_AHRS_09_2_ifWhileCond(const boolean_T x[100]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void prova_LOG_AHRS_09_23_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(prova_LOG_AHRS_09_23_M, 1));
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
  (prova_LOG_AHRS_09_23_M->Timing.TaskCounters.TID[1])++;
  if ((prova_LOG_AHRS_09_23_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    prova_LOG_AHRS_09_23_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for MATLAB Function: '<S1>/MATLAB Function4' */
static void prova_LOG_AHRS_09_23_find_254(const uint8_T pack[100], real_T
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
static boolean_T prova_LOG_AHRS_09_2_ifWhileCond(const boolean_T x[100])
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
void prova_LOG_AHRS_09_23_step0(void)  /* Sample time: [0.02s, 0.0s] */
{
  real_T rtb_RateTransition;
  real_T rtb_Sum;
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

  /* S-Function (Mti): '<S3>/S-Function Builder' */
  Mti_Outputs_wrapper(&prova_LOG_AHRS_09_23_B.SFunctionBuilder[0],
                      &prova_LOG_AHRS_09_23_DW.SFunctionBuilder_DSTATE);

  /* S-Function (byte2any_svd): '<S3>/Byte Unpack' */

  /* Unpack: <S3>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - uint8_T, size - 4 */
    {
      MW_outputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)&prova_LOG_AHRS_09_23_B.ByteUnpack_o1[0], (uint8_T*)
             &prova_LOG_AHRS_09_23_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&prova_LOG_AHRS_09_23_B.ByteUnpack_o2[0], (uint8_T*)
             &prova_LOG_AHRS_09_23_B.SFunctionBuilder[0] + MW_inputPortOffset,
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
      memcpy((uint8_T*)&prova_LOG_AHRS_09_23_B.ByteUnpack_o3, (uint8_T*)
             &prova_LOG_AHRS_09_23_B.SFunctionBuilder[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }

  /* S-Function (reverseendian_svd): '<S3>/Byte Reversal' */

  /* ReverseEndian: <S3>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const real32_T *u0 = &prova_LOG_AHRS_09_23_B.ByteUnpack_o2[0];
    real32_T *y0 = &prova_LOG_AHRS_09_23_B.ByteReversal[0];
    for (i1=0; i1 < 9; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Seriale_mav_Outputs_wrapper(&prova_LOG_AHRS_09_23_P.Constant1_Value_if,
    &prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[0],
    &prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2,
    &prova_LOG_AHRS_09_23_DW.SFunctionBuilder_DSTATE_n);

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  status = 0;
  caso = 0;
  memset(&prova_LOG_AHRS_09_23_B.messaggio[0], 0, 100U * sizeof(uint8_T));
  memset(&prova_LOG_AHRS_09_23_B.messaggio_2[0], 0, 100U * sizeof(uint8_T));
  prova_LOG_AHRS_09_23_find_254(prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1,
    prova_LOG_AHRS_09_23_B.poss_254, &prova_LOG_AHRS_09_23_B.num_254);
  if (prova_LOG_AHRS_09_23_DW.Interr_parz && (prova_LOG_AHRS_09_23_B.num_254 ==
       1.0)) {
    f = (int32_T)(prova_LOG_AHRS_09_23_DW.counter_o + 1U);
    if (prova_LOG_AHRS_09_23_DW.counter_o + 1U > 255U) {
      f = 255;
    }

    if (prova_LOG_AHRS_09_23_B.poss_254[0] != f) {
      prova_LOG_AHRS_09_23_B.num_254 = 0.0;
    }
  }

  y = !prova_LOG_AHRS_09_23_DW.Interr_parz;
  if ((prova_LOG_AHRS_09_23_B.num_254 == 1.0) && y) {
    caso = 1;
  } else if ((prova_LOG_AHRS_09_23_B.num_254 == 0.0) &&
             prova_LOG_AHRS_09_23_DW.Interr_parz) {
    caso = 2;
  } else if ((prova_LOG_AHRS_09_23_B.num_254 == 1.0) &&
             prova_LOG_AHRS_09_23_DW.Interr_parz) {
    caso = 3;
  } else {
    if ((prova_LOG_AHRS_09_23_B.num_254 == 2.0) && y) {
      caso = 4;
    }
  }

  switch (caso) {
   case 1:
    rtb_RateTransition = prova_LOG_AHRS_09_23_B.poss_254[(int32_T)
      prova_LOG_AHRS_09_23_B.num_254 - 1];
    if (rtb_RateTransition == 100.0) {
      prova_LOG_AHRS_09_23_DW.message[0] =
        prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[99];
      prova_LOG_AHRS_09_23_DW.Interr_parz = true;
    } else if (prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[(int32_T)
               (rtb_RateTransition + 1.0) - 1] <= 100) {
      f = (int32_T)(prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[(int32_T)
                    (prova_LOG_AHRS_09_23_B.poss_254[0] + 1.0) - 1] + 8U);
      g = f;
      if ((uint32_T)f > 255U) {
        g = 255;
      }

      if (g == prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2) {
        prova_LOG_AHRS_09_23_B.num_254 = rt_roundd_snf(rtb_RateTransition);
        if (prova_LOG_AHRS_09_23_B.num_254 < 256.0) {
          if (prova_LOG_AHRS_09_23_B.num_254 >= 0.0) {
            counter = (uint8_T)prova_LOG_AHRS_09_23_B.num_254;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        f = (int32_T)(prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[(int32_T)
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
          prova_LOG_AHRS_09_23_DW.message[f] =
            prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[status + f];
        }

        status = 1;
        for (caso = 0; caso < 100; caso++) {
          prova_LOG_AHRS_09_23_B.messaggio[caso] =
            prova_LOG_AHRS_09_23_DW.message[caso];
          prova_LOG_AHRS_09_23_DW.message[caso] = 0U;
        }

        prova_LOG_AHRS_09_23_DW.counter_o = 0U;
        prova_LOG_AHRS_09_23_DW.mess_len = 0.0;
      } else {
        if ((uint32_T)f > 255U) {
          f = 255;
        }

        if (f > prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2) {
          prova_LOG_AHRS_09_23_DW.mess_len =
            prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2;
          if (rtb_RateTransition > prova_LOG_AHRS_09_23_DW.mess_len) {
            g = 0;
            f = 0;
          } else {
            g = (int32_T)rtb_RateTransition - 1;
            f = (int32_T)prova_LOG_AHRS_09_23_DW.mess_len;
          }

          caso = f - g;
          for (f = 0; f < caso; f++) {
            prova_LOG_AHRS_09_23_DW.message[f] =
              prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[g + f];
          }

          f = (int32_T)(prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[(int32_T)
                        (rtb_RateTransition + 1.0) - 1] + 8U);
          if ((uint32_T)f > 255U) {
            f = 255;
          }

          rtb_RateTransition = rt_roundd_snf((real_T)f -
            prova_LOG_AHRS_09_23_DW.mess_len);
          if (rtb_RateTransition < 256.0) {
            if (rtb_RateTransition >= 0.0) {
              prova_LOG_AHRS_09_23_DW.counter_o = (uint8_T)rtb_RateTransition;
            } else {
              prova_LOG_AHRS_09_23_DW.counter_o = 0U;
            }
          } else {
            prova_LOG_AHRS_09_23_DW.counter_o = MAX_uint8_T;
          }

          prova_LOG_AHRS_09_23_DW.Interr_parz = true;
        }
      }
    } else {
      prova_LOG_AHRS_09_23_DW.Interr_parz = false;
      memset(&prova_LOG_AHRS_09_23_DW.message[0], 0, 100U * sizeof(uint8_T));
      prova_LOG_AHRS_09_23_DW.counter_o = 0U;
      prova_LOG_AHRS_09_23_DW.mess_len = 0.0;
      status = 1;
    }
    break;

   case 2:
    for (f = 0; f < 100; f++) {
      prova_LOG_AHRS_09_23_B.x[f] =
        (prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[f] != 0);
    }

    if (prova_LOG_AHRS_09_2_ifWhileCond(prova_LOG_AHRS_09_23_B.x)) {
      rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_DW.mess_len + 1.0);
      if (rtb_RateTransition < 256.0) {
        if (rtb_RateTransition >= 0.0) {
          c = (uint8_T)rtb_RateTransition;
        } else {
          c = 0U;
        }
      } else {
        c = MAX_uint8_T;
      }

      rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_DW.mess_len +
        (real_T)prova_LOG_AHRS_09_23_DW.counter_o);
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

      if (1 > prova_LOG_AHRS_09_23_DW.counter_o) {
        caso = -1;
      } else {
        caso = prova_LOG_AHRS_09_23_DW.counter_o - 1;
      }

      for (f = 0; f <= caso; f++) {
        prova_LOG_AHRS_09_23_DW.message[(status + f) - 1] =
          prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[f];
      }

      prova_LOG_AHRS_09_23_DW.Interr_parz = false;
      status = 1;
      for (caso = 0; caso < 100; caso++) {
        prova_LOG_AHRS_09_23_B.messaggio[caso] =
          prova_LOG_AHRS_09_23_DW.message[caso];
        prova_LOG_AHRS_09_23_DW.message[caso] = 0U;
      }

      prova_LOG_AHRS_09_23_DW.mess_len = 0.0;
      prova_LOG_AHRS_09_23_DW.counter_o = 0U;
    } else {
      prova_LOG_AHRS_09_23_DW.Interr_parz = false;
      status = 1;
      memset(&prova_LOG_AHRS_09_23_DW.message[0], 0, 100U * sizeof(uint8_T));
      prova_LOG_AHRS_09_23_DW.mess_len = 0.0;
      prova_LOG_AHRS_09_23_DW.counter_o = 0U;
    }
    break;

   case 3:
    rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_DW.mess_len + 1.0);
    if (rtb_RateTransition < 256.0) {
      if (rtb_RateTransition >= 0.0) {
        c = (uint8_T)rtb_RateTransition;
      } else {
        c = 0U;
      }
    } else {
      c = MAX_uint8_T;
    }

    rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_DW.mess_len +
      (real_T)prova_LOG_AHRS_09_23_DW.counter_o);
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

    if (1 > prova_LOG_AHRS_09_23_DW.counter_o) {
      caso = -1;
    } else {
      caso = prova_LOG_AHRS_09_23_DW.counter_o - 1;
    }

    for (f = 0; f <= caso; f++) {
      prova_LOG_AHRS_09_23_DW.message[(status + f) - 1] =
        prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[f];
    }

    prova_LOG_AHRS_09_23_DW.Interr_parz = false;
    status = 1;
    for (caso = 0; caso < 100; caso++) {
      prova_LOG_AHRS_09_23_B.messaggio[caso] =
        prova_LOG_AHRS_09_23_DW.message[caso];
      prova_LOG_AHRS_09_23_DW.message[caso] = 0U;
    }

    prova_LOG_AHRS_09_23_DW.mess_len = 0.0;
    prova_LOG_AHRS_09_23_DW.counter_o = 0U;
    f = (int32_T)(prova_LOG_AHRS_09_23_B.poss_254[(int32_T)
                  prova_LOG_AHRS_09_23_B.num_254 - 1] + 1.0) - 1;
    if (prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[f] <= 100) {
      g = (int32_T)(prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[(int32_T)
                    (prova_LOG_AHRS_09_23_B.poss_254[0] + 1.0) - 1] + 8U);
      if ((uint32_T)g > 255U) {
        g = 255;
      }

      caso = prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2;
      if (prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2 < 0) {
        caso = 0;
      } else {
        if (prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2 > 255) {
          caso = 255;
        }
      }

      if (g == caso) {
        rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_B.poss_254
          [(int32_T)prova_LOG_AHRS_09_23_B.num_254 - 1]);
        if (rtb_RateTransition < 256.0) {
          if (rtb_RateTransition >= 0.0) {
            counter = (uint8_T)rtb_RateTransition;
          } else {
            counter = 0U;
          }
        } else {
          counter = MAX_uint8_T;
        }

        f = (int32_T)(prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[f] + 7U);
        if ((uint32_T)f > 255U) {
          f = 255;
        }

        rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_B.poss_254
          [(int32_T)prova_LOG_AHRS_09_23_B.num_254 - 1] + (real_T)f);
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
          prova_LOG_AHRS_09_23_DW.message[f] =
            prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[g + f];
        }

        for (caso = 0; caso < 100; caso++) {
          prova_LOG_AHRS_09_23_B.messaggio_2[caso] =
            prova_LOG_AHRS_09_23_DW.message[caso];
          prova_LOG_AHRS_09_23_DW.message[caso] = 0U;
        }

        prova_LOG_AHRS_09_23_DW.counter_o = 0U;
        prova_LOG_AHRS_09_23_DW.mess_len = 0.0;
      } else {
        g = (int32_T)(prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[(int32_T)
                      (prova_LOG_AHRS_09_23_B.poss_254[0] + 1.0) - 1] + 8U);
        if ((uint32_T)g > 255U) {
          g = 255;
        }

        caso = prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2;
        if (prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2 < 0) {
          caso = 0;
        } else {
          if (prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2 > 255) {
            caso = 255;
          }
        }

        if (g > caso) {
          prova_LOG_AHRS_09_23_DW.mess_len =
            prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2;
          if (prova_LOG_AHRS_09_23_B.poss_254[(int32_T)
              prova_LOG_AHRS_09_23_B.num_254 - 1] >
              prova_LOG_AHRS_09_23_DW.mess_len) {
            x = 0;
            caso = 0;
          } else {
            x = (int32_T)prova_LOG_AHRS_09_23_B.poss_254[(int32_T)
              prova_LOG_AHRS_09_23_B.num_254 - 1] - 1;
            caso = (int32_T)prova_LOG_AHRS_09_23_DW.mess_len;
          }

          caso -= x;
          for (g = 0; g < caso; g++) {
            prova_LOG_AHRS_09_23_DW.message[g] =
              prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[x + g];
          }

          f = (int32_T)(prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[f] + 8U);
          if ((uint32_T)f > 255U) {
            f = 255;
          }

          rtb_RateTransition = rt_roundd_snf((real_T)f -
            prova_LOG_AHRS_09_23_DW.mess_len);
          if (rtb_RateTransition < 256.0) {
            if (rtb_RateTransition >= 0.0) {
              prova_LOG_AHRS_09_23_DW.counter_o = (uint8_T)rtb_RateTransition;
            } else {
              prova_LOG_AHRS_09_23_DW.counter_o = 0U;
            }
          } else {
            prova_LOG_AHRS_09_23_DW.counter_o = MAX_uint8_T;
          }

          prova_LOG_AHRS_09_23_DW.Interr_parz = true;
        }
      }
    } else {
      prova_LOG_AHRS_09_23_DW.Interr_parz = false;
      memset(&prova_LOG_AHRS_09_23_B.messaggio[0], 0, 100U * sizeof(uint8_T));
      memset(&prova_LOG_AHRS_09_23_DW.message[0], 0, 100U * sizeof(uint8_T));
      prova_LOG_AHRS_09_23_DW.counter_o = 0U;
      prova_LOG_AHRS_09_23_DW.mess_len = 0.0;
    }
    break;

   case 4:
    if (prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[(int32_T)
        (prova_LOG_AHRS_09_23_B.poss_254[0] + 1.0) - 1] <= 100) {
      rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_B.poss_254[0]);
      if (rtb_RateTransition < 256.0) {
        if (rtb_RateTransition >= 0.0) {
          counter = (uint8_T)rtb_RateTransition;
        } else {
          counter = 0U;
        }
      } else {
        counter = MAX_uint8_T;
      }

      f = (int32_T)(prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[(int32_T)
                    (prova_LOG_AHRS_09_23_B.poss_254[0] + 1.0) - 1] + 7U);
      if ((uint32_T)f > 255U) {
        f = 255;
      }

      rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_B.poss_254[0] +
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
        prova_LOG_AHRS_09_23_B.messaggio[f] =
          prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[status + f];
      }
    } else {
      prova_LOG_AHRS_09_23_DW.Interr_parz = false;
      memset(&prova_LOG_AHRS_09_23_DW.message[0], 0, 100U * sizeof(uint8_T));
    }

    status = 1;
    if ((prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[(int32_T)
         (prova_LOG_AHRS_09_23_B.poss_254[1] + 1.0) - 1] <= 100) &&
        (prova_LOG_AHRS_09_23_B.poss_254[1] - prova_LOG_AHRS_09_23_B.poss_254[0]
         > 3.0)) {
      rtb_RateTransition = rt_roundd_snf((real_T)
        prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2 -
        prova_LOG_AHRS_09_23_B.poss_254[1]);
      qY = prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[(int32_T)
        (prova_LOG_AHRS_09_23_B.poss_254[1] + 1.0) - 1];
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
        rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_B.poss_254[1]);
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

        rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_B.poss_254[1] +
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
          prova_LOG_AHRS_09_23_DW.message[f] =
            prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[status + f];
        }

        status = 2;
        for (caso = 0; caso < 100; caso++) {
          prova_LOG_AHRS_09_23_B.messaggio_2[caso] =
            prova_LOG_AHRS_09_23_DW.message[caso];
          prova_LOG_AHRS_09_23_DW.message[caso] = 0U;
        }

        prova_LOG_AHRS_09_23_DW.counter_o = 0U;
        prova_LOG_AHRS_09_23_DW.mess_len = 0.0;
      } else {
        rtb_RateTransition = rt_roundd_snf(prova_LOG_AHRS_09_23_B.poss_254[1]);
        if (rtb_RateTransition < 2.147483648E+9) {
          if (rtb_RateTransition >= -2.147483648E+9) {
            f = (int32_T)rtb_RateTransition;
          } else {
            f = MIN_int32_T;
          }
        } else {
          f = MAX_int32_T;
        }

        if (f > prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2) {
          f = -1;
          caso = 0;
        } else {
          f -= 2;
          caso = prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2;
        }

        prova_LOG_AHRS_09_23_DW.mess_len = (int8_T)((caso - f) - 1);
        if (rtb_RateTransition < 2.147483648E+9) {
          if (rtb_RateTransition >= -2.147483648E+9) {
            f = (int32_T)rtb_RateTransition;
          } else {
            f = MIN_int32_T;
          }
        } else {
          f = MAX_int32_T;
        }

        if (f > prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2) {
          g = 0;
          f = 0;
        } else {
          g = f - 1;
          f = prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2;
        }

        caso = f - g;
        for (f = 0; f < caso; f++) {
          prova_LOG_AHRS_09_23_DW.message[f] =
            prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[g + f];
        }

        f = (int32_T)(qY + 8U);
        if (qY + 8U > 255U) {
          f = 255;
        }

        rtb_RateTransition = rt_roundd_snf((real_T)f -
          prova_LOG_AHRS_09_23_DW.mess_len);
        if (rtb_RateTransition < 256.0) {
          if (rtb_RateTransition >= 0.0) {
            prova_LOG_AHRS_09_23_DW.counter_o = (uint8_T)rtb_RateTransition;
          } else {
            prova_LOG_AHRS_09_23_DW.counter_o = 0U;
          }
        } else {
          prova_LOG_AHRS_09_23_DW.counter_o = MAX_uint8_T;
        }

        prova_LOG_AHRS_09_23_DW.Interr_parz = true;
      }
    } else {
      prova_LOG_AHRS_09_23_DW.Interr_parz = false;
      memset(&prova_LOG_AHRS_09_23_DW.message[0], 0, 100U * sizeof(uint8_T));
      prova_LOG_AHRS_09_23_DW.counter_o = 0U;
      prova_LOG_AHRS_09_23_DW.mess_len = 0.0;
    }
    break;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   *  Memory: '<S1>/Memory4'
   */
  memset(&prova_LOG_AHRS_09_23_B.buffer[0], 0, 300U * sizeof(uint8_T));
  counter = 0U;
  for (f = 0; f < 100; f++) {
    prova_LOG_AHRS_09_23_B.buffer[3 * f] = 0U;
  }

  for (f = 0; f < 100; f++) {
    for (caso = 0; caso < 2; caso++) {
      g = 3 * f + caso;
      prova_LOG_AHRS_09_23_B.buffer[g + 1] =
        prova_LOG_AHRS_09_23_DW.Memory4_PreviousInput[g];
    }
  }

  caso = 3;
  exitg1 = false;
  while ((!exitg1) && (caso >= 1)) {
    for (f = 0; f < 100; f++) {
      prova_LOG_AHRS_09_23_B.x[f] = (prova_LOG_AHRS_09_23_B.buffer[(3 * f + caso)
        - 1] == 0);
    }

    y = true;
    f = 0;
    exitg2 = false;
    while ((!exitg2) && (f < 100)) {
      if (!prova_LOG_AHRS_09_23_B.x[f]) {
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
      prova_LOG_AHRS_09_23_B.buffer[(counter + 3 * f) - 1] =
        prova_LOG_AHRS_09_23_B.messaggio[f];
    }
  } else if (status == 2) {
    qY = counter - /*MW:OvSatOk*/ 1U;
    if (counter - 1U > counter) {
      qY = 0U;
    }

    for (f = 0; f < 100; f++) {
      prova_LOG_AHRS_09_23_B.buffer[(counter + 3 * f) - 1] =
        prova_LOG_AHRS_09_23_B.messaggio[f];
      prova_LOG_AHRS_09_23_B.buffer[((int32_T)qY + 3 * f) - 1] =
        prova_LOG_AHRS_09_23_B.messaggio_2[f];
    }
  } else {
    for (f = 0; f < 100; f++) {
      prova_LOG_AHRS_09_23_B.buffer[(counter + 3 * f) - 1] = 0U;
    }
  }

  for (f = 0; f < 100; f++) {
    prova_LOG_AHRS_09_23_B.mess_out[f] =
      prova_LOG_AHRS_09_23_DW.Memory4_PreviousInput[3 * f + 2];
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function2'
   *  Memory: '<S1>/Memory4'
   */
  prova_LOG_AHRS_09_23_B.Add = prova_LOG_AHRS_09_23_DW.Memory4_PreviousInput[5]
    + prova_LOG_AHRS_09_23_P.Constant_Value_i;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Memory: '<S1>/Memory5'
   */
  if (prova_LOG_AHRS_09_23_B.mess_out[2] !=
      prova_LOG_AHRS_09_23_DW.Memory5_PreviousInput[2]) {
    for (f = 0; f < 100; f++) {
      prova_LOG_AHRS_09_23_B.x[f] = (prova_LOG_AHRS_09_23_B.mess_out[f] != 0);
    }

    y = true;
    f = 0;
    exitg1 = false;
    while ((!exitg1) && (f < 100)) {
      if (!prova_LOG_AHRS_09_23_B.x[f]) {
        y = false;
        exitg1 = true;
      } else {
        f++;
      }
    }

    if (!y) {
      if (prova_LOG_AHRS_09_23_DW.counter > 100) {
        prova_LOG_AHRS_09_23_DW.counter = 0U;
      }

      qY = prova_LOG_AHRS_09_23_DW.counter + 1U;
      if (prova_LOG_AHRS_09_23_DW.counter + 1U > 65535U) {
        qY = 65535U;
      }

      prova_LOG_AHRS_09_23_DW.counter = (uint16_T)qY;
    }
  }

  prova_LOG_AHRS_09_23_B.new_mex = prova_LOG_AHRS_09_23_DW.counter;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Memory: '<S1>/Memory1' */
  prova_LOG_AHRS_09_23_B.Memory1[0] =
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0];
  prova_LOG_AHRS_09_23_B.Memory1[1] =
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1];

  /* Memory: '<Root>/Memory' */
  prova_LOG_AHRS_09_23_B.Memory_c[0] =
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[0];
  prova_LOG_AHRS_09_23_B.Memory_c[1] =
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[1];
  prova_LOG_AHRS_09_23_B.Memory_c[2] =
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[2];
  prova_LOG_AHRS_09_23_B.Memory_c[3] =
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[3];

  /* Memory: '<S1>/Memory3' */
  prova_LOG_AHRS_09_23_B.Memory3 = prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput;
  for (caso = 0; caso < 8; caso++) {
    /* Memory: '<S1>/Memory' */
    prova_LOG_AHRS_09_23_B.Memory[caso] =
      prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_c[caso];
  }

  /* S-Function (receive_MAVLink_v4_6_beta_AL_HITL_HOME): '<S1>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   */
  receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper
    (&prova_LOG_AHRS_09_23_B.mess_out[0], &prova_LOG_AHRS_09_23_B.Add,
     &prova_LOG_AHRS_09_23_B.new_mex, &prova_LOG_AHRS_09_23_P.SIUAVuint8_Value,
     &prova_LOG_AHRS_09_23_B.Memory[0], &prova_LOG_AHRS_09_23_B.Memory1[0],
     &prova_LOG_AHRS_09_23_B.Memory_c[0], &prova_LOG_AHRS_09_23_B.Memory3,
     &prova_LOG_AHRS_09_23_B.SFunction_o1[0],
     &prova_LOG_AHRS_09_23_B.SFunction_o2,
     &prova_LOG_AHRS_09_23_B.SFunction_o3_j,
     &prova_LOG_AHRS_09_23_B.SFunction_o4_b[0],
     &prova_LOG_AHRS_09_23_B.SFunction_o5[0],
     &prova_LOG_AHRS_09_23_B.SFunction_o6, &prova_LOG_AHRS_09_23_B.SFunction_o7
     [0], &prova_LOG_AHRS_09_23_B.SFunction_o8,
     &prova_LOG_AHRS_09_23_B.SFunction_o9[0],
     &prova_LOG_AHRS_09_23_B.SFunction_o10[0],
     &prova_LOG_AHRS_09_23_B.SFunction_o11[0],
     &prova_LOG_AHRS_09_23_B.SFunction_o12,
     &prova_LOG_AHRS_09_23_B.SFunction_o13,
     &prova_LOG_AHRS_09_23_B.SFunction_o14,
     &prova_LOG_AHRS_09_23_B.SFunction_o15,
     &prova_LOG_AHRS_09_23_B.SFunction_o16,
     &prova_LOG_AHRS_09_23_B.SFunction_o17, 100);

  /* Memory: '<S1>/Memory2' */
  for (caso = 0; caso < 9; caso++) {
    prova_LOG_AHRS_09_23_B.Memory2[caso] =
      prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput_i[caso];
  }

  /* End of Memory: '<S1>/Memory2' */

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  for (caso = 0; caso < 6; caso++) {
    prova_LOG_AHRS_09_23_B.WP_info_in[caso] =
      prova_LOG_AHRS_09_23_B.SFunction_o9[caso];
  }

  if ((!prova_LOG_AHRS_09_23_DW.WP_dbP_not_empty) ||
      ((prova_LOG_AHRS_09_23_B.SFunction_o7[0] == 3) &&
       (prova_LOG_AHRS_09_23_B.SFunction_o7[1] == 250))) {
    memset(&prova_LOG_AHRS_09_23_DW.WP_dbP[0], 0, 42U * sizeof(real32_T));
    prova_LOG_AHRS_09_23_DW.WP_dbP_not_empty = true;
    memset(&prova_LOG_AHRS_09_23_DW.WP_dbI[0], 0, 36U * sizeof(uint16_T));
  }

  if ((!prova_LOG_AHRS_09_23_DW.WP_dbP_AL_not_empty) ||
      ((prova_LOG_AHRS_09_23_B.SFunction_o7[0] == 3) &&
       (prova_LOG_AHRS_09_23_B.SFunction_o7[1] == 250))) {
    memset(&prova_LOG_AHRS_09_23_DW.WP_dbP_AL[0], 0, 42U * sizeof(real32_T));
    prova_LOG_AHRS_09_23_DW.WP_dbP_AL_not_empty = true;
  }

  prova_LOG_AHRS_09_23_B.GC_info[0] = prova_LOG_AHRS_09_23_B.SFunction_o7[0];
  prova_LOG_AHRS_09_23_B.GC_info[1] = prova_LOG_AHRS_09_23_B.SFunction_o7[1];
  prova_LOG_AHRS_09_23_B.GC_info[2] = prova_LOG_AHRS_09_23_B.SFunction_o11[0];
  if (prova_LOG_AHRS_09_23_B.GC_info[0] == 1) {
    if ((prova_LOG_AHRS_09_23_B.GC_info[1] > 0) &&
        (prova_LOG_AHRS_09_23_B.GC_info[1] <= 7)) {
      if ((real32_T)fabs(prova_LOG_AHRS_09_23_B.SFunction_o8) > 0.0F) {
        prova_LOG_AHRS_09_23_DW.riferimenti[prova_LOG_AHRS_09_23_B.GC_info[1] -
          1] = 1.0F;
      } else {
        if (prova_LOG_AHRS_09_23_B.SFunction_o8 == 0.0F) {
          prova_LOG_AHRS_09_23_DW.riferimenti[prova_LOG_AHRS_09_23_B.GC_info[1]
            - 1] = 0.0F;
        }
      }
    } else {
      if ((prova_LOG_AHRS_09_23_B.GC_info[1] > 7) &&
          (prova_LOG_AHRS_09_23_B.GC_info[1] < 12)) {
        prova_LOG_AHRS_09_23_DW.riferimenti[prova_LOG_AHRS_09_23_B.GC_info[1] -
          1] = prova_LOG_AHRS_09_23_B.SFunction_o8;
      }
    }
  }

  if (prova_LOG_AHRS_09_23_B.SFunction_o12 == 13) {
    prova_LOG_AHRS_09_23_DW.riferimenti[prova_LOG_AHRS_09_23_B.SFunction_o12 - 1]
      = prova_LOG_AHRS_09_23_B.SFunction_o13;
  }

  memcpy(&prova_LOG_AHRS_09_23_B.Val_out_MAV[0],
         &prova_LOG_AHRS_09_23_DW.riferimenti[0], sizeof(real32_T) << 4U);
  if ((prova_LOG_AHRS_09_23_B.GC_info[0] == 3) &&
      (prova_LOG_AHRS_09_23_B.GC_info[1] == 200)) {
    if (prova_LOG_AHRS_09_23_B.SFunction_o9[0] > 6) {
      prova_LOG_AHRS_09_23_B.WP_info_in[0] = 6U;
    }

    for (f = 0; f < 6; f++) {
      prova_LOG_AHRS_09_23_DW.WP_dbI[f] = prova_LOG_AHRS_09_23_B.WP_info_in[0];
    }
  }

  if ((prova_LOG_AHRS_09_23_B.GC_info[0] == 3) &&
      (prova_LOG_AHRS_09_23_B.GC_info[1] < 200)) {
    if (prova_LOG_AHRS_09_23_B.SFunction_o10[1] == 0.0F) {
      qY = prova_LOG_AHRS_09_23_B.SFunction_o9[1] + 1U;
      if (prova_LOG_AHRS_09_23_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (f = 0; f < 7; f++) {
        prova_LOG_AHRS_09_23_DW.WP_dbP[((int32_T)qY + 6 * f) - 1] =
          prova_LOG_AHRS_09_23_B.SFunction_o10[f];
      }

      qY = prova_LOG_AHRS_09_23_B.SFunction_o9[1] + 1U;
      if (prova_LOG_AHRS_09_23_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (f = 0; f < 6; f++) {
        prova_LOG_AHRS_09_23_DW.WP_dbI[((int32_T)qY + 6 * (f + 1)) - 1] =
          prova_LOG_AHRS_09_23_B.WP_info_in[f + 1];
      }
    } else {
      f = (int32_T)(prova_LOG_AHRS_09_23_B.SFunction_o10[0] + 1.0F);
      for (g = 0; g < 7; g++) {
        prova_LOG_AHRS_09_23_DW.WP_dbP_AL[(f + 6 * g) - 1] =
          prova_LOG_AHRS_09_23_B.SFunction_o10[g];
      }

      qY = prova_LOG_AHRS_09_23_B.SFunction_o9[1] + 1U;
      if (prova_LOG_AHRS_09_23_B.SFunction_o9[1] + 1U > 65535U) {
        qY = 65535U;
      }

      for (f = 0; f < 6; f++) {
        prova_LOG_AHRS_09_23_DW.WP_dbI[((int32_T)qY + 6 * (f + 1)) - 1] =
          prova_LOG_AHRS_09_23_B.WP_info_in[f + 1];
      }
    }
  }

  /* Update for Memory: '<S1>/Memory3' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput = 0U;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  if ((prova_LOG_AHRS_09_23_B.SFunction_o6 == 0) &&
      (prova_LOG_AHRS_09_23_B.SFunction_o3_j == 0)) {
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 0U;
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput = 0U;
  } else if ((prova_LOG_AHRS_09_23_B.SFunction_o6 == 0) &&
             (prova_LOG_AHRS_09_23_B.SFunction_o3_j == 3)) {
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 0U;
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 3U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput = 0U;
    prova_LOG_AHRS_09_23_DW.test1 = 0.0;
  } else if ((prova_LOG_AHRS_09_23_B.SFunction_o6 == 0) &&
             (prova_LOG_AHRS_09_23_B.SFunction_o3_j == 2)) {
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 0U;
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 2U;
    AP_mode_idx_0 = 1;
    AP_mode_idx_1 = 0;

    /* Update for Memory: '<S1>/Memory3' */
    prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput = 0U;
    prova_LOG_AHRS_09_23_DW.test1 = 0.0;
  } else if ((prova_LOG_AHRS_09_23_B.SFunction_o6 == 0) &&
             (prova_LOG_AHRS_09_23_B.SFunction_o3_j == 1)) {
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 0U;
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 1U;
    AP_mode_idx_0 = 0;
    AP_mode_idx_1 = 1;

    /* Update for Memory: '<S1>/Memory3' */
    prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput = 0U;
    prova_LOG_AHRS_09_23_DW.test1 = 1.0;
  } else {
    switch (prova_LOG_AHRS_09_23_B.SFunction_o6) {
     case 192:
      prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 192U;
      prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 4U;
      AP_mode_idx_0 = 1;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput = 192U;
      break;

     case 208:
      prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 208U;
      prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 3U;
      AP_mode_idx_0 = 0;
      AP_mode_idx_1 = 0;

      /* Update for Memory: '<S1>/Memory3' */
      prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput = 208U;
      break;

     default:
      if ((prova_LOG_AHRS_09_23_B.SFunction_o6 == 220) &&
          (prova_LOG_AHRS_09_23_B.SFunction_o3_j != 5)) {
        if ((prova_LOG_AHRS_09_23_B.Memory2[0] == 0) &&
            (prova_LOG_AHRS_09_23_B.Memory2[1] == 0) &&
            ((prova_LOG_AHRS_09_23_B.Memory2[2] == 1) ||
             (prova_LOG_AHRS_09_23_B.Memory2[3] == 1) ||
             (prova_LOG_AHRS_09_23_B.Memory2[4] == 1) ||
             (prova_LOG_AHRS_09_23_B.Memory2[5] == 1) ||
             (prova_LOG_AHRS_09_23_B.Memory2[6] == 1) ||
             (prova_LOG_AHRS_09_23_B.Memory2[7] == 1))) {
          prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 220U;
          prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput = 220U;
        } else if ((prova_LOG_AHRS_09_23_B.Memory2[0] == 0) &&
                   (prova_LOG_AHRS_09_23_B.Memory2[1] == 1) &&
                   ((prova_LOG_AHRS_09_23_B.Memory2[2] == 1) ||
                    (prova_LOG_AHRS_09_23_B.Memory2[3] == 1) ||
                    (prova_LOG_AHRS_09_23_B.Memory2[4] == 1) ||
                    (prova_LOG_AHRS_09_23_B.Memory2[5] == 1) ||
                    (prova_LOG_AHRS_09_23_B.Memory2[6] == 1) ||
                    (prova_LOG_AHRS_09_23_B.Memory2[7] == 1))) {
          prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 220U;
          prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 4U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 1;

          /* Update for Memory: '<S1>/Memory3' */
          prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput = 220U;
        } else {
          prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 208U;
          prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 3U;
          AP_mode_idx_0 = 0;
          AP_mode_idx_1 = 0;

          /* Update for Memory: '<S1>/Memory3' */
          prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput = 208U;
        }
      } else if (prova_LOG_AHRS_09_23_B.SFunction_o3_j == 5) {
        prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 220U;
        prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 5U;
        AP_mode_idx_0 = 0;
        AP_mode_idx_1 = 1;
      } else {
        prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] = 192U;
        prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] = 6U;
        AP_mode_idx_0 = 1;
        AP_mode_idx_1 = 0;
      }
      break;
    }
  }

  qY = 100U * prova_LOG_AHRS_09_23_B.SFunction_o11[5];
  if (qY > 65535U) {
    qY = 65535U;
  }

  if (prova_LOG_AHRS_09_23_B.SFunction_o11[4] == 0) {
    if ((uint16_T)qY == 0) {
      z = 0U;
    } else {
      z = MAX_uint16_T;
    }
  } else {
    z = (uint16_T)(prova_LOG_AHRS_09_23_B.SFunction_o11[4] == 0U ? MAX_uint32_T :
                   (uint32_T)(uint16_T)qY /
                   prova_LOG_AHRS_09_23_B.SFunction_o11[4]);
    x_0 = (uint16_T)((uint32_T)(uint16_T)qY - (uint16_T)((uint32_T)z *
      prova_LOG_AHRS_09_23_B.SFunction_o11[4]));
    if ((x_0 > 0) && (x_0 >= (int32_T)((uint32_T)
          prova_LOG_AHRS_09_23_B.SFunction_o11[4] >> 1) +
                      (prova_LOG_AHRS_09_23_B.SFunction_o11[4] & 1))) {
      z++;
    }
  }

  /* RateTransition: '<S23>/Rate Transition' */
  rtb_RateTransition = prova_LOG_AHRS_09_23_DW.RateTransition_Buffer0;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Constant: '<S23>/Constant3'
   *  Memory: '<S23>/Memory1'
   *  Sum: '<S23>/Add1'
   */
  prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput +=
    prova_LOG_AHRS_09_23_P.Constant2_Value +
    prova_LOG_AHRS_09_23_P.Constant3_Value;

  /* Switch: '<S23>/Switch' */
  if (prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput >
      prova_LOG_AHRS_09_23_P.Switch_Threshold) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<S23>/Constant2'
     */
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput =
      prova_LOG_AHRS_09_23_P.Constant2_Value;
  }

  /* End of Switch: '<S23>/Switch' */

  /* MATLAB Function: '<S12>/iflogic_function' */
  if ((prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 1.0) ||
      (prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 3.0)) {
    prova_LOG_AHRS_09_23_B.iflogic = 26U;
  } else if ((prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 2.0) ||
             (prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 4.0)) {
    prova_LOG_AHRS_09_23_B.iflogic = 30U;
  } else if ((prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 2.0)) {
    prova_LOG_AHRS_09_23_B.iflogic = 33U;
  } else if ((prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 6.0)) {
    prova_LOG_AHRS_09_23_B.iflogic = 34U;
  } else if ((prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 0.0)) {
    prova_LOG_AHRS_09_23_B.iflogic = 0U;
  } else if ((prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             ((rtb_RateTransition == 1.0) || (rtb_RateTransition == 5.0) ||
              (rtb_RateTransition == 9.0))) {
    prova_LOG_AHRS_09_23_B.iflogic = 1U;
  } else if ((prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             ((rtb_RateTransition == 3.0) || (rtb_RateTransition == 8.0))) {
    prova_LOG_AHRS_09_23_B.iflogic = 74U;
  } else if ((prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 7.0)) {
    prova_LOG_AHRS_09_23_B.iflogic = 36U;
  } else if ((prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput == 0.0) &&
             (rtb_RateTransition == 4.0)) {
    prova_LOG_AHRS_09_23_B.iflogic = 29U;
  } else {
    prova_LOG_AHRS_09_23_B.iflogic = MAX_uint8_T;
  }

  /* End of MATLAB Function: '<S12>/iflogic_function' */

  /* Sum: '<S23>/Add' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S23>/Constant1'
   *  Memory: '<S23>/Memory'
   */
  prova_LOG_AHRS_09_23_DW.Memory_PreviousInput +=
    prova_LOG_AHRS_09_23_P.Constant_Value +
    prova_LOG_AHRS_09_23_P.Constant1_Value;

  /* Gain: '<S12>/Gain' */
  rtb_RateTransition = prova_LOG_AHRS_09_23_P.Gain_Gain *
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
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

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3 = rtb_RateTransition < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-rtb_RateTransition : (uint32_T)
    rtb_RateTransition;

  /* MATLAB Function: '<S19>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  for (f = 0; f < 6; f++) {
    prova_LOG_AHRS_09_23_B.WP_info[f] = prova_LOG_AHRS_09_23_DW.WP_dbI[6 * f];
  }

  for (f = 0; f < 7; f++) {
    prova_LOG_AHRS_09_23_B.WP_param[f] = prova_LOG_AHRS_09_23_DW.WP_dbP[6 * f];
  }

  if ((prova_LOG_AHRS_09_23_B.GC_info[0] == 2) &&
      (prova_LOG_AHRS_09_23_B.GC_info[1] < 6)) {
    qY = prova_LOG_AHRS_09_23_B.GC_info[1] + 1U;
    if (prova_LOG_AHRS_09_23_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (f = 0; f < 6; f++) {
      prova_LOG_AHRS_09_23_B.WP_info[f] = prova_LOG_AHRS_09_23_DW.WP_dbI[(6 * f
        + (int32_T)qY) - 1];
    }

    qY = prova_LOG_AHRS_09_23_B.GC_info[1] + 1U;
    if (prova_LOG_AHRS_09_23_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (f = 0; f < 7; f++) {
      prova_LOG_AHRS_09_23_B.WP_param[f] = prova_LOG_AHRS_09_23_DW.WP_dbP[(6 * f
        + (int32_T)qY) - 1];
    }
  }

  if ((prova_LOG_AHRS_09_23_B.GC_info[0] == 3) &&
      (prova_LOG_AHRS_09_23_B.GC_info[1] < 200)) {
    qY = prova_LOG_AHRS_09_23_B.GC_info[1] + 1U;
    if (prova_LOG_AHRS_09_23_B.GC_info[1] + 1U > 65535U) {
      qY = 65535U;
    }

    for (f = 0; f < 6; f++) {
      prova_LOG_AHRS_09_23_B.WP_info[f] = prova_LOG_AHRS_09_23_DW.WP_dbI[(6 * f
        + (int32_T)qY) - 1];
    }
  }

  /* End of MATLAB Function: '<S19>/MATLAB Function' */

  /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
   *  Constant: '<S17>/onboard_control_sensor_present uint32'
   */
  prova_LOG_AHRS_09_23_B.onboard[0] =
    prova_LOG_AHRS_09_23_P.onboard_control_sensor_presentu[0];
  prova_LOG_AHRS_09_23_B.onboard[1] =
    prova_LOG_AHRS_09_23_P.onboard_control_sensor_presentu[1];
  prova_LOG_AHRS_09_23_B.onboard[2] =
    prova_LOG_AHRS_09_23_P.onboard_control_sensor_presentu[2];

  /* Gain: '<S17>/Gain' incorporates:
   *  Constant: '<S17>/Constant'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Gain_Gain_c *
    prova_LOG_AHRS_09_23_P.Constant_Value_o);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
   *  Constant: '<S17>/load uint16'
   *  Gain: '<S17>/Gain'
   */
  prova_LOG_AHRS_09_23_B.LVDE[0] = prova_LOG_AHRS_09_23_P.loaduint16_Value;
  prova_LOG_AHRS_09_23_B.LVDE[1] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  qY = 10U * z;
  if (qY > 65535U) {
    qY = 65535U;
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
   *  Constant: '<S17>/ '
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  prova_LOG_AHRS_09_23_B.LVDE[2] = (uint16_T)qY;
  prova_LOG_AHRS_09_23_B.LVDE[3] = prova_LOG_AHRS_09_23_B.SFunction_o11[6];
  prova_LOG_AHRS_09_23_B.LVDE[4] = prova_LOG_AHRS_09_23_B.SFunction_o11[2];
  prova_LOG_AHRS_09_23_B.LVDE[5] = prova_LOG_AHRS_09_23_P._Value;

  /* DataTypeConversion: '<S17>/Data Type Conversion4' incorporates:
   *  Constant: '<S17>/Constant1'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant1_Value_l[0]);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion4'
   */
  prova_LOG_AHRS_09_23_B.LVDE[6] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S17>/Data Type Conversion4' incorporates:
   *  Constant: '<S17>/Constant1'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant1_Value_l[1]);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion4'
   */
  prova_LOG_AHRS_09_23_B.LVDE[7] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* Gain: '<S17>/Gain2' incorporates:
   *  Constant: '<S17>/Constant3'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Gain2_Gain *
    prova_LOG_AHRS_09_23_P.Constant3_Value_m);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
   *  Gain: '<S17>/Gain1'
   *  Gain: '<S17>/Gain2'
   */
  prova_LOG_AHRS_09_23_B.B_Current = (int16_T)(((rtb_RateTransition < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition) * prova_LOG_AHRS_09_23_P.Gain1_Gain_f)
    >> 18);

  /* DataTypeConversion: '<S17>/Data Type Conversion3' incorporates:
   *  Constant: '<S17>/Constant2'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant2_Value_a);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.B_Remaining = (int8_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(int8_T)-(int8_T)(uint8_T)-rtb_RateTransition : (int32_T)(int8_T)
    (uint8_T)rtb_RateTransition);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant_Value_n);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion = rtb_RateTransition < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-rtb_RateTransition : (uint32_T)
    rtb_RateTransition;

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  MATLAB Function: '<S10>/Alarm set'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[2] =
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0];
  prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[3] =
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1];

  /* MATLAB Function: '<S10>/Alarm set' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  if (prova_LOG_AHRS_09_23_P.Constant1_Value_j[0] == 1.0) {
    /* DataTypeConversion: '<S10>/Data Type Conversion1' */
    prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[2] = 220U;
    prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[3] = 5U;
  }

  if (prova_LOG_AHRS_09_23_P.Constant1_Value_j[1] == 1.0) {
    /* DataTypeConversion: '<S10>/Data Type Conversion1' */
    prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[2] = 216U;
    prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[3] = 4U;
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S10>/Type fixed_wing Autopilot generic'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[0] =
    prova_LOG_AHRS_09_23_P.Typefixed_wingAutopilotgeneric_[0];
  prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[1] =
    prova_LOG_AHRS_09_23_P.Typefixed_wingAutopilotgeneric_[1];

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (prova_LOG_AHRS_09_23_B.ByteReversal[6] < 0.0F) {
    tmp = (real32_T)ceil(prova_LOG_AHRS_09_23_B.ByteReversal[6]);
  } else {
    tmp = (real32_T)floor(prova_LOG_AHRS_09_23_B.ByteReversal[6]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_j[0] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (prova_LOG_AHRS_09_23_B.ByteReversal[7] < 0.0F) {
    tmp = (real32_T)ceil(prova_LOG_AHRS_09_23_B.ByteReversal[7]);
  } else {
    tmp = (real32_T)floor(prova_LOG_AHRS_09_23_B.ByteReversal[7]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_j[1] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (prova_LOG_AHRS_09_23_B.ByteReversal[8] < 0.0F) {
    tmp = (real32_T)ceil(prova_LOG_AHRS_09_23_B.ByteReversal[8]);
  } else {
    tmp = (real32_T)floor(prova_LOG_AHRS_09_23_B.ByteReversal[8]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_j[2] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (prova_LOG_AHRS_09_23_B.ByteReversal[3] < 0.0F) {
    tmp = (real32_T)ceil(prova_LOG_AHRS_09_23_B.ByteReversal[3]);
  } else {
    tmp = (real32_T)floor(prova_LOG_AHRS_09_23_B.ByteReversal[3]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_j[3] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (prova_LOG_AHRS_09_23_B.ByteReversal[4] < 0.0F) {
    tmp = (real32_T)ceil(prova_LOG_AHRS_09_23_B.ByteReversal[4]);
  } else {
    tmp = (real32_T)floor(prova_LOG_AHRS_09_23_B.ByteReversal[4]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_j[4] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (prova_LOG_AHRS_09_23_B.ByteReversal[5] < 0.0F) {
    tmp = (real32_T)ceil(prova_LOG_AHRS_09_23_B.ByteReversal[5]);
  } else {
    tmp = (real32_T)floor(prova_LOG_AHRS_09_23_B.ByteReversal[5]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_j[5] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant3'
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   */
  if ((real32_T)prova_LOG_AHRS_09_23_P.Constant3_Value_a[0] < 0.0F) {
    tmp = (real32_T)ceil((real32_T)prova_LOG_AHRS_09_23_P.Constant3_Value_a[0]);
  } else {
    tmp = (real32_T)floor((real32_T)prova_LOG_AHRS_09_23_P.Constant3_Value_a[0]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_j[6] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant3'
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   */
  if ((real32_T)prova_LOG_AHRS_09_23_P.Constant3_Value_a[1] < 0.0F) {
    tmp = (real32_T)ceil((real32_T)prova_LOG_AHRS_09_23_P.Constant3_Value_a[1]);
  } else {
    tmp = (real32_T)floor((real32_T)prova_LOG_AHRS_09_23_P.Constant3_Value_a[1]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_j[7] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/Constant3'
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   */
  if ((real32_T)prova_LOG_AHRS_09_23_P.Constant3_Value_a[2] < 0.0F) {
    tmp = (real32_T)ceil((real32_T)prova_LOG_AHRS_09_23_P.Constant3_Value_a[2]);
  } else {
    tmp = (real32_T)floor((real32_T)prova_LOG_AHRS_09_23_P.Constant3_Value_a[2]);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_j[8] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S11>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion1[0] =
    prova_LOG_AHRS_09_23_B.ByteReversal[1];
  prova_LOG_AHRS_09_23_B.DataTypeConversion1[1] =
    prova_LOG_AHRS_09_23_B.ByteReversal[0];
  prova_LOG_AHRS_09_23_B.DataTypeConversion1[2] =
    prova_LOG_AHRS_09_23_B.ByteReversal[2];
  prova_LOG_AHRS_09_23_B.DataTypeConversion1[3] =
    prova_LOG_AHRS_09_23_B.ByteReversal[3];
  prova_LOG_AHRS_09_23_B.DataTypeConversion1[4] =
    prova_LOG_AHRS_09_23_B.ByteReversal[4];
  prova_LOG_AHRS_09_23_B.DataTypeConversion1[5] =
    prova_LOG_AHRS_09_23_B.ByteReversal[5];

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/Constant'
   */
  rtb_RateTransition = prova_LOG_AHRS_09_23_P.Gain_Gain_e[0] *
    prova_LOG_AHRS_09_23_P.Constant_Value_ng;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
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

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_a[0] = rtb_RateTransition < 0.0 ?
    -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/Constant2'
   */
  rtb_RateTransition = prova_LOG_AHRS_09_23_P.Gain_Gain_e[1] *
    prova_LOG_AHRS_09_23_P.Constant2_Value_o;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
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

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_a[1] = rtb_RateTransition < 0.0 ?
    -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  rtb_RateTransition = prova_LOG_AHRS_09_23_P.Gain_Gain_e[2] *
    prova_LOG_AHRS_09_23_P.Constant1_Value_m;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
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

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_a[2] = rtb_RateTransition < 0.0 ?
    -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/alt_r'
   */
  rtb_RateTransition = prova_LOG_AHRS_09_23_P.Gain_Gain_e[3] *
    prova_LOG_AHRS_09_23_P.alt_r_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
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

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_a[3] = rtb_RateTransition < 0.0 ?
    -(int32_T)(uint32_T)-rtb_RateTransition : (int32_T)(uint32_T)
    rtb_RateTransition;

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/Constant3'
   */
  rtb_RateTransition = prova_LOG_AHRS_09_23_P.Gain1_Gain *
    prova_LOG_AHRS_09_23_P.Constant3_Value_d;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
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

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion1_g[0] = (int16_T)(rtb_RateTransition
    < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition);

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/vel y'
   */
  rtb_RateTransition = prova_LOG_AHRS_09_23_P.Gain1_Gain *
    prova_LOG_AHRS_09_23_P.vely_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
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

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion1_g[1] = (int16_T)(rtb_RateTransition
    < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition);

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/RC Simulated'
   */
  rtb_RateTransition = prova_LOG_AHRS_09_23_P.Gain1_Gain *
    prova_LOG_AHRS_09_23_P.RCSimulated_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
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

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion1_g[2] = (int16_T)(rtb_RateTransition
    < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition);

  /* Gain: '<S9>/Gain2' incorporates:
   *  Constant: '<S9>/Constant4'
   */
  rtb_RateTransition = prova_LOG_AHRS_09_23_P.Gain2_Gain_j *
    prova_LOG_AHRS_09_23_P.Constant4_Value;

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
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

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion2 = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S18>/RC simulated'
   *  Constant: '<S18>/TAS simulated'
   *  Constant: '<S18>/v simulated'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_m[0] = (real32_T)
    prova_LOG_AHRS_09_23_P.TASsimulated_Value;
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_m[1] = (real32_T)
    prova_LOG_AHRS_09_23_P.vsimulated_Value;
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_m[2] = (real32_T)
    prova_LOG_AHRS_09_23_P.Constant_Value_nt;
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_m[3] = (real32_T)
    prova_LOG_AHRS_09_23_P.RCsimulated_Value;

  /* DataTypeConversion: '<S18>/Data Type Conversion4' incorporates:
   *  Constant: '<S18>/ Heading simulated'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Headingsimulated_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion4' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion4_i = (int16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S18>/Data Type Conversion5' incorporates:
   *  Constant: '<S18>/Rpm simulated'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Rpmsimulated_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S18>/Data Type Conversion5' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion5 = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* Gain: '<S25>/Gain2' incorporates:
   *  Constant: '<S16>/Manetta Simulated'
   */
  prova_LOG_AHRS_09_23_B.num_254 = prova_LOG_AHRS_09_23_P.Gain2_Gain_o *
    prova_LOG_AHRS_09_23_P.ManettaSimulated_Value;

  /* Sum: '<S25>/Sum' incorporates:
   *  Constant: '<S16>/Equilibratore Simulated'
   *  Constant: '<S25>/Constant2'
   *  Gain: '<S26>/Gain'
   */
  rtb_Sum = prova_LOG_AHRS_09_23_P.Gain_Gain_o *
    prova_LOG_AHRS_09_23_P.EquilibratoreSimulated_Value +
    prova_LOG_AHRS_09_23_P.Constant2_Value_d;

  /* Sum: '<S25>/Sum1' incorporates:
   *  Constant: '<S16>/Alettoni Simulated'
   *  Constant: '<S25>/Constant2'
   *  Gain: '<S27>/Gain'
   */
  prova_LOG_AHRS_09_23_B.Sum1 = prova_LOG_AHRS_09_23_P.Gain_Gain_n *
    prova_LOG_AHRS_09_23_P.AlettoniSimulated_Value +
    prova_LOG_AHRS_09_23_P.Constant2_Value_d;

  /* Sum: '<S25>/Sum2' incorporates:
   *  Constant: '<S16>/Timone Simulated'
   *  Constant: '<S25>/Constant2'
   *  Gain: '<S28>/Gain'
   */
  prova_LOG_AHRS_09_23_B.Sum2 = prova_LOG_AHRS_09_23_P.Gain_Gain_l *
    prova_LOG_AHRS_09_23_P.TimoneSimulated_Value +
    prova_LOG_AHRS_09_23_P.Constant2_Value_d;

  /* Gain: '<S16>/Gain' incorporates:
   *  Constant: '<S16>/Constant2'
   */
  prova_LOG_AHRS_09_23_B.Gain3 = prova_LOG_AHRS_09_23_P.Gain_Gain_b *
    prova_LOG_AHRS_09_23_P.Constant2_Value_p;

  /* Saturate: '<S16>/Saturation' */
  if (prova_LOG_AHRS_09_23_B.Gain3 > prova_LOG_AHRS_09_23_P.Saturation_UpperSat)
  {
    prova_LOG_AHRS_09_23_B.Gain3 = prova_LOG_AHRS_09_23_P.Saturation_UpperSat;
  } else {
    if (prova_LOG_AHRS_09_23_B.Gain3 <
        prova_LOG_AHRS_09_23_P.Saturation_LowerSat) {
      prova_LOG_AHRS_09_23_B.Gain3 = prova_LOG_AHRS_09_23_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
   *  Constant: '<S16>/Constant'
   */
  if (prova_LOG_AHRS_09_23_P.Constant_Value_g < 0.0) {
    rtb_RateTransition = ceil(prova_LOG_AHRS_09_23_P.Constant_Value_g);
  } else {
    rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant_Value_g);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.Heading[0] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (prova_LOG_AHRS_09_23_B.num_254 < 0.0) {
    rtb_RateTransition = ceil(prova_LOG_AHRS_09_23_B.num_254);
  } else {
    rtb_RateTransition = floor(prova_LOG_AHRS_09_23_B.num_254);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.Heading[1] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (rtb_Sum < 0.0) {
    rtb_RateTransition = ceil(rtb_Sum);
  } else {
    rtb_RateTransition = floor(rtb_Sum);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.Heading[2] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (prova_LOG_AHRS_09_23_B.Sum1 < 0.0) {
    rtb_RateTransition = ceil(prova_LOG_AHRS_09_23_B.Sum1);
  } else {
    rtb_RateTransition = floor(prova_LOG_AHRS_09_23_B.Sum1);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.Heading[3] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (prova_LOG_AHRS_09_23_B.Sum2 < 0.0) {
    rtb_RateTransition = ceil(prova_LOG_AHRS_09_23_B.Sum2);
  } else {
    rtb_RateTransition = floor(prova_LOG_AHRS_09_23_B.Sum2);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.Heading[4] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  if (prova_LOG_AHRS_09_23_P.Constant1_Value_d[0] < 0.0) {
    rtb_RateTransition = ceil(prova_LOG_AHRS_09_23_P.Constant1_Value_d[0]);
  } else {
    rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant1_Value_d[0]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.Heading[5] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  if (prova_LOG_AHRS_09_23_P.Constant1_Value_d[1] < 0.0) {
    rtb_RateTransition = ceil(prova_LOG_AHRS_09_23_P.Constant1_Value_d[1]);
  } else {
    rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant1_Value_d[1]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.Heading[6] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  if (prova_LOG_AHRS_09_23_P.Constant1_Value_d[2] < 0.0) {
    rtb_RateTransition = ceil(prova_LOG_AHRS_09_23_P.Constant1_Value_d[2]);
  } else {
    rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant1_Value_d[2]);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.Heading[7] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  if (prova_LOG_AHRS_09_23_B.Gain3 < 0.0) {
    rtb_RateTransition = ceil(prova_LOG_AHRS_09_23_B.Gain3);
  } else {
    rtb_RateTransition = floor(prova_LOG_AHRS_09_23_B.Gain3);
  }

  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  prova_LOG_AHRS_09_23_B.Heading[8] = (uint16_T)(rtb_RateTransition < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* Memory: '<S2>/Memory' */
  prova_LOG_AHRS_09_23_B.Memory_i =
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_c2;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion1_b = (real32_T)
    prova_LOG_AHRS_09_23_P.Constant1_Value_i;

  /* DataTypeConversion: '<S2>/Data Type Conversion4' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion4 = (real32_T)
    prova_LOG_AHRS_09_23_P.Constant6_Value;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Gain: '<S2>/Pa to hPa'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion_k = (real32_T)
    (prova_LOG_AHRS_09_23_P.PatohPa_Gain *
     prova_LOG_AHRS_09_23_P.Constant2_Value_g);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Pa to hPa1'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion1_bl = (real32_T)
    (prova_LOG_AHRS_09_23_P.PatohPa1_Gain *
     prova_LOG_AHRS_09_23_P.Constant2_Value_l);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant5_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion2_d = (int16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (int16_T)(uint16_T)rtb_RateTransition);

  /* S-Function (send_MAVLink_v4_4_2_beta_3_HOME): '<S2>/S-Function' incorporates:
   *  Constant: '<Root>/SI UAV uint8'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  send_MAVLink_v4_4_2_beta_3_HOME_Outputs_wrapper
    (&prova_LOG_AHRS_09_23_B.iflogic,
     &prova_LOG_AHRS_09_23_B.DataTypeConversion3,
     &prova_LOG_AHRS_09_23_P.SIUAVuint8_Value, &prova_LOG_AHRS_09_23_B.GC_info[0],
     &prova_LOG_AHRS_09_23_B.Val_out_MAV[0], &prova_LOG_AHRS_09_23_B.WP_info[0],
     &prova_LOG_AHRS_09_23_B.WP_param[0], &prova_LOG_AHRS_09_23_B.onboard[0],
     &prova_LOG_AHRS_09_23_B.LVDE[0], &prova_LOG_AHRS_09_23_B.B_Current,
     &prova_LOG_AHRS_09_23_B.B_Remaining,
     &prova_LOG_AHRS_09_23_B.DataTypeConversion,
     &prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[0],
     &prova_LOG_AHRS_09_23_B.DataTypeConversion_j[0],
     &prova_LOG_AHRS_09_23_B.DataTypeConversion1[0],
     &prova_LOG_AHRS_09_23_B.DataTypeConversion_a[0],
     &prova_LOG_AHRS_09_23_B.DataTypeConversion1_g[0],
     &prova_LOG_AHRS_09_23_B.DataTypeConversion2,
     &prova_LOG_AHRS_09_23_B.DataTypeConversion3_m[0],
     &prova_LOG_AHRS_09_23_B.DataTypeConversion4_i,
     &prova_LOG_AHRS_09_23_B.DataTypeConversion5,
     &prova_LOG_AHRS_09_23_B.Heading[0], &prova_LOG_AHRS_09_23_B.Memory_i,
     &prova_LOG_AHRS_09_23_B.DataTypeConversion1_b,
     &prova_LOG_AHRS_09_23_B.SFunction_o14,
     &prova_LOG_AHRS_09_23_B.DataTypeConversion4,
     &prova_LOG_AHRS_09_23_B.SFunction_o15,
     &prova_LOG_AHRS_09_23_B.DataTypeConversion_k,
     &prova_LOG_AHRS_09_23_B.DataTypeConversion1_bl,
     &prova_LOG_AHRS_09_23_B.DataTypeConversion2_d,
     &prova_LOG_AHRS_09_23_B.SFunction_o5[0],
     &prova_LOG_AHRS_09_23_P.Constant4_Value_g,
     &prova_LOG_AHRS_09_23_P.Constant5_Value_j,
     &prova_LOG_AHRS_09_23_P.Constant10_Value, ((const uint16_T*)
      &prova_LOG_AHRS_09_23_U16GND), &prova_LOG_AHRS_09_23_B.SFunction_o1_k,
     &prova_LOG_AHRS_09_23_B.SFunction_o2_i[0],
     &prova_LOG_AHRS_09_23_B.SFunction_o3, &prova_LOG_AHRS_09_23_B.SFunction_o4);

  /* Outputs for Enabled SubSystem: '<S2>/Enable ' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (prova_LOG_AHRS_09_23_B.SFunction_o1_k > 0) {
    /* Chart: '<S8>/Chart' */
    if (prova_LOG_AHRS_09_23_DW.is_active_c9_prova_LOG_AHRS_09_ == 0U) {
      prova_LOG_AHRS_09_23_DW.is_active_c9_prova_LOG_AHRS_09_ = 1U;
      prova_LOG_AHRS_09_23_DW.i = 1U;
    } else {
      do {
        exitg3 = 0;
        if (prova_LOG_AHRS_09_23_DW.obj_f.Protocol !=
            prova_LOG_AHRS_09_23_P.SerialTransmit_Protocol) {
          prova_LOG_AHRS_09_23_DW.obj_f.Protocol =
            prova_LOG_AHRS_09_23_P.SerialTransmit_Protocol;
        }

        counter =
          prova_LOG_AHRS_09_23_B.SFunction_o2_i[prova_LOG_AHRS_09_23_DW.i - 1];
        MW_Serial_write(prova_LOG_AHRS_09_23_DW.obj_f.port, &counter, 1.0,
                        prova_LOG_AHRS_09_23_DW.obj_f.dataSizeInBytes,
                        prova_LOG_AHRS_09_23_DW.obj_f.sendModeEnum,
                        prova_LOG_AHRS_09_23_DW.obj_f.dataType,
                        prova_LOG_AHRS_09_23_DW.obj_f.sendFormatEnum, 2.0,
                        '\x00');
        if (prova_LOG_AHRS_09_23_DW.i < prova_LOG_AHRS_09_23_B.SFunction_o3) {
          f = prova_LOG_AHRS_09_23_DW.i + 1;
          if (prova_LOG_AHRS_09_23_DW.i + 1 > 255) {
            f = 255;
          }

          prova_LOG_AHRS_09_23_DW.i = (uint8_T)f;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      prova_LOG_AHRS_09_23_DW.i = 1U;
    }

    /* End of Chart: '<S8>/Chart' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enable ' */

  /* DataTypeConversion: '<S2>/Data Type Conversion6' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant2'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion6[0] = (real32_T)
    prova_LOG_AHRS_09_23_P.Constant_Value_ng;
  prova_LOG_AHRS_09_23_B.DataTypeConversion6[1] = (real32_T)
    prova_LOG_AHRS_09_23_P.Constant2_Value_o;
  prova_LOG_AHRS_09_23_B.DataTypeConversion6[2] = (real32_T)
    prova_LOG_AHRS_09_23_P.Constant1_Value_m;
  prova_LOG_AHRS_09_23_B.DataTypeConversion6[3] = (real32_T)
    prova_LOG_AHRS_09_23_P.Constant_Value_nt;

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(prova_LOG_AHRS_09_23_P.Gain_Gain_m *
                        prova_LOG_AHRS_09_23_B.ByteReversal[0]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_k[0] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(prova_LOG_AHRS_09_23_P.Gain_Gain_m *
                        prova_LOG_AHRS_09_23_B.ByteReversal[1]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_k[1] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(prova_LOG_AHRS_09_23_P.Gain_Gain_m *
                        prova_LOG_AHRS_09_23_B.ByteReversal[2]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_k[2] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(prova_LOG_AHRS_09_23_P.Gain_Gain_lz *
                        prova_LOG_AHRS_09_23_B.ByteReversal[3] *
                        prova_LOG_AHRS_09_23_P.Gain_Gain_m);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_k[3] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S14>/Gain'
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(prova_LOG_AHRS_09_23_P.Gain_Gain_j *
                        prova_LOG_AHRS_09_23_B.ByteReversal[4] *
                        prova_LOG_AHRS_09_23_P.Gain_Gain_m);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_k[4] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S15>/Gain'
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(prova_LOG_AHRS_09_23_P.Gain_Gain_br *
                        prova_LOG_AHRS_09_23_B.ByteReversal[5] *
                        prova_LOG_AHRS_09_23_P.Gain_Gain_m);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_k[5] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(prova_LOG_AHRS_09_23_P.Gain_Gain_m *
                        prova_LOG_AHRS_09_23_B.ByteReversal[6]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_k[6] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(prova_LOG_AHRS_09_23_P.Gain_Gain_m *
                        prova_LOG_AHRS_09_23_B.ByteReversal[7]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_k[7] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  Gain: '<S2>/Gain'
   */
  tmp = (real32_T)floor(prova_LOG_AHRS_09_23_P.Gain_Gain_m *
                        prova_LOG_AHRS_09_23_B.ByteReversal[8]);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion3_k[8] = (int16_T)(tmp < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion10' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion10 =
    prova_LOG_AHRS_09_23_B.DataTypeConversion2;

  /* DataTypeConversion: '<S2>/Data Type Conversion11' incorporates:
   *  Gain: '<S2>/Gain2'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion11[0] = (uint16_T)
    ((prova_LOG_AHRS_09_23_P.Gain2_Gain_p *
      prova_LOG_AHRS_09_23_B.DataTypeConversion1_g[0]) >> 8);
  prova_LOG_AHRS_09_23_B.DataTypeConversion11[1] = (uint16_T)
    ((prova_LOG_AHRS_09_23_P.Gain2_Gain_p *
      prova_LOG_AHRS_09_23_B.DataTypeConversion1_g[1]) >> 8);
  prova_LOG_AHRS_09_23_B.DataTypeConversion11[2] = (uint16_T)
    ((prova_LOG_AHRS_09_23_P.Gain2_Gain_p *
      prova_LOG_AHRS_09_23_B.DataTypeConversion1_g[2]) >> 8);

  /* DataTypeConversion: '<S2>/Data Type Conversion12' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant_Value_or);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion12' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion12 = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion13' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant3_Value_mm);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion13' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion13 = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion14' incorporates:
   *  Constant: '<S2>/Constant7'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant7_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion14' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion14 = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion15' incorporates:
   *  Constant: '<S2>/Constant8'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant8_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion15' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion15 = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion21' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant9_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion21' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion21 = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion20' incorporates:
   *  Constant: '<S2>/Constant6'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant6_Value_k);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion20' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion20 = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion19' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant1_Value_ja);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion19' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion19 = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion18' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Gain: '<S2>/Gain3'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Gain3_Gain *
    prova_LOG_AHRS_09_23_P.Constant5_Value);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion18' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion18 = (uint16_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)
    (uint16_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion7' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant4_Value_j);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion7'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion8[0] = (uint8_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-rtb_RateTransition : (int32_T)
    (uint8_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_RateTransition = floor(prova_LOG_AHRS_09_23_P.Constant3_Value_j);
  if (rtIsNaN(rtb_RateTransition) || rtIsInf(rtb_RateTransition)) {
    rtb_RateTransition = 0.0;
  } else {
    rtb_RateTransition = fmod(rtb_RateTransition, 256.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion5'
   */
  prova_LOG_AHRS_09_23_B.DataTypeConversion8[1] = (uint8_T)(rtb_RateTransition <
    0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-rtb_RateTransition : (int32_T)
    (uint8_T)rtb_RateTransition);

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  tmp = (real32_T)floor(prova_LOG_AHRS_09_23_B.DataTypeConversion_k);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  prova_LOG_AHRS_09_23_B.DataTypeConversion9 = tmp < 0.0F ? (uint32_T)-(int32_T)
    (uint32_T)-tmp : (uint32_T)tmp;

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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_P.InizioMSG_Value[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion6[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion3_k[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion10, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion11[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion12, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion13, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion14, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion15, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion21, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion20, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion19, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion18, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion8[0], MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_B.DataTypeConversion9, MW_inputPortWidth);
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
      memcpy((uint8_T*)((uint8_T*)&prova_LOG_AHRS_09_23_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &prova_LOG_AHRS_09_23_P.FineMSG1_Value, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S2>/Serial Transmit1' */
  if (prova_LOG_AHRS_09_23_DW.obj.Protocol !=
      prova_LOG_AHRS_09_23_P.SerialTransmit1_Protocol) {
    prova_LOG_AHRS_09_23_DW.obj.Protocol =
      prova_LOG_AHRS_09_23_P.SerialTransmit1_Protocol;
  }

  memcpy(&prova_LOG_AHRS_09_23_B.dataIn[0], &prova_LOG_AHRS_09_23_B.BytePack[0],
         67U * sizeof(uint8_T));
  MW_Serial_write(prova_LOG_AHRS_09_23_DW.obj.port,
                  &prova_LOG_AHRS_09_23_B.dataIn[0], 67.0,
                  prova_LOG_AHRS_09_23_DW.obj.dataSizeInBytes,
                  prova_LOG_AHRS_09_23_DW.obj.sendModeEnum,
                  prova_LOG_AHRS_09_23_DW.obj.dataType,
                  prova_LOG_AHRS_09_23_DW.obj.sendFormatEnum, 2.0, '\x00');

  /* End of MATLABSystem: '<S2>/Serial Transmit1' */

  /* Update for Memory: '<S1>/Memory4' */
  memcpy(&prova_LOG_AHRS_09_23_DW.Memory4_PreviousInput[0],
         &prova_LOG_AHRS_09_23_B.buffer[0], 300U * sizeof(uint8_T));

  /* Update for S-Function (Mti): '<S3>/S-Function Builder' */

  /* S-Function "Mti_wrapper" Block: <S3>/S-Function Builder */
  Mti_Update_wrapper(&prova_LOG_AHRS_09_23_B.SFunctionBuilder[0],
                     &prova_LOG_AHRS_09_23_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<S1>/Constant1'
   */

  /* S-Function "Seriale_mav_wrapper" Block: <S1>/S-Function Builder */
  Seriale_mav_Update_wrapper(&prova_LOG_AHRS_09_23_P.Constant1_Value_if,
    &prova_LOG_AHRS_09_23_B.SFunctionBuilder_o1[0],
    &prova_LOG_AHRS_09_23_B.SFunctionBuilder_o2,
    &prova_LOG_AHRS_09_23_DW.SFunctionBuilder_DSTATE_n);

  /* Update for Memory: '<S1>/Memory5' */
  memcpy(&prova_LOG_AHRS_09_23_DW.Memory5_PreviousInput[0],
         &prova_LOG_AHRS_09_23_B.mess_out[0], 100U * sizeof(uint8_T));

  /* Update for Memory: '<Root>/Memory' */
  prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[0] =
    prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[0];
  prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[1] =
    prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[1];
  prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[2] =
    prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[2];
  prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[3] =
    prova_LOG_AHRS_09_23_B.DataTypeConversion1_n[3];

  /* Update for Memory: '<S1>/Memory' */
  for (caso = 0; caso < 8; caso++) {
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_c[caso] =
      prova_LOG_AHRS_09_23_B.SFunction_o11[caso];
  }

  /* End of Update for Memory: '<S1>/Memory' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput_i[0] = (uint8_T)AP_mode_idx_0;
  prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput_i[1] = (uint8_T)AP_mode_idx_1;
  for (caso = 0; caso < 7; caso++) {
    tmp = rt_roundf_snf(prova_LOG_AHRS_09_23_DW.riferimenti[caso]);
    if (tmp < 256.0F) {
      if (tmp >= 0.0F) {
        prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput_i[caso + 2] = (uint8_T)tmp;
      } else {
        prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput_i[caso + 2] = 0U;
      }
    } else {
      prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput_i[caso + 2] = MAX_uint8_T;
    }
  }

  /* End of Update for Memory: '<S1>/Memory2' */

  /* Update for Memory: '<S2>/Memory' */
  prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_c2 =
    prova_LOG_AHRS_09_23_B.SFunction_o4;
}

/* Model step function for TID1 */
void prova_LOG_AHRS_09_23_step1(void)  /* Sample time: [0.1s, 0.0s] */
{
  /* Sum: '<S23>/Add2' incorporates:
   *  Constant: '<S23>/Constant4'
   *  Constant: '<S23>/Constant5'
   *  Memory: '<S23>/Memory2'
   */
  prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput +=
    prova_LOG_AHRS_09_23_P.Constant4_Value_f +
    prova_LOG_AHRS_09_23_P.Constant5_Value_e;

  /* Switch: '<S23>/Switch1' */
  if (prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput >
      prova_LOG_AHRS_09_23_P.Switch1_Threshold) {
    /* Sum: '<S23>/Add2' incorporates:
     *  Constant: '<S23>/Constant4'
     */
    prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput =
      prova_LOG_AHRS_09_23_P.Constant4_Value_f;
  }

  /* End of Switch: '<S23>/Switch1' */

  /* RateTransition: '<S23>/Rate Transition' */
  prova_LOG_AHRS_09_23_DW.RateTransition_Buffer0 =
    prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput;
}

/* Model initialize function */
void prova_LOG_AHRS_09_23_initialize(void)
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

    /* Start for S-Function (Mti): '<S3>/S-Function Builder' */

    /* S-Function Block: <S3>/S-Function Builder */
    Mti_Start_wrapper(&prova_LOG_AHRS_09_23_DW.SFunctionBuilder_DSTATE);

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    memcpy(&prova_LOG_AHRS_09_23_DW.Memory4_PreviousInput[0],
           &prova_LOG_AHRS_09_23_P.Memory4_InitialCondition[0], 300U * sizeof
           (uint8_T));

    /* InitializeConditions for S-Function (Mti): '<S3>/S-Function Builder' */

    /* S-Function Block: <S3>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          prova_LOG_AHRS_09_23_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for S-Function (Seriale_mav): '<S1>/S-Function Builder' incorporates:
     *  Constant: '<S1>/Constant1'
     */

    /* S-Function Block: <S1>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          prova_LOG_AHRS_09_23_DW.SFunctionBuilder_DSTATE_n = initVector[0];
        }
      }
    }

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    for (i = 0; i < 100; i++) {
      prova_LOG_AHRS_09_23_DW.Memory5_PreviousInput[i] =
        prova_LOG_AHRS_09_23_P.Memory5_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory5' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[0] =
      prova_LOG_AHRS_09_23_P.Memory1_InitialCondition_j;
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput_c[1] =
      prova_LOG_AHRS_09_23_P.Memory1_InitialCondition_j;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[0] =
      prova_LOG_AHRS_09_23_P.Memory_InitialCondition_i;
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[1] =
      prova_LOG_AHRS_09_23_P.Memory_InitialCondition_i;
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[2] =
      prova_LOG_AHRS_09_23_P.Memory_InitialCondition_i;
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_k[3] =
      prova_LOG_AHRS_09_23_P.Memory_InitialCondition_i;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    prova_LOG_AHRS_09_23_DW.Memory3_PreviousInput =
      prova_LOG_AHRS_09_23_P.Memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 8; i++) {
      prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_c[i] =
        prova_LOG_AHRS_09_23_P.Memory_InitialCondition_l;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 9; i++) {
      prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput_i[i] =
        prova_LOG_AHRS_09_23_P.Memory2_InitialCondition_j[i];
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for RateTransition: '<S23>/Rate Transition' */
    prova_LOG_AHRS_09_23_DW.RateTransition_Buffer0 =
      prova_LOG_AHRS_09_23_P.RateTransition_InitialCondition;

    /* InitializeConditions for DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Memory: '<S23>/Memory1'
     */
    prova_LOG_AHRS_09_23_DW.Memory1_PreviousInput =
      prova_LOG_AHRS_09_23_P.Memory1_InitialCondition;

    /* InitializeConditions for Sum: '<S23>/Add' incorporates:
     *  Memory: '<S23>/Memory'
     */
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput =
      prova_LOG_AHRS_09_23_P.Memory_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    prova_LOG_AHRS_09_23_DW.Memory_PreviousInput_c2 =
      prova_LOG_AHRS_09_23_P.Memory_InitialCondition_m;

    /* InitializeConditions for Sum: '<S23>/Add2' incorporates:
     *  Memory: '<S23>/Memory2'
     */
    prova_LOG_AHRS_09_23_DW.Memory2_PreviousInput =
      prova_LOG_AHRS_09_23_P.Memory2_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
    memcpy(&prova_LOG_AHRS_09_23_DW.riferimenti[0], &tmp[0], sizeof(real32_T) <<
           4U);

    /* SystemInitialize for Enabled SubSystem: '<S2>/Enable ' */
    /* SystemInitialize for Chart: '<S8>/Chart' incorporates:
     *  SubSystem: '<S20>/sendbyte'
     */
    /* Start for MATLABSystem: '<S21>/Serial Transmit' */
    prova_LOG_AHRS_09_23_DW.obj_f.matlabCodegenIsDeleted = false;
    prova_LOG_AHRS_09_23_DW.obj_f.Protocol =
      prova_LOG_AHRS_09_23_P.SerialTransmit_Protocol;
    prova_LOG_AHRS_09_23_DW.obj_f.isInitialized = 1;
    prova_LOG_AHRS_09_23_DW.obj_f.port = 2.0;
    prova_LOG_AHRS_09_23_DW.obj_f.dataSizeInBytes = 1.0;
    prova_LOG_AHRS_09_23_DW.obj_f.dataType = 0.0;
    prova_LOG_AHRS_09_23_DW.obj_f.sendModeEnum = 0.0;
    prova_LOG_AHRS_09_23_DW.obj_f.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(prova_LOG_AHRS_09_23_DW.obj_f.port);
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
    prova_LOG_AHRS_09_23_DW.obj_f.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S21>/Serial Transmit' */
    /* End of SystemInitialize for SubSystem: '<S2>/Enable ' */

    /* Start for MATLABSystem: '<S2>/Serial Transmit1' */
    prova_LOG_AHRS_09_23_DW.obj.matlabCodegenIsDeleted = false;
    prova_LOG_AHRS_09_23_DW.obj.Protocol =
      prova_LOG_AHRS_09_23_P.SerialTransmit1_Protocol;
    prova_LOG_AHRS_09_23_DW.obj.isInitialized = 1;
    prova_LOG_AHRS_09_23_DW.obj.port = 0.0;
    prova_LOG_AHRS_09_23_DW.obj.dataSizeInBytes = 1.0;
    prova_LOG_AHRS_09_23_DW.obj.dataType = 0.0;
    prova_LOG_AHRS_09_23_DW.obj.sendModeEnum = 0.0;
    prova_LOG_AHRS_09_23_DW.obj.sendFormatEnum = 0.0;
    tmp_0 = rt_roundd_snf(prova_LOG_AHRS_09_23_DW.obj.port);
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
    prova_LOG_AHRS_09_23_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/Serial Transmit1' */
  }
}

/* Model terminate function */
void prova_LOG_AHRS_09_23_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<S2>/Enable ' */
  /* Terminate for Chart: '<S8>/Chart' incorporates:
   *  SubSystem: '<S20>/sendbyte'
   */
  /* Terminate for MATLABSystem: '<S21>/Serial Transmit' */
  if (!prova_LOG_AHRS_09_23_DW.obj_f.matlabCodegenIsDeleted) {
    prova_LOG_AHRS_09_23_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S21>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S2>/Enable ' */

  /* Terminate for MATLABSystem: '<S2>/Serial Transmit1' */
  if (!prova_LOG_AHRS_09_23_DW.obj.matlabCodegenIsDeleted) {
    prova_LOG_AHRS_09_23_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
