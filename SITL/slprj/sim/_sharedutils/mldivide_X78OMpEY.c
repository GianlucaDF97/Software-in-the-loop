#include "rtwtypes.h"
#include "multiword_types.h"
#include <string.h>
#include "xgetrfs_6diCZfCG.h"
#include "mldivide_X78OMpEY.h"

void mldivide_X78OMpEY(const real_T A[121], const real_T B[198], real_T Y[198])
{
  real_T b_A[121];
  memcpy(&Y[0], &B[0], 198U * sizeof(real_T));
  memcpy(&b_A[0], &A[0], 121U * sizeof(real_T));
  xgetrfs_6diCZfCG(b_A, Y);
}
