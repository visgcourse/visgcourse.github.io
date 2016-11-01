#include <stdio.h>
#include <stdlib.h>
//两种方法差别见函数gcd内循环体
#define Euler

int gcd(int ,int);
long long lcm(int ,int);

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("最小公约数%d\n",gcd(a,b));
	printf("最大公倍数%lld\n",lcm(a,b));
	system("pause");
	return 0;
}
int gcd(int x, int y)
{
	int temp;
	if(x<y)
	{
		temp=y;
		y=x;
		x=temp;
	}
	while(y!=0)
	{
#ifdef Euler
		temp=x%y;//辗转相除法(欧几里德算法)
#else
		temp=abs(x-y);//更相减损法
#endif
		x=y;
		y=temp;
	}
	return x;
}
long long lcm(int x, int y)
{
	long long c=(long long)x*y;
	c/=gcd(x,y);
	return c;
}
