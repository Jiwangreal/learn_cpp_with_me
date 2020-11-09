#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    Employee(const string& name, const int age, const int deptno) : name_(name),
        age_(age), deptno_(deptno)
    {

    }
private:
    string name_;
    int age_;
    int deptno_;//部门号
};

//经理类继承至员工类
class Manager : public Employee
{
public:
    Manager(const string& name, const int age, const int deptno, int level)
        : Employee(name, age, deptno, level), level_(level)

    //从语法上来演示基类对象可以转化为派生类对象，但是没有意义
    //带一个参数的构造函数，称之为转换构造函数
    Manager(const Employee& other) : Employee(other), level_(-1) 
    {

    }
private:
    int level_;
};

//基类对象转换为派生类对象是可以转换的，但是往往不去这样实现
//这样实现，会带来很多的语义错误
//语法上是可以转换的

int main(void)
{
    Employee el("zhangsan", 25, 20);
    Manager ml("lisi", 38, 20, 10);

    //方法(1)：转换构造函数：将其他类型转换为类类型
    m1 = e1;
    return 0;
}