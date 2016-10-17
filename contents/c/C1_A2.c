#include <stdio.h>
// 以后学到循环或函数时可以简化代码
// 现在就限制为输入5个字符
int main()
{
	char a;

	a=getchar();
	a=(a+25-'A')%26+'a';
	putchar(a);
	
	a=getchar();
	a=(a+25-'A')%26+'a';
	putchar(a);

	a=getchar();
	a=(a+25-'A')%26+'a';
	putchar(a);

	a=getchar();
	a=(a+25-'A')%26+'a';
	putchar(a);
	
	a=getchar();
	a=(a+25-'A')%26+'a';
	putchar(a);

	system("pause");
	return 0;
}