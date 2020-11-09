#include <iostream>
#include <string>
using namespace std;

class Manager;//因为operator Manager() ，所以需要前向声明
class Employee
{
public:
    Employee(const string& name, const int age, const int deptno) : name_(name),
        age_(age), deptno_(deptno)
    {

    }
    //将Employee转换为Manager类型
    operator Manager();

    //下面这样写是错的，因为在这俩类在同一个文件中，只有Manager的前向声明，看不到Manager的定义，也就看不到Manager类的构造函数，error
    // operator Manager()
    // {
    //     return Manager(name_, age_, deptno_, -1);
    // }


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

    Manager(const Employee& other) : Employee(other), level_(-1) 
    {

    }
private:
    int level_;
};

//仅仅是从语法上演示基类对象可以转化为派生类对象，但是没有意义
//目的是要理解转换构造函数与类型运算符重载的区别
//把它放在Manager类的定义之后，这样才能看到Manager的构造函数
Employee::operator Manager()
{
    return Manager(name_, age_, deptno_, -1);//构造Manager对象
}


int main(void)
{
    Employee el("zhangsan", 25, 20);
    Manager ml("lisi", 38, 20, 10);

    //方法（2）：类型转换运算符重载：将类类型转换为其他类型
    //将基类对象转换为派生类对象
    m1 = e1;
    return 0;
}