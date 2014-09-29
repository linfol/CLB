#include <stdio.h>
#include <time.h>
#include "myRand.h"		//上面的随机数生成函数，
						//将其保存为myRand.h

int main()
{
	mySrand( (unsigned)(time(NULL)) ); //获得随机数种子

	int i;
	for(i = 0; i < 100; i++)
	{ 
		i%10 == 0 ? printf("\n") : printf("%-5d",myRand()%99);  //三目运算
	}
	return 0;
}
