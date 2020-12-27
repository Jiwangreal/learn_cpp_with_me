#include <iostream>
#include <memory>
using namespace std;

//ΪʲôNoncopyable���ǽ�ֹ�����ģ�
//��1�������á���ֹ���󿽱���eg��ʾ
//Noncopyable���ܹ��������Ϊ�������û���壬���������̳�
class Noncopyable
{
protected:
    Noncopyable() {};
    ~Noncopyable() {};
private:
    Noncopyable(const Noncopyable&);
    const Noncopyable& operator=(const Noncopyable&);
};

//����̳з�ʽ��private�ģ�why��
//��������Ǽ̳�����ʵ�֣��Ǽ̳�����ʵ�֣������Ǽ̳����Ľӿڣ�������ʵ�ּ̳У������ǽӿڼ̳�
class Parent : private Noncopyable
{

};

//Parent�ǽ�ֹ�����ģ�������ChildҲ�ǽ�ֹ�����ģ���Ϊ��Ҳ�̳���Noncopyable��ʵ��
class Child : public Parent 
{

};

int main(void)
{
	Parent p1;
	Parent p2(p1);//Ҫ����Parent�������캯����Parent���캯���ֵ���Noncopyable�Ŀ������캯��
				  //�����˽�г�Ա�����������ǲ��ܱ����ʵģ����Ա����ʧ�ܣ���ʹ�ܷ��ʣ�����Ҳû
				  //����ʵ�֣�ͬ��Ҳ�����

	Child c1;
	Child c2(c1);
	return 0;
}