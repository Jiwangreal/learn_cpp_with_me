#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintFun(int n)
{
    cout<<n<<' ';
}

void Add3(int& n)
{
    n += 3;
}

//用函数对象方式实现
class PrintObj
{
public:
    void operator()(int n)
    {
        cout<<n<<' ';
    }
};


class Addoobj
{
public:
    Addoobj(int number) number_(number) {}
    void operator()(int& n)
    {
        n += number_;
    }
private:
    //函数对象是有状态的，可以定义一个成员来保存其状态，因为其本质是类对象
    //普通函数是不能保存状态的，除非其内部有静态成员
    int number_;
};

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a+5);

    for_each(v.begin(), v.end(), PrintFun);
    cout<<endl;

    //注意传递的是对象，而不是类名，这里传递的是匿名对象
    for_each(v.begin(), v.end(), PrintObj());
    cout<<endl;

    for_each(v.begin(), v.end(), Add3);
    for_each(v.begin(), v.end(), PrintFun);
    cout<<endl;

    for_each(v.begin(), v.end(), Addoobj(5));
    for_each(v.begin(), v.end(), PrintFun);
    cout<<endl;

    return 0;
}