#include <stdio.h>
#include <time.h>
#include "myRand.h"		//�������������ɺ�����
						//���䱣��ΪmyRand.h

int main()
{
	mySrand( (unsigned)(time(NULL)) ); //������������

	int i;
	for(i = 0; i < 100; i++)
	{ 
		i%10 == 0 ? printf("\n") : printf("%-5d",myRand()%99);  //��Ŀ����
	}
	return 0;
}
