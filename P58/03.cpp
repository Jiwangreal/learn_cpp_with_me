#include <iostream>

using namespace std;

int main(void)
{
    int n = 100;
    int n2 = 200;
    cout <<n<<" "<<n2<<endl;

    //put是ostream类的一个成员函数
    //put方法的返回值也是ostream对象的引用，所以也可以连续使用
    cout.put('H');
    cout.put('i');
    cout.put(' ');
    cout.put('H').put('i').put('\n');


    return 0;
}