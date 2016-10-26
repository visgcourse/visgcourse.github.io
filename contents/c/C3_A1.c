#include <stdio.h>
#include <stdlib.h>

void version_1();
void version_2();

int main()
{
	//version_1();
	version_2();
	system("pause");
	return 0;
}

//basic method
void version_1()
{
	int count = 0;
	for (int year = 1; year <= 2016; ++year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			printf("%d\t", year);
			++count;
		}
	}
	printf("%d\n", count);
}

//simple acceleration
void version_2()
{
	int count = 0;
	for (int year = 4; year <= 2016; year += 4)
	{
		if (year % 100 != 0 || year % 400 == 0)
		{
			printf("%d\t", year);
			++count;
		}
	}
	printf("%d\n", count);
}
