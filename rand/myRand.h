#include <stdio.h>

/**
* 线性同余法产生随机数
* 公式：x = A * x + B (mod M)
* 其中A，B，M为常数，定义如下define
* 时间：2014/9/29
* 用法：使用mySrand()产生随机数种子Seed()，
*       然后使用myRand()产生伪随机数
**/
#define A 16807L
#define B 2836L
#define M 0x7FFFFFFF  
#define C 127773L

static unsigned long seed = 1;  //默认seed值，
								//这里使用static定义为静态变量，
								//只有在程序结束的时候才释放

static long myDoRand(unsigned long *seed)  //真正的随机数产生函数
{
	long q, r, temp;
	q = *seed / C;    //取得商
	r = *seed % C;    //取得余数
	temp = A*r - B*(q-1);    //运用修改后的公式
	if(temp < 0) temp += C;
	return *seed = ( temp % M );  
}

// 随机数调用函数
int myRand()   
{
	return myDoRand(&seed);
}

//初始化seed函数
void mySrand(unsigned int initSeed)  
{
	seed = initSeed;
}
