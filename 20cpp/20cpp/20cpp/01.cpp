#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//ջ�ڲ������ݽṹ����������ʾ
struct Link
{
	int data;//����洢����������
	struct Link* next;//�����ָ����
};

struct Stack
{
	struct Link* head;//ָ������ͷ�ڵ��ָ��
	int size;//ջ�Ĵ�С
};

//ջ�ĳ�ʼ��
void StackInit(struct Stack* stack)
{
	stack->head = NULL;//ջ��ͷָ����Ϊ��
	stack->size = 0;//ջ�Ĵ�СΪ0
}

//��ջ����ջ��ѹ��һ��������
void StackPush(struct Stack* stack, const int data)
{
	//�ȴ���һ���ڵ�
	struct Link* node;
	node = (struct Link*)malloc(sizeof(struct Link));
	assert(node != NULL);
	node->data = data;
	node->next = stack->head;//�´���һ���ڵ�node����nextָ����Ӧָ��ͷ�ڵ�
	stack->head = node;//Ȼ��ͷָ��ָ���´����Ľڵ�
	++stack->size;
}

int StackEmpty(struct Stack* stack)
{
	return (stack->size == 0);
}

//��ջ
int StackPop(struct Stack* stack, int* data)
{
	//�ж�ջ�Ƿ�Ϊ�գ�ֻ���̵�ջ�Ĵ�С�Ƿ�Ϊ0
	if (StackEmpty(stack))
	{
		return 0;
	}

	//����ԭ����ͷ�ڵ㣬��Ϊͷ�ڵ㷢���˸ı䣬����Ҫ����ԭ����ͷ�ڵ�
	struct Link* tmp = stack->head;
	
	//��ͷ�ڵ��ջ
	*data = stack->head->data;
	//��ͷָ��ָ����һ���ڵ�
	stack->head = stack->head->next;

	//��һ���ڵ��ջ������Ҫ����ǰ��ͷ�ڵ��ͷŵ�
	free(tmp);
	--stack->size;

	return 1;
}

void StackCleanup(struct Stack* stack)
{
	struct Link* tmp;
	while (stack->head)
	{
		//tmpָ����һ���ڵ㣬Ȼ��tmp�ͷŵ�
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