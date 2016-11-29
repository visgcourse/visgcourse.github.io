#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//windows如果安装了Visual Leak Detector可以查看内存泄漏
//#include <vld.h>
//linux等可以用valgrind查看内存泄漏

struct node
{
	int val;
	node *next;
};
//获取长度
int LenTable(node* head)
{
	int i=0;
	for(;head!=nullptr;++i,head=head->next);
	return i;
}
//创建动态链表 长为size
node* MakeTable(int size)
{
	node* head=nullptr,*p=nullptr;
	for(int i=0;i<size;++i)
	{
		if(i==0)
		{
			head=(node*)malloc(sizeof(node));
			p=head;
		}
		else
		{
			p->next=(node*)malloc(sizeof(node));
			p=p->next;
		}
		p->val=rand();
	}
	if(p!=nullptr)
		p->next=nullptr;
	return head;
}
//打印一个start开头的链表
void PrintTable(node* start)
{
	if(start==nullptr)
		printf("链表是空的");
	while(start!=nullptr)
	{
		printf("%d",start->val);
		start=start->next;
		if(start!=nullptr)
			printf("->");
	}
	printf("\n");
}
//释放一个链表的内存
void DeleteTable(node* head)
{
	node *p;
	while(head!=nullptr)
	{
		p=head->next;
		delete(head);
		head=p;
	}
}
//交换值
void valExchange(node* p1,node *p2)
{
	int temp=p1->val;
	p1->val=p2->val;
	p2->val=temp;
}
//利用交换值的方式排序
void valSortTable(node* head)
{
	for(node*p=head;p->next!=nullptr;p=p->next)
		for(node*q=p->next;q!=nullptr;q=q->next)
			if(p->val > q->val)
				valExchange(p,q);
}

//输入三个参数
// 1.2. 交换的两个结点
// 3.   head结点
// 如果head需要修改返回修改后的head
node* nodeExchange(node *p1, node* p2, node* head)
{
	node *bp1=head,*bp2=head,*temp;
	while(bp1!=nullptr && bp1->next!=p1) bp1=bp1->next;
	while(bp2!=nullptr && bp2->next!=p2 ) bp2=bp2->next;
	if(bp1==nullptr&&bp2==nullptr) return head;//输入有误

	if(bp1!=nullptr)
		bp1->next=p2;
	else
		head=p2;

	if(bp2!=nullptr)
		bp2->next=p1;
	else
		head=p1;


	temp=p2->next;
	if(p1->next==p2)
		p2->next=p1;
	else
		p2->next=p1->next;

	if(temp==p1)
		p1->next=p2;
	else
		p1->next=temp;

	return head;
}
//利用交换node排序,返回改变后的head
node* nodeSortTable(node* head)
{
	node* temp;
	for(node*p=head;p->next!=nullptr;p=p->next)
		for(node*q=p->next;q!=nullptr;q=q->next)
			if(p->val > q->val)
			{
				head=nodeExchange(p,q,head);
				temp=p;
				p=q;
				q=temp;
			}
	return head;
}

int main()
{
	//srand(time(NULL));
	int i=0,size;
	printf("输入链表长度: ");
	scanf("%d",&size);


	///part1 静态链表
	{
		//创建
		node* head=(node*)malloc(sizeof(node)*size);
		   //赋值
		for(int i=0;i<size;++i)
			head[i].val=rand();
		   //链
		for(int i=0;i<size-1;++i)
			head[i].next=head+(i+1);
		head[size-1].next=nullptr;
		//链表长度
		printf("长度为: %d\n",LenTable(head));
		//打印
		printf("排序前: ");
		PrintTable(head);
		//排序
		valSortTable(head);
		//排序后
		printf("排序后: ");
		PrintTable(head);
		//清理内存
		free(head);
	}


	///part2 动态链表
	{
		//创建
		node* head=MakeTable(size);
		//链表长度
		printf("长度为: %d\n",LenTable(head));
		//打印
		printf("排序前: ");
		PrintTable(head);
		//排序
		head=nodeSortTable(head);
		//排序后
		printf("排序后: ");
		PrintTable(head);
		//清理内存
		DeleteTable(head);
	}


	system("pause");
	return 0;
}