/**
* ʹ��myRandom()�������������
* �÷�: ��ʹ��myRandom()������������seed
*       Ȼ��ʹ��myRand()�������������
* ʱ�䣺2014/9/30
**/

// unsigned long Ϊ32λ��0L����32λ����Ϊ�㣬~����ȡ��������1��0��0��1
//~0L����32ΪȫΪ1. >>�������ƣ����λ��0.
#define ULONG_MAX  ((unsigned long)(~0L)) /* 0xFFFFFFFF*/

#define LONG_MAX   ((long)(ULONG_MAX >> 1))/* 0x7FFFFFFF*/   //long int�����ֵ

static long int RandomTable[32] ={ 3,   //����ʹ����ԭ���ߵ��������

      0x9a319039, 0x32d9c024, 0x9b663182, 0x5da1f342,

      0xde3b81e0, 0xdf0a6fb5, 0xf103bc02, 0x48f340fb,

      0x7449e56b, 0xbeb1dbb0, 0xab5c5918, 0x946554fd,

      0x8c2e680f, 0xeb3d799f, 0xb11ee0b7, 0x2d436b86,

      0xda672e2a, 0x1588ca88, 0xe369735d, 0x904f35f7,

      0xd7158fd6, 0x6fa6f051, 0x616e6b96, 0xac94efdc,

      0x36413f93, 0xc622c298, 0xf5a42ab8, 0x8a88d77b,

      0xf5ad9d0e, 0x8999220b, 0x27fb47b9

    };

static long int *fptr = &RandomTable[4];   //ָ��ǰһ����������൱��ͼ���H

static long int *rptr = &RandomTable[1];   //ָ���һ����������൱��ͼ���F

static long int *state = &RandomTable[1];  //ָ���ʼ��λ�ã�����������û��ָ���ĵ�һ������

static long int *endPtr = &RandomTable[sizeof(RandomTable) / sizeof(RandomTable[0])];   //ָ����β���һ����
																						//sizeof(RandomTable)��ñ�Ĵ�С��
																						//sizeof(RandomTable[0])��ñ���һ��Ԫ�صĴ�С


long int myRandom ()

{

   long int i;

   *fptr += *rptr;   //ǰһ��������ҼӺ�һ�����������ͼ�е�H+F����������޸�H,���������

   i = (*fptr >> 1) & LONG_MAX; //(*fptr >> 1)����һλ���������λ��ֵ���������λ��ֵ
								//&��ʾ��λ�룬��֤�˽��i��long int�ͣ������������������

// --���濪ʼ�ƶ�ָ��--
   fptr++;  

   if (fptr >= endPtr)  //������������������ص��ʼ�ĵط�

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

   return i;  //������������

}

// --  �������������seed  --
void mySrandom (unsigned int seed)

{
   state[0] = seed;

   register long int i;  //register������η��Ǳ�ʾi��һ���Ĵ�������
						//ȥ��registerҲ�ǲ�Ӱ���������������ģ�ʹ��register��Ϊ�˸���Ч��

   for (i = 1; i < 31; ++i)

      state[i] = (1103515145 * state[i - 1]) + 12345;	//����������������
														//���������֪������Ϊʲôһֱ������������һ��������
   fptr = &state[3];

   rptr = &state[0];

   for (i = 0; i < 10 * 31; ++i)

      myRandom();  //ʹ��myRand�ٸ���һ���������

}
