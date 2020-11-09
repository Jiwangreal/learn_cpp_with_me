#include <iostream>
using namespace std;



class Test
{
public:
	Test(int n) : n_(n)
	{
		cout<<"Test(int n) : n_(n)"<<endl;
	}
	//拷贝构造函数
	Test(const Test& other)
	{
		cout<<"Test(const Test& other)"<<endl;
	}
	//析构函数不能被重载，只能有一个
	~Test()
	{
		cout<<"~Test()"<<endl;
	}

	void* operator new(size_t size)
	{
		cout<<"void* operator new(size_t size)"<<endl;
		void* p = malloc(size);
		return p;
	}

	void operator delete(void* p)
	{
		cout<<"void operator delete(void* p)"<<endl;
		free(p);
	}

	void operator delete(void* p, size_t size)
	{
		cout<<"void operator delete(void* p, size_t size)"<<endl;
		free(p);
	}

	void* operator new(size_t size, const char* file, long line)
	{
		//打印哪一个文件，哪一行
		cout<<file<<":"<<line<<endl;
		void* p = malloc(size);
		return p;
	}

	void operator delete(void* p, const char* file, long line)
	{
		//打印哪一个文件，哪一行
		cout<<file<<":"<<line<<endl;
		free(p);
	}

	void operator delete(void* p, size_t size, const char* file, long line)
	{
		cout<<file<<":"<<line<<endl;
		free(p);
	}

	//placement new的用法如下：
	//这是局部的 placement new，已经存在的内存地址，直接返回就可以了，内部不需要分配空间
	//所以相应的delete不需要做任何的操作
	void* operator new(size_t size, void* p)
	{
		return p;
	}

	void operator delete(void *, void *)
	{
	}

	int n_;
};

void* operator new(size_t size)
{
	cout<<"global void* operator new(size_t size)"<<endl;
	void* p = malloc(size);
	return p;
}

void operator delete(void* p)
{
	cout<<"global void operator delete(void* p)"<<endl;
	free(p);
}

void* operator new[](size_t size)
{
	cout<<"global void* operator new[](size_t size)"<<endl;
	void* p = malloc(size);
	return p;
}

void operator delete[](void* p)
{
	cout<<"global void operator delete[](void* p)"<<endl;
	free(p);
}

int main(void)
{
	//new operator用法
	Test* p1 = new Test(100);	// 称作是：new operator，new operator = operator new内存分配 + 构造函数的调用
	delete p1;

	//这个是全局的operator new操作
	char* str = new char[100];
	delete[] str;

	char chunk[10];

	//placement new用法
	//在chunk这块内存上进行new操作
	//返回的是p2指针就等于chunk的地址
	//p2的地址就等于chunk地址，4个字节的Test对象使用的空间就是chunk空间的4个字节
	Test* p2 = new (chunk) Test(200);	//operator new(size_t, void *_Where)
										// placement new，不分配内存 + 构造函数的调用
	cout<<p2->n_<<endl;
	p2->~Test();						// 显式调用析构函数，析构函数可以被显式调用的
										//不能使用delete p2，因为它不是堆上生成的内存，它的内存在已经存在的chunk内存中
										//所以要使用显式调用析构函数的方式来调用

	//强制转换
	//Test* p3 = (Test*)chunk;等价于下面的类型转换
	Test* p3 = reinterpret_cast<Test*>(chunk);
	cout<<p3->n_<<endl;



	//Test* p4 = new(__FILE__, __LINE__) Test(300);//传递的是operator new+构造函数的调用，operator不仅
													//传递了对象的大小300，还传递了__FILE__, __LINE__
	//delete(__FILE__, __LINE__) p4;delete p4(__FILE__, __LINE__);都没有调用与上面想对应的delete函数，后期有空可以研究下

//__FILE__表示这行所在的文件
//__LINE__表示这行所在的行号
#define new new(__FILE__, __LINE__)
	Test* p4 = new Test(300);
	delete p4;

	return 0;
}