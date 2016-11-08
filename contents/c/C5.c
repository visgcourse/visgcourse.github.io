#include <stdio.h>

int count = 0;
int arr[100];

int divid(int num)
{
	arr[count] = num;
	count++;
	if (num == 1)
	{
		return 1;
	}
	if (num % 2 == 0)
	{
		return divid(num / 2);
	}	
	else
	{
		return divid(num * 3 + 1);
	}
}

int main()
{
	int divid(int num);
	int n, result;
	printf("Input an Integer: ");
	scanf("%d", &n);

	result = divid(n);
	printf("count = %d\n", count);
	//print unsorted array
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//sort, using Selection Sort here.
	int tmp;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (arr[i]>arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	//print sorted array
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}