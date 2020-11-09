#include <iostream>
#include <string>
using namespace std;

class Manager;//��Ϊoperator Manager() ��������Ҫǰ������
class Employee
{
public:
    Employee(const string& name, const int age, const int deptno) : name_(name),
        age_(age), deptno_(deptno)
    {

    }
    //��Employeeת��ΪManager����
    operator Manager();

    //��������д�Ǵ�ģ���Ϊ����������ͬһ���ļ��У�ֻ��Manager��ǰ��������������Manager�Ķ��壬Ҳ�Ϳ�����Manager��Ĺ��캯����error
    // operator Manager()
    // {
    //     return Manager(name_, age_, deptno_, -1);
    // }


private:
    string name_;
    int age_;
    int deptno_;//���ź�
};

//������̳���Ա����
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

//�����Ǵ��﷨����ʾ����������ת��Ϊ��������󣬵���û������
//Ŀ����Ҫ���ת�����캯����������������ص�����
//��������Manager��Ķ���֮���������ܿ���Manager�Ĺ��캯��
Employee::operator Manager()
{
    return Manager(name_, age_, deptno_, -1);//����Manager����
}


int main(void)
{
    Employee el("zhangsan", 25, 20);
    Manager ml("lisi", 38, 20, 10);

    //������2��������ת����������أ���������ת��Ϊ��������
    //���������ת��Ϊ���������
    m1 = e1;
    return 0;
}