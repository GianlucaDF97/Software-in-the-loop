

        /*
      * rt_nrand_Upu32_Yd_f_pw_snf.c
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
              #include "mwmathutil.h"
      
        #include "rt_urand_Upu32_Yd_f_pw_snf.h"
      
    

      #include "rt_nrand_Upu32_Yd_f_pw_snf.h"


  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

                                  
          
    
    
        
     

               real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
    {
          real_T si;
real_T sr;
real_T y;





/* Normal (Gaussian) random number generator */
do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
} while (si > 1.0);
y = muDoubleScalarSqrt(-2.0 * muDoubleScalarLog(si) / si) * sr;
return y;


    }
      

      


  

  

  

  
