#include <stdio.h>
#include <stdlib.h>

#define STEP_ALLOC		256

/*****************************************************************************
+FUNCTION: ResizeBuffer
*******************************************************************************/
void ResizeBuffer(char** buffer, int* i_AllocSize, int i_Size)
{
	if (i_Size >= *i_AllocSize)
	{
		if (*buffer == NULL)
		{
			*buffer = (char*)malloc(STEP_ALLOC);
			*i_AllocSize = STEP_ALLOC;
			printf("Allocated memory\n");

			if (*buffer == NULL)
			{
				printf("RS232 Read Format error: could not allocate memory\n");
				*i_AllocSize = 0;
			}
		}
		else
		{
			int newSize = *i_AllocSize;

			while (newSize <= i_Size)
			{
				newSize += STEP_ALLOC;
			}

			*buffer = (char*)realloc(*buffer, newSize);
			*i_AllocSize = newSize;

			//printf("Required size is %d\n", i_Size);
			//printf("Allocated size is %d\n", *i_AllocSize);
			if (*buffer == NULL)
			{
				printf("RS232 Read Format error: could not allocate memory\n");
				*i_AllocSize = 0;
			}
		}
	}
	else if ((i_Size < *i_AllocSize - STEP_ALLOC)&&(i_Size > 0))
	{
		*buffer = (char*)realloc(*buffer, *i_AllocSize - STEP_ALLOC);
		*i_AllocSize -= STEP_ALLOC;

		//printf("Required size is %d\n", i_Size);
		//printf("Reduced size is %d\n", *i_AllocSize);

		if (*buffer == NULL)
		{
			printf("RS232 Read Format error: could not allocate memory\n");
			*i_AllocSize = 0;
		}
	}
	else 
	{
		/*
		printf ("Space is enough: allocated (%d): %d, needed: %d\n", 
							(int)*buffer, 
							i_AllocSize, 
							i_Size);
							*/
	}
}