#include <iostream>
using namespace std;

int var = 100;
int main(void)
{
	int var = 50;
	cout<<var<<endl;//输出为50
	cout<<::var<<endl;//输出为100
	return 0;
}