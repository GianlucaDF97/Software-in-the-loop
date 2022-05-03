#include "rtwtypes.h"
#include "multiword_types.h"
#include "xgetrf_kPxqlWXI.h"
#include "xgetrfs_6diCZfCG.h"

int32_T xgetrfs_6diCZfCG(real_T A[121], real_T B[198])
{
  real_T temp;
  int32_T ipiv[11];
  int32_T b_i;
  int32_T i;
  int32_T info;
  int32_T ip;
  int32_T j;
  int32_T kAcol;
  int32_T tmp;
  int32_T tmp_p;
  xgetrf_kPxqlWXI(A, ipiv, &info);
  for (i = 0; i < 10; i++) {
    ip = ipiv[i];
    if (i + 1 != ip) {
      for (j = 0; j < 18; j++) {
        kAcol = 11 * j + i;
        temp = B[kAcol];
        tmp = (ip + 11 * j) - 1;
        B[kAcol] = B[tmp];
        B[tmp] = temp;
      }
    }
  }

  for (i = 0; i < 18; i++) {
    ip = 11 * i;
    for (j = 0; j < 11; j++) {
      kAcol = 11 * j;
      tmp = j + ip;
      if (B[tmp] != 0.0) {
        for (b_i = j + 2; b_i < 12; b_i++) {
          tmp_p = (b_i + ip) - 1;
          B[tmp_p] -= A[(b_i + kAcol) - 1] * B[tmp];
        }
      }
    }
  }

  for (i = 0; i < 18; i++) {
    ip = 11 * i;
    for (j = 10; j >= 0; j--) {
      kAcol = 11 * j;
      tmp = j + ip;
      temp = B[tmp];
      if (temp != 0.0) {
        B[tmp] = temp / A[j + kAcol];
        for (b_i = 0; b_i < j; b_i++) {
          tmp_p = b_i + ip;
          B[tmp_p] -= B[tmp] * A[b_i + kAcol];
        }
      }
    }
  }

  return info;
}
