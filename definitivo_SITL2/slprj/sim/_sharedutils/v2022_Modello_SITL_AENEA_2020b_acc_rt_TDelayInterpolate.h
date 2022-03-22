

        /*
      * v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate.h
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
      * Created for block: <S217>/B_50_59
      */


  #ifndef RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate_h_
  #define RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate_h_
  

    

        #include "rtwtypes.h"
        #include "multiword_types.h"



  

  

  

  

  

  

  

  

  

  

  

  

  

  

                      real_T v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate(
      real_T     tMinusDelay,           /* tMinusDelay = currentSimTime - delay */
      real_T     tStart,
      real_T     *tBuf,
      real_T     *uBuf,
      int_T      bufSz,
      int_T      *lastIdx,
      int_T      oldestIdx,
      int_T      newIdx,
      real_T     initOutput,
      boolean_T  discrete,
      boolean_T  minorStepAndTAtLastMajorOutput)
;

      

  

  

  

  

  

    #endif /* RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayInterpolate_h_ */
