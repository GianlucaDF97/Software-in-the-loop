

        /*
      * rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf.c
      *
        * Academic License - for use in teaching, academic research, and meeting
* course requirements at degree granting institutions only.  Not for
* government, commercial, or other organizational use. 
  * 
  * Code generation for model "v2022_Modello_SITL_AENEA_2020b_acc".
  *
  * Model version              : 1.208
  * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
  * C source code generated on : Tue Mar 22 12:15:15 2022
      * Created for block: v2022_Modello_SITL_AENEA_2020b_acc
      */



    

  
#include "rtwtypes.h"

#include "multiword_types.h"
              #include <string.h>
      
        #include "mwmathutil.h"
      
    

      #include "rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf.h"


  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

                                  
          
    
    
        
     

               void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(const real_T u0[3], const real_T u1[9], real_T y[3])
    {
          real_T A[9];
real_T a21;
real_T maxval;
int32_T r1;
int32_T r2;
int32_T r3;
int32_T rtemp;
memcpy(&A[0], &u1[0], 9U * sizeof(real_T));
r1 = 1;
r2 = 2;
r3 = 3;
maxval = muDoubleScalarAbs(u1[0]);
a21 = muDoubleScalarAbs(u1[1]);
if (a21 > maxval) {
    maxval = a21;
    r1 = 2;
    r2 = 1;
}
if (muDoubleScalarAbs(u1[2]) > maxval) {
    r1 = 3;
    r2 = 2;
    r3 = 1;
}
A[r2 - 1] = u1[r2 - 1] / u1[r1 - 1];
A[r3 - 1] /= A[r1 - 1];
A[r2 + 2] -= A[r2 - 1] * A[r1 + 2];
A[r3 + 2] -= A[r3 - 1] * A[r1 + 2];
A[r2 + 5] -= A[r2 - 1] * A[r1 + 5];
A[r3 + 5] -= A[r3 - 1] * A[r1 + 5];
if (muDoubleScalarAbs(A[r3 + 2]) > muDoubleScalarAbs(A[r2 + 2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
}
A[r3 + 2] /= A[r2 + 2];
A[r3 + 5] -= A[r3 + 2] * A[r2 + 5];
y[r1 - 1] = u0[0] / A[r1 - 1];
y[r2 - 1] = u0[1] - y[r1 - 1] * A[r1 + 2];
y[r3 - 1] = u0[2] - y[r1 - 1] * A[r1 + 5];
y[r2 - 1] /= A[r2 + 2];
y[r3 - 1] -= y[r2 - 1] * A[r2 + 5];
y[r3 - 1] /= A[r3 + 5];
y[r2 - 1] -= y[r3 - 1] * A[r3 + 2];
y[r1 - 1] -= y[r3 - 1] * A[r3 - 1];
y[r1 - 1] -= y[r2 - 1] * A[r2 - 1];


    }
      

      


  

  

  

  
