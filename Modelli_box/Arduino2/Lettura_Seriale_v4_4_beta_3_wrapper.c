
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
#include "stdio.h"
#include "stdlib.h"
#include "MTi_Types.h"
#include "ReadBin_MTi_Arduino.c"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
extern int mdlOutput_ReadBin_Mti(unsigned char* buffer,
                      SerialInfo* pSerialInfo,
                      int* params,
                      int* led_test,
                      int* led_test_due,
                      double* data_out);
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void Lettura_Seriale_v4_4_beta_3_Outputs_wrapper(const uint32_T *block_state_in,
			uint8_T *dato,
			int16_T *uart_buffer,
			int16_T *check,
			real_T *data_out,
			uint16_T *flag,
			int32_T *counter,
			int16_T *led_test,
			int16_T *led_test_due,
			uint32_T *block_state_out,
			const int16_T *serial_port, const int_T p_width0,
			const int32_T *velocita, const int_T p_width1)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
SerialInfo* pSerialInfo = (SerialInfo*)block_state_in[0];
int16_T stato;
int32_T res;
int indice;

int params[3];

params[0] = 1;//(int)use_calibrated[0]; // 0: not calibrated, 1: calibrated
params[1] = 2;//(int)orientation_type[0]; // 1: quaternion, 2: euler, 3: dcm
params[2] = 1;//(int)use_counter[0]; // 0: don't use, 1: use it

if (pSerialInfo == 0)
{
    // è la prima esecuzione
    pSerialInfo = (SerialInfo*)malloc(sizeof(SerialInfo));
    if (pSerialInfo == 0)
    {
        // Verifica la allocazione della memoria
        check[0] = (int16_T)2;
        return;
    }
    memset(pSerialInfo, 0, sizeof(SerialInfo));
    
    /* don't do anything for MEX-file generation */
    # ifndef MATLAB_MEX_FILE
    Serial_begin(serial_port[0], velocita[0]); 
    # endif
                
    // In verità, questa non serve, basterebbe solo testare block_state_in 
    // per verificare se la struttura è stata inizializzata
    pSerialInfo->bInitialized = 1;
    
    pSerialInfo->counter = (int32_T)0;
    pSerialInfo->nCompleteMsg = (int32_T)0;
}

if (pSerialInfo == 0)
{
    check[0] = (int16_T)3;
    return;
}

/* wait until after initialization is done */
if (pSerialInfo->bInitialized) 
{
    // La dimensione deve essere non minore della dimensione del buffer in ingresso
    unsigned char buffer[128];
    int16_T inBytesCounter = 0; 
    
/* don't do anything for mex file generation */
    #ifndef MATLAB_MEX_FILE  
    while ((Serial_available(serial_port[0],&uart_buffer[0]) > 0)&&
           (inBytesCounter < 128))
//     #else 
//     int i;
//     for (i = 0;i <55; i++)
//     #endif
    {
//         #ifndef MATLAB_MEX_FILE  
        Serial_read(serial_port[0], 1, &dato[0], &stato);        
//         #else
//         dato[0] = (uint8_T)c_MTiSimMsg[ix_MTi];
//         ix_MTi++;
//         if (ix_MTi >= ix_CNT)
//             ix_MTi = 0;
//         stato = (int16_T)1;
//         #endif
                
        check[0]=4;
        
        if (stato==1)
        {
            check[0] =5;
            buffer[inBytesCounter] = dato[0];
            inBytesCounter++;  
        }
        else
        {
            // Esce dal blocco for se non ci sono bytes da leggere
            // e la funzione di lettura della seriale ritorna un valore
            // differente da 1
            break;            
        }
    }
    #endif
    
    if (inBytesCounter > 0)
        pSerialInfo->counter++;
    pSerialInfo->bytes_arrived = inBytesCounter;
    
    
//     int length = len[0]; //=55;??
    res=mdlOutput_ReadBin_Mti(buffer,
                      pSerialInfo,
                      params,    // parameters
    /*AGGIUNTO*/      led_test,     //output aggiunto
    /*AGGIUNTO*/      led_test_due, //output aggiunto
                      data_out  // output
                      );
                      
}
// Inizializzazione del puntatore che viene ritrasmesso in ingressi
// per memorizzare un riferimento all'oggetto allocato
block_state_out[0] = (uint32_T)pSerialInfo;

// Riempimento dei contatori in uscita
counter[0] = (int32_T)pSerialInfo->counter;
counter[1] = (int32_T)pSerialInfo->nCompleteMsg;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


