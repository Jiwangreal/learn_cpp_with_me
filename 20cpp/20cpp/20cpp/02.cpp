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
	//这个栈的内部用链表来实现
	//嵌套类的默认数据成员是公有的
	//结构体实际上也是一个类，也可以定义构造函数
	struct Link
	{
		int data_;
		Link* next_;
		Link(int data, Link* next) : data_(data), next_(next)
		{

		}
	};

public:

	//C语言中的NULL是：(void*)0
	//C++中的NULL=0，因为0赋值给指针，C++会自动做转换
	//栈的初始化用构造函数
	Stack() : head_(0), size_(0)
	{

	}

	//StackCleanup栈的释放用析构函数来实现
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
		head_ = node;//然后将头指针指向新创建的节点
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
		delete tmp;//释放掉原来的头节点
		--size_;

		return true;
	}

private:
	Link* head_;//链表的头指针
	int size_;//栈的大小
};

//C++与C区别（1）
// 避免名称冲突，C语言：StackPush，C++是Push，作用域在类内，完全不用担心
//或者使用namespace A
/*
namespace A
{

}
使用时：A::Stack，加上名称空间A
*/
//C++与C区别（2）
// 类型的扩充，指的是：类类型

//C++与C区别（3）
// 数据封装、能够保护内部的数据结构不遭受外界破坏，指的是：私有数据成员


int main(void)
{
						
	Stack stack;		// 抽象数据类型  类类型
	int i;
	for (i=0; i<5; i++)
	{
		//与C相比，每个函数的传递不必传递栈的地址
		//StackPush(&stack, i);
		stack.Push(i);		// 其实第一个参数是：this = &stack，是隐含的this指针，指向stack
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