

        /*
      * plook_bincpa.c
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
              #include "binsearch_u32d_prevIdx.h"
      
    

      #include "plook_bincpa.h"


  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

               
uint32_T plook_bincpa(real_T u, const real_T bp[], uint32_T maxIndex, real_T *fraction, uint32_T *prevIndex)
{
    uint32_T bpIndex;
    /* Prelookup - Index and Fraction
   Index Search method: 'binary'
   Extrapolation method: 'Clip'
   Use previous index: 'on'
   Use last breakpoint for index at or above upper limit: 'on'
   Remove protection against out-of-range input in generated code: 'off'
 */
    if (u <= bp[0U]) {
        bpIndex = 0U;
        *fraction = 0.0;
    } else if (u < bp[maxIndex]) {
        bpIndex = binsearch_u32d_prevIdx(u, bp, *prevIndex, maxIndex);
        *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
    } else {
        bpIndex = maxIndex;
        *fraction = 0.0;
    }
    *prevIndex = bpIndex;
    return bpIndex;
}
      


  

  

  

  
