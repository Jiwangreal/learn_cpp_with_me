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
private:
    int level_;
};

class Manager2 : private Employee
{
public:
    Manager(const string& name, const int age, const int deptno, int level)
        : Employee(name, age, deptno, level), level_(level)
private:
    int level_;
};


int main(void)
{
    Employee el("zhangsan", 25, 20);
    Manager ml("lisi", 38, 20, 10);
    Manager2 m2("wangwu", 40, 15, 8);
    Employee* pe;
    Manager* pm;
    Manager2* pm2;

    pe = &el;//基类指针指向基类对象
    pm = &ml;//派生类指针指向派生类对象
    pm2 = &m2;


    //基类指针指向派生类对象，换句话就是：派生类对象指针可以转化为基类指针。将派生类对象看成基类对象
    pe = &ml;
    pm = &el;//error,基类指针无法转化为派生类指针，无法将基类对象看成是派生类对象。
            //基类比派生类的适用集合更大，派生类是基类的具体化

    el = ml;//派生类对象可以转化为基类对象。因为可以将派生类对象看成是基类对象
            //对象转化，会产生对象切割object slicing
            //调用赋值运算符完成的

    //派生类指针转换为基类指针
    //私有或保护继承时，生类对象指针不可以转化为基类指针
    pe = pm2;//等价于pe = &pm2;因为&pm2的类型也是Manager*，都是error
    pe = static_cast<Employee*>(pm2);//error，这里的转化编译器不认识这
    pe = (Employee*)(pm2);//C风格的强制转化是可以的
    pe = reinterpret_cast<Employee*>(pm2);//是可以的

    // e1 = m2;//私有或保护继承时,派生类对象不可以转化为基类对象，error，自动或强制转化也不行，如下：
    // e1 = reinterpret_cast<Manager2>(pm2);//error
    // e1 = (Manager2)pm2;//error


    //基类指针转化为派生类指针
    // pm = pe;//error
    pm = static_cast<Manager*>(pe);//是可以的，但是不安全，pe指向的是基类对象，但是pm可以访问level_，该成员基类是没有的
    pm2 = static_cast<Manager2*>(pe);//是可以的

    //基类对象无法强制转化为派生类对象
    ml = el;//error
    ml = static_cast<Manager>(el);//error
    ml = reinterpret_cast<Manager>(el);//error

    return 0;
}

/*
回顾各种转化
静态转化：3种：
static_cast 用于编译器认可的静态转化，eg：从char到int，从double到int，或者具有转换构造函数，或者
重载了转换类型运算符
reinterpret_cast 重新解释，用于编译器不认可的静态转换。eg：从int *转为int，在转型的过程中，不做任何对齐操作
const_cast 去除常量性

动态转化：1钟：
dynamic_cast 用于动态转换，安全的向下转型。用于多态
*/