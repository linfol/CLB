/**
* 使用myRandom()函数生成随机数
* 用法: 先使用myRandom()函数生成种子seed
*       然后使用myRand()函数生成随机数
* 时间：2014/9/30
**/

// unsigned long 为32位，0L代表32位都是为零，~代表取反，就是1变0，0变1
//~0L就是32为全为1. >>代表右移，最高位补0.
#define ULONG_MAX  ((unsigned long)(~0L)) /* 0xFFFFFFFF*/

#define LONG_MAX   ((long)(ULONG_MAX >> 1))/* 0x7FFFFFFF*/   //long int的最大值

static long int RandomTable[32] ={ 3,   //这里使用了原作者的随机数表

      0x9a319039, 0x32d9c024, 0x9b663182, 0x5da1f342,

      0xde3b81e0, 0xdf0a6fb5, 0xf103bc02, 0x48f340fb,

      0x7449e56b, 0xbeb1dbb0, 0xab5c5918, 0x946554fd,

      0x8c2e680f, 0xeb3d799f, 0xb11ee0b7, 0x2d436b86,

      0xda672e2a, 0x1588ca88, 0xe369735d, 0x904f35f7,

      0xd7158fd6, 0x6fa6f051, 0x616e6b96, 0xac94efdc,

      0x36413f93, 0xc622c298, 0xf5a42ab8, 0x8a88d77b,

      0xf5ad9d0e, 0x8999220b, 0x27fb47b9

    };

static long int *fptr = &RandomTable[4];   //指向前一个随机数，相当于图里的H

static long int *rptr = &RandomTable[1];   //指向后一个随机数，相当于图里的F

static long int *state = &RandomTable[1];  //指向表开始的位置，这里作者是没有指向表的第一个数的

static long int *endPtr = &RandomTable[sizeof(RandomTable) / sizeof(RandomTable[0])];   //指向表结尾后的一个数
																						//sizeof(RandomTable)获得表的大小，
																						//sizeof(RandomTable[0])获得表内一个元素的大小


long int myRandom ()

{

   long int i;

   *fptr += *rptr;   //前一个随机数家加后一个随机数，如图中的H+F，并将结果修改H,更新随机表

   i = (*fptr >> 1) & LONG_MAX; //(*fptr >> 1)右移一位，保留最高位的值，舍弃最低位的值
								//&表示按位与，保证了结果i是long int型，这个就是输出的随机数

// --下面开始移动指针--
   fptr++;  

   if (fptr >= endPtr)  //如果超出了随机表，让其回到最开始的地方

   {
      fptr = state;

      rptr++;
   }

   else

   {

      rptr++;

      if (rptr >= endPtr)

        rptr = state;

   }

   return i;  //返回输出随机数

}

// --  生成随机数种子seed  --
void mySrandom (unsigned int seed)

{
   state[0] = seed;

   register long int i;  //register这个修饰符是表示i是一个寄存器变量
						//去掉register也是不影响程序的正常工作的，使用register是为了更有效率

   for (i = 1; i < 31; ++i)

      state[i] = (1103515145 * state[i - 1]) + 12345;	//这里更新了随机数表，
														//从这里可以知道作者为什么一直保留随机数表第一个数不变
   fptr = &state[3];

   rptr = &state[0];

   for (i = 0; i < 10 * 31; ++i)

      myRandom();  //使用myRand再更新一次随机数表

}
