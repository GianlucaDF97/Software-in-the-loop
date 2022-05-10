/*
 * modello_HITL_SFT_v4.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modello_HITL_SFT_v4".
 *
 * Model version              : 5.53
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 *
 */

#include "modello_HITL_SFT_v4_trc_ptr.h"
#include "modello_HITL_SFT_v4.h"
#include "modello_HITL_SFT_v4_private.h"

/* Block signals (default storage) */
B_modello_HITL_SFT_v4_T modello_HITL_SFT_v4_B;

/* Continuous states */
X_modello_HITL_SFT_v4_T modello_HITL_SFT_v4_X;

/* Block states (default storage) */
DW_modello_HITL_SFT_v4_T modello_HITL_SFT_v4_DW;

/* Periodic continuous states */
PeriodicIndX_modello_HITL_SFT_v4_T modello_HITL_SFT_v4_PeriodicIndX;
PeriodicRngX_modello_HITL_SFT_v4_T modello_HITL_SFT_v4_PeriodicRngX;

/* Real-time model */
static RT_MODEL_modello_HITL_SFT_v4_T modello_HITL_SFT_v4_M_;
RT_MODEL_modello_HITL_SFT_v4_T *const modello_HITL_SFT_v4_M =
  &modello_HITL_SFT_v4_M_;
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
  (modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2])++;
  if ((modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.02s, 0.0s] */
    modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] = 0;
  }

  (modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3])++;
  if ((modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3]) > 9) {/* Sample time: [0.1s, 0.0s] */
    modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] = 0;
  }

  (modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[4])++;
  if ((modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[4]) > 19) {/* Sample time: [0.2s, 0.0s] */
    modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[4] = 0;
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
  modello_HITL_SFT_v4_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  modello_HITL_SFT_v4_output();
  modello_HITL_SFT_v4_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  modello_HITL_SFT_v4_output();
  modello_HITL_SFT_v4_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  modello_HITL_SFT_v4_output();
  modello_HITL_SFT_v4_derivatives();

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

/*
 * Output and update for atomic system:
 *    '<S88>/MATLAB Function'
 *    '<S97>/MATLAB Function'
 */
void modello_HITL_SFT_v4_MATLABFunction(const real_T rtu_degree[43], const
  real_T rtu_microsec[43], real_T rtu_input, real_T rtu_flag,
  B_MATLABFunction_modello_HITL_SFT_v4_T *localB)
{
  real_T K;
  int32_T b_i;

  /* MATLAB Function 'Comandi da ARDUINO/AILERON/MATLAB Function': '<S99>:1' */
  /* '<S99>:1:16' */
  K = 0.0;

  /* '<S99>:1:17' */
  localB->C = 0.0;
  if (rtu_flag == 1.0) {
    /* '<S99>:1:18' */
    if ((rtu_input <= rtu_degree[42]) && (rtu_input >= rtu_degree[0])) {
      /* '<S99>:1:19' */
      /* '<S99>:1:20' */
      for (b_i = 0; b_i < 42; b_i++) {
        /* '<S99>:1:20' */
        if ((rtu_input >= rtu_degree[b_i]) && (rtu_input <= rtu_degree[b_i + 1]))
        {
          /* '<S99>:1:21' */
          /* '<S99>:1:22' */
          K = (rtu_microsec[b_i + 1] - rtu_microsec[b_i]) / (rtu_degree[b_i + 1]
            - rtu_degree[b_i]);

          /* '<S99>:1:23' */
          localB->C = -K * rtu_degree[b_i] + rtu_microsec[b_i];
        }
      }
    } else if (rtu_input > rtu_degree[42]) {
      /* '<S99>:1:27' */
      /* '<S99>:1:28' */
      K = (rtu_microsec[42] - rtu_microsec[41]) / (rtu_degree[42] - rtu_degree
        [41]);

      /* '<S99>:1:29' */
      localB->C = -K * rtu_degree[41] + rtu_microsec[41];
    } else {
      if (rtu_input < rtu_degree[0]) {
        /* '<S99>:1:30' */
        /* '<S99>:1:31' */
        K = (rtu_microsec[1] - rtu_microsec[0]) / (rtu_degree[1] - rtu_degree[0]);

        /* '<S99>:1:32' */
        localB->C = -K * rtu_degree[0] + rtu_microsec[0];
      }
    }
  } else {
    if (rtu_flag == 0.0) {
      /* '<S99>:1:34' */
      if ((rtu_input <= rtu_microsec[42]) && (rtu_input >= rtu_microsec[0])) {
        /* '<S99>:1:35' */
        /* '<S99>:1:36' */
        for (b_i = 0; b_i < 42; b_i++) {
          /* '<S99>:1:36' */
          if ((rtu_input >= rtu_microsec[b_i]) && (rtu_input <= rtu_microsec[b_i
               + 1])) {
            /* '<S99>:1:37' */
            /* '<S99>:1:38' */
            K = (rtu_degree[b_i + 1] - rtu_degree[b_i]) / (rtu_microsec[b_i + 1]
              - rtu_microsec[b_i]);

            /* '<S99>:1:39' */
            localB->C = -K * rtu_microsec[b_i] + rtu_degree[b_i];
          }
        }
      } else if (rtu_input > rtu_microsec[42]) {
        /* '<S99>:1:42' */
        /* '<S99>:1:43' */
        K = (rtu_degree[42] - rtu_degree[41]) / (rtu_microsec[42] -
          rtu_microsec[41]);

        /* '<S99>:1:44' */
        localB->C = -K * rtu_microsec[42] + rtu_degree[42];
      } else {
        if (rtu_input < rtu_microsec[0]) {
          /* '<S99>:1:45' */
          /* '<S99>:1:46' */
          K = (rtu_degree[1] - rtu_degree[0]) / (rtu_microsec[1] - rtu_microsec
            [0]);

          /* '<S99>:1:47' */
          localB->C = -K * rtu_microsec[42] + rtu_degree[42];
        }
      }
    }
  }

  localB->K = K;
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
void modello_HITL_SFT_v4_FunctionCallSubsystem(void)
{
  /* S-Function (rti_commonblock): '<S102>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:TRANSMIT */
  {
    UInt32 txFifoLevel;
    UInt32 bytesRefNumOf;
    bytesRefNumOf = (modello_HITL_SFT_v4_P.SFunction1_BytesRefNumOf_i <= 41) ?
      modello_HITL_SFT_v4_P.SFunction1_BytesRefNumOf_i : 41;
    txFifoLevel = dsser_transmit_fifo_level(rtiDS4201SER_B1_Ser[0]);
    if (((rtiDS4201SER_B1_Ser[0]->fifo_size) - txFifoLevel) > bytesRefNumOf) {
      UInt32 bytesActNumOfAddr;
      dsser_transmit(rtiDS4201SER_B1_Ser[0], bytesRefNumOf,
                     &modello_HITL_SFT_v4_B.RateTransition_c[0],
                     &(bytesActNumOfAddr));
    }
  }
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

void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(const real_T u0[3], const real_T u1[9],
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
void modello_HITL_SFT_v4_output(void)
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
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M)) {
    /* set solver stop time */
    if (!(modello_HITL_SFT_v4_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&modello_HITL_SFT_v4_M->solverInfo,
                            ((modello_HITL_SFT_v4_M->Timing.clockTickH0 + 1) *
        modello_HITL_SFT_v4_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&modello_HITL_SFT_v4_M->solverInfo,
                            ((modello_HITL_SFT_v4_M->Timing.clockTick0 + 1) *
        modello_HITL_SFT_v4_M->Timing.stepSize0 +
        modello_HITL_SFT_v4_M->Timing.clockTickH0 *
        modello_HITL_SFT_v4_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(modello_HITL_SFT_v4_M)) {
    modello_HITL_SFT_v4_M->Timing.t[0] = rtsiGetT
      (&modello_HITL_SFT_v4_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S6>/S-Function1' */
    /* This comment workarounds a code generation problem */
  }

  /* Integrator: '<S26>/ub,vb,wb' */
  /* Unit Conversion - from: m/s to: m/s
     Expression: output = (1*input) + (0) */
  modello_HITL_SFT_v4_B.ubvbwb[0] = modello_HITL_SFT_v4_X.ubvbwb_CSTATE[0];

  /* UnitConversion: '<S40>/Unit Conversion' */
  modello_HITL_SFT_v4_B.UnitConversion[0] = modello_HITL_SFT_v4_B.ubvbwb[0];

  /* Sum: '<S34>/Sum2' incorporates:
   *  Constant: '<S15>/Winds'
   */
  modello_HITL_SFT_v4_B.Va[0] = modello_HITL_SFT_v4_B.UnitConversion[0] -
    modello_HITL_SFT_v4_P.wind_constant[0];

  /* Integrator: '<S26>/ub,vb,wb' */
  modello_HITL_SFT_v4_B.ubvbwb[1] = modello_HITL_SFT_v4_X.ubvbwb_CSTATE[1];

  /* UnitConversion: '<S40>/Unit Conversion' */
  modello_HITL_SFT_v4_B.UnitConversion[1] = modello_HITL_SFT_v4_B.ubvbwb[1];

  /* Sum: '<S34>/Sum2' incorporates:
   *  Constant: '<S15>/Winds'
   */
  modello_HITL_SFT_v4_B.Va[1] = modello_HITL_SFT_v4_B.UnitConversion[1] -
    modello_HITL_SFT_v4_P.wind_constant[1];

  /* Integrator: '<S26>/ub,vb,wb' */
  modello_HITL_SFT_v4_B.ubvbwb[2] = modello_HITL_SFT_v4_X.ubvbwb_CSTATE[2];

  /* UnitConversion: '<S40>/Unit Conversion' */
  modello_HITL_SFT_v4_B.UnitConversion[2] = modello_HITL_SFT_v4_B.ubvbwb[2];

  /* Sum: '<S34>/Sum2' incorporates:
   *  Constant: '<S15>/Winds'
   */
  modello_HITL_SFT_v4_B.Va[2] = modello_HITL_SFT_v4_B.UnitConversion[2] -
    modello_HITL_SFT_v4_P.wind_constant[2];

  /* MATLAB Function: '<S34>/MATLAB Function' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Velocità1/MATLAB Function': '<S77>:1' */
  /* '<S77>:1:5' */
  modello_HITL_SFT_v4_B.module = (modello_HITL_SFT_v4_B.Va[0] *
    modello_HITL_SFT_v4_B.Va[0] + modello_HITL_SFT_v4_B.Va[1] *
    modello_HITL_SFT_v4_B.Va[1]) + modello_HITL_SFT_v4_B.Va[2] *
    modello_HITL_SFT_v4_B.Va[2];
  modello_HITL_SFT_v4_B.module = sqrt(modello_HITL_SFT_v4_B.module);

  /* Switch: '<S127>/Switch1' */
  if (modello_HITL_SFT_v4_B.module > modello_HITL_SFT_v4_P.Switch1_Threshold) {
    /* Switch: '<S127>/Switch1' incorporates:
     *  Constant: '<S127>/Constant3'
     */
    modello_HITL_SFT_v4_B.Switch1 = modello_HITL_SFT_v4_P.Constant3_Value;
  } else {
    /* Switch: '<S127>/Switch1' */
    modello_HITL_SFT_v4_B.Switch1 = modello_HITL_SFT_v4_B.module;
  }

  /* End of Switch: '<S127>/Switch1' */

  /* MATLAB Function: '<S21>/MATLAB Function' */
  /* MATLAB Function 'scalatura velocità/MATLAB Function': '<S126>:1' */
  /* '<S126>:1:4' */
  /* '<S126>:1:5' */
  modello_HITL_SFT_v4_B.deltaP = modello_HITL_SFT_v4_B.Switch1 *
    modello_HITL_SFT_v4_B.Switch1 * 1.225 / 2.0;

  /* Gain: '<S128>/m_deltaP_to_volt' */
  modello_HITL_SFT_v4_B.m_deltaP_to_volt =
    modello_HITL_SFT_v4_P.m_deltaP_to_volt_Gain * modello_HITL_SFT_v4_B.deltaP;

  /* Sum: '<S128>/Sum' incorporates:
   *  Constant: '<S128>/q_deltaP_to_volt'
   */
  modello_HITL_SFT_v4_B.Sum = modello_HITL_SFT_v4_B.m_deltaP_to_volt +
    modello_HITL_SFT_v4_P.q_deltaP_to_volt_Value;

  /* Gain: '<S21>/Gain' */
  modello_HITL_SFT_v4_B.Gain = modello_HITL_SFT_v4_P.Gain_Gain *
    modello_HITL_SFT_v4_B.Sum;
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S6>/S-Function2' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS2101 #1 Unit:DAC Group:CHANNEL2 */
    ds2101_out(DS2101_1_BASE, 2, (dsfloat) modello_HITL_SFT_v4_B.Gain);

    /* S-Function (rti_commonblock): '<S6>/S-Function3' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S6>/S-Function4' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S6>/S-Function5' */
    /* This comment workarounds a code generation problem */
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* RandomNumber: '<S19>/White_press' */
    modello_HITL_SFT_v4_B.White_press = modello_HITL_SFT_v4_DW.NextOutput;
  }

  /* Integrator: '<S83>/Position Integrator2' */
  modello_HITL_SFT_v4_B.PositionIntegrator2[0] =
    modello_HITL_SFT_v4_X.PositionIntegrator2_CSTATE[0];
  modello_HITL_SFT_v4_B.PositionIntegrator2[1] =
    modello_HITL_SFT_v4_X.PositionIntegrator2_CSTATE[1];
  modello_HITL_SFT_v4_B.PositionIntegrator2[2] =
    modello_HITL_SFT_v4_X.PositionIntegrator2_CSTATE[2];

  /* Saturate: '<S109>/Limit  altitude  to troposhere' */
  u0 = modello_HITL_SFT_v4_B.PositionIntegrator2[2];
  u1 = modello_HITL_SFT_v4_P.Limitaltitudetotroposhere_LowerSat;
  u2 = modello_HITL_SFT_v4_P.Limitaltitudetotroposhere_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S109>/Limit  altitude  to troposhere' */
    modello_HITL_SFT_v4_B.Limitaltitudetotroposhere = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S109>/Limit  altitude  to troposhere' */
    modello_HITL_SFT_v4_B.Limitaltitudetotroposhere = u1;
  } else {
    /* Saturate: '<S109>/Limit  altitude  to troposhere' */
    modello_HITL_SFT_v4_B.Limitaltitudetotroposhere = u0;
  }

  /* End of Saturate: '<S109>/Limit  altitude  to troposhere' */

  /* Gain: '<S109>/Lapse Rate' */
  modello_HITL_SFT_v4_B.LapseRate = modello_HITL_SFT_v4_P.LapseRate_Gain *
    modello_HITL_SFT_v4_B.Limitaltitudetotroposhere;

  /* Sum: '<S109>/Sum1' incorporates:
   *  Constant: '<S109>/Sea Level  Temperature'
   */
  modello_HITL_SFT_v4_B.Sum1 = modello_HITL_SFT_v4_P.SeaLevelTemperature_Value -
    modello_HITL_SFT_v4_B.LapseRate;

  /* Gain: '<S109>/1//T0' */
  modello_HITL_SFT_v4_B.uT0 = modello_HITL_SFT_v4_P.uT0_Gain *
    modello_HITL_SFT_v4_B.Sum1;

  /* Math: '<S109>/(T//T0)^(g//LR) ' incorporates:
   *  Constant: '<S109>/Constant'
   */
  b_fmod = modello_HITL_SFT_v4_B.uT0;
  b_s = modello_HITL_SFT_v4_P.Constant_Value;
  if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
    /* Math: '<S109>/(T//T0)^(g//LR) ' */
    modello_HITL_SFT_v4_B.TT0gLR = -rt_powd_snf(-b_fmod, b_s);
  } else {
    /* Math: '<S109>/(T//T0)^(g//LR) ' */
    modello_HITL_SFT_v4_B.TT0gLR = rt_powd_snf(b_fmod, b_s);
  }

  /* End of Math: '<S109>/(T//T0)^(g//LR) ' */

  /* Gain: '<S109>/P0' */
  modello_HITL_SFT_v4_B.P0 = modello_HITL_SFT_v4_P.P0_Gain *
    modello_HITL_SFT_v4_B.TT0gLR;

  /* Sum: '<S109>/Sum' incorporates:
   *  Constant: '<S109>/Altitude of Troposphere'
   */
  modello_HITL_SFT_v4_B.Sum_k =
    modello_HITL_SFT_v4_P.AltitudeofTroposphere_Value -
    modello_HITL_SFT_v4_B.PositionIntegrator2[2];

  /* Saturate: '<S109>/Limit  altitude  to Stratosphere' */
  u0 = modello_HITL_SFT_v4_B.Sum_k;
  u1 = modello_HITL_SFT_v4_P.LimitaltitudetoStratosphere_LowerSat;
  u2 = modello_HITL_SFT_v4_P.LimitaltitudetoStratosphere_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S109>/Limit  altitude  to Stratosphere' */
    modello_HITL_SFT_v4_B.LimitaltitudetoStratosphere = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S109>/Limit  altitude  to Stratosphere' */
    modello_HITL_SFT_v4_B.LimitaltitudetoStratosphere = u1;
  } else {
    /* Saturate: '<S109>/Limit  altitude  to Stratosphere' */
    modello_HITL_SFT_v4_B.LimitaltitudetoStratosphere = u0;
  }

  /* End of Saturate: '<S109>/Limit  altitude  to Stratosphere' */

  /* Gain: '<S109>/g//R' */
  modello_HITL_SFT_v4_B.gR = modello_HITL_SFT_v4_P.gR_Gain *
    modello_HITL_SFT_v4_B.LimitaltitudetoStratosphere;

  /* Product: '<S109>/Product1' */
  modello_HITL_SFT_v4_B.Product1 = 1.0 / modello_HITL_SFT_v4_B.Sum1 *
    modello_HITL_SFT_v4_B.gR;

  /* Math: '<S109>/Stratosphere Model'
   *
   * About '<S109>/Stratosphere Model':
   *  Operator: exp
   */
  modello_HITL_SFT_v4_B.StratosphereModel = exp(modello_HITL_SFT_v4_B.Product1);

  /* Product: '<S109>/Product2' */
  modello_HITL_SFT_v4_B.Product2 = modello_HITL_SFT_v4_B.P0 *
    modello_HITL_SFT_v4_B.StratosphereModel;

  /* RateTransition: '<S19>/Rate Transition' */
  if ((rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
       modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) &&
      (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
       modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0)) {
    modello_HITL_SFT_v4_DW.RateTransition_Buffer =
      modello_HITL_SFT_v4_B.Product2;
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* RateTransition: '<S19>/Rate Transition' */
    modello_HITL_SFT_v4_B.RateTransition =
      modello_HITL_SFT_v4_DW.RateTransition_Buffer;

    /* Sum: '<S19>/Sum13' */
    modello_HITL_SFT_v4_B.Sum13 = modello_HITL_SFT_v4_B.White_press +
      modello_HITL_SFT_v4_B.RateTransition;

    /* Lookup_n-D: '<S19>/1-D Lookup Table' incorporates:
     *  Sum: '<S19>/Sum13'
     */
    modello_HITL_SFT_v4_B.uDLookupTable = look1_binlxpw
      (modello_HITL_SFT_v4_B.Sum13, modello_HITL_SFT_v4_P.p_bmp,
       modello_HITL_SFT_v4_P.adc_P_bmp, 16362U);

    /* DataTypeConversion: '<S19>/Data Type Conversion' */
    tmp_f = floor(modello_HITL_SFT_v4_B.uDLookupTable);
    if (rtIsNaN(tmp_f) || rtIsInf(tmp_f)) {
      tmp_f = 0.0;
    } else {
      tmp_f = fmod(tmp_f, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S19>/Data Type Conversion' */
    modello_HITL_SFT_v4_B.DataTypeConversion_l = tmp_f < 0.0 ? -(int32_T)
      (uint32_T)-tmp_f : (int32_T)(uint32_T)tmp_f;

    /* S-Function (any2byte_svd): '<S19>/Byte Pack1' */

    /* Pack: <S19>/Byte Pack1 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - int32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(int32_T);
        memcpy((uint8_T*)((uint8_T*)&modello_HITL_SFT_v4_B.BytePack1[0] +
                          MW_outputPortOffset), (uint8_T*)
               &modello_HITL_SFT_v4_B.DataTypeConversion_l, MW_inputPortWidth);
      }
    }

    /* RandomNumber: '<S19>/White Noise4' */
    modello_HITL_SFT_v4_B.WhiteNoise4 = modello_HITL_SFT_v4_DW.NextOutput_p;
  }

  /* End of RateTransition: '<S19>/Rate Transition' */

  /* Integrator: '<S36>/phi theta psi' */
  modello_HITL_SFT_v4_B.phithetapsi[0] =
    modello_HITL_SFT_v4_X.phithetapsi_CSTATE[0];
  modello_HITL_SFT_v4_B.phithetapsi[1] =
    modello_HITL_SFT_v4_X.phithetapsi_CSTATE[1];
  modello_HITL_SFT_v4_B.phithetapsi[2] =
    modello_HITL_SFT_v4_X.phithetapsi_CSTATE[2];
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S106>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:RECEIVE */
    {
      UInt32 bytesActNumOfAddr;
      UInt32 bytesRefNumOf;
      bytesRefNumOf = (modello_HITL_SFT_v4_P.SFunction1_BytesRefNumOf <= 8) ?
        modello_HITL_SFT_v4_P.SFunction1_BytesRefNumOf : 8;
      dsser_receive(rtiDS4201SER_B1_Ser[2], bytesRefNumOf, (UInt8 *)
                    &modello_HITL_SFT_v4_B.SFunction1[0], &(bytesActNumOfAddr));
    }

    /* S-Function (byte2any_svd): '<S19>/Byte Unpack' */

    /* Unpack: <S19>/Byte Unpack */
    {
      uint32_T MW_inputPortOffset = 0;
      uint32_T MW_outputPortWidth = 0;
      uint32_T MW_remainder2 = 0;

      /* Packed input data type - uint8_T */
      /* Unpacking the values to output 1 */
      /* Output data type - real_T, size - 1 */
      {
        MW_outputPortWidth = 1 * sizeof(real_T);
        memcpy((uint8_T*)&modello_HITL_SFT_v4_B.h_ground, (uint8_T*)
               &modello_HITL_SFT_v4_B.SFunction1[0] + MW_inputPortOffset,
               MW_outputPortWidth);
      }
    }
  }

  /* Sum: '<S19>/Sum' */
  modello_HITL_SFT_v4_B.Sum_l = modello_HITL_SFT_v4_B.PositionIntegrator2[2] -
    modello_HITL_SFT_v4_B.h_ground;

  /* SignalConversion generated from: '<S119>/ SFunction ' incorporates:
   *  Constant: '<S19>/Constant'
   *  MATLAB Function: '<S19>/trasformazione quota earth-body'
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport4[0] =
    modello_HITL_SFT_v4_P.Constant_Value_n;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport4[1] =
    modello_HITL_SFT_v4_P.Constant_Value_n;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport4[2] =
    modello_HITL_SFT_v4_B.Sum_l;

  /* MATLAB Function: '<S19>/trasformazione quota earth-body' */
  /* MATLAB Function 'SENSORI/trasformazione quota earth-body': '<S119>:1' */
  /* '<S119>:1:4' */
  /* '<S119>:1:8' */
  /* '<S119>:1:10' */
  tmp_f = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
  u2 = cos(modello_HITL_SFT_v4_B.phithetapsi[2]);
  u0 = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
  diffLm = sin(modello_HITL_SFT_v4_B.phithetapsi[2]);
  Fss = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  Frms = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  b_s = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  b_fmod = cos(modello_HITL_SFT_v4_B.phithetapsi[2]);
  Mye = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  u1 = sin(modello_HITL_SFT_v4_B.phithetapsi[2]);
  Fsd = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  Frmd = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  tmp_g = sin(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_0 = cos(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp_1 = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_2 = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
  tmp_3 = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_4 = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  tmp_5 = cos(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp_6 = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_7 = sin(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp_8 = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_9 = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  tmp_a = sin(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp_b = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_c = cos(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp_d = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_e = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
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
    tmp_f = dcmt[i] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport4[0];
    tmp_f += dcmt[i + 3] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport4[1];
    tmp_f += dcmt[i + 6] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport4[2];
    Mape[i] = tmp_f;
  }

  modello_HITL_SFT_v4_B.h_lidar = Mape[2];

  /* Gain: '<S19>/Gain' */
  modello_HITL_SFT_v4_B.Gain_n = modello_HITL_SFT_v4_P.Gain_Gain_j *
    modello_HITL_SFT_v4_B.h_lidar;

  /* Saturate: '<S19>/Saturation3' */
  u0 = modello_HITL_SFT_v4_B.Gain_n;
  u1 = modello_HITL_SFT_v4_P.Saturation3_LowerSat;
  u2 = modello_HITL_SFT_v4_P.Saturation3_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S19>/Saturation3' */
    modello_HITL_SFT_v4_B.Saturation3 = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S19>/Saturation3' */
    modello_HITL_SFT_v4_B.Saturation3 = u1;
  } else {
    /* Saturate: '<S19>/Saturation3' */
    modello_HITL_SFT_v4_B.Saturation3 = u0;
  }

  /* End of Saturate: '<S19>/Saturation3' */

  /* Sum: '<S19>/Sum14' */
  modello_HITL_SFT_v4_B.Sum14 = modello_HITL_SFT_v4_B.WhiteNoise4 +
    modello_HITL_SFT_v4_B.Saturation3;

  /* RateTransition: '<S19>/Rate Transition1' */
  if ((rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
       modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) &&
      (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
       modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0)) {
    modello_HITL_SFT_v4_DW.RateTransition1_Buffer = modello_HITL_SFT_v4_B.Sum14;
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* RateTransition: '<S19>/Rate Transition1' */
    modello_HITL_SFT_v4_B.RateTransition1 =
      modello_HITL_SFT_v4_DW.RateTransition1_Buffer;

    /* DataTypeConversion: '<S19>/Data Type Conversion1' */
    tmp_f = floor(modello_HITL_SFT_v4_B.RateTransition1);
    if (rtIsNaN(tmp_f) || rtIsInf(tmp_f)) {
      tmp_f = 0.0;
    } else {
      tmp_f = fmod(tmp_f, 65536.0);
    }

    /* DataTypeConversion: '<S19>/Data Type Conversion1' */
    modello_HITL_SFT_v4_B.DataTypeConversion1 = (uint16_T)(tmp_f < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-tmp_f : (int32_T)(uint16_T)tmp_f);

    /* S-Function (any2byte_svd): '<S19>/Byte Pack' */

    /* Pack: <S19>/Byte Pack */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - uint16_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)((uint8_T*)&modello_HITL_SFT_v4_B.BytePack[0] +
                          MW_outputPortOffset), (uint8_T*)
               &modello_HITL_SFT_v4_B.DataTypeConversion1, MW_inputPortWidth);
      }
    }
  }

  /* End of RateTransition: '<S19>/Rate Transition1' */

  /* RateTransition: '<S19>/Rate Transition2' */
  if ((rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
       modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) &&
      (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
       modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0)) {
    modello_HITL_SFT_v4_DW.RateTransition2_Buffer = modello_HITL_SFT_v4_B.module;
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* RateTransition: '<S19>/Rate Transition2' */
    modello_HITL_SFT_v4_B.RateTransition2 =
      modello_HITL_SFT_v4_DW.RateTransition2_Buffer;

    /* Math: '<S19>/Math Function'
     *
     * About '<S19>/Math Function':
     *  Operator: magnitude^2
     */
    b_fmod = modello_HITL_SFT_v4_B.RateTransition2;

    /* Math: '<S19>/Math Function'
     *
     * About '<S19>/Math Function':
     *  Operator: magnitude^2
     */
    modello_HITL_SFT_v4_B.MathFunction = b_fmod * b_fmod;

    /* Gain: '<S19>/Gain3' */
    modello_HITL_SFT_v4_B.Gain3 = modello_HITL_SFT_v4_P.Gain3_Gain *
      modello_HITL_SFT_v4_B.MathFunction;

    /* Product: '<S19>/Divide' incorporates:
     *  Constant: '<S19>/Constant2'
     */
    modello_HITL_SFT_v4_B.Divide = modello_HITL_SFT_v4_B.Gain3 /
      modello_HITL_SFT_v4_P.Constant2_Value;

    /* Gain: '<S19>/Gain4' */
    modello_HITL_SFT_v4_B.Gain4 = modello_HITL_SFT_v4_P.Gain4_Gain *
      modello_HITL_SFT_v4_B.Divide;

    /* DataTypeConversion: '<S19>/Data Type Conversion2' */
    tmp_f = floor(modello_HITL_SFT_v4_B.Gain4);
    if (rtIsNaN(tmp_f) || rtIsInf(tmp_f)) {
      tmp_f = 0.0;
    } else {
      tmp_f = fmod(tmp_f, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S19>/Data Type Conversion2' */
    modello_HITL_SFT_v4_B.DataTypeConversion2 = tmp_f < 0.0 ? -(int32_T)
      (uint32_T)-tmp_f : (int32_T)(uint32_T)tmp_f;

    /* S-Function (any2byte_svd): '<S19>/Byte Pack2' */

    /* Pack: <S19>/Byte Pack2 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - int32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(int32_T);
        memcpy((uint8_T*)((uint8_T*)&modello_HITL_SFT_v4_B.BytePack2[0] +
                          MW_outputPortOffset), (uint8_T*)
               &modello_HITL_SFT_v4_B.DataTypeConversion2, MW_inputPortWidth);
      }
    }

    /* S-Function (rti_commonblock): '<S13>/S-Function1' incorporates:
     *  Constant: '<S19>/Constant1'
     */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:TRANSMIT */
    {
      UInt8 tempBuf[15];

      {
        int_T i1;
        const uint8_T *u0 = &modello_HITL_SFT_v4_P.Constant1_Value_p[0];
        UInt8 *p_tempBuf = &tempBuf[0];
        for (i1=0; i1 < 5; i1++) {
          p_tempBuf[i1] = (UInt8) u0[i1];
        }

        tempBuf[5] = (UInt8) modello_HITL_SFT_v4_B.BytePack1[0];
        tempBuf[6] = (UInt8) modello_HITL_SFT_v4_B.BytePack1[1];
        tempBuf[7] = (UInt8) modello_HITL_SFT_v4_B.BytePack1[2];
        tempBuf[8] = (UInt8) modello_HITL_SFT_v4_B.BytePack1[3];
        tempBuf[9] = (UInt8) modello_HITL_SFT_v4_B.BytePack[0];
        tempBuf[10] = (UInt8) modello_HITL_SFT_v4_B.BytePack[1];
        tempBuf[11] = (UInt8) modello_HITL_SFT_v4_B.BytePack2[0];
        tempBuf[12] = (UInt8) modello_HITL_SFT_v4_B.BytePack2[1];
        tempBuf[13] = (UInt8) modello_HITL_SFT_v4_B.BytePack2[2];
        tempBuf[14] = (UInt8) modello_HITL_SFT_v4_B.BytePack2[3];
      }

      {
        UInt32 bytesActNumOfAddr;
        UInt32 bytesRefNumOf;
        bytesRefNumOf = (modello_HITL_SFT_v4_P.SFunction1_BytesRefNumOf_n <= 15)
          ? modello_HITL_SFT_v4_P.SFunction1_BytesRefNumOf_n : 15;
        dsser_transmit(rtiDS4201SER_B1_Ser[3], bytesRefNumOf, tempBuf,
                       &(bytesActNumOfAddr));
      }
    }
  }

  /* End of RateTransition: '<S19>/Rate Transition2' */

  /* Sum: '<S85>/Sum2' incorporates:
   *  Constant: '<S85>/pi'
   */
  modello_HITL_SFT_v4_B.Sum2 = modello_HITL_SFT_v4_B.PositionIntegrator2[1] +
    modello_HITL_SFT_v4_P.pi_Value;

  /* Math: '<S85>/Math Function' incorporates:
   *  Constant: '<S85>/2pi'
   */
  modello_HITL_SFT_v4_B.MathFunction_o = rt_modd_snf(modello_HITL_SFT_v4_B.Sum2,
    modello_HITL_SFT_v4_P.upi_Value);

  /* Sum: '<S85>/Sum1' incorporates:
   *  Constant: '<S85>/pi'
   */
  modello_HITL_SFT_v4_B.Sum1_f = modello_HITL_SFT_v4_B.MathFunction_o -
    modello_HITL_SFT_v4_P.pi_Value;

  /* Gain: '<S17>/Gain' */
  modello_HITL_SFT_v4_B.Gain_h = modello_HITL_SFT_v4_P.Gain_Gain_a *
    modello_HITL_SFT_v4_B.Sum1_f;

  /* Sum: '<S84>/Sum2' incorporates:
   *  Constant: '<S84>/pi//2'
   */
  modello_HITL_SFT_v4_B.Sum2_o = modello_HITL_SFT_v4_B.PositionIntegrator2[0] +
    modello_HITL_SFT_v4_P.pi2_Value;

  /* Math: '<S84>/Math Function' incorporates:
   *  Constant: '<S84>/pi'
   */
  modello_HITL_SFT_v4_B.MathFunction_l = rt_modd_snf
    (modello_HITL_SFT_v4_B.Sum2_o, modello_HITL_SFT_v4_P.pi_Value_h);

  /* Sum: '<S84>/Sum1' incorporates:
   *  Constant: '<S84>/pi//2'
   */
  modello_HITL_SFT_v4_B.Sum1_i = modello_HITL_SFT_v4_B.MathFunction_l -
    modello_HITL_SFT_v4_P.pi2_Value;

  /* Gain: '<S84>/ChSign' */
  modello_HITL_SFT_v4_B.ChSign = modello_HITL_SFT_v4_P.ChSign_Gain *
    modello_HITL_SFT_v4_B.Sum1_i;

  /* Math: '<S84>/Math Function1' incorporates:
   *  Constant: '<S84>/2pi'
   */
  modello_HITL_SFT_v4_B.MathFunction1 = rt_modd_snf(modello_HITL_SFT_v4_B.Sum2_o,
    modello_HITL_SFT_v4_P.upi_Value_j);

  /* Switch: '<S84>/Switch' */
  if (modello_HITL_SFT_v4_B.MathFunction1 >=
      modello_HITL_SFT_v4_P.Switch_Threshold) {
    /* Switch: '<S84>/Switch' */
    modello_HITL_SFT_v4_B.Switch = modello_HITL_SFT_v4_B.ChSign;
  } else {
    /* Switch: '<S84>/Switch' */
    modello_HITL_SFT_v4_B.Switch = modello_HITL_SFT_v4_B.Sum1_i;
  }

  /* End of Switch: '<S84>/Switch' */

  /* Gain: '<S18>/Gain' */
  modello_HITL_SFT_v4_B.Gain_f = modello_HITL_SFT_v4_P.Gain_Gain_jh *
    modello_HITL_SFT_v4_B.Switch;

  /* SignalConversion generated from: '<Root>/S-Function Builder1' */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionBuilder1Inport1[0] =
    modello_HITL_SFT_v4_B.Gain_h;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionBuilder1Inport1[1] =
    modello_HITL_SFT_v4_B.Gain_f;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionBuilder1Inport1[2] =
    modello_HITL_SFT_v4_B.PositionIntegrator2[2];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionBuilder1Inport1[3] =
    modello_HITL_SFT_v4_B.phithetapsi[0];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionBuilder1Inport1[4] =
    modello_HITL_SFT_v4_B.phithetapsi[1];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionBuilder1Inport1[5] =
    modello_HITL_SFT_v4_B.phithetapsi[2];

  /* S-Function (outputStream_v1): '<Root>/S-Function Builder1' */
  outputStream_v1_Outputs_wrapper
    (&modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionBuilder1Inport1[0],
     &modello_HITL_SFT_v4_B.SFunctionBuilder1_o1[0],
     &modello_HITL_SFT_v4_B.SFunctionBuilder1_o2);
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S12>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:TRANSMIT */
    {
      UInt32 txFifoLevel;
      UInt32 bytesRefNumOf;
      bytesRefNumOf = (modello_HITL_SFT_v4_B.SFunctionBuilder1_o2 <= 64) ?
        modello_HITL_SFT_v4_B.SFunctionBuilder1_o2 : 64;
      txFifoLevel = dsser_transmit_fifo_level(rtiDS4201SER_B1_Ser[2]);
      if (((rtiDS4201SER_B1_Ser[2]->fifo_size) - txFifoLevel) > bytesRefNumOf) {
        modello_HITL_SFT_v4_B.SFunction1_o2 = dsser_transmit
          (rtiDS4201SER_B1_Ser[2], bytesRefNumOf,
           &modello_HITL_SFT_v4_B.SFunctionBuilder1_o1[0], (UInt32 *)
           &modello_HITL_SFT_v4_B.SFunction1_o1);
      } else {
        UInt32 *temp = (UInt32 *) &modello_HITL_SFT_v4_B.SFunction1_o1;
        *temp = 0;
        modello_HITL_SFT_v4_B.SFunction1_o2 = DSSER_FIFO_OVERFLOW;
      }
    }
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator =
      modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE;
  }

  /* Sum: '<S122>/Sum1' */
  modello_HITL_SFT_v4_B.Sum1_e = modello_HITL_SFT_v4_B.Switch +
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator;

  /* ZeroOrderHold: '<S118>/Zero-Order Hold' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
    /* ZeroOrderHold: '<S118>/Zero-Order Hold' */
    modello_HITL_SFT_v4_B.ZeroOrderHold = modello_HITL_SFT_v4_B.Sum1_e;

    /* Gain: '<S113>/Gain' */
    modello_HITL_SFT_v4_B.Gain_g = modello_HITL_SFT_v4_P.Gain_Gain_e *
      modello_HITL_SFT_v4_B.ZeroOrderHold;
  }

  /* End of ZeroOrderHold: '<S118>/Zero-Order Hold' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscreteIntegrator: '<S123>/Discrete-Time Integrator' */
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator_f =
      modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_n;
  }

  /* Sum: '<S123>/Sum1' */
  modello_HITL_SFT_v4_B.Sum1_p = modello_HITL_SFT_v4_B.Sum1_f +
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator_f;

  /* ZeroOrderHold: '<S118>/Zero-Order Hold1' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
    /* ZeroOrderHold: '<S118>/Zero-Order Hold1' */
    modello_HITL_SFT_v4_B.ZeroOrderHold1 = modello_HITL_SFT_v4_B.Sum1_p;

    /* Gain: '<S114>/Gain' */
    modello_HITL_SFT_v4_B.Gain_fx = modello_HITL_SFT_v4_P.Gain_Gain_m *
      modello_HITL_SFT_v4_B.ZeroOrderHold1;
  }

  /* End of ZeroOrderHold: '<S118>/Zero-Order Hold1' */

  /* SignalConversion generated from: '<S44>/sincos' */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtsincosInport1[0] =
    modello_HITL_SFT_v4_B.phithetapsi[2];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtsincosInport1[1] =
    modello_HITL_SFT_v4_B.phithetapsi[1];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtsincosInport1[2] =
    modello_HITL_SFT_v4_B.phithetapsi[0];

  /* Trigonometry: '<S44>/sincos' */
  b_s = modello_HITL_SFT_v4_B.TmpSignalConversionAtsincosInport1[0];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  modello_HITL_SFT_v4_B.sincos_o1[0] = b_fmod;
  modello_HITL_SFT_v4_B.sincos_o2[0] = b_s;
  b_s = modello_HITL_SFT_v4_B.TmpSignalConversionAtsincosInport1[1];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  modello_HITL_SFT_v4_B.sincos_o1[1] = b_fmod;
  modello_HITL_SFT_v4_B.sincos_o2[1] = b_s;
  b_s = modello_HITL_SFT_v4_B.TmpSignalConversionAtsincosInport1[2];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  modello_HITL_SFT_v4_B.sincos_o1[2] = b_fmod;
  modello_HITL_SFT_v4_B.sincos_o2[2] = b_s;

  /* Fcn: '<S44>/Fcn11' */
  modello_HITL_SFT_v4_B.VectorConcatenate[0] = modello_HITL_SFT_v4_B.sincos_o2[1]
    * modello_HITL_SFT_v4_B.sincos_o2[0];

  /* Fcn: '<S44>/Fcn21' */
  modello_HITL_SFT_v4_B.VectorConcatenate[1] = modello_HITL_SFT_v4_B.sincos_o1[2]
    * modello_HITL_SFT_v4_B.sincos_o1[1] * modello_HITL_SFT_v4_B.sincos_o2[0] -
    modello_HITL_SFT_v4_B.sincos_o2[2] * modello_HITL_SFT_v4_B.sincos_o1[0];

  /* Fcn: '<S44>/Fcn31' */
  modello_HITL_SFT_v4_B.VectorConcatenate[2] = modello_HITL_SFT_v4_B.sincos_o2[2]
    * modello_HITL_SFT_v4_B.sincos_o1[1] * modello_HITL_SFT_v4_B.sincos_o2[0] +
    modello_HITL_SFT_v4_B.sincos_o1[2] * modello_HITL_SFT_v4_B.sincos_o1[0];

  /* Fcn: '<S44>/Fcn12' */
  modello_HITL_SFT_v4_B.VectorConcatenate[3] = modello_HITL_SFT_v4_B.sincos_o2[1]
    * modello_HITL_SFT_v4_B.sincos_o1[0];

  /* Fcn: '<S44>/Fcn22' */
  modello_HITL_SFT_v4_B.VectorConcatenate[4] = modello_HITL_SFT_v4_B.sincos_o1[2]
    * modello_HITL_SFT_v4_B.sincos_o1[1] * modello_HITL_SFT_v4_B.sincos_o1[0] +
    modello_HITL_SFT_v4_B.sincos_o2[2] * modello_HITL_SFT_v4_B.sincos_o2[0];

  /* Fcn: '<S44>/Fcn32' */
  modello_HITL_SFT_v4_B.VectorConcatenate[5] = modello_HITL_SFT_v4_B.sincos_o2[2]
    * modello_HITL_SFT_v4_B.sincos_o1[1] * modello_HITL_SFT_v4_B.sincos_o1[0] -
    modello_HITL_SFT_v4_B.sincos_o1[2] * modello_HITL_SFT_v4_B.sincos_o2[0];

  /* Fcn: '<S44>/Fcn13' */
  modello_HITL_SFT_v4_B.VectorConcatenate[6] = -modello_HITL_SFT_v4_B.sincos_o1
    [1];

  /* Fcn: '<S44>/Fcn23' */
  modello_HITL_SFT_v4_B.VectorConcatenate[7] = modello_HITL_SFT_v4_B.sincos_o1[2]
    * modello_HITL_SFT_v4_B.sincos_o2[1];

  /* Fcn: '<S44>/Fcn33' */
  modello_HITL_SFT_v4_B.VectorConcatenate[8] = modello_HITL_SFT_v4_B.sincos_o2[2]
    * modello_HITL_SFT_v4_B.sincos_o2[1];

  /* Reshape: '<S46>/Reshape (9) to [3x3] column-major' */
  memcpy(&modello_HITL_SFT_v4_B.Reshape9to3x3columnmajor[0],
         &modello_HITL_SFT_v4_B.VectorConcatenate[0], 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    /* Math: '<S26>/Transpose' incorporates:
     *  Reshape: '<S46>/Reshape (9) to [3x3] column-major'
     */
    modello_HITL_SFT_v4_B.Transpose[3 * i] =
      modello_HITL_SFT_v4_B.Reshape9to3x3columnmajor[i];
    modello_HITL_SFT_v4_B.Transpose[3 * i + 1] =
      modello_HITL_SFT_v4_B.Reshape9to3x3columnmajor[i + 3];
    modello_HITL_SFT_v4_B.Transpose[3 * i + 2] =
      modello_HITL_SFT_v4_B.Reshape9to3x3columnmajor[i + 6];

    /* Reshape: '<S43>/Reshape1' */
    modello_HITL_SFT_v4_B.Reshape1[i] = modello_HITL_SFT_v4_B.ubvbwb[i];
  }

  /* Product: '<S43>/Product' incorporates:
   *  Math: '<S26>/Transpose'
   *  Reshape: '<S43>/Reshape1'
   */
  memcpy(&dcmt[0], &modello_HITL_SFT_v4_B.Transpose[0], 9U * sizeof(real_T));
  Fape[0] = modello_HITL_SFT_v4_B.Reshape1[0];
  Fape[1] = modello_HITL_SFT_v4_B.Reshape1[1];
  Fape[2] = modello_HITL_SFT_v4_B.Reshape1[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S43>/Product' */
    modello_HITL_SFT_v4_B.Product[i] = 0.0;
    modello_HITL_SFT_v4_B.Product[i] += dcmt[i] * Fape[0];
    modello_HITL_SFT_v4_B.Product[i] += dcmt[i + 3] * Fape[1];
    modello_HITL_SFT_v4_B.Product[i] += dcmt[i + 6] * Fape[2];
  }

  /* Reshape: '<S43>/Reshape2' incorporates:
   *  Product: '<S43>/Product'
   */
  modello_HITL_SFT_v4_B.Reshape2[0] = modello_HITL_SFT_v4_B.Product[0];
  modello_HITL_SFT_v4_B.Reshape2[1] = modello_HITL_SFT_v4_B.Product[1];
  modello_HITL_SFT_v4_B.Reshape2[2] = modello_HITL_SFT_v4_B.Product[2];

  /* UnitConversion: '<S41>/Unit Conversion' */
  /* Unit Conversion - from: m/s to: m/s
     Expression: output = (1*input) + (0) */
  modello_HITL_SFT_v4_B.UnitConversion_g[0] = modello_HITL_SFT_v4_B.Reshape2[0];
  modello_HITL_SFT_v4_B.UnitConversion_g[1] = modello_HITL_SFT_v4_B.Reshape2[1];
  modello_HITL_SFT_v4_B.UnitConversion_g[2] = modello_HITL_SFT_v4_B.Reshape2[2];

  /* Math: '<S80>/Square2' */
  modello_HITL_SFT_v4_B.Square2 = modello_HITL_SFT_v4_B.UnitConversion_g[0] *
    modello_HITL_SFT_v4_B.UnitConversion_g[0];

  /* Math: '<S80>/Square1' */
  modello_HITL_SFT_v4_B.Square1 = modello_HITL_SFT_v4_B.UnitConversion_g[1] *
    modello_HITL_SFT_v4_B.UnitConversion_g[1];

  /* Sum: '<S80>/Add' */
  modello_HITL_SFT_v4_B.Add = modello_HITL_SFT_v4_B.Square2 +
    modello_HITL_SFT_v4_B.Square1;

  /* Sqrt: '<S80>/Sqrt' */
  modello_HITL_SFT_v4_B.Sqrt = sqrt(modello_HITL_SFT_v4_B.Add);
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
    /* RandomNumber: '<S124>/Noise V_hor' */
    modello_HITL_SFT_v4_B.NoiseV_hor = modello_HITL_SFT_v4_DW.NextOutput_c;

    /* RandomNumber: '<S124>/noise terra V_hor1' */
    modello_HITL_SFT_v4_B.noiseterraV_hor1 = modello_HITL_SFT_v4_DW.NextOutput_m;

    /* Abs: '<S124>/Abs' */
    modello_HITL_SFT_v4_B.Abs = fabs(modello_HITL_SFT_v4_B.noiseterraV_hor1);
  }

  /* ZeroOrderHold: '<S124>/Zero-Order Hold2' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S124>/Zero-Order Hold2' */
    modello_HITL_SFT_v4_B.ZeroOrderHold2 = modello_HITL_SFT_v4_B.Sqrt;

    /* Switch: '<S124>/Switch4' */
    if (modello_HITL_SFT_v4_B.ZeroOrderHold2 >
        modello_HITL_SFT_v4_P.Switch4_Threshold) {
      /* Switch: '<S124>/Switch4' */
      modello_HITL_SFT_v4_B.Switch4 = modello_HITL_SFT_v4_B.NoiseV_hor;
    } else {
      /* Switch: '<S124>/Switch4' */
      modello_HITL_SFT_v4_B.Switch4 = modello_HITL_SFT_v4_B.Abs;
    }

    /* End of Switch: '<S124>/Switch4' */

    /* Sum: '<S124>/Sum5' */
    modello_HITL_SFT_v4_B.Sum5 = modello_HITL_SFT_v4_B.ZeroOrderHold2 +
      modello_HITL_SFT_v4_B.Switch4;

    /* ZeroOrderHold: '<S118>/Zero-Order Hold4' */
    if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
        modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
      /* ZeroOrderHold: '<S118>/Zero-Order Hold4' */
      modello_HITL_SFT_v4_B.ZeroOrderHold4 = modello_HITL_SFT_v4_B.Sum5;
    }

    /* End of ZeroOrderHold: '<S118>/Zero-Order Hold4' */
  }

  /* End of ZeroOrderHold: '<S124>/Zero-Order Hold2' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
    /* Gain: '<S19>/Gain5' */
    modello_HITL_SFT_v4_B.Gain5 = modello_HITL_SFT_v4_P.Gain5_Gain *
      modello_HITL_SFT_v4_B.ZeroOrderHold4;
  }

  /* Trigonometry: '<S81>/Atan2' */
  modello_HITL_SFT_v4_B.Atan2 = rt_atan2d_snf
    (modello_HITL_SFT_v4_B.UnitConversion_g[1],
     modello_HITL_SFT_v4_B.UnitConversion_g[0]);

  /* ZeroOrderHold: '<S124>/Zero-Order Hold' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S124>/Zero-Order Hold' */
    modello_HITL_SFT_v4_B.ZeroOrderHold_d = modello_HITL_SFT_v4_B.Atan2;

    /* RandomNumber: '<S124>/Rumore bianco' */
    modello_HITL_SFT_v4_B.Rumorebianco = modello_HITL_SFT_v4_DW.NextOutput_d;

    /* Product: '<S124>/Divide2' incorporates:
     *  Constant: '<S124>/Std_vel'
     */
    modello_HITL_SFT_v4_B.Divide2 = modello_HITL_SFT_v4_P.Std_vel /
      modello_HITL_SFT_v4_B.ZeroOrderHold2;

    /* Product: '<S124>/Multiply5' */
    modello_HITL_SFT_v4_B.Multiply5 = modello_HITL_SFT_v4_B.Rumorebianco *
      modello_HITL_SFT_v4_B.Divide2;

    /* RandomNumber: '<S124>/Noise terra course' */
    modello_HITL_SFT_v4_B.Noiseterracourse =
      modello_HITL_SFT_v4_DW.NextOutput_c2;

    /* Switch: '<S124>/Switch3' */
    if (modello_HITL_SFT_v4_B.ZeroOrderHold2 >
        modello_HITL_SFT_v4_P.Switch3_Threshold) {
      /* Switch: '<S124>/Switch3' */
      modello_HITL_SFT_v4_B.Switch3 = modello_HITL_SFT_v4_B.Multiply5;
    } else {
      /* Switch: '<S124>/Switch3' */
      modello_HITL_SFT_v4_B.Switch3 = modello_HITL_SFT_v4_B.Noiseterracourse;
    }

    /* End of Switch: '<S124>/Switch3' */

    /* Sum: '<S124>/Add' */
    modello_HITL_SFT_v4_B.Course_sporco = modello_HITL_SFT_v4_B.ZeroOrderHold_d
      + modello_HITL_SFT_v4_B.Switch3;

    /* MATLAB Function: '<S124>/0-2pi Wrapper' */
    /* MATLAB Function 'SENSORI/Subsystem1/Subsystem2/0-2pi Wrapper': '<S125>:1' */
    /* '<S125>:1:6' */
    /* '<S125>:1:8' */
    /* '<S125>:1:9' */
    b_fmod = modello_HITL_SFT_v4_B.Course_sporco - floor
      (modello_HITL_SFT_v4_B.Course_sporco / 6.2831853071795862) *
      6.2831853071795862;
    if (b_fmod < 0.0) {
      /* '<S125>:1:12' */
      /* '<S125>:1:14' */
      b_fmod += 6.2831853071795862;
    }

    /* '<S125>:1:18' */
    modello_HITL_SFT_v4_B.y = b_fmod;

    /* End of MATLAB Function: '<S124>/0-2pi Wrapper' */

    /* Switch: '<S124>/Switch1' */
    if (modello_HITL_SFT_v4_B.ZeroOrderHold2 >
        modello_HITL_SFT_v4_P.Switch1_Threshold_g) {
      /* Switch: '<S124>/Switch1' */
      modello_HITL_SFT_v4_B.Switch1_a = modello_HITL_SFT_v4_B.y;
    } else {
      /* Switch: '<S124>/Switch1' incorporates:
       *  Constant: '<S124>/Constant'
       */
      modello_HITL_SFT_v4_B.Switch1_a = modello_HITL_SFT_v4_P.Constant_Value_l;
    }

    /* End of Switch: '<S124>/Switch1' */

    /* ZeroOrderHold: '<S118>/Zero-Order Hold5' */
    if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
        modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
      /* ZeroOrderHold: '<S118>/Zero-Order Hold5' */
      modello_HITL_SFT_v4_B.ZeroOrderHold5 = modello_HITL_SFT_v4_B.Switch1_a;
    }

    /* End of ZeroOrderHold: '<S118>/Zero-Order Hold5' */
  }

  /* End of ZeroOrderHold: '<S124>/Zero-Order Hold' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
    /* Gain: '<S111>/Gain' */
    modello_HITL_SFT_v4_B.Gain_m = modello_HITL_SFT_v4_P.Gain_Gain_p *
      modello_HITL_SFT_v4_B.ZeroOrderHold5;

    /* ZeroOrderHold: '<S118>/Zero-Order Hold6' */
    modello_HITL_SFT_v4_B.ZeroOrderHold6 =
      modello_HITL_SFT_v4_B.PositionIntegrator2[2];
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[4] == 0) {
    /* S-Function (SImulate_messageGPS_nmea_carriage_return): '<S108>/S-Function Builder1' */
    SImulate_messageGPS_nmea_carriage_return_Outputs_wrapper
      (&modello_HITL_SFT_v4_B.Gain_g, &modello_HITL_SFT_v4_B.Gain_fx,
       &modello_HITL_SFT_v4_B.Gain5, &modello_HITL_SFT_v4_B.Gain_m,
       &modello_HITL_SFT_v4_B.ZeroOrderHold6,
       &modello_HITL_SFT_v4_B.SFunctionBuilder1[0]);

    /* S-Function (rti_commonblock): '<S20>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:TRANSMIT */
    {
      UInt32 txFifoLevel;
      UInt32 bytesRefNumOf;
      bytesRefNumOf = (modello_HITL_SFT_v4_P.SFunction1_BytesRefNumOf_l <= 131) ?
        modello_HITL_SFT_v4_P.SFunction1_BytesRefNumOf_l : 131;
      txFifoLevel = dsser_transmit_fifo_level(rtiDS4201SER_B1_Ser[1]);
      if (((rtiDS4201SER_B1_Ser[1]->fifo_size) - txFifoLevel) > bytesRefNumOf) {
        UInt32 bytesActNumOfAddr;
        dsser_transmit(rtiDS4201SER_B1_Ser[1], bytesRefNumOf,
                       &modello_HITL_SFT_v4_B.SFunctionBuilder1[0],
                       &(bytesActNumOfAddr));
      }
    }
  }

  /* SignalConversion generated from: '<S78>/ SFunction ' incorporates:
   *  MATLAB Function: '<S34>/controllo divisione per 0 su alpha'
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ny[0] =
    modello_HITL_SFT_v4_B.Va[2];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ny[1] =
    modello_HITL_SFT_v4_B.Va[0];

  /* MATLAB Function: '<S34>/controllo divisione per 0 su alpha' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Velocità1/controllo divisione per 0 su alpha': '<S78>:1' */
  if (modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ny[1] == 0.0)
  {
    /* '<S78>:1:6' */
    /* '<S78>:1:7' */
    modello_HITL_SFT_v4_B.y_j = 0.0;
  } else {
    /* '<S78>:1:9' */
    modello_HITL_SFT_v4_B.y_j =
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ny[0] /
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ny[1];
  }

  /* Trigonometry: '<S34>/Trigonometric Function1' */
  modello_HITL_SFT_v4_B.u = atan(modello_HITL_SFT_v4_B.y_j);

  /* SignalConversion generated from: '<S79>/ SFunction ' incorporates:
   *  MATLAB Function: '<S34>/controllo divisione per 0 su beta'
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n[0] =
    modello_HITL_SFT_v4_B.Va[1];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n[1] =
    modello_HITL_SFT_v4_B.module;

  /* MATLAB Function: '<S34>/controllo divisione per 0 su beta' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Velocità1/controllo divisione per 0 su beta': '<S79>:1' */
  if (modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n[1] == 0.0) {
    /* '<S79>:1:6' */
    /* '<S79>:1:7' */
    modello_HITL_SFT_v4_B.y_m = 0.0;
  } else {
    /* '<S79>:1:9' */
    modello_HITL_SFT_v4_B.y_m =
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n[0] /
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n[1];
  }

  /* Trigonometry: '<S34>/Trigonometric Function2' */
  u0 = modello_HITL_SFT_v4_B.y_m;
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* Trigonometry: '<S34>/Trigonometric Function2' */
  modello_HITL_SFT_v4_B.u_n = asin(u0);

  /* MATLAB Function: '<S28>/MATLAB Function' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/MATLAB Function': '<S56>:1' */
  /* '<S56>:1:4' */
  tmp_f = cos(modello_HITL_SFT_v4_B.u);
  u2 = cos(modello_HITL_SFT_v4_B.u_n);
  u0 = cos(modello_HITL_SFT_v4_B.u);
  diffLm = sin(modello_HITL_SFT_v4_B.u_n);
  Fss = sin(modello_HITL_SFT_v4_B.u);
  Frms = sin(modello_HITL_SFT_v4_B.u_n);
  b_s = cos(modello_HITL_SFT_v4_B.u_n);
  b_fmod = sin(modello_HITL_SFT_v4_B.u);
  Mye = cos(modello_HITL_SFT_v4_B.u_n);
  u1 = sin(modello_HITL_SFT_v4_B.u);
  Fsd = sin(modello_HITL_SFT_v4_B.u_n);
  Frmd = cos(modello_HITL_SFT_v4_B.u);
  modello_HITL_SFT_v4_B.Lbw[0] = tmp_f * u2;
  modello_HITL_SFT_v4_B.Lbw[3] = -u0 * diffLm;
  modello_HITL_SFT_v4_B.Lbw[6] = -Fss;
  modello_HITL_SFT_v4_B.Lbw[1] = Frms;
  modello_HITL_SFT_v4_B.Lbw[4] = b_s;
  modello_HITL_SFT_v4_B.Lbw[7] = 0.0;
  modello_HITL_SFT_v4_B.Lbw[2] = b_fmod * Mye;
  modello_HITL_SFT_v4_B.Lbw[5] = -u1 * Fsd;
  modello_HITL_SFT_v4_B.Lbw[8] = Frmd;

  /* Lookup_n-D: '<S58>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  modello_HITL_SFT_v4_B.uDLookupTable_n = look2_binlxpw(modello_HITL_SFT_v4_B.u,
    modello_HITL_SFT_v4_B.u_n, modello_HITL_SFT_v4_P.alphavec_rad,
    modello_HITL_SFT_v4_P.betavec_rad,
    modello_HITL_SFT_v4_P.uDLookupTable_tableData,
    modello_HITL_SFT_v4_P.uDLookupTable_maxIndex, 13U);

  /* Sum: '<S58>/Sum1' incorporates:
   *  Constant: '<S23>/CD_0'
   */
  modello_HITL_SFT_v4_B.Sum1_fc = modello_HITL_SFT_v4_B.uDLookupTable_n +
    modello_HITL_SFT_v4_P.CD0;

  /* Gain: '<S55>/Gain4' */
  modello_HITL_SFT_v4_B.CD = modello_HITL_SFT_v4_P.Gain4_Gain_l *
    modello_HITL_SFT_v4_B.Sum1_fc;

  /* Lookup_n-D: '<S59>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  modello_HITL_SFT_v4_B.uDLookupTable_e = look2_binlxpw(modello_HITL_SFT_v4_B.u,
    modello_HITL_SFT_v4_B.u_n, modello_HITL_SFT_v4_P.alphavec_rad,
    modello_HITL_SFT_v4_P.betavec_rad,
    modello_HITL_SFT_v4_P.uDLookupTable_tableData_o,
    modello_HITL_SFT_v4_P.uDLookupTable_maxIndex_c, 13U);

  /* Saturate: '<S59>/Saturation' */
  u0 = modello_HITL_SFT_v4_B.uDLookupTable_e;
  u1 = modello_HITL_SFT_v4_P.Saturation_LowerSat;
  u2 = modello_HITL_SFT_v4_P.Saturation_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S59>/Saturation' */
    modello_HITL_SFT_v4_B.Saturation = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S59>/Saturation' */
    modello_HITL_SFT_v4_B.Saturation = u1;
  } else {
    /* Saturate: '<S59>/Saturation' */
    modello_HITL_SFT_v4_B.Saturation = u0;
  }

  /* End of Saturate: '<S59>/Saturation' */

  /* Integrator: '<S26>/p,q,r ' */
  modello_HITL_SFT_v4_B.pqr[0] = modello_HITL_SFT_v4_X.pqr_CSTATE[0];
  modello_HITL_SFT_v4_B.pqr[1] = modello_HITL_SFT_v4_X.pqr_CSTATE[1];
  modello_HITL_SFT_v4_B.pqr[2] = modello_HITL_SFT_v4_X.pqr_CSTATE[2];

  /* SignalConversion generated from: '<S61>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S59>/controllo divisione per zero Yp '
   */
  b_fmod = modello_HITL_SFT_v4_P.b / 2.0;

  /* SignalConversion generated from: '<S61>/ SFunction ' incorporates:
   *  Constant: '<S23>/CY_p '
   *  MATLAB Function: '<S59>/controllo divisione per zero Yp '
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[0] =
    modello_HITL_SFT_v4_P.CYp;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[1] =
    modello_HITL_SFT_v4_B.pqr[0];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[2] = b_fmod;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[3] =
    modello_HITL_SFT_v4_B.module;

  /* MATLAB Function: '<S59>/controllo divisione per zero Yp ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem1/controllo divisione per zero Yp ': '<S61>:1' */
  if (modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[3] == 0.0) {
    /* '<S61>:1:6' */
    /* '<S61>:1:7' */
    modello_HITL_SFT_v4_B.y_gq = 0.0;
  } else {
    /* '<S61>:1:9' */
    modello_HITL_SFT_v4_B.y_gq =
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[0] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[1] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[2] /
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[3];
  }

  /* SignalConversion generated from: '<S62>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S59>/controllo divisione per zero Yr'
   */
  b_fmod = modello_HITL_SFT_v4_P.b / 2.0;

  /* SignalConversion generated from: '<S62>/ SFunction ' incorporates:
   *  Constant: '<S23>/CY_r'
   *  MATLAB Function: '<S59>/controllo divisione per zero Yr'
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[0] =
    modello_HITL_SFT_v4_B.pqr[2];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[1] = b_fmod;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[2] =
    modello_HITL_SFT_v4_P.CYr;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[3] =
    modello_HITL_SFT_v4_B.module;

  /* MATLAB Function: '<S59>/controllo divisione per zero Yr' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem1/controllo divisione per zero Yr': '<S62>:1' */
  if (modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[3] == 0.0)
  {
    /* '<S62>:1:6' */
    /* '<S62>:1:7' */
    modello_HITL_SFT_v4_B.y_b = 0.0;
  } else {
    /* '<S62>:1:9' */
    modello_HITL_SFT_v4_B.y_b =
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[0] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[1] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[2] /
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[3];
  }

  /* StateSpace: '<S2>/State-Space2' */
  modello_HITL_SFT_v4_B.Timone = 0.0;
  modello_HITL_SFT_v4_B.Timone += modello_HITL_SFT_v4_P.StateSpace2_C *
    modello_HITL_SFT_v4_X.StateSpace2_CSTATE;

  /* Saturate: '<S2>/Saturation3' */
  b_fmod = -modello_HITL_SFT_v4_P.attuatore_Rmax;
  b_s = modello_HITL_SFT_v4_P.attuatore_Rmax + 0.1;
  u0 = modello_HITL_SFT_v4_B.Timone;
  if (u0 > b_s) {
    /* Saturate: '<S2>/Saturation3' */
    modello_HITL_SFT_v4_B.deltaR = b_s;
  } else if (u0 < b_fmod) {
    /* Saturate: '<S2>/Saturation3' */
    modello_HITL_SFT_v4_B.deltaR = b_fmod;
  } else {
    /* Saturate: '<S2>/Saturation3' */
    modello_HITL_SFT_v4_B.deltaR = u0;
  }

  /* End of Saturate: '<S2>/Saturation3' */

  /* StateSpace: '<S3>/State-Space2' */
  modello_HITL_SFT_v4_B.Timone_l = 0.0;
  modello_HITL_SFT_v4_B.Timone_l += modello_HITL_SFT_v4_P.StateSpace2_C_g *
    modello_HITL_SFT_v4_X.StateSpace2_CSTATE_b;

  /* Saturate: '<S3>/Saturation3' */
  b_fmod = -modello_HITL_SFT_v4_P.attuatore_Rmax;
  b_s = modello_HITL_SFT_v4_P.attuatore_Rmax + 0.1;
  u0 = modello_HITL_SFT_v4_B.Timone_l;
  if (u0 > b_s) {
    /* Saturate: '<S3>/Saturation3' */
    modello_HITL_SFT_v4_B.deltaR_i = b_s;
  } else if (u0 < b_fmod) {
    /* Saturate: '<S3>/Saturation3' */
    modello_HITL_SFT_v4_B.deltaR_i = b_fmod;
  } else {
    /* Saturate: '<S3>/Saturation3' */
    modello_HITL_SFT_v4_B.deltaR_i = u0;
  }

  /* End of Saturate: '<S3>/Saturation3' */

  /* Switch generated from: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (modello_HITL_SFT_v4_P.Constant_Value_k >
      modello_HITL_SFT_v4_P.Switch_4_Threshold) {
    /* Switch generated from: '<Root>/Switch' */
    modello_HITL_SFT_v4_B.deltaR_d = modello_HITL_SFT_v4_B.deltaR;
  } else {
    /* Switch generated from: '<Root>/Switch' */
    modello_HITL_SFT_v4_B.deltaR_d = modello_HITL_SFT_v4_B.deltaR_i;
  }

  /* Product: '<S59>/Product' incorporates:
   *  Constant: '<S23>/CY_dR'
   */
  modello_HITL_SFT_v4_B.Product_f = modello_HITL_SFT_v4_P.CYdR *
    modello_HITL_SFT_v4_B.deltaR_d;

  /* StateSpace: '<S2>/State-Space1' */
  modello_HITL_SFT_v4_B.Alettoni = 0.0;
  modello_HITL_SFT_v4_B.Alettoni += modello_HITL_SFT_v4_P.StateSpace1_C *
    modello_HITL_SFT_v4_X.StateSpace1_CSTATE;

  /* Saturate: '<S2>/Saturation2' */
  b_fmod = -modello_HITL_SFT_v4_P.attuatore_Amax;
  b_s = modello_HITL_SFT_v4_P.attuatore_Amax + 0.1;
  u0 = modello_HITL_SFT_v4_B.Alettoni;
  if (u0 > b_s) {
    /* Saturate: '<S2>/Saturation2' */
    modello_HITL_SFT_v4_B.deltaA = b_s;
  } else if (u0 < b_fmod) {
    /* Saturate: '<S2>/Saturation2' */
    modello_HITL_SFT_v4_B.deltaA = b_fmod;
  } else {
    /* Saturate: '<S2>/Saturation2' */
    modello_HITL_SFT_v4_B.deltaA = u0;
  }

  /* End of Saturate: '<S2>/Saturation2' */

  /* StateSpace: '<S3>/State-Space1' */
  modello_HITL_SFT_v4_B.Alettoni_p = 0.0;
  modello_HITL_SFT_v4_B.Alettoni_p += modello_HITL_SFT_v4_P.StateSpace1_C_h *
    modello_HITL_SFT_v4_X.StateSpace1_CSTATE_b;

  /* Saturate: '<S3>/Saturation2' */
  b_fmod = -modello_HITL_SFT_v4_P.attuatore_Amax;
  b_s = modello_HITL_SFT_v4_P.attuatore_Amax + 0.1;
  u0 = modello_HITL_SFT_v4_B.Alettoni_p;
  if (u0 > b_s) {
    /* Saturate: '<S3>/Saturation2' */
    modello_HITL_SFT_v4_B.deltaA_g = b_s;
  } else if (u0 < b_fmod) {
    /* Saturate: '<S3>/Saturation2' */
    modello_HITL_SFT_v4_B.deltaA_g = b_fmod;
  } else {
    /* Saturate: '<S3>/Saturation2' */
    modello_HITL_SFT_v4_B.deltaA_g = u0;
  }

  /* End of Saturate: '<S3>/Saturation2' */

  /* Switch generated from: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (modello_HITL_SFT_v4_P.Constant_Value_k >
      modello_HITL_SFT_v4_P.Switch_3_Threshold) {
    /* Switch generated from: '<Root>/Switch' */
    modello_HITL_SFT_v4_B.deltaA_gw = modello_HITL_SFT_v4_B.deltaA;
  } else {
    /* Switch generated from: '<Root>/Switch' */
    modello_HITL_SFT_v4_B.deltaA_gw = modello_HITL_SFT_v4_B.deltaA_g;
  }

  /* Product: '<S59>/Product3' incorporates:
   *  Constant: '<S23>/CY_dA'
   */
  modello_HITL_SFT_v4_B.Product3 = modello_HITL_SFT_v4_P.CYdA *
    modello_HITL_SFT_v4_B.deltaA_gw;

  /* Sum: '<S59>/Sum' */
  modello_HITL_SFT_v4_B.Sum_o = (((modello_HITL_SFT_v4_B.Saturation +
    modello_HITL_SFT_v4_B.y_gq) + modello_HITL_SFT_v4_B.y_b) +
    modello_HITL_SFT_v4_B.Product_f) + modello_HITL_SFT_v4_B.Product3;

  /* Lookup_n-D: '<S60>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  modello_HITL_SFT_v4_B.uDLookupTable_g = look2_binlxpw(modello_HITL_SFT_v4_B.u,
    modello_HITL_SFT_v4_B.u_n, modello_HITL_SFT_v4_P.alphavec_rad,
    modello_HITL_SFT_v4_P.betavec_rad,
    modello_HITL_SFT_v4_P.uDLookupTable_tableData_e,
    modello_HITL_SFT_v4_P.uDLookupTable_maxIndex_o, 13U);

  /* Gain: '<S60>/Gain1' */
  modello_HITL_SFT_v4_B.Gain1 = modello_HITL_SFT_v4_P.Gain1_Gain *
    modello_HITL_SFT_v4_B.module;

  /* SignalConversion generated from: '<S63>/ SFunction ' incorporates:
   *  Constant: '<S23>/CL_q '
   *  Constant: '<S23>/cbar '
   *  MATLAB Function: '<S60>/controllo divisione per zero Lq '
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[0] =
    modello_HITL_SFT_v4_P.CLq;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[1] =
    modello_HITL_SFT_v4_B.pqr[1];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[2] =
    modello_HITL_SFT_v4_P.cbar;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[3] =
    modello_HITL_SFT_v4_B.Gain1;

  /* MATLAB Function: '<S60>/controllo divisione per zero Lq ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Forze assi vento//q/Subsystem2/controllo divisione per zero Lq ': '<S63>:1' */
  if (modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[3] == 0.0) {
    /* '<S63>:1:6' */
    /* '<S63>:1:7' */
    modello_HITL_SFT_v4_B.y_g1 = 0.0;
  } else {
    /* '<S63>:1:9' */
    modello_HITL_SFT_v4_B.y_g1 =
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[0] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[1] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[2] /
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[3];
  }

  /* StateSpace: '<S2>/State-Space' */
  modello_HITL_SFT_v4_B.Equilibratore = 0.0;
  modello_HITL_SFT_v4_B.Equilibratore += modello_HITL_SFT_v4_P.StateSpace_C *
    modello_HITL_SFT_v4_X.StateSpace_CSTATE;

  /* Saturate: '<S2>/Saturation1' */
  b_fmod = -modello_HITL_SFT_v4_P.attuatore_Emax;
  b_s = modello_HITL_SFT_v4_P.attuatore_Emax + 0.1;
  u0 = modello_HITL_SFT_v4_B.Equilibratore;
  if (u0 > b_s) {
    /* Saturate: '<S2>/Saturation1' */
    modello_HITL_SFT_v4_B.deltaE = b_s;
  } else if (u0 < b_fmod) {
    /* Saturate: '<S2>/Saturation1' */
    modello_HITL_SFT_v4_B.deltaE = b_fmod;
  } else {
    /* Saturate: '<S2>/Saturation1' */
    modello_HITL_SFT_v4_B.deltaE = u0;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* StateSpace: '<S3>/State-Space' */
  modello_HITL_SFT_v4_B.Equilibratore_n = 0.0;
  modello_HITL_SFT_v4_B.Equilibratore_n += modello_HITL_SFT_v4_P.StateSpace_C_d *
    modello_HITL_SFT_v4_X.StateSpace_CSTATE_p;

  /* Saturate: '<S3>/Saturation1' */
  b_fmod = -modello_HITL_SFT_v4_P.attuatore_Emax;
  b_s = modello_HITL_SFT_v4_P.attuatore_Emax + 0.1;
  u0 = modello_HITL_SFT_v4_B.Equilibratore_n;
  if (u0 > b_s) {
    /* Saturate: '<S3>/Saturation1' */
    modello_HITL_SFT_v4_B.deltaE_h = b_s;
  } else if (u0 < b_fmod) {
    /* Saturate: '<S3>/Saturation1' */
    modello_HITL_SFT_v4_B.deltaE_h = b_fmod;
  } else {
    /* Saturate: '<S3>/Saturation1' */
    modello_HITL_SFT_v4_B.deltaE_h = u0;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* Switch generated from: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (modello_HITL_SFT_v4_P.Constant_Value_k >
      modello_HITL_SFT_v4_P.Switch_2_Threshold) {
    /* Switch generated from: '<Root>/Switch' */
    modello_HITL_SFT_v4_B.deltaE_k = modello_HITL_SFT_v4_B.deltaE;
  } else {
    /* Switch generated from: '<Root>/Switch' */
    modello_HITL_SFT_v4_B.deltaE_k = modello_HITL_SFT_v4_B.deltaE_h;
  }

  /* Product: '<S60>/Product4' incorporates:
   *  Constant: '<S23>/CL_dE '
   */
  modello_HITL_SFT_v4_B.Product4 = modello_HITL_SFT_v4_P.CLdE *
    modello_HITL_SFT_v4_B.deltaE_k;

  /* Sum: '<S60>/Sum' */
  modello_HITL_SFT_v4_B.Sum_h = (modello_HITL_SFT_v4_B.uDLookupTable_g +
    modello_HITL_SFT_v4_B.y_g1) + modello_HITL_SFT_v4_B.Product4;

  /* Gain: '<S55>/Gain5' */
  modello_HITL_SFT_v4_B.CL = modello_HITL_SFT_v4_P.Gain5_Gain_h *
    modello_HITL_SFT_v4_B.Sum_h;

  /* SignalConversion generated from: '<S28>/Matrix Multiply' */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtMatrixMultiplyInport2[0] =
    modello_HITL_SFT_v4_B.CD;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtMatrixMultiplyInport2[1] =
    modello_HITL_SFT_v4_B.Sum_o;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtMatrixMultiplyInport2[2] =
    modello_HITL_SFT_v4_B.CL;

  /* Product: '<S28>/Matrix Multiply' */
  memcpy(&dcmt[0], &modello_HITL_SFT_v4_B.Lbw[0], 9U * sizeof(real_T));
  Fape[0] = modello_HITL_SFT_v4_B.TmpSignalConversionAtMatrixMultiplyInport2[0];
  Fape[1] = modello_HITL_SFT_v4_B.TmpSignalConversionAtMatrixMultiplyInport2[1];
  Fape[2] = modello_HITL_SFT_v4_B.TmpSignalConversionAtMatrixMultiplyInport2[2];

  /* Product: '<S54>/Product' */
  modello_HITL_SFT_v4_B.Product_j = modello_HITL_SFT_v4_B.Va[0] *
    modello_HITL_SFT_v4_B.Va[0];

  /* Product: '<S54>/Product1' */
  modello_HITL_SFT_v4_B.Product1_i = modello_HITL_SFT_v4_B.Va[1] *
    modello_HITL_SFT_v4_B.Va[1];

  /* Product: '<S54>/Product2' */
  modello_HITL_SFT_v4_B.Product2_k = modello_HITL_SFT_v4_B.Va[2] *
    modello_HITL_SFT_v4_B.Va[2];

  /* Sum: '<S54>/Sum' */
  modello_HITL_SFT_v4_B.Sum_e = (modello_HITL_SFT_v4_B.Product_j +
    modello_HITL_SFT_v4_B.Product1_i) + modello_HITL_SFT_v4_B.Product2_k;
  for (i = 0; i < 3; i++) {
    /* Product: '<S28>/Matrix Multiply' */
    u2 = dcmt[i] * Fape[0];
    u2 += dcmt[i + 3] * Fape[1];
    u2 += dcmt[i + 6] * Fape[2];

    /* Product: '<S28>/Matrix Multiply' */
    modello_HITL_SFT_v4_B.FA_Bq[i] = u2;

    /* Integrator: '<S26>/xe,ye,ze' */
    modello_HITL_SFT_v4_B.xeyeze[i] = modello_HITL_SFT_v4_X.xeyeze_CSTATE[i];
  }

  /* Gain: '<S1>/Gain' */
  modello_HITL_SFT_v4_B.Gain_a = modello_HITL_SFT_v4_P.Gain_Gain_c *
    modello_HITL_SFT_v4_B.xeyeze[2];

  /* Saturate: '<S24>/Limit  altitude  to troposhere' */
  u0 = modello_HITL_SFT_v4_B.Gain_a;
  u1 = modello_HITL_SFT_v4_P.Limitaltitudetotroposhere_LowerSat_c;
  u2 = modello_HITL_SFT_v4_P.Limitaltitudetotroposhere_UpperSat_d;
  if (u0 > u2) {
    /* Saturate: '<S24>/Limit  altitude  to troposhere' */
    modello_HITL_SFT_v4_B.Limitaltitudetotroposhere_n = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S24>/Limit  altitude  to troposhere' */
    modello_HITL_SFT_v4_B.Limitaltitudetotroposhere_n = u1;
  } else {
    /* Saturate: '<S24>/Limit  altitude  to troposhere' */
    modello_HITL_SFT_v4_B.Limitaltitudetotroposhere_n = u0;
  }

  /* End of Saturate: '<S24>/Limit  altitude  to troposhere' */

  /* Gain: '<S24>/Lapse Rate' */
  modello_HITL_SFT_v4_B.LapseRate_f = modello_HITL_SFT_v4_P.LapseRate_Gain_g *
    modello_HITL_SFT_v4_B.Limitaltitudetotroposhere_n;

  /* Sum: '<S24>/Sum1' incorporates:
   *  Constant: '<S24>/Sea Level  Temperature'
   */
  modello_HITL_SFT_v4_B.Sum1_b =
    modello_HITL_SFT_v4_P.SeaLevelTemperature_Value_b -
    modello_HITL_SFT_v4_B.LapseRate_f;

  /* Gain: '<S24>/1//T0' */
  modello_HITL_SFT_v4_B.uT0_m = modello_HITL_SFT_v4_P.uT0_Gain_h *
    modello_HITL_SFT_v4_B.Sum1_b;

  /* Math: '<S24>/(T//T0)^(g//LR) ' incorporates:
   *  Constant: '<S24>/Constant'
   */
  b_fmod = modello_HITL_SFT_v4_B.uT0_m;
  b_s = modello_HITL_SFT_v4_P.Constant_Value_i;
  if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
    /* Math: '<S24>/(T//T0)^(g//LR) ' */
    modello_HITL_SFT_v4_B.TT0gLR_m = -rt_powd_snf(-b_fmod, b_s);
  } else {
    /* Math: '<S24>/(T//T0)^(g//LR) ' */
    modello_HITL_SFT_v4_B.TT0gLR_m = rt_powd_snf(b_fmod, b_s);
  }

  /* End of Math: '<S24>/(T//T0)^(g//LR) ' */

  /* Product: '<S24>/Product' */
  modello_HITL_SFT_v4_B.Product_d = modello_HITL_SFT_v4_B.TT0gLR_m /
    modello_HITL_SFT_v4_B.uT0_m;

  /* Gain: '<S24>/rho0' */
  modello_HITL_SFT_v4_B.rho0 = modello_HITL_SFT_v4_P.rho0_Gain *
    modello_HITL_SFT_v4_B.Product_d;

  /* Sum: '<S24>/Sum' incorporates:
   *  Constant: '<S24>/Altitude of Troposphere'
   */
  modello_HITL_SFT_v4_B.Sum_d =
    modello_HITL_SFT_v4_P.AltitudeofTroposphere_Value_i -
    modello_HITL_SFT_v4_B.Gain_a;

  /* Saturate: '<S24>/Limit  altitude  to Stratosphere' */
  u0 = modello_HITL_SFT_v4_B.Sum_d;
  u1 = modello_HITL_SFT_v4_P.LimitaltitudetoStratosphere_LowerSat_f;
  u2 = modello_HITL_SFT_v4_P.LimitaltitudetoStratosphere_UpperSat_c;
  if (u0 > u2) {
    /* Saturate: '<S24>/Limit  altitude  to Stratosphere' */
    modello_HITL_SFT_v4_B.LimitaltitudetoStratosphere_e = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S24>/Limit  altitude  to Stratosphere' */
    modello_HITL_SFT_v4_B.LimitaltitudetoStratosphere_e = u1;
  } else {
    /* Saturate: '<S24>/Limit  altitude  to Stratosphere' */
    modello_HITL_SFT_v4_B.LimitaltitudetoStratosphere_e = u0;
  }

  /* End of Saturate: '<S24>/Limit  altitude  to Stratosphere' */

  /* Gain: '<S24>/g//R' */
  modello_HITL_SFT_v4_B.gR_a = modello_HITL_SFT_v4_P.gR_Gain_c *
    modello_HITL_SFT_v4_B.LimitaltitudetoStratosphere_e;

  /* Product: '<S24>/Product1' */
  modello_HITL_SFT_v4_B.Product1_j = 1.0 / modello_HITL_SFT_v4_B.Sum1_b *
    modello_HITL_SFT_v4_B.gR_a;

  /* Math: '<S24>/Stratosphere Model'
   *
   * About '<S24>/Stratosphere Model':
   *  Operator: exp
   */
  modello_HITL_SFT_v4_B.StratosphereModel_e = exp
    (modello_HITL_SFT_v4_B.Product1_j);

  /* Product: '<S24>/Product3' */
  modello_HITL_SFT_v4_B.Product3_c = modello_HITL_SFT_v4_B.rho0 *
    modello_HITL_SFT_v4_B.StratosphereModel_e;

  /* Product: '<S27>/Product2' */
  modello_HITL_SFT_v4_B.Product2_c = modello_HITL_SFT_v4_B.Sum_e *
    modello_HITL_SFT_v4_B.Product3_c;

  /* Gain: '<S27>/1//2rhoV^2' */
  modello_HITL_SFT_v4_B.u2rhoV2 = modello_HITL_SFT_v4_P.u2rhoV2_Gain *
    modello_HITL_SFT_v4_B.Product2_c;

  /* Product: '<S28>/Product' incorporates:
   *  Constant: '<S23>/S'
   */
  modello_HITL_SFT_v4_B.Product_jt[0] = modello_HITL_SFT_v4_P.S *
    modello_HITL_SFT_v4_B.FA_Bq[0] * modello_HITL_SFT_v4_B.u2rhoV2;
  modello_HITL_SFT_v4_B.Product_jt[1] = modello_HITL_SFT_v4_P.S *
    modello_HITL_SFT_v4_B.FA_Bq[1] * modello_HITL_SFT_v4_B.u2rhoV2;
  modello_HITL_SFT_v4_B.Product_jt[2] = modello_HITL_SFT_v4_P.S *
    modello_HITL_SFT_v4_B.FA_Bq[2] * modello_HITL_SFT_v4_B.u2rhoV2;

  /* Lookup_n-D: '<S64>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  modello_HITL_SFT_v4_B.uDLookupTable_h = look2_binlxpw(modello_HITL_SFT_v4_B.u,
    modello_HITL_SFT_v4_B.u_n, modello_HITL_SFT_v4_P.alphavec_rad,
    modello_HITL_SFT_v4_P.betavec_rad,
    modello_HITL_SFT_v4_P.uDLookupTable_tableData_n,
    modello_HITL_SFT_v4_P.uDLookupTable_maxIndex_cp, 13U);

  /* Gain: '<S64>/Gain4' */
  modello_HITL_SFT_v4_B.Gain4_p = modello_HITL_SFT_v4_P.Gain4_Gain_d *
    modello_HITL_SFT_v4_B.uDLookupTable_h;

  /* SignalConversion generated from: '<S67>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S64>/controllo divisione per zero lp '
   */
  b_fmod = modello_HITL_SFT_v4_P.b / 2.0;

  /* SignalConversion generated from: '<S67>/ SFunction ' incorporates:
   *  Constant: '<S23>/Cl_p '
   *  MATLAB Function: '<S64>/controllo divisione per zero lp '
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[0] =
    modello_HITL_SFT_v4_P.Clp;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[1] =
    modello_HITL_SFT_v4_B.pqr[0];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[2] = b_fmod;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[3] =
    modello_HITL_SFT_v4_B.module;

  /* MATLAB Function: '<S64>/controllo divisione per zero lp ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem3/controllo divisione per zero lp ': '<S67>:1' */
  if (modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[3] == 0.0)
  {
    /* '<S67>:1:6' */
    /* '<S67>:1:7' */
    modello_HITL_SFT_v4_B.y_k = 0.0;
  } else {
    /* '<S67>:1:9' */
    modello_HITL_SFT_v4_B.y_k =
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[0] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[1] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[2] /
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[3];
  }

  /* SignalConversion generated from: '<S68>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S64>/controllo divisione per zero lr '
   */
  b_fmod = modello_HITL_SFT_v4_P.b / 2.0;

  /* SignalConversion generated from: '<S68>/ SFunction ' incorporates:
   *  Constant: '<S23>/Cl_r '
   *  MATLAB Function: '<S64>/controllo divisione per zero lr '
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[0] =
    modello_HITL_SFT_v4_P.Clr;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[1] = b_fmod;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[2] =
    modello_HITL_SFT_v4_B.pqr[2];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[3] =
    modello_HITL_SFT_v4_B.module;

  /* MATLAB Function: '<S64>/controllo divisione per zero lr ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem3/controllo divisione per zero lr ': '<S68>:1' */
  if (modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[3] == 0.0) {
    /* '<S68>:1:6' */
    /* '<S68>:1:7' */
    modello_HITL_SFT_v4_B.y_o = 0.0;
  } else {
    /* '<S68>:1:9' */
    modello_HITL_SFT_v4_B.y_o =
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[0] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[1] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[2] /
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[3];
  }

  /* Product: '<S64>/Product2' incorporates:
   *  Constant: '<S23>/Cl_dA'
   */
  modello_HITL_SFT_v4_B.Product2_d = modello_HITL_SFT_v4_P.CldA *
    modello_HITL_SFT_v4_B.deltaA_gw;

  /* Product: '<S64>/Product3' incorporates:
   *  Constant: '<S23>/Cl_dR'
   */
  modello_HITL_SFT_v4_B.Product3_f = modello_HITL_SFT_v4_P.CldR *
    modello_HITL_SFT_v4_B.deltaR_d;

  /* Sum: '<S64>/Sum' */
  modello_HITL_SFT_v4_B.Sum_p = (((modello_HITL_SFT_v4_B.Gain4_p +
    modello_HITL_SFT_v4_B.y_k) + modello_HITL_SFT_v4_B.y_o) +
    modello_HITL_SFT_v4_B.Product2_d) + modello_HITL_SFT_v4_B.Product3_f;

  /* Product: '<S57>/Product' incorporates:
   *  Constant: '<S23>/S*b '
   */
  b_fmod = modello_HITL_SFT_v4_P.S * modello_HITL_SFT_v4_P.b;

  /* Product: '<S57>/Product' */
  modello_HITL_SFT_v4_B.Cl = b_fmod * modello_HITL_SFT_v4_B.Sum_p;

  /* Lookup_n-D: '<S65>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  modello_HITL_SFT_v4_B.uDLookupTable_d = look2_binlxpw(modello_HITL_SFT_v4_B.u,
    modello_HITL_SFT_v4_B.u_n, modello_HITL_SFT_v4_P.alphavec_rad,
    modello_HITL_SFT_v4_P.betavec_rad,
    modello_HITL_SFT_v4_P.uDLookupTable_tableData_k,
    modello_HITL_SFT_v4_P.uDLookupTable_maxIndex_h, 13U);

  /* Gain: '<S65>/Gain1' */
  modello_HITL_SFT_v4_B.Gain1_h = modello_HITL_SFT_v4_P.Gain1_Gain_l *
    modello_HITL_SFT_v4_B.module;

  /* SignalConversion generated from: '<S69>/ SFunction ' incorporates:
   *  Constant: '<S23>/Cm_q '
   *  Constant: '<S23>/cbar '
   *  MATLAB Function: '<S65>/controllo divisione per zero mq '
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[0] =
    modello_HITL_SFT_v4_P.Cmq;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[1] =
    modello_HITL_SFT_v4_B.pqr[1];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[2] =
    modello_HITL_SFT_v4_P.cbar;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[3] =
    modello_HITL_SFT_v4_B.Gain1_h;

  /* MATLAB Function: '<S65>/controllo divisione per zero mq ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem4/controllo divisione per zero mq ': '<S69>:1' */
  if (modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[3] == 0.0) {
    /* '<S69>:1:6' */
    /* '<S69>:1:7' */
    modello_HITL_SFT_v4_B.y_g = 0.0;
  } else {
    /* '<S69>:1:9' */
    modello_HITL_SFT_v4_B.y_g =
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[0] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[1] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[2] /
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[3];
  }

  /* Product: '<S65>/Product2' incorporates:
   *  Constant: '<S23>/Cm_dE '
   */
  modello_HITL_SFT_v4_B.Product2_kw = modello_HITL_SFT_v4_P.CmdE *
    modello_HITL_SFT_v4_B.deltaE_k;

  /* Sum: '<S65>/Sum' */
  modello_HITL_SFT_v4_B.Sum_g = (modello_HITL_SFT_v4_B.uDLookupTable_d +
    modello_HITL_SFT_v4_B.y_g) + modello_HITL_SFT_v4_B.Product2_kw;

  /* Product: '<S57>/Product1' incorporates:
   *  Constant: '<S23>/S*cbar'
   */
  b_fmod = modello_HITL_SFT_v4_P.S * modello_HITL_SFT_v4_P.cbar;

  /* Product: '<S57>/Product1' */
  modello_HITL_SFT_v4_B.Cm = b_fmod * modello_HITL_SFT_v4_B.Sum_g;

  /* Lookup_n-D: '<S66>/2-D Lookup Table' incorporates:
   *  Trigonometry: '<S34>/Trigonometric Function1'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  modello_HITL_SFT_v4_B.uDLookupTable_l = look2_binlxpw(modello_HITL_SFT_v4_B.u,
    modello_HITL_SFT_v4_B.u_n, modello_HITL_SFT_v4_P.alphavec_rad,
    modello_HITL_SFT_v4_P.betavec_rad,
    modello_HITL_SFT_v4_P.uDLookupTable_tableData_kg,
    modello_HITL_SFT_v4_P.uDLookupTable_maxIndex_j, 13U);

  /* SignalConversion generated from: '<S70>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S66>/controllo divisione per zero np '
   */
  b_fmod = modello_HITL_SFT_v4_P.b / 2.0;

  /* SignalConversion generated from: '<S70>/ SFunction ' incorporates:
   *  Constant: '<S23>/Cn_p '
   *  MATLAB Function: '<S66>/controllo divisione per zero np '
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[0] =
    modello_HITL_SFT_v4_P.Cnp;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[1] =
    modello_HITL_SFT_v4_B.pqr[0];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[2] = b_fmod;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[3] =
    modello_HITL_SFT_v4_B.module;

  /* MATLAB Function: '<S66>/controllo divisione per zero np ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem5/controllo divisione per zero np ': '<S70>:1' */
  if (modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[3] == 0.0) {
    /* '<S70>:1:6' */
    /* '<S70>:1:7' */
    modello_HITL_SFT_v4_B.y_l = 0.0;
  } else {
    /* '<S70>:1:9' */
    modello_HITL_SFT_v4_B.y_l =
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[0] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[1] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[2] /
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[3];
  }

  /* SignalConversion generated from: '<S71>/ SFunction ' incorporates:
   *  Constant: '<S23>/b//2'
   *  MATLAB Function: '<S66>/controllo divisione per zero nr '
   */
  b_fmod = modello_HITL_SFT_v4_P.b / 2.0;

  /* SignalConversion generated from: '<S71>/ SFunction ' incorporates:
   *  Constant: '<S23>/Cn_r '
   *  MATLAB Function: '<S66>/controllo divisione per zero nr '
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[0] =
    modello_HITL_SFT_v4_P.Cnr;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[1] =
    modello_HITL_SFT_v4_B.pqr[2];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[2] = b_fmod;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[3] =
    modello_HITL_SFT_v4_B.module;

  /* MATLAB Function: '<S66>/controllo divisione per zero nr ' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/Forze aerodinamiche/Momenti //press din/Subsystem5/controllo divisione per zero nr ': '<S71>:1' */
  if (modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[3] == 0.0) {
    /* '<S71>:1:6' */
    /* '<S71>:1:7' */
    modello_HITL_SFT_v4_B.y_c = 0.0;
  } else {
    /* '<S71>:1:9' */
    modello_HITL_SFT_v4_B.y_c =
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[0] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[1] *
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[2] /
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[3];
  }

  /* Product: '<S66>/Product2' incorporates:
   *  Constant: '<S23>/Cn_dA'
   */
  modello_HITL_SFT_v4_B.Product2_m = modello_HITL_SFT_v4_P.CndA *
    modello_HITL_SFT_v4_B.deltaA_gw;

  /* Product: '<S66>/Product3' incorporates:
   *  Constant: '<S23>/Cn_dR '
   */
  modello_HITL_SFT_v4_B.Product3_fd = modello_HITL_SFT_v4_P.CndR *
    modello_HITL_SFT_v4_B.deltaR_d;

  /* Sum: '<S66>/Sum' */
  modello_HITL_SFT_v4_B.Sum_lc = (((modello_HITL_SFT_v4_B.uDLookupTable_l +
    modello_HITL_SFT_v4_B.y_l) + modello_HITL_SFT_v4_B.y_c) +
    modello_HITL_SFT_v4_B.Product2_m) + modello_HITL_SFT_v4_B.Product3_fd;

  /* Product: '<S57>/Product3' incorporates:
   *  Constant: '<S23>/S*b '
   */
  b_fmod = modello_HITL_SFT_v4_P.S * modello_HITL_SFT_v4_P.b;

  /* Product: '<S57>/Product3' */
  modello_HITL_SFT_v4_B.Cn = b_fmod * modello_HITL_SFT_v4_B.Sum_lc;

  /* Product: '<S28>/Product2' */
  modello_HITL_SFT_v4_B.Product2_f[0] = modello_HITL_SFT_v4_B.u2rhoV2 *
    modello_HITL_SFT_v4_B.Cl;
  modello_HITL_SFT_v4_B.Product2_f[1] = modello_HITL_SFT_v4_B.u2rhoV2 *
    modello_HITL_SFT_v4_B.Cm;
  modello_HITL_SFT_v4_B.Product2_f[2] = modello_HITL_SFT_v4_B.u2rhoV2 *
    modello_HITL_SFT_v4_B.Cn;

  /* Product: '<S35>/Product3' incorporates:
   *  Constant: '<S23>/W'
   *  Reshape: '<S46>/Reshape (9) to [3x3] column-major'
   */
  memcpy(&dcmt[0], &modello_HITL_SFT_v4_B.Reshape9to3x3columnmajor[0], 9U *
         sizeof(real_T));
  Fape[0] = modello_HITL_SFT_v4_P.W[0];
  Fape[1] = modello_HITL_SFT_v4_P.W[1];
  Fape[2] = modello_HITL_SFT_v4_P.W[2];
  for (i = 0; i < 3; i++) {
    u2 = dcmt[i] * Fape[0];
    u2 += dcmt[i + 3] * Fape[1];
    u2 += dcmt[i + 6] * Fape[2];

    /* Product: '<S35>/Product3' */
    modello_HITL_SFT_v4_B.Product3_j[i] = u2;
  }

  /* End of Product: '<S35>/Product3' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitDelay: '<S31>/Unit Delay' */
    modello_HITL_SFT_v4_B.UnitDelay = modello_HITL_SFT_v4_DW.UnitDelay_DSTATE;

    /* Gain: '<S31>/RPM->RPs' */
    modello_HITL_SFT_v4_B.RPMRPs = modello_HITL_SFT_v4_P.RPMRPs_Gain *
      modello_HITL_SFT_v4_B.UnitDelay;

    /* Math: '<S31>/Math Function3' incorporates:
     *  Constant: '<S31>/Constant'
     */
    b_fmod = modello_HITL_SFT_v4_B.RPMRPs;
    b_s = modello_HITL_SFT_v4_P.Constant_Value_p;
    if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
      /* Math: '<S31>/Math Function3' */
      modello_HITL_SFT_v4_B.MathFunction3 = -rt_powd_snf(-b_fmod, b_s);
    } else {
      /* Math: '<S31>/Math Function3' */
      modello_HITL_SFT_v4_B.MathFunction3 = rt_powd_snf(b_fmod, b_s);
    }

    /* End of Math: '<S31>/Math Function3' */

    /* Math: '<S31>/Math Function' incorporates:
     *  Constant: '<S23>/Dprop'
     *  Constant: '<S31>/Constant1'
     */
    b_fmod = modello_HITL_SFT_v4_P.Dprop;
    b_s = modello_HITL_SFT_v4_P.Constant1_Value;
    if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
      /* Math: '<S31>/Math Function' */
      modello_HITL_SFT_v4_B.MathFunction_g = -rt_powd_snf(-b_fmod, b_s);
    } else {
      /* Math: '<S31>/Math Function' */
      modello_HITL_SFT_v4_B.MathFunction_g = rt_powd_snf(b_fmod, b_s);
    }

    /* End of Math: '<S31>/Math Function' */
  }

  /* Product: '<S31>/Product1' incorporates:
   *  Constant: '<S23>/Dprop'
   */
  modello_HITL_SFT_v4_B.Product1_d = 1.0 / modello_HITL_SFT_v4_B.RPMRPs *
    modello_HITL_SFT_v4_B.module / modello_HITL_SFT_v4_P.Dprop;

  /* Lookup_n-D: '<S75>/2-D Lookup Table' incorporates:
   *  Product: '<S31>/Product1'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  modello_HITL_SFT_v4_B.uDLookupTable_et = look2_binlxpw
    (modello_HITL_SFT_v4_B.Product1_d, modello_HITL_SFT_v4_B.UnitDelay,
     modello_HITL_SFT_v4_P.J_vec, modello_HITL_SFT_v4_P.uDLookupTable_bp02Data,
     modello_HITL_SFT_v4_P.uDLookupTable_tableData_od,
     modello_HITL_SFT_v4_P.uDLookupTable_maxIndex_p, 30U);

  /* Product: '<S31>/Product2' */
  modello_HITL_SFT_v4_B.Product2_h = modello_HITL_SFT_v4_B.MathFunction3 *
    modello_HITL_SFT_v4_B.MathFunction_g * modello_HITL_SFT_v4_B.Product3_c *
    modello_HITL_SFT_v4_B.uDLookupTable_et;

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S76>/Constant'
   */
  modello_HITL_SFT_v4_B.F[0] = (modello_HITL_SFT_v4_B.Product3_j[0] +
    modello_HITL_SFT_v4_B.Product_jt[0]) + modello_HITL_SFT_v4_B.Product2_h;
  modello_HITL_SFT_v4_B.F[1] = (modello_HITL_SFT_v4_B.Product3_j[1] +
    modello_HITL_SFT_v4_B.Product_jt[1]) +
    modello_HITL_SFT_v4_P.Constant_Value_e;
  modello_HITL_SFT_v4_B.F[2] = (modello_HITL_SFT_v4_B.Product3_j[2] +
    modello_HITL_SFT_v4_B.Product_jt[2]) +
    modello_HITL_SFT_v4_P.Constant_Value_e;
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Concatenate: '<S38>/Vector Concatenate' incorporates:
       *  Constant: '<S38>/Constant1'
       *  Constant: '<S38>/Constant2'
       */
      modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i] =
        modello_HITL_SFT_v4_P.I[3 * i];
      modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 3] =
        modello_HITL_SFT_v4_P.Constant2_Value_f[3 * i];

      /* Selector: '<S37>/Selector' incorporates:
       *  Concatenate: '<S38>/Vector Concatenate'
       */
      modello_HITL_SFT_v4_B.Selector[3 * i] =
        modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i];

      /* Concatenate: '<S38>/Vector Concatenate' incorporates:
       *  Constant: '<S38>/Constant1'
       *  Constant: '<S38>/Constant2'
       */
      modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 1] =
        modello_HITL_SFT_v4_P.I[3 * i + 1];
      modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 4] =
        modello_HITL_SFT_v4_P.Constant2_Value_f[3 * i + 1];

      /* Selector: '<S37>/Selector' incorporates:
       *  Concatenate: '<S38>/Vector Concatenate'
       */
      modello_HITL_SFT_v4_B.Selector[3 * i + 1] =
        modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 1];

      /* Concatenate: '<S38>/Vector Concatenate' incorporates:
       *  Constant: '<S38>/Constant1'
       *  Constant: '<S38>/Constant2'
       */
      modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 2] =
        modello_HITL_SFT_v4_P.I[3 * i + 2];
      modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 5] =
        modello_HITL_SFT_v4_P.Constant2_Value_f[3 * i + 2];

      /* Selector: '<S37>/Selector' incorporates:
       *  Concatenate: '<S38>/Vector Concatenate'
       */
      modello_HITL_SFT_v4_B.Selector[3 * i + 2] =
        modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 2];
    }
  }

  /* Trigonometry: '<S45>/sincos' */
  b_s = modello_HITL_SFT_v4_B.phithetapsi[0];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  modello_HITL_SFT_v4_B.sincos_o1_p[0] = b_fmod;
  modello_HITL_SFT_v4_B.sincos_o2_m[0] = b_s;
  b_s = modello_HITL_SFT_v4_B.phithetapsi[1];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  modello_HITL_SFT_v4_B.sincos_o1_p[1] = b_fmod;
  modello_HITL_SFT_v4_B.sincos_o2_m[1] = b_s;
  b_s = modello_HITL_SFT_v4_B.phithetapsi[2];
  b_fmod = sin(b_s);
  b_s = cos(b_s);
  modello_HITL_SFT_v4_B.sincos_o1_p[2] = b_fmod;
  modello_HITL_SFT_v4_B.sincos_o2_m[2] = b_s;

  /* Fcn: '<S45>/phidot' */
  modello_HITL_SFT_v4_B.phidot = (modello_HITL_SFT_v4_B.pqr[1] *
    modello_HITL_SFT_v4_B.sincos_o1_p[0] + modello_HITL_SFT_v4_B.pqr[2] *
    modello_HITL_SFT_v4_B.sincos_o2_m[0]) * (modello_HITL_SFT_v4_B.sincos_o1_p[1]
    / modello_HITL_SFT_v4_B.sincos_o2_m[1]) + modello_HITL_SFT_v4_B.pqr[0];

  /* Fcn: '<S45>/thetadot' */
  modello_HITL_SFT_v4_B.thetadot = modello_HITL_SFT_v4_B.pqr[1] *
    modello_HITL_SFT_v4_B.sincos_o2_m[0] - modello_HITL_SFT_v4_B.pqr[2] *
    modello_HITL_SFT_v4_B.sincos_o1_p[0];

  /* Fcn: '<S45>/psidot' */
  modello_HITL_SFT_v4_B.psidot = (modello_HITL_SFT_v4_B.pqr[1] *
    modello_HITL_SFT_v4_B.sincos_o1_p[0] + modello_HITL_SFT_v4_B.pqr[2] *
    modello_HITL_SFT_v4_B.sincos_o2_m[0]) / modello_HITL_SFT_v4_B.sincos_o2_m[1];

  /* SignalConversion generated from: '<S36>/phi theta psi' */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtphithetapsiInport1[0] =
    modello_HITL_SFT_v4_B.phidot;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtphithetapsiInport1[1] =
    modello_HITL_SFT_v4_B.thetadot;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtphithetapsiInport1[2] =
    modello_HITL_SFT_v4_B.psidot;

  /* Reshape: '<S48>/Reshape1' */
  modello_HITL_SFT_v4_B.Reshape1_k[0] = modello_HITL_SFT_v4_B.pqr[0];
  modello_HITL_SFT_v4_B.Reshape1_k[1] = modello_HITL_SFT_v4_B.pqr[1];
  modello_HITL_SFT_v4_B.Reshape1_k[2] = modello_HITL_SFT_v4_B.pqr[2];

  /* Product: '<S48>/Product' incorporates:
   *  Reshape: '<S48>/Reshape1'
   *  Selector: '<S37>/Selector'
   */
  memcpy(&dcmt[0], &modello_HITL_SFT_v4_B.Selector[0], 9U * sizeof(real_T));
  Fape[0] = modello_HITL_SFT_v4_B.Reshape1_k[0];
  Fape[1] = modello_HITL_SFT_v4_B.Reshape1_k[1];
  Fape[2] = modello_HITL_SFT_v4_B.Reshape1_k[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S48>/Product' */
    modello_HITL_SFT_v4_B.Product_l[i] = 0.0;
    modello_HITL_SFT_v4_B.Product_l[i] += dcmt[i] * Fape[0];
    modello_HITL_SFT_v4_B.Product_l[i] += dcmt[i + 3] * Fape[1];
    modello_HITL_SFT_v4_B.Product_l[i] += dcmt[i + 6] * Fape[2];

    /* Reshape: '<S48>/Reshape2' incorporates:
     *  Product: '<S48>/Product'
     */
    modello_HITL_SFT_v4_B.Reshape2_d[i] = modello_HITL_SFT_v4_B.Product_l[i];
  }

  /* Product: '<S50>/i x j' */
  modello_HITL_SFT_v4_B.ixj = modello_HITL_SFT_v4_B.pqr[0] *
    modello_HITL_SFT_v4_B.Reshape2_d[1];

  /* Product: '<S50>/j x k' */
  modello_HITL_SFT_v4_B.jxk = modello_HITL_SFT_v4_B.pqr[1] *
    modello_HITL_SFT_v4_B.Reshape2_d[2];

  /* Product: '<S50>/k x i' */
  modello_HITL_SFT_v4_B.kxi = modello_HITL_SFT_v4_B.pqr[2] *
    modello_HITL_SFT_v4_B.Reshape2_d[0];

  /* Product: '<S51>/i x k' */
  modello_HITL_SFT_v4_B.ixk = modello_HITL_SFT_v4_B.pqr[0] *
    modello_HITL_SFT_v4_B.Reshape2_d[2];

  /* Product: '<S51>/j x i' */
  modello_HITL_SFT_v4_B.jxi = modello_HITL_SFT_v4_B.pqr[1] *
    modello_HITL_SFT_v4_B.Reshape2_d[0];

  /* Product: '<S51>/k x j' */
  modello_HITL_SFT_v4_B.kxj = modello_HITL_SFT_v4_B.pqr[2] *
    modello_HITL_SFT_v4_B.Reshape2_d[1];

  /* Sum: '<S47>/Sum' */
  modello_HITL_SFT_v4_B.Sum_n[0] = modello_HITL_SFT_v4_B.jxk -
    modello_HITL_SFT_v4_B.kxj;
  modello_HITL_SFT_v4_B.Sum_n[1] = modello_HITL_SFT_v4_B.kxi -
    modello_HITL_SFT_v4_B.ixk;
  modello_HITL_SFT_v4_B.Sum_n[2] = modello_HITL_SFT_v4_B.ixj -
    modello_HITL_SFT_v4_B.jxi;
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Selector: '<S37>/Selector1' incorporates:
       *  Concatenate: '<S38>/Vector Concatenate'
       */
      modello_HITL_SFT_v4_B.Selector1[3 * i] =
        modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 3];
      modello_HITL_SFT_v4_B.Selector1[3 * i + 1] =
        modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 4];
      modello_HITL_SFT_v4_B.Selector1[3 * i + 2] =
        modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 5];
    }
  }

  /* Reshape: '<S49>/Reshape1' */
  modello_HITL_SFT_v4_B.Reshape1_d[0] = modello_HITL_SFT_v4_B.pqr[0];
  modello_HITL_SFT_v4_B.Reshape1_d[1] = modello_HITL_SFT_v4_B.pqr[1];
  modello_HITL_SFT_v4_B.Reshape1_d[2] = modello_HITL_SFT_v4_B.pqr[2];

  /* Product: '<S49>/Product' incorporates:
   *  Reshape: '<S49>/Reshape1'
   *  Selector: '<S37>/Selector1'
   */
  memcpy(&dcmt[0], &modello_HITL_SFT_v4_B.Selector1[0], 9U * sizeof(real_T));
  Fape[0] = modello_HITL_SFT_v4_B.Reshape1_d[0];
  Fape[1] = modello_HITL_SFT_v4_B.Reshape1_d[1];
  Fape[2] = modello_HITL_SFT_v4_B.Reshape1_d[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S49>/Product' */
    modello_HITL_SFT_v4_B.Product_jg[i] = 0.0;
    modello_HITL_SFT_v4_B.Product_jg[i] += dcmt[i] * Fape[0];
    modello_HITL_SFT_v4_B.Product_jg[i] += dcmt[i + 3] * Fape[1];
    modello_HITL_SFT_v4_B.Product_jg[i] += dcmt[i + 6] * Fape[2];

    /* Reshape: '<S49>/Reshape2' incorporates:
     *  Product: '<S49>/Product'
     */
    modello_HITL_SFT_v4_B.Reshape2_o[i] = modello_HITL_SFT_v4_B.Product_jg[i];
  }

  /* Lookup_n-D: '<S75>/2-D Lookup Table1' incorporates:
   *  Product: '<S31>/Product1'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  modello_HITL_SFT_v4_B.uDLookupTable1 = look2_binlxpw
    (modello_HITL_SFT_v4_B.Product1_d, modello_HITL_SFT_v4_B.UnitDelay,
     modello_HITL_SFT_v4_P.J_vec, modello_HITL_SFT_v4_P.uDLookupTable1_bp02Data,
     modello_HITL_SFT_v4_P.uDLookupTable1_tableData,
     modello_HITL_SFT_v4_P.uDLookupTable1_maxIndex, 30U);
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S31>/Math Function2' incorporates:
     *  Constant: '<S23>/Dprop'
     *  Constant: '<S31>/Constant3'
     */
    b_fmod = modello_HITL_SFT_v4_P.Dprop;
    b_s = modello_HITL_SFT_v4_P.Constant3_Value_l;
    if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
      /* Math: '<S31>/Math Function2' */
      modello_HITL_SFT_v4_B.MathFunction2 = -rt_powd_snf(-b_fmod, b_s);
    } else {
      /* Math: '<S31>/Math Function2' */
      modello_HITL_SFT_v4_B.MathFunction2 = rt_powd_snf(b_fmod, b_s);
    }

    /* End of Math: '<S31>/Math Function2' */

    /* Math: '<S31>/Math Function1' incorporates:
     *  Constant: '<S31>/Constant2'
     */
    b_fmod = modello_HITL_SFT_v4_B.RPMRPs;
    b_s = modello_HITL_SFT_v4_P.Constant2_Value_j;
    if ((b_fmod < 0.0) && (b_s > floor(b_s))) {
      /* Math: '<S31>/Math Function1' */
      modello_HITL_SFT_v4_B.MathFunction1_h = -rt_powd_snf(-b_fmod, b_s);
    } else {
      /* Math: '<S31>/Math Function1' */
      modello_HITL_SFT_v4_B.MathFunction1_h = rt_powd_snf(b_fmod, b_s);
    }

    /* End of Math: '<S31>/Math Function1' */

    /* Gain: '<S76>/Gain' */
    modello_HITL_SFT_v4_B.Gain_a3 = modello_HITL_SFT_v4_P.Gain_Gain_ai *
      modello_HITL_SFT_v4_B.RPMRPs;
  }

  /* Product: '<S31>/Product3' */
  modello_HITL_SFT_v4_B.Product3_o = modello_HITL_SFT_v4_B.uDLookupTable1 *
    modello_HITL_SFT_v4_B.Product3_c * modello_HITL_SFT_v4_B.MathFunction2 *
    modello_HITL_SFT_v4_B.MathFunction1_h;

  /* Product: '<S76>/Divide' */
  modello_HITL_SFT_v4_B.Divide_e = modello_HITL_SFT_v4_B.Product3_o /
    modello_HITL_SFT_v4_B.Gain_a3;

  /* Gain: '<S76>/Gain1' */
  modello_HITL_SFT_v4_B.Gain1_b = modello_HITL_SFT_v4_P.Gain1_Gain_d *
    modello_HITL_SFT_v4_B.Divide_e;

  /* Product: '<S76>/Divide1' incorporates:
   *  Constant: '<S23>/Zeng'
   */
  modello_HITL_SFT_v4_B.Divide1 = modello_HITL_SFT_v4_P.Zeng *
    modello_HITL_SFT_v4_B.Product2_h;

  /* Sum: '<S22>/Sum1' incorporates:
   *  Constant: '<S76>/Constant1'
   */
  modello_HITL_SFT_v4_B.Sum1_n[0] = modello_HITL_SFT_v4_B.Gain1_b +
    modello_HITL_SFT_v4_B.Product2_f[0];
  modello_HITL_SFT_v4_B.Sum1_n[1] = modello_HITL_SFT_v4_B.Divide1 +
    modello_HITL_SFT_v4_B.Product2_f[1];
  modello_HITL_SFT_v4_B.Sum1_n[2] = modello_HITL_SFT_v4_P.Constant1_Value_o +
    modello_HITL_SFT_v4_B.Product2_f[2];
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator_p =
      modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_i;

    /* Switch: '<S19>/Switch' */
    if (modello_HITL_SFT_v4_B.DiscreteTimeIntegrator_p >
        modello_HITL_SFT_v4_P.Switch_Threshold_a) {
      /* Switch: '<S19>/Switch' */
      modello_HITL_SFT_v4_B.Switch_g = modello_HITL_SFT_v4_B.h_ground;
    } else {
      /* Switch: '<S19>/Switch' incorporates:
       *  Constant: '<S19>/Constant3'
       */
      modello_HITL_SFT_v4_B.Switch_g = modello_HITL_SFT_v4_P.Constant3_Value_f;
    }

    /* End of Switch: '<S19>/Switch' */
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
  tmp_f = cos(modello_HITL_SFT_v4_B.phithetapsi[2]);
  u2 = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
  u0 = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
  diffLm = sin(modello_HITL_SFT_v4_B.phithetapsi[2]);
  Fss = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  Frms = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  b_s = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  b_fmod = cos(modello_HITL_SFT_v4_B.phithetapsi[2]);
  Mye = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  u1 = sin(modello_HITL_SFT_v4_B.phithetapsi[2]);
  Fsd = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  Frmd = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  tmp_g = sin(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_0 = cos(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp_1 = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_2 = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
  tmp_3 = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_4 = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  tmp_5 = cos(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp_6 = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_7 = sin(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp_8 = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_9 = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  tmp_a = sin(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp_b = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_c = cos(modello_HITL_SFT_v4_B.phithetapsi[2]);
  tmp_d = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  tmp_e = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
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
    tmp_f = dcmt[i] * modello_HITL_SFT_v4_P.rngG[0];
    tmp_f += dcmt[i + 3] * modello_HITL_SFT_v4_P.rngG[1];
    tmp_f += dcmt[i + 6] * modello_HITL_SFT_v4_P.rngG[2];
    Fape[i] = tmp_f + modello_HITL_SFT_v4_B.xeyeze[i];
  }

  b_fmod = Fape[2] - modello_HITL_SFT_v4_B.Switch_g;
  if (!(b_fmod > 0.0)) {
    /* '<S72>:1:29' */
    b_fmod = 0.0;
  } else {
    /* '<S72>:1:27' */
    /* '<S72>:1:28' */
  }

  /* '<S72>:1:31' */
  for (i = 0; i < 3; i++) {
    tmp_f = dcmt[i] * modello_HITL_SFT_v4_P.rmgrG[0];
    tmp_f += dcmt[i + 3] * modello_HITL_SFT_v4_P.rmgrG[1];
    tmp_f += dcmt[i + 6] * modello_HITL_SFT_v4_P.rmgrG[2];
    Fape[i] = tmp_f + modello_HITL_SFT_v4_B.xeyeze[i];
  }

  b_s = Fape[2] - modello_HITL_SFT_v4_B.Switch_g;
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
    tmp_f = dcmt[i] * modello_HITL_SFT_v4_P.rmglG[0];
    tmp_f += dcmt[i + 3] * modello_HITL_SFT_v4_P.rmglG[1];
    tmp_f += dcmt[i + 6] * modello_HITL_SFT_v4_P.rmglG[2];
    Fape[i] = tmp_f + modello_HITL_SFT_v4_B.xeyeze[i];
  }

  diffLm = Fape[2] - modello_HITL_SFT_v4_B.Switch_g;
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
    Fss = modello_HITL_SFT_v4_P.kng_Value * b_fmod;
  } else {
    /* '<S72>:1:43' */
    Fss = 1.0 / (0.02 - b_fmod) * 0.0837 + modello_HITL_SFT_v4_P.kng_Value *
      b_fmod;
  }

  if (Mye <= 0.007) {
    /* '<S72>:1:45' */
    /* '<S72>:1:46' */
    Frms = modello_HITL_SFT_v4_P.kmg_Value * Mye;
  } else {
    /* '<S72>:1:47' */
    Frms = 1.0 / (0.02 - Mye) * 0.0912 + modello_HITL_SFT_v4_P.kmg_Value * Mye;
  }

  if (diffLm <= 0.007) {
    /* '<S72>:1:49' */
    /* '<S72>:1:50' */
    u1 = modello_HITL_SFT_v4_P.kmg_Value * diffLm;
  } else {
    /* '<S72>:1:51' */
    u1 = 1.0 / (0.02 - diffLm) * 0.0912 + modello_HITL_SFT_v4_P.kmg_Value *
      diffLm;
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
    tmp_f = modello_HITL_SFT_v4_B.pqr[1] * modello_HITL_SFT_v4_P.rngG[2] -
      modello_HITL_SFT_v4_B.pqr[2] * modello_HITL_SFT_v4_P.rngG[1];
    u2 = modello_HITL_SFT_v4_B.pqr[2] * modello_HITL_SFT_v4_P.rngG[0] -
      modello_HITL_SFT_v4_B.pqr[0] * modello_HITL_SFT_v4_P.rngG[2];
    u0 = modello_HITL_SFT_v4_B.pqr[0] * modello_HITL_SFT_v4_P.rngG[1] -
      modello_HITL_SFT_v4_B.pqr[1] * modello_HITL_SFT_v4_P.rngG[0];
    tmp_f += modello_HITL_SFT_v4_B.UnitConversion[0];
    u2 += modello_HITL_SFT_v4_B.UnitConversion[1];
    tmp_g = modello_HITL_SFT_v4_B.UnitConversion[2] + u0;
    for (i = 0; i < 3; i++) {
      u0 = dcmt[i] * tmp_f;
      u0 += dcmt[i + 3] * u2;
      u0 += dcmt[i + 6] * tmp_g;
      Fape[i] = u0;
    }

    Fsd = Fape[2] * modello_HITL_SFT_v4_P.cng_Value;
  } else {
    /* '<S72>:1:61' */
    Fsd = 0.0;
  }

  if (Mye > 0.05) {
    /* '<S72>:1:63' */
    /* '<S72>:1:64' */
    tmp_f = modello_HITL_SFT_v4_B.pqr[1] * modello_HITL_SFT_v4_P.rmgrG[2] -
      modello_HITL_SFT_v4_B.pqr[2] * modello_HITL_SFT_v4_P.rmgrG[1];
    u2 = modello_HITL_SFT_v4_B.pqr[2] * modello_HITL_SFT_v4_P.rmgrG[0] -
      modello_HITL_SFT_v4_B.pqr[0] * modello_HITL_SFT_v4_P.rmgrG[2];
    u0 = modello_HITL_SFT_v4_B.pqr[0] * modello_HITL_SFT_v4_P.rmgrG[1] -
      modello_HITL_SFT_v4_B.pqr[1] * modello_HITL_SFT_v4_P.rmgrG[0];
    tmp_f += modello_HITL_SFT_v4_B.UnitConversion[0];
    u2 += modello_HITL_SFT_v4_B.UnitConversion[1];
    tmp_g = modello_HITL_SFT_v4_B.UnitConversion[2] + u0;
    for (i = 0; i < 3; i++) {
      u0 = dcmt[i] * tmp_f;
      u0 += dcmt[i + 3] * u2;
      u0 += dcmt[i + 6] * tmp_g;
      Fape[i] = u0;
    }

    Frmd = Fape[2] * modello_HITL_SFT_v4_P.cmg_Value;
  } else {
    /* '<S72>:1:65' */
    Frmd = 0.0;
  }

  if (diffLm > 0.05) {
    /* '<S72>:1:67' */
    /* '<S72>:1:68' */
    tmp_f = modello_HITL_SFT_v4_B.pqr[1] * modello_HITL_SFT_v4_P.rmglG[2] -
      modello_HITL_SFT_v4_B.pqr[2] * modello_HITL_SFT_v4_P.rmglG[1];
    u2 = modello_HITL_SFT_v4_B.pqr[2] * modello_HITL_SFT_v4_P.rmglG[0] -
      modello_HITL_SFT_v4_B.pqr[0] * modello_HITL_SFT_v4_P.rmglG[2];
    u0 = modello_HITL_SFT_v4_B.pqr[0] * modello_HITL_SFT_v4_P.rmglG[1] -
      modello_HITL_SFT_v4_B.pqr[1] * modello_HITL_SFT_v4_P.rmglG[0];
    tmp_f += modello_HITL_SFT_v4_B.UnitConversion[0];
    u2 += modello_HITL_SFT_v4_B.UnitConversion[1];
    tmp_g = modello_HITL_SFT_v4_B.UnitConversion[2] + u0;
    for (i = 0; i < 3; i++) {
      u0 = dcmt[i] * tmp_f;
      u0 += dcmt[i + 3] * u2;
      u0 += dcmt[i + 6] * tmp_g;
      Fape[i] = u0;
    }

    u0 = Fape[2] * modello_HITL_SFT_v4_P.cmg_Value;
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
  modello_HITL_SFT_v4_B.Ntot = (u2 + tmp_f) + tmp_g;
  modello_HITL_SFT_v4_B.diffRm = b_s;
  modello_HITL_SFT_v4_B.Ds = b_fmod;
  modello_HITL_SFT_v4_B.Drm = Mye;
  modello_HITL_SFT_v4_B.Dlm = diffLm;
  modello_HITL_SFT_v4_B.Fss = Fss;
  modello_HITL_SFT_v4_B.Frms = Frms;
  modello_HITL_SFT_v4_B.Flms = u1;
  modello_HITL_SFT_v4_B.Fsd = Fsd;
  modello_HITL_SFT_v4_B.Frmd = Frmd;
  modello_HITL_SFT_v4_B.Flmd = u0;
  modello_HITL_SFT_v4_B.Ns = u2;
  modello_HITL_SFT_v4_B.Nrm = tmp_f;
  modello_HITL_SFT_v4_B.Nlm = tmp_g;

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
  tmp_f = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
  u2 = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  u0 = sin(modello_HITL_SFT_v4_B.phithetapsi[1]);
  diffLm = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
  dcmt[0] = tmp_f;
  dcmt[3] = 0.0;
  dcmt[6] = -u2;
  dcmt[2] = u0;
  dcmt[5] = 0.0;
  dcmt[8] = diffLm;

  /* '<S73>:1:18' */
  tmp_f = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  u2 = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  u0 = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  diffLm = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
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
    tmp_f = u0 * modello_HITL_SFT_v4_B.F[0];
    u2 = u0 * modello_HITL_SFT_v4_B.Sum1_n[0];
    diffLm = u0 * modello_HITL_SFT_v4_B.UnitConversion[0];
    Fss = u0 * modello_HITL_SFT_v4_B.pqr[0];
    dcmt[3 * i] = u0;
    u0 = T_eb[i + 3];
    tmp_f += u0 * modello_HITL_SFT_v4_B.F[1];
    u2 += u0 * modello_HITL_SFT_v4_B.Sum1_n[1];
    diffLm += u0 * modello_HITL_SFT_v4_B.UnitConversion[1];
    Fss += u0 * modello_HITL_SFT_v4_B.pqr[1];
    dcmt[3 * i + 1] = u0;
    u0 = T_eb[i + 6];
    tmp_f += u0 * modello_HITL_SFT_v4_B.F[2];
    u2 += u0 * modello_HITL_SFT_v4_B.Sum1_n[2];
    diffLm += u0 * modello_HITL_SFT_v4_B.UnitConversion[2];
    Fss += u0 * modello_HITL_SFT_v4_B.pqr[2];
    dcmt[3 * i + 2] = u0;
    Fape[i] = tmp_f;
    Mape[i] = u2;
    Ve[i] = diffLm;
    ratese[i] = Fss;
  }

  if (modello_HITL_SFT_v4_B.Ntot == 0.0) {
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
  b_fmod = 0.35 * modello_HITL_SFT_v4_B.Ns * 0.2742 + 0.7 *
    modello_HITL_SFT_v4_B.Nrm * 0.1958;
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
  if (modello_HITL_SFT_v4_B.Ntot == 0.0) {
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
  tmp_f = ((0.35 * modello_HITL_SFT_v4_B.Ntot - u0) * u1 + u2) * -tmp_f;
  u2 = ((0.35 * modello_HITL_SFT_v4_B.Ntot - Frms) * Fsd + Fss) * -diffLm;
  tmp_g = modello_HITL_SFT_v4_B.Ntot;
  for (i = 0; i < 3; i++) {
    u0 = dcmt[i] * tmp_f;
    u0 += dcmt[i + 3] * u2;
    u0 += dcmt[i + 6] * tmp_g;
    v_re[i] = u0;
  }

  /* '<S73>:1:67' */
  modello_HITL_SFT_v4_B.Fgear[0] = v_re[0];
  modello_HITL_SFT_v4_B.Fgear[1] = v_re[1];
  modello_HITL_SFT_v4_B.Fgear[2] = -v_re[2];

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
    modello_HITL_SFT_v4_B.Mgear[i] = 0.0;
    modello_HITL_SFT_v4_B.Mgear[i] += dcmt[i] * b_s;
    modello_HITL_SFT_v4_B.Mgear[i] += dcmt[i + 3] * Mye;
    modello_HITL_SFT_v4_B.Mgear[i] += dcmt[i + 6] * u0;

    /* Sum: '<S22>/Sum3' */
    modello_HITL_SFT_v4_B.Sum3[i] = modello_HITL_SFT_v4_B.Sum1_n[i] +
      modello_HITL_SFT_v4_B.Mgear[i];

    /* Sum: '<S37>/Sum2' */
    modello_HITL_SFT_v4_B.Sum2_m[i] = (modello_HITL_SFT_v4_B.Sum3[i] -
      modello_HITL_SFT_v4_B.Reshape2_o[i]) - modello_HITL_SFT_v4_B.Sum_n[i];

    /* Reshape: '<S37>/Reshape1' */
    modello_HITL_SFT_v4_B.Reshape1_m[i] = modello_HITL_SFT_v4_B.Sum2_m[i];
  }

  /* End of MATLAB Function: '<S29>/MATLAB Function2' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Selector: '<S37>/Selector2' incorporates:
       *  Concatenate: '<S38>/Vector Concatenate'
       */
      modello_HITL_SFT_v4_B.Selector2[3 * i] =
        modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i];
      modello_HITL_SFT_v4_B.Selector2[3 * i + 1] =
        modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 1];
      modello_HITL_SFT_v4_B.Selector2[3 * i + 2] =
        modello_HITL_SFT_v4_B.VectorConcatenate_i[6 * i + 2];
    }
  }

  /* Product: '<S37>/Product2' incorporates:
   *  Reshape: '<S37>/Reshape1'
   *  Selector: '<S37>/Selector2'
   */
  rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(modello_HITL_SFT_v4_B.Reshape1_m,
    modello_HITL_SFT_v4_B.Selector2, modello_HITL_SFT_v4_B.Product2_l);

  /* Reshape: '<S37>/Reshape' incorporates:
   *  Product: '<S37>/Product2'
   */
  modello_HITL_SFT_v4_B.Reshape[0] = modello_HITL_SFT_v4_B.Product2_l[0];
  modello_HITL_SFT_v4_B.Reshape[1] = modello_HITL_SFT_v4_B.Product2_l[1];
  modello_HITL_SFT_v4_B.Reshape[2] = modello_HITL_SFT_v4_B.Product2_l[2];

  /* Sum: '<S22>/Sum2' */
  modello_HITL_SFT_v4_B.F_m[0] = modello_HITL_SFT_v4_B.F[0] +
    modello_HITL_SFT_v4_B.Fgear[0];

  /* Product: '<S26>/Product' incorporates:
   *  Constant: '<S38>/Constant'
   */
  modello_HITL_SFT_v4_B.Product_m[0] = modello_HITL_SFT_v4_B.F_m[0] /
    modello_HITL_SFT_v4_P.m;

  /* Sum: '<S22>/Sum2' */
  modello_HITL_SFT_v4_B.F_m[1] = modello_HITL_SFT_v4_B.F[1] +
    modello_HITL_SFT_v4_B.Fgear[1];

  /* Product: '<S26>/Product' incorporates:
   *  Constant: '<S38>/Constant'
   */
  modello_HITL_SFT_v4_B.Product_m[1] = modello_HITL_SFT_v4_B.F_m[1] /
    modello_HITL_SFT_v4_P.m;

  /* Sum: '<S22>/Sum2' */
  modello_HITL_SFT_v4_B.F_m[2] = modello_HITL_SFT_v4_B.F[2] +
    modello_HITL_SFT_v4_B.Fgear[2];

  /* Product: '<S26>/Product' incorporates:
   *  Constant: '<S38>/Constant'
   */
  modello_HITL_SFT_v4_B.Product_m[2] = modello_HITL_SFT_v4_B.F_m[2] /
    modello_HITL_SFT_v4_P.m;

  /* Product: '<S52>/j x k' */
  modello_HITL_SFT_v4_B.jxk_d = modello_HITL_SFT_v4_B.ubvbwb[1] *
    modello_HITL_SFT_v4_B.pqr[2];

  /* Product: '<S52>/k x i' */
  modello_HITL_SFT_v4_B.kxi_o = modello_HITL_SFT_v4_B.ubvbwb[2] *
    modello_HITL_SFT_v4_B.pqr[0];

  /* Product: '<S52>/i x j' */
  modello_HITL_SFT_v4_B.ixj_o = modello_HITL_SFT_v4_B.ubvbwb[0] *
    modello_HITL_SFT_v4_B.pqr[1];

  /* Product: '<S53>/k x j' */
  modello_HITL_SFT_v4_B.kxj_j = modello_HITL_SFT_v4_B.ubvbwb[2] *
    modello_HITL_SFT_v4_B.pqr[1];

  /* Product: '<S53>/i x k' */
  modello_HITL_SFT_v4_B.ixk_p = modello_HITL_SFT_v4_B.ubvbwb[0] *
    modello_HITL_SFT_v4_B.pqr[2];

  /* Product: '<S53>/j x i' */
  modello_HITL_SFT_v4_B.jxi_k = modello_HITL_SFT_v4_B.ubvbwb[1] *
    modello_HITL_SFT_v4_B.pqr[0];

  /* Sum: '<S39>/Sum' */
  modello_HITL_SFT_v4_B.Sum_a[0] = modello_HITL_SFT_v4_B.jxk_d -
    modello_HITL_SFT_v4_B.kxj_j;
  modello_HITL_SFT_v4_B.Sum_a[1] = modello_HITL_SFT_v4_B.kxi_o -
    modello_HITL_SFT_v4_B.ixk_p;
  modello_HITL_SFT_v4_B.Sum_a[2] = modello_HITL_SFT_v4_B.ixj_o -
    modello_HITL_SFT_v4_B.jxi_k;

  /* Sum: '<S26>/Sum' */
  modello_HITL_SFT_v4_B.Sum_h2[0] = modello_HITL_SFT_v4_B.Product_m[0] +
    modello_HITL_SFT_v4_B.Sum_a[0];
  modello_HITL_SFT_v4_B.Sum_h2[1] = modello_HITL_SFT_v4_B.Product_m[1] +
    modello_HITL_SFT_v4_B.Sum_a[1];
  modello_HITL_SFT_v4_B.Sum_h2[2] = modello_HITL_SFT_v4_B.Product_m[2] +
    modello_HITL_SFT_v4_B.Sum_a[2];
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitConversion: '<S42>/Unit Conversion' */
    /* Unit Conversion - from: m/s to: m/s
       Expression: output = (1*input) + (0) */
    modello_HITL_SFT_v4_B.UnitConversion_m = 0.0;
  }

  /* Gain: '<S22>/Gain1' */
  modello_HITL_SFT_v4_B.Gain1_k = modello_HITL_SFT_v4_P.Gain1_Gain_b *
    modello_HITL_SFT_v4_B.UnitConversion_g[2];

  /* MATLAB Function: '<S22>/MATLAB Function' */
  /* MATLAB Function 'AENEA /AENEA II_SITL1/MATLAB Function': '<S30>:1' */
  /* '<S30>:1:4' */
  /* '<S30>:1:5' */
  /* '<S30>:1:7' */
  tmp_f = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  u2 = tan(modello_HITL_SFT_v4_B.phithetapsi[1]);
  u0 = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  diffLm = tan(modello_HITL_SFT_v4_B.phithetapsi[1]);
  Fss = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  Frms = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  b_s = sin(modello_HITL_SFT_v4_B.phithetapsi[0]);
  b_fmod = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
  Mye = cos(modello_HITL_SFT_v4_B.phithetapsi[0]);
  u1 = cos(modello_HITL_SFT_v4_B.phithetapsi[1]);
  modello_HITL_SFT_v4_B.invR[0] = 1.0;
  modello_HITL_SFT_v4_B.invR[3] = tmp_f * u2;
  modello_HITL_SFT_v4_B.invR[6] = u0 * diffLm;
  modello_HITL_SFT_v4_B.invR[1] = 0.0;
  modello_HITL_SFT_v4_B.invR[4] = Fss;
  modello_HITL_SFT_v4_B.invR[7] = -Frms;
  modello_HITL_SFT_v4_B.invR[2] = 0.0;
  modello_HITL_SFT_v4_B.invR[5] = 1.0 / b_fmod * b_s;
  modello_HITL_SFT_v4_B.invR[8] = 1.0 / u1 * Mye;

  /* Product: '<S22>/Product' */
  modello_HITL_SFT_v4_B.Product_c = modello_HITL_SFT_v4_B.Gain1_k /
    modello_HITL_SFT_v4_B.module;

  /* Product: '<S22>/Product1' */
  memcpy(&dcmt[0], &modello_HITL_SFT_v4_B.invR[0], 9U * sizeof(real_T));
  Fape[0] = modello_HITL_SFT_v4_B.pqr[0];
  Fape[1] = modello_HITL_SFT_v4_B.pqr[1];
  Fape[2] = modello_HITL_SFT_v4_B.pqr[2];
  for (i = 0; i < 3; i++) {
    u2 = dcmt[i] * Fape[0];
    u2 += dcmt[i + 3] * Fape[1];
    u2 += dcmt[i + 6] * Fape[2];
    Mape[i] = u2;
  }

  /* Product: '<S22>/Product1' */
  modello_HITL_SFT_v4_B.Product1_l[0] = Mape[0];
  modello_HITL_SFT_v4_B.Product1_l[1] = Mape[1];
  modello_HITL_SFT_v4_B.Product1_l[2] = Mape[2];

  /* Gain: '<S31>/Gain' */
  modello_HITL_SFT_v4_B.Gain_c = modello_HITL_SFT_v4_P.Gain_Gain_k *
    modello_HITL_SFT_v4_B.Product3_o;

  /* RelationalOperator: '<S74>/Compare' incorporates:
   *  Constant: '<S74>/Constant'
   */
  modello_HITL_SFT_v4_B.Compare = (modello_HITL_SFT_v4_B.Gain_c >=
    modello_HITL_SFT_v4_P.CompareToConstant_const);
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* Stop: '<S31>/Stop Simulation' */
    if (modello_HITL_SFT_v4_B.Compare) {
      rtmSetStopRequested(modello_HITL_SFT_v4_M, 1);
    }

    /* End of Stop: '<S31>/Stop Simulation' */

    /* S-Function (rti_commonblock): '<S89>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* Product: '<S5>/Divide' */
    modello_HITL_SFT_v4_B.Divide_a = 1.0 / modello_HITL_SFT_v4_B.SFunction_o1 *
      modello_HITL_SFT_v4_B.SFunction_o2;

    /* Gain: '<S5>/Gain' */
    modello_HITL_SFT_v4_B.Gain_o = modello_HITL_SFT_v4_P.Gain_Gain_f *
      modello_HITL_SFT_v4_B.Divide_a;

    /* Gain: '<S98>/Gain1' */
    modello_HITL_SFT_v4_B.Gain1_g = modello_HITL_SFT_v4_P.Gain1_Gain_f *
      modello_HITL_SFT_v4_B.Gain_o;

    /* Sum: '<S98>/Sum2' incorporates:
     *  Constant: '<S98>/Constant2'
     */
    modello_HITL_SFT_v4_B.Sum2_g = modello_HITL_SFT_v4_B.Gain1_g -
      modello_HITL_SFT_v4_P.Constant2_Value_e;

    /* Switch generated from: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    if (modello_HITL_SFT_v4_P.Constant_Value_k >
        modello_HITL_SFT_v4_P.Switch_1_Threshold) {
      /* Switch generated from: '<Root>/Switch' incorporates:
       *  Constant: '<S4>/T'
       */
      modello_HITL_SFT_v4_B.Manetta = modello_HITL_SFT_v4_P.U0[3];
    } else {
      /* Switch generated from: '<Root>/Switch' */
      modello_HITL_SFT_v4_B.Manetta = modello_HITL_SFT_v4_B.Sum2_g;
    }

    /* Saturate: '<S31>/Saturation' */
    u0 = modello_HITL_SFT_v4_B.Manetta;
    u1 = modello_HITL_SFT_v4_P.Saturation_LowerSat_i;
    u2 = modello_HITL_SFT_v4_P.Saturation_UpperSat_f;
    if (u0 > u2) {
      /* Saturate: '<S31>/Saturation' */
      modello_HITL_SFT_v4_B.Saturation_b = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S31>/Saturation' */
      modello_HITL_SFT_v4_B.Saturation_b = u1;
    } else {
      /* Saturate: '<S31>/Saturation' */
      modello_HITL_SFT_v4_B.Saturation_b = u0;
    }

    /* End of Saturate: '<S31>/Saturation' */

    /* Gain: '<S31>/LUT MOTORE' */
    modello_HITL_SFT_v4_B.LUTMOTORE = modello_HITL_SFT_v4_P.LUTMOTORE_Gain *
      modello_HITL_SFT_v4_B.Saturation_b;

    /* Fcn: '<S31>/Fcn' */
    modello_HITL_SFT_v4_B.Fcn = modello_HITL_SFT_v4_B.LUTMOTORE + 1.0;

    /* Gain: '<S31>/RPs->rad//s' */
    modello_HITL_SFT_v4_B.RPsrads = modello_HITL_SFT_v4_P.RPsrads_Gain *
      modello_HITL_SFT_v4_B.RPMRPs;
  }

  /* Trigonometry: '<S22>/Trigonometric Function' */
  u0 = modello_HITL_SFT_v4_B.Product_c;
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* Trigonometry: '<S22>/Trigonometric Function' */
  modello_HITL_SFT_v4_B.u_h = asin(u0);
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S23>/Constant' */
    modello_HITL_SFT_v4_B.rPG[0] = modello_HITL_SFT_v4_P.rPG[0];
    modello_HITL_SFT_v4_B.rPG[1] = modello_HITL_SFT_v4_P.rPG[1];
    modello_HITL_SFT_v4_B.rPG[2] = modello_HITL_SFT_v4_P.rPG[2];

    /* Constant: '<S23>/Constant5' */
    modello_HITL_SFT_v4_B.rLEG[0] = modello_HITL_SFT_v4_P.rLEG[0];
    modello_HITL_SFT_v4_B.rLEG[1] = modello_HITL_SFT_v4_P.rLEG[1];
    modello_HITL_SFT_v4_B.rLEG[2] = modello_HITL_SFT_v4_P.rLEG[2];

    /* Constant: '<S23>/Constant6' */
    modello_HITL_SFT_v4_B.rACwG[0] = modello_HITL_SFT_v4_P.rACwG[0];
    modello_HITL_SFT_v4_B.rACwG[1] = modello_HITL_SFT_v4_P.rACwG[1];
    modello_HITL_SFT_v4_B.rACwG[2] = modello_HITL_SFT_v4_P.rACwG[2];

    /* Constant: '<S23>/Constant7' */
    modello_HITL_SFT_v4_B.rACtG[0] = modello_HITL_SFT_v4_P.rACtG[0];
    modello_HITL_SFT_v4_B.rACtG[1] = modello_HITL_SFT_v4_P.rACtG[1];
    modello_HITL_SFT_v4_B.rACtG[2] = modello_HITL_SFT_v4_P.rACtG[2];

    /* Constant: '<S23>/Constant8' */
    modello_HITL_SFT_v4_B.rNPG[0] = modello_HITL_SFT_v4_P.rNPG[0];
    modello_HITL_SFT_v4_B.rNPG[1] = modello_HITL_SFT_v4_P.rNPG[1];
    modello_HITL_SFT_v4_B.rNPG[2] = modello_HITL_SFT_v4_P.rNPG[2];

    /* Constant: '<S23>/Jeng' */
    modello_HITL_SFT_v4_B.Jeng = modello_HITL_SFT_v4_P.Jeng;

    /* Constant: '<S23>/Jprop' */
    modello_HITL_SFT_v4_B.Jprop = modello_HITL_SFT_v4_P.Jprop;

    /* Constant: '<S23>/Rprop' */
    modello_HITL_SFT_v4_B.Rprop = modello_HITL_SFT_v4_P.Rprop;

    /* Constant: '<S23>/b' */
    modello_HITL_SFT_v4_B.b = modello_HITL_SFT_v4_P.b;

    /* Constant: '<S23>/c' */
    modello_HITL_SFT_v4_B.c = modello_HITL_SFT_v4_P.c;
  }

  /* Gain: '<S24>/P0' */
  modello_HITL_SFT_v4_B.P0_n = modello_HITL_SFT_v4_P.P0_Gain_e *
    modello_HITL_SFT_v4_B.TT0gLR_m;

  /* Product: '<S24>/Product2' */
  modello_HITL_SFT_v4_B.Product2_fr = modello_HITL_SFT_v4_B.P0_n *
    modello_HITL_SFT_v4_B.StratosphereModel_e;

  /* Gain: '<S24>/gamma*R' */
  modello_HITL_SFT_v4_B.gammaR = modello_HITL_SFT_v4_P.gammaR_Gain *
    modello_HITL_SFT_v4_B.Sum1_b;

  /* Sqrt: '<S24>/a' */
  modello_HITL_SFT_v4_B.a = sqrt(modello_HITL_SFT_v4_B.gammaR);

  /* SignalConversion generated from: '<S82>/ SFunction ' incorporates:
   *  Constant: '<S23>/Constant1'
   *  MATLAB Function: '<S25>/MATLAB Function'
   */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[0] =
    modello_HITL_SFT_v4_B.pqr[0];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[3] =
    modello_HITL_SFT_v4_P.rAHRSG[0];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[1] =
    modello_HITL_SFT_v4_B.pqr[1];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[4] =
    modello_HITL_SFT_v4_P.rAHRSG[1];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[2] =
    modello_HITL_SFT_v4_B.pqr[2];
  modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[5] =
    modello_HITL_SFT_v4_P.rAHRSG[2];

  /* MATLAB Function: '<S25>/MATLAB Function' */
  /* MATLAB Function 'AENEA /toSensors/MATLAB Function': '<S82>:1' */
  /* '<S82>:1:2' */
  Fape[0] = modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[0];
  Fape[1] = modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[1];
  Fape[2] = modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[2];

  /* '<S82>:1:3' */
  Mape[0] = modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[3];
  Mape[1] = modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[4];
  Mape[2] = modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[5];

  /* '<S82>:1:6' */
  Ve[0] = Fape[1] * Mape[2] - Fape[2] * Mape[1];
  Ve[1] = Fape[2] * Mape[0] - Fape[0] * Mape[2];
  Ve[2] = Fape[0] * Mape[1] - Fape[1] * Mape[0];

  /* '<S82>:1:7' */
  modello_HITL_SFT_v4_B.y_p[0] = Fape[1] * Ve[2] - Fape[2] * Ve[1];
  modello_HITL_SFT_v4_B.y_p[1] = Fape[2] * Ve[0] - Fape[0] * Ve[2];
  modello_HITL_SFT_v4_B.y_p[2] = Fape[0] * Ve[1] - Fape[1] * Ve[0];

  /* Product: '<S25>/Product' incorporates:
   *  Constant: '<S25>/Constant'
   *  Reshape: '<S46>/Reshape (9) to [3x3] column-major'
   */
  memcpy(&dcmt[0], &modello_HITL_SFT_v4_B.Reshape9to3x3columnmajor[0], 9U *
         sizeof(real_T));
  Fape[0] = modello_HITL_SFT_v4_P.g[0];
  Fape[1] = modello_HITL_SFT_v4_P.g[1];
  Fape[2] = modello_HITL_SFT_v4_P.g[2];
  for (i = 0; i < 3; i++) {
    u2 = dcmt[i] * Fape[0];
    u2 += dcmt[i + 3] * Fape[1];
    u2 += dcmt[i + 6] * Fape[2];

    /* Product: '<S25>/Product' */
    modello_HITL_SFT_v4_B.Product_k[i] = u2;
  }

  /* End of Product: '<S25>/Product' */

  /* Sum: '<S25>/Sum1' */
  modello_HITL_SFT_v4_B.Sum1_d[0] = modello_HITL_SFT_v4_B.Sum_h2[0] -
    modello_HITL_SFT_v4_B.Product_k[0];
  modello_HITL_SFT_v4_B.Sum1_d[1] = modello_HITL_SFT_v4_B.Sum_h2[1] -
    modello_HITL_SFT_v4_B.Product_k[1];
  modello_HITL_SFT_v4_B.Sum1_d[2] = modello_HITL_SFT_v4_B.Sum_h2[2] -
    modello_HITL_SFT_v4_B.Product_k[2];

  /* Sum: '<S25>/Sum' */
  modello_HITL_SFT_v4_B.Sum_dn[0] = modello_HITL_SFT_v4_B.y_p[0] +
    modello_HITL_SFT_v4_B.Sum1_d[0];
  modello_HITL_SFT_v4_B.Sum_dn[1] = modello_HITL_SFT_v4_B.y_p[1] +
    modello_HITL_SFT_v4_B.Sum1_d[1];
  modello_HITL_SFT_v4_B.Sum_dn[2] = modello_HITL_SFT_v4_B.y_p[2] +
    modello_HITL_SFT_v4_B.Sum1_d[2];

  /* Gain: '<S83>/Gain' */
  modello_HITL_SFT_v4_B.Gain_fl = modello_HITL_SFT_v4_P.Gain_Gain_g *
    modello_HITL_SFT_v4_B.UnitConversion_g[2];

  /* UnitConversion: '<S87>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  modello_HITL_SFT_v4_B.UnitConversion_gt = 0.017453292519943295 *
    modello_HITL_SFT_v4_B.Switch;
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S86>/Sum' incorporates:
     *  Constant: '<S86>/Constant'
     *  Constant: '<S86>/f'
     */
    modello_HITL_SFT_v4_B.Sum_i = modello_HITL_SFT_v4_P.Constant_Value_j -
      modello_HITL_SFT_v4_P.f_Value;

    /* Product: '<S86>/Product4' */
    modello_HITL_SFT_v4_B.Product4_p = modello_HITL_SFT_v4_B.Sum_i *
      modello_HITL_SFT_v4_B.Sum_i;

    /* Product: '<S86>/Product1' incorporates:
     *  Constant: '<S86>/Constant'
     */
    modello_HITL_SFT_v4_B.Product1_o = modello_HITL_SFT_v4_P.Constant_Value_j /
      modello_HITL_SFT_v4_B.Product4_p;

    /* Sum: '<S86>/Sum1' incorporates:
     *  Constant: '<S86>/Constant'
     */
    modello_HITL_SFT_v4_B.Sum1_a = modello_HITL_SFT_v4_B.Product1_o -
      modello_HITL_SFT_v4_P.Constant_Value_j;
  }

  /* Trigonometry: '<S86>/Trigonometric Function' */
  modello_HITL_SFT_v4_B.TrigonometricFunction = sin
    (modello_HITL_SFT_v4_B.UnitConversion_gt);

  /* Product: '<S86>/Product2' */
  modello_HITL_SFT_v4_B.Product2_i = modello_HITL_SFT_v4_B.TrigonometricFunction
    * modello_HITL_SFT_v4_B.TrigonometricFunction * modello_HITL_SFT_v4_B.Sum1_a;

  /* Sum: '<S86>/Sum2' incorporates:
   *  Constant: '<S86>/Constant'
   */
  modello_HITL_SFT_v4_B.Sum2_e = modello_HITL_SFT_v4_P.Constant_Value_j +
    modello_HITL_SFT_v4_B.Product2_i;

  /* Product: '<S86>/Product3' incorporates:
   *  Constant: '<S86>/Re'
   */
  modello_HITL_SFT_v4_B.Product3_p = modello_HITL_SFT_v4_P.Re_Value *
    modello_HITL_SFT_v4_P.Re_Value / modello_HITL_SFT_v4_B.Sum2_e;

  /* Sqrt: '<S86>/sqrt' */
  modello_HITL_SFT_v4_B.sqrt_n = sqrt(modello_HITL_SFT_v4_B.Product3_p);

  /* Sum: '<S83>/Sum' */
  modello_HITL_SFT_v4_B.Sum_j = modello_HITL_SFT_v4_B.sqrt_n +
    modello_HITL_SFT_v4_B.PositionIntegrator2[2];

  /* Sum: '<S83>/Sum1' */
  modello_HITL_SFT_v4_B.Sum1_ba = modello_HITL_SFT_v4_B.sqrt_n +
    modello_HITL_SFT_v4_B.PositionIntegrator2[2];

  /* Product: '<S83>/Vn//(Rm+h)' */
  modello_HITL_SFT_v4_B.VnRmh = modello_HITL_SFT_v4_B.UnitConversion_g[0] /
    modello_HITL_SFT_v4_B.Sum_j;

  /* Trigonometry: '<S83>/cos(phi)' */
  modello_HITL_SFT_v4_B.cosphi = cos(modello_HITL_SFT_v4_B.Switch);

  /* Product: '<S83>/Ve//(Rn+h)cos(phi)' */
  modello_HITL_SFT_v4_B.VeRnhcosphi = modello_HITL_SFT_v4_B.UnitConversion_g[1] /
    modello_HITL_SFT_v4_B.Sum1_ba / modello_HITL_SFT_v4_B.cosphi;

  /* SignalConversion generated from: '<S83>/Position Integrator2' */
  modello_HITL_SFT_v4_B.TmpSignalConversionAtPositionIntegrator2Inport1[0] =
    modello_HITL_SFT_v4_B.VnRmh;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtPositionIntegrator2Inport1[1] =
    modello_HITL_SFT_v4_B.VeRnhcosphi;
  modello_HITL_SFT_v4_B.TmpSignalConversionAtPositionIntegrator2Inport1[2] =
    modello_HITL_SFT_v4_B.Gain_fl;
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S90>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* Product: '<S5>/Divide1' */
    modello_HITL_SFT_v4_B.Divide1_k = 1.0 / modello_HITL_SFT_v4_B.SFunction_o1_j
      * modello_HITL_SFT_v4_B.SFunction_o2_i;

    /* Gain: '<S5>/Gain1' */
    modello_HITL_SFT_v4_B.Gain1_hj = modello_HITL_SFT_v4_P.Gain1_Gain_k *
      modello_HITL_SFT_v4_B.Divide1_k;

    /* MATLAB Function: '<S96>/MATLAB Function' incorporates:
     *  Constant: '<S96>/Constant1'
     *  Constant: '<S96>/Constant4'
     *  Constant: '<S96>/Constant5'
     */
    /* MATLAB Function 'Comandi da ARDUINO/ELEVATOR/MATLAB Function': '<S100>:1' */
    /* '<S100>:1:16' */
    b_fmod = 0.0;

    /* '<S100>:1:17' */
    modello_HITL_SFT_v4_B.C = 0.0;
    if (modello_HITL_SFT_v4_P.Constant1_Value_f == 1.0) {
      /* '<S100>:1:18' */
      if ((modello_HITL_SFT_v4_B.Gain1_hj <=
           modello_HITL_SFT_v4_P.degree_elevator[14]) &&
          (modello_HITL_SFT_v4_B.Gain1_hj >=
           modello_HITL_SFT_v4_P.degree_elevator[0])) {
        /* '<S100>:1:19' */
        /* '<S100>:1:20' */
        for (i = 0; i < 14; i++) {
          /* '<S100>:1:20' */
          if ((modello_HITL_SFT_v4_B.Gain1_hj >=
               modello_HITL_SFT_v4_P.degree_elevator[i]) &&
              (modello_HITL_SFT_v4_B.Gain1_hj <=
               modello_HITL_SFT_v4_P.degree_elevator[i + 1])) {
            /* '<S100>:1:21' */
            /* '<S100>:1:22' */
            b_fmod = (modello_HITL_SFT_v4_P.microsec_elevator[i + 1] -
                      modello_HITL_SFT_v4_P.microsec_elevator[i]) /
              (modello_HITL_SFT_v4_P.degree_elevator[i + 1] -
               modello_HITL_SFT_v4_P.degree_elevator[i]);

            /* '<S100>:1:23' */
            modello_HITL_SFT_v4_B.C = -b_fmod *
              modello_HITL_SFT_v4_P.degree_elevator[i] +
              modello_HITL_SFT_v4_P.microsec_elevator[i];
          }
        }
      } else if (modello_HITL_SFT_v4_B.Gain1_hj >
                 modello_HITL_SFT_v4_P.degree_elevator[14]) {
        /* '<S100>:1:27' */
        /* '<S100>:1:28' */
        b_fmod = (modello_HITL_SFT_v4_P.microsec_elevator[14] -
                  modello_HITL_SFT_v4_P.microsec_elevator[13]) /
          (modello_HITL_SFT_v4_P.degree_elevator[14] -
           modello_HITL_SFT_v4_P.degree_elevator[13]);

        /* '<S100>:1:29' */
        modello_HITL_SFT_v4_B.C = -b_fmod *
          modello_HITL_SFT_v4_P.degree_elevator[13] +
          modello_HITL_SFT_v4_P.microsec_elevator[13];
      } else {
        if (modello_HITL_SFT_v4_B.Gain1_hj <
            modello_HITL_SFT_v4_P.degree_elevator[0]) {
          /* '<S100>:1:30' */
          /* '<S100>:1:31' */
          b_fmod = (modello_HITL_SFT_v4_P.microsec_elevator[1] -
                    modello_HITL_SFT_v4_P.microsec_elevator[0]) /
            (modello_HITL_SFT_v4_P.degree_elevator[1] -
             modello_HITL_SFT_v4_P.degree_elevator[0]);

          /* '<S100>:1:32' */
          modello_HITL_SFT_v4_B.C = -b_fmod *
            modello_HITL_SFT_v4_P.degree_elevator[0] +
            modello_HITL_SFT_v4_P.microsec_elevator[0];
        }
      }
    } else {
      if (modello_HITL_SFT_v4_P.Constant1_Value_f == 0.0) {
        /* '<S100>:1:34' */
        if ((modello_HITL_SFT_v4_B.Gain1_hj <=
             modello_HITL_SFT_v4_P.microsec_elevator[14]) &&
            (modello_HITL_SFT_v4_B.Gain1_hj >=
             modello_HITL_SFT_v4_P.microsec_elevator[0])) {
          /* '<S100>:1:35' */
          /* '<S100>:1:36' */
          for (iU = 0; iU < 14; iU++) {
            /* '<S100>:1:36' */
            if ((modello_HITL_SFT_v4_B.Gain1_hj >=
                 modello_HITL_SFT_v4_P.microsec_elevator[iU]) &&
                (modello_HITL_SFT_v4_B.Gain1_hj <=
                 modello_HITL_SFT_v4_P.microsec_elevator[iU + 1])) {
              /* '<S100>:1:37' */
              /* '<S100>:1:38' */
              b_fmod = (modello_HITL_SFT_v4_P.degree_elevator[iU + 1] -
                        modello_HITL_SFT_v4_P.degree_elevator[iU]) /
                (modello_HITL_SFT_v4_P.microsec_elevator[iU + 1] -
                 modello_HITL_SFT_v4_P.microsec_elevator[iU]);

              /* '<S100>:1:39' */
              modello_HITL_SFT_v4_B.C = -b_fmod *
                modello_HITL_SFT_v4_P.microsec_elevator[iU] +
                modello_HITL_SFT_v4_P.degree_elevator[iU];
            }
          }
        } else if (modello_HITL_SFT_v4_B.Gain1_hj >
                   modello_HITL_SFT_v4_P.microsec_elevator[14]) {
          /* '<S100>:1:42' */
          /* '<S100>:1:43' */
          b_fmod = (modello_HITL_SFT_v4_P.degree_elevator[14] -
                    modello_HITL_SFT_v4_P.degree_elevator[13]) /
            (modello_HITL_SFT_v4_P.microsec_elevator[14] -
             modello_HITL_SFT_v4_P.microsec_elevator[13]);

          /* '<S100>:1:44' */
          modello_HITL_SFT_v4_B.C = -b_fmod *
            modello_HITL_SFT_v4_P.microsec_elevator[14] +
            modello_HITL_SFT_v4_P.degree_elevator[14];
        } else {
          if (modello_HITL_SFT_v4_B.Gain1_hj <
              modello_HITL_SFT_v4_P.microsec_elevator[0]) {
            /* '<S100>:1:45' */
            /* '<S100>:1:46' */
            b_fmod = (modello_HITL_SFT_v4_P.degree_elevator[1] -
                      modello_HITL_SFT_v4_P.degree_elevator[0]) /
              (modello_HITL_SFT_v4_P.microsec_elevator[1] -
               modello_HITL_SFT_v4_P.microsec_elevator[0]);

            /* '<S100>:1:47' */
            modello_HITL_SFT_v4_B.C = -b_fmod *
              modello_HITL_SFT_v4_P.microsec_elevator[14] +
              modello_HITL_SFT_v4_P.degree_elevator[14];
          }
        }
      }
    }

    modello_HITL_SFT_v4_B.K = b_fmod;

    /* End of MATLAB Function: '<S96>/MATLAB Function' */

    /* Product: '<S96>/Product' */
    modello_HITL_SFT_v4_B.Product_e = modello_HITL_SFT_v4_B.K *
      modello_HITL_SFT_v4_B.Gain1_hj;

    /* Sum: '<S96>/Add' */
    modello_HITL_SFT_v4_B.Add_b = modello_HITL_SFT_v4_B.Product_e +
      modello_HITL_SFT_v4_B.C;

    /* Gain: '<S93>/Gain1' */
    modello_HITL_SFT_v4_B.Gain1_n = modello_HITL_SFT_v4_P.Gain1_Gain_j *
      modello_HITL_SFT_v4_B.Add_b;

    /* S-Function (rti_commonblock): '<S91>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* Product: '<S5>/Divide2' */
    modello_HITL_SFT_v4_B.Divide2_c = 1.0 / modello_HITL_SFT_v4_B.SFunction_o1_k
      * modello_HITL_SFT_v4_B.SFunction_o2_l;

    /* Gain: '<S5>/Gain2' */
    modello_HITL_SFT_v4_B.Gain2 = modello_HITL_SFT_v4_P.Gain2_Gain *
      modello_HITL_SFT_v4_B.Divide2_c;

    /* MATLAB Function: '<S88>/MATLAB Function' incorporates:
     *  Constant: '<S88>/Constant1'
     *  Constant: '<S88>/Constant4'
     *  Constant: '<S88>/Constant5'
     */
    modello_HITL_SFT_v4_MATLABFunction(modello_HITL_SFT_v4_P.degree_aileron,
      modello_HITL_SFT_v4_P.microsec_aileron, modello_HITL_SFT_v4_B.Gain2,
      modello_HITL_SFT_v4_P.Constant1_Value_b,
      &modello_HITL_SFT_v4_B.sf_MATLABFunction_i);

    /* Product: '<S88>/Product' */
    modello_HITL_SFT_v4_B.Product_m4 =
      modello_HITL_SFT_v4_B.sf_MATLABFunction_i.K * modello_HITL_SFT_v4_B.Gain2;

    /* Sum: '<S88>/Add' */
    modello_HITL_SFT_v4_B.Add_m = modello_HITL_SFT_v4_B.Product_m4 +
      modello_HITL_SFT_v4_B.sf_MATLABFunction_i.C;

    /* Gain: '<S95>/Gain1' */
    modello_HITL_SFT_v4_B.Gain1_m = modello_HITL_SFT_v4_P.Gain1_Gain_b0 *
      modello_HITL_SFT_v4_B.Add_m;

    /* S-Function (rti_commonblock): '<S92>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* Product: '<S5>/Divide3' */
    modello_HITL_SFT_v4_B.Divide3 = 1.0 / modello_HITL_SFT_v4_B.SFunction_o1_c *
      modello_HITL_SFT_v4_B.SFunction_o2_d;

    /* Gain: '<S5>/Gain3' */
    modello_HITL_SFT_v4_B.Gain3_c = modello_HITL_SFT_v4_P.Gain3_Gain_d *
      modello_HITL_SFT_v4_B.Divide3;

    /* MATLAB Function: '<S97>/MATLAB Function' incorporates:
     *  Constant: '<S97>/Constant1'
     *  Constant: '<S97>/Constant5'
     *  Constant: '<S97>/Constant6'
     */
    modello_HITL_SFT_v4_MATLABFunction(modello_HITL_SFT_v4_P.degree_rudder,
      modello_HITL_SFT_v4_P.microsec_rudder, modello_HITL_SFT_v4_B.Gain3_c,
      modello_HITL_SFT_v4_P.Constant1_Value_j,
      &modello_HITL_SFT_v4_B.sf_MATLABFunction_o);

    /* Product: '<S97>/Product' */
    modello_HITL_SFT_v4_B.Product_g =
      modello_HITL_SFT_v4_B.sf_MATLABFunction_o.K *
      modello_HITL_SFT_v4_B.Gain3_c;

    /* Sum: '<S97>/Add' */
    modello_HITL_SFT_v4_B.Add_h = modello_HITL_SFT_v4_B.Product_g +
      modello_HITL_SFT_v4_B.sf_MATLABFunction_o.C;

    /* Gain: '<S94>/Gain1' */
    modello_HITL_SFT_v4_B.Gain1_gb = modello_HITL_SFT_v4_P.Gain1_Gain_a *
      modello_HITL_SFT_v4_B.Add_h;

    /* S-Function (rti_commonblock): '<S7>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* End of Outputs for S-Function (rti_commonblock): '<S7>/S-Function1' */
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscreteIntegrator: '<S117>/Discrete-Time Integrator3' */
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator3 =
      modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator3_DSTATE;
  }

  /* Sum: '<S117>/Sum12' */
  modello_HITL_SFT_v4_B.Sum12 = modello_HITL_SFT_v4_B.phithetapsi[0] +
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator3;

  /* ZeroOrderHold: '<S117>/Zero-Order Hold9' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S117>/Zero-Order Hold9' */
    modello_HITL_SFT_v4_B.ZeroOrderHold9 = modello_HITL_SFT_v4_B.Sum12;

    /* Gain: '<S116>/Gain' */
    modello_HITL_SFT_v4_B.Gain_k = modello_HITL_SFT_v4_P.Gain_Gain_cg *
      modello_HITL_SFT_v4_B.ZeroOrderHold9;

    /* Saturate: '<S19>/Saturation5' */
    u0 = modello_HITL_SFT_v4_B.Gain_k;
    u1 = modello_HITL_SFT_v4_P.Saturation5_LowerSat;
    u2 = modello_HITL_SFT_v4_P.Saturation5_UpperSat;
    if (u0 > u2) {
      /* Saturate: '<S19>/Saturation5' */
      modello_HITL_SFT_v4_B.Saturation5 = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S19>/Saturation5' */
      modello_HITL_SFT_v4_B.Saturation5 = u1;
    } else {
      /* Saturate: '<S19>/Saturation5' */
      modello_HITL_SFT_v4_B.Saturation5 = u0;
    }

    /* End of Saturate: '<S19>/Saturation5' */

    /* DiscreteIntegrator: '<S117>/Discrete-Time Integrator4' */
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator4 =
      modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator4_DSTATE;
  }

  /* End of ZeroOrderHold: '<S117>/Zero-Order Hold9' */

  /* Sum: '<S117>/Sum16' */
  modello_HITL_SFT_v4_B.Sum16 = modello_HITL_SFT_v4_B.phithetapsi[1] +
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator4;

  /* ZeroOrderHold: '<S117>/Zero-Order Hold10' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S117>/Zero-Order Hold10' */
    modello_HITL_SFT_v4_B.ZeroOrderHold10 = modello_HITL_SFT_v4_B.Sum16;

    /* Gain: '<S112>/Gain' */
    modello_HITL_SFT_v4_B.Gain_l = modello_HITL_SFT_v4_P.Gain_Gain_o *
      modello_HITL_SFT_v4_B.ZeroOrderHold10;

    /* Saturate: '<S19>/Saturation6' */
    u0 = modello_HITL_SFT_v4_B.Gain_l;
    u1 = modello_HITL_SFT_v4_P.Saturation6_LowerSat;
    u2 = modello_HITL_SFT_v4_P.Saturation6_UpperSat;
    if (u0 > u2) {
      /* Saturate: '<S19>/Saturation6' */
      modello_HITL_SFT_v4_B.Saturation6 = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S19>/Saturation6' */
      modello_HITL_SFT_v4_B.Saturation6 = u1;
    } else {
      /* Saturate: '<S19>/Saturation6' */
      modello_HITL_SFT_v4_B.Saturation6 = u0;
    }

    /* End of Saturate: '<S19>/Saturation6' */

    /* DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' */
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator5 =
      modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator5_DSTATE;
  }

  /* End of ZeroOrderHold: '<S117>/Zero-Order Hold10' */

  /* Sum: '<S117>/Sum18' */
  modello_HITL_SFT_v4_B.Sum18 = modello_HITL_SFT_v4_B.phithetapsi[2] +
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator5;

  /* ZeroOrderHold: '<S117>/Zero-Order Hold11' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S117>/Zero-Order Hold11' */
    modello_HITL_SFT_v4_B.ZeroOrderHold11 = modello_HITL_SFT_v4_B.Sum18;

    /* Gain: '<S115>/Gain' */
    modello_HITL_SFT_v4_B.Gain_b = modello_HITL_SFT_v4_P.Gain_Gain_ki *
      modello_HITL_SFT_v4_B.ZeroOrderHold11;

    /* Saturate: '<S19>/Saturation4' */
    u0 = modello_HITL_SFT_v4_B.Gain_b;
    u1 = modello_HITL_SFT_v4_P.Saturation4_LowerSat;
    u2 = modello_HITL_SFT_v4_P.Saturation4_UpperSat;
    if (u0 > u2) {
      /* Saturate: '<S19>/Saturation4' */
      modello_HITL_SFT_v4_B.Saturation4 = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S19>/Saturation4' */
      modello_HITL_SFT_v4_B.Saturation4 = u1;
    } else {
      /* Saturate: '<S19>/Saturation4' */
      modello_HITL_SFT_v4_B.Saturation4 = u0;
    }

    /* End of Saturate: '<S19>/Saturation4' */

    /* RandomNumber: '<S117>/Random Number6' */
    modello_HITL_SFT_v4_B.RandomNumber6 = modello_HITL_SFT_v4_DW.NextOutput_n;
  }

  /* End of ZeroOrderHold: '<S117>/Zero-Order Hold11' */

  /* Sum: '<S117>/Sum23' */
  modello_HITL_SFT_v4_B.Sum23 = modello_HITL_SFT_v4_B.pqr[0] +
    modello_HITL_SFT_v4_B.RandomNumber6;

  /* ZeroOrderHold: '<S117>/Zero-Order Hold15' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S117>/Zero-Order Hold15' */
    modello_HITL_SFT_v4_B.ZeroOrderHold15 = modello_HITL_SFT_v4_B.Sum23;

    /* RandomNumber: '<S117>/Random Number7' */
    modello_HITL_SFT_v4_B.RandomNumber7 = modello_HITL_SFT_v4_DW.NextOutput_b;
  }

  /* End of ZeroOrderHold: '<S117>/Zero-Order Hold15' */

  /* Sum: '<S117>/Sum14' */
  modello_HITL_SFT_v4_B.Sum14_c = modello_HITL_SFT_v4_B.pqr[1] +
    modello_HITL_SFT_v4_B.RandomNumber7;

  /* ZeroOrderHold: '<S117>/Zero-Order Hold16' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S117>/Zero-Order Hold16' */
    modello_HITL_SFT_v4_B.ZeroOrderHold16 = modello_HITL_SFT_v4_B.Sum14_c;

    /* RandomNumber: '<S117>/Random Number8' */
    modello_HITL_SFT_v4_B.RandomNumber8 = modello_HITL_SFT_v4_DW.NextOutput_h;
  }

  /* End of ZeroOrderHold: '<S117>/Zero-Order Hold16' */

  /* Sum: '<S117>/Sum15' */
  modello_HITL_SFT_v4_B.Sum15 = modello_HITL_SFT_v4_B.pqr[2] +
    modello_HITL_SFT_v4_B.RandomNumber8;

  /* ZeroOrderHold: '<S117>/Zero-Order Hold17' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S117>/Zero-Order Hold17' */
    modello_HITL_SFT_v4_B.ZeroOrderHold17 = modello_HITL_SFT_v4_B.Sum15;

    /* RandomNumber: '<S117>/Random Number3' */
    modello_HITL_SFT_v4_B.RandomNumber3 = modello_HITL_SFT_v4_DW.NextOutput_na;
  }

  /* End of ZeroOrderHold: '<S117>/Zero-Order Hold17' */

  /* Sum: '<S117>/Sum20' */
  modello_HITL_SFT_v4_B.Sum20 = modello_HITL_SFT_v4_B.Sum1_d[0] +
    modello_HITL_SFT_v4_B.RandomNumber3;

  /* ZeroOrderHold: '<S117>/Zero-Order Hold12' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S117>/Zero-Order Hold12' */
    modello_HITL_SFT_v4_B.ZeroOrderHold12 = modello_HITL_SFT_v4_B.Sum20;

    /* RandomNumber: '<S117>/Random Number4' */
    modello_HITL_SFT_v4_B.RandomNumber4 = modello_HITL_SFT_v4_DW.NextOutput_o;
  }

  /* End of ZeroOrderHold: '<S117>/Zero-Order Hold12' */

  /* Sum: '<S117>/Sum21' */
  modello_HITL_SFT_v4_B.Sum21 = modello_HITL_SFT_v4_B.Sum1_d[1] +
    modello_HITL_SFT_v4_B.RandomNumber4;

  /* ZeroOrderHold: '<S117>/Zero-Order Hold13' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S117>/Zero-Order Hold13' */
    modello_HITL_SFT_v4_B.ZeroOrderHold13 = modello_HITL_SFT_v4_B.Sum21;

    /* RandomNumber: '<S117>/Random Number5' */
    modello_HITL_SFT_v4_B.RandomNumber5 = modello_HITL_SFT_v4_DW.NextOutput_a;
  }

  /* End of ZeroOrderHold: '<S117>/Zero-Order Hold13' */

  /* Sum: '<S117>/Sum22' */
  modello_HITL_SFT_v4_B.Sum22 = modello_HITL_SFT_v4_B.Sum1_d[2] +
    modello_HITL_SFT_v4_B.RandomNumber5;

  /* ZeroOrderHold: '<S117>/Zero-Order Hold14' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S117>/Zero-Order Hold14' */
    modello_HITL_SFT_v4_B.ZeroOrderHold14 = modello_HITL_SFT_v4_B.Sum22;

    /* Outputs for Atomic SubSystem: '<S19>/Enabled Subsystem' */
    /* DataTypeConversion: '<S107>/Data Type Conversion' */
    modello_HITL_SFT_v4_B.DataTypeConversion[0] = (real32_T)
      modello_HITL_SFT_v4_B.ZeroOrderHold12;
    modello_HITL_SFT_v4_B.DataTypeConversion[1] = (real32_T)
      modello_HITL_SFT_v4_B.ZeroOrderHold13;
    modello_HITL_SFT_v4_B.DataTypeConversion[2] = (real32_T)
      modello_HITL_SFT_v4_B.ZeroOrderHold14;
    modello_HITL_SFT_v4_B.DataTypeConversion[3] = (real32_T)
      modello_HITL_SFT_v4_B.ZeroOrderHold15;
    modello_HITL_SFT_v4_B.DataTypeConversion[4] = (real32_T)
      modello_HITL_SFT_v4_B.ZeroOrderHold16;
    modello_HITL_SFT_v4_B.DataTypeConversion[5] = (real32_T)
      modello_HITL_SFT_v4_B.ZeroOrderHold17;
    modello_HITL_SFT_v4_B.DataTypeConversion[6] = (real32_T)
      modello_HITL_SFT_v4_B.Saturation5;
    modello_HITL_SFT_v4_B.DataTypeConversion[7] = (real32_T)
      modello_HITL_SFT_v4_B.Saturation6;
    modello_HITL_SFT_v4_B.DataTypeConversion[8] = (real32_T)
      modello_HITL_SFT_v4_B.Saturation4;

    /* S-Function (SImulate_messageMTi_nuovo): '<S107>/S-Function Builder1' */
    SImulate_messageMTi_nuovo_Outputs_wrapper
      (&modello_HITL_SFT_v4_B.DataTypeConversion[0],
       &modello_HITL_SFT_v4_B.SFunctionBuilder1_o1_j[0],
       &modello_HITL_SFT_v4_B.SFunctionBuilder1_o2_o,
       &modello_HITL_SFT_v4_B.SFunctionBuilder1_o3[0]);

    /* End of Outputs for SubSystem: '<S19>/Enabled Subsystem' */

    /* RateTransition: '<Root>/Rate Transition' */
    switch (modello_HITL_SFT_v4_DW.RateTransition_read_buf) {
     case 0:
      modello_HITL_SFT_v4_DW.RateTransition_write_buf = 1;
      break;

     case 1:
      modello_HITL_SFT_v4_DW.RateTransition_write_buf = 0;
      break;

     default:
      modello_HITL_SFT_v4_DW.RateTransition_write_buf = (int8_T)
        (modello_HITL_SFT_v4_DW.RateTransition_last_buf_wr == 0);
      break;
    }

    if (modello_HITL_SFT_v4_DW.RateTransition_write_buf != 0) {
      for (i = 0; i < 41; i++) {
        modello_HITL_SFT_v4_DW.RateTransition_Buffer1[i] =
          modello_HITL_SFT_v4_B.SFunctionBuilder1_o1_j[i];
      }
    } else {
      for (i = 0; i < 41; i++) {
        modello_HITL_SFT_v4_DW.RateTransition_Buffer0[i] =
          modello_HITL_SFT_v4_B.SFunctionBuilder1_o1_j[i];
      }
    }

    modello_HITL_SFT_v4_DW.RateTransition_last_buf_wr =
      modello_HITL_SFT_v4_DW.RateTransition_write_buf;
    modello_HITL_SFT_v4_DW.RateTransition_write_buf = -1;

    /* End of RateTransition: '<Root>/Rate Transition' */
  }

  /* End of ZeroOrderHold: '<S117>/Zero-Order Hold14' */
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Product: '<S109>/Product' */
  modello_HITL_SFT_v4_B.Product_a = modello_HITL_SFT_v4_B.TT0gLR /
    modello_HITL_SFT_v4_B.uT0;

  /* Gain: '<S109>/rho0' */
  modello_HITL_SFT_v4_B.rho0_m = modello_HITL_SFT_v4_P.rho0_Gain_e *
    modello_HITL_SFT_v4_B.Product_a;

  /* Product: '<S109>/Product3' */
  modello_HITL_SFT_v4_B.Product3_cn = modello_HITL_SFT_v4_B.rho0_m *
    modello_HITL_SFT_v4_B.StratosphereModel;

  /* Gain: '<S109>/gamma*R' */
  modello_HITL_SFT_v4_B.gammaR_f = modello_HITL_SFT_v4_P.gammaR_Gain_c *
    modello_HITL_SFT_v4_B.Sum1;

  /* Sqrt: '<S109>/a' */
  modello_HITL_SFT_v4_B.a_b = sqrt(modello_HITL_SFT_v4_B.gammaR_f);

  /* UnitConversion: '<S121>/Unit Conversion' */
  /* Unit Conversion - from: Pa to: Pa
     Expression: output = (1*input) + (0) */
  modello_HITL_SFT_v4_B.UnitConversion_gp = modello_HITL_SFT_v4_B.Product2;

  /* S-Function (saeropalt): '<S110>/S-Function' */

  /* S-Function Block: <S110>/S-Function */
  {
    real_T *temp_table = (real_T *)
      &modello_HITL_SFT_v4_DW.SFunction_temp_table[0];
    real_T *pres_table = (real_T *)
      &modello_HITL_SFT_v4_DW.SFunction_pres_table[0];
    CalcPAltCOESA( &modello_HITL_SFT_v4_B.UnitConversion_gp,
                  &modello_HITL_SFT_v4_B.SFunction, temp_table, pres_table, 1);
  }

  /* UnitConversion: '<S120>/Unit Conversion' */
  /* Unit Conversion - from: m to: m
     Expression: output = (1*input) + (0) */
  modello_HITL_SFT_v4_B.UnitConversion_ge = modello_HITL_SFT_v4_B.SFunction;
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
    /* RandomNumber: '<S122>/White Noise Lat' */
    modello_HITL_SFT_v4_B.WhiteNoiseLat = modello_HITL_SFT_v4_DW.NextOutput_as;
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S117>/Gain3' */
    modello_HITL_SFT_v4_B.Gain3_f = modello_HITL_SFT_v4_P.beta_phi *
      modello_HITL_SFT_v4_B.DiscreteTimeIntegrator3;

    /* RandomNumber: '<S117>/Random Number' */
    modello_HITL_SFT_v4_B.RandomNumber = modello_HITL_SFT_v4_DW.NextOutput_i;

    /* Sum: '<S117>/Sum13' */
    modello_HITL_SFT_v4_B.Sum13_a = modello_HITL_SFT_v4_B.RandomNumber -
      modello_HITL_SFT_v4_B.Gain3_f;

    /* Gain: '<S117>/Gain4' */
    modello_HITL_SFT_v4_B.Gain4_k = modello_HITL_SFT_v4_P.beta_theta *
      modello_HITL_SFT_v4_B.DiscreteTimeIntegrator4;

    /* RandomNumber: '<S117>/Random Number1' */
    modello_HITL_SFT_v4_B.RandomNumber1 = modello_HITL_SFT_v4_DW.NextOutput_e;

    /* Sum: '<S117>/Sum17' */
    modello_HITL_SFT_v4_B.Sum17 = modello_HITL_SFT_v4_B.RandomNumber1 -
      modello_HITL_SFT_v4_B.Gain4_k;

    /* Gain: '<S117>/Gain5' */
    modello_HITL_SFT_v4_B.Gain5_a = modello_HITL_SFT_v4_P.beta_psi *
      modello_HITL_SFT_v4_B.DiscreteTimeIntegrator5;

    /* RandomNumber: '<S117>/Random Number2' */
    modello_HITL_SFT_v4_B.RandomNumber2 = modello_HITL_SFT_v4_DW.NextOutput_or;

    /* Sum: '<S117>/Sum19' */
    modello_HITL_SFT_v4_B.Sum19 = modello_HITL_SFT_v4_B.RandomNumber2 -
      modello_HITL_SFT_v4_B.Gain5_a;

    /* Gain: '<S122>/Gain' */
    b_fmod = 1.0 / modello_HITL_SFT_v4_P.Ta_lat;

    /* Gain: '<S122>/Gain' */
    modello_HITL_SFT_v4_B.Gain_l4 = b_fmod *
      modello_HITL_SFT_v4_B.DiscreteTimeIntegrator;
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
    /* RandomNumber: '<S123>/White Noise' */
    modello_HITL_SFT_v4_B.WhiteNoise = modello_HITL_SFT_v4_DW.NextOutput_f;
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sum: '<S122>/Sum' */
    modello_HITL_SFT_v4_B.Sum_gh = modello_HITL_SFT_v4_B.WhiteNoiseLat -
      modello_HITL_SFT_v4_B.Gain_l4;

    /* Gain: '<S123>/Gain' */
    b_fmod = 1.0 / modello_HITL_SFT_v4_P.Ta_long;

    /* Gain: '<S123>/Gain' */
    modello_HITL_SFT_v4_B.Gain_ai = b_fmod *
      modello_HITL_SFT_v4_B.DiscreteTimeIntegrator_f;

    /* Sum: '<S123>/Sum' */
    modello_HITL_SFT_v4_B.Sum_ic = modello_HITL_SFT_v4_B.WhiteNoise -
      modello_HITL_SFT_v4_B.Gain_ai;

    /* Trigonometry: '<S124>/Cos1' */
    modello_HITL_SFT_v4_B.Cos1 = cos(modello_HITL_SFT_v4_B.Switch1_a);

    /* Product: '<S124>/Multiply6' */
    modello_HITL_SFT_v4_B.V_n = modello_HITL_SFT_v4_B.Sum5 *
      modello_HITL_SFT_v4_B.Cos1;

    /* Trigonometry: '<S124>/Sin1' */
    modello_HITL_SFT_v4_B.Sin1 = sin(modello_HITL_SFT_v4_B.Switch1_a);

    /* Product: '<S124>/Multiply7' */
    modello_HITL_SFT_v4_B.V_e = modello_HITL_SFT_v4_B.Sum5 *
      modello_HITL_SFT_v4_B.Sin1;

    /* ZeroOrderHold: '<S118>/Zero-Order Hold2' */
    if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
        modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
      /* ZeroOrderHold: '<S118>/Zero-Order Hold2' */
      modello_HITL_SFT_v4_B.ZeroOrderHold2_m = modello_HITL_SFT_v4_B.V_n;

      /* ZeroOrderHold: '<S118>/Zero-Order Hold3' */
      modello_HITL_SFT_v4_B.ZeroOrderHold3 = modello_HITL_SFT_v4_B.V_e;
    }

    /* End of ZeroOrderHold: '<S118>/Zero-Order Hold2' */
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
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

    /* S-Function (rti_commonblock): '<S11>/S-Function' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S11>/S-Function1' */
    /* This comment workarounds a code generation problem */
  }
}

/* Model update function */
void modello_HITL_SFT_v4_update(void)
{
  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for RandomNumber: '<S19>/White_press' */
    modello_HITL_SFT_v4_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed) * sqrt
      (modello_HITL_SFT_v4_P.White_pressione) +
      modello_HITL_SFT_v4_P.White_press_Mean;

    /* Update for RandomNumber: '<S19>/White Noise4' */
    modello_HITL_SFT_v4_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_i) *
      modello_HITL_SFT_v4_P.WhiteNoise4_StdDev +
      modello_HITL_SFT_v4_P.WhiteNoise4_Mean;

    /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE +=
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator_gainval *
      modello_HITL_SFT_v4_B.Sum_gh;

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_n +=
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator_gainval_p *
      modello_HITL_SFT_v4_B.Sum_ic;

    /* Update for RandomNumber: '<S124>/Rumore bianco' */
    modello_HITL_SFT_v4_DW.NextOutput_d = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_d) *
      modello_HITL_SFT_v4_P.Rumorebianco_StdDev +
      modello_HITL_SFT_v4_P.Rumorebianco_Mean;

    /* Update for RandomNumber: '<S124>/Noise terra course' */
    modello_HITL_SFT_v4_DW.NextOutput_c2 = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_h) * sqrt
      (modello_HITL_SFT_v4_P.Var_heading_static) +
      modello_HITL_SFT_v4_P.Noiseterracourse_Mean;
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update for RandomNumber: '<S124>/Noise V_hor' */
    modello_HITL_SFT_v4_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_f) *
      modello_HITL_SFT_v4_P.NoiseV_hor_StdDev +
      modello_HITL_SFT_v4_P.NoiseV_hor_Mean;

    /* Update for RandomNumber: '<S124>/noise terra V_hor1' */
    modello_HITL_SFT_v4_DW.NextOutput_m = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_j) * sqrt
      (modello_HITL_SFT_v4_P.Var_V_hor_static) +
      modello_HITL_SFT_v4_P.noiseterraV_hor1_Mean;
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S31>/Unit Delay' */
    modello_HITL_SFT_v4_DW.UnitDelay_DSTATE = modello_HITL_SFT_v4_B.Fcn;

    /* Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S19>/Constant4'
     */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_i +=
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator_gainval_n *
      modello_HITL_SFT_v4_P.Constant4_Value;
    if (modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_i >=
        modello_HITL_SFT_v4_P.DiscreteTimeIntegrator_UpperSat) {
      modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_i =
        modello_HITL_SFT_v4_P.DiscreteTimeIntegrator_UpperSat;
    } else {
      if (modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_i <=
          modello_HITL_SFT_v4_P.DiscreteTimeIntegrator_LowerSat) {
        modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_i =
          modello_HITL_SFT_v4_P.DiscreteTimeIntegrator_LowerSat;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator3' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator3_DSTATE +=
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator3_gainval *
      modello_HITL_SFT_v4_B.Sum13_a;

    /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator4' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator4_DSTATE +=
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator4_gainval *
      modello_HITL_SFT_v4_B.Sum17;

    /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator5_DSTATE +=
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator5_gainval *
      modello_HITL_SFT_v4_B.Sum19;

    /* Update for RandomNumber: '<S117>/Random Number6' */
    modello_HITL_SFT_v4_DW.NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_l) * sqrt(modello_HITL_SFT_v4_P.White_p)
      + modello_HITL_SFT_v4_P.mean_p;

    /* Update for RandomNumber: '<S117>/Random Number7' */
    modello_HITL_SFT_v4_DW.NextOutput_b = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_js) * sqrt(modello_HITL_SFT_v4_P.White_q)
      + modello_HITL_SFT_v4_P.mean_q;

    /* Update for RandomNumber: '<S117>/Random Number8' */
    modello_HITL_SFT_v4_DW.NextOutput_h = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_hb) * sqrt(modello_HITL_SFT_v4_P.White_r)
      + modello_HITL_SFT_v4_P.mean_r;

    /* Update for RandomNumber: '<S117>/Random Number3' */
    modello_HITL_SFT_v4_DW.NextOutput_na = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_e) * sqrt(modello_HITL_SFT_v4_P.White_ax)
      + modello_HITL_SFT_v4_P.mean_ax;

    /* Update for RandomNumber: '<S117>/Random Number4' */
    modello_HITL_SFT_v4_DW.NextOutput_o = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_le) * sqrt
      (modello_HITL_SFT_v4_P.White_ay) + modello_HITL_SFT_v4_P.mean_ay;

    /* Update for RandomNumber: '<S117>/Random Number5' */
    modello_HITL_SFT_v4_DW.NextOutput_a = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_d0) * sqrt
      (modello_HITL_SFT_v4_P.White_az) + modello_HITL_SFT_v4_P.mean_az;

    /* Update for RandomNumber: '<S117>/Random Number' */
    modello_HITL_SFT_v4_DW.NextOutput_i = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_ej) * sqrt
      (modello_HITL_SFT_v4_P.White_gm_phi) +
      modello_HITL_SFT_v4_P.RandomNumber_Mean;

    /* Update for RandomNumber: '<S117>/Random Number1' */
    modello_HITL_SFT_v4_DW.NextOutput_e = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_ix) * sqrt
      (modello_HITL_SFT_v4_P.White_gm_theta) +
      modello_HITL_SFT_v4_P.RandomNumber1_Mean;

    /* Update for RandomNumber: '<S117>/Random Number2' */
    modello_HITL_SFT_v4_DW.NextOutput_or = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_n) * sqrt
      (modello_HITL_SFT_v4_P.White_gm_psi) +
      modello_HITL_SFT_v4_P.RandomNumber2_Mean;
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M) &&
      modello_HITL_SFT_v4_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update for RandomNumber: '<S122>/White Noise Lat' */
    modello_HITL_SFT_v4_DW.NextOutput_as = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_o) *
      modello_HITL_SFT_v4_P.WhiteNoiseLat_StdDev +
      modello_HITL_SFT_v4_P.WhiteNoiseLat_Mean;

    /* Update for RandomNumber: '<S123>/White Noise' */
    modello_HITL_SFT_v4_DW.NextOutput_f = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_ou) *
      modello_HITL_SFT_v4_P.WhiteNoise_StdDev +
      modello_HITL_SFT_v4_P.WhiteNoise_Mean;
  }

  if (rtmIsMajorTimeStep(modello_HITL_SFT_v4_M)) {
    rt_ertODEUpdateContinuousStates(&modello_HITL_SFT_v4_M->solverInfo);
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
  if (!(++modello_HITL_SFT_v4_M->Timing.clockTick0)) {
    ++modello_HITL_SFT_v4_M->Timing.clockTickH0;
  }

  modello_HITL_SFT_v4_M->Timing.t[0] = rtsiGetSolverStopTime
    (&modello_HITL_SFT_v4_M->solverInfo);

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
    modello_HITL_SFT_v4_M->Timing.clockTick1++;
    if (!modello_HITL_SFT_v4_M->Timing.clockTick1) {
      modello_HITL_SFT_v4_M->Timing.clockTickH1++;
    }
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void modello_HITL_SFT_v4_derivatives(void)
{
  XDot_modello_HITL_SFT_v4_T *_rtXdot;
  real_T tmp;
  _rtXdot = ((XDot_modello_HITL_SFT_v4_T *) modello_HITL_SFT_v4_M->derivs);

  /* Derivatives for Integrator: '<S26>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[0] = modello_HITL_SFT_v4_B.Sum_h2[0];
  _rtXdot->ubvbwb_CSTATE[1] = modello_HITL_SFT_v4_B.Sum_h2[1];
  _rtXdot->ubvbwb_CSTATE[2] = modello_HITL_SFT_v4_B.Sum_h2[2];

  /* Derivatives for Integrator: '<S83>/Position Integrator2' */
  _rtXdot->PositionIntegrator2_CSTATE[0] =
    modello_HITL_SFT_v4_B.TmpSignalConversionAtPositionIntegrator2Inport1[0];
  _rtXdot->PositionIntegrator2_CSTATE[1] =
    modello_HITL_SFT_v4_B.TmpSignalConversionAtPositionIntegrator2Inport1[1];
  _rtXdot->PositionIntegrator2_CSTATE[2] =
    modello_HITL_SFT_v4_B.TmpSignalConversionAtPositionIntegrator2Inport1[2];

  /* Derivatives for Integrator: '<S36>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[0] =
    modello_HITL_SFT_v4_B.TmpSignalConversionAtphithetapsiInport1[0];
  _rtXdot->phithetapsi_CSTATE[1] =
    modello_HITL_SFT_v4_B.TmpSignalConversionAtphithetapsiInport1[1];
  _rtXdot->phithetapsi_CSTATE[2] =
    modello_HITL_SFT_v4_B.TmpSignalConversionAtphithetapsiInport1[2];

  /* Derivatives for Integrator: '<S26>/p,q,r ' */
  _rtXdot->pqr_CSTATE[0] = modello_HITL_SFT_v4_B.Reshape[0];
  _rtXdot->pqr_CSTATE[1] = modello_HITL_SFT_v4_B.Reshape[1];
  _rtXdot->pqr_CSTATE[2] = modello_HITL_SFT_v4_B.Reshape[2];

  /* Derivatives for StateSpace: '<S2>/State-Space2' incorporates:
   *  Constant: '<S4>/R'
   */
  _rtXdot->StateSpace2_CSTATE = 0.0;
  _rtXdot->StateSpace2_CSTATE += modello_HITL_SFT_v4_P.StateSpace2_A *
    modello_HITL_SFT_v4_X.StateSpace2_CSTATE;
  tmp = modello_HITL_SFT_v4_P.U0[2];
  _rtXdot->StateSpace2_CSTATE += modello_HITL_SFT_v4_P.StateSpace2_B * tmp;

  /* Derivatives for StateSpace: '<S3>/State-Space2' */
  _rtXdot->StateSpace2_CSTATE_b = 0.0;
  _rtXdot->StateSpace2_CSTATE_b += modello_HITL_SFT_v4_P.StateSpace2_A_e *
    modello_HITL_SFT_v4_X.StateSpace2_CSTATE_b;
  _rtXdot->StateSpace2_CSTATE_b += modello_HITL_SFT_v4_P.StateSpace2_B_c *
    modello_HITL_SFT_v4_B.Gain1_gb;

  /* Derivatives for StateSpace: '<S2>/State-Space1' incorporates:
   *  Constant: '<S4>/A'
   */
  _rtXdot->StateSpace1_CSTATE = 0.0;
  _rtXdot->StateSpace1_CSTATE += modello_HITL_SFT_v4_P.StateSpace1_A *
    modello_HITL_SFT_v4_X.StateSpace1_CSTATE;
  tmp = modello_HITL_SFT_v4_P.U0[1];
  _rtXdot->StateSpace1_CSTATE += modello_HITL_SFT_v4_P.StateSpace1_B * tmp;

  /* Derivatives for StateSpace: '<S3>/State-Space1' */
  _rtXdot->StateSpace1_CSTATE_b = 0.0;
  _rtXdot->StateSpace1_CSTATE_b += modello_HITL_SFT_v4_P.StateSpace1_A_k *
    modello_HITL_SFT_v4_X.StateSpace1_CSTATE_b;
  _rtXdot->StateSpace1_CSTATE_b += modello_HITL_SFT_v4_P.StateSpace1_B_g *
    modello_HITL_SFT_v4_B.Gain1_m;

  /* Derivatives for StateSpace: '<S2>/State-Space' incorporates:
   *  Constant: '<S4>/E'
   */
  _rtXdot->StateSpace_CSTATE = 0.0;
  _rtXdot->StateSpace_CSTATE += modello_HITL_SFT_v4_P.StateSpace_A *
    modello_HITL_SFT_v4_X.StateSpace_CSTATE;
  tmp = modello_HITL_SFT_v4_P.U0[0];
  _rtXdot->StateSpace_CSTATE += modello_HITL_SFT_v4_P.StateSpace_B * tmp;

  /* Derivatives for StateSpace: '<S3>/State-Space' */
  _rtXdot->StateSpace_CSTATE_p = 0.0;
  _rtXdot->StateSpace_CSTATE_p += modello_HITL_SFT_v4_P.StateSpace_A_p *
    modello_HITL_SFT_v4_X.StateSpace_CSTATE_p;
  _rtXdot->StateSpace_CSTATE_p += modello_HITL_SFT_v4_P.StateSpace_B_m *
    modello_HITL_SFT_v4_B.Gain1_n;

  /* Derivatives for Integrator: '<S26>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[0] = modello_HITL_SFT_v4_B.Reshape2[0];
  _rtXdot->xeyeze_CSTATE[1] = modello_HITL_SFT_v4_B.Reshape2[1];
  _rtXdot->xeyeze_CSTATE[2] = modello_HITL_SFT_v4_B.Reshape2[2];
}

/* Model initialize function */
void modello_HITL_SFT_v4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)modello_HITL_SFT_v4_M, 0,
                sizeof(RT_MODEL_modello_HITL_SFT_v4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&modello_HITL_SFT_v4_M->solverInfo,
                          &modello_HITL_SFT_v4_M->Timing.simTimeStep);
    rtsiSetTPtr(&modello_HITL_SFT_v4_M->solverInfo, &rtmGetTPtr
                (modello_HITL_SFT_v4_M));
    rtsiSetStepSizePtr(&modello_HITL_SFT_v4_M->solverInfo,
                       &modello_HITL_SFT_v4_M->Timing.stepSize0);
    rtsiSetdXPtr(&modello_HITL_SFT_v4_M->solverInfo,
                 &modello_HITL_SFT_v4_M->derivs);
    rtsiSetContStatesPtr(&modello_HITL_SFT_v4_M->solverInfo, (real_T **)
                         &modello_HITL_SFT_v4_M->contStates);
    rtsiSetNumContStatesPtr(&modello_HITL_SFT_v4_M->solverInfo,
      &modello_HITL_SFT_v4_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&modello_HITL_SFT_v4_M->solverInfo,
      &modello_HITL_SFT_v4_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&modello_HITL_SFT_v4_M->solverInfo,
      &modello_HITL_SFT_v4_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&modello_HITL_SFT_v4_M->solverInfo,
      &modello_HITL_SFT_v4_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&modello_HITL_SFT_v4_M->solverInfo,
                          (&rtmGetErrorStatus(modello_HITL_SFT_v4_M)));
    rtsiSetRTModelPtr(&modello_HITL_SFT_v4_M->solverInfo, modello_HITL_SFT_v4_M);
  }

  rtsiSetSimTimeStep(&modello_HITL_SFT_v4_M->solverInfo, MAJOR_TIME_STEP);
  modello_HITL_SFT_v4_M->intgData.y = modello_HITL_SFT_v4_M->odeY;
  modello_HITL_SFT_v4_M->intgData.f[0] = modello_HITL_SFT_v4_M->odeF[0];
  modello_HITL_SFT_v4_M->intgData.f[1] = modello_HITL_SFT_v4_M->odeF[1];
  modello_HITL_SFT_v4_M->intgData.f[2] = modello_HITL_SFT_v4_M->odeF[2];
  modello_HITL_SFT_v4_M->intgData.f[3] = modello_HITL_SFT_v4_M->odeF[3];
  modello_HITL_SFT_v4_M->contStates = ((X_modello_HITL_SFT_v4_T *)
    &modello_HITL_SFT_v4_X);
  modello_HITL_SFT_v4_M->periodicContStateIndices = ((int_T*)
    modello_HITL_SFT_v4_PeriodicIndX);
  modello_HITL_SFT_v4_M->periodicContStateRanges = ((real_T*)
    modello_HITL_SFT_v4_PeriodicRngX);
  rtsiSetSolverData(&modello_HITL_SFT_v4_M->solverInfo, (void *)
                    &modello_HITL_SFT_v4_M->intgData);
  rtsiSetSolverName(&modello_HITL_SFT_v4_M->solverInfo,"ode4");
  rtmSetTPtr(modello_HITL_SFT_v4_M, &modello_HITL_SFT_v4_M->Timing.tArray[0]);
  modello_HITL_SFT_v4_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &modello_HITL_SFT_v4_B), 0,
                sizeof(B_modello_HITL_SFT_v4_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionBuilder1Inport1[i] =
        0.0;
    }

    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_B.VectorConcatenate[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_B.Reshape9to3x3columnmajor[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_B.Transpose[i] = 0.0;
    }

    for (i = 0; i < 18; i++) {
      modello_HITL_SFT_v4_B.VectorConcatenate_i[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_B.Selector[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_B.Selector1[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_B.Selector2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_B.invR[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_B.Lbw[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_B.DataTypeConversion[i] = 0.0F;
    }

    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_B.SFunctionBuilder1_o3[i] = 0.0F;
    }

    modello_HITL_SFT_v4_B.ubvbwb[0] = 0.0;
    modello_HITL_SFT_v4_B.ubvbwb[1] = 0.0;
    modello_HITL_SFT_v4_B.ubvbwb[2] = 0.0;
    modello_HITL_SFT_v4_B.UnitConversion[0] = 0.0;
    modello_HITL_SFT_v4_B.UnitConversion[1] = 0.0;
    modello_HITL_SFT_v4_B.UnitConversion[2] = 0.0;
    modello_HITL_SFT_v4_B.Va[0] = 0.0;
    modello_HITL_SFT_v4_B.Va[1] = 0.0;
    modello_HITL_SFT_v4_B.Va[2] = 0.0;
    modello_HITL_SFT_v4_B.Switch1 = 0.0;
    modello_HITL_SFT_v4_B.m_deltaP_to_volt = 0.0;
    modello_HITL_SFT_v4_B.Sum = 0.0;
    modello_HITL_SFT_v4_B.Gain = 0.0;
    modello_HITL_SFT_v4_B.White_press = 0.0;
    modello_HITL_SFT_v4_B.PositionIntegrator2[0] = 0.0;
    modello_HITL_SFT_v4_B.PositionIntegrator2[1] = 0.0;
    modello_HITL_SFT_v4_B.PositionIntegrator2[2] = 0.0;
    modello_HITL_SFT_v4_B.Limitaltitudetotroposhere = 0.0;
    modello_HITL_SFT_v4_B.LapseRate = 0.0;
    modello_HITL_SFT_v4_B.Sum1 = 0.0;
    modello_HITL_SFT_v4_B.uT0 = 0.0;
    modello_HITL_SFT_v4_B.TT0gLR = 0.0;
    modello_HITL_SFT_v4_B.P0 = 0.0;
    modello_HITL_SFT_v4_B.Sum_k = 0.0;
    modello_HITL_SFT_v4_B.LimitaltitudetoStratosphere = 0.0;
    modello_HITL_SFT_v4_B.gR = 0.0;
    modello_HITL_SFT_v4_B.Product1 = 0.0;
    modello_HITL_SFT_v4_B.StratosphereModel = 0.0;
    modello_HITL_SFT_v4_B.Product2 = 0.0;
    modello_HITL_SFT_v4_B.RateTransition = 0.0;
    modello_HITL_SFT_v4_B.Sum13 = 0.0;
    modello_HITL_SFT_v4_B.uDLookupTable = 0.0;
    modello_HITL_SFT_v4_B.WhiteNoise4 = 0.0;
    modello_HITL_SFT_v4_B.phithetapsi[0] = 0.0;
    modello_HITL_SFT_v4_B.phithetapsi[1] = 0.0;
    modello_HITL_SFT_v4_B.phithetapsi[2] = 0.0;
    modello_HITL_SFT_v4_B.h_ground = 0.0;
    modello_HITL_SFT_v4_B.Sum_l = 0.0;
    modello_HITL_SFT_v4_B.Gain_n = 0.0;
    modello_HITL_SFT_v4_B.Saturation3 = 0.0;
    modello_HITL_SFT_v4_B.Sum14 = 0.0;
    modello_HITL_SFT_v4_B.RateTransition1 = 0.0;
    modello_HITL_SFT_v4_B.RateTransition2 = 0.0;
    modello_HITL_SFT_v4_B.MathFunction = 0.0;
    modello_HITL_SFT_v4_B.Gain3 = 0.0;
    modello_HITL_SFT_v4_B.Divide = 0.0;
    modello_HITL_SFT_v4_B.Gain4 = 0.0;
    modello_HITL_SFT_v4_B.Sum2 = 0.0;
    modello_HITL_SFT_v4_B.MathFunction_o = 0.0;
    modello_HITL_SFT_v4_B.Sum1_f = 0.0;
    modello_HITL_SFT_v4_B.Gain_h = 0.0;
    modello_HITL_SFT_v4_B.Sum2_o = 0.0;
    modello_HITL_SFT_v4_B.MathFunction_l = 0.0;
    modello_HITL_SFT_v4_B.Sum1_i = 0.0;
    modello_HITL_SFT_v4_B.ChSign = 0.0;
    modello_HITL_SFT_v4_B.MathFunction1 = 0.0;
    modello_HITL_SFT_v4_B.Switch = 0.0;
    modello_HITL_SFT_v4_B.Gain_f = 0.0;
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator = 0.0;
    modello_HITL_SFT_v4_B.Sum1_e = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold = 0.0;
    modello_HITL_SFT_v4_B.Gain_g = 0.0;
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator_f = 0.0;
    modello_HITL_SFT_v4_B.Sum1_p = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold1 = 0.0;
    modello_HITL_SFT_v4_B.Gain_fx = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtsincosInport1[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtsincosInport1[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtsincosInport1[2] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o1[0] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o1[1] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o1[2] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o2[0] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o2[1] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o2[2] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1[0] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1[1] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1[2] = 0.0;
    modello_HITL_SFT_v4_B.Product[0] = 0.0;
    modello_HITL_SFT_v4_B.Product[1] = 0.0;
    modello_HITL_SFT_v4_B.Product[2] = 0.0;
    modello_HITL_SFT_v4_B.Reshape2[0] = 0.0;
    modello_HITL_SFT_v4_B.Reshape2[1] = 0.0;
    modello_HITL_SFT_v4_B.Reshape2[2] = 0.0;
    modello_HITL_SFT_v4_B.UnitConversion_g[0] = 0.0;
    modello_HITL_SFT_v4_B.UnitConversion_g[1] = 0.0;
    modello_HITL_SFT_v4_B.UnitConversion_g[2] = 0.0;
    modello_HITL_SFT_v4_B.Square2 = 0.0;
    modello_HITL_SFT_v4_B.Square1 = 0.0;
    modello_HITL_SFT_v4_B.Add = 0.0;
    modello_HITL_SFT_v4_B.Sqrt = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold2 = 0.0;
    modello_HITL_SFT_v4_B.NoiseV_hor = 0.0;
    modello_HITL_SFT_v4_B.noiseterraV_hor1 = 0.0;
    modello_HITL_SFT_v4_B.Abs = 0.0;
    modello_HITL_SFT_v4_B.Switch4 = 0.0;
    modello_HITL_SFT_v4_B.Sum5 = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold4 = 0.0;
    modello_HITL_SFT_v4_B.Gain5 = 0.0;
    modello_HITL_SFT_v4_B.Atan2 = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold_d = 0.0;
    modello_HITL_SFT_v4_B.Rumorebianco = 0.0;
    modello_HITL_SFT_v4_B.Divide2 = 0.0;
    modello_HITL_SFT_v4_B.Multiply5 = 0.0;
    modello_HITL_SFT_v4_B.Noiseterracourse = 0.0;
    modello_HITL_SFT_v4_B.Switch3 = 0.0;
    modello_HITL_SFT_v4_B.Course_sporco = 0.0;
    modello_HITL_SFT_v4_B.Switch1_a = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold5 = 0.0;
    modello_HITL_SFT_v4_B.Gain_m = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold6 = 0.0;
    modello_HITL_SFT_v4_B.u = 0.0;
    modello_HITL_SFT_v4_B.u_n = 0.0;
    modello_HITL_SFT_v4_B.uDLookupTable_n = 0.0;
    modello_HITL_SFT_v4_B.Sum1_fc = 0.0;
    modello_HITL_SFT_v4_B.CD = 0.0;
    modello_HITL_SFT_v4_B.uDLookupTable_e = 0.0;
    modello_HITL_SFT_v4_B.Saturation = 0.0;
    modello_HITL_SFT_v4_B.pqr[0] = 0.0;
    modello_HITL_SFT_v4_B.pqr[1] = 0.0;
    modello_HITL_SFT_v4_B.pqr[2] = 0.0;
    modello_HITL_SFT_v4_B.Timone = 0.0;
    modello_HITL_SFT_v4_B.deltaR = 0.0;
    modello_HITL_SFT_v4_B.Timone_l = 0.0;
    modello_HITL_SFT_v4_B.deltaR_i = 0.0;
    modello_HITL_SFT_v4_B.deltaR_d = 0.0;
    modello_HITL_SFT_v4_B.Product_f = 0.0;
    modello_HITL_SFT_v4_B.Alettoni = 0.0;
    modello_HITL_SFT_v4_B.deltaA = 0.0;
    modello_HITL_SFT_v4_B.Alettoni_p = 0.0;
    modello_HITL_SFT_v4_B.deltaA_g = 0.0;
    modello_HITL_SFT_v4_B.deltaA_gw = 0.0;
    modello_HITL_SFT_v4_B.Product3 = 0.0;
    modello_HITL_SFT_v4_B.Sum_o = 0.0;
    modello_HITL_SFT_v4_B.uDLookupTable_g = 0.0;
    modello_HITL_SFT_v4_B.Gain1 = 0.0;
    modello_HITL_SFT_v4_B.Equilibratore = 0.0;
    modello_HITL_SFT_v4_B.deltaE = 0.0;
    modello_HITL_SFT_v4_B.Equilibratore_n = 0.0;
    modello_HITL_SFT_v4_B.deltaE_h = 0.0;
    modello_HITL_SFT_v4_B.deltaE_k = 0.0;
    modello_HITL_SFT_v4_B.Product4 = 0.0;
    modello_HITL_SFT_v4_B.Sum_h = 0.0;
    modello_HITL_SFT_v4_B.CL = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtMatrixMultiplyInport2[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtMatrixMultiplyInport2[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtMatrixMultiplyInport2[2] = 0.0;
    modello_HITL_SFT_v4_B.FA_Bq[0] = 0.0;
    modello_HITL_SFT_v4_B.FA_Bq[1] = 0.0;
    modello_HITL_SFT_v4_B.FA_Bq[2] = 0.0;
    modello_HITL_SFT_v4_B.Product_j = 0.0;
    modello_HITL_SFT_v4_B.Product1_i = 0.0;
    modello_HITL_SFT_v4_B.Product2_k = 0.0;
    modello_HITL_SFT_v4_B.Sum_e = 0.0;
    modello_HITL_SFT_v4_B.xeyeze[0] = 0.0;
    modello_HITL_SFT_v4_B.xeyeze[1] = 0.0;
    modello_HITL_SFT_v4_B.xeyeze[2] = 0.0;
    modello_HITL_SFT_v4_B.Gain_a = 0.0;
    modello_HITL_SFT_v4_B.Limitaltitudetotroposhere_n = 0.0;
    modello_HITL_SFT_v4_B.LapseRate_f = 0.0;
    modello_HITL_SFT_v4_B.Sum1_b = 0.0;
    modello_HITL_SFT_v4_B.uT0_m = 0.0;
    modello_HITL_SFT_v4_B.TT0gLR_m = 0.0;
    modello_HITL_SFT_v4_B.Product_d = 0.0;
    modello_HITL_SFT_v4_B.rho0 = 0.0;
    modello_HITL_SFT_v4_B.Sum_d = 0.0;
    modello_HITL_SFT_v4_B.LimitaltitudetoStratosphere_e = 0.0;
    modello_HITL_SFT_v4_B.gR_a = 0.0;
    modello_HITL_SFT_v4_B.Product1_j = 0.0;
    modello_HITL_SFT_v4_B.StratosphereModel_e = 0.0;
    modello_HITL_SFT_v4_B.Product3_c = 0.0;
    modello_HITL_SFT_v4_B.Product2_c = 0.0;
    modello_HITL_SFT_v4_B.u2rhoV2 = 0.0;
    modello_HITL_SFT_v4_B.Product_jt[0] = 0.0;
    modello_HITL_SFT_v4_B.Product_jt[1] = 0.0;
    modello_HITL_SFT_v4_B.Product_jt[2] = 0.0;
    modello_HITL_SFT_v4_B.uDLookupTable_h = 0.0;
    modello_HITL_SFT_v4_B.Gain4_p = 0.0;
    modello_HITL_SFT_v4_B.Product2_d = 0.0;
    modello_HITL_SFT_v4_B.Product3_f = 0.0;
    modello_HITL_SFT_v4_B.Sum_p = 0.0;
    modello_HITL_SFT_v4_B.Cl = 0.0;
    modello_HITL_SFT_v4_B.uDLookupTable_d = 0.0;
    modello_HITL_SFT_v4_B.Gain1_h = 0.0;
    modello_HITL_SFT_v4_B.Product2_kw = 0.0;
    modello_HITL_SFT_v4_B.Sum_g = 0.0;
    modello_HITL_SFT_v4_B.Cm = 0.0;
    modello_HITL_SFT_v4_B.uDLookupTable_l = 0.0;
    modello_HITL_SFT_v4_B.Product2_m = 0.0;
    modello_HITL_SFT_v4_B.Product3_fd = 0.0;
    modello_HITL_SFT_v4_B.Sum_lc = 0.0;
    modello_HITL_SFT_v4_B.Cn = 0.0;
    modello_HITL_SFT_v4_B.Product2_f[0] = 0.0;
    modello_HITL_SFT_v4_B.Product2_f[1] = 0.0;
    modello_HITL_SFT_v4_B.Product2_f[2] = 0.0;
    modello_HITL_SFT_v4_B.Product3_j[0] = 0.0;
    modello_HITL_SFT_v4_B.Product3_j[1] = 0.0;
    modello_HITL_SFT_v4_B.Product3_j[2] = 0.0;
    modello_HITL_SFT_v4_B.UnitDelay = 0.0;
    modello_HITL_SFT_v4_B.RPMRPs = 0.0;
    modello_HITL_SFT_v4_B.MathFunction3 = 0.0;
    modello_HITL_SFT_v4_B.MathFunction_g = 0.0;
    modello_HITL_SFT_v4_B.Product1_d = 0.0;
    modello_HITL_SFT_v4_B.uDLookupTable_et = 0.0;
    modello_HITL_SFT_v4_B.Product2_h = 0.0;
    modello_HITL_SFT_v4_B.F[0] = 0.0;
    modello_HITL_SFT_v4_B.F[1] = 0.0;
    modello_HITL_SFT_v4_B.F[2] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o1_p[0] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o1_p[1] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o1_p[2] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o2_m[0] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o2_m[1] = 0.0;
    modello_HITL_SFT_v4_B.sincos_o2_m[2] = 0.0;
    modello_HITL_SFT_v4_B.phidot = 0.0;
    modello_HITL_SFT_v4_B.thetadot = 0.0;
    modello_HITL_SFT_v4_B.psidot = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtphithetapsiInport1[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtphithetapsiInport1[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtphithetapsiInport1[2] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1_k[0] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1_k[1] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1_k[2] = 0.0;
    modello_HITL_SFT_v4_B.Product_l[0] = 0.0;
    modello_HITL_SFT_v4_B.Product_l[1] = 0.0;
    modello_HITL_SFT_v4_B.Product_l[2] = 0.0;
    modello_HITL_SFT_v4_B.Reshape2_d[0] = 0.0;
    modello_HITL_SFT_v4_B.Reshape2_d[1] = 0.0;
    modello_HITL_SFT_v4_B.Reshape2_d[2] = 0.0;
    modello_HITL_SFT_v4_B.ixj = 0.0;
    modello_HITL_SFT_v4_B.jxk = 0.0;
    modello_HITL_SFT_v4_B.kxi = 0.0;
    modello_HITL_SFT_v4_B.ixk = 0.0;
    modello_HITL_SFT_v4_B.jxi = 0.0;
    modello_HITL_SFT_v4_B.kxj = 0.0;
    modello_HITL_SFT_v4_B.Sum_n[0] = 0.0;
    modello_HITL_SFT_v4_B.Sum_n[1] = 0.0;
    modello_HITL_SFT_v4_B.Sum_n[2] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1_d[0] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1_d[1] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1_d[2] = 0.0;
    modello_HITL_SFT_v4_B.Product_jg[0] = 0.0;
    modello_HITL_SFT_v4_B.Product_jg[1] = 0.0;
    modello_HITL_SFT_v4_B.Product_jg[2] = 0.0;
    modello_HITL_SFT_v4_B.Reshape2_o[0] = 0.0;
    modello_HITL_SFT_v4_B.Reshape2_o[1] = 0.0;
    modello_HITL_SFT_v4_B.Reshape2_o[2] = 0.0;
    modello_HITL_SFT_v4_B.uDLookupTable1 = 0.0;
    modello_HITL_SFT_v4_B.MathFunction2 = 0.0;
    modello_HITL_SFT_v4_B.MathFunction1_h = 0.0;
    modello_HITL_SFT_v4_B.Product3_o = 0.0;
    modello_HITL_SFT_v4_B.Gain_a3 = 0.0;
    modello_HITL_SFT_v4_B.Divide_e = 0.0;
    modello_HITL_SFT_v4_B.Gain1_b = 0.0;
    modello_HITL_SFT_v4_B.Divide1 = 0.0;
    modello_HITL_SFT_v4_B.Sum1_n[0] = 0.0;
    modello_HITL_SFT_v4_B.Sum1_n[1] = 0.0;
    modello_HITL_SFT_v4_B.Sum1_n[2] = 0.0;
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator_p = 0.0;
    modello_HITL_SFT_v4_B.Switch_g = 0.0;
    modello_HITL_SFT_v4_B.Sum3[0] = 0.0;
    modello_HITL_SFT_v4_B.Sum3[1] = 0.0;
    modello_HITL_SFT_v4_B.Sum3[2] = 0.0;
    modello_HITL_SFT_v4_B.Sum2_m[0] = 0.0;
    modello_HITL_SFT_v4_B.Sum2_m[1] = 0.0;
    modello_HITL_SFT_v4_B.Sum2_m[2] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1_m[0] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1_m[1] = 0.0;
    modello_HITL_SFT_v4_B.Reshape1_m[2] = 0.0;
    modello_HITL_SFT_v4_B.Product2_l[0] = 0.0;
    modello_HITL_SFT_v4_B.Product2_l[1] = 0.0;
    modello_HITL_SFT_v4_B.Product2_l[2] = 0.0;
    modello_HITL_SFT_v4_B.Reshape[0] = 0.0;
    modello_HITL_SFT_v4_B.Reshape[1] = 0.0;
    modello_HITL_SFT_v4_B.Reshape[2] = 0.0;
    modello_HITL_SFT_v4_B.F_m[0] = 0.0;
    modello_HITL_SFT_v4_B.F_m[1] = 0.0;
    modello_HITL_SFT_v4_B.F_m[2] = 0.0;
    modello_HITL_SFT_v4_B.Product_m[0] = 0.0;
    modello_HITL_SFT_v4_B.Product_m[1] = 0.0;
    modello_HITL_SFT_v4_B.Product_m[2] = 0.0;
    modello_HITL_SFT_v4_B.jxk_d = 0.0;
    modello_HITL_SFT_v4_B.kxi_o = 0.0;
    modello_HITL_SFT_v4_B.ixj_o = 0.0;
    modello_HITL_SFT_v4_B.kxj_j = 0.0;
    modello_HITL_SFT_v4_B.ixk_p = 0.0;
    modello_HITL_SFT_v4_B.jxi_k = 0.0;
    modello_HITL_SFT_v4_B.Sum_a[0] = 0.0;
    modello_HITL_SFT_v4_B.Sum_a[1] = 0.0;
    modello_HITL_SFT_v4_B.Sum_a[2] = 0.0;
    modello_HITL_SFT_v4_B.Sum_h2[0] = 0.0;
    modello_HITL_SFT_v4_B.Sum_h2[1] = 0.0;
    modello_HITL_SFT_v4_B.Sum_h2[2] = 0.0;
    modello_HITL_SFT_v4_B.UnitConversion_m = 0.0;
    modello_HITL_SFT_v4_B.Gain1_k = 0.0;
    modello_HITL_SFT_v4_B.Product_c = 0.0;
    modello_HITL_SFT_v4_B.Product1_l[0] = 0.0;
    modello_HITL_SFT_v4_B.Product1_l[1] = 0.0;
    modello_HITL_SFT_v4_B.Product1_l[2] = 0.0;
    modello_HITL_SFT_v4_B.Gain_c = 0.0;
    modello_HITL_SFT_v4_B.SFunction_o1 = 0.0;
    modello_HITL_SFT_v4_B.SFunction_o2 = 0.0;
    modello_HITL_SFT_v4_B.Divide_a = 0.0;
    modello_HITL_SFT_v4_B.Gain_o = 0.0;
    modello_HITL_SFT_v4_B.Gain1_g = 0.0;
    modello_HITL_SFT_v4_B.Sum2_g = 0.0;
    modello_HITL_SFT_v4_B.Manetta = 0.0;
    modello_HITL_SFT_v4_B.Saturation_b = 0.0;
    modello_HITL_SFT_v4_B.LUTMOTORE = 0.0;
    modello_HITL_SFT_v4_B.Fcn = 0.0;
    modello_HITL_SFT_v4_B.RPsrads = 0.0;
    modello_HITL_SFT_v4_B.u_h = 0.0;
    modello_HITL_SFT_v4_B.rPG[0] = 0.0;
    modello_HITL_SFT_v4_B.rPG[1] = 0.0;
    modello_HITL_SFT_v4_B.rPG[2] = 0.0;
    modello_HITL_SFT_v4_B.rLEG[0] = 0.0;
    modello_HITL_SFT_v4_B.rLEG[1] = 0.0;
    modello_HITL_SFT_v4_B.rLEG[2] = 0.0;
    modello_HITL_SFT_v4_B.rACwG[0] = 0.0;
    modello_HITL_SFT_v4_B.rACwG[1] = 0.0;
    modello_HITL_SFT_v4_B.rACwG[2] = 0.0;
    modello_HITL_SFT_v4_B.rACtG[0] = 0.0;
    modello_HITL_SFT_v4_B.rACtG[1] = 0.0;
    modello_HITL_SFT_v4_B.rACtG[2] = 0.0;
    modello_HITL_SFT_v4_B.rNPG[0] = 0.0;
    modello_HITL_SFT_v4_B.rNPG[1] = 0.0;
    modello_HITL_SFT_v4_B.rNPG[2] = 0.0;
    modello_HITL_SFT_v4_B.Jeng = 0.0;
    modello_HITL_SFT_v4_B.Jprop = 0.0;
    modello_HITL_SFT_v4_B.Rprop = 0.0;
    modello_HITL_SFT_v4_B.b = 0.0;
    modello_HITL_SFT_v4_B.c = 0.0;
    modello_HITL_SFT_v4_B.P0_n = 0.0;
    modello_HITL_SFT_v4_B.Product2_fr = 0.0;
    modello_HITL_SFT_v4_B.gammaR = 0.0;
    modello_HITL_SFT_v4_B.a = 0.0;
    modello_HITL_SFT_v4_B.Product_k[0] = 0.0;
    modello_HITL_SFT_v4_B.Product_k[1] = 0.0;
    modello_HITL_SFT_v4_B.Product_k[2] = 0.0;
    modello_HITL_SFT_v4_B.Sum1_d[0] = 0.0;
    modello_HITL_SFT_v4_B.Sum1_d[1] = 0.0;
    modello_HITL_SFT_v4_B.Sum1_d[2] = 0.0;
    modello_HITL_SFT_v4_B.Sum_dn[0] = 0.0;
    modello_HITL_SFT_v4_B.Sum_dn[1] = 0.0;
    modello_HITL_SFT_v4_B.Sum_dn[2] = 0.0;
    modello_HITL_SFT_v4_B.Gain_fl = 0.0;
    modello_HITL_SFT_v4_B.UnitConversion_gt = 0.0;
    modello_HITL_SFT_v4_B.Sum_i = 0.0;
    modello_HITL_SFT_v4_B.Product4_p = 0.0;
    modello_HITL_SFT_v4_B.Product1_o = 0.0;
    modello_HITL_SFT_v4_B.TrigonometricFunction = 0.0;
    modello_HITL_SFT_v4_B.Sum1_a = 0.0;
    modello_HITL_SFT_v4_B.Product2_i = 0.0;
    modello_HITL_SFT_v4_B.Sum2_e = 0.0;
    modello_HITL_SFT_v4_B.Product3_p = 0.0;
    modello_HITL_SFT_v4_B.sqrt_n = 0.0;
    modello_HITL_SFT_v4_B.Sum_j = 0.0;
    modello_HITL_SFT_v4_B.Sum1_ba = 0.0;
    modello_HITL_SFT_v4_B.VnRmh = 0.0;
    modello_HITL_SFT_v4_B.cosphi = 0.0;
    modello_HITL_SFT_v4_B.VeRnhcosphi = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtPositionIntegrator2Inport1[0] =
      0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtPositionIntegrator2Inport1[1] =
      0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtPositionIntegrator2Inport1[2] =
      0.0;
    modello_HITL_SFT_v4_B.SFunction_o1_j = 0.0;
    modello_HITL_SFT_v4_B.SFunction_o2_i = 0.0;
    modello_HITL_SFT_v4_B.Divide1_k = 0.0;
    modello_HITL_SFT_v4_B.Gain1_hj = 0.0;
    modello_HITL_SFT_v4_B.Product_e = 0.0;
    modello_HITL_SFT_v4_B.Add_b = 0.0;
    modello_HITL_SFT_v4_B.Gain1_n = 0.0;
    modello_HITL_SFT_v4_B.SFunction_o1_k = 0.0;
    modello_HITL_SFT_v4_B.SFunction_o2_l = 0.0;
    modello_HITL_SFT_v4_B.Divide2_c = 0.0;
    modello_HITL_SFT_v4_B.Gain2 = 0.0;
    modello_HITL_SFT_v4_B.Product_m4 = 0.0;
    modello_HITL_SFT_v4_B.Add_m = 0.0;
    modello_HITL_SFT_v4_B.Gain1_m = 0.0;
    modello_HITL_SFT_v4_B.SFunction_o1_c = 0.0;
    modello_HITL_SFT_v4_B.SFunction_o2_d = 0.0;
    modello_HITL_SFT_v4_B.Divide3 = 0.0;
    modello_HITL_SFT_v4_B.Gain3_c = 0.0;
    modello_HITL_SFT_v4_B.Product_g = 0.0;
    modello_HITL_SFT_v4_B.Add_h = 0.0;
    modello_HITL_SFT_v4_B.Gain1_gb = 0.0;
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator3 = 0.0;
    modello_HITL_SFT_v4_B.Sum12 = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold9 = 0.0;
    modello_HITL_SFT_v4_B.Gain_k = 0.0;
    modello_HITL_SFT_v4_B.Saturation5 = 0.0;
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator4 = 0.0;
    modello_HITL_SFT_v4_B.Sum16 = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold10 = 0.0;
    modello_HITL_SFT_v4_B.Gain_l = 0.0;
    modello_HITL_SFT_v4_B.Saturation6 = 0.0;
    modello_HITL_SFT_v4_B.DiscreteTimeIntegrator5 = 0.0;
    modello_HITL_SFT_v4_B.Sum18 = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold11 = 0.0;
    modello_HITL_SFT_v4_B.Gain_b = 0.0;
    modello_HITL_SFT_v4_B.Saturation4 = 0.0;
    modello_HITL_SFT_v4_B.RandomNumber6 = 0.0;
    modello_HITL_SFT_v4_B.Sum23 = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold15 = 0.0;
    modello_HITL_SFT_v4_B.RandomNumber7 = 0.0;
    modello_HITL_SFT_v4_B.Sum14_c = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold16 = 0.0;
    modello_HITL_SFT_v4_B.RandomNumber8 = 0.0;
    modello_HITL_SFT_v4_B.Sum15 = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold17 = 0.0;
    modello_HITL_SFT_v4_B.RandomNumber3 = 0.0;
    modello_HITL_SFT_v4_B.Sum20 = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold12 = 0.0;
    modello_HITL_SFT_v4_B.RandomNumber4 = 0.0;
    modello_HITL_SFT_v4_B.Sum21 = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold13 = 0.0;
    modello_HITL_SFT_v4_B.RandomNumber5 = 0.0;
    modello_HITL_SFT_v4_B.Sum22 = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold14 = 0.0;
    modello_HITL_SFT_v4_B.Product_a = 0.0;
    modello_HITL_SFT_v4_B.rho0_m = 0.0;
    modello_HITL_SFT_v4_B.Product3_cn = 0.0;
    modello_HITL_SFT_v4_B.gammaR_f = 0.0;
    modello_HITL_SFT_v4_B.a_b = 0.0;
    modello_HITL_SFT_v4_B.UnitConversion_gp = 0.0;
    modello_HITL_SFT_v4_B.SFunction = 0.0;
    modello_HITL_SFT_v4_B.UnitConversion_ge = 0.0;
    modello_HITL_SFT_v4_B.Gain3_f = 0.0;
    modello_HITL_SFT_v4_B.RandomNumber = 0.0;
    modello_HITL_SFT_v4_B.Sum13_a = 0.0;
    modello_HITL_SFT_v4_B.Gain4_k = 0.0;
    modello_HITL_SFT_v4_B.RandomNumber1 = 0.0;
    modello_HITL_SFT_v4_B.Sum17 = 0.0;
    modello_HITL_SFT_v4_B.Gain5_a = 0.0;
    modello_HITL_SFT_v4_B.RandomNumber2 = 0.0;
    modello_HITL_SFT_v4_B.Sum19 = 0.0;
    modello_HITL_SFT_v4_B.Gain_l4 = 0.0;
    modello_HITL_SFT_v4_B.WhiteNoiseLat = 0.0;
    modello_HITL_SFT_v4_B.Sum_gh = 0.0;
    modello_HITL_SFT_v4_B.Gain_ai = 0.0;
    modello_HITL_SFT_v4_B.WhiteNoise = 0.0;
    modello_HITL_SFT_v4_B.Sum_ic = 0.0;
    modello_HITL_SFT_v4_B.Cos1 = 0.0;
    modello_HITL_SFT_v4_B.V_n = 0.0;
    modello_HITL_SFT_v4_B.Sin1 = 0.0;
    modello_HITL_SFT_v4_B.V_e = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold2_m = 0.0;
    modello_HITL_SFT_v4_B.ZeroOrderHold3 = 0.0;
    modello_HITL_SFT_v4_B.deltaP = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport4[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport4[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport4[2] = 0.0;
    modello_HITL_SFT_v4_B.h_lidar = 0.0;
    modello_HITL_SFT_v4_B.y = 0.0;
    modello_HITL_SFT_v4_B.K = 0.0;
    modello_HITL_SFT_v4_B.C = 0.0;
    modello_HITL_SFT_v4_B.y_p[0] = 0.0;
    modello_HITL_SFT_v4_B.y_p[1] = 0.0;
    modello_HITL_SFT_v4_B.y_p[2] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n[1] = 0.0;
    modello_HITL_SFT_v4_B.y_m = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ny[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ny[1] = 0.0;
    modello_HITL_SFT_v4_B.y_j = 0.0;
    modello_HITL_SFT_v4_B.module = 0.0;
    modello_HITL_SFT_v4_B.Fgear[0] = 0.0;
    modello_HITL_SFT_v4_B.Fgear[1] = 0.0;
    modello_HITL_SFT_v4_B.Fgear[2] = 0.0;
    modello_HITL_SFT_v4_B.Mgear[0] = 0.0;
    modello_HITL_SFT_v4_B.Mgear[1] = 0.0;
    modello_HITL_SFT_v4_B.Mgear[2] = 0.0;
    modello_HITL_SFT_v4_B.diffRm = 0.0;
    modello_HITL_SFT_v4_B.Ds = 0.0;
    modello_HITL_SFT_v4_B.Drm = 0.0;
    modello_HITL_SFT_v4_B.Dlm = 0.0;
    modello_HITL_SFT_v4_B.Fss = 0.0;
    modello_HITL_SFT_v4_B.Frms = 0.0;
    modello_HITL_SFT_v4_B.Flms = 0.0;
    modello_HITL_SFT_v4_B.Fsd = 0.0;
    modello_HITL_SFT_v4_B.Frmd = 0.0;
    modello_HITL_SFT_v4_B.Flmd = 0.0;
    modello_HITL_SFT_v4_B.Ns = 0.0;
    modello_HITL_SFT_v4_B.Nrm = 0.0;
    modello_HITL_SFT_v4_B.Nlm = 0.0;
    modello_HITL_SFT_v4_B.Ntot = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[2] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_b[3] = 0.0;
    modello_HITL_SFT_v4_B.y_c = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[2] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_a[3] = 0.0;
    modello_HITL_SFT_v4_B.y_l = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[2] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_k[3] = 0.0;
    modello_HITL_SFT_v4_B.y_g = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[2] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_c[3] = 0.0;
    modello_HITL_SFT_v4_B.y_o = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[2] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_n4[3] = 0.0;
    modello_HITL_SFT_v4_B.y_k = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[2] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_p[3] = 0.0;
    modello_HITL_SFT_v4_B.y_g1 = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[2] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_ks[3] = 0.0;
    modello_HITL_SFT_v4_B.y_b = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[0] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[1] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[2] = 0.0;
    modello_HITL_SFT_v4_B.TmpSignalConversionAtSFunctionInport1_g[3] = 0.0;
    modello_HITL_SFT_v4_B.y_gq = 0.0;
    modello_HITL_SFT_v4_B.sf_MATLABFunction_o.K = 0.0;
    modello_HITL_SFT_v4_B.sf_MATLABFunction_o.C = 0.0;
    modello_HITL_SFT_v4_B.sf_MATLABFunction_i.K = 0.0;
    modello_HITL_SFT_v4_B.sf_MATLABFunction_i.C = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&modello_HITL_SFT_v4_X, 0,
                  sizeof(X_modello_HITL_SFT_v4_T));
  }

  /* Periodic continuous states */
  {
    (void) memset((void*) modello_HITL_SFT_v4_PeriodicIndX, 0,
                  3*sizeof(int_T));
    (void) memset((void*) modello_HITL_SFT_v4_PeriodicRngX, 0,
                  6*sizeof(real_T));
  }

  /* states (dwork) */
  (void) memset((void *)&modello_HITL_SFT_v4_DW, 0,
                sizeof(DW_modello_HITL_SFT_v4_T));
  modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
  modello_HITL_SFT_v4_DW.UnitDelay_DSTATE = 0.0;
  modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_i = 0.0;
  modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator3_DSTATE = 0.0;
  modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator4_DSTATE = 0.0;
  modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator5_DSTATE = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput = 0.0;
  modello_HITL_SFT_v4_DW.RateTransition_Buffer = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_p = 0.0;
  modello_HITL_SFT_v4_DW.RateTransition1_Buffer = 0.0;
  modello_HITL_SFT_v4_DW.RateTransition2_Buffer = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_c = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_m = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_d = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_c2 = 0.0;

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_DW.Product2_DWORK1[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_DW.Product2_DWORK3[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_DW.Product2_DWORK4[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      modello_HITL_SFT_v4_DW.Product2_DWORK5[i] = 0.0;
    }
  }

  modello_HITL_SFT_v4_DW.NextOutput_n = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_b = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_h = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_na = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_o = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_a = 0.0;

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      modello_HITL_SFT_v4_DW.SFunction_temp_table[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      modello_HITL_SFT_v4_DW.SFunction_pres_table[i] = 0.0;
    }
  }

  modello_HITL_SFT_v4_DW.NextOutput_i = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_e = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_or = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_as = 0.0;
  modello_HITL_SFT_v4_DW.NextOutput_f = 0.0;

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    modello_HITL_SFT_v4_rti_init_trc_pointers();
  }

  /* Start for S-Function (rti_commonblock): '<S6>/S-Function2' */

  /* dSPACE I/O Board DS2101 #1 Unit:DAC Group:CHANNEL2 */
  ds2101_out(DS2101_1_BASE, 2, 0);

  /* Start for S-Function (outputStream_v1): '<Root>/S-Function Builder1' */

  /* S-Function Block: <Root>/S-Function Builder1 */
  outputStream_v1_Start_wrapper();

  /* Start for S-Function (SImulate_messageGPS_nmea_carriage_return): '<S108>/S-Function Builder1' */

  /* S-Function Block: <S108>/S-Function Builder1 */
  SImulate_messageGPS_nmea_carriage_return_Start_wrapper();

  /* Start for S-Function (saeropalt): '<S110>/S-Function' */
  {
    real_T *temp_table = (real_T *)
      &modello_HITL_SFT_v4_DW.SFunction_temp_table[0];
    real_T *pres_table = (real_T *)
      &modello_HITL_SFT_v4_DW.SFunction_pres_table[0];
    InitCalcAtmosCOESA( temp_table, pres_table );
  }

  {
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for Integrator: '<S26>/ub,vb,wb' */
    modello_HITL_SFT_v4_X.ubvbwb_CSTATE[0] = modello_HITL_SFT_v4_P.State0.Vb0[0];
    modello_HITL_SFT_v4_X.ubvbwb_CSTATE[1] = modello_HITL_SFT_v4_P.State0.Vb0[1];
    modello_HITL_SFT_v4_X.ubvbwb_CSTATE[2] = modello_HITL_SFT_v4_P.State0.Vb0[2];

    /* InitializeConditions for RandomNumber: '<S19>/White_press' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_baro);
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

    modello_HITL_SFT_v4_DW.RandSeed = tseed;
    modello_HITL_SFT_v4_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed) * sqrt
      (modello_HITL_SFT_v4_P.White_pressione) +
      modello_HITL_SFT_v4_P.White_press_Mean;

    /* End of InitializeConditions for RandomNumber: '<S19>/White_press' */

    /* InitializeConditions for Integrator: '<S83>/Position Integrator2' */
    modello_HITL_SFT_v4_X.PositionIntegrator2_CSTATE[0] =
      modello_HITL_SFT_v4_P.PositionIntegrator2_IC[0];
    modello_HITL_SFT_v4_X.PositionIntegrator2_CSTATE[1] =
      modello_HITL_SFT_v4_P.PositionIntegrator2_IC[1];
    modello_HITL_SFT_v4_X.PositionIntegrator2_CSTATE[2] =
      modello_HITL_SFT_v4_P.PositionIntegrator2_IC[2];

    /* InitializeConditions for RandomNumber: '<S19>/White Noise4' */
    tmp = floor(modello_HITL_SFT_v4_P.WhiteNoise4_Seed);
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

    modello_HITL_SFT_v4_DW.RandSeed_i = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_i) *
      modello_HITL_SFT_v4_P.WhiteNoise4_StdDev +
      modello_HITL_SFT_v4_P.WhiteNoise4_Mean;

    /* End of InitializeConditions for RandomNumber: '<S19>/White Noise4' */

    /* InitializeConditions for Integrator: '<S36>/phi theta psi' */
    modello_HITL_SFT_v4_X.phithetapsi_CSTATE[0] =
      modello_HITL_SFT_v4_P.State0.PHI0[0];
    modello_HITL_SFT_v4_X.phithetapsi_CSTATE[1] =
      modello_HITL_SFT_v4_P.State0.PHI0[1];
    modello_HITL_SFT_v4_X.phithetapsi_CSTATE[2] =
      modello_HITL_SFT_v4_P.State0.PHI0[2];

    /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE =
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S123>/Discrete-Time Integrator' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_n =
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator_IC_p;

    /* InitializeConditions for RandomNumber: '<S124>/Noise V_hor' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_gps);
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

    modello_HITL_SFT_v4_DW.RandSeed_f = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_f) *
      modello_HITL_SFT_v4_P.NoiseV_hor_StdDev +
      modello_HITL_SFT_v4_P.NoiseV_hor_Mean;

    /* End of InitializeConditions for RandomNumber: '<S124>/Noise V_hor' */

    /* InitializeConditions for RandomNumber: '<S124>/noise terra V_hor1' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_gps);
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

    modello_HITL_SFT_v4_DW.RandSeed_j = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_m = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_j) * sqrt
      (modello_HITL_SFT_v4_P.Var_V_hor_static) +
      modello_HITL_SFT_v4_P.noiseterraV_hor1_Mean;

    /* End of InitializeConditions for RandomNumber: '<S124>/noise terra V_hor1' */

    /* InitializeConditions for RandomNumber: '<S124>/Rumore bianco' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_gps);
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

    modello_HITL_SFT_v4_DW.RandSeed_d = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_d = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_d) *
      modello_HITL_SFT_v4_P.Rumorebianco_StdDev +
      modello_HITL_SFT_v4_P.Rumorebianco_Mean;

    /* End of InitializeConditions for RandomNumber: '<S124>/Rumore bianco' */

    /* InitializeConditions for RandomNumber: '<S124>/Noise terra course' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_gps);
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

    modello_HITL_SFT_v4_DW.RandSeed_h = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_c2 = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_h) * sqrt
      (modello_HITL_SFT_v4_P.Var_heading_static) +
      modello_HITL_SFT_v4_P.Noiseterracourse_Mean;

    /* End of InitializeConditions for RandomNumber: '<S124>/Noise terra course' */

    /* InitializeConditions for StateSpace: '<S2>/State-Space2' */
    modello_HITL_SFT_v4_X.StateSpace2_CSTATE = modello_HITL_SFT_v4_P.State0.Rud0;

    /* InitializeConditions for StateSpace: '<S3>/State-Space2' */
    modello_HITL_SFT_v4_X.StateSpace2_CSTATE_b =
      modello_HITL_SFT_v4_P.State0.Ele0;

    /* InitializeConditions for StateSpace: '<S2>/State-Space1' */
    modello_HITL_SFT_v4_X.StateSpace1_CSTATE = modello_HITL_SFT_v4_P.State0.Ail0;

    /* InitializeConditions for StateSpace: '<S3>/State-Space1' */
    modello_HITL_SFT_v4_X.StateSpace1_CSTATE_b =
      modello_HITL_SFT_v4_P.State0.Ele0;

    /* InitializeConditions for StateSpace: '<S2>/State-Space' */
    modello_HITL_SFT_v4_X.StateSpace_CSTATE = modello_HITL_SFT_v4_P.State0.Ele0;

    /* InitializeConditions for StateSpace: '<S3>/State-Space' */
    modello_HITL_SFT_v4_X.StateSpace_CSTATE_p =
      modello_HITL_SFT_v4_P.State0.Ele0;

    /* InitializeConditions for Integrator: '<S26>/p,q,r ' */
    modello_HITL_SFT_v4_X.pqr_CSTATE[0] = modello_HITL_SFT_v4_P.State0.Omega0[0];

    /* InitializeConditions for Integrator: '<S26>/xe,ye,ze' */
    modello_HITL_SFT_v4_X.xeyeze_CSTATE[0] = modello_HITL_SFT_v4_P.State0.Pos0[0];

    /* InitializeConditions for Integrator: '<S26>/p,q,r ' */
    modello_HITL_SFT_v4_X.pqr_CSTATE[1] = modello_HITL_SFT_v4_P.State0.Omega0[1];

    /* InitializeConditions for Integrator: '<S26>/xe,ye,ze' */
    modello_HITL_SFT_v4_X.xeyeze_CSTATE[1] = modello_HITL_SFT_v4_P.State0.Pos0[1];

    /* InitializeConditions for Integrator: '<S26>/p,q,r ' */
    modello_HITL_SFT_v4_X.pqr_CSTATE[2] = modello_HITL_SFT_v4_P.State0.Omega0[2];

    /* InitializeConditions for Integrator: '<S26>/xe,ye,ze' */
    modello_HITL_SFT_v4_X.xeyeze_CSTATE[2] = modello_HITL_SFT_v4_P.State0.Pos0[2];

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
    modello_HITL_SFT_v4_DW.UnitDelay_DSTATE = modello_HITL_SFT_v4_P.deltaTtrim *
      7400.0;

    /* InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator_DSTATE_i =
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator_IC_b;

    /* InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator3' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator3_DSTATE =
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator3_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator4' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator4_DSTATE =
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator4_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' */
    modello_HITL_SFT_v4_DW.DiscreteTimeIntegrator5_DSTATE =
      modello_HITL_SFT_v4_P.DiscreteTimeIntegrator5_IC;

    /* InitializeConditions for RandomNumber: '<S117>/Random Number6' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_ahrs);
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

    modello_HITL_SFT_v4_DW.RandSeed_l = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_l) * sqrt(modello_HITL_SFT_v4_P.White_p)
      + modello_HITL_SFT_v4_P.mean_p;

    /* End of InitializeConditions for RandomNumber: '<S117>/Random Number6' */

    /* InitializeConditions for RandomNumber: '<S117>/Random Number7' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_ahrs);
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

    modello_HITL_SFT_v4_DW.RandSeed_js = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_b = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_js) * sqrt(modello_HITL_SFT_v4_P.White_q)
      + modello_HITL_SFT_v4_P.mean_q;

    /* End of InitializeConditions for RandomNumber: '<S117>/Random Number7' */

    /* InitializeConditions for RandomNumber: '<S117>/Random Number8' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_ahrs);
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

    modello_HITL_SFT_v4_DW.RandSeed_hb = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_h = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_hb) * sqrt(modello_HITL_SFT_v4_P.White_r)
      + modello_HITL_SFT_v4_P.mean_r;

    /* End of InitializeConditions for RandomNumber: '<S117>/Random Number8' */

    /* InitializeConditions for RandomNumber: '<S117>/Random Number3' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_ahrs);
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

    modello_HITL_SFT_v4_DW.RandSeed_e = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_na = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_e) * sqrt(modello_HITL_SFT_v4_P.White_ax)
      + modello_HITL_SFT_v4_P.mean_ax;

    /* End of InitializeConditions for RandomNumber: '<S117>/Random Number3' */

    /* InitializeConditions for RandomNumber: '<S117>/Random Number4' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_ahrs);
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

    modello_HITL_SFT_v4_DW.RandSeed_le = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_o = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_le) * sqrt
      (modello_HITL_SFT_v4_P.White_ay) + modello_HITL_SFT_v4_P.mean_ay;

    /* End of InitializeConditions for RandomNumber: '<S117>/Random Number4' */

    /* InitializeConditions for RandomNumber: '<S117>/Random Number5' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_ahrs);
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

    modello_HITL_SFT_v4_DW.RandSeed_d0 = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_a = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_d0) * sqrt
      (modello_HITL_SFT_v4_P.White_az) + modello_HITL_SFT_v4_P.mean_az;

    /* End of InitializeConditions for RandomNumber: '<S117>/Random Number5' */

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
    for (i = 0; i < 41; i++) {
      modello_HITL_SFT_v4_DW.RateTransition_Buffer0[i] =
        modello_HITL_SFT_v4_P.RateTransition_InitialCondition;
    }

    modello_HITL_SFT_v4_DW.RateTransition_write_buf = -1;
    modello_HITL_SFT_v4_DW.RateTransition_read_buf = -1;

    /* End of InitializeConditions for RateTransition: '<Root>/Rate Transition' */

    /* InitializeConditions for RandomNumber: '<S117>/Random Number' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_ahrs);
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

    modello_HITL_SFT_v4_DW.RandSeed_ej = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_i = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_ej) * sqrt
      (modello_HITL_SFT_v4_P.White_gm_phi) +
      modello_HITL_SFT_v4_P.RandomNumber_Mean;

    /* End of InitializeConditions for RandomNumber: '<S117>/Random Number' */

    /* InitializeConditions for RandomNumber: '<S117>/Random Number1' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_ahrs);
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

    modello_HITL_SFT_v4_DW.RandSeed_ix = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_e = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_ix) * sqrt
      (modello_HITL_SFT_v4_P.White_gm_theta) +
      modello_HITL_SFT_v4_P.RandomNumber1_Mean;

    /* End of InitializeConditions for RandomNumber: '<S117>/Random Number1' */

    /* InitializeConditions for RandomNumber: '<S117>/Random Number2' */
    tmp = floor(modello_HITL_SFT_v4_P.seed_ahrs);
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

    modello_HITL_SFT_v4_DW.RandSeed_n = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_or = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_n) * sqrt
      (modello_HITL_SFT_v4_P.White_gm_psi) +
      modello_HITL_SFT_v4_P.RandomNumber2_Mean;

    /* End of InitializeConditions for RandomNumber: '<S117>/Random Number2' */

    /* InitializeConditions for RandomNumber: '<S122>/White Noise Lat' */
    tmp = floor(modello_HITL_SFT_v4_P.WhiteNoiseLat_Seed);
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

    modello_HITL_SFT_v4_DW.RandSeed_o = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_as = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_o) *
      modello_HITL_SFT_v4_P.WhiteNoiseLat_StdDev +
      modello_HITL_SFT_v4_P.WhiteNoiseLat_Mean;

    /* End of InitializeConditions for RandomNumber: '<S122>/White Noise Lat' */

    /* InitializeConditions for RandomNumber: '<S123>/White Noise' */
    tmp = floor(modello_HITL_SFT_v4_P.WhiteNoise_Seed);
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

    modello_HITL_SFT_v4_DW.RandSeed_ou = tseed;
    modello_HITL_SFT_v4_DW.NextOutput_f = rt_nrand_Upu32_Yd_f_pw_snf
      (&modello_HITL_SFT_v4_DW.RandSeed_ou) *
      modello_HITL_SFT_v4_P.WhiteNoise_StdDev +
      modello_HITL_SFT_v4_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S123>/White Noise' */

    /* InitializeConditions for root-level periodic continuous states */
    {
      int_T rootPeriodicContStateIndices[3] = { 6, 7, 8 };

      real_T rootPeriodicContStateRanges[6] = { -3.1415926535897931,
        3.1415926535897931, -3.1415926535897931, 3.1415926535897931,
        -3.1415926535897931, 3.1415926535897931 };

      (void) memcpy((void*)modello_HITL_SFT_v4_PeriodicIndX,
                    rootPeriodicContStateIndices,
                    3*sizeof(int_T));
      (void) memcpy((void*)modello_HITL_SFT_v4_PeriodicRngX,
                    rootPeriodicContStateRanges,
                    6*sizeof(real_T));
    }
  }
}

/* Model terminate function */
void modello_HITL_SFT_v4_terminate(void)
{
  /* Terminate for S-Function (outputStream_v1): '<Root>/S-Function Builder1' */

  /* S-Function Block: <Root>/S-Function Builder1 */
  outputStream_v1_Terminate_wrapper();

  /* Terminate for S-Function (SImulate_messageGPS_nmea_carriage_return): '<S108>/S-Function Builder1' */

  /* S-Function Block: <S108>/S-Function Builder1 */
  SImulate_messageGPS_nmea_carriage_return_Terminate_wrapper();

  /* Terminate for S-Function (rti_commonblock): '<S8>/S-Function1' */

  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS4201SER_B1_Ser[0]);
  dsser_fifo_reset(rtiDS4201SER_B1_Ser[0]);

  /* Terminate for S-Function (rti_commonblock): '<S9>/S-Function1' */

  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS4201SER_B1_Ser[1]);
  dsser_fifo_reset(rtiDS4201SER_B1_Ser[1]);

  /* Terminate for S-Function (rti_commonblock): '<S10>/S-Function1' */

  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS4201SER_B1_Ser[2]);
  dsser_fifo_reset(rtiDS4201SER_B1_Ser[2]);

  /* Terminate for S-Function (rti_commonblock): '<S11>/S-Function1' */

  /* dSPACE I/O Board DS4201SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS4201SER_B1_Ser[3]);
  dsser_fifo_reset(rtiDS4201SER_B1_Ser[3]);
}
