#include "add.h"
#include "sub.h"
#include <iostream>		// for cout
using namespace std;	// ���������ռ�

int main(void)
{
	int a = 10;
	int b =3;
	cout<<"hello world!"<<endl;
	cout<<"a+b="<<add(a, b)<<endl;
	cout<<"a-b="<<sub(a, b)<<endl;
	return 0;
}