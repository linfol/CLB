#include <stdio.h>

/**
* ����ͬ�෨���������
* ��ʽ��x = A * x + B (mod M)
* ����A��B��MΪ��������������define
* ʱ�䣺2014/9/29
* �÷���ʹ��mySrand()�������������Seed()��
*       Ȼ��ʹ��myRand()����α�����
**/
#define A 16807L
#define B 2836L
#define M 0x7FFFFFFF  
#define C 127773L

static unsigned long seed = 1;  //Ĭ��seedֵ��
								//����ʹ��static����Ϊ��̬������
								//ֻ���ڳ��������ʱ����ͷ�

static long myDoRand(unsigned long *seed)  //�������������������
{
	long q, r, temp;
	q = *seed / C;    //ȡ����
	r = *seed % C;    //ȡ������
	temp = A*r - B*(q-1);    //�����޸ĺ�Ĺ�ʽ
	if(temp < 0) temp += C;
	return *seed = ( temp % M );  
}

// ��������ú���
int myRand()   
{
	return myDoRand(&seed);
}

//��ʼ��seed����
void mySrand(unsigned int initSeed)  
{
	seed = initSeed;
}
