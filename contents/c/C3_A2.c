#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (2 * pow(x, 3.0) - 4 * pow(x, 2.0) + 3 * x - 7)
//��֪�������ֵ���
void version_1();
void version_2();

int main()
{
	version_1();
	//version_2();
	system("pause");
	return 0;
}

//�޶�x���䷶Χ�ķ�ʽ
void version_1()
{
	double left = -5, right = 5;
	double err, x, y;
	int iter = 0;
	printf("input maxerr: ");
	scanf("%lf", &err);
	while (right - left > err)
	{
		++iter;
		x = (right + left) / 2;
		y = f(x);
		if (y < 0)
			left = x;
		else if (y > 0)
			right = x;
		else
			break;
	}
	printf("result is %f   iter = %d \n", x, iter);
}

//�޶�y���䷶Χ�ķ�ʽ
void version_2()
{
	double left = -5, right = 5;
	double err, x, y;
	int iter = 0;
	printf("input maxerr: ");
	scanf("%lf", &err);
	do
	{
		++iter;
		x = (right + left) / 2;
		y = f(x);
		if (y < 0)
			left = x;
		else if (y > 0)
			right = x;
		else
			break;
	} while (fabs(y) > err);
	printf("result is %f   iter = %d \n", x, iter);
}