#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NULL_DEREF(ptr) ((!ptr) ? 0 : 1)
#define BUFFER_OVERFLOW(n, m) ((n > m) ? 0 : 1)

void func_1()
{
    int a, b, c; // some integers
    int *pi;     // a pointer to an integer

    a = 5;
    pi = &a; // pi points to a
    b = *pi; // b is now 5
    pi = NULL;
    if((NULL_DEREF(pi) == 1))
        {
            abort();
        }
    c = *pi; // this is a NULL pointer dereference
}


int func_2()
{
    // Reserve 5 byte of buffer plus the terminating NULL. 
       // should allocate 8 bytes = 2 double words, 
       // To overflow, need more than 8 bytes... 
       char buffer[5];  // If more than 8 characters input 
                        // by user, there will be access  
                        // violation, segmentation fault 

    // copy the user input to mybuffer, without any 
       // bound checking a secure version is srtcpy_s() 
       strcpy(buffer, 9); 
       if(BUFFER_OVERFLOW(9, 5) == 1)
       {
           abort();
       }
       printf("buffer content= %s\n", buffer); 
  
       // you may want to try strcpy_s() 
       printf("strcpy() executed...\n"); 
}

int func_3()
{
    int *ptr = (int *) malloc(sizeof(int)); 
  
   /* Do some work */
  if(NULL_DEREF(ptr) == 1)
  {
      abort();
  }

   return; /* Return without freeing ptr*/
}


int main()
{
    return(0);
}
