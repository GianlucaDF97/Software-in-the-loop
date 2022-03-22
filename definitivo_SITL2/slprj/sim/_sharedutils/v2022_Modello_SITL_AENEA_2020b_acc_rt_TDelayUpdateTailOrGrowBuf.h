

        /*
      * v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf.h
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


  #ifndef RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf_h_
  #define RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf_h_
  

    

        #include "rtwtypes.h"
        #include "multiword_types.h"



  

  

  

  

  

  

  

  

  

  

  

  

  

  

                  boolean_T  v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf(
int_T       *bufSzPtr,        /* in/out - circular buffer size                 */
int_T       *tailPtr,         /* in/out - tail of circular buffer              */
int_T       *headPtr,         /* in/out - head of circular buffer              */
int_T       *lastPtr,         /* in/out - same logical 'last' referenced index */
real_T      tMinusDelay,      /* in     - last point we are looking at   */
real_T      **tBufPtr,        /* in/out - larger buffer for time         */
real_T      **uBufPtr,        /* in/out - larger buffer for input        */
real_T      **xBufPtr,        /* in/out - larger buffer for state        */
boolean_T   isfixedbuf,       /* in     - fixed buffer size enable       */
boolean_T istransportdelay,   /* in     - block acts as transport dela y */
int_T     *maxNewBufSzPtr);

      

  

  

  

  

  

    #endif /* RTW_HEADER_v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf_h_ */
