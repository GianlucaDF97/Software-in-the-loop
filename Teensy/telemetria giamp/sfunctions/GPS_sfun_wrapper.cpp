 
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
#include <Wire.h> //Needed for I2C to GNSS
#include <MillisTimer.h>
#define myWire Wire1
#include "SparkFun_Ublox_Arduino_Library.h"//Click here to get the library: http://librarymanager/All#SparkFun_u-blox_GNSS
SFE_UBLOX_GPS myGNSS;
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1
 
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */
 
/*
 * Start function
 *
 */
extern "C" void GPS_sfun_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
//     Serial1.begin(57600);
 
  myWire.begin();
 
  
 
  if (myGNSS.begin(myWire) == false) //Connect to the Ublox module using Wire port
  {
    //Serial1.println(F("Ublox GPS not detected at default I2C address. Please check wiring. Freezing."));
return
      ;
  }
  
 
  //myGNSS.enableDebugging(Serial); // Uncomment this line to enable debug message
 
  myGNSS.setI2COutput(COM_TYPE_UBX); //Set the I2C port to output UBX only (turn off NMEA noise)
  myGNSS.setNavigationFrequency(10); // produce 10 solution per second
  myGNSS.setAutoPVT(true);
   myGNSS.setAutoHPPOSLLH(true);
    
  
 
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void GPS_sfun_Outputs_wrapper(real_T *d_lat,
			real_T *d_long,
			real_T *f_groundspeed,
			real_T *f_msl,
			real_T *f_heading,
			real_T *d_fixType,
			boolean_T *gps_data_fresh)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    //Query module only every second.
  //The module only responds when a new position is available.
    *gps_data_fresh=false;
    
  if (myGNSS.getPVT() || myGNSS.getHPPOSLLH())
  {
    *gps_data_fresh=true;
 
    // getHighResLatitude: returns the latitude from HPPOSLLH as an int32_t in degrees * 10^-7
    // getHighResLatitudeHp: returns the high resolution component of latitude from HPPOSLLH as an int8_t in degrees * 10^-9
    // getHighResLongitude: returns the longitude from HPPOSLLH as an int32_t in degrees * 10^-7
    // getHighResLongitudeHp: returns the high resolution component of longitude from HPPOSLLH as an int8_t in degrees * 10^-9
    // getElipsoid: returns the height above ellipsoid as an int32_t in mm
    // getElipsoidHp: returns the high resolution component of the height above ellipsoid as an int8_t in mm * 10^-1
    // getMeanSeaLevel: returns the height above mean sea level as an int32_t in mm
    // getMeanSeaLevelHp: returns the high resolution component of the height above mean sea level as an int8_t in mm * 10^-1
    // getHorizontalAccuracy: returns the horizontal accuracy estimate from HPPOSLLH as an uint32_t in mm * 10^-1
 
    // First, let's collect the position data
    int32_t latitude = myGNSS.getHighResLatitude();
    int8_t latitudeHp = myGNSS.getHighResLatitudeHp();
    int32_t longitude = myGNSS.getHighResLongitude();
    int8_t longitudeHp = myGNSS.getHighResLongitudeHp();
    // int32_t ellipsoid = myGNSS.getElipsoid();
    // int8_t ellipsoidHp = myGNSS.getElipsoidHp();
    int32_t msl = myGNSS.getMeanSeaLevel();
    int8_t mslHp = myGNSS.getMeanSeaLevelHp();
    uint32_t accuracy = myGNSS.getHorizontalAccuracy();
      
    int32_t groundspeed= myGNSS.getGroundSpeed();
    int32_t heading=myGNSS.getHeading();  
      
      
   int d_fixType = myGNSS.getFixType(); // returns the type of fix: 0=no, 1=1D, 2=2D, 3=3D, 4=GNSS+Deadreckoning
   int RTK=myGNSS.getCarrierSolutionType(); // Returns RTK solution: 0=no, 1=float solution, 2=fixed solution
   if  (d_fixType==4){
       d_fixType=6; //la regola solitamente dice che il fixType 6 corrisponde al dead reckoning, si  imposto questo if solo per farlo corrispondere.
   }
   else if (RTK==1){
       d_fixType=5;
   } 
   else if (RTK==2){
       d_fixType=4;
   }
    // Defines storage for the lat and lon as double
    double d_lat; // latitude
    double d_lon; // longitude
 
    // Assemble the high precision latitude and longitude
    d_lat = ((double)latitude) / 10000000.0; // Convert latitude from degrees * 10^-7 to degrees
    d_lat += ((double)latitudeHp) / 1000000000.0; // Now add the high resolution component (degrees * 10^-9 )
    d_lon = ((double)longitude) / 10000000.0; // Convert longitude from degrees * 10^-7 to degrees
    d_lon += ((double)longitudeHp) / 1000000000.0; // Now add the high resolution component (degrees * 10^-9 )
 
   // Print the lat and lon
//   
//     Serial1.print("Lat (deg): ");
//     Serial1.print(d_lat, 9);
//     Serial1.print(", Lon (deg): ");
//     Serial1.print(d_lon, 9);
 
    // Now define float storage for the heights and accuracy
    // float f_ellipsoid;
    float f_msl;
    float f_accuracy;
    float f_groundspeed;
    float f_heading;
    
    
 
    // Calculate the height above ellipsoid in mm * 10^-1
   // f_ellipsoid = (ellipsoid * 10) + ellipsoidHp;
    // Now convert to m
    //f_ellipsoid = f_ellipsoid / 10000.0; // Convert from mm * 10^-1 to m
 
    // Calculate the height above mean sea level in mm * 10^-1
    f_msl = (msl * 10) + mslHp;
    // Now convert to m
    f_msl = f_msl / 10000.0; // Convert from mm * 10^-1 to m
 
    // Convert the horizontal accuracy (mm * 10^-1) to a float
    f_accuracy = accuracy;
    // Now convert to m
    f_accuracy = f_accuracy / 10000.0; // Convert from mm * 10^-1 to m
 
    // Convert the ground Speed (mm/s in m/s)  
    f_groundspeed=groundspeed/1000.0;  
    // Convert heading  (deggree *10^-5)
    f_heading=heading/100000.0;
    
    
  
    // Finally, do the printing
  
    
   // Serial1.print(", Ellipsoid (m): ");
   // Serial1.print(f_ellipsoid, 4); // Print the ellipsoid with 4 decimal places
   
    // Serial1.print(", Mean Sea Level (m): ");
    // Serial1.print(f_msl, 4); // Print the mean sea level with 4 decimal places
    
    // Serial1.print(", Ground Speed (m): ");
   //  Serial1.print(f_groundspeed, 4); // Print the ground speed with 4 decimal places 
    
    //Serial1.print(", Heading (m): ");
//     Serial1.print(f_heading, 5); // Print the heading with 4 decimal places  
//       
//     Serial1.print(", d_fixType: ");
//     Serial1.print( d_fixType); //
//       
//     Serial1.print(", Accuracy (m): ");
//     Serial1.println(f_accuracy, 4); // Print the accuracy with 4 decimal places
//     Serial1.println(" ");   
    
      
  }
     #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
 
 
