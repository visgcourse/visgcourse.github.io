#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
void Sort_insert(int a[],int len);
void Sort_select(int a[],int len);
void Sort_merge(int a[],int len);

int main()
{
	int num[N];
	//产生不同的随机数
	//srand(time(NULL));
	//初始化数组内容
	printf("初始化时的数组内容:\n");
	for(int i=0;i<N;++i)
	{
		num[i]=rand();
		printf("%d\t",num[i]);
	}
	//排序 
	int method=3;
	switch(method)
	{
	case 1:
		Sort_insert(num,N);break;
	case 2:
		Sort_select(num,N);break;
	case 3:
		Sort_merge(num,N);break;
	default:
		printf("\n没有进行排序");break;
	}
	//打印结果
	printf("\n排序后的数组内容:\n");
	for(int i=0;i<N;++i)
	{
		printf("%d\t",num[i]);
	}

	system("pause");
	return 0;
}
void Sort_insert(int a[],int len)
{
	for(int i=1,j,temp;i<len;++i)
	{
		temp=a[i];
		j=i-1;
		while(a[j]>temp&&j>=0)
		{
			a[j+1]=a[j];
			--j;
		}
		a[j+1]=temp;
	}
}

void Sort_select(int a[],int len)
{
	for(int i=0,temp;i<len-1;++i)
		for(int j=i+1;j<len;++j)
			if(a[i]>a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
}
void Sort_merge(int a[],int len)
{
	static int temp[N];
	if(len>1)
	{
		int mid_point=len/2;
		//先排好左侧
		Sort_merge(a,mid_point);
		//再排好右侧
		Sort_merge(a+mid_point,len-mid_point);
		//merge====================
		//这里要融合的两个数组为
		//   1.   p1开始的长为l1的数组
		//   2.   p2开始的长为l2的数组
		int *p1=a,*p2=a+mid_point;
		int l1=mid_point,l2=len-mid_point;
		int i=0,j=0,k=0;
		//将融合的结果先填到临时数组里
		while(i!=l1&&j!=l2)
		{
			if(p1[i]<p2[j])
				temp[k++]=p1[i++];
			else
				temp[k++]=p2[j++];
		}
		while(i!=l1)
			temp[k++]=p1[i++];
		while(j!=l2)
			temp[k++]=p2[j++];
		//填回原来的数组里
		for(i=0;i<k;i++)
			a[i]=temp[i];
		//========================
	}
}
