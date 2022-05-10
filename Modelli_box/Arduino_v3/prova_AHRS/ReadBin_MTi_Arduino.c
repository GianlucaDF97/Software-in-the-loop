#include <memory.h>
#include <string.h>


#define HEADER				0xFA
#define HEADER_LEN			4
#define CHECK_LEN			1

void ResizeBuffer(char** buffer, int* i_AllocSize, int i_Size);

/*****************************************************************************
+FUNCTION: finv32
+DESCRIPTION: Inverts 32 byte order, generating a float.
******************************************************************************/
float finv32(void* f)
{
	float r;
	char* pr = (char*)(&r);
	char* pf = (char*)f;
	pr[0] = pf[3];
	pr[1] = pf[2];
	pr[2] = pf[1];
	pr[3] = pf[0];
	return r;
}

/*****************************************************************************
+FUNCTION: uinv16
+DESCRIPTION: Inverts 16 byte order, generating an integer 16 bit.
******************************************************************************/
unsigned short uinv16(void* f)
{
	unsigned short r;
	char* pr = (char*)(&r);
	char* pf = (char*)f;
	pr[0] = pf[1];
	pr[1] = pf[0];
	return r;
}

/*****************************************************************************
+FUNCTION: mdlOutput_ReadBin_Mtx
+DESCRIPTION: Read the bytes from the incoming buffer
******************************************************************************/
int mdlOutput_ReadBin_Mti(unsigned char* incoming_buffer,
                             // int length, 
                             // unsigned int* mem_in,
							 SerialInfo* pSerialInfo,
                             int* params,
                             int* led_test,
                             int* led_test_due,
                             double* output)  // output
                             // unsigned int mem_out)//, // output
                            // int* status_out) // output
{
	//SOSTITUIRE BUFFER, BUFFER_USED, BUFFER_LEN CON I PUNTATORI A STRUCT
	
	//int isHeader = 0;
	char*	pHead = NULL;
	int USE_CALIBRATED = params[0];
	int ORIENTATION_TYPE = params[1];
	int USE_COUNTER = params[2];
    
    int luce = 0;
    int luce_due = 0;
    int count = 0;
   // int status = 0;
//     
   // Return, if no bytes arrived
	// if (length <= 0)
	if(pSerialInfo->bytes_arrived<=0)
	{
		// mem_out[0] = (int)buffer;
		// mem_out[1] = buffer_len;
		// mem_out[2] = buffer_used;
		luce_due=1;
		return 0;
	}

	// Reallocate the buffer, if some bytes arrived
	// ResizeBuffer(&buffer, &buffer_len, length + buffer_used);
	ResizeBuffer(&pSerialInfo->buffer, &pSerialInfo->buffer_len, pSerialInfo->buffer_used + pSerialInfo->bytes_arrived);

	//--------------------------------------------------------------------------
	// Manage the allocation failure
	//--------------------------------------------------------------------------
	if (pSerialInfo->buffer == NULL)
	{
		printf("RS232 Read Format error: error managing buffers\n");
		// buffer_used = 0;
		pSerialInfo->buffer_used;
		// mem_out[0] = (int)buffer;
		// mem_out[1] = buffer_len;
		// mem_out[2] = buffer_used;
		luce=1;
              
		return -1;
	}

	//--------------------------------------------------------------------------
	// If there's some bytes in input, copies all bytes in the allocated buffer
	//--------------------------------------------------------------------------
	// if (length != 0)
	if (pSerialInfo->bytes_arrived !=0)
	{
		int j;
              
		// for (j=0;j<length;j++) 
		for(j=0;j<pSerialInfo->bytes_arrived;j++)
		{
			pSerialInfo->buffer[pSerialInfo->buffer_used+j] = incoming_buffer[j];
		}
	}

	//-----------------------------------------------------
	// Null-terminate the buffer
	//-----------------------------------------------------
	// buffer_used += length;
	pSerialInfo->buffer_used += pSerialInfo->bytes_arrived;
	pSerialInfo->buffer[pSerialInfo->buffer_used]=0; // Null-terminate the buffer

	//-------------------------------------------------------------------------------
	// If the total message is greater then the message terminator, look for the 
	// terminator
	//-------------------------------------------------------------------------------
	pHead = pSerialInfo->buffer;
	while (pSerialInfo->buffer_used >= HEADER_LEN) // This is not a loop, it's a if-like block
	{
		char chksum = 0;
		char* pCheck = NULL;
		float* pData = NULL;
		char  BID = 0;
		char  MID = 0;
		char  LEN = 0;
		char  rLEN = 0;
        
		// Look for the HEADER byte
		pHead = memchr(pHead, HEADER, pSerialInfo->buffer_used);
		
       
          
		if (pHead == NULL)
		{
            // Header not found, reject the buffer data
			pSerialInfo->buffer_used = 0;
          //  status = 1;
			break;
		}
        
      

		// Header byte found: now look for the rest of header
		BID = pHead[1];
		MID = pHead[2];
		LEN = pHead[3];
        
		// Check checksum validity
		if (LEN <= 0)
		{
			// Checksum not valid
			printf("Invalid length (%d)\n", LEN);
			pHead++;
			continue; // Look for another preamble
		}

        
       	// Check if there's at least the indicated number of bytes
		if (pSerialInfo->buffer_used - (pHead - pSerialInfo->buffer) < HEADER_LEN + LEN + CHECK_LEN)
		{
			// There's not the needed number of bytes
			// Wait for other bytes
        //    status = 2;
			break;
		}
         
        
         
        
		//----------------------------------------------------------------------
		// Check the checksum: from the BIN to the checksum itself
		// If all the message bytes excluding the header are summed and the sum is equal
		// to zero (included the checksum), the message is valid
		//----------------------------------------------------------------------
		for (pCheck = pHead+1; pCheck < pHead + HEADER_LEN + LEN + CHECK_LEN; pCheck++)
		{
			chksum += *pCheck;
		}
        
      
        
		// Check checksum validity
		if (chksum != 0)
		{
			// Checksum not valid
			printf("Some characters (%d) rejected (no checksum found)\n", pHead - pSerialInfo->buffer);
			pHead++;
			continue; // Look for another preamble
		}

		//----------------------------------------------------------------------
		// Verify the message type: it should be MID = 0x32
		//----------------------------------------------------------------------
        
        
		if (MID == 0x32)
		{
           
            
			//----------------------------------------------------------------------
			// Now we know that we got the message
			// Let's start the data interpretation
			//----------------------------------------------------------------------
			pData = (float*)(pHead + 4);
			rLEN = LEN;
            
            
			// Use not calibrated
			if ((USE_CALIBRATED == 0)&&(rLEN >= 20))
			{
				unsigned short* pU16Data = (unsigned short*)pData;
				double *Acc, *Rot, *Mag, *Tmp;

				Acc = &output[0];
				Rot = &output[3];
				Mag = &output[6];
				Tmp = &output[18];

				Acc[0] = (real_T)uinv16(pU16Data); pU16Data++;
				Acc[1] = (real_T)uinv16(pU16Data); pU16Data++;
				Acc[2] = (real_T)uinv16(pU16Data); pU16Data++;
				Rot[0] = (real_T)uinv16(pU16Data); pU16Data++;
				Rot[1] = (real_T)uinv16(pU16Data); pU16Data++;
				Rot[2] = (real_T)uinv16(pU16Data); pU16Data++;
				Mag[0] = (real_T)uinv16(pU16Data); pU16Data++;
				Mag[1] = (real_T)uinv16(pU16Data); pU16Data++;
				Mag[2] = (real_T)uinv16(pU16Data); pU16Data++;
				Tmp[0] = (real_T)uinv16(pU16Data); pU16Data++;

				pData = (float*)pU16Data;
				rLEN -= 20;
                
                
                
			}

			// Use calibrated
			if ((USE_CALIBRATED == 1)&&(rLEN >= 36))
			{
				double *Acc, *Rot, *Mag;

				Acc = &output[0];
				Rot = &output[3];
				Mag = &output[6];

				Acc[0] = (real_T)finv32(pData); pData++;
				Acc[1] = (real_T)finv32(pData); pData++;
				Acc[2] = (real_T)finv32(pData); pData++;
				Rot[0] = (real_T)finv32(pData); pData++;
				Rot[1] = (real_T)finv32(pData); pData++;
				Rot[2] = (real_T)finv32(pData); pData++;
				Mag[0] = (real_T)finv32(pData); pData++;
				Mag[1] = (real_T)finv32(pData); pData++;
				Mag[2] = (real_T)finv32(pData); pData++;

				rLEN -= 36;
                
                
            }

			// Use quaternions
			if ((ORIENTATION_TYPE == 1)&&(rLEN >= 16)) 
			{
				double *Quat;

				Quat = &output[9];

				Quat[0] = (real_T)finv32(pData); pData++;
				Quat[1] = (real_T)finv32(pData); pData++;
				Quat[2] = (real_T)finv32(pData); pData++;
				Quat[3] = (real_T)finv32(pData); pData++;

				rLEN -= 16;
                
                 
			}
               

			// Use Euler angles
			if ((ORIENTATION_TYPE == 2)&&(rLEN >= 12))
			{
				double *Eul;
                

				Eul = &output[9];

				Eul[0] = (real_T)finv32(pData); pData++;
				Eul[1] = (real_T)finv32(pData); pData++;
				Eul[2] = (real_T)finv32(pData); pData++;

				rLEN -= 12;
                
            
               
            }

			// Use DCM
			if ((ORIENTATION_TYPE == 3)&&(rLEN >= 36))
			{
				double *Dcm;

				Dcm = &output[9];

				Dcm[0] = (real_T)finv32(pData); pData++;
				Dcm[1] = (real_T)finv32(pData); pData++;
				Dcm[2] = (real_T)finv32(pData); pData++;
				Dcm[3] = (real_T)finv32(pData); pData++;
				Dcm[4] = (real_T)finv32(pData); pData++;
				Dcm[5] = (real_T)finv32(pData); pData++;
				Dcm[6] = (real_T)finv32(pData); pData++;
				Dcm[7] = (real_T)finv32(pData); pData++;
				Dcm[8] = (real_T)finv32(pData); pData++;

				rLEN -= 36;
                
                
			}
            
            
             
            
            
			// Use Counter
			if ((USE_COUNTER == 1)&&(rLEN >= 2))
			{
				unsigned short* pU16Data = (unsigned short*)pData;
				double *Cnt;

				Cnt = &output[19];

				Cnt[0] = (double)uinv16(pU16Data); pU16Data++;

				pData = (float*)pU16Data;

				rLEN -= 2;
                
               
			}

			if (rLEN > 0)
			{
				printf("Error: Not interpreted bytes (%d)\n", rLEN);
                luce=1;
			}
		}
		else
		{
			printf("Msg type %02x detected\n", MID);
			luce=1;
             
		}

        
        
		//----------------------------------------------------------------------
		// Data bytes have been read. Now it's time to manage the buffer
		//----------------------------------------------------------------------
		{
			// Compute the message length, included the header shift
			int msgLen = (int)(HEADER_LEN + LEN + CHECK_LEN) + (int)(pHead - pSerialInfo->buffer);
                
            
                   
            
			if (pSerialInfo->buffer_used == msgLen)
			{
				// There's no more bytes in the buffer. Deallocate it
				pSerialInfo->buffer_used = 0;
				luce_due=1;
                
			}
			else if (pSerialInfo->buffer_used > msgLen)
			{
				// Move back the remaining bytes
				memmove(pSerialInfo->buffer,
					pSerialInfo->buffer + msgLen,
					pSerialInfo->buffer_used - msgLen);
				pSerialInfo->buffer_used -= msgLen;
				luce_due=1;
                
            }
			else
			{
				// Memory leak DANGER!
				printf("Something very bad happened: Memory leak!\n");
				luce=1;
			}
		}

		//----------------------------------------------------------------------
		// Get out the loop
		//----------------------------------------------------------------------
		if (++count > 4) 
        {
      //      status = 4;
            break;
        }
	}

	//-----------------------------------------------------
	// Set the output
	//-----------------------------------------------------
	// mem_out[0] = (int)buffer;
	// mem_out[1] = buffer_len;
	// mem_out[2] = buffer_used;

    led_test[0]= luce;
    led_test_due[0] = luce_due;
    
 //  status_out[0] = status;    
       
	return 0;
}