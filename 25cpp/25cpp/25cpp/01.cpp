#include "Integer.h"
#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main(void)
{
	Integer n(100);
	n = 200;//ͨ��ת�����캯��Integer(int n);Ҳ�й��캯�������Խ�200ת��Ϊ�����ͣ���ֵ��n
	n.Display();

	int sum = add(n, 100);

	cout<<sum<<endl;

	int x = n;//��ʽת������������ת�������operator int();
	int y = static_cast<int>(n);//��ʾת������������ת�������operator int();

	return 0;
}