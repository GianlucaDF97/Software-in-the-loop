#include "rtwtypes.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "xgetrf_kPxqlWXI.h"

void xgetrf_kPxqlWXI(real_T A[121], int32_T ipiv[11], int32_T *info)
{
  real_T smax;
  real_T y;
  int32_T c;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int32_T j;
  int32_T jA;
  for (j = 0; j < 11; j++) {
    ipiv[j] = j + 1;
  }

  *info = 0;
  for (j = 0; j < 10; j++) {
    c = j * 12;
    jA = 0;
    ix = c;
    smax = muDoubleScalarAbs(A[c]);
    for (iy = 2; iy <= 11 - j; iy++) {
      ix++;
      y = muDoubleScalarAbs(A[ix]);
      if (y > smax) {
        jA = iy - 1;
        smax = y;
      }
    }

    if (A[c + jA] != 0.0) {
      if (jA != 0) {
        iy = j + jA;
        ipiv[j] = iy + 1;
        ix = j;
        for (jA = 0; jA < 11; jA++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 11;
          iy += 11;
        }
      }

      jA = (c - j) + 11;
      for (ix = c + 1; ix < jA; ix++) {
        A[ix] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    jA = c;
    ix = c + 11;
    for (iy = 0; iy <= 9 - j; iy++) {
      if (A[ix] != 0.0) {
        smax = -A[ix];
        c_ix = c + 1;
        d = (jA - j) + 22;
        for (ijA = jA + 12; ijA < d; ijA++) {
          A[ijA] += A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 11;
      jA += 11;
    }
  }

  if ((*info == 0) && (!(A[120] != 0.0))) {
    *info = 11;
  }
}
