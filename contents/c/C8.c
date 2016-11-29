#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//windows�����װ��Visual Leak Detector���Բ鿴�ڴ�й©
//#include <vld.h>
//linux�ȿ�����valgrind�鿴�ڴ�й©

struct node
{
	int val;
	node *next;
};
//��ȡ����
int LenTable(node* head)
{
	int i=0;
	for(;head!=nullptr;++i,head=head->next);
	return i;
}
//������̬���� ��Ϊsize
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
//��ӡһ��start��ͷ������
void PrintTable(node* start)
{
	if(start==nullptr)
		printf("�����ǿյ�");
	while(start!=nullptr)
	{
		printf("%d",start->val);
		start=start->next;
		if(start!=nullptr)
			printf("->");
	}
	printf("\n");
}
//�ͷ�һ��������ڴ�
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
//����ֵ
void valExchange(node* p1,node *p2)
{
	int temp=p1->val;
	p1->val=p2->val;
	p2->val=temp;
}
//���ý���ֵ�ķ�ʽ����
void valSortTable(node* head)
{
	for(node*p=head;p->next!=nullptr;p=p->next)
		for(node*q=p->next;q!=nullptr;q=q->next)
			if(p->val > q->val)
				valExchange(p,q);
}

//������������
// 1.2. �������������
// 3.   head���
// ���head��Ҫ�޸ķ����޸ĺ��head
node* nodeExchange(node *p1, node* p2, node* head)
{
	node *bp1=head,*bp2=head,*temp;
	while(bp1!=nullptr && bp1->next!=p1) bp1=bp1->next;
	while(bp2!=nullptr && bp2->next!=p2 ) bp2=bp2->next;
	if(bp1==nullptr&&bp2==nullptr) return head;//��������

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
//���ý���node����,���ظı���head
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
	printf("����������: ");
	scanf("%d",&size);


	///part1 ��̬����
	{
		//����
		node* head=(node*)malloc(sizeof(node)*size);
		   //��ֵ
		for(int i=0;i<size;++i)
			head[i].val=rand();
		   //��
		for(int i=0;i<size-1;++i)
			head[i].next=head+(i+1);
		head[size-1].next=nullptr;
		//������
		printf("����Ϊ: %d\n",LenTable(head));
		//��ӡ
		printf("����ǰ: ");
		PrintTable(head);
		//����
		valSortTable(head);
		//�����
		printf("�����: ");
		PrintTable(head);
		//�����ڴ�
		free(head);
	}


	///part2 ��̬����
	{
		//����
		node* head=MakeTable(size);
		//������
		printf("����Ϊ: %d\n",LenTable(head));
		//��ӡ
		printf("����ǰ: ");
		PrintTable(head);
		//����
		head=nodeSortTable(head);
		//�����
		printf("�����: ");
		PrintTable(head);
		//�����ڴ�
		DeleteTable(head);
	}


	system("pause");
	return 0;
}