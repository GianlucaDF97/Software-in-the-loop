
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */



#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */



/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void calc_T_Outputs_wrapper(const uint16_T *dig_T1,
			const int16_T *dig_T2,
			const int16_T *dig_T3,
			const int32_T *adc_T,
			real32_T *T,
			int32_T *t_fine)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */



long int var1  = ((((adc_T[0]>>3) - ((long int)dig_T1[0] <<1))) *
     ((long int)dig_T2[0])) >> 11;

 long int var2  = (((((adc_T[0]>>4) - ((long int )dig_T1[0])) *
       ((adc_T[0]>>4) - ((long int)dig_T1[0]))) >> 12) *
     ((long int)dig_T3[0])) >> 14;

t_fine[0] = var1 + var2;

  T[0]  = (t_fine[0] * 5 + 128) >> 8;
  T[0] = T[0]/100 ;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


