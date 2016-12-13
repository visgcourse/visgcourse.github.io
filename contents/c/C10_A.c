#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType;

struct stack_node
{
	ElemType val;
	stack_node *next;
};

stack_node * create()
{
	return nullptr;
}

stack_node * push(stack_node * head, ElemType val)
{
	stack_node* val_node=(stack_node*)malloc(sizeof(stack_node));
	if(!val_node)return val_node;
	val_node->val=val;
	val_node->next=head;
	return val_node;
}

stack_node * pop(stack_node * head, ElemType* out_val=nullptr)
{
	stack_node * pop_node=head;
	head=head->next;
	if(out_val)
		*out_val=pop_node->val;
	free(pop_node);
	return head;
}

stack_node * clear(stack_node * head)
{
	ElemType temp;
	while(!pop(head,&temp));
	return nullptr;
}

void print(stack_node * head)
{
	printf("当前内容: ");
	while(head)
	{
		printf("%c ",head->val);
		head=head->next;
	}
	printf("\n");
}


int main()
{
	stack_node* head=create();
	head=push(head,'e');
	head=push(head,'e');
	head=push(head,'u');
	head=push(head,'j');
	head=push(head,'n');
	print(head);
	ElemType t;
	head=pop(head,&t);
	printf("刚刚取出了%c\n",t);
	print(head);
	head=push(head,'N');
	print(head);
	head=clear(head);
	print(head);

	system("pause");
	return 0;
}