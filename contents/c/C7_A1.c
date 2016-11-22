#include <stdio.h>
#include <stdlib.h>
void Solve(int *, int *, int *);

int main()
{
	int a,b,c;
	while(1)
	{
		printf("请输入三个数字:\n");
		scanf("%d%d%d",&a,&b,&c);
		Solve(&a,&b,&c);
		printf("max=%d,mid=%d,min=%d",a,b,c);
	}
	system("pause");
	return 0;
}
void Solve(int *a, int *b, int *c)
{
	int temp;
	if(*a<*b){temp=*a;*a=*b;*b=temp;}
	if(*a<*c){temp=*a;*a=*c;*c=temp;}
	if(*b<*c){temp=*b;*b=*c;*c=temp;}
}