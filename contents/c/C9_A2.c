#include <stdio.h>
#include <stdlib.h>

int findPos(int a[], int len, int target)
{
	int lo = 0, hi = len - 1, mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		printf("当前范围%d-->%d\n",lo,hi);
		if (a[mid] < target)
			lo = mid + 1;
		else if (a[mid] > target)
			hi = mid - 1;
		else
			break;
	}
	return lo<=hi?mid:-1;
}
//visual studio 2015
#define N 10
int main()
{
	int a[N] = { 1,3,6,9,15,19,23,27,53,77 };
	int target=20;
	int result = findPos(a, N, target);
	if (result!=-1)
		printf("结果为 a[%d]=%d\n",result,target);
	else
		printf("没有结果\n");

	system("pause");
	return 0;
}