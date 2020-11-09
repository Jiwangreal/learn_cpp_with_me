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
    int deptno_;//���ź�
};

//������̳���Ա����
class Manager : public Employee
{
public:
    Manager(const string& name, const int age, const int deptno, int level)
        : Employee(name, age, deptno, level), level_(level)

    //���﷨������ʾ����������ת��Ϊ��������󣬵���û������
    //��һ�������Ĺ��캯������֮Ϊת�����캯��
    Manager(const Employee& other) : Employee(other), level_(-1) 
    {

    }
private:
    int level_;
};

//�������ת��Ϊ����������ǿ���ת���ģ�����������ȥ����ʵ��
//����ʵ�֣�������ܶ���������
//�﷨���ǿ���ת����

int main(void)
{
    Employee el("zhangsan", 25, 20);
    Manager ml("lisi", 38, 20, 10);

    //����(1)��ת�����캯��������������ת��Ϊ������
    m1 = e1;
    return 0;
}