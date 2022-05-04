
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
#include "clib\U8g2lib.h"
#include "clib\U8x8lib.h"
#include "clib\U8x8lib.cpp"
#include "clib\u8x8.h"
#include "clib\u8x8_u16toa.c"
#include "clib\u8x8_u8toa.c"
#include "clib\u8x8_string.c"
#include "clib\u8x8_setup.c"
#include "clib\u8x8_selection_list.c"
#include "clib\u8x8_message.c"
#include "clib\u8x8_input_value.c"
#include "clib\u8x8_gpio.c"
#include "clib\u8x8_fonts.c"
#include "clib\u8x8_display.c"
#include "clib\u8x8_debounce.c"
#include "clib\u8x8_d_ssd1306_128x64_noname.c"
#include "clib\u8x8_cad.c"
#include "clib\u8x8_byte.c"
#include "clib\u8x8_8x8.c"
#include "clib\u8log_u8x8.c"
#include "clib\u8log_u8g2.c"
#include "clib\u8log.c"
#include "clib\u8g2.h"
#include "clib\u8g2_setup.c"
#include "clib\u8g2_selection_list.c"
#include "clib\u8g2_polygon.c"
#include "clib\u8g2_message.c"
#include "clib\u8g2_ll_hvline.c"
#include "clib\u8g2_line.c"
#include "clib\u8g2_kerning.c"
#include "clib\u8g2_intersection.c"
#include "clib\u8g2_input_value.c"
#include "clib\u8g2_hvline.c"
#include "clib\u8g2_fonts.c"
#include "clib\u8g2_font.c"
#include "clib\u8g2_d_setup.c"
#include "clib\u8g2_d_memory.c"
#include "clib\u8g2_cleardisplay.c"
#include "clib\u8g2_circle.c"
#include "clib\u8g2_buffer.c"
#include "clib\u8g2_box.c"
#include "clib\u8g2_bitmap.c"

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int counter = 0;
unsigned long cal_time = 0;
int currentState = 0;
int previousState = 0;

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 6
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
extern "C" void Display_Outputs_wrapper(const real_T *Gps_data,
			const real_T *Baro_data,
			const real_T *Imu_data,
			const real_T *Pitot_data,
			const boolean_T *val,
			const real_T *sleep,
			const real_T *pwm,
			const int8_T *proceed,
			int8_T *cal_init,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==1)
{
#ifndef MATLAB_MEX_FILE
    
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_profont10_tf);	// choose a suitable font  
  
 

  
  if (val[0] == true) { // check if the input is HIGH (button released)   
  currentState = 1;
   if (millis()-cal_time >= 5000){
   cal_init[0] = 1;  
  }
  }
  else {    
  currentState = 0; 
  cal_time = millis();
 }

  if (cal_init[0]==1) {
      
  u8g2.drawStr(10,6,"RADIO CALIBRATING MODE");	// write something to the internal memory
  //u8g2.setCursor(80,15); 
  //u8g2.sendBuffer();
  
    if (proceed[0] == 0){
  u8g2.drawStr(1,20,"Set Sticks neutral point");	// write something to the internal memory
   u8g2.drawStr(10,30,"Pwm throttle:");	
  u8g2.setCursor(80,30);
  u8g2.print(pwm[0]);           // cambiare questo
     u8g2.drawStr(10,40,"Pwm elevator:");	
  u8g2.setCursor(80,40);
  u8g2.print(pwm[2]);           // cambiare questo
     u8g2.drawStr(10,50,"Pwm ailerons:");	
  u8g2.setCursor(80,50);
  u8g2.print(pwm[4]);           // cambiare questo
     u8g2.drawStr(10,60,"Pwm rudder:");	
  u8g2.setCursor(80,60);
  u8g2.print(pwm[6]);           // cambiare questo
  u8g2.sendBuffer();   
  }
  else if (proceed[0] == 1){
  u8g2.drawStr(1,20,"Move Throttle ...");	// write something to the internal memory
  u8g2.drawStr(1,30,"...until pwm change");
   u8g2.drawStr(10,51,"Pwm:");	
  u8g2.setCursor(80,51);
  u8g2.print(pwm[0]); 
  u8g2.sendBuffer();   
  }
  else if (proceed[0] == 2){
  u8g2.drawStr(1,20,"Move Throttle opposite");	// write something to the internal memory
    u8g2.drawStr(10,51,"Pwm:");	
  u8g2.setCursor(80,51);
  u8g2.print(pwm[1]);  
  u8g2.sendBuffer();   
  }
    else if (proceed[0] == 3){
  u8g2.drawStr(1,20,"Move Elevator ...");	// write something to the internal memory
  u8g2.drawStr(1,30,"...until pwm change");
  u8g2.drawStr(10,51,"Pwm:");	
  u8g2.setCursor(80,51);
  u8g2.print(pwm[2]);  
  u8g2.sendBuffer();   
  }
      else if (proceed[0] == 4){
  u8g2.drawStr(1,20,"Move Elevator to opposite");	// write something to the internal memory
  u8g2.drawStr(10,51,"Pwm:");	
  u8g2.setCursor(80,51);
  u8g2.print(pwm[3]); 
  u8g2.sendBuffer();   
  }
      else if (proceed[0] == 5){
  u8g2.drawStr(1,20,"Move Aileron ? ...");	// write something to the internal memory
  u8g2.drawStr(1,30,"...until pwm change");
  u8g2.drawStr(10,51,"Pwm:");	
  u8g2.setCursor(80,51);
  u8g2.print(pwm[4]); 
  u8g2.sendBuffer();   
  }
        else if (proceed[0] == 6){
  u8g2.drawStr(1,20,"Move Aileron to opposite");	// write something to the internal memory
  u8g2.drawStr(10,51,"Pwm:");	
  u8g2.setCursor(80,51);
  u8g2.print(pwm[5]);  
  u8g2.sendBuffer();   
  }
        else if (proceed[0] == 7){
  u8g2.drawStr(1,20,"Move Rudder ? ...");	// write something to the internal memory
  u8g2.drawStr(1,30,"...until pwm change");
  u8g2.drawStr(10,51,"Pwm:");	
  u8g2.setCursor(80,51);
  u8g2.print(pwm[6]);  
  u8g2.sendBuffer();   
  }
        else if (proceed[0] == 8){
  u8g2.drawStr(1,20,"Move Rudder to opposite");	// write something to the internal memory
  u8g2.drawStr(10,51,"Pwm:");	
  u8g2.setCursor(80,51);
  u8g2.print(pwm[7]);  
  u8g2.sendBuffer();   
  }
          else if (proceed[0] == 9){
  cal_init[0]=0;
  }
        
  
  }
  else {
  if(currentState != previousState){
   if(currentState == 1){
    counter = counter + 1;
    }
  }
 if (counter > 5) {
     counter = 0;
 }
     
previousState = currentState;
cal_init[0] = 0;

if (sleep[0] >= 7.5){
  u8g2.setPowerSave(1);  
}
else {
    
  u8g2.setPowerSave(0);
  
  if (counter == 0) {
   u8g2.setPowerSave(1);
 }

 else {
     u8g2.setPowerSave(0);
 }
  
  if (counter == 1) {    
  u8g2.drawStr(50,6,"GPS DATA");	// write something to the internal memory
  u8g2.drawStr(10,15,"Fix:");	// write something to the internal memory
  u8g2.setCursor(80,15);
  if (Gps_data[5] == 0) {
  u8g2.drawStr(80,15,"2D Gps");
  }
  else if (Gps_data[5] == 1) {
  u8g2.drawStr(80,15,"3D Gps");    
  }
  else if (Gps_data[5] == 2) {
  u8g2.drawStr(80,15,"SBAS 2D");     
  }
  else if (Gps_data[5] == 3) {
  u8g2.drawStr(80,15,"SBAS 3D");    
  }
   else {
   u8g2.drawStr(80,15,"No Fix");   
  }
    u8g2.drawStr(10,24,"Lat:");	// write something to the internal memory
  u8g2.setCursor(80,24);
  u8g2.print(Gps_data[0],6);
    u8g2.drawStr(10,33,"Long:");	// write something to the internal memory
  u8g2.setCursor(80,33);
  u8g2.print(Gps_data[1],6);
    u8g2.drawStr(10,42,"Altitude:");	// write something to the internal memory
  u8g2.setCursor(80,42);
  u8g2.print(Gps_data[3]);
    u8g2.drawStr(10,51,"Speed:");	// write something to the internal memory
  u8g2.setCursor(80,51);
  u8g2.print(Gps_data[2]);
    u8g2.drawStr(10,60,"Heading:");	// write something to the internal memory
  u8g2.setCursor(80,60);
  u8g2.print(Gps_data[4],3);
  u8g2.sendBuffer();					// transfer internal memory to the display
      
  }
  
  if (counter == 2) {  
  u8g2.drawStr(50,6,"BARO DATA");
  u8g2.drawStr(10,15,"Press:");	// write something to the internal memory
  u8g2.setCursor(80,15);
  u8g2.print(Baro_data[0]);
  u8g2.drawStr(10,24,"Temp:");	// write something to the internal memory
  u8g2.setCursor(80,24);
  u8g2.print(Baro_data[1]);
  u8g2.drawStr(10,33,"Altitude:");	// write something to the internal memory
  u8g2.setCursor(80,33);
  u8g2.print(Baro_data[2]);
  u8g2.drawStr(10,42,"RC:");	// write something to the internal memory
  u8g2.setCursor(80,42);
  u8g2.print(Baro_data[3]);
  u8g2.sendBuffer();					// transfer internal memory to the display
      
  }
  
  if (counter == 3) { 
   u8g2.drawStr(50,6,"AHRS DATA");
  u8g2.drawStr(10,15,"Euler:");	// write something to the internal memory
  u8g2.setCursor(40,15);
  u8g2.print(Imu_data[6]);
  u8g2.drawStr(60,15,"|");
   u8g2.setCursor(65,15);
  u8g2.print(Imu_data[7]);
  u8g2.drawStr(85,15,"|");
   u8g2.setCursor(90,15);
  u8g2.print(Imu_data[8]);
  u8g2.drawStr(10,24,"Rate:");	// write something to the internal memory
    u8g2.setCursor(40,24);
  u8g2.print(Imu_data[3]);
  u8g2.drawStr(60,24,"|");
   u8g2.setCursor(65,24);
  u8g2.print(Imu_data[4]);
  u8g2.drawStr(85,24,"|");
   u8g2.setCursor(90,24);
   u8g2.print(Imu_data[5]);
  u8g2.drawStr(10,33,"Acc:");	// write something to the internal memory
    u8g2.setCursor(40,33);
  u8g2.print(Imu_data[0]);
  u8g2.drawStr(60,33,"|");
   u8g2.setCursor(65,33);
  u8g2.print(Imu_data[1]);
  u8g2.drawStr(85,33,"|");
   u8g2.setCursor(90,33);
   u8g2.print(Imu_data[2]);
 
  u8g2.sendBuffer();				// transfer internal memory to the display
      
  }
  
  if (counter == 4) {  
  u8g2.drawStr(50,6,"PITOT DATA");
  u8g2.drawStr(10,25,"Speed:");	// write something to the internal memory
  u8g2.setCursor(55,25);
  u8g2.print(Pitot_data[0]);					// transfer internal memory to the display
  u8g2.sendBuffer();    
  }
  
    if (counter == 5) {  
  u8g2.drawStr(35,6,"STORED RADIO PWM");
  u8g2.drawStr(50,13,"Min    Max");
   u8g2.drawStr(1,21,"Throttle:");	// write something to the internal memory
  u8g2.setCursor(50,21);
  u8g2.print((int)(pwm[1]));					// transfer internal memory to the display
    u8g2.setCursor(87,21);
  u8g2.print((int)(pwm[0]));	
    u8g2.drawStr(1,33,"Elevator:");	// write something to the internal memory
  u8g2.setCursor(50,33);
  u8g2.print((int)(pwm[3]));					// transfer internal memory to the display
    u8g2.setCursor(87,33);
  u8g2.print((int)(pwm[2]));	
    u8g2.drawStr(1,45,"Ailerons:");	// write something to the internal memory
  u8g2.setCursor(50,45);
  u8g2.print((int)(pwm[5]));					// transfer internal memory to the display
    u8g2.setCursor(87,45);
  u8g2.print((int)(pwm[4]));	
    u8g2.drawStr(1,57,"Rudder:");	// write something to the internal memory
  u8g2.setCursor(50,57);
  u8g2.print((int)(pwm[7]));					// transfer internal memory to the display
    u8g2.setCursor(87,57);
  u8g2.print((int)(pwm[6]));	
  u8g2.sendBuffer();    
  }
  
}
  }
 
   
       
#endif
    
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void Display_Update_wrapper(const real_T *Gps_data,
			const real_T *Baro_data,
			const real_T *Imu_data,
			const real_T *Pitot_data,
			const boolean_T *val,
			const real_T *sleep,
			const real_T *pwm,
			const int8_T *proceed,
			int8_T *cal_init,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1)
{
#ifndef MATLAB_MEX_FILE
    
u8g2.begin();
       
#endif
xD[0] = 1;
    
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

