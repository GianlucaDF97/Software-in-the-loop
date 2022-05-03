
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
 * Start function
 *
 */
void SImulate_messageGPS_nmea_carriage_return_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
    * Custom Start code goes here.
    */
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void SImulate_messageGPS_nmea_carriage_return_Outputs_wrapper(const real_T *Lat,
			const real_T *Long,
			const real_T *V_,
			const real_T *heading,
			const real_T *h,
			uint8_T *GPSmsg)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// CODIFICA MESSAGGIO NMEA GGA/RMC
    char GPS_msg[131];
    int punt = 0;
    char chkval = 0;
    char* msgAst = NULL;
    int p = 0;
    int i = 0;
    size_t len_gga = 0;
    int Lat_int = 0;
    double Lat_dec = 0;
    int Long_int = 0;
    double Long_dec = 0;
    
    // Inizializzo il puntatore all'inizio del buffer da formare
    char* pMsg = GPS_msg;
    
    //header
    pMsg += sprintf(pMsg,"$GPGGA");
    punt=6;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    //GPS TIME
    pMsg += sprintf(pMsg,"%06d", 123456);
    punt+=6;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    //LATITUDINE
    Lat_int = floor(fabs(Lat[0]));
    Lat_dec = (Lat[0] - floor(fabs(Lat[0])))*60;
    
    pMsg += sprintf(pMsg,"%02d",Lat_int);
    punt+=2;
    pMsg += sprintf(pMsg,"%06.3f",Lat_dec);
    punt+=6;
    
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    
    //LATITUDINE N o S
    if (Lat[0] >= 0)
        pMsg += sprintf(pMsg, "N");
    else
        pMsg += sprintf(pMsg, "S");
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    
    //LONGITUDINE
    Long_int = floor(fabs(Long[0]));
    Long_dec = (Long[0] - floor(fabs(Long[0])))*60;
    
    pMsg += sprintf(pMsg,"%03d",Long_int);
    punt+=3;
    pMsg += sprintf(pMsg,"%06.3f",Long_dec);
    punt+=6;
    
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    //LONGITUDINE E o W
    if (Long[0] >= 0)
        pMsg += sprintf(pMsg, "E");
    else
        pMsg += sprintf(pMsg, "W");
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // Fix lo lascio ad 1
    pMsg += sprintf(pMsg,"%01d",1);
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // Num satelliti lo lascio ad 08
    pMsg += sprintf(pMsg,"%02d",8);
    punt+=2;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // non mi ricordo ma non serve e lo metto a 0.9
    pMsg += sprintf(pMsg,"%.1f",0.9);
    punt+=3;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    
    //QUOTA
    
    if (h[0]>=0 && h[0]<10){
        pMsg += sprintf(pMsg,"%.1f",h[0]);
        punt+=3;
    }
    else if  (h[0]>=10 && h[0]<100){
        pMsg += sprintf(pMsg,"%.1f",h[0]);
        punt+=4;
    }
    else if (h[0]>=100 && h[0]<1000){
        pMsg += sprintf(pMsg,"%.1f",h[0]);
        punt+=5;
    }
    else if (h[0] >=1000 && h[0] < 10000) {
        pMsg += sprintf(pMsg,"%.1f",h[0]);
        punt+=6;
    }
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // UNITA DI MISURA 'M'
    pMsg += sprintf(pMsg, "M");
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // QUOTA NON UTILIZZATA, LA METTO AD 1
    pMsg += sprintf(pMsg,"%.1f",1.0);
    punt+=3;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // UNITA DI MISURA 'M'
    pMsg += sprintf(pMsg, "M");
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    
    
    // calcolo checksum
    for (p = 1; p<= strlen(GPS_msg); p++)
    {
        chkval = chkval ^(GPS_msg[p]);
    }
    
    
    // star
    pMsg += sprintf(pMsg,"*");
    punt+=1;
    //checksum
    pMsg += sprintf(pMsg, "%02x",chkval);
    punt+=2;
    // carriage return
    pMsg += sprintf(pMsg, "\r" ) ;
    punt+=1;
    
    len_gga = strlen(GPS_msg);
    // INIZIO MESSAGGIO 'RMC'
    
    //header
    pMsg += sprintf(pMsg,"$GPRMC");
    punt+=6;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    //GPS TIME
    pMsg += sprintf(pMsg,"%06d",123456);
    punt+=6;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // A
    pMsg += sprintf(pMsg,"A");
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    //LATITUDINE
    pMsg += sprintf(pMsg,"%02d",Lat_int);
    punt+=2;
    pMsg += sprintf(pMsg,"%06.3f",Lat_dec);
    punt+=6;
    
    
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    
    //LATITUDINE N o S
    if (Lat[0] >= 0)
        pMsg += sprintf(pMsg, "N");
    else
        pMsg += sprintf(pMsg, "S");
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    
    //LONGITUDINE
    pMsg += sprintf(pMsg,"%03d",Long_int);
    punt+=3;
    pMsg += sprintf(pMsg,"%06.3f",Long_dec);
    punt+=6;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    //LONGITUDINE E o W
    if (Long[0] >= 0)
        pMsg += sprintf(pMsg, "E");
    else
        pMsg += sprintf(pMsg, "W");
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // velocita
    pMsg += sprintf(pMsg,"%05.1f",fabs(V_[0]));
    punt+=5;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // heading
    pMsg += sprintf(pMsg,"%05.1f",fabs(heading[0]));
    punt+=5;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // data
    pMsg += sprintf(pMsg,"%06d",110419);
    punt+=6;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // comma
    pMsg += sprintf(pMsg,",");
    punt+=1;
    // A
    pMsg += sprintf(pMsg,"A");
    punt+=1;
    chkval = 0;
    for (p = len_gga+1; p<=strlen(GPS_msg); p++)
    {
        chkval = chkval ^(GPS_msg[p]);
    }
    // star
    pMsg += sprintf(pMsg,"*");
    punt+=1;
    //checksum
    pMsg += sprintf(pMsg, "%02x",chkval);
    punt+=2;
    // carriage return
    pMsg += sprintf(pMsg, "\r" ) ;
    punt+=1;
    //chiusura
    *pMsg = 0;
    memcpy(GPSmsg,GPS_msg,punt);
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Terminate function
 *
 */
void SImulate_messageGPS_nmea_carriage_return_Terminate_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
    * Custom Terminate code goes here.
    */
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

