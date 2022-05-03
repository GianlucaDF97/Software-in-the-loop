#include "rtwtypes.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "measure_F1B_GBktGI3Q.h"

void measure_F1B_GBktGI3Q(const real_T stato[18], const real_T EULERO[3], real_T
  rx, real_T ry, real_T rz, real_T g, real_T Y[11])
{
  real_T Y_tmp;
  real_T Y_tmp_b;
  real_T Y_tmp_c;
  real_T Y_tmp_e;
  real_T Y_tmp_f;
  real_T Y_tmp_g;
  real_T Y_tmp_i;
  real_T Y_tmp_j;
  real_T Y_tmp_k;
  real_T Y_tmp_m;
  real_T Y_tmp_n;
  real_T Y_tmp_p;
  Y[0] = stato[0];
  Y[1] = stato[1];
  Y[2] = stato[2];
  Y_tmp = muDoubleScalarCos(EULERO[0]);
  Y_tmp_p = muDoubleScalarSin(EULERO[2]);
  Y_tmp_e = muDoubleScalarCos(EULERO[2]);
  Y_tmp_i = muDoubleScalarSin(EULERO[0]);
  Y_tmp_m = muDoubleScalarSin(EULERO[1]);
  Y_tmp_g = muDoubleScalarCos(EULERO[1]);
  Y_tmp_j = stato[9] * ry - stato[10] * rx;
  Y_tmp_c = stato[9] * rz - stato[11] * rx;
  Y_tmp_k = stato[10] * rz - stato[11] * ry;
  Y[3] = (((Y_tmp * Y_tmp_e * Y_tmp_m + Y_tmp_i * Y_tmp_p) * Y_tmp_j + stato[3])
          + (Y_tmp * Y_tmp_p - Y_tmp_e * Y_tmp_i * Y_tmp_m) * Y_tmp_c) + Y_tmp_k
    * (Y_tmp_e * Y_tmp_g);
  Y_tmp_f = muDoubleScalarCos(EULERO[0]) * muDoubleScalarSin(EULERO[2]);
  Y_tmp_n = muDoubleScalarCos(EULERO[2]) * muDoubleScalarSin(EULERO[0]);
  Y[4] = ((stato[4] - (Y_tmp_n - Y_tmp_f * Y_tmp_m) * Y_tmp_j) -
          (muDoubleScalarSin(EULERO[0]) * muDoubleScalarSin(EULERO[2]) * Y_tmp_m
           + Y_tmp_f) * Y_tmp_c) + Y_tmp_k * (Y_tmp_g * Y_tmp_p);
  Y_tmp_b = stato[8] - g;
  Y[5] = ((((stato[6] * Y_tmp_g * Y_tmp_e + stato[12]) + stato[7] * Y_tmp_g *
            Y_tmp_p) - Y_tmp_b * Y_tmp_m) + Y_tmp_j * stato[10]) + Y_tmp_c *
    stato[11];
  Y[6] = (((((muDoubleScalarCos(EULERO[2]) * muDoubleScalarSin(EULERO[0]) *
              muDoubleScalarSin(EULERO[1]) - Y_tmp_f) * stato[6] + stato[13]) +
            (muDoubleScalarSin(EULERO[0]) * muDoubleScalarSin(EULERO[2]) *
             muDoubleScalarSin(EULERO[1]) + muDoubleScalarCos(EULERO[0]) *
             muDoubleScalarCos(EULERO[2])) * stato[7]) + Y_tmp_g * Y_tmp_i *
           Y_tmp_b) - Y_tmp_j * stato[9]) + Y_tmp_k * stato[11];
  Y[7] = (((((muDoubleScalarCos(EULERO[0]) * muDoubleScalarCos(EULERO[2]) *
              muDoubleScalarSin(EULERO[1]) + muDoubleScalarSin(EULERO[0]) *
              muDoubleScalarSin(EULERO[2])) * stato[6] + stato[14]) +
            (muDoubleScalarCos(EULERO[0]) * muDoubleScalarSin(EULERO[2]) *
             muDoubleScalarSin(EULERO[1]) - Y_tmp_n) * stato[7]) + Y_tmp *
           Y_tmp_g * Y_tmp_b) - Y_tmp_c * stato[9]) - Y_tmp_k * stato[10];
  Y[8] = stato[15] + stato[9];
  Y[9] = stato[16] + stato[10];
  Y[10] = stato[17] + stato[11];
}
