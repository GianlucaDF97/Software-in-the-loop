/*
 * loaddspace.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "loaddspace".
 *
 * Model version              : 1.59
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Oct 25 15:41:33 2021
 *
 * Target selection: rti1006.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "loaddspace_trc_ptr.h"
#include "loaddspace.h"
#include "loaddspace_private.h"

/* Block signals (default storage) */
B_loaddspace_T loaddspace_B;

/* Continuous states */
X_loaddspace_T loaddspace_X;

/* Block states (default storage) */
DW_loaddspace_T loaddspace_DW;

/* Periodic continuous states */
PeriodicIndX_loaddspace_T loaddspace_PeriodicIndX;
PeriodicRngX_loaddspace_T loaddspace_PeriodicRngX;

/* Real-time model */
static RT_MODEL_loaddspace_T loaddspace_M_;
RT_MODEL_loaddspace_T *const loaddspace_M = &loaddspace_M_;
static void rate_scheduler(void);

/*     Initialize pressure and temperature tables. */
void InitCalcAtmosCOESA(real_T *temperature76, real_T *pressureRatio76)
{
  if (temperature76[0] != TEMPERATURE0 ) {
    int_T k;
    temperature76[0] = TEMPERATURE0;
    pressureRatio76[0] = 1.0;

    /* set up the data at the 1976 altitude breakpoints */
    for (k=0; k<(NUM1976PTS-1); k++) {
      if (tempGradient76[k] != 0.0) {
        temperature76[k+1] = temperature76[k] +
          tempGradient76[k]*(altitude76[k+1] - altitude76[k]);
        pressureRatio76[k+1] = pressureRatio76[k] *
          exp(log(temperature76[k]/temperature76[k+1]) * GMR/tempGradient76[k]);
      } else {
        temperature76[k+1] = temperature76[k];
        pressureRatio76[k+1] = pressureRatio76[k] *
          exp((-GMR)*(altitude76[k+1] - altitude76[k])/temperature76[k]);
      }
    }
  }
}

/*
 *     Using cached pressure and Altitude tables, find the working interval
 *     and perform logarithmic interpolation.
 */
void CalcPAltCOESA(const real_T *pressure, real_T *altitude, real_T
                   *temperature76, real_T *pressureRatio76, int_T numPoints)
{
  int_T i;
  real_T ptemp;
  for (i=0; i<numPoints; i++) {
    int_T bottom = 0;
    int_T top = NUM1976PTS-1;
    int_T idx;

    /* Find altitude interval using binary search
     *
     * Deal with the extreme cases first:
     *   if pressure >= pressureRatio76[bottom]*PRESSURE0
     *   then return idx = bottom
     *
     *   if pressure <= pressureRatio76[top]*PRESSURE0
     *   then return idx = top
     */
    if (pressure[i] >= pressureRatio76[bottom]*PRESSURE0) {
      idx = bottom;
    } else if (pressure[i] <= pressureRatio76[top]*PRESSURE0) {
      idx = NUM1976PTS-2;
    } else {
      for (;;) {
        idx = (bottom + top)/2;
        if (pressure[i] > pressureRatio76[idx]*PRESSURE0) {
          top = idx - 1;
        } else if (pressure[i] <= pressureRatio76[idx+1]*PRESSURE0) {
          bottom = idx + 1;
        } else {
          /* we have pressureRatio76[idx]*PRESSURE0 >= pressure[i] >
           *                          pressureRatio76[idx+1]*PRESSURE0,
           * so break and just use idx
           */
          break;
        }
      }
    }

    /* Interval has been obtained, now do log altitude interpolation.
     */
    if (pressure[i] == (PRESSURE0 * pressureRatio76[idx])) {
      altitude[i] = altitude76[idx];
    } else {
      if (tempGradient76[idx] != 0.0 ) {
        ptemp = (rt_powd_snf(pressure[i]/(PRESSURE0 * pressureRatio76[idx]),
                             (tempGradient76[idx]/GMR)));
        altitude[i] = altitude76[idx] + ((1.0 - ptemp)/
          (tempGradient76[idx] * ptemp))*temperature76[idx];
      } else {
        altitude[i] = altitude76[idx]-((temperature76[idx]/GMR)*
          log(pressure[i]/(PRESSURE0 * pressureRatio76[idx])));
      }
    }
  }
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (loaddspace_M->Timing.TaskCounters.TID[2])++;
  if ((loaddspace_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.02s, 0.0s] */
    loaddspace_M->Timing.TaskCounters.TID[2] = 0;
  }

  (loaddspace_M->Timing.TaskCounters.TID[3])++;
  if ((loaddspace_M->Timing.TaskCounters.TID[3]) > 9) {/* Sample time: [0.1s, 0.0s] */
    loaddspace_M->Timing.TaskCounters.TID[3] = 0;
  }

  (loaddspace_M->Timing.TaskCounters.TID[4])++;
  if ((loaddspace_M->Timing.TaskCounters.TID[4]) > 19) {/* Sample time: [0.2s, 0.0s] */
    loaddspace_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 21;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  loaddspace_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  loaddspace_output();
  loaddspace_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  loaddspace_output();
  loaddspace_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  loaddspace_output();
  loaddspace_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  local_stateReduction(x, rtsiGetPeriodicContStateIndices(si), 3,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
void loaddspac_FunctionCallSubsystem(void)
{
  /* S-Function (rti_commonblock): '<S88>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:TRANSMIT */
  {
    UInt32 txFifoLevel;
    UInt32 bytesRefNumOf;
    bytesRefNumOf = (loaddspace_P.SFunction1_BytesRefNumOf_p <= 41) ?
      loaddspace_P.SFunction1_BytesRefNumOf_p : 41;
    txFifoLevel = dsser_transmit_fifo_level(rtiDS4201SER_B1_Ser[0]);
    if (((rtiDS4201SER_B1_Ser[0]->fifo_size) - txFifoLevel) > bytesRefNumOf) {
      UInt32 bytesActNumOfAddr;
      dsser_transmit(rtiDS4201SER_B1_Ser[0], bytesRefNumOf,
                     &loaddspace_B.RateTransition_e[0], &(bytesActNumOfAddr));
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S112>/MATLAB Function'
 *    '<S121>/MATLAB Function'
 */
void loaddspace_MATLABFunction(const real_T rtu_degree[43], const real_T
  rtu_microsec[43], real_T rtu_input, real_T rtu_flag,
  B_MATLABFunction_loaddspace_T *localB)
{
  real_T K;
  int32_T b_i;

  /* MATLAB Function 'Subsystem1/AILERON/MATLAB Function': '<S123>:1' */
  /* '<S123>:1:16' */
  K = 0.0;

  /* '<S123>:1:17' */
  localB->C = 0.0;
  if (rtu_flag == 1.0) {
    /* '<S123>:1:18' */
    if ((rtu_input <= rtu_degree[42]) && (rtu_input >= rtu_degree[0])) {
      /* '<S123>:1:19' */
      /* '<S123>:1:20' */
      for (b_i = 0; b_i < 42; b_i++) {
        /* '<S123>:1:20' */
        if ((rtu_input >= rtu_degree[b_i]) && (rtu_input <= rtu_degree[b_i + 1]))
        {
          /* '<S123>:1:21' */
          /* '<S123>:1:22' */
          K = (rtu_microsec[b_i + 1] - rtu_microsec[b_i]) / (rtu_degree[b_i + 1]
            - rtu_degree[b_i]);

          /* '<S123>:1:23' */
          localB->C = -K * rtu_degree[b_i] + rtu_microsec[b_i];
        }
      }
    } else if (rtu_input > rtu_degree[42]) {
      /* '<S123>:1:27' */
      /* '<S123>:1:28' */
      K = (rtu_microsec[42] - rtu_microsec[41]) / (rtu_degree[42] - rtu_degree
        [41]);

      /* '<S123>:1:29' */
      localB->C = -K * rtu_degree[41] + rtu_microsec[41];
    } else {
      if (rtu_input < rtu_degree[0]) {
        /* '<S123>:1:30' */
        /* '<S123>:1:31' */
        K = (rtu_microsec[1] - rtu_microsec[0]) / (rtu_degree[1] - rtu_degree[0]);

        /* '<S123>:1:32' */
        localB->C = -K * rtu_degree[0] + rtu_microsec[0];
      }
    }
  } else {
    if (rtu_flag == 0.0) {
      /* '<S123>:1:34' */
      if ((rtu_input <= rtu_microsec[42]) && (rtu_input >= rtu_microsec[0])) {
        /* '<S123>:1:35' */
        /* '<S123>:1:36' */
        for (b_i = 0; b_i < 42; b_i++) {
          /* '<S123>:1:36' */
          if ((rtu_input >= rtu_microsec[b_i]) && (rtu_input <= rtu_microsec[b_i
               + 1])) {
            /* '<S123>:1:37' */
            /* '<S123>:1:38' */
            K = (rtu_degree[b_i + 1] - rtu_degree[b_i]) / (rtu_microsec[b_i + 1]
              - rtu_microsec[b_i]);

            /* '<S123>:1:39' */
            localB->C = -K * rtu_microsec[b_i] + rtu_degree[b_i];
          }
        }
      } else if (rtu_input > rtu_microsec[42]) {
        /* '<S123>:1:42' */
        /* '<S123>:1:43' */
        K = (rtu_degree[42] - rtu_degree[41]) / (rtu_microsec[42] -
          rtu_microsec[41]);

        /* '<S123>:1:44' */
        localB->C = -K * rtu_microsec[42] + rtu_degree[42];
      } else {
        if (rtu_input < rtu_microsec[0]) {
          /* '<S123>:1:45' */
          /* '<S123>:1:46' */
          K = (rtu_degree[1] - rtu_degree[0]) / (rtu_microsec[1] - rtu_microsec
            [0]);

          /* '<S123>:1:47' */
          localB->C = -K * rtu_microsec[42] + rtu_degree[42];
        }
      }
    }
  }

  localB->K = K;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else {
      if ((u0 < 0.0) != (u1 < 0.0)) {
        y += u1;
      }
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

void rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(const real_T u0[3], const real_T u1[9],
  real_T y[3])
{
  real_T u1_0[9];
  real_T a21;
  real_T maxval;
  real_T u0_idx_0;
  real_T u0_idx_1;
  real_T u0_idx_2;
  real_T x;
  int32_T ONE;
  int32_T THREE;
  int32_T r1;
  int32_T r2;
  u0_idx_0 = u0[0];
  u0_idx_1 = u0[1];
  u0_idx_2 = u0[2];
  memcpy(&u1_0[0], &u1[0], 9U * sizeof(real_T));
  THREE = 2;
  r1 = 0;
  r2 = 1;
  x = u1_0[0];
  x = fabs(x);
  maxval = x;
  x = u1_0[1];
  x = fabs(x);
  a21 = x;
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  x = u1_0[2];
  x = fabs(x);
  a21 = x;
  if (a21 > maxval) {
    r1 = 2;
    r2 = 1;
    THREE = 0;
  }

  u1_0[r2] /= u1_0[r1];
  u1_0[THREE] /= u1_0[r1];
  u1_0[r2 + 3] -= u1_0[r1 + 3] * u1_0[r2];
  u1_0[THREE + 3] -= u1_0[r1 + 3] * u1_0[THREE];
  u1_0[r2 + 6] -= u1_0[r1 + 6] * u1_0[r2];
  u1_0[THREE + 6] -= u1_0[r1 + 6] * u1_0[THREE];
  x = u1_0[THREE + 3];
  x = fabs(x);
  a21 = x;
  x = u1_0[r2 + 3];
  x = fabs(x);
  maxval = x;
  if (a21 > maxval) {
    ONE = r2 + 1;
    r2 = THREE;
    THREE = ONE - 1;
  }

  u1_0[THREE + 3] /= u1_0[r2 + 3];
  u1_0[THREE + 6] -= u1_0[THREE + 3] * u1_0[r2 + 6];
  y[r1] = u0_idx_0 / u1_0[r1];
  y[r2] = u0_idx_1 - u1_0[r1 + 3] * y[r1];
  y[THREE] = u0_idx_2 - u1_0[r1 + 6] * y[r1];
  y[r2] /= u1_0[r2 + 3];
  y[THREE] -= u1_0[r2 + 6] * y[r2];
  y[THREE] /= u1_0[THREE + 6];
  y[r2] -= u1_0[THREE + 3] * y[THREE];
  y[r1] -= y[THREE] * u1_0[THREE];
  y[r1] -= y[r2] * u1_0[r2];
}

/* Model output function */
void loaddspace_output(void)
{
  real_T T_eb[9];
  real_T T_phi[9];
  real_T dcmt[9];
  real_T Fape[3];
  real_T Mape[3];
  real_T Ve[3];
  real_T ratese[3];
  real_T v_re[3];
  real_T Frmd;
  real_T Frms;
  real_T Fsd;
  real_T Fss;
  real_T Mye;
  real_T b_fmod;
  real_T b_s;
  real_T diffLm;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_4;
  real_T tmp_5;
  real_T tmp_6;
  real_T tmp_7;
  real_T tmp_8;
  real_T tmp_9;
  real_T tmp_a;
  real_T tmp_b;
  real_T tmp_c;
  real_T tmp_d;
  real_T tmp_e;
  real_T tmp_f;
  real_T tmp_g;
  real_T u0;
  real_T u1;
  real_T u2;
  int32_T aoffset;
  int32_T coffset;
  int32_T i;
  int32_T iU;
  if (rtmIsMajorTimeStep(loaddspace_M)) {
    /* set solver stop time */
    if (!(loaddspace_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&loaddspace_M->solverInfo,
                            ((loaddspace_M->Timing.clockTickH0 + 1) *
        loaddspace_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&loaddspace_M->solverInfo,
                            ((loaddspace_M->Timing.clockTick0 + 1) *
        loaddspace_M->Timing.stepSize0 + loaddspace_M->Timing.clockTickH0 *
        loaddspace_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(loaddspace_M)) {
    loaddspace_M->Timing.t[0] = rtsiGetT(&loaddspace_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S5>/S-Function1' */
    /* This comment workarounds a code generation problem */
  }

  /* Integrator: '<S26>/ub,vb,wb' */
  /* Unit Conversion - from: m/s to: m/s
     Expression: output = (1*input) + (0) */
  loaddspace_B.ubvbwb[0] = loaddspace_X.ubvbwb_CSTATE[0];

  /* UnitConversion: '<S40>/Unit Conversion' */
  loaddspace_B.UnitConversion[0] = loaddspace_B.ubvbwb[0];

  /* Sum: '<S34>/Sum2' incorporates:
   *  Constant: '<S14>/Winds'
   */
  loaddspace_B.Va[0] = loaddspace_B.UnitConversion[0] -
    loaddspace_P.wind_constant[0];

  /* Integrator: '<S26>/ub,vb,wb' */
  loaddspace_B.ubvbwb[1] = loaddspace_X.ubvbwb_CSTATE[1];

  /* UnitConversion: '<S40>/Unit Conversion' */
  loaddspace_B.UnitConversion[1] = loaddspace_B.ubvbwb[1];

  /* Sum: '<S34>/Sum2' incorporates:
   *  Constant: '<S14>/Winds'
   */
  loaddspace_B.Va[1] = loaddspace_B.UnitConversion[1] -
    loaddspace_P.wind_constant[1];

  /* Integrator: '<S26>/ub,vb,wb' */
  loaddspace_B.ubvbwb[2] = loaddspace_X.ubvbwb_CSTATE[2];

  /* UnitConversion: '<S40>/Unit Conversion' */
  loaddspace_B.UnitConversion[2] = loaddspace_B.ubvbwb[2];

  /* Sum: '<S34>/Sum2' incorporates:
   *  Constant: '<S14>/Winds'
   */
  loaddspace_B.Va[2] = loaddspace_B.UnitConversion[2] -
    loaddspace_P.wind_constant[2];

  /* MATLAB Function: '<S34>/MATLAB Function' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Velocità1/MATLAB Function': '<S77>:1' */
  /* '<S77>:1:5' */
  loaddspace_B.module = (loaddspace_B.Va[0] * loaddspace_B.Va[0] +
    loaddspace_B.Va[1] * loaddspace_B.Va[1]) + loaddspace_B.Va[2] *
    loaddspace_B.Va[2];
  loaddspace_B.module = sqrt(loaddspace_B.module);

  /* Switch: '<S127>/Switch1' */
  if (loaddspace_B.module > loaddspace_P.Switch1_Threshold) {
    /* Switch: '<S127>/Switch1' incorporates:
     *  Constant: '<S127>/Constant3'
     */
    loaddspace_B.Switch1 = loaddspace_P.Constant3_Value;
  } else {
    /* Switch: '<S127>/Switch1' */
    loaddspace_B.Switch1 = loaddspace_B.module;
  }

  /* End of Switch: '<S127>/Switch1' */

  /* MATLAB Function: '<S21>/MATLAB Function' */
  /* MATLAB Function 'scalatura velocità/MATLAB Function': '<S126>:1' */
  /* '<S126>:1:4' */
  /* '<S126>:1:5' */
  loaddspace_B.deltaP = loaddspace_B.Switch1 * loaddspace_B.Switch1 * 1.225 /
    2.0;

  /* Gain: '<S128>/m_deltaP_to_volt' */
  loaddspace_B.m_deltaP_to_volt = loaddspace_P.m_deltaP_to_volt_Gain *
    loaddspace_B.deltaP;

  /* Sum: '<S128>/Sum' incorporates:
   *  Constant: '<S128>/q_deltaP_to_volt'
   */
  loaddspace_B.Sum = loaddspace_B.m_deltaP_to_volt +
    loaddspace_P.q_deltaP_to_volt_Value;

  /* Gain: '<S21>/Gain' */
  loaddspace_B.Gain = loaddspace_P.Gain_Gain * loaddspace_B.Sum;
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S5>/S-Function2' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS2101 #1 Unit:DAC Group:CHANNEL2 */
    ds2101_out(DS2101_1_BASE, 2, (dsfloat) loaddspace_B.Gain);

    /* S-Function (rti_commonblock): '<S5>/S-Function3' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S5>/S-Function4' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S5>/S-Function5' */
    /* This comment workarounds a code generation problem */
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* RandomNumber: '<S18>/White_press' */
    loaddspace_B.White_press = loaddspace_DW.NextOutput;
  }

  /* Integrator: '<S83>/Position Integrator2' */
  loaddspace_B.PositionIntegrator2[0] = loaddspace_X.PositionIntegrator2_CSTATE
    [0];
  loaddspace_B.PositionIntegrator2[1] = loaddspace_X.PositionIntegrator2_CSTATE
    [1];
  loaddspace_B.PositionIntegrator2[2] = loaddspace_X.PositionIntegrator2_CSTATE
    [2];

  /* Saturate: '<S95>/Limit  altitude  to troposhere' */
  u0 = loaddspace_B.PositionIntegrator2[2];
  u1 = loaddspace_P.Limitaltitudetotroposhere_Lower;
  u2 = loaddspace_P.Limitaltitudetotroposhere_Upper;
  if (u0 > u2) {
    /* Saturate: '<S95>/Limit  altitude  to troposhere' */
    loaddspace_B.Limitaltitudetotroposhere = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S95>/Limit  altitude  to troposhere' */
    loaddspace_B.Limitaltitudetotroposhere = u1;
  } else {
    /* Saturate: '<S95>/Limit  altitude  to troposhere' */
    loaddspace_B.Limitaltitudetotroposhere = u0;
  }

  /* End of Saturate: '<S95>/Limit  altitude  to troposhere' */

  /* Gain: '<S95>/Lapse Rate' */
  loaddspace_B.LapseRate = loaddspace_P.LapseRate_Gain *
    loaddspace_B.Limitaltitudetotroposhere;

  /* Sum: '<S95>/Sum1' incorporates:
   *  Constant: '<S95>/Sea Level  Temperature'
   */
  loaddspace_B.Sum1 = loaddspace_P.SeaLevelTemperature_Value -
    loaddspace_B.LapseRate;

  /* Gain: '<S95>/1//T0' */
  loaddspace_B.uT0 = loaddspace_P.uT0_Gain * loaddspace_B.Sum1;

  /* Math: '<S95>/(T//T0)^(g//LR) ' incorporates:
   *  Constant: '<S95>/Constant'
   */
  b_fmod = loaddspace_B.uT0;
  b_s = loaddspace_P.Constant_Value_i;
  if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
    /* Math: '<S95>/(T//T0)^(g//LR) ' */
    loaddspace_B.TT0gLR = -rt_powd_snf(-b_fmod, b_s);
  } else {
    /* Math: '<S95>/(T//T0)^(g//LR) ' */
    loaddspace_B.TT0gLR = rt_powd_snf(b_fmod, b_s);
  }

  /* End of Math: '<S95>/(T//T0)^(g//LR) ' */

  /* Gain: '<S95>/P0' */
  loaddspace_B.P0 = loaddspace_P.P0_Gain * loaddspace_B.TT0gLR;

  /* Sum: '<S95>/Sum' incorporates:
   *  Constant: '<S95>/Altitude of Troposphere'
   */
  loaddspace_B.Sum_h = loaddspace_P.AltitudeofTroposphere_Value -
    loaddspace_B.PositionIntegrator2[2];

  /* Saturate: '<S95>/Limit  altitude  to Stratosphere' */
  u0 = loaddspace_B.Sum_h;
  u1 = loaddspace_P.LimitaltitudetoStratosphere_Low;
  u2 = loaddspace_P.LimitaltitudetoStratosphere_Upp;
  if (u0 > u2) {
    /* Saturate: '<S95>/Limit  altitude  to Stratosphere' */
    loaddspace_B.LimitaltitudetoStratosphere = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S95>/Limit  altitude  to Stratosphere' */
    loaddspace_B.LimitaltitudetoStratosphere = u1;
  } else {
    /* Saturate: '<S95>/Limit  altitude  to Stratosphere' */
    loaddspace_B.LimitaltitudetoStratosphere = u0;
  }

  /* End of Saturate: '<S95>/Limit  altitude  to Stratosphere' */

  /* Gain: '<S95>/g//R' */
  loaddspace_B.gR = loaddspace_P.gR_Gain *
    loaddspace_B.LimitaltitudetoStratosphere;

  /* Product: '<S95>/Product1' */
  loaddspace_B.Product1 = 1.0 / loaddspace_B.Sum1 * loaddspace_B.gR;

  /* Math: '<S95>/Stratosphere Model'
   *
   * About '<S95>/Stratosphere Model':
   *  Operator: exp
   */
  loaddspace_B.StratosphereModel = exp(loaddspace_B.Product1);

  /* Product: '<S95>/Product2' */
  loaddspace_B.Product2 = loaddspace_B.P0 * loaddspace_B.StratosphereModel;

  /* RateTransition: '<S18>/Rate Transition' */
  if ((rtmIsMajorTimeStep(loaddspace_M) &&
       loaddspace_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
       (loaddspace_M) &&
       loaddspace_M->Timing.TaskCounters.TID[2] == 0)) {
    loaddspace_DW.RateTransition_Buffer = loaddspace_B.Product2;
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* RateTransition: '<S18>/Rate Transition' */
    loaddspace_B.RateTransition = loaddspace_DW.RateTransition_Buffer;

    /* Sum: '<S18>/Sum13' */
    loaddspace_B.Sum13 = loaddspace_B.White_press + loaddspace_B.RateTransition;

    /* Lookup_n-D: '<S18>/1-D Lookup Table' incorporates:
     *  Sum: '<S18>/Sum13'
     */
    loaddspace_B.uDLookupTable = look1_binlxpw(loaddspace_B.Sum13,
      loaddspace_P.p_bmp, loaddspace_P.adc_P_bmp, 16362U);

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    tmp_f = floor(loaddspace_B.uDLookupTable);
    if (rtIsNaN(tmp_f) || rtIsInf(tmp_f)) {
      tmp_f = 0.0;
    } else {
      tmp_f = fmod(tmp_f, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    loaddspace_B.DataTypeConversion_m = tmp_f < 0.0 ? -(int32_T)(uint32_T)-tmp_f
      : (int32_T)(uint32_T)tmp_f;

    /* S-Function (any2byte_svd): '<S18>/Byte Pack1' */

    /* Pack: <S18>/Byte Pack1 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - int32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(int32_T);
        memcpy((uint8_T*)((uint8_T*)&loaddspace_B.BytePack1[0] +
                          MW_outputPortOffset), (uint8_T*)
               &loaddspace_B.DataTypeConversion_m, MW_inputPortWidth);
      }
    }

    /* RandomNumber: '<S18>/White Noise4' */
    loaddspace_B.WhiteNoise4 = loaddspace_DW.NextOutput_a;
  }

  /* End of RateTransition: '<S18>/Rate Transition' */

  /* Integrator: '<S36>/phi theta psi' */
  loaddspace_B.phithetapsi[0] = loaddspace_X.phithetapsi_CSTATE[0];
  loaddspace_B.phithetapsi[1] = loaddspace_X.phithetapsi_CSTATE[1];
  loaddspace_B.phithetapsi[2] = loaddspace_X.phithetapsi_CSTATE[2];
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S92>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:RECEIVE */
    {
      UInt32 bytesActNumOfAddr;
      UInt32 bytesRefNumOf;
      bytesRefNumOf = (loaddspace_P.SFunction1_BytesRefNumOf <= 8) ?
        loaddspace_P.SFunction1_BytesRefNumOf : 8;
      dsser_receive(rtiDS4201SER_B1_Ser[2], bytesRefNumOf, (UInt8 *)
                    &loaddspace_B.SFunction1[0], &(bytesActNumOfAddr));
    }

    /* S-Function (byte2any_svd): '<S18>/Byte Unpack' */

    /* Unpack: <S18>/Byte Unpack */
    {
      uint32_T MW_inputPortOffset = 0;
      uint32_T MW_outputPortWidth = 0;
      uint32_T MW_remainder2 = 0;

      /* Packed input data type - uint8_T */
      /* Unpacking the values to output 1 */
      /* Output data type - real_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(real_T);
        memcpy((uint8_T*)&loaddspace_B.h_ground, (uint8_T*)
               &loaddspace_B.SFunction1[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }
    }
  }

  /* Sum: '<S18>/Sum' */
  loaddspace_B.Sum_e = loaddspace_B.PositionIntegrator2[2] -
    loaddspace_B.h_ground;

  /* SignalConversion generated from: '<S105>/ SFunction ' incorporates:
   *  Constant: '<S18>/Constant'
   *  MATLAB Function: '<S18>/trasformazione quota earth-body'
   */
  loaddspace_B.TmpSignalConversionAtSFunctionI[0] =
    loaddspace_P.Constant_Value_a;
  loaddspace_B.TmpSignalConversionAtSFunctionI[1] =
    loaddspace_P.Constant_Value_a;
  loaddspace_B.TmpSignalConversionAtSFunctionI[2] = loaddspace_B.Sum_e;

  /* MATLAB Function: '<S18>/trasformazione quota earth-body' */
  /* MATLAB Function 'SENSORI/trasformazione quota earth-body': '<S105>:1' */
  /* '<S105>:1:4' */
  /* '<S105>:1:8' */
  /* '<S105>:1:10' */
  tmp_f = cos(loaddspace_B.phithetapsi[1]);
  u2 = cos(loaddspace_B.phithetapsi[2]);
  u0 = cos(loaddspace_B.phithetapsi[1]);
  diffLm = sin(loaddspace_B.phithetapsi[2]);
  Fss = sin(loaddspace_B.phithetapsi[1]);
  Frms = sin(loaddspace_B.phithetapsi[0]);
  b_s = sin(loaddspace_B.phithetapsi[1]);
  b_fmod = cos(loaddspace_B.phithetapsi[2]);
  Mye = cos(loaddspace_B.phithetapsi[0]);
  u1 = sin(loaddspace_B.phithetapsi[2]);
  Fsd = sin(loaddspace_B.phithetapsi[0]);
  Frmd = sin(loaddspace_B.phithetapsi[1]);
  tmp_g = sin(loaddspace_B.phithetapsi[2]);
  tmp = cos(loaddspace_B.phithetapsi[0]);
  tmp_0 = cos(loaddspace_B.phithetapsi[2]);
  tmp_1 = sin(loaddspace_B.phithetapsi[0]);
  tmp_2 = cos(loaddspace_B.phithetapsi[1]);
  tmp_3 = cos(loaddspace_B.phithetapsi[0]);
  tmp_4 = sin(loaddspace_B.phithetapsi[1]);
  tmp_5 = cos(loaddspace_B.phithetapsi[2]);
  tmp_6 = sin(loaddspace_B.phithetapsi[0]);
  tmp_7 = sin(loaddspace_B.phithetapsi[2]);
  tmp_8 = cos(loaddspace_B.phithetapsi[0]);
  tmp_9 = sin(loaddspace_B.phithetapsi[1]);
  tmp_a = sin(loaddspace_B.phithetapsi[2]);
  tmp_b = sin(loaddspace_B.phithetapsi[0]);
  tmp_c = cos(loaddspace_B.phithetapsi[2]);
  tmp_d = cos(loaddspace_B.phithetapsi[0]);
  tmp_e = cos(loaddspace_B.phithetapsi[1]);
  dcmt[0] = tmp_f * u2;
  dcmt[3] = u0 * diffLm;
  dcmt[6] = -Fss;
  dcmt[1] = Frms * b_s * b_fmod - Mye * u1;
  dcmt[4] = Fsd * Frmd * tmp_g + tmp * tmp_0;
  dcmt[7] = tmp_1 * tmp_2;
  dcmt[2] = tmp_3 * tmp_4 * tmp_5 + tmp_6 * tmp_7;
  dcmt[5] = tmp_8 * tmp_9 * tmp_a - tmp_b * tmp_c;
  dcmt[8] = tmp_d * tmp_e;
  for (i = 0; i < 3; i++) {
    tmp_f = dcmt[i] * loaddspace_B.TmpSignalConversionAtSFunctionI[0];
    tmp_f += dcmt[i + 3] * loaddspace_B.TmpSignalConversionAtSFunctionI[1];
    tmp_f += dcmt[i + 6] * loaddspace_B.TmpSignalConversionAtSFunctionI[2];
    Mape[i] = tmp_f;
  }

  loaddspace_B.h_lidar = Mape[2];

  /* Gain: '<S18>/Gain' */
  loaddspace_B.Gain_m = loaddspace_P.Gain_Gain_a * loaddspace_B.h_lidar;

  /* Saturate: '<S18>/Saturation3' */
  u0 = loaddspace_B.Gain_m;
  u1 = loaddspace_P.Saturation3_LowerSat;
  u2 = loaddspace_P.Saturation3_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S18>/Saturation3' */
    loaddspace_B.Saturation3 = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S18>/Saturation3' */
    loaddspace_B.Saturation3 = u1;
  } else {
    /* Saturate: '<S18>/Saturation3' */
    loaddspace_B.Saturation3 = u0;
  }

  /* End of Saturate: '<S18>/Saturation3' */

  /* Sum: '<S18>/Sum14' */
  loaddspace_B.Sum14 = loaddspace_B.WhiteNoise4 + loaddspace_B.Saturation3;

  /* RateTransition: '<S18>/Rate Transition1' */
  if ((rtmIsMajorTimeStep(loaddspace_M) &&
       loaddspace_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
       (loaddspace_M) &&
       loaddspace_M->Timing.TaskCounters.TID[2] == 0)) {
    loaddspace_DW.RateTransition1_Buffer = loaddspace_B.Sum14;
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* RateTransition: '<S18>/Rate Transition1' */
    loaddspace_B.RateTransition1 = loaddspace_DW.RateTransition1_Buffer;

    /* DataTypeConversion: '<S18>/Data Type Conversion1' */
    tmp_f = floor(loaddspace_B.RateTransition1);
    if (rtIsNaN(tmp_f) || rtIsInf(tmp_f)) {
      tmp_f = 0.0;
    } else {
      tmp_f = fmod(tmp_f, 65536.0);
    }

    /* DataTypeConversion: '<S18>/Data Type Conversion1' */
    loaddspace_B.DataTypeConversion1 = (uint16_T)(tmp_f < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-tmp_f : (int32_T)(uint16_T)tmp_f);

    /* S-Function (any2byte_svd): '<S18>/Byte Pack' */

    /* Pack: <S18>/Byte Pack */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - uint16_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)((uint8_T*)&loaddspace_B.BytePack[0] +
                          MW_outputPortOffset), (uint8_T*)
               &loaddspace_B.DataTypeConversion1, MW_inputPortWidth);
      }
    }
  }

  /* End of RateTransition: '<S18>/Rate Transition1' */

  /* RateTransition: '<S18>/Rate Transition2' */
  if ((rtmIsMajorTimeStep(loaddspace_M) &&
       loaddspace_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
       (loaddspace_M) &&
       loaddspace_M->Timing.TaskCounters.TID[2] == 0)) {
    loaddspace_DW.RateTransition2_Buffer = loaddspace_B.module;
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* RateTransition: '<S18>/Rate Transition2' */
    loaddspace_B.RateTransition2 = loaddspace_DW.RateTransition2_Buffer;

    /* Math: '<S18>/Math Function'
     *
     * About '<S18>/Math Function':
     *  Operator: magnitude^2
     */
    b_fmod = loaddspace_B.RateTransition2;

    /* Math: '<S18>/Math Function'
     *
     * About '<S18>/Math Function':
     *  Operator: magnitude^2
     */
    loaddspace_B.MathFunction = b_fmod * b_fmod;

    /* Gain: '<S18>/Gain3' */
    loaddspace_B.Gain3 = loaddspace_P.Gain3_Gain * loaddspace_B.MathFunction;

    /* Product: '<S18>/Divide' incorporates:
     *  Constant: '<S18>/Constant2'
     */
    loaddspace_B.Divide = loaddspace_B.Gain3 / loaddspace_P.Constant2_Value;

    /* Gain: '<S18>/Gain4' */
    loaddspace_B.Gain4 = loaddspace_P.Gain4_Gain * loaddspace_B.Divide;

    /* DataTypeConversion: '<S18>/Data Type Conversion2' */
    tmp_f = floor(loaddspace_B.Gain4);
    if (rtIsNaN(tmp_f) || rtIsInf(tmp_f)) {
      tmp_f = 0.0;
    } else {
      tmp_f = fmod(tmp_f, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S18>/Data Type Conversion2' */
    loaddspace_B.DataTypeConversion2 = tmp_f < 0.0 ? -(int32_T)(uint32_T)-tmp_f :
      (int32_T)(uint32_T)tmp_f;

    /* S-Function (any2byte_svd): '<S18>/Byte Pack2' */

    /* Pack: <S18>/Byte Pack2 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - int32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(int32_T);
        memcpy((uint8_T*)((uint8_T*)&loaddspace_B.BytePack2[0] +
                          MW_outputPortOffset), (uint8_T*)
               &loaddspace_B.DataTypeConversion2, MW_inputPortWidth);
      }
    }

    /* S-Function (rti_commonblock): '<S12>/S-Function1' incorporates:
     *  Constant: '<S18>/Constant1'
     */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:TRANSMIT */
    {
      UInt8 tempBuf[15];

      {
        int_T i1;
        const uint8_T *u0 = &loaddspace_P.Constant1_Value_p[0];
        UInt8 *p_tempBuf = &tempBuf[0];
        for (i1=0; i1 < 5; i1++) {
          p_tempBuf[i1] = (UInt8) u0[i1];
        }

        tempBuf[5] = (UInt8) loaddspace_B.BytePack1[0];
        tempBuf[6] = (UInt8) loaddspace_B.BytePack1[1];
        tempBuf[7] = (UInt8) loaddspace_B.BytePack1[2];
        tempBuf[8] = (UInt8) loaddspace_B.BytePack1[3];
        tempBuf[9] = (UInt8) loaddspace_B.BytePack[0];
        tempBuf[10] = (UInt8) loaddspace_B.BytePack[1];
        tempBuf[11] = (UInt8) loaddspace_B.BytePack2[0];
        tempBuf[12] = (UInt8) loaddspace_B.BytePack2[1];
        tempBuf[13] = (UInt8) loaddspace_B.BytePack2[2];
        tempBuf[14] = (UInt8) loaddspace_B.BytePack2[3];
      }

      {
        UInt32 bytesActNumOfAddr;
        UInt32 bytesRefNumOf;
        bytesRefNumOf = (loaddspace_P.SFunction1_BytesRefNumOf_o <= 15) ?
          loaddspace_P.SFunction1_BytesRefNumOf_o : 15;
        dsser_transmit(rtiDS4201SER_B1_Ser[3], bytesRefNumOf, tempBuf,
                       &(bytesActNumOfAddr));
      }
    }
  }

  /* End of RateTransition: '<S18>/Rate Transition2' */

  /* Sum: '<S85>/Sum2' incorporates:
   *  Constant: '<S85>/pi'
   */
  loaddspace_B.Sum2 = loaddspace_B.PositionIntegrator2[1] +
    loaddspace_P.pi_Value;

  /* Math: '<S85>/Math Function' incorporates:
   *  Constant: '<S85>/2pi'
   */
  loaddspace_B.MathFunction_f = rt_modd_snf(loaddspace_B.Sum2,
    loaddspace_P.upi_Value);

  /* Sum: '<S85>/Sum1' incorporates:
   *  Constant: '<S85>/pi'
   */
  loaddspace_B.Sum1_p = loaddspace_B.MathFunction_f - loaddspace_P.pi_Value;

  /* Gain: '<S16>/Gain' */
  loaddspace_B.Gain_h = loaddspace_P.Gain_Gain_j * loaddspace_B.Sum1_p;

  /* Sum: '<S84>/Sum2' incorporates:
   *  Constant: '<S84>/pi//2'
   */
  loaddspace_B.Sum2_d = loaddspace_B.PositionIntegrator2[0] +
    loaddspace_P.pi2_Value;

  /* Math: '<S84>/Math Function' incorporates:
   *  Constant: '<S84>/pi'
   */
  loaddspace_B.MathFunction_h = rt_modd_snf(loaddspace_B.Sum2_d,
    loaddspace_P.pi_Value_d);

  /* Sum: '<S84>/Sum1' incorporates:
   *  Constant: '<S84>/pi//2'
   */
  loaddspace_B.Sum1_m = loaddspace_B.MathFunction_h - loaddspace_P.pi2_Value;

  /* Math: '<S84>/Math Function1' incorporates:
   *  Constant: '<S84>/2pi'
   */
  loaddspace_B.MathFunction1 = rt_modd_snf(loaddspace_B.Sum2_d,
    loaddspace_P.upi_Value_e);

  /* Switch: '<S84>/Switch' */
  if (loaddspace_B.MathFunction1 >= loaddspace_P.Switch_Threshold) {
    /* Gain: '<S84>/ChSign' */
    loaddspace_B.ChSign = loaddspace_P.ChSign_Gain * loaddspace_B.Sum1_m;

    /* Switch: '<S84>/Switch' */
    loaddspace_B.Switch = loaddspace_B.ChSign;
  } else {
    /* Switch: '<S84>/Switch' */
    loaddspace_B.Switch = loaddspace_B.Sum1_m;
  }

  /* End of Switch: '<S84>/Switch' */

  /* Gain: '<S17>/Gain' */
  loaddspace_B.Gain_g = loaddspace_P.Gain_Gain_b * loaddspace_B.Switch;

  /* SignalConversion generated from: '<Root>/S-Function Builder1' */
  loaddspace_B.TmpSignalConversionAtSFunctionB[0] = loaddspace_B.Gain_h;
  loaddspace_B.TmpSignalConversionAtSFunctionB[1] = loaddspace_B.Gain_g;
  loaddspace_B.TmpSignalConversionAtSFunctionB[2] =
    loaddspace_B.PositionIntegrator2[2];
  loaddspace_B.TmpSignalConversionAtSFunctionB[3] = loaddspace_B.phithetapsi[0];
  loaddspace_B.TmpSignalConversionAtSFunctionB[4] = loaddspace_B.phithetapsi[1];
  loaddspace_B.TmpSignalConversionAtSFunctionB[5] = loaddspace_B.phithetapsi[2];

  /* S-Function (outputStream_v1): '<Root>/S-Function Builder1' */
  outputStream_v1_Outputs_wrapper(&loaddspace_B.TmpSignalConversionAtSFunctionB
    [0], &loaddspace_B.SFunctionBuilder1_o1[0],
    &loaddspace_B.SFunctionBuilder1_o2);
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S11>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:TRANSMIT */
    {
      UInt32 txFifoLevel;
      UInt32 bytesRefNumOf;
      bytesRefNumOf = (loaddspace_B.SFunctionBuilder1_o2 <= 64) ?
        loaddspace_B.SFunctionBuilder1_o2 : 64;
      txFifoLevel = dsser_transmit_fifo_level(rtiDS4201SER_B1_Ser[2]);
      if (((rtiDS4201SER_B1_Ser[2]->fifo_size) - txFifoLevel) > bytesRefNumOf) {
        loaddspace_B.SFunction1_o2 = dsser_transmit(rtiDS4201SER_B1_Ser[2],
          bytesRefNumOf, &loaddspace_B.SFunctionBuilder1_o1[0], (UInt32 *)
          &loaddspace_B.SFunction1_o1);
      } else {
        UInt32 *temp = (UInt32 *) &loaddspace_B.SFunction1_o1;
        *temp = 0;
        loaddspace_B.SFunction1_o2 = DSSER_FIFO_OVERFLOW;
      }
    }
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */
    loaddspace_B.DiscreteTimeIntegrator =
      loaddspace_DW.DiscreteTimeIntegrator_DSTATE;
  }

  /* Sum: '<S108>/Sum1' */
  loaddspace_B.Sum1_o = loaddspace_B.Switch +
    loaddspace_B.DiscreteTimeIntegrator;

  /* ZeroOrderHold: '<S104>/Zero-Order Hold' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
    /* ZeroOrderHold: '<S104>/Zero-Order Hold' */
    loaddspace_B.ZeroOrderHold = loaddspace_B.Sum1_o;

    /* Gain: '<S99>/Gain' */
    loaddspace_B.Gain_a = loaddspace_P.Gain_Gain_l * loaddspace_B.ZeroOrderHold;
  }

  /* End of ZeroOrderHold: '<S104>/Zero-Order Hold' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscreteIntegrator: '<S109>/Discrete-Time Integrator' */
    loaddspace_B.DiscreteTimeIntegrator_e =
      loaddspace_DW.DiscreteTimeIntegrator_DSTATE_f;
  }

  /* Sum: '<S109>/Sum1' */
  loaddspace_B.Sum1_o4 = loaddspace_B.Sum1_p +
    loaddspace_B.DiscreteTimeIntegrator_e;

  /* ZeroOrderHold: '<S104>/Zero-Order Hold1' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
    /* ZeroOrderHold: '<S104>/Zero-Order Hold1' */
    loaddspace_B.ZeroOrderHold1 = loaddspace_B.Sum1_o4;

    /* Gain: '<S100>/Gain' */
    loaddspace_B.Gain_o = loaddspace_P.Gain_Gain_m * loaddspace_B.ZeroOrderHold1;
  }

  /* End of ZeroOrderHold: '<S104>/Zero-Order Hold1' */

  /* SignalConversion generated from: '<S44>/sincos' */
  loaddspace_B.TmpSignalConversionAtsincosInpo[0] = loaddspace_B.phithetapsi[2];
  loaddspace_B.TmpSignalConversionAtsincosInpo[1] = loaddspace_B.phithetapsi[1];
  loaddspace_B.TmpSignalConversionAtsincosInpo[2] = loaddspace_B.phithetapsi[0];

  /* Trigonometry: '<S44>/sincos' */
  b_s = loaddspace_B.TmpSignalConversionAtsincosInpo[0];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  loaddspace_B.sincos_o1[0] = b_fmod;
  loaddspace_B.sincos_o2[0] = b_s;
  b_s = loaddspace_B.TmpSignalConversionAtsincosInpo[1];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  loaddspace_B.sincos_o1[1] = b_fmod;
  loaddspace_B.sincos_o2[1] = b_s;
  b_s = loaddspace_B.TmpSignalConversionAtsincosInpo[2];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  loaddspace_B.sincos_o1[2] = b_fmod;
  loaddspace_B.sincos_o2[2] = b_s;

  /* Fcn: '<S44>/Fcn11' */
  loaddspace_B.VectorConcatenate[0] = loaddspace_B.sincos_o2[1] *
    loaddspace_B.sincos_o2[0];

  /* Fcn: '<S44>/Fcn21' */
  loaddspace_B.VectorConcatenate[1] = loaddspace_B.sincos_o1[2] *
    loaddspace_B.sincos_o1[1] * loaddspace_B.sincos_o2[0] -
    loaddspace_B.sincos_o2[2] * loaddspace_B.sincos_o1[0];

  /* Fcn: '<S44>/Fcn31' */
  loaddspace_B.VectorConcatenate[2] = loaddspace_B.sincos_o2[2] *
    loaddspace_B.sincos_o1[1] * loaddspace_B.sincos_o2[0] +
    loaddspace_B.sincos_o1[2] * loaddspace_B.sincos_o1[0];

  /* Fcn: '<S44>/Fcn12' */
  loaddspace_B.VectorConcatenate[3] = loaddspace_B.sincos_o2[1] *
    loaddspace_B.sincos_o1[0];

  /* Fcn: '<S44>/Fcn22' */
  loaddspace_B.VectorConcatenate[4] = loaddspace_B.sincos_o1[2] *
    loaddspace_B.sincos_o1[1] * loaddspace_B.sincos_o1[0] +
    loaddspace_B.sincos_o2[2] * loaddspace_B.sincos_o2[0];

  /* Fcn: '<S44>/Fcn32' */
  loaddspace_B.VectorConcatenate[5] = loaddspace_B.sincos_o2[2] *
    loaddspace_B.sincos_o1[1] * loaddspace_B.sincos_o1[0] -
    loaddspace_B.sincos_o1[2] * loaddspace_B.sincos_o2[0];

  /* Fcn: '<S44>/Fcn13' */
  loaddspace_B.VectorConcatenate[6] = -loaddspace_B.sincos_o1[1];

  /* Fcn: '<S44>/Fcn23' */
  loaddspace_B.VectorConcatenate[7] = loaddspace_B.sincos_o1[2] *
    loaddspace_B.sincos_o2[1];

  /* Fcn: '<S44>/Fcn33' */
  loaddspace_B.VectorConcatenate[8] = loaddspace_B.sincos_o2[2] *
    loaddspace_B.sincos_o2[1];

  /* Reshape: '<S46>/Reshape (9) to [3x3] column-major' */
  memcpy(&loaddspace_B.Reshape9to3x3columnmajor[0],
         &loaddspace_B.VectorConcatenate[0], 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    /* Math: '<S26>/Transpose' incorporates:
     *  Reshape: '<S46>/Reshape (9) to [3x3] column-major'
     */
    loaddspace_B.Transpose[3 * i] = loaddspace_B.Reshape9to3x3columnmajor[i];
    loaddspace_B.Transpose[3 * i + 1] = loaddspace_B.Reshape9to3x3columnmajor[i
      + 3];
    loaddspace_B.Transpose[3 * i + 2] = loaddspace_B.Reshape9to3x3columnmajor[i
      + 6];

    /* Reshape: '<S43>/Reshape1' */
    loaddspace_B.Reshape1[i] = loaddspace_B.ubvbwb[i];
  }

  /* Product: '<S43>/Product' incorporates:
   *  Math: '<S26>/Transpose'
   *  Reshape: '<S43>/Reshape1'
   */
  memcpy(&dcmt[0], &loaddspace_B.Transpose[0], 9U * sizeof(real_T));
  Fape[0] = loaddspace_B.Reshape1[0];
  Fape[1] = loaddspace_B.Reshape1[1];
  Fape[2] = loaddspace_B.Reshape1[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S43>/Product' */
    loaddspace_B.Product[i] = 0.0;
    loaddspace_B.Product[i] += dcmt[i] * Fape[0];
    loaddspace_B.Product[i] += dcmt[i + 3] * Fape[1];
    loaddspace_B.Product[i] += dcmt[i + 6] * Fape[2];
  }

  /* Reshape: '<S43>/Reshape2' incorporates:
   *  Product: '<S43>/Product'
   */
  loaddspace_B.Reshape2[0] = loaddspace_B.Product[0];
  loaddspace_B.Reshape2[1] = loaddspace_B.Product[1];
  loaddspace_B.Reshape2[2] = loaddspace_B.Product[2];

  /* UnitConversion: '<S41>/Unit Conversion' */
  /* Unit Conversion - from: m/s to: m/s
     Expression: output = (1*input) + (0) */
  loaddspace_B.UnitConversion_f[0] = loaddspace_B.Reshape2[0];
  loaddspace_B.UnitConversion_f[1] = loaddspace_B.Reshape2[1];
  loaddspace_B.UnitConversion_f[2] = loaddspace_B.Reshape2[2];

  /* Math: '<S80>/Square2' */
  loaddspace_B.Square2 = loaddspace_B.UnitConversion_f[0] *
    loaddspace_B.UnitConversion_f[0];

  /* Math: '<S80>/Square1' */
  loaddspace_B.Square1 = loaddspace_B.UnitConversion_f[1] *
    loaddspace_B.UnitConversion_f[1];

  /* Sum: '<S80>/Add' */
  loaddspace_B.Add = loaddspace_B.Square2 + loaddspace_B.Square1;

  /* Sqrt: '<S80>/Sqrt' */
  loaddspace_B.Sqrt = sqrt(loaddspace_B.Add);
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
    /* RandomNumber: '<S110>/Noise V_hor' */
    loaddspace_B.NoiseV_hor = loaddspace_DW.NextOutput_b;

    /* RandomNumber: '<S110>/noise terra V_hor1' */
    loaddspace_B.noiseterraV_hor1 = loaddspace_DW.NextOutput_am;

    /* Abs: '<S110>/Abs' */
    loaddspace_B.Abs = fabs(loaddspace_B.noiseterraV_hor1);
  }

  /* ZeroOrderHold: '<S110>/Zero-Order Hold2' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S110>/Zero-Order Hold2' */
    loaddspace_B.ZeroOrderHold2 = loaddspace_B.Sqrt;

    /* Switch: '<S110>/Switch4' */
    if (loaddspace_B.ZeroOrderHold2 > loaddspace_P.Switch4_Threshold) {
      /* Switch: '<S110>/Switch4' */
      loaddspace_B.Switch4 = loaddspace_B.NoiseV_hor;
    } else {
      /* Switch: '<S110>/Switch4' */
      loaddspace_B.Switch4 = loaddspace_B.Abs;
    }

    /* End of Switch: '<S110>/Switch4' */

    /* Sum: '<S110>/Sum5' */
    loaddspace_B.Sum5 = loaddspace_B.ZeroOrderHold2 + loaddspace_B.Switch4;

    /* ZeroOrderHold: '<S104>/Zero-Order Hold4' */
    if (rtmIsMajorTimeStep(loaddspace_M) &&
        loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
      /* ZeroOrderHold: '<S104>/Zero-Order Hold4' */
      loaddspace_B.ZeroOrderHold4 = loaddspace_B.Sum5;
    }

    /* End of ZeroOrderHold: '<S104>/Zero-Order Hold4' */
  }

  /* End of ZeroOrderHold: '<S110>/Zero-Order Hold2' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
    /* Gain: '<S18>/Gain5' */
    loaddspace_B.Gain5 = loaddspace_P.Gain5_Gain * loaddspace_B.ZeroOrderHold4;
  }

  /* Trigonometry: '<S81>/Atan2' */
  loaddspace_B.Atan2 = rt_atan2d_snf(loaddspace_B.UnitConversion_f[1],
    loaddspace_B.UnitConversion_f[0]);

  /* ZeroOrderHold: '<S110>/Zero-Order Hold' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S110>/Zero-Order Hold' */
    loaddspace_B.ZeroOrderHold_o = loaddspace_B.Atan2;

    /* RandomNumber: '<S110>/Rumore bianco' */
    loaddspace_B.Rumorebianco = loaddspace_DW.NextOutput_p;

    /* RandomNumber: '<S110>/Noise terra course' */
    loaddspace_B.Noiseterracourse = loaddspace_DW.NextOutput_k;

    /* Switch: '<S110>/Switch3' */
    if (loaddspace_B.ZeroOrderHold2 > loaddspace_P.Switch3_Threshold) {
      /* Product: '<S110>/Divide2' incorporates:
       *  Constant: '<S110>/Std_vel'
       */
      loaddspace_B.Divide2_e = loaddspace_P.Std_vel /
        loaddspace_B.ZeroOrderHold2;

      /* Product: '<S110>/Multiply5' */
      loaddspace_B.Multiply5 = loaddspace_B.Rumorebianco *
        loaddspace_B.Divide2_e;

      /* Switch: '<S110>/Switch3' */
      loaddspace_B.Switch3 = loaddspace_B.Multiply5;
    } else {
      /* Switch: '<S110>/Switch3' */
      loaddspace_B.Switch3 = loaddspace_B.Noiseterracourse;
    }

    /* End of Switch: '<S110>/Switch3' */

    /* Sum: '<S110>/Add' */
    loaddspace_B.Course_sporco = loaddspace_B.ZeroOrderHold_o +
      loaddspace_B.Switch3;

    /* MATLAB Function: '<S110>/0-2pi Wrapper' */
    /* MATLAB Function 'SENSORI/Subsystem1/Subsystem2/0-2pi Wrapper': '<S111>:1' */
    /* '<S111>:1:6' */
    /* '<S111>:1:8' */
    /* '<S111>:1:9' */
    b_fmod = loaddspace_B.Course_sporco - floor(loaddspace_B.Course_sporco /
      6.2831853071795862) * 6.2831853071795862;
    if (b_fmod < 0.0) {
      /* '<S111>:1:12' */
      /* '<S111>:1:14' */
      b_fmod += 6.2831853071795862;
    }

    /* '<S111>:1:18' */
    loaddspace_B.y = b_fmod;

    /* End of MATLAB Function: '<S110>/0-2pi Wrapper' */

    /* Switch: '<S110>/Switch1' */
    if (loaddspace_B.ZeroOrderHold2 > loaddspace_P.Switch1_Threshold_i) {
      /* Switch: '<S110>/Switch1' */
      loaddspace_B.Switch1_f = loaddspace_B.y;
    } else {
      /* Switch: '<S110>/Switch1' incorporates:
       *  Constant: '<S110>/Constant'
       */
      loaddspace_B.Switch1_f = loaddspace_P.Constant_Value;
    }

    /* End of Switch: '<S110>/Switch1' */

    /* ZeroOrderHold: '<S104>/Zero-Order Hold5' */
    if (rtmIsMajorTimeStep(loaddspace_M) &&
        loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
      /* ZeroOrderHold: '<S104>/Zero-Order Hold5' */
      loaddspace_B.ZeroOrderHold5 = loaddspace_B.Switch1_f;
    }

    /* End of ZeroOrderHold: '<S104>/Zero-Order Hold5' */
  }

  /* End of ZeroOrderHold: '<S110>/Zero-Order Hold' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
    /* Gain: '<S97>/Gain' */
    loaddspace_B.Gain_n = loaddspace_P.Gain_Gain_f * loaddspace_B.ZeroOrderHold5;

    /* ZeroOrderHold: '<S104>/Zero-Order Hold6' */
    loaddspace_B.ZeroOrderHold6 = loaddspace_B.PositionIntegrator2[2];
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[4] == 0) {
    /* S-Function (SImulate_messageGPS_nmea_carriage_return): '<S94>/S-Function Builder1' */
    SImulate_messageGPS_nmea_carriage_return_Outputs_wrapper
      (&loaddspace_B.Gain_a, &loaddspace_B.Gain_o, &loaddspace_B.Gain5,
       &loaddspace_B.Gain_n, &loaddspace_B.ZeroOrderHold6,
       &loaddspace_B.SFunctionBuilder1[0]);

    /* S-Function (rti_commonblock): '<S20>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:TRANSMIT */
    {
      UInt32 txFifoLevel;
      UInt32 bytesRefNumOf;
      bytesRefNumOf = (loaddspace_P.SFunction1_BytesRefNumOf_m <= 131) ?
        loaddspace_P.SFunction1_BytesRefNumOf_m : 131;
      txFifoLevel = dsser_transmit_fifo_level(rtiDS4201SER_B1_Ser[1]);
      if (((rtiDS4201SER_B1_Ser[1]->fifo_size) - txFifoLevel) > bytesRefNumOf) {
        UInt32 bytesActNumOfAddr;
        dsser_transmit(rtiDS4201SER_B1_Ser[1], bytesRefNumOf,
                       &loaddspace_B.SFunctionBuilder1[0], &(bytesActNumOfAddr));
      }
    }
  }

  /* SignalConversion generated from: '<S78>/ SFunction ' incorporates:
   *  MATLAB Function: '<S34>/controllo divisione per 0 su alpha'
   */
  loaddspace_B.TmpSignalConversionAtSFunctio_l[0] = loaddspace_B.Va[2];
  loaddspace_B.TmpSignalConversionAtSFunctio_l[1] = loaddspace_B.Va[0];

  /* MATLAB Function: '<S34>/controllo divisione per 0 su alpha' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Velocità1/controllo divisione per 0 su alpha': '<S78>:1' */
  if (loaddspace_B.TmpSignalConversionAtSFunctio_l[1] == 0.0) {
    /* '<S78>:1:6' */
    /* '<S78>:1:7' */
    loaddspace_B.y_e = 0.0;
  } else {
    /* '<S78>:1:9' */
    loaddspace_B.y_e = loaddspace_B.TmpSignalConversionAtSFunctio_l[0] /
      loaddspace_B.TmpSignalConversionAtSFunctio_l[1];
  }

  /* Trigonometry: '<S34>/Trigonometric Function1' */
  loaddspace_B.u = atan(loaddspace_B.y_e);

  /* SignalConversion generated from: '<S79>/ SFunction ' incorporates:
   *  MATLAB Function: '<S34>/controllo divisione per 0 su beta'
   */
  loaddspace_B.TmpSignalConversionAtSFunctio_p[0] = loaddspace_B.Va[1];
  loaddspace_B.TmpSignalConversionAtSFunctio_p[1] = loaddspace_B.module;

  /* MATLAB Function: '<S34>/controllo divisione per 0 su beta' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Velocità1/controllo divisione per 0 su beta': '<S79>:1' */
  if (loaddspace_B.TmpSignalConversionAtSFunctio_p[1] == 0.0) {
    /* '<S79>:1:6' */
    /* '<S79>:1:7' */
    loaddspace_B.y_f = 0.0;
  } else {
    /* '<S79>:1:9' */
    loaddspace_B.y_f = loaddspace_B.TmpSignalConversionAtSFunctio_p[0] /
      loaddspace_B.TmpSignalConversionAtSFunctio_p[1];
  }

  /* Trigonometry: '<S34>/Trigonometric Function2' */
  u0 = loaddspace_B.y_f;
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* Trigonometry: '<S34>/Trigonometric Function2' */
  loaddspace_B.u_m = asin(u0);

  /* MATLAB Function: '<S28>/MATLAB Function' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/MATLAB Function': '<S56>:1' */
  /* '<S56>:1:4' */
  tmp_f = cos(loaddspace_B.u);
  u2 = cos(loaddspace_B.u_m);
  u0 = cos(loaddspace_B.u);
  diffLm = sin(loaddspace_B.u_m);
  Fss = sin(loaddspace_B.u);
  Frms = sin(loaddspace_B.u_m);
  b_s = cos(loaddspace_B.u_m);
  b_fmod = sin(loaddspace_B.u);
  Mye = cos(loaddspace_B.u_m);
  u1 = sin(loaddspace_B.u);
  Fsd = sin(loaddspace_B.u_m);
  Frmd = cos(loaddspace_B.u);
  loaddspace_B.Lbw[0] = tmp_f * u2;
  loaddspace_B.Lbw[3] = -u0 * diffLm;
  loaddspace_B.Lbw[6] = -Fss;
  loaddspace_B.Lbw[1] = Frms;
  loaddspace_B.Lbw[4] = b_s;
  loaddspace_B.Lbw[7] = 0.0;
  loaddspace_B.Lbw[2] = b_fmod * Mye;
  loaddspace_B.Lbw[5] = -u1 * Fsd;
  loaddspace_B.Lbw[8] = Frmd;

  /* Lookup_n-D: '<S58>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  loaddspace_B.uDLookupTable_n = look2_binlxpw(loaddspace_B.u, loaddspace_B.u_m,
    loaddspace_P.alphavec_rad, loaddspace_P.betavec_rad,
    loaddspace_P.uDLookupTable_tableData, loaddspace_P.uDLookupTable_maxIndex,
    13U);

  /* Sum: '<S58>/Sum1' incorporates:
   *  Constant: '<S23>/CD_0'
   */
  loaddspace_B.Sum1_d = loaddspace_B.uDLookupTable_n + loaddspace_P.CD0;

  /* Gain: '<S55>/Gain4' */
  loaddspace_B.CD = loaddspace_P.Gain4_Gain_j * loaddspace_B.Sum1_d;

  /* Lookup_n-D: '<S59>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  loaddspace_B.uDLookupTable_g = look2_binlxpw(loaddspace_B.u, loaddspace_B.u_m,
    loaddspace_P.alphavec_rad, loaddspace_P.betavec_rad,
    loaddspace_P.uDLookupTable_tableData_k,
    loaddspace_P.uDLookupTable_maxIndex_n, 13U);

  /* Saturate: '<S59>/Saturation' */
  u0 = loaddspace_B.uDLookupTable_g;
  u1 = loaddspace_P.Saturation_LowerSat;
  u2 = loaddspace_P.Saturation_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S59>/Saturation' */
    loaddspace_B.Saturation = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S59>/Saturation' */
    loaddspace_B.Saturation = u1;
  } else {
    /* Saturate: '<S59>/Saturation' */
    loaddspace_B.Saturation = u0;
  }

  /* End of Saturate: '<S59>/Saturation' */

  /* Integrator: '<S26>/p,q,r ' */
  loaddspace_B.pqr[0] = loaddspace_X.pqr_CSTATE[0];
  loaddspace_B.pqr[1] = loaddspace_X.pqr_CSTATE[1];
  loaddspace_B.pqr[2] = loaddspace_X.pqr_CSTATE[2];

  /* SignalConversion generated from: '<S61>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S59>/controllo divisione per zero Yp '
   */
  b_fmod = loaddspace_P.b / 2.0;

  /* SignalConversion generated from: '<S61>/ SFunction ' incorporates:
   *  Constant: '<S23>/CY_p '
   *  MATLAB Function: '<S59>/controllo divisione per zero Yp '
   */
  loaddspace_B.TmpSignalConversionAtSFuncti_kl[0] = loaddspace_P.CYp;
  loaddspace_B.TmpSignalConversionAtSFuncti_kl[1] = loaddspace_B.pqr[0];
  loaddspace_B.TmpSignalConversionAtSFuncti_kl[2] = b_fmod;
  loaddspace_B.TmpSignalConversionAtSFuncti_kl[3] = loaddspace_B.module;

  /* MATLAB Function: '<S59>/controllo divisione per zero Yp ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem1/controllo divisione per zero Yp ': '<S61>:1' */
  if (loaddspace_B.TmpSignalConversionAtSFuncti_kl[3] == 0.0) {
    /* '<S61>:1:6' */
    /* '<S61>:1:7' */
    loaddspace_B.y_g = 0.0;
  } else {
    /* '<S61>:1:9' */
    loaddspace_B.y_g = loaddspace_B.TmpSignalConversionAtSFuncti_kl[0] *
      loaddspace_B.TmpSignalConversionAtSFuncti_kl[1] *
      loaddspace_B.TmpSignalConversionAtSFuncti_kl[2] /
      loaddspace_B.TmpSignalConversionAtSFuncti_kl[3];
  }

  /* SignalConversion generated from: '<S62>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S59>/controllo divisione per zero Yr'
   */
  b_fmod = loaddspace_P.b / 2.0;

  /* SignalConversion generated from: '<S62>/ SFunction ' incorporates:
   *  Constant: '<S23>/CY_r'
   *  MATLAB Function: '<S59>/controllo divisione per zero Yr'
   */
  loaddspace_B.TmpSignalConversionAtSFuncti_mf[0] = loaddspace_B.pqr[2];
  loaddspace_B.TmpSignalConversionAtSFuncti_mf[1] = b_fmod;
  loaddspace_B.TmpSignalConversionAtSFuncti_mf[2] = loaddspace_P.CYr;
  loaddspace_B.TmpSignalConversionAtSFuncti_mf[3] = loaddspace_B.module;

  /* MATLAB Function: '<S59>/controllo divisione per zero Yr' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem1/controllo divisione per zero Yr': '<S62>:1' */
  if (loaddspace_B.TmpSignalConversionAtSFuncti_mf[3] == 0.0) {
    /* '<S62>:1:6' */
    /* '<S62>:1:7' */
    loaddspace_B.y_j = 0.0;
  } else {
    /* '<S62>:1:9' */
    loaddspace_B.y_j = loaddspace_B.TmpSignalConversionAtSFuncti_mf[0] *
      loaddspace_B.TmpSignalConversionAtSFuncti_mf[1] *
      loaddspace_B.TmpSignalConversionAtSFuncti_mf[2] /
      loaddspace_B.TmpSignalConversionAtSFuncti_mf[3];
  }

  /* StateSpace: '<S2>/State-Space2' */
  loaddspace_B.Timone = 0.0;
  loaddspace_B.Timone += loaddspace_P.StateSpace2_C *
    loaddspace_X.StateSpace2_CSTATE;

  /* StateSpace: '<S3>/State-Space2' */
  loaddspace_B.Timone_p = 0.0;
  loaddspace_B.Timone_p += loaddspace_P.StateSpace2_C_b *
    loaddspace_X.StateSpace2_CSTATE_g;

  /* ManualSwitch generated from: '<Root>/Manual Switch' */
  if (loaddspace_P.ManualSwitch_4_CurrentSetting == 1) {
    /* Saturate: '<S2>/Saturation3' */
    b_fmod = -loaddspace_P.attuatore_Rmax;
    b_s = loaddspace_P.attuatore_Rmax + 0.1;
    u0 = loaddspace_B.Timone;
    if (u0 > b_s) {
      /* Saturate: '<S2>/Saturation3' */
      loaddspace_B.deltaR_j = b_s;
    } else if (u0 < b_fmod) {
      /* Saturate: '<S2>/Saturation3' */
      loaddspace_B.deltaR_j = b_fmod;
    } else {
      /* Saturate: '<S2>/Saturation3' */
      loaddspace_B.deltaR_j = u0;
    }

    /* End of Saturate: '<S2>/Saturation3' */

    /* ManualSwitch generated from: '<Root>/Manual Switch' */
    loaddspace_B.deltaR = loaddspace_B.deltaR_j;
  } else {
    /* Saturate: '<S3>/Saturation3' */
    b_fmod = -loaddspace_P.attuatore_Rmax;
    b_s = loaddspace_P.attuatore_Rmax + 0.1;
    u0 = loaddspace_B.Timone_p;
    if (u0 > b_s) {
      /* Saturate: '<S3>/Saturation3' */
      loaddspace_B.deltaR_g = b_s;
    } else if (u0 < b_fmod) {
      /* Saturate: '<S3>/Saturation3' */
      loaddspace_B.deltaR_g = b_fmod;
    } else {
      /* Saturate: '<S3>/Saturation3' */
      loaddspace_B.deltaR_g = u0;
    }

    /* End of Saturate: '<S3>/Saturation3' */

    /* ManualSwitch generated from: '<Root>/Manual Switch' */
    loaddspace_B.deltaR = loaddspace_B.deltaR_g;
  }

  /* Product: '<S59>/Product' incorporates:
   *  Constant: '<S23>/CY_dR'
   */
  loaddspace_B.Product_h = loaddspace_P.CYdR * loaddspace_B.deltaR;

  /* StateSpace: '<S2>/State-Space1' */
  loaddspace_B.Alettoni = 0.0;
  loaddspace_B.Alettoni += loaddspace_P.StateSpace1_C *
    loaddspace_X.StateSpace1_CSTATE;

  /* StateSpace: '<S3>/State-Space1' */
  loaddspace_B.Alettoni_n = 0.0;
  loaddspace_B.Alettoni_n += loaddspace_P.StateSpace1_C_o *
    loaddspace_X.StateSpace1_CSTATE_n;

  /* ManualSwitch generated from: '<Root>/Manual Switch' */
  if (loaddspace_P.ManualSwitch_3_CurrentSetting == 1) {
    /* Saturate: '<S2>/Saturation2' */
    b_fmod = -loaddspace_P.attuatore_Amax;
    b_s = loaddspace_P.attuatore_Amax + 0.1;
    u0 = loaddspace_B.Alettoni;
    if (u0 > b_s) {
      /* Saturate: '<S2>/Saturation2' */
      loaddspace_B.deltaA_l = b_s;
    } else if (u0 < b_fmod) {
      /* Saturate: '<S2>/Saturation2' */
      loaddspace_B.deltaA_l = b_fmod;
    } else {
      /* Saturate: '<S2>/Saturation2' */
      loaddspace_B.deltaA_l = u0;
    }

    /* End of Saturate: '<S2>/Saturation2' */

    /* ManualSwitch generated from: '<Root>/Manual Switch' */
    loaddspace_B.deltaA = loaddspace_B.deltaA_l;
  } else {
    /* Saturate: '<S3>/Saturation2' */
    b_fmod = -loaddspace_P.attuatore_Amax;
    b_s = loaddspace_P.attuatore_Amax + 0.1;
    u0 = loaddspace_B.Alettoni_n;
    if (u0 > b_s) {
      /* Saturate: '<S3>/Saturation2' */
      loaddspace_B.deltaA_g = b_s;
    } else if (u0 < b_fmod) {
      /* Saturate: '<S3>/Saturation2' */
      loaddspace_B.deltaA_g = b_fmod;
    } else {
      /* Saturate: '<S3>/Saturation2' */
      loaddspace_B.deltaA_g = u0;
    }

    /* End of Saturate: '<S3>/Saturation2' */

    /* ManualSwitch generated from: '<Root>/Manual Switch' */
    loaddspace_B.deltaA = loaddspace_B.deltaA_g;
  }

  /* Product: '<S59>/Product3' incorporates:
   *  Constant: '<S23>/CY_dA'
   */
  loaddspace_B.Product3 = loaddspace_P.CYdA * loaddspace_B.deltaA;

  /* Sum: '<S59>/Sum' */
  loaddspace_B.Sum_k = (((loaddspace_B.Saturation + loaddspace_B.y_g) +
    loaddspace_B.y_j) + loaddspace_B.Product_h) + loaddspace_B.Product3;

  /* Lookup_n-D: '<S60>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  loaddspace_B.uDLookupTable_k = look2_binlxpw(loaddspace_B.u, loaddspace_B.u_m,
    loaddspace_P.alphavec_rad, loaddspace_P.betavec_rad,
    loaddspace_P.uDLookupTable_tableData_a,
    loaddspace_P.uDLookupTable_maxIndex_i, 13U);

  /* Gain: '<S60>/Gain1' */
  loaddspace_B.Gain1 = loaddspace_P.Gain1_Gain * loaddspace_B.module;

  /* SignalConversion generated from: '<S63>/ SFunction ' incorporates:
   *  Constant: '<S23>/CL_q '
   *  Constant: '<S23>/cbar '
   *  MATLAB Function: '<S60>/controllo divisione per zero Lq '
   */
  loaddspace_B.TmpSignalConversionAtSFuncti_am[0] = loaddspace_P.CLq;
  loaddspace_B.TmpSignalConversionAtSFuncti_am[1] = loaddspace_B.pqr[1];
  loaddspace_B.TmpSignalConversionAtSFuncti_am[2] = loaddspace_P.cbar;
  loaddspace_B.TmpSignalConversionAtSFuncti_am[3] = loaddspace_B.Gain1;

  /* MATLAB Function: '<S60>/controllo divisione per zero Lq ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem2/controllo divisione per zero Lq ': '<S63>:1' */
  if (loaddspace_B.TmpSignalConversionAtSFuncti_am[3] == 0.0) {
    /* '<S63>:1:6' */
    /* '<S63>:1:7' */
    loaddspace_B.y_ak = 0.0;
  } else {
    /* '<S63>:1:9' */
    loaddspace_B.y_ak = loaddspace_B.TmpSignalConversionAtSFuncti_am[0] *
      loaddspace_B.TmpSignalConversionAtSFuncti_am[1] *
      loaddspace_B.TmpSignalConversionAtSFuncti_am[2] /
      loaddspace_B.TmpSignalConversionAtSFuncti_am[3];
  }

  /* StateSpace: '<S2>/State-Space' */
  loaddspace_B.Equilibratore = 0.0;
  loaddspace_B.Equilibratore += loaddspace_P.StateSpace_C *
    loaddspace_X.StateSpace_CSTATE;

  /* StateSpace: '<S3>/State-Space' */
  loaddspace_B.Equilibratore_o = 0.0;
  loaddspace_B.Equilibratore_o += loaddspace_P.StateSpace_C_a *
    loaddspace_X.StateSpace_CSTATE_k;

  /* ManualSwitch generated from: '<Root>/Manual Switch' */
  if (loaddspace_P.ManualSwitch_2_CurrentSetting == 1) {
    /* Saturate: '<S2>/Saturation1' */
    b_fmod = -loaddspace_P.attuatore_Emax;
    b_s = loaddspace_P.attuatore_Emax + 0.1;
    u0 = loaddspace_B.Equilibratore;
    if (u0 > b_s) {
      /* Saturate: '<S2>/Saturation1' */
      loaddspace_B.deltaE_i = b_s;
    } else if (u0 < b_fmod) {
      /* Saturate: '<S2>/Saturation1' */
      loaddspace_B.deltaE_i = b_fmod;
    } else {
      /* Saturate: '<S2>/Saturation1' */
      loaddspace_B.deltaE_i = u0;
    }

    /* End of Saturate: '<S2>/Saturation1' */

    /* ManualSwitch generated from: '<Root>/Manual Switch' */
    loaddspace_B.deltaE = loaddspace_B.deltaE_i;
  } else {
    /* Saturate: '<S3>/Saturation1' */
    b_fmod = -loaddspace_P.attuatore_Emax;
    b_s = loaddspace_P.attuatore_Emax + 0.1;
    u0 = loaddspace_B.Equilibratore_o;
    if (u0 > b_s) {
      /* Saturate: '<S3>/Saturation1' */
      loaddspace_B.deltaE_b = b_s;
    } else if (u0 < b_fmod) {
      /* Saturate: '<S3>/Saturation1' */
      loaddspace_B.deltaE_b = b_fmod;
    } else {
      /* Saturate: '<S3>/Saturation1' */
      loaddspace_B.deltaE_b = u0;
    }

    /* End of Saturate: '<S3>/Saturation1' */

    /* ManualSwitch generated from: '<Root>/Manual Switch' */
    loaddspace_B.deltaE = loaddspace_B.deltaE_b;
  }

  /* Product: '<S60>/Product4' incorporates:
   *  Constant: '<S23>/CL_dE '
   */
  loaddspace_B.Product4 = loaddspace_P.CLdE * loaddspace_B.deltaE;

  /* Sum: '<S60>/Sum' */
  loaddspace_B.Sum_m = (loaddspace_B.uDLookupTable_k + loaddspace_B.y_ak) +
    loaddspace_B.Product4;

  /* Gain: '<S55>/Gain5' */
  loaddspace_B.CL = loaddspace_P.Gain5_Gain_e * loaddspace_B.Sum_m;

  /* SignalConversion generated from: '<S28>/Matrix Multiply' */
  loaddspace_B.TmpSignalConversionAtMatrixMult[0] = loaddspace_B.CD;
  loaddspace_B.TmpSignalConversionAtMatrixMult[1] = loaddspace_B.Sum_k;
  loaddspace_B.TmpSignalConversionAtMatrixMult[2] = loaddspace_B.CL;

  /* Product: '<S28>/Matrix Multiply' */
  memcpy(&dcmt[0], &loaddspace_B.Lbw[0], 9U * sizeof(real_T));
  Fape[0] = loaddspace_B.TmpSignalConversionAtMatrixMult[0];
  Fape[1] = loaddspace_B.TmpSignalConversionAtMatrixMult[1];
  Fape[2] = loaddspace_B.TmpSignalConversionAtMatrixMult[2];

  /* Product: '<S54>/Product' */
  loaddspace_B.Product_k = loaddspace_B.Va[0] * loaddspace_B.Va[0];

  /* Product: '<S54>/Product1' */
  loaddspace_B.Product1_l = loaddspace_B.Va[1] * loaddspace_B.Va[1];

  /* Product: '<S54>/Product2' */
  loaddspace_B.Product2_o = loaddspace_B.Va[2] * loaddspace_B.Va[2];

  /* Sum: '<S54>/Sum' */
  loaddspace_B.Sum_a = (loaddspace_B.Product_k + loaddspace_B.Product1_l) +
    loaddspace_B.Product2_o;
  for (i = 0; i < 3; i++) {
    /* Product: '<S28>/Matrix Multiply' */
    u2 = dcmt[i] * Fape[0];
    u2 += dcmt[i + 3] * Fape[1];
    u2 += dcmt[i + 6] * Fape[2];

    /* Product: '<S28>/Matrix Multiply' */
    loaddspace_B.FA_Bq[i] = u2;

    /* Integrator: '<S26>/xe,ye,ze' */
    loaddspace_B.xeyeze[i] = loaddspace_X.xeyeze_CSTATE[i];
  }

  /* Gain: '<S1>/Gain' */
  loaddspace_B.Gain_n1 = loaddspace_P.Gain_Gain_p * loaddspace_B.xeyeze[2];

  /* Saturate: '<S24>/Limit  altitude  to troposhere' */
  u0 = loaddspace_B.Gain_n1;
  u1 = loaddspace_P.Limitaltitudetotroposhere_Low_o;
  u2 = loaddspace_P.Limitaltitudetotroposhere_Upp_a;
  if (u0 > u2) {
    /* Saturate: '<S24>/Limit  altitude  to troposhere' */
    loaddspace_B.Limitaltitudetotroposhere_l = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S24>/Limit  altitude  to troposhere' */
    loaddspace_B.Limitaltitudetotroposhere_l = u1;
  } else {
    /* Saturate: '<S24>/Limit  altitude  to troposhere' */
    loaddspace_B.Limitaltitudetotroposhere_l = u0;
  }

  /* End of Saturate: '<S24>/Limit  altitude  to troposhere' */

  /* Gain: '<S24>/Lapse Rate' */
  loaddspace_B.LapseRate_g = loaddspace_P.LapseRate_Gain_n *
    loaddspace_B.Limitaltitudetotroposhere_l;

  /* Sum: '<S24>/Sum1' incorporates:
   *  Constant: '<S24>/Sea Level  Temperature'
   */
  loaddspace_B.Sum1_j = loaddspace_P.SeaLevelTemperature_Value_i -
    loaddspace_B.LapseRate_g;

  /* Gain: '<S24>/1//T0' */
  loaddspace_B.uT0_h = loaddspace_P.uT0_Gain_i * loaddspace_B.Sum1_j;

  /* Math: '<S24>/(T//T0)^(g//LR) ' incorporates:
   *  Constant: '<S24>/Constant'
   */
  b_fmod = loaddspace_B.uT0_h;
  b_s = loaddspace_P.Constant_Value_c;
  if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
    /* Math: '<S24>/(T//T0)^(g//LR) ' */
    loaddspace_B.TT0gLR_n = -rt_powd_snf(-b_fmod, b_s);
  } else {
    /* Math: '<S24>/(T//T0)^(g//LR) ' */
    loaddspace_B.TT0gLR_n = rt_powd_snf(b_fmod, b_s);
  }

  /* End of Math: '<S24>/(T//T0)^(g//LR) ' */

  /* Product: '<S24>/Product' */
  loaddspace_B.Product_a = loaddspace_B.TT0gLR_n / loaddspace_B.uT0_h;

  /* Gain: '<S24>/rho0' */
  loaddspace_B.rho0 = loaddspace_P.rho0_Gain * loaddspace_B.Product_a;

  /* Sum: '<S24>/Sum' incorporates:
   *  Constant: '<S24>/Altitude of Troposphere'
   */
  loaddspace_B.Sum_p = loaddspace_P.AltitudeofTroposphere_Value_p -
    loaddspace_B.Gain_n1;

  /* Saturate: '<S24>/Limit  altitude  to Stratosphere' */
  u0 = loaddspace_B.Sum_p;
  u1 = loaddspace_P.LimitaltitudetoStratosphere_L_k;
  u2 = loaddspace_P.LimitaltitudetoStratosphere_U_o;
  if (u0 > u2) {
    /* Saturate: '<S24>/Limit  altitude  to Stratosphere' */
    loaddspace_B.LimitaltitudetoStratosphere_i = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S24>/Limit  altitude  to Stratosphere' */
    loaddspace_B.LimitaltitudetoStratosphere_i = u1;
  } else {
    /* Saturate: '<S24>/Limit  altitude  to Stratosphere' */
    loaddspace_B.LimitaltitudetoStratosphere_i = u0;
  }

  /* End of Saturate: '<S24>/Limit  altitude  to Stratosphere' */

  /* Gain: '<S24>/g//R' */
  loaddspace_B.gR_j = loaddspace_P.gR_Gain_i *
    loaddspace_B.LimitaltitudetoStratosphere_i;

  /* Product: '<S24>/Product1' */
  loaddspace_B.Product1_f = 1.0 / loaddspace_B.Sum1_j * loaddspace_B.gR_j;

  /* Math: '<S24>/Stratosphere Model'
   *
   * About '<S24>/Stratosphere Model':
   *  Operator: exp
   */
  loaddspace_B.StratosphereModel_c = exp(loaddspace_B.Product1_f);

  /* Product: '<S24>/Product3' */
  loaddspace_B.Product3_f = loaddspace_B.rho0 * loaddspace_B.StratosphereModel_c;

  /* Product: '<S27>/Product2' */
  loaddspace_B.Product2_k = loaddspace_B.Sum_a * loaddspace_B.Product3_f;

  /* Gain: '<S27>/1//2rhoV^2' */
  loaddspace_B.u2rhoV2 = loaddspace_P.u2rhoV2_Gain * loaddspace_B.Product2_k;

  /* Product: '<S28>/Product' incorporates:
   *  Constant: '<S23>/S'
   */
  loaddspace_B.Product_ks[0] = loaddspace_P.S * loaddspace_B.FA_Bq[0] *
    loaddspace_B.u2rhoV2;
  loaddspace_B.Product_ks[1] = loaddspace_P.S * loaddspace_B.FA_Bq[1] *
    loaddspace_B.u2rhoV2;
  loaddspace_B.Product_ks[2] = loaddspace_P.S * loaddspace_B.FA_Bq[2] *
    loaddspace_B.u2rhoV2;

  /* Lookup_n-D: '<S64>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  loaddspace_B.uDLookupTable_m = look2_binlxpw(loaddspace_B.u, loaddspace_B.u_m,
    loaddspace_P.alphavec_rad, loaddspace_P.betavec_rad,
    loaddspace_P.uDLookupTable_tableData_d,
    loaddspace_P.uDLookupTable_maxIndex_d, 13U);

  /* Gain: '<S64>/Gain4' */
  loaddspace_B.Gain4_k = loaddspace_P.Gain4_Gain_c *
    loaddspace_B.uDLookupTable_m;

  /* SignalConversion generated from: '<S67>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S64>/controllo divisione per zero lp '
   */
  b_fmod = loaddspace_P.b / 2.0;

  /* SignalConversion generated from: '<S67>/ SFunction ' incorporates:
   *  Constant: '<S23>/Cl_p '
   *  MATLAB Function: '<S64>/controllo divisione per zero lp '
   */
  loaddspace_B.TmpSignalConversionAtSFunctio_k[0] = loaddspace_P.Clp;
  loaddspace_B.TmpSignalConversionAtSFunctio_k[1] = loaddspace_B.pqr[0];
  loaddspace_B.TmpSignalConversionAtSFunctio_k[2] = b_fmod;
  loaddspace_B.TmpSignalConversionAtSFunctio_k[3] = loaddspace_B.module;

  /* MATLAB Function: '<S64>/controllo divisione per zero lp ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem3/controllo divisione per zero lp ': '<S67>:1' */
  if (loaddspace_B.TmpSignalConversionAtSFunctio_k[3] == 0.0) {
    /* '<S67>:1:6' */
    /* '<S67>:1:7' */
    loaddspace_B.y_n = 0.0;
  } else {
    /* '<S67>:1:9' */
    loaddspace_B.y_n = loaddspace_B.TmpSignalConversionAtSFunctio_k[0] *
      loaddspace_B.TmpSignalConversionAtSFunctio_k[1] *
      loaddspace_B.TmpSignalConversionAtSFunctio_k[2] /
      loaddspace_B.TmpSignalConversionAtSFunctio_k[3];
  }

  /* SignalConversion generated from: '<S68>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S64>/controllo divisione per zero lr '
   */
  b_fmod = loaddspace_P.b / 2.0;

  /* SignalConversion generated from: '<S68>/ SFunction ' incorporates:
   *  Constant: '<S23>/Cl_r '
   *  MATLAB Function: '<S64>/controllo divisione per zero lr '
   */
  loaddspace_B.TmpSignalConversionAtSFunctio_f[0] = loaddspace_P.Clr;
  loaddspace_B.TmpSignalConversionAtSFunctio_f[1] = b_fmod;
  loaddspace_B.TmpSignalConversionAtSFunctio_f[2] = loaddspace_B.pqr[2];
  loaddspace_B.TmpSignalConversionAtSFunctio_f[3] = loaddspace_B.module;

  /* MATLAB Function: '<S64>/controllo divisione per zero lr ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem3/controllo divisione per zero lr ': '<S68>:1' */
  if (loaddspace_B.TmpSignalConversionAtSFunctio_f[3] == 0.0) {
    /* '<S68>:1:6' */
    /* '<S68>:1:7' */
    loaddspace_B.y_o = 0.0;
  } else {
    /* '<S68>:1:9' */
    loaddspace_B.y_o = loaddspace_B.TmpSignalConversionAtSFunctio_f[0] *
      loaddspace_B.TmpSignalConversionAtSFunctio_f[1] *
      loaddspace_B.TmpSignalConversionAtSFunctio_f[2] /
      loaddspace_B.TmpSignalConversionAtSFunctio_f[3];
  }

  /* Product: '<S64>/Product2' incorporates:
   *  Constant: '<S23>/Cl_dA'
   */
  loaddspace_B.Product2_c = loaddspace_P.CldA * loaddspace_B.deltaA;

  /* Product: '<S64>/Product3' incorporates:
   *  Constant: '<S23>/Cl_dR'
   */
  loaddspace_B.Product3_e = loaddspace_P.CldR * loaddspace_B.deltaR;

  /* Sum: '<S64>/Sum' */
  loaddspace_B.Sum_n = (((loaddspace_B.Gain4_k + loaddspace_B.y_n) +
    loaddspace_B.y_o) + loaddspace_B.Product2_c) + loaddspace_B.Product3_e;

  /* Product: '<S57>/Product' incorporates:
   *  Constant: '<S23>/S*b '
   */
  b_fmod = loaddspace_P.S * loaddspace_P.b;

  /* Product: '<S57>/Product' */
  loaddspace_B.Cl = b_fmod * loaddspace_B.Sum_n;

  /* Lookup_n-D: '<S65>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  loaddspace_B.uDLookupTable_km = look2_binlxpw(loaddspace_B.u, loaddspace_B.u_m,
    loaddspace_P.alphavec_rad, loaddspace_P.betavec_rad,
    loaddspace_P.uDLookupTable_tableData_c,
    loaddspace_P.uDLookupTable_maxIndex_d3, 13U);

  /* Gain: '<S65>/Gain1' */
  loaddspace_B.Gain1_o = loaddspace_P.Gain1_Gain_p * loaddspace_B.module;

  /* SignalConversion generated from: '<S69>/ SFunction ' incorporates:
   *  Constant: '<S23>/Cm_q '
   *  Constant: '<S23>/cbar '
   *  MATLAB Function: '<S65>/controllo divisione per zero mq '
   */
  loaddspace_B.TmpSignalConversionAtSFunctio_o[0] = loaddspace_P.Cmq;
  loaddspace_B.TmpSignalConversionAtSFunctio_o[1] = loaddspace_B.pqr[1];
  loaddspace_B.TmpSignalConversionAtSFunctio_o[2] = loaddspace_P.cbar;
  loaddspace_B.TmpSignalConversionAtSFunctio_o[3] = loaddspace_B.Gain1_o;

  /* MATLAB Function: '<S65>/controllo divisione per zero mq ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem4/controllo divisione per zero mq ': '<S69>:1' */
  if (loaddspace_B.TmpSignalConversionAtSFunctio_o[3] == 0.0) {
    /* '<S69>:1:6' */
    /* '<S69>:1:7' */
    loaddspace_B.y_cl = 0.0;
  } else {
    /* '<S69>:1:9' */
    loaddspace_B.y_cl = loaddspace_B.TmpSignalConversionAtSFunctio_o[0] *
      loaddspace_B.TmpSignalConversionAtSFunctio_o[1] *
      loaddspace_B.TmpSignalConversionAtSFunctio_o[2] /
      loaddspace_B.TmpSignalConversionAtSFunctio_o[3];
  }

  /* Product: '<S65>/Product2' incorporates:
   *  Constant: '<S23>/Cm_dE '
   */
  loaddspace_B.Product2_j = loaddspace_P.CmdE * loaddspace_B.deltaE;

  /* Sum: '<S65>/Sum' */
  loaddspace_B.Sum_hs = (loaddspace_B.uDLookupTable_km + loaddspace_B.y_cl) +
    loaddspace_B.Product2_j;

  /* Product: '<S57>/Product1' incorporates:
   *  Constant: '<S23>/S*cbar'
   */
  b_fmod = loaddspace_P.S * loaddspace_P.cbar;

  /* Product: '<S57>/Product1' */
  loaddspace_B.Cm = b_fmod * loaddspace_B.Sum_hs;

  /* Lookup_n-D: '<S66>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  loaddspace_B.uDLookupTable_i = look2_binlxpw(loaddspace_B.u, loaddspace_B.u_m,
    loaddspace_P.alphavec_rad, loaddspace_P.betavec_rad,
    loaddspace_P.uDLookupTable_tableData_h,
    loaddspace_P.uDLookupTable_maxIndex_j, 13U);

  /* SignalConversion generated from: '<S70>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S66>/controllo divisione per zero np '
   */
  b_fmod = loaddspace_P.b / 2.0;

  /* SignalConversion generated from: '<S70>/ SFunction ' incorporates:
   *  Constant: '<S23>/Cn_p '
   *  MATLAB Function: '<S66>/controllo divisione per zero np '
   */
  loaddspace_B.TmpSignalConversionAtSFunctio_a[0] = loaddspace_P.Cnp;
  loaddspace_B.TmpSignalConversionAtSFunctio_a[1] = loaddspace_B.pqr[0];
  loaddspace_B.TmpSignalConversionAtSFunctio_a[2] = b_fmod;
  loaddspace_B.TmpSignalConversionAtSFunctio_a[3] = loaddspace_B.module;

  /* MATLAB Function: '<S66>/controllo divisione per zero np ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem5/controllo divisione per zero np ': '<S70>:1' */
  if (loaddspace_B.TmpSignalConversionAtSFunctio_a[3] == 0.0) {
    /* '<S70>:1:6' */
    /* '<S70>:1:7' */
    loaddspace_B.y_a = 0.0;
  } else {
    /* '<S70>:1:9' */
    loaddspace_B.y_a = loaddspace_B.TmpSignalConversionAtSFunctio_a[0] *
      loaddspace_B.TmpSignalConversionAtSFunctio_a[1] *
      loaddspace_B.TmpSignalConversionAtSFunctio_a[2] /
      loaddspace_B.TmpSignalConversionAtSFunctio_a[3];
  }

  /* SignalConversion generated from: '<S71>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S66>/controllo divisione per zero nr '
   */
  b_fmod = loaddspace_P.b / 2.0;

  /* SignalConversion generated from: '<S71>/ SFunction ' incorporates:
   *  Constant: '<S23>/Cn_r '
   *  MATLAB Function: '<S66>/controllo divisione per zero nr '
   */
  loaddspace_B.TmpSignalConversionAtSFunctio_m[0] = loaddspace_P.Cnr;
  loaddspace_B.TmpSignalConversionAtSFunctio_m[1] = loaddspace_B.pqr[2];
  loaddspace_B.TmpSignalConversionAtSFunctio_m[2] = b_fmod;
  loaddspace_B.TmpSignalConversionAtSFunctio_m[3] = loaddspace_B.module;

  /* MATLAB Function: '<S66>/controllo divisione per zero nr ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem5/controllo divisione per zero nr ': '<S71>:1' */
  if (loaddspace_B.TmpSignalConversionAtSFunctio_m[3] == 0.0) {
    /* '<S71>:1:6' */
    /* '<S71>:1:7' */
    loaddspace_B.y_cd = 0.0;
  } else {
    /* '<S71>:1:9' */
    loaddspace_B.y_cd = loaddspace_B.TmpSignalConversionAtSFunctio_m[0] *
      loaddspace_B.TmpSignalConversionAtSFunctio_m[1] *
      loaddspace_B.TmpSignalConversionAtSFunctio_m[2] /
      loaddspace_B.TmpSignalConversionAtSFunctio_m[3];
  }

  /* Product: '<S66>/Product2' incorporates:
   *  Constant: '<S23>/Cn_dA'
   */
  loaddspace_B.Product2_p = loaddspace_P.CndA * loaddspace_B.deltaA;

  /* Product: '<S66>/Product3' incorporates:
   *  Constant: '<S23>/Cn_dR '
   */
  loaddspace_B.Product3_c = loaddspace_P.CndR * loaddspace_B.deltaR;

  /* Sum: '<S66>/Sum' */
  loaddspace_B.Sum_hu = (((loaddspace_B.uDLookupTable_i + loaddspace_B.y_a) +
    loaddspace_B.y_cd) + loaddspace_B.Product2_p) + loaddspace_B.Product3_c;

  /* Product: '<S57>/Product3' incorporates:
   *  Constant: '<S23>/S*b '
   */
  b_fmod = loaddspace_P.S * loaddspace_P.b;

  /* Product: '<S57>/Product3' */
  loaddspace_B.Cn = b_fmod * loaddspace_B.Sum_hu;

  /* Product: '<S28>/Product2' */
  loaddspace_B.Product2_i[0] = loaddspace_B.u2rhoV2 * loaddspace_B.Cl;
  loaddspace_B.Product2_i[1] = loaddspace_B.u2rhoV2 * loaddspace_B.Cm;
  loaddspace_B.Product2_i[2] = loaddspace_B.u2rhoV2 * loaddspace_B.Cn;

  /* Product: '<S35>/Product3' incorporates:
   *  Constant: '<S23>/W'
   *  Reshape: '<S46>/Reshape (9) to [3x3] column-major'
   */
  memcpy(&dcmt[0], &loaddspace_B.Reshape9to3x3columnmajor[0], 9U * sizeof(real_T));
  Fape[0] = loaddspace_P.W[0];
  Fape[1] = loaddspace_P.W[1];
  Fape[2] = loaddspace_P.W[2];
  for (i = 0; i < 3; i++) {
    u2 = dcmt[i] * Fape[0];
    u2 += dcmt[i + 3] * Fape[1];
    u2 += dcmt[i + 6] * Fape[2];

    /* Product: '<S35>/Product3' */
    loaddspace_B.Product3_l[i] = u2;
  }

  /* End of Product: '<S35>/Product3' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitDelay: '<S31>/Unit Delay' */
    loaddspace_B.UnitDelay = loaddspace_DW.UnitDelay_DSTATE;

    /* Gain: '<S31>/RPM->RPs' */
    loaddspace_B.RPMRPs = loaddspace_P.RPMRPs_Gain * loaddspace_B.UnitDelay;

    /* Math: '<S31>/Math Function3' incorporates:
     *  Constant: '<S31>/Constant'
     */
    b_fmod = loaddspace_B.RPMRPs;
    b_s = loaddspace_P.Constant_Value_n;
    if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
      /* Math: '<S31>/Math Function3' */
      loaddspace_B.MathFunction3 = -rt_powd_snf(-b_fmod, b_s);
    } else {
      /* Math: '<S31>/Math Function3' */
      loaddspace_B.MathFunction3 = rt_powd_snf(b_fmod, b_s);
    }

    /* End of Math: '<S31>/Math Function3' */

    /* Math: '<S31>/Math Function' incorporates:
     *  Constant: '<S23>/Dprop'
     *  Constant: '<S31>/Constant1'
     */
    b_fmod = loaddspace_P.Dprop;
    b_s = loaddspace_P.Constant1_Value;
    if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
      /* Math: '<S31>/Math Function' */
      loaddspace_B.MathFunction_c = -rt_powd_snf(-b_fmod, b_s);
    } else {
      /* Math: '<S31>/Math Function' */
      loaddspace_B.MathFunction_c = rt_powd_snf(b_fmod, b_s);
    }

    /* End of Math: '<S31>/Math Function' */
  }

  /* Product: '<S31>/Product1' incorporates:
   *  Constant: '<S23>/Dprop'
   */
  loaddspace_B.Product1_m = 1.0 / loaddspace_B.RPMRPs * loaddspace_B.module /
    loaddspace_P.Dprop;

  /* Lookup_n-D: '<S75>/2-D Lookup Table' incorporates:
   *  Product: '<S31>/Product1'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  loaddspace_B.uDLookupTable_b = look2_binlxpw(loaddspace_B.Product1_m,
    loaddspace_B.UnitDelay, loaddspace_P.J_vec,
    loaddspace_P.uDLookupTable_bp02Data, loaddspace_P.uDLookupTable_tableData_f,
    loaddspace_P.uDLookupTable_maxIndex_nw, 30U);

  /* Product: '<S31>/Product2' */
  loaddspace_B.Product2_f = loaddspace_B.MathFunction3 *
    loaddspace_B.MathFunction_c * loaddspace_B.Product3_f *
    loaddspace_B.uDLookupTable_b;

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S76>/Constant'
   */
  loaddspace_B.F[0] = (loaddspace_B.Product3_l[0] + loaddspace_B.Product_ks[0])
    + loaddspace_B.Product2_f;
  loaddspace_B.F[1] = (loaddspace_B.Product3_l[1] + loaddspace_B.Product_ks[1])
    + loaddspace_P.Constant_Value_i4;
  loaddspace_B.F[2] = (loaddspace_B.Product3_l[2] + loaddspace_B.Product_ks[2])
    + loaddspace_P.Constant_Value_i4;
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Concatenate: '<S38>/Vector Concatenate' incorporates:
       *  Constant: '<S38>/Constant1'
       *  Constant: '<S38>/Constant2'
       */
      loaddspace_B.VectorConcatenate_m[6 * i] = loaddspace_P.I[3 * i];
      loaddspace_B.VectorConcatenate_m[6 * i + 3] =
        loaddspace_P.Constant2_Value_l[3 * i];

      /* Selector: '<S37>/Selector' incorporates:
       *  Concatenate: '<S38>/Vector Concatenate'
       */
      loaddspace_B.Selector[3 * i] = loaddspace_B.VectorConcatenate_m[6 * i];

      /* Concatenate: '<S38>/Vector Concatenate' incorporates:
       *  Constant: '<S38>/Constant1'
       *  Constant: '<S38>/Constant2'
       */
      loaddspace_B.VectorConcatenate_m[6 * i + 1] = loaddspace_P.I[3 * i + 1];
      loaddspace_B.VectorConcatenate_m[6 * i + 4] =
        loaddspace_P.Constant2_Value_l[3 * i + 1];

      /* Selector: '<S37>/Selector' incorporates:
       *  Concatenate: '<S38>/Vector Concatenate'
       */
      loaddspace_B.Selector[3 * i + 1] = loaddspace_B.VectorConcatenate_m[6 * i
        + 1];

      /* Concatenate: '<S38>/Vector Concatenate' incorporates:
       *  Constant: '<S38>/Constant1'
       *  Constant: '<S38>/Constant2'
       */
      loaddspace_B.VectorConcatenate_m[6 * i + 2] = loaddspace_P.I[3 * i + 2];
      loaddspace_B.VectorConcatenate_m[6 * i + 5] =
        loaddspace_P.Constant2_Value_l[3 * i + 2];

      /* Selector: '<S37>/Selector' incorporates:
       *  Concatenate: '<S38>/Vector Concatenate'
       */
      loaddspace_B.Selector[3 * i + 2] = loaddspace_B.VectorConcatenate_m[6 * i
        + 2];
    }
  }

  /* Trigonometry: '<S45>/sincos' */
  b_s = loaddspace_B.phithetapsi[0];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  loaddspace_B.sincos_o1_g[0] = b_fmod;
  loaddspace_B.sincos_o2_m[0] = b_s;
  b_s = loaddspace_B.phithetapsi[1];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  loaddspace_B.sincos_o1_g[1] = b_fmod;
  loaddspace_B.sincos_o2_m[1] = b_s;
  b_s = loaddspace_B.phithetapsi[2];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  loaddspace_B.sincos_o1_g[2] = b_fmod;
  loaddspace_B.sincos_o2_m[2] = b_s;

  /* Fcn: '<S45>/phidot' */
  loaddspace_B.phidot = (loaddspace_B.pqr[1] * loaddspace_B.sincos_o1_g[0] +
    loaddspace_B.pqr[2] * loaddspace_B.sincos_o2_m[0]) *
    (loaddspace_B.sincos_o1_g[1] / loaddspace_B.sincos_o2_m[1]) +
    loaddspace_B.pqr[0];

  /* Fcn: '<S45>/thetadot' */
  loaddspace_B.thetadot = loaddspace_B.pqr[1] * loaddspace_B.sincos_o2_m[0] -
    loaddspace_B.pqr[2] * loaddspace_B.sincos_o1_g[0];

  /* Fcn: '<S45>/psidot' */
  loaddspace_B.psidot = (loaddspace_B.pqr[1] * loaddspace_B.sincos_o1_g[0] +
    loaddspace_B.pqr[2] * loaddspace_B.sincos_o2_m[0]) /
    loaddspace_B.sincos_o2_m[1];

  /* SignalConversion generated from: '<S36>/phi theta psi' */
  loaddspace_B.TmpSignalConversionAtphithetaps[0] = loaddspace_B.phidot;
  loaddspace_B.TmpSignalConversionAtphithetaps[1] = loaddspace_B.thetadot;
  loaddspace_B.TmpSignalConversionAtphithetaps[2] = loaddspace_B.psidot;

  /* Reshape: '<S48>/Reshape1' */
  loaddspace_B.Reshape1_k[0] = loaddspace_B.pqr[0];
  loaddspace_B.Reshape1_k[1] = loaddspace_B.pqr[1];
  loaddspace_B.Reshape1_k[2] = loaddspace_B.pqr[2];

  /* Product: '<S48>/Product' incorporates:
   *  Reshape: '<S48>/Reshape1'
   *  Selector: '<S37>/Selector'
   */
  memcpy(&dcmt[0], &loaddspace_B.Selector[0], 9U * sizeof(real_T));
  Fape[0] = loaddspace_B.Reshape1_k[0];
  Fape[1] = loaddspace_B.Reshape1_k[1];
  Fape[2] = loaddspace_B.Reshape1_k[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S48>/Product' */
    loaddspace_B.Product_f[i] = 0.0;
    loaddspace_B.Product_f[i] += dcmt[i] * Fape[0];
    loaddspace_B.Product_f[i] += dcmt[i + 3] * Fape[1];
    loaddspace_B.Product_f[i] += dcmt[i + 6] * Fape[2];

    /* Reshape: '<S48>/Reshape2' incorporates:
     *  Product: '<S48>/Product'
     */
    loaddspace_B.Reshape2_a[i] = loaddspace_B.Product_f[i];
  }

  /* Product: '<S50>/i x j' */
  loaddspace_B.ixj = loaddspace_B.pqr[0] * loaddspace_B.Reshape2_a[1];

  /* Product: '<S50>/j x k' */
  loaddspace_B.jxk = loaddspace_B.pqr[1] * loaddspace_B.Reshape2_a[2];

  /* Product: '<S50>/k x i' */
  loaddspace_B.kxi = loaddspace_B.pqr[2] * loaddspace_B.Reshape2_a[0];

  /* Product: '<S51>/i x k' */
  loaddspace_B.ixk = loaddspace_B.pqr[0] * loaddspace_B.Reshape2_a[2];

  /* Product: '<S51>/j x i' */
  loaddspace_B.jxi = loaddspace_B.pqr[1] * loaddspace_B.Reshape2_a[0];

  /* Product: '<S51>/k x j' */
  loaddspace_B.kxj = loaddspace_B.pqr[2] * loaddspace_B.Reshape2_a[1];

  /* Sum: '<S47>/Sum' */
  loaddspace_B.Sum_o[0] = loaddspace_B.jxk - loaddspace_B.kxj;
  loaddspace_B.Sum_o[1] = loaddspace_B.kxi - loaddspace_B.ixk;
  loaddspace_B.Sum_o[2] = loaddspace_B.ixj - loaddspace_B.jxi;
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Selector: '<S37>/Selector1' incorporates:
       *  Concatenate: '<S38>/Vector Concatenate'
       */
      loaddspace_B.Selector1[3 * i] = loaddspace_B.VectorConcatenate_m[6 * i + 3];
      loaddspace_B.Selector1[3 * i + 1] = loaddspace_B.VectorConcatenate_m[6 * i
        + 4];
      loaddspace_B.Selector1[3 * i + 2] = loaddspace_B.VectorConcatenate_m[6 * i
        + 5];
    }
  }

  /* Reshape: '<S49>/Reshape1' */
  loaddspace_B.Reshape1_l[0] = loaddspace_B.pqr[0];
  loaddspace_B.Reshape1_l[1] = loaddspace_B.pqr[1];
  loaddspace_B.Reshape1_l[2] = loaddspace_B.pqr[2];

  /* Product: '<S49>/Product' incorporates:
   *  Reshape: '<S49>/Reshape1'
   *  Selector: '<S37>/Selector1'
   */
  memcpy(&dcmt[0], &loaddspace_B.Selector1[0], 9U * sizeof(real_T));
  Fape[0] = loaddspace_B.Reshape1_l[0];
  Fape[1] = loaddspace_B.Reshape1_l[1];
  Fape[2] = loaddspace_B.Reshape1_l[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S49>/Product' */
    loaddspace_B.Product_p[i] = 0.0;
    loaddspace_B.Product_p[i] += dcmt[i] * Fape[0];
    loaddspace_B.Product_p[i] += dcmt[i + 3] * Fape[1];
    loaddspace_B.Product_p[i] += dcmt[i + 6] * Fape[2];

    /* Reshape: '<S49>/Reshape2' incorporates:
     *  Product: '<S49>/Product'
     */
    loaddspace_B.Reshape2_i[i] = loaddspace_B.Product_p[i];
  }

  /* Lookup_n-D: '<S75>/2-D Lookup Table1' incorporates:
   *  Product: '<S31>/Product1'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  loaddspace_B.uDLookupTable1 = look2_binlxpw(loaddspace_B.Product1_m,
    loaddspace_B.UnitDelay, loaddspace_P.J_vec,
    loaddspace_P.uDLookupTable1_bp02Data, loaddspace_P.uDLookupTable1_tableData,
    loaddspace_P.uDLookupTable1_maxIndex, 30U);
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S31>/Math Function2' incorporates:
     *  Constant: '<S23>/Dprop'
     *  Constant: '<S31>/Constant3'
     */
    b_fmod = loaddspace_P.Dprop;
    b_s = loaddspace_P.Constant3_Value_h;
    if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
      /* Math: '<S31>/Math Function2' */
      loaddspace_B.MathFunction2 = -rt_powd_snf(-b_fmod, b_s);
    } else {
      /* Math: '<S31>/Math Function2' */
      loaddspace_B.MathFunction2 = rt_powd_snf(b_fmod, b_s);
    }

    /* End of Math: '<S31>/Math Function2' */

    /* Math: '<S31>/Math Function1' incorporates:
     *  Constant: '<S31>/Constant2'
     */
    b_fmod = loaddspace_B.RPMRPs;
    b_s = loaddspace_P.Constant2_Value_p;
    if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
      /* Math: '<S31>/Math Function1' */
      loaddspace_B.MathFunction1_c = -rt_powd_snf(-b_fmod, b_s);
    } else {
      /* Math: '<S31>/Math Function1' */
      loaddspace_B.MathFunction1_c = rt_powd_snf(b_fmod, b_s);
    }

    /* End of Math: '<S31>/Math Function1' */

    /* Gain: '<S76>/Gain' */
    loaddspace_B.Gain_gk = loaddspace_P.Gain_Gain_lp * loaddspace_B.RPMRPs;
  }

  /* Product: '<S31>/Product3' */
  loaddspace_B.Product3_i = loaddspace_B.uDLookupTable1 *
    loaddspace_B.Product3_f * loaddspace_B.MathFunction2 *
    loaddspace_B.MathFunction1_c;

  /* Product: '<S76>/Divide' */
  loaddspace_B.Divide_b = loaddspace_B.Product3_i / loaddspace_B.Gain_gk;

  /* Gain: '<S76>/Gain1' */
  loaddspace_B.Gain1_f = loaddspace_P.Gain1_Gain_c * loaddspace_B.Divide_b;

  /* Product: '<S76>/Divide1' incorporates:
   *  Constant: '<S23>/Zeng'
   */
  loaddspace_B.Divide1 = loaddspace_P.Zeng * loaddspace_B.Product2_f;

  /* Sum: '<S22>/Sum1' incorporates:
   *  Constant: '<S76>/Constant1'
   */
  loaddspace_B.Sum1_i[0] = loaddspace_B.Gain1_f + loaddspace_B.Product2_i[0];
  loaddspace_B.Sum1_i[1] = loaddspace_B.Divide1 + loaddspace_B.Product2_i[1];
  loaddspace_B.Sum1_i[2] = loaddspace_P.Constant1_Value_m +
    loaddspace_B.Product2_i[2];
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    loaddspace_B.DiscreteTimeIntegrator_c =
      loaddspace_DW.DiscreteTimeIntegrator_DSTATE_d;

    /* Switch: '<S18>/Switch' */
    if (loaddspace_B.DiscreteTimeIntegrator_c > loaddspace_P.Switch_Threshold_e)
    {
      /* Switch: '<S18>/Switch' */
      loaddspace_B.Switch_k = loaddspace_B.h_ground;
    } else {
      /* Switch: '<S18>/Switch' incorporates:
       *  Constant: '<S18>/Constant3'
       */
      loaddspace_B.Switch_k = loaddspace_P.Constant3_Value_i;
    }

    /* End of Switch: '<S18>/Switch' */
  }

  /* MATLAB Function: '<S29>/MATLAB Function' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant4'
   *  Constant: '<S23>/cmg'
   *  Constant: '<S23>/cng'
   *  Constant: '<S23>/kmg'
   *  Constant: '<S23>/kng'
   */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Gear/MATLAB Function': '<S72>:1' */
  /* '<S72>:1:20' */
  /* '<S72>:1:22' */
  tmp_f = cos(loaddspace_B.phithetapsi[2]);
  u2 = cos(loaddspace_B.phithetapsi[1]);
  u0 = cos(loaddspace_B.phithetapsi[1]);
  diffLm = sin(loaddspace_B.phithetapsi[2]);
  Fss = sin(loaddspace_B.phithetapsi[1]);
  Frms = sin(loaddspace_B.phithetapsi[0]);
  b_s = sin(loaddspace_B.phithetapsi[1]);
  b_fmod = cos(loaddspace_B.phithetapsi[2]);
  Mye = cos(loaddspace_B.phithetapsi[0]);
  u1 = sin(loaddspace_B.phithetapsi[2]);
  Fsd = sin(loaddspace_B.phithetapsi[0]);
  Frmd = sin(loaddspace_B.phithetapsi[1]);
  tmp_g = sin(loaddspace_B.phithetapsi[2]);
  tmp = cos(loaddspace_B.phithetapsi[0]);
  tmp_0 = cos(loaddspace_B.phithetapsi[2]);
  tmp_1 = sin(loaddspace_B.phithetapsi[0]);
  tmp_2 = cos(loaddspace_B.phithetapsi[1]);
  tmp_3 = cos(loaddspace_B.phithetapsi[0]);
  tmp_4 = sin(loaddspace_B.phithetapsi[1]);
  tmp_5 = cos(loaddspace_B.phithetapsi[2]);
  tmp_6 = sin(loaddspace_B.phithetapsi[0]);
  tmp_7 = sin(loaddspace_B.phithetapsi[2]);
  tmp_8 = cos(loaddspace_B.phithetapsi[0]);
  tmp_9 = sin(loaddspace_B.phithetapsi[1]);
  tmp_a = sin(loaddspace_B.phithetapsi[2]);
  tmp_b = sin(loaddspace_B.phithetapsi[0]);
  tmp_c = cos(loaddspace_B.phithetapsi[2]);
  tmp_d = cos(loaddspace_B.phithetapsi[0]);
  tmp_e = cos(loaddspace_B.phithetapsi[1]);
  dcmt[0] = tmp_f * u2;
  dcmt[1] = u0 * diffLm;
  dcmt[2] = -Fss;
  dcmt[3] = Frms * b_s * b_fmod - Mye * u1;
  dcmt[4] = Fsd * Frmd * tmp_g + tmp * tmp_0;
  dcmt[5] = tmp_1 * tmp_2;
  dcmt[6] = tmp_3 * tmp_4 * tmp_5 + tmp_6 * tmp_7;
  dcmt[7] = tmp_8 * tmp_9 * tmp_a - tmp_b * tmp_c;
  dcmt[8] = tmp_d * tmp_e;

  /* '<S72>:1:23' */
  /* '<S72>:1:24' */
  /* '<S72>:1:25' */
  /* '<S72>:1:26' */
  for (i = 0; i < 3; i++) {
    tmp_f = dcmt[i] * loaddspace_P.rngG[0];
    tmp_f += dcmt[i + 3] * loaddspace_P.rngG[1];
    tmp_f += dcmt[i + 6] * loaddspace_P.rngG[2];
    Fape[i] = tmp_f + loaddspace_B.xeyeze[i];
  }

  b_fmod = Fape[2] - loaddspace_B.Switch_k;
  if (!(b_fmod > 0.0)) {
    /* '<S72>:1:29' */
    b_fmod = 0.0;
  } else {
    /* '<S72>:1:27' */
    /* '<S72>:1:28' */
  }

  /* '<S72>:1:31' */
  for (i = 0; i < 3; i++) {
    tmp_f = dcmt[i] * loaddspace_P.rmgrG[0];
    tmp_f += dcmt[i + 3] * loaddspace_P.rmgrG[1];
    tmp_f += dcmt[i + 6] * loaddspace_P.rmgrG[2];
    Fape[i] = tmp_f + loaddspace_B.xeyeze[i];
  }

  b_s = Fape[2] - loaddspace_B.Switch_k;
  if (b_s > 0.0) {
    /* '<S72>:1:32' */
    /* '<S72>:1:33' */
    Mye = b_s;
  } else {
    /* '<S72>:1:34' */
    Mye = 0.0;
  }

  /* '<S72>:1:36' */
  for (i = 0; i < 3; i++) {
    tmp_f = dcmt[i] * loaddspace_P.rmglG[0];
    tmp_f += dcmt[i + 3] * loaddspace_P.rmglG[1];
    tmp_f += dcmt[i + 6] * loaddspace_P.rmglG[2];
    Fape[i] = tmp_f + loaddspace_B.xeyeze[i];
  }

  diffLm = Fape[2] - loaddspace_B.Switch_k;
  if (!(diffLm > 0.0)) {
    /* '<S72>:1:39' */
    diffLm = 0.0;
  } else {
    /* '<S72>:1:37' */
    /* '<S72>:1:38' */
  }

  if (b_fmod <= 0.007) {
    /* '<S72>:1:41' */
    /* '<S72>:1:42' */
    Fss = loaddspace_P.kng_Value * b_fmod;
  } else {
    /* '<S72>:1:43' */
    Fss = 1.0 / (0.02 - b_fmod) * 0.0837 + loaddspace_P.kng_Value * b_fmod;
  }

  if (Mye <= 0.007) {
    /* '<S72>:1:45' */
    /* '<S72>:1:46' */
    Frms = loaddspace_P.kmg_Value * Mye;
  } else {
    /* '<S72>:1:47' */
    Frms = 1.0 / (0.02 - Mye) * 0.0912 + loaddspace_P.kmg_Value * Mye;
  }

  if (diffLm <= 0.007) {
    /* '<S72>:1:49' */
    /* '<S72>:1:50' */
    u1 = loaddspace_P.kmg_Value * diffLm;
  } else {
    /* '<S72>:1:51' */
    u1 = 1.0 / (0.02 - diffLm) * 0.0912 + loaddspace_P.kmg_Value * diffLm;
  }

  /* '<S72>:1:53' */
  /* '<S72>:1:54' */
  /* '<S72>:1:55' */
  /* '<S72>:1:56' */
  /* '<S72>:1:57' */
  /* '<S72>:1:58' */
  if (b_fmod > 0.05) {
    /* '<S72>:1:59' */
    /* '<S72>:1:60' */
    tmp_f = loaddspace_B.pqr[1] * loaddspace_P.rngG[2] - loaddspace_B.pqr[2] *
      loaddspace_P.rngG[1];
    u2 = loaddspace_B.pqr[2] * loaddspace_P.rngG[0] - loaddspace_B.pqr[0] *
      loaddspace_P.rngG[2];
    u0 = loaddspace_B.pqr[0] * loaddspace_P.rngG[1] - loaddspace_B.pqr[1] *
      loaddspace_P.rngG[0];
    tmp_f += loaddspace_B.UnitConversion[0];
    u2 += loaddspace_B.UnitConversion[1];
    tmp_g = loaddspace_B.UnitConversion[2] + u0;
    for (i = 0; i < 3; i++) {
      u0 = dcmt[i] * tmp_f;
      u0 += dcmt[i + 3] * u2;
      u0 += dcmt[i + 6] * tmp_g;
      Fape[i] = u0;
    }

    Fsd = Fape[2] * loaddspace_P.cng_Value;
  } else {
    /* '<S72>:1:61' */
    Fsd = 0.0;
  }

  if (Mye > 0.05) {
    /* '<S72>:1:63' */
    /* '<S72>:1:64' */
    tmp_f = loaddspace_B.pqr[1] * loaddspace_P.rmgrG[2] - loaddspace_B.pqr[2] *
      loaddspace_P.rmgrG[1];
    u2 = loaddspace_B.pqr[2] * loaddspace_P.rmgrG[0] - loaddspace_B.pqr[0] *
      loaddspace_P.rmgrG[2];
    u0 = loaddspace_B.pqr[0] * loaddspace_P.rmgrG[1] - loaddspace_B.pqr[1] *
      loaddspace_P.rmgrG[0];
    tmp_f += loaddspace_B.UnitConversion[0];
    u2 += loaddspace_B.UnitConversion[1];
    tmp_g = loaddspace_B.UnitConversion[2] + u0;
    for (i = 0; i < 3; i++) {
      u0 = dcmt[i] * tmp_f;
      u0 += dcmt[i + 3] * u2;
      u0 += dcmt[i + 6] * tmp_g;
      Fape[i] = u0;
    }

    Frmd = Fape[2] * loaddspace_P.cmg_Value;
  } else {
    /* '<S72>:1:65' */
    Frmd = 0.0;
  }

  if (diffLm > 0.05) {
    /* '<S72>:1:67' */
    /* '<S72>:1:68' */
    tmp_f = loaddspace_B.pqr[1] * loaddspace_P.rmglG[2] - loaddspace_B.pqr[2] *
      loaddspace_P.rmglG[1];
    u2 = loaddspace_B.pqr[2] * loaddspace_P.rmglG[0] - loaddspace_B.pqr[0] *
      loaddspace_P.rmglG[2];
    u0 = loaddspace_B.pqr[0] * loaddspace_P.rmglG[1] - loaddspace_B.pqr[1] *
      loaddspace_P.rmglG[0];
    tmp_f += loaddspace_B.UnitConversion[0];
    u2 += loaddspace_B.UnitConversion[1];
    tmp_g = loaddspace_B.UnitConversion[2] + u0;
    for (i = 0; i < 3; i++) {
      u0 = dcmt[i] * tmp_f;
      u0 += dcmt[i + 3] * u2;
      u0 += dcmt[i + 6] * tmp_g;
      Fape[i] = u0;
    }

    u0 = Fape[2] * loaddspace_P.cmg_Value;
  } else {
    /* '<S72>:1:69' */
    u0 = 0.0;
  }

  /* '<S72>:1:72' */
  u2 = Fss + Fsd;

  /* '<S72>:1:73' */
  tmp_f = Frms + Frmd;

  /* '<S72>:1:74' */
  tmp_g = u1 + u0;

  /* '<S72>:1:75' */
  loaddspace_B.Ntot = (u2 + tmp_f) + tmp_g;
  loaddspace_B.diffRm = b_s;
  loaddspace_B.Ds = b_fmod;
  loaddspace_B.Drm = Mye;
  loaddspace_B.Dlm = diffLm;
  loaddspace_B.Fss = Fss;
  loaddspace_B.Frms = Frms;
  loaddspace_B.Flms = u1;
  loaddspace_B.Fsd = Fsd;
  loaddspace_B.Frmd = Frmd;
  loaddspace_B.Flmd = u0;
  loaddspace_B.Ns = u2;
  loaddspace_B.Nrm = tmp_f;
  loaddspace_B.Nlm = tmp_g;

  /* End of MATLAB Function: '<S29>/MATLAB Function' */

  /* MATLAB Function: '<S29>/MATLAB Function2' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Gear/MATLAB Function2': '<S73>:1' */
  /* '<S73>:1:17' */
  /* '<S73>:1:18' */
  /* '<S73>:1:7' */
  /* '<S73>:1:8' */
  /* '<S73>:1:10' */
  /* '<S73>:1:11' */
  /* '<S73>:1:14' */
  /* '<S73>:1:15' */
  tmp_f = cos(loaddspace_B.phithetapsi[1]);
  u2 = sin(loaddspace_B.phithetapsi[1]);
  u0 = sin(loaddspace_B.phithetapsi[1]);
  diffLm = cos(loaddspace_B.phithetapsi[1]);
  dcmt[0] = tmp_f;
  dcmt[3] = 0.0;
  dcmt[6] = -u2;
  dcmt[2] = u0;
  dcmt[5] = 0.0;
  dcmt[8] = diffLm;

  /* '<S73>:1:18' */
  tmp_f = cos(loaddspace_B.phithetapsi[0]);
  u2 = sin(loaddspace_B.phithetapsi[0]);
  u0 = sin(loaddspace_B.phithetapsi[0]);
  diffLm = cos(loaddspace_B.phithetapsi[0]);
  dcmt[1] = 0.0;
  T_phi[0] = 1.0;
  dcmt[4] = 1.0;
  T_phi[3] = 0.0;
  dcmt[7] = 0.0;
  T_phi[6] = 0.0;
  T_phi[1] = 0.0;
  T_phi[4] = tmp_f;
  T_phi[7] = u2;
  T_phi[2] = 0.0;
  T_phi[5] = -u0;
  T_phi[8] = diffLm;

  /* '<S73>:1:20' */
  for (iU = 0; iU < 3; iU++) {
    coffset = iU * 3;
    for (i = 0; i < 3; i++) {
      aoffset = i * 3;
      b_fmod = dcmt[aoffset] * T_phi[iU];
      b_fmod += dcmt[aoffset + 1] * T_phi[iU + 3];
      b_fmod += dcmt[aoffset + 2] * T_phi[iU + 6];
      T_eb[coffset + i] = b_fmod;
    }
  }

  /* '<S73>:1:21' */
  /* '<S73>:1:23' */
  /* '<S73>:1:24' */
  /* '<S73>:1:25' */
  /* '<S73>:1:26' */
  for (i = 0; i < 3; i++) {
    u0 = T_eb[i];
    tmp_f = u0 * loaddspace_B.F[0];
    u2 = u0 * loaddspace_B.Sum1_i[0];
    diffLm = u0 * loaddspace_B.UnitConversion[0];
    Fss = u0 * loaddspace_B.pqr[0];
    dcmt[3 * i] = u0;
    u0 = T_eb[i + 3];
    tmp_f += u0 * loaddspace_B.F[1];
    u2 += u0 * loaddspace_B.Sum1_i[1];
    diffLm += u0 * loaddspace_B.UnitConversion[1];
    Fss += u0 * loaddspace_B.pqr[1];
    dcmt[3 * i + 1] = u0;
    u0 = T_eb[i + 6];
    tmp_f += u0 * loaddspace_B.F[2];
    u2 += u0 * loaddspace_B.Sum1_i[2];
    diffLm += u0 * loaddspace_B.UnitConversion[2];
    Fss += u0 * loaddspace_B.pqr[2];
    dcmt[3 * i + 2] = u0;
    Fape[i] = tmp_f;
    Mape[i] = u2;
    Ve[i] = diffLm;
    ratese[i] = Fss;
  }

  if (loaddspace_B.Ntot == 0.0) {
    /* '<S73>:1:28' */
    /* '<S73>:1:29' */
    /* '<S73>:1:30' */
    Fape[0] = 0.0;
    Fape[1] = 0.0;
    Mape[2] = 0.0;
  }

  /* '<S73>:1:33' */
  /* '<S73>:1:34' */
  /* '<S73>:1:37' */
  b_fmod = 0.35 * loaddspace_B.Ns * 0.2742 + 0.7 * loaddspace_B.Nrm * 0.1958;
  if (b_fmod > 5.0) {
    /* '<S73>:1:38' */
    /* '<S73>:1:39' */
    b_fmod = 5.0;
  }

  /* '<S73>:1:42' */
  /* '<S73>:1:43' */
  /* '<S73>:1:48' */
  /* '<S73>:1:50' */
  /* '<S73>:1:51' */
  /* '<S73>:1:54' */
  for (iU = 0; iU < 3; iU++) {
    coffset = iU * 3;
    b_s = dcmt[coffset] * 0.0;
    b_s += dcmt[coffset + 1] * 0.0;
    b_s += dcmt[coffset + 2];
    v_re[iU] = b_s;
  }

  /* '<S73>:1:55' */
  /* '<S73>:1:56' */
  /* '<S73>:1:58' */
  b_s = -v_re[1] / sqrt(v_re[0] * v_re[0] + v_re[2] * v_re[2]) * -9000.0 - 190.0
    * ratese[0];

  /* '<S73>:1:59' */
  Mye = v_re[0] / v_re[2] * -9000.0 - 190.0 * ratese[1];
  if (loaddspace_B.Ntot == 0.0) {
    /* '<S73>:1:61' */
    /* '<S73>:1:62' */
    b_s = 0.0;

    /* '<S73>:1:63' */
    Mye = 0.0;
  }

  /* '<S73>:1:66' */
  diffLm = Ve[0];
  if (diffLm < 0.0) {
    tmp_f = -1.0;
  } else if (diffLm > 0.0) {
    tmp_f = 1.0;
  } else if (diffLm == 0.0) {
    tmp_f = 0.0;
  } else {
    tmp_f = (rtNaN);
  }

  u2 = fabs(Fape[0]);
  u1 = fabs(Ve[0]);
  if ((0.8 < u1) || rtIsNaN(u1)) {
    u1 = 0.8;
  }

  u0 = fabs(Fape[0]);
  diffLm = Ve[1];
  if (diffLm < 0.0) {
    diffLm = -1.0;
  } else if (diffLm > 0.0) {
    diffLm = 1.0;
  } else if (diffLm == 0.0) {
    diffLm = 0.0;
  } else {
    diffLm = (rtNaN);
  }

  Fss = fabs(Fape[1]);
  Fsd = fabs(Ve[1]);
  if ((0.8 < Fsd) || rtIsNaN(Fsd)) {
    Fsd = 0.8;
  }

  Frms = fabs(Fape[1]);
  tmp_f = ((0.35 * loaddspace_B.Ntot - u0) * u1 + u2) * -tmp_f;
  u2 = ((0.35 * loaddspace_B.Ntot - Frms) * Fsd + Fss) * -diffLm;
  tmp_g = loaddspace_B.Ntot;
  for (i = 0; i < 3; i++) {
    u0 = dcmt[i] * tmp_f;
    u0 += dcmt[i + 3] * u2;
    u0 += dcmt[i + 6] * tmp_g;
    v_re[i] = u0;
  }

  /* '<S73>:1:67' */
  loaddspace_B.Fgear[0] = v_re[0];
  loaddspace_B.Fgear[1] = v_re[1];
  loaddspace_B.Fgear[2] = -v_re[2];

  /* '<S73>:1:68' */
  diffLm = ratese[2];
  if (diffLm < 0.0) {
    tmp_f = -1.0;
  } else if (diffLm > 0.0) {
    tmp_f = 1.0;
  } else if (diffLm == 0.0) {
    tmp_f = 0.0;
  } else {
    tmp_f = (rtNaN);
  }

  u2 = fabs(Mape[2]);
  u1 = fabs(ratese[2]);
  if ((0.8 < u1) || rtIsNaN(u1)) {
    u1 = 0.8;
  }

  u0 = fabs(Mape[2]);
  u0 = ((b_fmod - u0) * u1 + u2) * -tmp_f;
  for (i = 0; i < 3; i++) {
    loaddspace_B.Mgear[i] = 0.0;
    loaddspace_B.Mgear[i] += dcmt[i] * b_s;
    loaddspace_B.Mgear[i] += dcmt[i + 3] * Mye;
    loaddspace_B.Mgear[i] += dcmt[i + 6] * u0;

    /* Sum: '<S22>/Sum3' */
    loaddspace_B.Sum3[i] = loaddspace_B.Sum1_i[i] + loaddspace_B.Mgear[i];

    /* Sum: '<S37>/Sum2' */
    loaddspace_B.Sum2_i[i] = (loaddspace_B.Sum3[i] - loaddspace_B.Reshape2_i[i])
      - loaddspace_B.Sum_o[i];

    /* Reshape: '<S37>/Reshape1' */
    loaddspace_B.Reshape1_o[i] = loaddspace_B.Sum2_i[i];
  }

  /* End of MATLAB Function: '<S29>/MATLAB Function2' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Selector: '<S37>/Selector2' incorporates:
       *  Concatenate: '<S38>/Vector Concatenate'
       */
      loaddspace_B.Selector2[3 * i] = loaddspace_B.VectorConcatenate_m[6 * i];
      loaddspace_B.Selector2[3 * i + 1] = loaddspace_B.VectorConcatenate_m[6 * i
        + 1];
      loaddspace_B.Selector2[3 * i + 2] = loaddspace_B.VectorConcatenate_m[6 * i
        + 2];
    }
  }

  /* Product: '<S37>/Product2' incorporates:
   *  Reshape: '<S37>/Reshape1'
   *  Selector: '<S37>/Selector2'
   */
  rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(loaddspace_B.Reshape1_o,
    loaddspace_B.Selector2, loaddspace_B.Product2_kq);

  /* Reshape: '<S37>/Reshape' incorporates:
   *  Product: '<S37>/Product2'
   */
  loaddspace_B.Reshape[0] = loaddspace_B.Product2_kq[0];
  loaddspace_B.Reshape[1] = loaddspace_B.Product2_kq[1];
  loaddspace_B.Reshape[2] = loaddspace_B.Product2_kq[2];

  /* Sum: '<S22>/Sum2' */
  loaddspace_B.F_a[0] = loaddspace_B.F[0] + loaddspace_B.Fgear[0];

  /* Product: '<S26>/Product' incorporates:
   *  Constant: '<S38>/Constant'
   */
  loaddspace_B.Product_j[0] = loaddspace_B.F_a[0] / loaddspace_P.m;

  /* Sum: '<S22>/Sum2' */
  loaddspace_B.F_a[1] = loaddspace_B.F[1] + loaddspace_B.Fgear[1];

  /* Product: '<S26>/Product' incorporates:
   *  Constant: '<S38>/Constant'
   */
  loaddspace_B.Product_j[1] = loaddspace_B.F_a[1] / loaddspace_P.m;

  /* Sum: '<S22>/Sum2' */
  loaddspace_B.F_a[2] = loaddspace_B.F[2] + loaddspace_B.Fgear[2];

  /* Product: '<S26>/Product' incorporates:
   *  Constant: '<S38>/Constant'
   */
  loaddspace_B.Product_j[2] = loaddspace_B.F_a[2] / loaddspace_P.m;

  /* Product: '<S52>/j x k' */
  loaddspace_B.jxk_e = loaddspace_B.ubvbwb[1] * loaddspace_B.pqr[2];

  /* Product: '<S52>/k x i' */
  loaddspace_B.kxi_d = loaddspace_B.ubvbwb[2] * loaddspace_B.pqr[0];

  /* Product: '<S52>/i x j' */
  loaddspace_B.ixj_i = loaddspace_B.ubvbwb[0] * loaddspace_B.pqr[1];

  /* Product: '<S53>/k x j' */
  loaddspace_B.kxj_n = loaddspace_B.ubvbwb[2] * loaddspace_B.pqr[1];

  /* Product: '<S53>/i x k' */
  loaddspace_B.ixk_b = loaddspace_B.ubvbwb[0] * loaddspace_B.pqr[2];

  /* Product: '<S53>/j x i' */
  loaddspace_B.jxi_j = loaddspace_B.ubvbwb[1] * loaddspace_B.pqr[0];

  /* Sum: '<S39>/Sum' */
  loaddspace_B.Sum_j[0] = loaddspace_B.jxk_e - loaddspace_B.kxj_n;
  loaddspace_B.Sum_j[1] = loaddspace_B.kxi_d - loaddspace_B.ixk_b;
  loaddspace_B.Sum_j[2] = loaddspace_B.ixj_i - loaddspace_B.jxi_j;

  /* Sum: '<S26>/Sum' */
  loaddspace_B.Sum_f[0] = loaddspace_B.Product_j[0] + loaddspace_B.Sum_j[0];
  loaddspace_B.Sum_f[1] = loaddspace_B.Product_j[1] + loaddspace_B.Sum_j[1];
  loaddspace_B.Sum_f[2] = loaddspace_B.Product_j[2] + loaddspace_B.Sum_j[2];
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitConversion: '<S42>/Unit Conversion' */
    /* Unit Conversion - from: m/s to: m/s
       Expression: output = (1*input) + (0) */
    loaddspace_B.UnitConversion_h = 0.0;
  }

  /* Gain: '<S22>/Gain1' */
  loaddspace_B.Gain1_e = loaddspace_P.Gain1_Gain_m *
    loaddspace_B.UnitConversion_f[2];

  /* MATLAB Function: '<S22>/MATLAB Function' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/MATLAB Function': '<S30>:1' */
  /* '<S30>:1:4' */
  /* '<S30>:1:5' */
  /* '<S30>:1:7' */
  tmp_f = sin(loaddspace_B.phithetapsi[0]);
  u2 = tan(loaddspace_B.phithetapsi[1]);
  u0 = cos(loaddspace_B.phithetapsi[0]);
  diffLm = tan(loaddspace_B.phithetapsi[1]);
  Fss = cos(loaddspace_B.phithetapsi[0]);
  Frms = sin(loaddspace_B.phithetapsi[0]);
  b_s = sin(loaddspace_B.phithetapsi[0]);
  b_fmod = cos(loaddspace_B.phithetapsi[1]);
  Mye = cos(loaddspace_B.phithetapsi[0]);
  u1 = cos(loaddspace_B.phithetapsi[1]);
  loaddspace_B.invR[0] = 1.0;
  loaddspace_B.invR[3] = tmp_f * u2;
  loaddspace_B.invR[6] = u0 * diffLm;
  loaddspace_B.invR[1] = 0.0;
  loaddspace_B.invR[4] = Fss;
  loaddspace_B.invR[7] = -Frms;
  loaddspace_B.invR[2] = 0.0;
  loaddspace_B.invR[5] = 1.0 / b_fmod * b_s;
  loaddspace_B.invR[8] = 1.0 / u1 * Mye;

  /* Product: '<S22>/Product' */
  loaddspace_B.Product_g = loaddspace_B.Gain1_e / loaddspace_B.module;

  /* Product: '<S22>/Product1' */
  memcpy(&dcmt[0], &loaddspace_B.invR[0], 9U * sizeof(real_T));
  Fape[0] = loaddspace_B.pqr[0];
  Fape[1] = loaddspace_B.pqr[1];
  Fape[2] = loaddspace_B.pqr[2];
  for (i = 0; i < 3; i++) {
    u2 = dcmt[i] * Fape[0];
    u2 += dcmt[i + 3] * Fape[1];
    u2 += dcmt[i + 6] * Fape[2];
    Mape[i] = u2;
  }

  /* Product: '<S22>/Product1' */
  loaddspace_B.Product1_h[0] = Mape[0];
  loaddspace_B.Product1_h[1] = Mape[1];
  loaddspace_B.Product1_h[2] = Mape[2];

  /* Gain: '<S31>/Gain' */
  loaddspace_B.Gain_p = loaddspace_P.Gain_Gain_o * loaddspace_B.Product3_i;

  /* RelationalOperator: '<S74>/Compare' incorporates:
   *  Constant: '<S74>/Constant'
   */
  loaddspace_B.Compare = (loaddspace_B.Gain_p >=
    loaddspace_P.CompareToConstant_const);
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* Stop: '<S31>/Stop Simulation' */
    if (loaddspace_B.Compare) {
      rtmSetStopRequested(loaddspace_M, 1);
    }

    /* End of Stop: '<S31>/Stop Simulation' */

    /* S-Function (rti_commonblock): '<S113>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* Product: '<S19>/Divide' */
    loaddspace_B.Divide_d = 1.0 / loaddspace_B.SFunction_o1 *
      loaddspace_B.SFunction_o2;

    /* Gain: '<S19>/Gain' */
    loaddspace_B.Gain_ow = loaddspace_P.Gain_Gain_l3 * loaddspace_B.Divide_d;

    /* Sum: '<S122>/Sum1' incorporates:
     *  Constant: '<S122>/Constant1'
     */
    loaddspace_B.Sum1_l = loaddspace_B.Gain_ow + loaddspace_P.Constant1_Value_i;

    /* Gain: '<S122>/Gain' */
    loaddspace_B.Gain_k = loaddspace_P.Gain_Gain_i * loaddspace_B.Sum1_l;

    /* Sum: '<S122>/Sum' incorporates:
     *  Constant: '<S122>/Constant'
     */
    loaddspace_B.Sum_g = loaddspace_B.Gain_k - loaddspace_P.Constant_Value_id;

    /* ManualSwitch generated from: '<Root>/Manual Switch' */
    if (loaddspace_P.ManualSwitch_1_CurrentSetting == 1) {
      /* ManualSwitch generated from: '<Root>/Manual Switch' */
      loaddspace_B.Manetta = loaddspace_B.Sum_g;
    } else {
      /* ManualSwitch generated from: '<Root>/Manual Switch' incorporates:
       *  Constant: '<S4>/T'
       */
      loaddspace_B.Manetta = loaddspace_P.U0[3];
    }

    /* Saturate: '<S31>/Saturation' */
    u0 = loaddspace_B.Manetta;
    u1 = loaddspace_P.Saturation_LowerSat_l;
    u2 = loaddspace_P.Saturation_UpperSat_l;
    if (u0 > u2) {
      /* Saturate: '<S31>/Saturation' */
      loaddspace_B.Saturation_i = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S31>/Saturation' */
      loaddspace_B.Saturation_i = u1;
    } else {
      /* Saturate: '<S31>/Saturation' */
      loaddspace_B.Saturation_i = u0;
    }

    /* End of Saturate: '<S31>/Saturation' */

    /* Gain: '<S31>/LUT MOTORE' */
    loaddspace_B.LUTMOTORE = loaddspace_P.LUTMOTORE_Gain *
      loaddspace_B.Saturation_i;

    /* Fcn: '<S31>/Fcn' */
    loaddspace_B.Fcn = loaddspace_B.LUTMOTORE + 1.0;

    /* Gain: '<S31>/RPs->rad//s' */
    loaddspace_B.RPsrads = loaddspace_P.RPsrads_Gain * loaddspace_B.RPMRPs;
  }

  /* Trigonometry: '<S22>/Trigonometric Function' */
  u0 = loaddspace_B.Product_g;
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* Trigonometry: '<S22>/Trigonometric Function' */
  loaddspace_B.u_o = asin(u0);
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S23>/Constant' */
    loaddspace_B.rPG[0] = loaddspace_P.rPG[0];
    loaddspace_B.rPG[1] = loaddspace_P.rPG[1];
    loaddspace_B.rPG[2] = loaddspace_P.rPG[2];

    /* Constant: '<S23>/Constant5' */
    loaddspace_B.rLEG[0] = loaddspace_P.rLEG[0];
    loaddspace_B.rLEG[1] = loaddspace_P.rLEG[1];
    loaddspace_B.rLEG[2] = loaddspace_P.rLEG[2];

    /* Constant: '<S23>/Constant6' */
    loaddspace_B.rACwG[0] = loaddspace_P.rACwG[0];
    loaddspace_B.rACwG[1] = loaddspace_P.rACwG[1];
    loaddspace_B.rACwG[2] = loaddspace_P.rACwG[2];

    /* Constant: '<S23>/Constant7' */
    loaddspace_B.rACtG[0] = loaddspace_P.rACtG[0];
    loaddspace_B.rACtG[1] = loaddspace_P.rACtG[1];
    loaddspace_B.rACtG[2] = loaddspace_P.rACtG[2];

    /* Constant: '<S23>/Constant8' */
    loaddspace_B.rNPG[0] = loaddspace_P.rNPG[0];
    loaddspace_B.rNPG[1] = loaddspace_P.rNPG[1];
    loaddspace_B.rNPG[2] = loaddspace_P.rNPG[2];

    /* Constant: '<S23>/Jeng' */
    loaddspace_B.Jeng = loaddspace_P.Jeng;

    /* Constant: '<S23>/Jprop' */
    loaddspace_B.Jprop = loaddspace_P.Jprop;

    /* Constant: '<S23>/Rprop' */
    loaddspace_B.Rprop = loaddspace_P.Rprop;

    /* Constant: '<S23>/b' */
    loaddspace_B.b = loaddspace_P.b;

    /* Constant: '<S23>/c' */
    loaddspace_B.c = loaddspace_P.c;
  }

  /* Gain: '<S24>/P0' */
  loaddspace_B.P0_j = loaddspace_P.P0_Gain_h * loaddspace_B.TT0gLR_n;

  /* Product: '<S24>/Product2' */
  loaddspace_B.Product2_b = loaddspace_B.P0_j * loaddspace_B.StratosphereModel_c;

  /* Gain: '<S24>/gamma*R' */
  loaddspace_B.gammaR = loaddspace_P.gammaR_Gain * loaddspace_B.Sum1_j;

  /* Sqrt: '<S24>/a' */
  loaddspace_B.a = sqrt(loaddspace_B.gammaR);

  /* SignalConversion generated from: '<S82>/ SFunction ' incorporates:
   *  Constant: '<S23>/Constant1'
   *  MATLAB Function: '<S25>/MATLAB Function'
   */
  loaddspace_B.TmpSignalConversionAtSFunctio_d[0] = loaddspace_B.pqr[0];
  loaddspace_B.TmpSignalConversionAtSFunctio_d[3] = loaddspace_P.rAHRSG[0];
  loaddspace_B.TmpSignalConversionAtSFunctio_d[1] = loaddspace_B.pqr[1];
  loaddspace_B.TmpSignalConversionAtSFunctio_d[4] = loaddspace_P.rAHRSG[1];
  loaddspace_B.TmpSignalConversionAtSFunctio_d[2] = loaddspace_B.pqr[2];
  loaddspace_B.TmpSignalConversionAtSFunctio_d[5] = loaddspace_P.rAHRSG[2];

  /* MATLAB Function: '<S25>/MATLAB Function' */
  /* MATLAB Function 'AENEA /toSensors/MATLAB Function': '<S82>:1' */
  /* '<S82>:1:2' */
  Fape[0] = loaddspace_B.TmpSignalConversionAtSFunctio_d[0];
  Fape[1] = loaddspace_B.TmpSignalConversionAtSFunctio_d[1];
  Fape[2] = loaddspace_B.TmpSignalConversionAtSFunctio_d[2];

  /* '<S82>:1:3' */
  Mape[0] = loaddspace_B.TmpSignalConversionAtSFunctio_d[3];
  Mape[1] = loaddspace_B.TmpSignalConversionAtSFunctio_d[4];
  Mape[2] = loaddspace_B.TmpSignalConversionAtSFunctio_d[5];

  /* '<S82>:1:6' */
  Ve[0] = Fape[1] * Mape[2] - Fape[2] * Mape[1];
  Ve[1] = Fape[2] * Mape[0] - Fape[0] * Mape[2];
  Ve[2] = Fape[0] * Mape[1] - Fape[1] * Mape[0];

  /* '<S82>:1:7' */
  loaddspace_B.y_c[0] = Fape[1] * Ve[2] - Fape[2] * Ve[1];
  loaddspace_B.y_c[1] = Fape[2] * Ve[0] - Fape[0] * Ve[2];
  loaddspace_B.y_c[2] = Fape[0] * Ve[1] - Fape[1] * Ve[0];

  /* Product: '<S25>/Product' incorporates:
   *  Constant: '<S25>/Constant'
   *  Reshape: '<S46>/Reshape (9) to [3x3] column-major'
   */
  memcpy(&dcmt[0], &loaddspace_B.Reshape9to3x3columnmajor[0], 9U * sizeof(real_T));
  Fape[0] = loaddspace_P.g[0];
  Fape[1] = loaddspace_P.g[1];
  Fape[2] = loaddspace_P.g[2];
  for (i = 0; i < 3; i++) {
    u2 = dcmt[i] * Fape[0];
    u2 += dcmt[i + 3] * Fape[1];
    u2 += dcmt[i + 6] * Fape[2];

    /* Product: '<S25>/Product' */
    loaddspace_B.Product_f4[i] = u2;
  }

  /* End of Product: '<S25>/Product' */

  /* Sum: '<S25>/Sum1' */
  loaddspace_B.Sum1_p3[0] = loaddspace_B.Sum_f[0] - loaddspace_B.Product_f4[0];
  loaddspace_B.Sum1_p3[1] = loaddspace_B.Sum_f[1] - loaddspace_B.Product_f4[1];
  loaddspace_B.Sum1_p3[2] = loaddspace_B.Sum_f[2] - loaddspace_B.Product_f4[2];

  /* Sum: '<S25>/Sum' */
  loaddspace_B.Sum_am[0] = loaddspace_B.y_c[0] + loaddspace_B.Sum1_p3[0];
  loaddspace_B.Sum_am[1] = loaddspace_B.y_c[1] + loaddspace_B.Sum1_p3[1];
  loaddspace_B.Sum_am[2] = loaddspace_B.y_c[2] + loaddspace_B.Sum1_p3[2];

  /* Gain: '<S83>/Gain' */
  loaddspace_B.Gain_nh = loaddspace_P.Gain_Gain_e *
    loaddspace_B.UnitConversion_f[2];

  /* UnitConversion: '<S87>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  loaddspace_B.UnitConversion_hr = 0.017453292519943295 * loaddspace_B.Switch;
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S86>/Sum' incorporates:
     *  Constant: '<S86>/Constant'
     *  Constant: '<S86>/f'
     */
    loaddspace_B.Sum_ke = loaddspace_P.Constant_Value_nj - loaddspace_P.f_Value;

    /* Product: '<S86>/Product4' */
    loaddspace_B.Product4_l = loaddspace_B.Sum_ke * loaddspace_B.Sum_ke;

    /* Product: '<S86>/Product1' incorporates:
     *  Constant: '<S86>/Constant'
     */
    loaddspace_B.Product1_k = loaddspace_P.Constant_Value_nj /
      loaddspace_B.Product4_l;

    /* Sum: '<S86>/Sum1' incorporates:
     *  Constant: '<S86>/Constant'
     */
    loaddspace_B.Sum1_n = loaddspace_B.Product1_k -
      loaddspace_P.Constant_Value_nj;
  }

  /* Trigonometry: '<S86>/Trigonometric Function' */
  loaddspace_B.TrigonometricFunction = sin(loaddspace_B.UnitConversion_hr);

  /* Product: '<S86>/Product2' */
  loaddspace_B.Product2_l = loaddspace_B.TrigonometricFunction *
    loaddspace_B.TrigonometricFunction * loaddspace_B.Sum1_n;

  /* Sum: '<S86>/Sum2' incorporates:
   *  Constant: '<S86>/Constant'
   */
  loaddspace_B.Sum2_g = loaddspace_P.Constant_Value_nj + loaddspace_B.Product2_l;

  /* Product: '<S86>/Product3' incorporates:
   *  Constant: '<S86>/Re'
   */
  loaddspace_B.Product3_m = loaddspace_P.Re_Value * loaddspace_P.Re_Value /
    loaddspace_B.Sum2_g;

  /* Sqrt: '<S86>/sqrt' */
  loaddspace_B.sqrt_e = sqrt(loaddspace_B.Product3_m);

  /* Sum: '<S83>/Sum' */
  loaddspace_B.Sum_h1 = loaddspace_B.sqrt_e + loaddspace_B.PositionIntegrator2[2];

  /* Sum: '<S83>/Sum1' */
  loaddspace_B.Sum1_lf = loaddspace_B.sqrt_e + loaddspace_B.PositionIntegrator2
    [2];

  /* Product: '<S83>/Vn//(Rm+h)' */
  loaddspace_B.VnRmh = loaddspace_B.UnitConversion_f[0] / loaddspace_B.Sum_h1;

  /* Trigonometry: '<S83>/cos(phi)' */
  loaddspace_B.cosphi = cos(loaddspace_B.Switch);

  /* Product: '<S83>/Ve//(Rn+h)cos(phi)' */
  loaddspace_B.VeRnhcosphi = loaddspace_B.UnitConversion_f[1] /
    loaddspace_B.Sum1_lf / loaddspace_B.cosphi;

  /* SignalConversion generated from: '<S83>/Position Integrator2' */
  loaddspace_B.TmpSignalConversionAtPositionIn[0] = loaddspace_B.VnRmh;
  loaddspace_B.TmpSignalConversionAtPositionIn[1] = loaddspace_B.VeRnhcosphi;
  loaddspace_B.TmpSignalConversionAtPositionIn[2] = loaddspace_B.Gain_nh;
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S6>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* End of Outputs for S-Function (rti_commonblock): '<S6>/S-Function1' */
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscreteIntegrator: '<S103>/Discrete-Time Integrator3' */
    loaddspace_B.DiscreteTimeIntegrator3 =
      loaddspace_DW.DiscreteTimeIntegrator3_DSTATE;
  }

  /* Sum: '<S103>/Sum12' */
  loaddspace_B.Sum12 = loaddspace_B.phithetapsi[0] +
    loaddspace_B.DiscreteTimeIntegrator3;

  /* ZeroOrderHold: '<S103>/Zero-Order Hold9' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S103>/Zero-Order Hold9' */
    loaddspace_B.ZeroOrderHold9 = loaddspace_B.Sum12;

    /* Gain: '<S102>/Gain' */
    loaddspace_B.Gain_gz = loaddspace_P.Gain_Gain_li *
      loaddspace_B.ZeroOrderHold9;

    /* Saturate: '<S18>/Saturation5' */
    u0 = loaddspace_B.Gain_gz;
    u1 = loaddspace_P.Saturation5_LowerSat;
    u2 = loaddspace_P.Saturation5_UpperSat;
    if (u0 > u2) {
      /* Saturate: '<S18>/Saturation5' */
      loaddspace_B.Saturation5 = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S18>/Saturation5' */
      loaddspace_B.Saturation5 = u1;
    } else {
      /* Saturate: '<S18>/Saturation5' */
      loaddspace_B.Saturation5 = u0;
    }

    /* End of Saturate: '<S18>/Saturation5' */

    /* DiscreteIntegrator: '<S103>/Discrete-Time Integrator4' */
    loaddspace_B.DiscreteTimeIntegrator4 =
      loaddspace_DW.DiscreteTimeIntegrator4_DSTATE;
  }

  /* End of ZeroOrderHold: '<S103>/Zero-Order Hold9' */

  /* Sum: '<S103>/Sum16' */
  loaddspace_B.Sum16 = loaddspace_B.phithetapsi[1] +
    loaddspace_B.DiscreteTimeIntegrator4;

  /* ZeroOrderHold: '<S103>/Zero-Order Hold10' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S103>/Zero-Order Hold10' */
    loaddspace_B.ZeroOrderHold10 = loaddspace_B.Sum16;

    /* Gain: '<S98>/Gain' */
    loaddspace_B.Gain_l = loaddspace_P.Gain_Gain_ow *
      loaddspace_B.ZeroOrderHold10;

    /* Saturate: '<S18>/Saturation6' */
    u0 = loaddspace_B.Gain_l;
    u1 = loaddspace_P.Saturation6_LowerSat;
    u2 = loaddspace_P.Saturation6_UpperSat;
    if (u0 > u2) {
      /* Saturate: '<S18>/Saturation6' */
      loaddspace_B.Saturation6 = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S18>/Saturation6' */
      loaddspace_B.Saturation6 = u1;
    } else {
      /* Saturate: '<S18>/Saturation6' */
      loaddspace_B.Saturation6 = u0;
    }

    /* End of Saturate: '<S18>/Saturation6' */

    /* DiscreteIntegrator: '<S103>/Discrete-Time Integrator5' */
    loaddspace_B.DiscreteTimeIntegrator5 =
      loaddspace_DW.DiscreteTimeIntegrator5_DSTATE;
  }

  /* End of ZeroOrderHold: '<S103>/Zero-Order Hold10' */

  /* Sum: '<S103>/Sum18' */
  loaddspace_B.Sum18 = loaddspace_B.phithetapsi[2] +
    loaddspace_B.DiscreteTimeIntegrator5;

  /* ZeroOrderHold: '<S103>/Zero-Order Hold11' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S103>/Zero-Order Hold11' */
    loaddspace_B.ZeroOrderHold11 = loaddspace_B.Sum18;

    /* Gain: '<S101>/Gain' */
    loaddspace_B.Gain_h5 = loaddspace_P.Gain_Gain_jt *
      loaddspace_B.ZeroOrderHold11;

    /* Saturate: '<S18>/Saturation4' */
    u0 = loaddspace_B.Gain_h5;
    u1 = loaddspace_P.Saturation4_LowerSat;
    u2 = loaddspace_P.Saturation4_UpperSat;
    if (u0 > u2) {
      /* Saturate: '<S18>/Saturation4' */
      loaddspace_B.Saturation4 = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S18>/Saturation4' */
      loaddspace_B.Saturation4 = u1;
    } else {
      /* Saturate: '<S18>/Saturation4' */
      loaddspace_B.Saturation4 = u0;
    }

    /* End of Saturate: '<S18>/Saturation4' */

    /* RandomNumber: '<S103>/Random Number6' */
    loaddspace_B.RandomNumber6 = loaddspace_DW.NextOutput_i;
  }

  /* End of ZeroOrderHold: '<S103>/Zero-Order Hold11' */

  /* Sum: '<S103>/Sum23' */
  loaddspace_B.Sum23 = loaddspace_B.pqr[0] + loaddspace_B.RandomNumber6;

  /* ZeroOrderHold: '<S103>/Zero-Order Hold15' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S103>/Zero-Order Hold15' */
    loaddspace_B.ZeroOrderHold15 = loaddspace_B.Sum23;

    /* RandomNumber: '<S103>/Random Number7' */
    loaddspace_B.RandomNumber7 = loaddspace_DW.NextOutput_e;
  }

  /* End of ZeroOrderHold: '<S103>/Zero-Order Hold15' */

  /* Sum: '<S103>/Sum14' */
  loaddspace_B.Sum14_i = loaddspace_B.pqr[1] + loaddspace_B.RandomNumber7;

  /* ZeroOrderHold: '<S103>/Zero-Order Hold16' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S103>/Zero-Order Hold16' */
    loaddspace_B.ZeroOrderHold16 = loaddspace_B.Sum14_i;

    /* RandomNumber: '<S103>/Random Number8' */
    loaddspace_B.RandomNumber8 = loaddspace_DW.NextOutput_c;
  }

  /* End of ZeroOrderHold: '<S103>/Zero-Order Hold16' */

  /* Sum: '<S103>/Sum15' */
  loaddspace_B.Sum15 = loaddspace_B.pqr[2] + loaddspace_B.RandomNumber8;

  /* ZeroOrderHold: '<S103>/Zero-Order Hold17' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S103>/Zero-Order Hold17' */
    loaddspace_B.ZeroOrderHold17 = loaddspace_B.Sum15;

    /* RandomNumber: '<S103>/Random Number3' */
    loaddspace_B.RandomNumber3 = loaddspace_DW.NextOutput_ig;
  }

  /* End of ZeroOrderHold: '<S103>/Zero-Order Hold17' */

  /* Sum: '<S103>/Sum20' */
  loaddspace_B.Sum20 = loaddspace_B.Sum1_p3[0] + loaddspace_B.RandomNumber3;

  /* ZeroOrderHold: '<S103>/Zero-Order Hold12' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S103>/Zero-Order Hold12' */
    loaddspace_B.ZeroOrderHold12 = loaddspace_B.Sum20;

    /* RandomNumber: '<S103>/Random Number4' */
    loaddspace_B.RandomNumber4 = loaddspace_DW.NextOutput_pp;
  }

  /* End of ZeroOrderHold: '<S103>/Zero-Order Hold12' */

  /* Sum: '<S103>/Sum21' */
  loaddspace_B.Sum21 = loaddspace_B.Sum1_p3[1] + loaddspace_B.RandomNumber4;

  /* ZeroOrderHold: '<S103>/Zero-Order Hold13' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S103>/Zero-Order Hold13' */
    loaddspace_B.ZeroOrderHold13 = loaddspace_B.Sum21;

    /* RandomNumber: '<S103>/Random Number5' */
    loaddspace_B.RandomNumber5 = loaddspace_DW.NextOutput_bc;
  }

  /* End of ZeroOrderHold: '<S103>/Zero-Order Hold13' */

  /* Sum: '<S103>/Sum22' */
  loaddspace_B.Sum22 = loaddspace_B.Sum1_p3[2] + loaddspace_B.RandomNumber5;

  /* ZeroOrderHold: '<S103>/Zero-Order Hold14' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S103>/Zero-Order Hold14' */
    loaddspace_B.ZeroOrderHold14 = loaddspace_B.Sum22;

    /* Outputs for Atomic SubSystem: '<S18>/Enabled Subsystem' */
    /* DataTypeConversion: '<S93>/Data Type Conversion' */
    loaddspace_B.DataTypeConversion[0] = (real32_T)loaddspace_B.ZeroOrderHold12;
    loaddspace_B.DataTypeConversion[1] = (real32_T)loaddspace_B.ZeroOrderHold13;
    loaddspace_B.DataTypeConversion[2] = (real32_T)loaddspace_B.ZeroOrderHold14;
    loaddspace_B.DataTypeConversion[3] = (real32_T)loaddspace_B.ZeroOrderHold15;
    loaddspace_B.DataTypeConversion[4] = (real32_T)loaddspace_B.ZeroOrderHold16;
    loaddspace_B.DataTypeConversion[5] = (real32_T)loaddspace_B.ZeroOrderHold17;
    loaddspace_B.DataTypeConversion[6] = (real32_T)loaddspace_B.Saturation5;
    loaddspace_B.DataTypeConversion[7] = (real32_T)loaddspace_B.Saturation6;
    loaddspace_B.DataTypeConversion[8] = (real32_T)loaddspace_B.Saturation4;

    /* S-Function (SImulate_messageMTi_nuovo): '<S93>/S-Function Builder1' */
    SImulate_messageMTi_nuovo_Outputs_wrapper(&loaddspace_B.DataTypeConversion[0],
      &loaddspace_B.SFunctionBuilder1_o1_g[0],
      &loaddspace_B.SFunctionBuilder1_o2_j, &loaddspace_B.SFunctionBuilder1_o3[0]);

    /* End of Outputs for SubSystem: '<S18>/Enabled Subsystem' */

    /* RateTransition: '<Root>/Rate Transition' */
    switch (loaddspace_DW.RateTransition_read_buf) {
     case 0:
      loaddspace_DW.RateTransition_write_buf = 1;
      break;

     case 1:
      loaddspace_DW.RateTransition_write_buf = 0;
      break;

     default:
      loaddspace_DW.RateTransition_write_buf = (int8_T)
        (loaddspace_DW.RateTransition_last_buf_wr == 0);
      break;
    }

    if (loaddspace_DW.RateTransition_write_buf != 0) {
      for (i = 0; i < 41; i++) {
        loaddspace_DW.RateTransition_Buffer1[i] =
          loaddspace_B.SFunctionBuilder1_o1_g[i];
      }
    } else {
      for (i = 0; i < 41; i++) {
        loaddspace_DW.RateTransition_Buffer0[i] =
          loaddspace_B.SFunctionBuilder1_o1_g[i];
      }
    }

    loaddspace_DW.RateTransition_last_buf_wr =
      loaddspace_DW.RateTransition_write_buf;
    loaddspace_DW.RateTransition_write_buf = -1;

    /* End of RateTransition: '<Root>/Rate Transition' */
  }

  /* End of ZeroOrderHold: '<S103>/Zero-Order Hold14' */
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Product: '<S95>/Product' */
  loaddspace_B.Product_b = loaddspace_B.TT0gLR / loaddspace_B.uT0;

  /* Gain: '<S95>/rho0' */
  loaddspace_B.rho0_n = loaddspace_P.rho0_Gain_n * loaddspace_B.Product_b;

  /* Product: '<S95>/Product3' */
  loaddspace_B.Product3_k = loaddspace_B.rho0_n * loaddspace_B.StratosphereModel;

  /* Gain: '<S95>/gamma*R' */
  loaddspace_B.gammaR_o = loaddspace_P.gammaR_Gain_b * loaddspace_B.Sum1;

  /* Sqrt: '<S95>/a' */
  loaddspace_B.a_h = sqrt(loaddspace_B.gammaR_o);

  /* UnitConversion: '<S107>/Unit Conversion' */
  /* Unit Conversion - from: Pa to: Pa
     Expression: output = (1*input) + (0) */
  loaddspace_B.UnitConversion_k = loaddspace_B.Product2;

  /* S-Function (saeropalt): '<S96>/S-Function' */

  /* S-Function Block: <S96>/S-Function */
  {
    real_T *temp_table = (real_T *) &loaddspace_DW.SFunction_temp_table[0];
    real_T *pres_table = (real_T *) &loaddspace_DW.SFunction_pres_table[0];
    CalcPAltCOESA( &loaddspace_B.UnitConversion_k, &loaddspace_B.SFunction,
                  temp_table, pres_table, 1);
  }

  /* UnitConversion: '<S106>/Unit Conversion' */
  /* Unit Conversion - from: m to: m
     Expression: output = (1*input) + (0) */
  loaddspace_B.UnitConversion_l = loaddspace_B.SFunction;
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
    /* RandomNumber: '<S108>/White Noise Lat' */
    loaddspace_B.WhiteNoiseLat = loaddspace_DW.NextOutput_n;
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S103>/Gain3' */
    loaddspace_B.Gain3_h = loaddspace_P.beta_phi *
      loaddspace_B.DiscreteTimeIntegrator3;

    /* RandomNumber: '<S103>/Random Number' */
    loaddspace_B.RandomNumber = loaddspace_DW.NextOutput_aa;

    /* Sum: '<S103>/Sum13' */
    loaddspace_B.Sum13_d = loaddspace_B.RandomNumber - loaddspace_B.Gain3_h;

    /* Gain: '<S103>/Gain4' */
    loaddspace_B.Gain4_n = loaddspace_P.beta_theta *
      loaddspace_B.DiscreteTimeIntegrator4;

    /* RandomNumber: '<S103>/Random Number1' */
    loaddspace_B.RandomNumber1 = loaddspace_DW.NextOutput_j;

    /* Sum: '<S103>/Sum17' */
    loaddspace_B.Sum17 = loaddspace_B.RandomNumber1 - loaddspace_B.Gain4_n;

    /* Gain: '<S103>/Gain5' */
    loaddspace_B.Gain5_j = loaddspace_P.beta_psi *
      loaddspace_B.DiscreteTimeIntegrator5;

    /* RandomNumber: '<S103>/Random Number2' */
    loaddspace_B.RandomNumber2 = loaddspace_DW.NextOutput_jf;

    /* Sum: '<S103>/Sum19' */
    loaddspace_B.Sum19 = loaddspace_B.RandomNumber2 - loaddspace_B.Gain5_j;

    /* Gain: '<S108>/Gain' */
    b_fmod = 1.0 / loaddspace_P.Ta_lat;

    /* Gain: '<S108>/Gain' */
    loaddspace_B.Gain_f = b_fmod * loaddspace_B.DiscreteTimeIntegrator;
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
    /* RandomNumber: '<S109>/White Noise' */
    loaddspace_B.WhiteNoise = loaddspace_DW.NextOutput_n2;
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sum: '<S108>/Sum' */
    loaddspace_B.Sum_c = loaddspace_B.WhiteNoiseLat - loaddspace_B.Gain_f;

    /* Gain: '<S109>/Gain' */
    b_fmod = 1.0 / loaddspace_P.Ta_long;

    /* Gain: '<S109>/Gain' */
    loaddspace_B.Gain_i = b_fmod * loaddspace_B.DiscreteTimeIntegrator_e;

    /* Sum: '<S109>/Sum' */
    loaddspace_B.Sum_e0 = loaddspace_B.WhiteNoise - loaddspace_B.Gain_i;

    /* Trigonometry: '<S110>/Cos1' */
    loaddspace_B.Cos1 = cos(loaddspace_B.Switch1_f);

    /* Product: '<S110>/Multiply6' */
    loaddspace_B.V_n = loaddspace_B.Sum5 * loaddspace_B.Cos1;

    /* Trigonometry: '<S110>/Sin1' */
    loaddspace_B.Sin1 = sin(loaddspace_B.Switch1_f);

    /* Product: '<S110>/Multiply7' */
    loaddspace_B.V_e = loaddspace_B.Sum5 * loaddspace_B.Sin1;

    /* ZeroOrderHold: '<S104>/Zero-Order Hold2' */
    if (rtmIsMajorTimeStep(loaddspace_M) &&
        loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
      /* ZeroOrderHold: '<S104>/Zero-Order Hold2' */
      loaddspace_B.ZeroOrderHold2_m = loaddspace_B.V_n;

      /* ZeroOrderHold: '<S104>/Zero-Order Hold3' */
      loaddspace_B.ZeroOrderHold3 = loaddspace_B.V_e;
    }

    /* End of ZeroOrderHold: '<S104>/Zero-Order Hold2' */
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S115>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* Product: '<S19>/Divide2' */
    loaddspace_B.Divide2 = 1.0 / loaddspace_B.SFunction_o1_h *
      loaddspace_B.SFunction_o2_g;

    /* Gain: '<S19>/Gain2' */
    loaddspace_B.Gain2 = loaddspace_P.Gain2_Gain * loaddspace_B.Divide2;

    /* MATLAB Function: '<S112>/MATLAB Function' incorporates:
     *  Constant: '<S112>/Constant1'
     *  Constant: '<S112>/Constant4'
     *  Constant: '<S112>/Constant5'
     */
    loaddspace_MATLABFunction(loaddspace_P.degree_aileron,
      loaddspace_P.microsec_aileron, loaddspace_B.Gain2,
      loaddspace_P.Constant1_Value_g, &loaddspace_B.sf_MATLABFunction_b);

    /* Product: '<S112>/Product' */
    loaddspace_B.Product_pb = loaddspace_B.sf_MATLABFunction_b.K *
      loaddspace_B.Gain2;

    /* Sum: '<S112>/Add' */
    loaddspace_B.Add_c = loaddspace_B.Product_pb +
      loaddspace_B.sf_MATLABFunction_b.C;

    /* Gain: '<S119>/Gain1' */
    loaddspace_B.Gain1_n = loaddspace_P.Gain1_Gain_cd * loaddspace_B.Add_c;

    /* S-Function (rti_commonblock): '<S116>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* Product: '<S19>/Divide3' */
    loaddspace_B.Divide3 = 1.0 / loaddspace_B.SFunction_o1_f *
      loaddspace_B.SFunction_o2_k;

    /* S-Function (rti_commonblock): '<S114>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* Product: '<S19>/Divide1' */
    loaddspace_B.Divide1_d = 1.0 / loaddspace_B.SFunction_o1_j *
      loaddspace_B.SFunction_o2_e;

    /* Gain: '<S19>/Gain1' */
    loaddspace_B.Gain1_fv = loaddspace_P.Gain1_Gain_f * loaddspace_B.Divide1_d;

    /* MATLAB Function: '<S120>/MATLAB Function' incorporates:
     *  Constant: '<S120>/Constant1'
     *  Constant: '<S120>/Constant4'
     *  Constant: '<S120>/Constant5'
     */
    /* MATLAB Function 'Subsystem1/ELEVATOR/MATLAB Function': '<S124>:1' */
    /* '<S124>:1:16' */
    b_fmod = 0.0;

    /* '<S124>:1:17' */
    loaddspace_B.C = 0.0;
    if (loaddspace_P.Constant1_Value_c == 1.0) {
      /* '<S124>:1:18' */
      if ((loaddspace_B.Gain1_fv <= loaddspace_P.degree_elevator[14]) &&
          (loaddspace_B.Gain1_fv >= loaddspace_P.degree_elevator[0])) {
        /* '<S124>:1:19' */
        /* '<S124>:1:20' */
        for (i = 0; i < 14; i++) {
          /* '<S124>:1:20' */
          if ((loaddspace_B.Gain1_fv >= loaddspace_P.degree_elevator[i]) &&
              (loaddspace_B.Gain1_fv <= loaddspace_P.degree_elevator[i + 1])) {
            /* '<S124>:1:21' */
            /* '<S124>:1:22' */
            b_fmod = (loaddspace_P.microsec_elevator[i + 1] -
                      loaddspace_P.microsec_elevator[i]) /
              (loaddspace_P.degree_elevator[i + 1] -
               loaddspace_P.degree_elevator[i]);

            /* '<S124>:1:23' */
            loaddspace_B.C = -b_fmod * loaddspace_P.degree_elevator[i] +
              loaddspace_P.microsec_elevator[i];
          }
        }
      } else if (loaddspace_B.Gain1_fv > loaddspace_P.degree_elevator[14]) {
        /* '<S124>:1:27' */
        /* '<S124>:1:28' */
        b_fmod = (loaddspace_P.microsec_elevator[14] -
                  loaddspace_P.microsec_elevator[13]) /
          (loaddspace_P.degree_elevator[14] - loaddspace_P.degree_elevator[13]);

        /* '<S124>:1:29' */
        loaddspace_B.C = -b_fmod * loaddspace_P.degree_elevator[13] +
          loaddspace_P.microsec_elevator[13];
      } else {
        if (loaddspace_B.Gain1_fv < loaddspace_P.degree_elevator[0]) {
          /* '<S124>:1:30' */
          /* '<S124>:1:31' */
          b_fmod = (loaddspace_P.microsec_elevator[1] -
                    loaddspace_P.microsec_elevator[0]) /
            (loaddspace_P.degree_elevator[1] - loaddspace_P.degree_elevator[0]);

          /* '<S124>:1:32' */
          loaddspace_B.C = -b_fmod * loaddspace_P.degree_elevator[0] +
            loaddspace_P.microsec_elevator[0];
        }
      }
    } else {
      if (loaddspace_P.Constant1_Value_c == 0.0) {
        /* '<S124>:1:34' */
        if ((loaddspace_B.Gain1_fv <= loaddspace_P.microsec_elevator[14]) &&
            (loaddspace_B.Gain1_fv >= loaddspace_P.microsec_elevator[0])) {
          /* '<S124>:1:35' */
          /* '<S124>:1:36' */
          for (iU = 0; iU < 14; iU++) {
            /* '<S124>:1:36' */
            if ((loaddspace_B.Gain1_fv >= loaddspace_P.microsec_elevator[iU]) &&
                (loaddspace_B.Gain1_fv <= loaddspace_P.microsec_elevator[iU + 1]))
            {
              /* '<S124>:1:37' */
              /* '<S124>:1:38' */
              b_fmod = (loaddspace_P.degree_elevator[iU + 1] -
                        loaddspace_P.degree_elevator[iU]) /
                (loaddspace_P.microsec_elevator[iU + 1] -
                 loaddspace_P.microsec_elevator[iU]);

              /* '<S124>:1:39' */
              loaddspace_B.C = -b_fmod * loaddspace_P.microsec_elevator[iU] +
                loaddspace_P.degree_elevator[iU];
            }
          }
        } else if (loaddspace_B.Gain1_fv > loaddspace_P.microsec_elevator[14]) {
          /* '<S124>:1:42' */
          /* '<S124>:1:43' */
          b_fmod = (loaddspace_P.degree_elevator[14] -
                    loaddspace_P.degree_elevator[13]) /
            (loaddspace_P.microsec_elevator[14] -
             loaddspace_P.microsec_elevator[13]);

          /* '<S124>:1:44' */
          loaddspace_B.C = -b_fmod * loaddspace_P.microsec_elevator[14] +
            loaddspace_P.degree_elevator[14];
        } else {
          if (loaddspace_B.Gain1_fv < loaddspace_P.microsec_elevator[0]) {
            /* '<S124>:1:45' */
            /* '<S124>:1:46' */
            b_fmod = (loaddspace_P.degree_elevator[1] -
                      loaddspace_P.degree_elevator[0]) /
              (loaddspace_P.microsec_elevator[1] -
               loaddspace_P.microsec_elevator[0]);

            /* '<S124>:1:47' */
            loaddspace_B.C = -b_fmod * loaddspace_P.microsec_elevator[14] +
              loaddspace_P.degree_elevator[14];
          }
        }
      }
    }

    loaddspace_B.K = b_fmod;

    /* End of MATLAB Function: '<S120>/MATLAB Function' */

    /* Product: '<S120>/Product' */
    loaddspace_B.Product_jy = loaddspace_B.K * loaddspace_B.Gain1_fv;

    /* Sum: '<S120>/Add' */
    loaddspace_B.Add_n = loaddspace_B.Product_jy + loaddspace_B.C;

    /* Gain: '<S117>/Gain1' */
    loaddspace_B.Gain1_i = loaddspace_P.Gain1_Gain_h * loaddspace_B.Add_n;

    /* Gain: '<S19>/Gain3' */
    loaddspace_B.Gain3_a = loaddspace_P.Gain3_Gain_k * loaddspace_B.Divide3;

    /* MATLAB Function: '<S121>/MATLAB Function' incorporates:
     *  Constant: '<S121>/Constant1'
     *  Constant: '<S121>/Constant5'
     *  Constant: '<S121>/Constant6'
     */
    loaddspace_MATLABFunction(loaddspace_P.degree_rudder,
      loaddspace_P.microsec_rudder, loaddspace_B.Gain3_a,
      loaddspace_P.Constant1_Value_b, &loaddspace_B.sf_MATLABFunction_j);

    /* Product: '<S121>/Product' */
    loaddspace_B.Product_hc = loaddspace_B.sf_MATLABFunction_j.K *
      loaddspace_B.Gain3_a;

    /* Sum: '<S121>/Add' */
    loaddspace_B.Add_h = loaddspace_B.Product_hc +
      loaddspace_B.sf_MATLABFunction_j.C;

    /* Gain: '<S118>/Gain1' */
    loaddspace_B.Gain1_ne = loaddspace_P.Gain1_Gain_d * loaddspace_B.Add_h;

    /* S-Function (rti_commonblock): '<S7>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S7>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S8>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S8>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S9>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S9>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S10>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S10>/S-Function1' */
    /* This comment workarounds a code generation problem */
  }
}

/* Model update function */
void loaddspace_update(void)
{
  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for RandomNumber: '<S18>/White_press' */
    loaddspace_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed) * sqrt(loaddspace_P.White_pressione) +
      loaddspace_P.White_press_Mean;

    /* Update for RandomNumber: '<S18>/White Noise4' */
    loaddspace_DW.NextOutput_a = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_o) * loaddspace_P.WhiteNoise4_StdDev +
      loaddspace_P.WhiteNoise4_Mean;

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */
    loaddspace_DW.DiscreteTimeIntegrator_DSTATE +=
      loaddspace_P.DiscreteTimeIntegrator_gainval * loaddspace_B.Sum_c;

    /* Update for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' */
    loaddspace_DW.DiscreteTimeIntegrator_DSTATE_f +=
      loaddspace_P.DiscreteTimeIntegrator_gainva_b * loaddspace_B.Sum_e0;

    /* Update for RandomNumber: '<S110>/Rumore bianco' */
    loaddspace_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_d) * loaddspace_P.Rumorebianco_StdDev +
      loaddspace_P.Rumorebianco_Mean;

    /* Update for RandomNumber: '<S110>/Noise terra course' */
    loaddspace_DW.NextOutput_k = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_a) * sqrt(loaddspace_P.Var_heading_static) +
      loaddspace_P.Noiseterracourse_Mean;
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update for RandomNumber: '<S110>/Noise V_hor' */
    loaddspace_DW.NextOutput_b = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_n) * loaddspace_P.NoiseV_hor_StdDev +
      loaddspace_P.NoiseV_hor_Mean;

    /* Update for RandomNumber: '<S110>/noise terra V_hor1' */
    loaddspace_DW.NextOutput_am = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_f) * sqrt(loaddspace_P.Var_V_hor_static) +
      loaddspace_P.noiseterraV_hor1_Mean;
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S31>/Unit Delay' */
    loaddspace_DW.UnitDelay_DSTATE = loaddspace_B.Fcn;

    /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S18>/Constant4'
     */
    loaddspace_DW.DiscreteTimeIntegrator_DSTATE_d +=
      loaddspace_P.DiscreteTimeIntegrator_gainva_j *
      loaddspace_P.Constant4_Value;
    if (loaddspace_DW.DiscreteTimeIntegrator_DSTATE_d >=
        loaddspace_P.DiscreteTimeIntegrator_UpperSat) {
      loaddspace_DW.DiscreteTimeIntegrator_DSTATE_d =
        loaddspace_P.DiscreteTimeIntegrator_UpperSat;
    } else {
      if (loaddspace_DW.DiscreteTimeIntegrator_DSTATE_d <=
          loaddspace_P.DiscreteTimeIntegrator_LowerSat) {
        loaddspace_DW.DiscreteTimeIntegrator_DSTATE_d =
          loaddspace_P.DiscreteTimeIntegrator_LowerSat;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator3' */
    loaddspace_DW.DiscreteTimeIntegrator3_DSTATE +=
      loaddspace_P.DiscreteTimeIntegrator3_gainval * loaddspace_B.Sum13_d;

    /* Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator4' */
    loaddspace_DW.DiscreteTimeIntegrator4_DSTATE +=
      loaddspace_P.DiscreteTimeIntegrator4_gainval * loaddspace_B.Sum17;

    /* Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator5' */
    loaddspace_DW.DiscreteTimeIntegrator5_DSTATE +=
      loaddspace_P.DiscreteTimeIntegrator5_gainval * loaddspace_B.Sum19;

    /* Update for RandomNumber: '<S103>/Random Number6' */
    loaddspace_DW.NextOutput_i = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_am) * sqrt(loaddspace_P.White_p) +
      loaddspace_P.mean_p;

    /* Update for RandomNumber: '<S103>/Random Number7' */
    loaddspace_DW.NextOutput_e = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_g) * sqrt(loaddspace_P.White_q) +
      loaddspace_P.mean_q;

    /* Update for RandomNumber: '<S103>/Random Number8' */
    loaddspace_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_e) * sqrt(loaddspace_P.White_r) +
      loaddspace_P.mean_r;

    /* Update for RandomNumber: '<S103>/Random Number3' */
    loaddspace_DW.NextOutput_ig = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_g5) * sqrt(loaddspace_P.White_ax) +
      loaddspace_P.mean_ax;

    /* Update for RandomNumber: '<S103>/Random Number4' */
    loaddspace_DW.NextOutput_pp = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_gp) * sqrt(loaddspace_P.White_ay) +
      loaddspace_P.mean_ay;

    /* Update for RandomNumber: '<S103>/Random Number5' */
    loaddspace_DW.NextOutput_bc = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_b) * sqrt(loaddspace_P.White_az) +
      loaddspace_P.mean_az;

    /* Update for RandomNumber: '<S103>/Random Number' */
    loaddspace_DW.NextOutput_aa = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_fw) * sqrt(loaddspace_P.White_gm_phi) +
      loaddspace_P.RandomNumber_Mean;

    /* Update for RandomNumber: '<S103>/Random Number1' */
    loaddspace_DW.NextOutput_j = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_i) * sqrt(loaddspace_P.White_gm_theta) +
      loaddspace_P.RandomNumber1_Mean;

    /* Update for RandomNumber: '<S103>/Random Number2' */
    loaddspace_DW.NextOutput_jf = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_o0) * sqrt(loaddspace_P.White_gm_psi) +
      loaddspace_P.RandomNumber2_Mean;
  }

  if (rtmIsMajorTimeStep(loaddspace_M) &&
      loaddspace_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update for RandomNumber: '<S108>/White Noise Lat' */
    loaddspace_DW.NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_bo) * loaddspace_P.WhiteNoiseLat_StdDev +
      loaddspace_P.WhiteNoiseLat_Mean;

    /* Update for RandomNumber: '<S109>/White Noise' */
    loaddspace_DW.NextOutput_n2 = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_k) * loaddspace_P.WhiteNoise_StdDev +
      loaddspace_P.WhiteNoise_Mean;
  }

  if (rtmIsMajorTimeStep(loaddspace_M)) {
    rt_ertODEUpdateContinuousStates(&loaddspace_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++loaddspace_M->Timing.clockTick0)) {
    ++loaddspace_M->Timing.clockTickH0;
  }

  loaddspace_M->Timing.t[0] = rtsiGetSolverStopTime(&loaddspace_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    loaddspace_M->Timing.clockTick1++;
    if (!loaddspace_M->Timing.clockTick1) {
      loaddspace_M->Timing.clockTickH1++;
    }
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void loaddspace_derivatives(void)
{
  XDot_loaddspace_T *_rtXdot;
  real_T tmp;
  _rtXdot = ((XDot_loaddspace_T *) loaddspace_M->derivs);

  /* Derivatives for Integrator: '<S26>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[0] = loaddspace_B.Sum_f[0];
  _rtXdot->ubvbwb_CSTATE[1] = loaddspace_B.Sum_f[1];
  _rtXdot->ubvbwb_CSTATE[2] = loaddspace_B.Sum_f[2];

  /* Derivatives for Integrator: '<S83>/Position Integrator2' */
  _rtXdot->PositionIntegrator2_CSTATE[0] =
    loaddspace_B.TmpSignalConversionAtPositionIn[0];
  _rtXdot->PositionIntegrator2_CSTATE[1] =
    loaddspace_B.TmpSignalConversionAtPositionIn[1];
  _rtXdot->PositionIntegrator2_CSTATE[2] =
    loaddspace_B.TmpSignalConversionAtPositionIn[2];

  /* Derivatives for Integrator: '<S36>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[0] = loaddspace_B.TmpSignalConversionAtphithetaps
    [0];
  _rtXdot->phithetapsi_CSTATE[1] = loaddspace_B.TmpSignalConversionAtphithetaps
    [1];
  _rtXdot->phithetapsi_CSTATE[2] = loaddspace_B.TmpSignalConversionAtphithetaps
    [2];

  /* Derivatives for Integrator: '<S26>/p,q,r ' */
  _rtXdot->pqr_CSTATE[0] = loaddspace_B.Reshape[0];
  _rtXdot->pqr_CSTATE[1] = loaddspace_B.Reshape[1];
  _rtXdot->pqr_CSTATE[2] = loaddspace_B.Reshape[2];

  /* Derivatives for StateSpace: '<S2>/State-Space2' */
  _rtXdot->StateSpace2_CSTATE = 0.0;
  _rtXdot->StateSpace2_CSTATE += loaddspace_P.StateSpace2_A *
    loaddspace_X.StateSpace2_CSTATE;
  _rtXdot->StateSpace2_CSTATE += loaddspace_P.StateSpace2_B *
    loaddspace_B.Gain1_ne;

  /* Derivatives for StateSpace: '<S3>/State-Space2' incorporates:
   *  Constant: '<S4>/R'
   */
  _rtXdot->StateSpace2_CSTATE_g = 0.0;
  _rtXdot->StateSpace2_CSTATE_g += loaddspace_P.StateSpace2_A_l *
    loaddspace_X.StateSpace2_CSTATE_g;
  tmp = loaddspace_P.U0[2];
  _rtXdot->StateSpace2_CSTATE_g += loaddspace_P.StateSpace2_B_o * tmp;

  /* Derivatives for StateSpace: '<S2>/State-Space1' */
  _rtXdot->StateSpace1_CSTATE = 0.0;
  _rtXdot->StateSpace1_CSTATE += loaddspace_P.StateSpace1_A *
    loaddspace_X.StateSpace1_CSTATE;
  _rtXdot->StateSpace1_CSTATE += loaddspace_P.StateSpace1_B *
    loaddspace_B.Gain1_n;

  /* Derivatives for StateSpace: '<S3>/State-Space1' incorporates:
   *  Constant: '<S4>/A'
   */
  _rtXdot->StateSpace1_CSTATE_n = 0.0;
  _rtXdot->StateSpace1_CSTATE_n += loaddspace_P.StateSpace1_A_b *
    loaddspace_X.StateSpace1_CSTATE_n;
  tmp = loaddspace_P.U0[1];
  _rtXdot->StateSpace1_CSTATE_n += loaddspace_P.StateSpace1_B_a * tmp;

  /* Derivatives for StateSpace: '<S2>/State-Space' */
  _rtXdot->StateSpace_CSTATE = 0.0;
  _rtXdot->StateSpace_CSTATE += loaddspace_P.StateSpace_A *
    loaddspace_X.StateSpace_CSTATE;
  _rtXdot->StateSpace_CSTATE += loaddspace_P.StateSpace_B * loaddspace_B.Gain1_i;

  /* Derivatives for StateSpace: '<S3>/State-Space' incorporates:
   *  Constant: '<S4>/E'
   */
  _rtXdot->StateSpace_CSTATE_k = 0.0;
  _rtXdot->StateSpace_CSTATE_k += loaddspace_P.StateSpace_A_h *
    loaddspace_X.StateSpace_CSTATE_k;
  tmp = loaddspace_P.U0[0];
  _rtXdot->StateSpace_CSTATE_k += loaddspace_P.StateSpace_B_o * tmp;

  /* Derivatives for Integrator: '<S26>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[0] = loaddspace_B.Reshape2[0];
  _rtXdot->xeyeze_CSTATE[1] = loaddspace_B.Reshape2[1];
  _rtXdot->xeyeze_CSTATE[2] = loaddspace_B.Reshape2[2];
}

/* Model initialize function */
void loaddspace_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)loaddspace_M, 0,
                sizeof(RT_MODEL_loaddspace_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&loaddspace_M->solverInfo,
                          &loaddspace_M->Timing.simTimeStep);
    rtsiSetTPtr(&loaddspace_M->solverInfo, &rtmGetTPtr(loaddspace_M));
    rtsiSetStepSizePtr(&loaddspace_M->solverInfo,
                       &loaddspace_M->Timing.stepSize0);
    rtsiSetdXPtr(&loaddspace_M->solverInfo, &loaddspace_M->derivs);
    rtsiSetContStatesPtr(&loaddspace_M->solverInfo, (real_T **)
                         &loaddspace_M->contStates);
    rtsiSetNumContStatesPtr(&loaddspace_M->solverInfo,
      &loaddspace_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&loaddspace_M->solverInfo,
      &loaddspace_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&loaddspace_M->solverInfo,
      &loaddspace_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&loaddspace_M->solverInfo,
      &loaddspace_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&loaddspace_M->solverInfo, (&rtmGetErrorStatus
      (loaddspace_M)));
    rtsiSetRTModelPtr(&loaddspace_M->solverInfo, loaddspace_M);
  }

  rtsiSetSimTimeStep(&loaddspace_M->solverInfo, MAJOR_TIME_STEP);
  loaddspace_M->intgData.y = loaddspace_M->odeY;
  loaddspace_M->intgData.f[0] = loaddspace_M->odeF[0];
  loaddspace_M->intgData.f[1] = loaddspace_M->odeF[1];
  loaddspace_M->intgData.f[2] = loaddspace_M->odeF[2];
  loaddspace_M->intgData.f[3] = loaddspace_M->odeF[3];
  loaddspace_M->contStates = ((X_loaddspace_T *) &loaddspace_X);
  loaddspace_M->periodicContStateIndices = ((int_T*) loaddspace_PeriodicIndX);
  loaddspace_M->periodicContStateRanges = ((real_T*) loaddspace_PeriodicRngX);
  rtsiSetSolverData(&loaddspace_M->solverInfo, (void *)&loaddspace_M->intgData);
  rtsiSetSolverName(&loaddspace_M->solverInfo,"ode4");
  rtmSetTPtr(loaddspace_M, &loaddspace_M->Timing.tArray[0]);
  loaddspace_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &loaddspace_B), 0,
                sizeof(B_loaddspace_T));

  /* states (continuous) */
  {
    (void) memset((void *)&loaddspace_X, 0,
                  sizeof(X_loaddspace_T));
  }

  /* Periodic continuous states */
  {
    (void) memset((void*) loaddspace_PeriodicIndX, 0,
                  3*sizeof(int_T));
    (void) memset((void*) loaddspace_PeriodicRngX, 0,
                  6*sizeof(real_T));
  }

  /* states (dwork) */
  (void) memset((void *)&loaddspace_DW, 0,
                sizeof(DW_loaddspace_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    loaddspace_rti_init_trc_pointers();
  }

  /* Start for S-Function (rti_commonblock): '<S5>/S-Function2' */

  /* dSPACE I/O Board DS2101 #1 Unit:DAC Group:CHANNEL2 */
  ds2101_out(DS2101_1_BASE, 2, 0);

  /* Start for S-Function (outputStream_v1): '<Root>/S-Function Builder1' */

  /* S-Function Block: <Root>/S-Function Builder1 */
  outputStream_v1_Start_wrapper();

  /* Start for S-Function (SImulate_messageGPS_nmea_carriage_return): '<S94>/S-Function Builder1' */

  /* S-Function Block: <S94>/S-Function Builder1 */
  SImulate_messageGPS_nmea_carriage_return_Start_wrapper();

  /* Start for S-Function (saeropalt): '<S96>/S-Function' */
  {
    real_T *temp_table = (real_T *) &loaddspace_DW.SFunction_temp_table[0];
    real_T *pres_table = (real_T *) &loaddspace_DW.SFunction_pres_table[0];
    InitCalcAtmosCOESA( temp_table, pres_table );
  }

  {
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for Integrator: '<S26>/ub,vb,wb' */
    loaddspace_X.ubvbwb_CSTATE[0] = loaddspace_P.State0.Vb0[0];
    loaddspace_X.ubvbwb_CSTATE[1] = loaddspace_P.State0.Vb0[1];
    loaddspace_X.ubvbwb_CSTATE[2] = loaddspace_P.State0.Vb0[2];

    /* InitializeConditions for RandomNumber: '<S18>/White_press' */
    tmp = floor(loaddspace_P.seed_baro);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed = tseed;
    loaddspace_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed) * sqrt(loaddspace_P.White_pressione) +
      loaddspace_P.White_press_Mean;

    /* End of InitializeConditions for RandomNumber: '<S18>/White_press' */

    /* InitializeConditions for Integrator: '<S83>/Position Integrator2' */
    loaddspace_X.PositionIntegrator2_CSTATE[0] =
      loaddspace_P.PositionIntegrator2_IC[0];
    loaddspace_X.PositionIntegrator2_CSTATE[1] =
      loaddspace_P.PositionIntegrator2_IC[1];
    loaddspace_X.PositionIntegrator2_CSTATE[2] =
      loaddspace_P.PositionIntegrator2_IC[2];

    /* InitializeConditions for RandomNumber: '<S18>/White Noise4' */
    tmp = floor(loaddspace_P.WhiteNoise4_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_o = tseed;
    loaddspace_DW.NextOutput_a = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_o) * loaddspace_P.WhiteNoise4_StdDev +
      loaddspace_P.WhiteNoise4_Mean;

    /* End of InitializeConditions for RandomNumber: '<S18>/White Noise4' */

    /* InitializeConditions for Integrator: '<S36>/phi theta psi' */
    loaddspace_X.phithetapsi_CSTATE[0] = loaddspace_P.State0.PHI0[0];
    loaddspace_X.phithetapsi_CSTATE[1] = loaddspace_P.State0.PHI0[1];
    loaddspace_X.phithetapsi_CSTATE[2] = loaddspace_P.State0.PHI0[2];

    /* InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */
    loaddspace_DW.DiscreteTimeIntegrator_DSTATE =
      loaddspace_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' */
    loaddspace_DW.DiscreteTimeIntegrator_DSTATE_f =
      loaddspace_P.DiscreteTimeIntegrator_IC_c;

    /* InitializeConditions for RandomNumber: '<S110>/Noise V_hor' */
    tmp = floor(loaddspace_P.seed_gps);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_n = tseed;
    loaddspace_DW.NextOutput_b = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_n) * loaddspace_P.NoiseV_hor_StdDev +
      loaddspace_P.NoiseV_hor_Mean;

    /* End of InitializeConditions for RandomNumber: '<S110>/Noise V_hor' */

    /* InitializeConditions for RandomNumber: '<S110>/noise terra V_hor1' */
    tmp = floor(loaddspace_P.seed_gps);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_f = tseed;
    loaddspace_DW.NextOutput_am = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_f) * sqrt(loaddspace_P.Var_V_hor_static) +
      loaddspace_P.noiseterraV_hor1_Mean;

    /* End of InitializeConditions for RandomNumber: '<S110>/noise terra V_hor1' */

    /* InitializeConditions for RandomNumber: '<S110>/Rumore bianco' */
    tmp = floor(loaddspace_P.seed_gps);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_d = tseed;
    loaddspace_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_d) * loaddspace_P.Rumorebianco_StdDev +
      loaddspace_P.Rumorebianco_Mean;

    /* End of InitializeConditions for RandomNumber: '<S110>/Rumore bianco' */

    /* InitializeConditions for RandomNumber: '<S110>/Noise terra course' */
    tmp = floor(loaddspace_P.seed_gps);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_a = tseed;
    loaddspace_DW.NextOutput_k = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_a) * sqrt(loaddspace_P.Var_heading_static) +
      loaddspace_P.Noiseterracourse_Mean;

    /* End of InitializeConditions for RandomNumber: '<S110>/Noise terra course' */

    /* InitializeConditions for StateSpace: '<S2>/State-Space2' */
    loaddspace_X.StateSpace2_CSTATE = loaddspace_P.State0.Ele0;

    /* InitializeConditions for StateSpace: '<S3>/State-Space2' */
    loaddspace_X.StateSpace2_CSTATE_g = loaddspace_P.State0.Ele0;

    /* InitializeConditions for StateSpace: '<S2>/State-Space1' */
    loaddspace_X.StateSpace1_CSTATE = loaddspace_P.State0.Ele0;

    /* InitializeConditions for StateSpace: '<S3>/State-Space1' */
    loaddspace_X.StateSpace1_CSTATE_n = loaddspace_P.State0.Ele0;

    /* InitializeConditions for StateSpace: '<S2>/State-Space' */
    loaddspace_X.StateSpace_CSTATE = loaddspace_P.State0.Ele0;

    /* InitializeConditions for StateSpace: '<S3>/State-Space' */
    loaddspace_X.StateSpace_CSTATE_k = loaddspace_P.State0.Ele0;

    /* InitializeConditions for Integrator: '<S26>/p,q,r ' */
    loaddspace_X.pqr_CSTATE[0] = loaddspace_P.State0.Omega0[0];

    /* InitializeConditions for Integrator: '<S26>/xe,ye,ze' */
    loaddspace_X.xeyeze_CSTATE[0] = loaddspace_P.State0.Pos0[0];

    /* InitializeConditions for Integrator: '<S26>/p,q,r ' */
    loaddspace_X.pqr_CSTATE[1] = loaddspace_P.State0.Omega0[1];

    /* InitializeConditions for Integrator: '<S26>/xe,ye,ze' */
    loaddspace_X.xeyeze_CSTATE[1] = loaddspace_P.State0.Pos0[1];

    /* InitializeConditions for Integrator: '<S26>/p,q,r ' */
    loaddspace_X.pqr_CSTATE[2] = loaddspace_P.State0.Omega0[2];

    /* InitializeConditions for Integrator: '<S26>/xe,ye,ze' */
    loaddspace_X.xeyeze_CSTATE[2] = loaddspace_P.State0.Pos0[2];

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
    loaddspace_DW.UnitDelay_DSTATE = loaddspace_P.deltaTtrim * 7400.0;

    /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    loaddspace_DW.DiscreteTimeIntegrator_DSTATE_d =
      loaddspace_P.DiscreteTimeIntegrator_IC_cw;

    /* InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator3' */
    loaddspace_DW.DiscreteTimeIntegrator3_DSTATE =
      loaddspace_P.DiscreteTimeIntegrator3_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator4' */
    loaddspace_DW.DiscreteTimeIntegrator4_DSTATE =
      loaddspace_P.DiscreteTimeIntegrator4_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator5' */
    loaddspace_DW.DiscreteTimeIntegrator5_DSTATE =
      loaddspace_P.DiscreteTimeIntegrator5_IC;

    /* InitializeConditions for RandomNumber: '<S103>/Random Number6' */
    tmp = floor(loaddspace_P.seed_ahrs);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_am = tseed;
    loaddspace_DW.NextOutput_i = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_am) * sqrt(loaddspace_P.White_p) +
      loaddspace_P.mean_p;

    /* End of InitializeConditions for RandomNumber: '<S103>/Random Number6' */

    /* InitializeConditions for RandomNumber: '<S103>/Random Number7' */
    tmp = floor(loaddspace_P.seed_ahrs);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_g = tseed;
    loaddspace_DW.NextOutput_e = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_g) * sqrt(loaddspace_P.White_q) +
      loaddspace_P.mean_q;

    /* End of InitializeConditions for RandomNumber: '<S103>/Random Number7' */

    /* InitializeConditions for RandomNumber: '<S103>/Random Number8' */
    tmp = floor(loaddspace_P.seed_ahrs);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_e = tseed;
    loaddspace_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_e) * sqrt(loaddspace_P.White_r) +
      loaddspace_P.mean_r;

    /* End of InitializeConditions for RandomNumber: '<S103>/Random Number8' */

    /* InitializeConditions for RandomNumber: '<S103>/Random Number3' */
    tmp = floor(loaddspace_P.seed_ahrs);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_g5 = tseed;
    loaddspace_DW.NextOutput_ig = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_g5) * sqrt(loaddspace_P.White_ax) +
      loaddspace_P.mean_ax;

    /* End of InitializeConditions for RandomNumber: '<S103>/Random Number3' */

    /* InitializeConditions for RandomNumber: '<S103>/Random Number4' */
    tmp = floor(loaddspace_P.seed_ahrs);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_gp = tseed;
    loaddspace_DW.NextOutput_pp = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_gp) * sqrt(loaddspace_P.White_ay) +
      loaddspace_P.mean_ay;

    /* End of InitializeConditions for RandomNumber: '<S103>/Random Number4' */

    /* InitializeConditions for RandomNumber: '<S103>/Random Number5' */
    tmp = floor(loaddspace_P.seed_ahrs);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_b = tseed;
    loaddspace_DW.NextOutput_bc = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_b) * sqrt(loaddspace_P.White_az) +
      loaddspace_P.mean_az;

    /* End of InitializeConditions for RandomNumber: '<S103>/Random Number5' */

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
    for (i = 0; i < 41; i++) {
      loaddspace_DW.RateTransition_Buffer0[i] =
        loaddspace_P.RateTransition_InitialCondition;
    }

    loaddspace_DW.RateTransition_write_buf = -1;
    loaddspace_DW.RateTransition_read_buf = -1;

    /* End of InitializeConditions for RateTransition: '<Root>/Rate Transition' */

    /* InitializeConditions for RandomNumber: '<S103>/Random Number' */
    tmp = floor(loaddspace_P.seed_ahrs);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_fw = tseed;
    loaddspace_DW.NextOutput_aa = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_fw) * sqrt(loaddspace_P.White_gm_phi) +
      loaddspace_P.RandomNumber_Mean;

    /* End of InitializeConditions for RandomNumber: '<S103>/Random Number' */

    /* InitializeConditions for RandomNumber: '<S103>/Random Number1' */
    tmp = floor(loaddspace_P.seed_ahrs);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_i = tseed;
    loaddspace_DW.NextOutput_j = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_i) * sqrt(loaddspace_P.White_gm_theta) +
      loaddspace_P.RandomNumber1_Mean;

    /* End of InitializeConditions for RandomNumber: '<S103>/Random Number1' */

    /* InitializeConditions for RandomNumber: '<S103>/Random Number2' */
    tmp = floor(loaddspace_P.seed_ahrs);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_o0 = tseed;
    loaddspace_DW.NextOutput_jf = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_o0) * sqrt(loaddspace_P.White_gm_psi) +
      loaddspace_P.RandomNumber2_Mean;

    /* End of InitializeConditions for RandomNumber: '<S103>/Random Number2' */

    /* InitializeConditions for RandomNumber: '<S108>/White Noise Lat' */
    tmp = floor(loaddspace_P.WhiteNoiseLat_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_bo = tseed;
    loaddspace_DW.NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_bo) * loaddspace_P.WhiteNoiseLat_StdDev +
      loaddspace_P.WhiteNoiseLat_Mean;

    /* End of InitializeConditions for RandomNumber: '<S108>/White Noise Lat' */

    /* InitializeConditions for RandomNumber: '<S109>/White Noise' */
    tmp = floor(loaddspace_P.WhiteNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    loaddspace_DW.RandSeed_k = tseed;
    loaddspace_DW.NextOutput_n2 = rt_nrand_Upu32_Yd_f_pw_snf
      (&loaddspace_DW.RandSeed_k) * loaddspace_P.WhiteNoise_StdDev +
      loaddspace_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S109>/White Noise' */

    /* InitializeConditions for root-level periodic continuous states */
    {
      int_T rootPeriodicContStateIndices[3] = { 6, 7, 8 };

      real_T rootPeriodicContStateRanges[6] = { -3.1415926535897931,
        3.1415926535897931, -3.1415926535897931, 3.1415926535897931,
        -3.1415926535897931, 3.1415926535897931 };

      (void) memcpy((void*)loaddspace_PeriodicIndX, rootPeriodicContStateIndices,
                    3*sizeof(int_T));
      (void) memcpy((void*)loaddspace_PeriodicRngX, rootPeriodicContStateRanges,
                    6*sizeof(real_T));
    }
  }
}

/* Model terminate function */
void loaddspace_terminate(void)
{
  /* Terminate for S-Function (outputStream_v1): '<Root>/S-Function Builder1' */

  /* S-Function Block: <Root>/S-Function Builder1 */
  outputStream_v1_Terminate_wrapper();

  /* Terminate for S-Function (SImulate_messageGPS_nmea_carriage_return): '<S94>/S-Function Builder1' */

  /* S-Function Block: <S94>/S-Function Builder1 */
  SImulate_messageGPS_nmea_carriage_return_Terminate_wrapper();

  /* Terminate for S-Function (rti_commonblock): '<S7>/S-Function1' */

  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS4201SER_B1_Ser[0]);
  dsser_fifo_reset(rtiDS4201SER_B1_Ser[0]);

  /* Terminate for S-Function (rti_commonblock): '<S8>/S-Function1' */

  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS4201SER_B1_Ser[1]);
  dsser_fifo_reset(rtiDS4201SER_B1_Ser[1]);

  /* Terminate for S-Function (rti_commonblock): '<S9>/S-Function1' */

  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS4201SER_B1_Ser[2]);
  dsser_fifo_reset(rtiDS4201SER_B1_Ser[2]);

  /* Terminate for S-Function (rti_commonblock): '<S10>/S-Function1' */

  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS4201SER_B1_Ser[3]);
  dsser_fifo_reset(rtiDS4201SER_B1_Ser[3]);
}
