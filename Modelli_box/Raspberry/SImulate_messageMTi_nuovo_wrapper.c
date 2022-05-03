
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
//#include "stdio.h"                                                            
//#include "string.h"
#include "uinv16.c"
#include "finv32.c"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 9
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */

/* extern double func(double a); */                                           
extern real32_T finv32(void* f);
extern uint16_T uinv16(void* ui);
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void SImulate_messageMTi_nuovo_Outputs_wrapper(const real32_T *input,
			uint8_T *MTimsg,
			int32_T *Len,
			real32_T *P_num)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */

/* esempio                                                                    
 * 0xfa 0xff 0x32 0x32 header                                                 
 * 63 15 246 249 190 142 88 43 65 28 186 190 acc                              
 * 60 11 220 170 189 127 100 9 188 75 180 246 gyr                                                    
 * 191 229 238 100 192 71 155 158 194 186 136 230 Euler                       
 * 3 139 205 ...                                                              
 */                                                                           
char MTi_msg_app[54];                                                         
char* pData = MTi_msg_app;                                                    
char* pHead = MTi_msg_app;                                                      

int i=0;                                                                      
real32_T numero;                                                                 
real32_T* pInp = (real32_T*)input;                                                          
real32_T *Acc, *Rot, *Eul;

char chksum=0;                                                                
char* pCheck=NULL;   
uint8_T HEADER_LEN = 4;
uint8_T CHECK_LEN = 1;

uint16_T counter;
uint16_T ui16;
real32_T f32;

uint8_T  HEAD = 0xfa;                                                            
uint8_T  BID = 0xff;                                                             
uint8_T  MID = 0x32;                                                             
uint8_T  LEN;                                                             
                                                                              
// Scrittura dell'header                                                      
// header 0xfa 0xff 0x32 0x32                                                 
pData[0] = HEAD;                                                              
pData[1] = BID;                                                               
pData[2] = MID;                                                               
pData[3] = LEN; // Questa dovrebbe essere scritta solo alla fine
pData+=4;                                                                     
                                                                              
// Dati                                                                       
Acc = (real32_T*)&input[0];                                                              
Rot = (real32_T*)&input[3];                                                              
Mag = (real32_T*)&input[6];                                                              
Eul = (real32_T*)&input[9];                                                              
                                                                              
// Caso di dati calibrati                                                  
f32 = finv32(&Acc[0]); memcpy(pData, &f32, 4); pData+=4;
f32 = finv32(&Acc[1]); memcpy(pData, &f32, 4); pData+=4;
f32 = finv32(&Acc[2]); memcpy(pData, &f32, 4); pData+=4;
f32 = finv32(&Rot[0]); memcpy(pData, &f32, 4); pData+=4;
f32 = finv32(&Rot[1]); memcpy(pData, &f32, 4); pData+=4;
f32 = finv32(&Rot[2]); memcpy(pData, &f32, 4); pData+=4;
f32 = finv32(&Mag[0]); memcpy(pData, &f32, 4); pData+=4;
f32 = finv32(&Mag[1]); memcpy(pData, &f32, 4); pData+=4;
f32 = finv32(&Mag[2]); memcpy(pData, &f32, 4); pData+=4;

// Inserimento angoli di eulero
f32 = finv32(&Eul[0]); memcpy(pData, &f32, 4); pData+=4;
f32 = finv32(&Eul[1]); memcpy(pData, &f32, 4); pData+=4;
f32 = finv32(&Eul[2]); memcpy(pData, &f32, 4); pData+=4;

// Inserimento contatore
// Metto un numero a caso, ma dovrebbe essere uno degli input
counter = 2883;
ui16 = uinv16(&counter); memcpy(pData, &ui16, 2); pData+=2;
                                                                              
// La lunghezza non tiene in conto né dell'header (4 bytes) né del checksum (1 byte)
// Questa dovrebbe essere scritta solo alla fine, perché in realtà dipende dal tipo 
// di messaggio da scrivere
LEN = pData - pHead - HEADER_LEN;
pHead[3] = LEN; 

//----------------------------------------------------------------------
// Creazione del checksum: dal byte BIN fino al byte precedente al checksum
// Il checksum è creato in modo che sommando tutti i byte compreso il checksum
// la somma è zero
//----------------------------------------------------------------------
for (pCheck = pHead+1; pCheck < pHead + HEADER_LEN + LEN; pCheck++)
{
	chksum += *pCheck;
}
// Scrive l'inverso del checksum in modo che la somma con il checksum sia nulla
pData[0] = -chksum;
                                                                              
// Copia in uscita i float invertiti
memcpy(P_num, pHead+4, 12*sizeof(real32_T));

// Scrive in uscita
memcpy(MTimsg, MTi_msg_app, HEADER_LEN + LEN + CHECK_LEN);                                               

// La lunghezza in uscita è quella totale del messaggio
Len[0] = HEADER_LEN + LEN + CHECK_LEN;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


