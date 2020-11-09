#include <iostream>
using namespace std;



class Test
{
public:
	Test(int n) : n_(n)
	{
		cout<<"Test(int n) : n_(n)"<<endl;
	}
	//�������캯��
	Test(const Test& other)
	{
		cout<<"Test(const Test& other)"<<endl;
	}
	//�����������ܱ����أ�ֻ����һ��
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
		//��ӡ��һ���ļ�����һ��
		cout<<file<<":"<<line<<endl;
		void* p = malloc(size);
		return p;
	}

	void operator delete(void* p, const char* file, long line)
	{
		//��ӡ��һ���ļ�����һ��
		cout<<file<<":"<<line<<endl;
		free(p);
	}

	void operator delete(void* p, size_t size, const char* file, long line)
	{
		cout<<file<<":"<<line<<endl;
		free(p);
	}

	//placement new���÷����£�
	//���Ǿֲ��� placement new���Ѿ����ڵ��ڴ��ַ��ֱ�ӷ��ؾͿ����ˣ��ڲ�����Ҫ����ռ�
	//������Ӧ��delete����Ҫ���κεĲ���
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
	//new operator�÷�
	Test* p1 = new Test(100);	// �����ǣ�new operator��new operator = operator new�ڴ���� + ���캯���ĵ���
	delete p1;

	//�����ȫ�ֵ�operator new����
	char* str = new char[100];
	delete[] str;

	char chunk[10];

	//placement new�÷�
	//��chunk����ڴ��Ͻ���new����
	//���ص���p2ָ��͵���chunk�ĵ�ַ
	//p2�ĵ�ַ�͵���chunk��ַ��4���ֽڵ�Test����ʹ�õĿռ����chunk�ռ��4���ֽ�
	Test* p2 = new (chunk) Test(200);	//operator new(size_t, void *_Where)
										// placement new���������ڴ� + ���캯���ĵ���
	cout<<p2->n_<<endl;
	p2->~Test();						// ��ʽ�������������������������Ա���ʽ���õ�
										//����ʹ��delete p2����Ϊ�����Ƕ������ɵ��ڴ棬�����ڴ����Ѿ����ڵ�chunk�ڴ���
										//����Ҫʹ����ʽ�������������ķ�ʽ������

	//ǿ��ת��
	//Test* p3 = (Test*)chunk;�ȼ������������ת��
	Test* p3 = reinterpret_cast<Test*>(chunk);
	cout<<p3->n_<<endl;



	//Test* p4 = new(__FILE__, __LINE__) Test(300);//���ݵ���operator new+���캯���ĵ��ã�operator����
													//�����˶���Ĵ�С300����������__FILE__, __LINE__
	//delete(__FILE__, __LINE__) p4;delete p4(__FILE__, __LINE__);��û�е������������Ӧ��delete�����������пտ����о���

//__FILE__��ʾ�������ڵ��ļ�
//__LINE__��ʾ�������ڵ��к�
#define new new(__FILE__, __LINE__)
	Test* p4 = new Test(300);
	delete p4;

	return 0;
}