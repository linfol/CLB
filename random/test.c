#include <stdio.h>
#include <time.h>
#include "myRandom.h"

int main()
{
   int i;
   mySrandom((unsigned)(time(NULL)));  //获得初始种子seed
   for(i=0;i<100;i++)
      i%10 == 0 ? printf("\n") : printf("%-5d",myRandom()%99+1);
   return 0;
} 
