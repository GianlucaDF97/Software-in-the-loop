

        /*
      * binsearch_u32d_prevIdx.c
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


  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

               
uint32_T binsearch_u32d_prevIdx(real_T u, const real_T bp[], uint32_T startIndex, uint32_T maxIndex)
{
    uint32_T bpIndex;
    uint32_T found;
    uint32_T iLeft;
    uint32_T iRght;
    /* Binary Search using Previous Index */
    bpIndex = startIndex;
    iLeft = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
        if (u < bp[bpIndex]) {
            iRght = bpIndex - 1U;
            bpIndex = ((bpIndex + iLeft) - 1U) >> 1U;
        } else if (u < bp[bpIndex + 1U]) {
            found = 1U;
        } else {
            iLeft = bpIndex + 1U;
            bpIndex = ((bpIndex + iRght) + 1U) >> 1U;
        }
    }
    return bpIndex;
}
      


  

  

  

  
