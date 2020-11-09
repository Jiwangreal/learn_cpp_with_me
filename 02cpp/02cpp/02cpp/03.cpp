#include <iostream>
using namespace std;

#define STR(a) #a
#define CAT(a,b) a##b

int main(void)
{
	int xy = 100;
	cout<<STR(ABCD)<<endl;			//#ABCD <=> "ABCD"     转换为字符串，输出为ABCD
	cout<<CAT(x, y)<<endl;			//x##y  <=> xy			输出为100
	return 0;
}