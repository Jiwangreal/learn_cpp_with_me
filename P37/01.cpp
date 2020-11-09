#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void Draw() = 0;
    virtual ~Shape() = 0;
};

class Circle : public Shape
{
public:
    void Draw()
    {
        cout<<"Circle Circle ..."<<endl;
    }
};
class Square : public Shape
{
public:
    void Draw()
    {
        cout<<"Square Square ..."<<endl;
    }
};

int main(void)
{
    Shape* p;
    Circle c;

    p = &c;
    p->Draw();
    
    //���»���ָ�뵽��ָ����һ����
    //dynamic_cast��һ�����Ͱ�ȫ������ת��
    if(dynamic_cast<Circle*>(p))    //��pָ��ת��ΪCircle*��ָ�룬˵��ָ��������������
    {
        cout<<"p is point to a Circle object"<<endl;
        //dynamic_cast���°�ȫת�͵�������ʲô��
        //dynamic_castҪ���ڶ�̬�����棬Ҳ����˵��Ӧ�����麯����������̳�����̬���࣬���û���麯���Ļ����ǲ�����������ת�͵�
        //ʹ��dynamic_cast��2����������1��Ҫ����VS����������ʶ��GR���ԣ���2��Ҫ���ھ��ж�̬��ϵ�ļ̳���ϵ֮�ϲſ��ԣ����������麯��
        Circle* cp = dynamic_cast<Circle*>(p);//��ȫ����ת��
        cp->Draw();
    }
    else if(dynamic_cast<Square*>(p))
    {
        cout<<"p is a point to a Square object"<<endl;
    }
    else
    {
        cout<<"p is point to a Other object"<<endl;
    }
    
    return 0;
}