#include <stdio.h>
#include <stdlib.h>
//题目本意不是用数组来解决的,当然我们的原则是：
//不管白猫黑猫，做出结果就是好猫

int main()
{
	char c,c_before=' ';
	int lower=0,upper=0,words=0;
	while((c=getchar())!='\n')
	{
		if(c_before==' '&&c!=' ')
			++words;
		
		if(c>='a'&&c<='z')
			++lower;
		else if(c>='A'&&c<='Z')
			++upper;
		
		c_before=c;
	}
	printf("小写字母数量%d  大写字母数量%d  单词数量%d\n",lower,upper,words);
	system("pause");
	return 0;
}
