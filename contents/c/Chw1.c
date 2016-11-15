#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define isSkip(c) (c==' '||c=='\n'||c=='\0'||c==',')
#define MAX_SIZE 1000

int main()
{
	printf("最终以ctrl-z结尾.请输入内容：\n");
	char str[MAX_SIZE],c_before='\n';
	int words=0,lines=0,char_freq[256];
	int line_start,max_line_length=0,max_line=1;
	int word_start,word_length;
	int max_word_length=0,max_word_start=0;
	for(int i=0;i<256;++i)
		char_freq[i]=0;
	str[0]='\0';
	
	for(int i=1;i<MAX_SIZE;++i)
	{
		str[i]=getchar();
		if(str[i]==EOF)break;
		//字符频率统计
		++char_freq[(unsigned char)str[i]];

		//单词统计
		if((isSkip(c_before)||i==0)&&!isSkip(str[i]))
		{
			++words;
			word_start=i;
		}
		else if(isSkip(str[i])&&!isSkip(c_before))
		{
			word_length=i-word_start;
			if(word_length>max_word_length)
			{
				max_word_start=word_start;
				max_word_length=word_length;
				str[i]='\0';
			}
		}

		//行数统计
		if(c_before=='\n')
		{
			++lines;
			line_start=i;
		}
		if(str[i]=='\n')
		{
			if((i-line_start+1)>max_line_length)
			{
				max_line_length=i-line_start+1;
				max_line=lines;
			}
		}
		c_before=str[i];
	}

	int max_freq=0;
	char max_freq_char='\0';
	for(int i=0;i<256;++i)
	{
		if(char_freq[i]>max_freq)
		{
			max_freq=char_freq[i];
			max_freq_char=i;
		}
	}

	printf("\n=====================================\n统计完成!\n");
	bool show_instruction=true;
	while(1)
	{
		if(show_instruction)
			printf("\n输入1:打印行数相关信息; 输入2:打印字符相关信息; 输入3: 打印单词相关信息  输入0:退出\n\n");
		show_instruction=true;
		c_before=getchar();
		if(c_before=='0')break;
		switch(c_before)
		{
		case '1':
			printf("行数%d  最长行:%d\n",lines,max_line);break;
		case '2':
			printf("频率最高字符%c  它的ascii码在10进制下为%d\n",max_freq_char,max_freq_char);break;
		case '3':
			printf("单词数%d  最长单词%s\n",words,str+max_word_start);break;
		case '\n':
			show_instruction=false;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}