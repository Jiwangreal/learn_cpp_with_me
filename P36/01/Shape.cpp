#include "Shape.h"
#include "DynBase.h"
#include <iostream>
using namespace std;

void Circle::Draw()
{
    cout<<"Circle::Draw() ..."<<endl;
}
Circle::~Circle()
{
    cout <<"~Circle ..."<<endl;
}


void Square::Draw()
{
    cout<<"Square::Draw() ..."<<endl;
}
Square::~Square()
{
    cout <<"~Square ..."<<endl;
}


void Rectangle::Rectangle()
{
    cout<<"Rectangle::Draw() ..."<<endl;
}
Rectangle::~Rectangle()
{
    cout <<"~Rectangle ..."<<endl;
}

//���������������,��������Ϊչ������
REGISTER_CLASS(Circle);
REGISTER_CLASS(Square);
REGISTER_CLASS(Rectangle);

/*

#define REGISTER_CLASS(class_name) \
class class_name##Register { \
public: \
    static void* NewInstance() \
    { \
        return new class_name; \
    } \
private: \
    static Register reg_; \
}; \
Register class_name##Register::reg_(#class_name, class_name##Register::NewInstance);


eg:��չ���Ľ��
//ע����һ��Circle��,֧�ֶ�̬��������
#define REGISTER_CLASS(Circle)
class CircleRegister {
public:
    static void* NewInstance()
    {
        return new Circle;
    }
private:
    static Register reg_;//�����,����ֻ������,��Ҫ����������ж���
};
Register CircleRegister::reg_("Circle", CircleRegister::NewInstance);
//����reg_������������캯���ĵ���

*/