#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//栈内部的数据结构用链表来表示
struct Link
{
	int data;//链表存储的数据类型
	struct Link* next;//链表的指针域
};

struct Stack
{
	struct Link* head;//指向链表头节点的指针
	int size;//栈的大小
};

//栈的初始化
void StackInit(struct Stack* stack)
{
	stack->head = NULL;//栈的头指针置为空
	stack->size = 0;//栈的大小为0
}

//入栈：往栈中压入一个数据项
void StackPush(struct Stack* stack, const int data)
{
	//先创建一个节点
	struct Link* node;
	node = (struct Link*)malloc(sizeof(struct Link));
	assert(node != NULL);
	node->data = data;
	node->next = stack->head;//新创建一个节点node，其next指针域应指向头节点
	stack->head = node;//然后将头指针指向新创建的节点
	++stack->size;
}

int StackEmpty(struct Stack* stack)
{
	return (stack->size == 0);
}

//出栈
int StackPop(struct Stack* stack, int* data)
{
	//判定栈是否为空，只需盘点栈的大小是否为0
	if (StackEmpty(stack))
	{
		return 0;
	}

	//保存原来的头节点，因为头节点发生了改变，所以要保存原来的头节点
	struct Link* tmp = stack->head;
	
	//将头节点出栈
	*data = stack->head->data;
	//将头指针指向下一个节点
	stack->head = stack->head->next;

	//把一个节点出栈，所以要将以前的头节点释放掉
	free(tmp);
	--stack->size;

	return 1;
}

void StackCleanup(struct Stack* stack)
{
	struct Link* tmp;
	while (stack->head)
	{
		//tmp指向下一个节点，然后将tmp释放掉
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}

	stack->size = 0;
}

int main(void)
{
	struct Stack stack;
	StackInit(&stack);
	int i;
	for (i=0; i<5; i++)
	{
		StackPush(&stack, i);
	}

	while (!StackEmpty(&stack))
	{
		StackPop(&stack, &i);
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}