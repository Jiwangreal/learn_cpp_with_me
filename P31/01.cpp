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

    pe = &el;//����ָ��ָ��������
    pm = &ml;//������ָ��ָ�����������
    pm2 = &m2;


    //����ָ��ָ����������󣬻��仰���ǣ����������ָ�����ת��Ϊ����ָ�롣����������󿴳ɻ������
    pe = &ml;
    pm = &el;//error,����ָ���޷�ת��Ϊ������ָ�룬�޷���������󿴳������������
            //���������������ü��ϸ����������ǻ���ľ��廯

    el = ml;//������������ת��Ϊ���������Ϊ���Խ���������󿴳��ǻ������
            //����ת��������������и�object slicing
            //���ø�ֵ�������ɵ�

    //������ָ��ת��Ϊ����ָ��
    //˽�л򱣻��̳�ʱ���������ָ�벻����ת��Ϊ����ָ��
    pe = pm2;//�ȼ���pe = &pm2;��Ϊ&pm2������Ҳ��Manager*������error
    pe = static_cast<Employee*>(pm2);//error�������ת������������ʶ��
    pe = (Employee*)(pm2);//C����ǿ��ת���ǿ��Ե�
    pe = reinterpret_cast<Employee*>(pm2);//�ǿ��Ե�

    // e1 = m2;//˽�л򱣻��̳�ʱ,��������󲻿���ת��Ϊ�������error���Զ���ǿ��ת��Ҳ���У����£�
    // e1 = reinterpret_cast<Manager2>(pm2);//error
    // e1 = (Manager2)pm2;//error


    //����ָ��ת��Ϊ������ָ��
    // pm = pe;//error
    pm = static_cast<Manager*>(pe);//�ǿ��Եģ����ǲ���ȫ��peָ����ǻ�����󣬵���pm���Է���level_���ó�Ա������û�е�
    pm2 = static_cast<Manager2*>(pe);//�ǿ��Ե�

    //��������޷�ǿ��ת��Ϊ���������
    ml = el;//error
    ml = static_cast<Manager>(el);//error
    ml = reinterpret_cast<Manager>(el);//error

    return 0;
}

/*
�ع˸���ת��
��̬ת����3�֣�
static_cast ���ڱ������Ͽɵľ�̬ת����eg����char��int����double��int�����߾���ת�����캯��������
������ת�����������
reinterpret_cast ���½��ͣ����ڱ��������Ͽɵľ�̬ת����eg����int *תΪint����ת�͵Ĺ����У������κζ������
const_cast ȥ��������

��̬ת����1�ӣ�
dynamic_cast ���ڶ�̬ת������ȫ������ת�͡����ڶ�̬
*/