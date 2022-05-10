#include <stdlib.h>

typedef signed long        int32_t;
typedef unsigned long      uint32_t;

typedef struct
{
    int32_t    bInitialized;
    int32_t    counter; 
    int32_t    nCompleteMsg;
    int32_T	   bytes_arrived;
    char* buffer;
	int32_T buffer_len;  // Total allocated length
	int32_T buffer_used; // Total used length, always less than buffer_len
} SerialInfo;

// Simulazione segnale GPS
//extern int ix_MTi;
//extern const int ix_CNT;
//extern char* c_MTiSimMsg;
