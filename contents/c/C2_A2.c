#include <stdio.h>

int main()
{
	//输入num
	int num;
	scanf("%d",&num);
	//检查num
	if(num<-100000||num>100000)
	{
		printf("输入数字范围有误 请重新运行\n");
		return 0;
	}
	//符号判断
	if(num<0)
	{
		printf("negative");
		num=-num;
	}
	else
		printf("positive");
	//循环取数字
	while(num!=0)
	{
		printf(" ");
		switch(num%10)
		{
		case 0:printf("zero");break;
		case 1:printf("one");break;
		case 2:printf("two");break;
		case 3:printf("three");break;
		case 4:printf("four");break;
		case 5:printf("five");break;
		case 6:printf("six");break;
		case 7:printf("seven");break;
		case 8:printf("eight");break;
		case 9:printf("nine");break;
		}
		num/=10;
	}

	return 0;
}