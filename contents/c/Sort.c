// read more and write more,you'll be the god/godness of the code
// there are lots of tutorials(including source code) about Sort on the internet
// I would appreciate it if you find any bug or have any advice about the program ,just contact 121180088@smail.nju.edu.cn
#include "stdafx.h"
#include <stdlib.h>
#define MAX_NUM 10

void sortBubble(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if (a[j] > a[j+1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void sortInsert(int *a, int n)
{
	int temp;
	for (int i = 1; i < n; ++i)
	{
		temp = a[i];
		int j = i - 1;
		for (;j >= 0 && a[j] > temp; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

void sortSelect(int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int min = a[i];
		int min_index = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < min)
			{
				min = a[j];
				min_index = j;
			}
		}

		int temp = a[min_index];
		a[min_index] = a[i];
		a[i] = temp;
	}
}

int main()
{
	int a[MAX_NUM];
	for (int i = 0; i < MAX_NUM; ++i)
	{
		a[i] = rand();
	}
	
	//sortBubble(a,MAX_NUM);
	//sortInsert(a, MAX_NUM);
	sortSelect(a, MAX_NUM);
	for (int i = 0; i < MAX_NUM; i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}
