
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
void calc_p_Outputs_wrapper(const uint16_T *dig_p1,
			const int16_T *dig_p2,
			const int16_T *dig_p3,
			const int16_T *dig_p4,
			const int16_T *dig_p5,
			const int16_T *dig_p6,
			const int16_T *dig_p7,
			const int16_T *dig_p8,
			const int16_T *dig_p9,
			const int32_T *adc_P,
			const int32_T *t_fine,
			uint32_T *p)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
long int  var1, var2;

var1 = (((long int)t_fine[0])>>1) - (long int)64000;
var2 = (((var1>>2) * (var1>>2)) >> 11 ) * ((long int)dig_p6[0]);
var2 = var2 + ((var1*((long int)dig_p5[0]))<<1);
var2 = (var2>>2)+(((long int)dig_p4[0])<<16);
var1 = (((dig_p3[0] * (((var1>>2) * (var1>>2)) >> 13 )) >> 3) + ((((long int)dig_p2[0]) * var1)>>1))>>18;
var1 =((((32768+var1))*((long int)dig_p1[0]))>>15);
if (var1 == 0)
{
p[0] = 0; // avoid exception caused by division by zero
}
p[0] = (((unsigned long int)(((long int)1048576)-adc_P[0])-(var2>>12)))*3125;
if (p[0] < 0x80000000)
{
p[0] = (p[0] << 1) / ((unsigned long int)var1);
}
else
{
p[0] = (p[0] / (unsigned long int)var1) * 2;
}
var1 = (((long int)dig_p9[0]) * ((long int)(((p[0]>>3) * (p[0]>>3))>>13)))>>12;
var2 = (((long int)(p[0]>>2)) * ((long int)dig_p8[0]))>>13;
p[0] = (unsigned long int)((long int)p[0] + ((var1 + var2 + dig_p7[0]) >> 4));
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


