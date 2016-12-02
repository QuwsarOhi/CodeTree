#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, n;
   n = 10;
   
   /* Intializes random number generator */
   srand(time(NULL)); 
   /*time(NULL)*/

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < n ; i++ ) 
   {
      printf("%d\n", rand() % 20);
   }
   
   return(0);

}
