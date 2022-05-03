

        /*
      * v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf.c
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



    

  
#include "rtwtypes.h"

#include "multiword_types.h"
              #include <stddef.h>
      
    

      #include "v2022_Modello_SITL_AENEA_2020b_acc_rt_TDelayUpdateTailOrGrowBuf.h"


  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

                    
      #ifndef __RTW_UTFREE__  
      extern void * utMalloc(size_t);
      extern void   utFree(void *); 
      #endif
      
      
  
    /* Buffer management routine for variable delay block */
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
int_T     *maxNewBufSzPtr)
    {
      
      int_T  testIdx;
      int_T  tail  = *tailPtr;
      int_T  bufSz = *bufSzPtr;
      real_T *tBuf = *tBufPtr;
      real_T *xBuf = (NULL); 
      
      int_T    numBuffer = 2;
      if (istransportdelay){
        numBuffer =3 ;
        xBuf= *xBufPtr;
      }
      
      /*    Get testIdx, the index of the second oldest data point and
      *    see if this is older than current sim time minus applied delay,
      *    used to see if we can move tail forward 
      */
      testIdx = (tail < (bufSz - 1)) ? (tail + 1) : 0;
      
      if ( (tMinusDelay <= tBuf[testIdx]) && !isfixedbuf) {
        int_T  j;
        real_T *tempT;
        real_T *tempU;
        real_T *tempX = (NULL);    
        
        real_T *uBuf     = *uBufPtr;
        int_T  newBufSz  = bufSz + 1024;
        
        if (newBufSz > *maxNewBufSzPtr) {
          *maxNewBufSzPtr = newBufSz; /* save for warning*/
        }
        
        tempU = (real_T*)utMalloc(numBuffer*newBufSz*sizeof(real_T));        
        
        if (tempU == (NULL)){
          return (false);
        }     
        tempT = tempU + newBufSz;
        if(istransportdelay) tempX = tempT + newBufSz;
        
        for (j = tail; j < bufSz; j++) {
          tempT[j - tail] = tBuf[j];
          tempU[j - tail] = uBuf[j];
          if (istransportdelay)  
          tempX[j - tail] = xBuf[j];
        }
        for (j = 0; j < tail; j++) {
          tempT[j + bufSz - tail] = tBuf[j];
          tempU[j + bufSz - tail] = uBuf[j];
          if (istransportdelay)  
          tempX[j + bufSz - tail] = xBuf[j];
        }
        
        if (*lastPtr> tail) 
        {
          *lastPtr -= tail;
        } else {
          *lastPtr += (bufSz - tail);
        }
        *tailPtr= 0;
        *headPtr = bufSz;
        
        utFree(uBuf);
        
        *bufSzPtr = newBufSz;
        *tBufPtr  = tempT;
        *uBufPtr  = tempU;
        if (istransportdelay) *xBufPtr  = tempX;
        
      }else {
        *tailPtr = testIdx; /* move tail forward */
      }
      
      return(true);      


    }
      


  

  

  

  
