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
public:
	//���캯������û���Ĺ��캯������ʹû��д��Parent(): Noncopyable()��Ҳ�ǻ��Զ����õ�
	Parent()//������û��Ĭ�Ϲ��캯������ô������ĳ�Ա�����б��и������๹�캯���ĵ���
	{

	}
	//�������캯������û���Ŀ������캯��������ֻ��Parent(const Parent& other) : Noncopyable(other)��ôȥд
	//�Ż���û���Ŀ������캯����
	Parent(const Parent& other) : Noncopyable(other)
	{

	}
};

//Parent�ǽ�ֹ�����ģ�������ChildҲ�ǽ�ֹ�����ģ���Ϊ��Ҳ�̳���Noncopyable��ʵ��
class Child : public Parent 
{

};

int main(void)
{
	Parent p1;//���ù��캯��
	//���ÿ������캯���������ôд��Parent(const Parent& other){}��
	//Parent��ʵ���˿������캯�����ǲ�����û���Ŀ������캯������ô˽�е�Noncopyable(const Noncopyable&);������ƾͲ���Ч��
	Parent p2(p1);//Ҫ����Parent�������캯����Parent���캯���ֵ���Noncopyable�Ŀ������캯��
				  //�����˽�г�Ա�����������ǲ��ܱ����ʵģ����Ա����ʧ�ܣ���ʹ�ܷ��ʣ�����Ҳû
				  //����ʵ�֣�ͬ��Ҳ�����

	// Child c1;
	// Child c2(c1);
	return 0;
}