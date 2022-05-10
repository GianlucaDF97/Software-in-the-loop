
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
#ifndef MATLAB_MEX_FILE
#include <Arduino.h>
#include <inttypes.h>
#include "DueFlashStorage_lib/DueFlashStorage.h"
#include "DueFlashStorage_lib/DueFlashStorage.cpp"
#include "DueFlashStorage_lib/efc.h"
#include "DueFlashStorage_lib/efc.cpp"
#include "DueFlashStorage_lib/flash_efc.h"
#include "DueFlashStorage_lib/flash_efc.cpp"


unsigned long start_time = 0; 
double pwm_manetta_neutro = 0;
double pwm_equilibratore_neutro = 0;
double pwm_alettoni_neutro = 0;
double pwm_timone_neutro = 0;
DueFlashStorage dueFlashStorage;
#endif
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
extern "C" void Radio_calibrating_Outputs_wrapper(const real_T *manetta,
			const real_T *equilibratore,
			const real_T *alettoni,
			const real_T *timone,
			const int8_T *cal_start,
			real_T *pwm_manetta_max,
			real_T *pwm_manetta_min,
			real_T *pwm_equilibratore_max,
			real_T *pwm_equilibratore_min,
			real_T *pwm_alettoni_max,
			real_T *pwm_alettoni_min,
			real_T *pwm_timone_max,
			real_T *pwm_timone_min,
			int8_T *proceed,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==1)
{
#ifndef MATLAB_MEX_FILE
int soglia = 3;    
if (cal_start[0] == 1)
{    
    /*proceed[0] =1;*/
if (proceed[0] == 0)    
{   
if ((abs(pwm_manetta_neutro - manetta[0]) > soglia) || (abs(pwm_equilibratore_neutro - equilibratore[0] > soglia)) || (abs(pwm_alettoni_neutro - alettoni[0]) > soglia) || (abs(pwm_timone_neutro - timone[0] ) > soglia)) 
{   
pwm_manetta_neutro = manetta[0];
pwm_equilibratore_neutro = equilibratore[0];
pwm_alettoni_neutro = alettoni[0];
pwm_timone_neutro = timone[0];
pwm_manetta_max[0] = pwm_manetta_neutro;
pwm_manetta_min[0] = pwm_manetta_neutro;
pwm_equilibratore_max[0] = pwm_equilibratore_neutro;
pwm_equilibratore_min[0] = pwm_equilibratore_neutro;
pwm_alettoni_max[0] = pwm_alettoni_neutro;
pwm_alettoni_min[0] = pwm_alettoni_neutro;
pwm_timone_max[0] = pwm_timone_neutro;
pwm_timone_min[0] = pwm_timone_neutro;  
start_time = millis();
}
if (millis()-start_time >= 10000) 
{  
proceed[0] = 1;   
start_time = millis();
}
}

    
if (proceed[0] == 1)   /*inizio fase calibrazione manetta max */
{   
if (pwm_manetta_max[0] < manetta[0]) 
{   
pwm_manetta_max[0] = manetta[0];
start_time = millis();
}
if (millis()-start_time >= 7000) 
{
dueFlashStorage.write(0,(int)(pwm_manetta_max[0]/10));   
proceed[0] = 2;   
start_time = millis();
}
}
else if (proceed[0] == 2)  /* inizio fase calibrazione manetta min */
{  
if (pwm_manetta_min[0] > manetta[0]) {   
pwm_manetta_min[0] = manetta[0];
start_time = millis();
}
if (millis()-start_time >= 7000) {
dueFlashStorage.write(1,(int)(pwm_manetta_min[0]/10));     
proceed[0] = 3;
start_time = millis();
}
}
else if (proceed[0] == 3) {   /* inizio fase calibrazione equilibratore max */
if (pwm_equilibratore_max[0] < equilibratore[0]) {   
pwm_equilibratore_max[0] = equilibratore[0];
start_time = millis();
}
if (millis()-start_time >= 7000){
dueFlashStorage.write(2,(int)(pwm_equilibratore_max[0]/10));     
proceed[0] = 4;  
start_time = millis();
}
}  
else if (proceed[0] == 4) {   /* inizio fase calibrazione equilibratore min */
if (pwm_equilibratore_min[0] > equilibratore[0]) {   
pwm_equilibratore_min[0] = equilibratore[0];
start_time = millis();
}
if (millis()-start_time >= 7000){
dueFlashStorage.write(3,(int)(pwm_equilibratore_min[0]/10));     
proceed[0] = 5;
start_time = millis();
}
}
else if (proceed[0] == 5) {   /* inizio fase calibrazione alettoni max */
if (pwm_alettoni_max[0] < alettoni[0]) {   
pwm_alettoni_max[0] = alettoni[0];
start_time = millis();
}
if (millis()-start_time >= 7000){
dueFlashStorage.write(4,(int)(pwm_alettoni_max[0]/10));     
proceed[0] = 6; 
start_time = millis();
}
}      
else if (proceed[0] == 6) {   /* inizio fase calibrazione alettoni min */
if (pwm_alettoni_min[0] > alettoni[0]) {   
pwm_alettoni_min[0] = alettoni[0];
start_time = millis();
}
if (millis()-start_time >= 7000){
dueFlashStorage.write(5,(int)(pwm_alettoni_min[0]/10));    
proceed[0] = 7;
start_time = millis();
}
}    
else if (proceed[0] == 7) {   /* inizio fase calibrazione timone max */
if (pwm_timone_max[0] < timone[0]) {   
pwm_timone_max[0] = timone[0];
start_time = millis();
}
if (millis()-start_time >= 7000){
dueFlashStorage.write(6,(int)(pwm_timone_max[0]/10));    
proceed[0] = 8;
start_time = millis();
}
}        
else if (proceed[0] == 8) {   /* inizio fase calibrazione timone min */
if (pwm_timone_min[0] > timone[0]) {   
pwm_timone_min[0] = timone[0];
start_time = millis();
}
if (millis()-start_time >= 7000){
dueFlashStorage.write(7,(int)(pwm_timone_min[0]/10));     
proceed[0] = 9;
start_time = 0;
}
}  
}
else {
 proceed[0] = 0;   
}
#endif
    
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void Radio_calibrating_Update_wrapper(const real_T *manetta,
			const real_T *equilibratore,
			const real_T *alettoni,
			const real_T *timone,
			const int8_T *cal_start,
			real_T *pwm_manetta_max,
			real_T *pwm_manetta_min,
			real_T *pwm_equilibratore_max,
			real_T *pwm_equilibratore_min,
			real_T *pwm_alettoni_max,
			real_T *pwm_alettoni_min,
			real_T *pwm_timone_max,
			real_T *pwm_timone_min,
			int8_T *proceed,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1)
{
#ifndef MATLAB_MEX_FILE   
proceed[0] = 0; 
pwm_manetta_max[0] = (double)(dueFlashStorage.read(0)*10);          // legge dalla memoria flash i valori salvati dei pwm, in questo modo non si cancellano dopo lo spegnimento/reset di arduino
pwm_manetta_min[0] = (double)(dueFlashStorage.read(1)*10);
pwm_equilibratore_max[0] = (double)(dueFlashStorage.read(2)*10);
pwm_equilibratore_min[0] = (double)(dueFlashStorage.read(3)*10);
pwm_alettoni_max[0] = (double)(dueFlashStorage.read(4)*10);
pwm_alettoni_min[0] = (double)(dueFlashStorage.read(5)*10);
pwm_timone_max[0] = (double)(dueFlashStorage.read(6)*10);
pwm_timone_min[0] = (double)(dueFlashStorage.read(7)*10);
#endif
xD[0] = 1;
    
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

