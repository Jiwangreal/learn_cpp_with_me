#include <iostream>
using namespace std;

/*
struct Link
{
	int data;
	struct Link* next;
};

struct Stack
{
	struct Link* head;
	int size;
};

void StackInit(struct Stack* stack)
{
	stack->head = NULL;
	stack->size = 0;
}

void StackPush(struct Stack* stack, const int data)
{
	struct Link* node;
	node = (struct Link*)malloc(sizeof(struct Link));
	assert(node != NULL);
	node->data = data;
	node->next = stack->head;
	stack->head = node;
	++stack->size;
}

int StackEmpty(struct Stack* stack)
{
	return (stack->size == 0);
}

int StackPop(struct Stack* stack, int* data)
{
	if (StackEmpty(stack))
	{
		return 0;
	}

	struct Link* tmp = stack->head;
	*data = stack->head->data;
	stack->head = stack->head->next;
	free(tmp);
	--stack->size;

	return 1;
}

void StackCleanup(struct Stack* stack)
{
	struct Link* tmp;
	while (stack->head)
	{
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
*/


class Stack
{
	//���ջ���ڲ���������ʵ��
	//Ƕ�����Ĭ�����ݳ�Ա�ǹ��е�
	//�ṹ��ʵ����Ҳ��һ���࣬Ҳ���Զ��幹�캯��
	struct Link
	{
		int data_;
		Link* next_;
		Link(int data, Link* next) : data_(data), next_(next)
		{

		}
	};

public:

	//C�����е�NULL�ǣ�(void*)0
	//C++�е�NULL=0����Ϊ0��ֵ��ָ�룬C++���Զ���ת��
	//ջ�ĳ�ʼ���ù��캯��
	Stack() : head_(0), size_(0)
	{

	}

	//StackCleanupջ���ͷ�������������ʵ��
	~Stack()
	{
		Link* tmp;
		while (head_)
		{
			tmp = head_;
			head_ = head_->next_;
			delete tmp;
		}
	}

	
	void Push(const int data)
	{
		Link* node = new Link(data, head_);
		head_ = node;//Ȼ��ͷָ��ָ���´����Ľڵ�
		++size_;
	}

	bool Empty()
	{
		return (size_ == 0);
	}

	bool Pop(int& data)
	{
		if (Empty())
		{
			return false;
		}

		Link* tmp = head_;
		data = head_->data_;
		head_ = head_->next_;
		delete tmp;//�ͷŵ�ԭ����ͷ�ڵ�
		--size_;

		return true;
	}

private:
	Link* head_;//�����ͷָ��
	int size_;//ջ�Ĵ�С
};

//C++��C����1��
// �������Ƴ�ͻ��C���ԣ�StackPush��C++��Push�������������ڣ���ȫ���õ���
//����ʹ��namespace A
/*
namespace A
{

}
ʹ��ʱ��A::Stack���������ƿռ�A
*/
//C++��C����2��
// ���͵����䣬ָ���ǣ�������

//C++��C����3��
// ���ݷ�װ���ܹ������ڲ������ݽṹ����������ƻ���ָ���ǣ�˽�����ݳ�Ա


int main(void)
{
						
	Stack stack;		// ������������  ������
	int i;
	for (i=0; i<5; i++)
	{
		//��C��ȣ�ÿ�������Ĵ��ݲ��ش���ջ�ĵ�ַ
		//StackPush(&stack, i);
		stack.Push(i);		// ��ʵ��һ�������ǣ�this = &stack����������thisָ�룬ָ��stack
	}

	//while (!StackEmpty(&stack))
	while (!stack.Empty())
	{
		//StackPop(&stack, &i);
		//printf("%d ", i);
		stack.Pop(i);
		cout<<i<<" ";
	}
	//printf("\n");
	cout<<endl;

	return 0;
}