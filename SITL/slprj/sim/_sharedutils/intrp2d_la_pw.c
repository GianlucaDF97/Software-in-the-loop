

        /*
      * intrp2d_la_pw.c
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
          

      #include "intrp2d_la_pw.h"


  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

               
real_T intrp2d_la_pw(const uint32_T bpIndex[], const real_T frac[], const real_T table[], const uint32_T stride, const uint32_T maxIndex[])
{
    real_T y;
    real_T yL_0d0;
    uint32_T offset_1d;
    /* Column-major Interpolation 2-D
   Interpolation method: 'Linear point-slope'
   Use last breakpoint for index at or above upper limit: 'on'
   Overflow mode: 'portable wrapping'
 */
    offset_1d = bpIndex[1U] * stride + bpIndex[0U];
    if (bpIndex[0U] == maxIndex[0U]) {
        y = table[offset_1d];
    } else {
        yL_0d0 = table[offset_1d];
        y = (table[offset_1d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
    }
    if (bpIndex[1U] == maxIndex[1U]) {
    } else {
        offset_1d += stride;
        if (bpIndex[0U] == maxIndex[0U]) {
            yL_0d0 = table[offset_1d];
        } else {
            yL_0d0 = table[offset_1d];
            yL_0d0 += (table[offset_1d + 1U] - yL_0d0) * frac[0U];
        }
        y += (yL_0d0 - y) * frac[1U];
    }
    return y;
}
      


  

  

  

  
