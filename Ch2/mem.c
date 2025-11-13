#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"

int
main (int argc, char *argv[])
{

   int *p = malloc(sizeof(int));  //a1 
 // give me enough memory to store one integer, and save that address in p
   assert(p != NULL);
   printf("(%d) address pointed to by p: %p\n",
         getpid(), p);           //a2
   *p = 0;     //a3
// go to the memory stored in p and access the value there (dereferencing)
// put the value 0 at that memory location
                     
   while (1)  {    // infinite loop
       Spin(1);        // wait 1 sec
       *p = *p + 1; // incremeent, *p -> read the value at address p 
// +1 -> add one , -> *p one left side write back to that address
// so, 0 -> 1 -> 2 -> 3 ... 
       printf("(%d) p: %d\n", getpid(), *p);  //a4
   }
   return 0;
}
