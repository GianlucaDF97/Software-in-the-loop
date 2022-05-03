#include "rtwtypes.h"
#include "multiword_types.h"
#include <string.h>
#include "mwmathutil.h"
#include "f_pred_F1B_UfNJrhoQ.h"

void f_pred_F1B_UfNJrhoQ(const real_T prediction[18], real_T a, real_T dt,
  real_T f[18])
{
  real_T f_tmp;
  f_tmp = a + prediction[2];
  f[0] = dt * prediction[3] / f_tmp + prediction[0];
  f[1] = dt * prediction[4] / (f_tmp * muDoubleScalarCos(prediction[0])) +
    prediction[1];
  f[2] = prediction[2] - dt * prediction[5];
  f[3] = prediction[6] * dt + prediction[3];
  f[4] = prediction[7] * dt + prediction[4];
  f[5] = prediction[8] * dt + prediction[5];
  memcpy(&f[6], &prediction[6], 12U * sizeof(real_T));
}
