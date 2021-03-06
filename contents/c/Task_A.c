#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char *name;
	float score;
	struct node *next;
};

/* 这部分函数操作单个结点,与链表是否有头节点无关 */
void InsertNode(node* pos,node* In);
void FreeNode(node* pos);
void PrintNode(node* pos);
void SetNodeName(node* p, const char*str);

void SetNodeName(node* p, const char*str)
{
	if(p->name)
		free(p->name);
	p->name=(char*)malloc(sizeof(char)*(1+strlen(str)));
	memcpy(p->name,str,strlen(str)+1);
}
void InsertNode(node* pos,node* In)
{
	node* p=pos->next;
	pos->next=In;
	In->next=p;
}
void FreeNode(node* pos)
{
	if(pos)
	{
		if(pos->name)
			free(pos->name);
		free(pos);
	}
}
void PrintNode(node* pos)
{
	if(pos->name)
		printf("name:%s\t",pos->name);
	printf("score:%f\n",pos->score);
}


/* 链表类型, 表示是否有头节点 */
enum _type
{
	HEADNODE,NOHEADNODE
};

/* 链表相关的函数 除了删除[DeleteTable]外其它函数对于不同类型的实现不同,使用switch-case控制 */
node* BuildTable(int _size, _type _t=_type::NOHEADNODE);
void PrintTable(node* head,  _type _t);
int GetLenTable(node* head, _type);
void DeleteTable(node* head);
node* InsertTable(node* head, _type _t, node* In, int pos);
node* DeleteNode(node* head, _type _t, int pos);
void FindNode(node* head, _type _t, const char* _Name);

node* BuildTable(int _size, _type _t)
{
	node * head,*p;
	switch(_t)
	{
	case _type::HEADNODE:
		head = new node();
		head->name=nullptr;
		head->score=_size;
		p=head;
		for(int i=0;i<_size;++i)
		{
			p->next=new node();
			p->next->score=i;
			p->next->name=nullptr;
			p=p->next;
		}
		p->next=nullptr;
		break;
	case _type::NOHEADNODE:
		head=nullptr;
		if(_size>0)
		{
			p=new node();
			p->name=nullptr;
			p->score=0;
			head=p;
		}
		for(int i=1;i<_size;++i)
		{
			p->next=new node();
			p->next->score=i;
			p->next->name=nullptr;
			p=p->next;
		}
		p->next=nullptr;
		break;
	default:
		break;
	}
	return head;
}
void PrintTable(node* head, _type _t)
{
	if(_t==_type::HEADNODE)
		head=head->next;
	while(head)
	{
		PrintNode(head);
		head=head->next;
	}
}
int GetLenTable(node* head, _type _t)
{
	switch(_t)
	{
	case _type::HEADNODE:
		return head->score;
	case _type::NOHEADNODE:
		int i;
		for(i=0;head;++i,head=head->next);
		return i;
	default:
		return 0;
	}
}
void DeleteTable(node* head)
{
	node*p;
	while(head)
	{
		p=head->next;
		FreeNode(head);
		head=p;
	}	
}
node* InsertTable(node* head, _type _t, node* In, int pos)
{
	if(pos>GetLenTable(head,_t))
		return head;
	node* p=head;
	switch(_t)
	{
	case _type::HEADNODE:
		for(int i=0;i<pos;++i,p=p->next);
		InsertNode(p,In);
		++head->score;
	case _type::NOHEADNODE:
		if(pos==0)
		{
			In->next=p;
			head=In;
		}
		else
		{
			for(int i=1;i<pos;++i,p=p->next);
			InsertNode(p,In);
		}
	}
	return head;
}
node* DeleteNode(node* head, _type _t, int pos)
{
	if(pos>=GetLenTable(head,_t))
		return head;
	node* p=head,*q;
	switch(_t)
	{
	case _type::HEADNODE:
		for(int i=0;i<pos;++i,p=p->next);
		q=p->next;
		if(q)
		{	
			p->next=q->next;
			FreeNode(q);
		}
		--head->score;
		break;
	case _type::NOHEADNODE:
		if(pos==0)
		{
			p=p->next;
			FreeNode(head);
			head=p;
		}
		else
		{
			for(int i=1;i<pos;++i,p=p->next);
			q=p->next;
			if(q)
			{	
				p->next=q->next;
				FreeNode(q);
			}
		}
		break;
	}
	return head;
}
void FindNode(node* head, _type _t, const char* _Name)
{
	switch(_t)
	{
	case _type::HEADNODE:
		head=head->next;
		break;
	case _type::NOHEADNODE:
		break;
	}
	int i=0;
	while(head)
	{
		if(head->name && !strcmp(head->name,_Name))
		{
			printf("%3d. ",i+1);
			PrintNode(head);
			//return head;
		}
		head=head->next;++i;
	}
	//return nullptr;
}


int main()
{
	int i=0,size;
	printf("输入链表长度: ");
	scanf("%d",&size);
	_type t=_type::NOHEADNODE;
	node* head,*n;

	//NoHead
	n=(node*)malloc(sizeof(node));
	n->score=123;
	n->name=nullptr;
	SetNodeName(n,"liupeng");

	head=BuildTable(size,t);
	head=InsertTable(head,t,n,2);
	head=DeleteNode(head,t,5);
	PrintTable(head,t);
	printf("FindResult:\n");
	FindNode(head,t,"liupeng");
	printf("%d\n",GetLenTable(head,t));
	DeleteTable(head);

	printf("<NoHead===============\n=================Head>\n");
	//Head
	n=(node*)malloc(sizeof(node));
	n->score=123;
	n->name=nullptr;
	SetNodeName(n,"liupeng");
	t=_type::HEADNODE;

	head=BuildTable(size,t);
	head=InsertTable(head,t,n,2);
	head=DeleteNode(head,t,5);
	PrintTable(head,t);
	printf("FindResult:\n");
	FindNode(head,t,"liupeng");
	printf("%d\n",GetLenTable(head,t));
	DeleteTable(head);


	system("pause");
	return 0;
}