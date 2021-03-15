#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using  namespace std;

class Person
{
public:
    Person( const string &name) : name_(name) {}
     void Print()  const
    {
        cout << name_ << endl;
    }
     void PrintWithPrefix(string prefix)  const
    {
        cout << prefix << name_ << endl;
    }
private:
    string name_;
};

void foo( const vector<Person> &v)
{
    //for_each接收的是一元的函数对象
    // mem_fun_ref将不带参数的成员函数转换成一元函数对象，将print()成员函数转换成立一元函数对象
    // mem_fun_ref是一个函数适配器
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::Print));
    //mem_fun_ref将带一个参数的成员函数转换成二元函数对象
    //称之为：mem_fun_ref函数模板的类型自动推导功能，可以根据传递进来的参数进行类型推导
    for_each(v.begin(), v.end(), bind2nd(mem_fun_ref(&Person::PrintWithPrefix),  "person: "));
}

void foo2( const vector<Person *> &v)
{
    //mem_fun_ref用于容器里面的元素是对象
    //mem_fun用于容器里面的元素是指针
    for_each(v.begin(), v.end(), mem_fun(&Person::Print));
    for_each(v.begin(), v.end(), bind2nd(mem_fun(&Person::PrintWithPrefix),  "person: "));
}

int main( void)
{
    vector<Person> v;
    v.push_back(Person( "tom"));
    v.push_back(Person( "jerry"));
    foo(v);

    //向量中存放的是对象指针
    vector<Person *> v2;
    v2.push_back( new Person( "tom"));
    v2.push_back( new Person( "jerry"));
    foo2(v2);
     return  0;
}