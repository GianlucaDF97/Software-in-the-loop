#include "rtwtypes.h"
#include "multiword_types.h"
#include "diag_DZDfKIir.h"

void diag_DZDfKIir(const real_T v[324], real_T d[18])
{
  int32_T k;
  for (k = 0; k < 18; k++) {
    d[k] = v[18 * k + k];
  }
}
