#include <stdio.h>
#include <stdlib.h>

bool twoSum(int a[], int len, int target, int result[])
{
	int lo = 0, hi = len - 1;
	while (a[lo] + a[hi] != target && lo < hi) {
		printf("当前位置:lo:%d, hi:%d\n",lo,hi);
		if (a[lo] + a[hi]<target) {
			lo++;
		}
		else {
			hi--;
		}
	}
	result[0] = lo;
	result[1] = hi;
	return a[lo] + a[hi] == target;
}
//visual studio 2015
#define N 10
int main()
{
	int a[N] = { 1,3,6,9,15,19,23,27,53,77 };
	int result[2], target = 34;

	if (twoSum(a, N, target, result))
		printf("结果为 a[%d]+a[%d]=%d+%d=%d\n", result[0], result[1], a[result[0]], a[result[1]], target);
	else
		printf("没有结果\n");

	system("pause");
	return 0;
}