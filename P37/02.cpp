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

    //dynamic_cast和typeid运行时类型识别都不如虚函数的多态效率来得高，即使调用派生类对象的虚函数
    p = &c;
    p->Draw();
    


    //看下基类指针到底指向哪一个类
    //dynamic_cast是一个类型安全的向下转型
    if(dynamic_cast<Circle*>(p))    //若p指针转化为Circle*的指针，说明指向的是派生类对象
    {
        cout<<"p is point to a Circle object"<<endl;
        //dynamic_cast向下安全转型的条件是什么？
        //dynamic_cast要用在多态类上面，也就是说它应该有虚函数，派生类继承至多态基类，如果没有虚函数的话，是不允许做向下转型的
        //使用dynamic_cast的2个条件：（1）要开启VS编译器类型识别GR特性；（2）要用在具有多态关系的继承体系之上才可以，即基类有虚函数
        Circle* cp = dynamic_cast<Circle*>(p);//安全向下转型
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

    //typeid也可以做到运行时，类型识别
    //typeid返回的是type_info对象,name就是实际的类型
    //typeid既可以用在类型上，又可以用在对象上
    cout<<typeid(*p).name()<<endl;
    cout<<typeid(Circle).name()<<endl;
    if (typeid(Circle).name() == typeid(*p).name())
    {
        cout<<"p is point to a Circle object"<<endl;
        ((Circle*)p)->draw();
    }
    else if (typeid(Square).name() == typeid(*p).name())
    {
        cout<<"p is point to a Square object"<<endl;
        ((Square*)p)->draw();
        //((Square*)p)这种C风格的强转会做一些对齐操作，而reinterpret_cast是不会做任何对齐操作的
    }
    else
    {
        cout<<"p is point to a Other object"<<endl;
    }
    
    // type_info ti = type_id(Circle);error
    
    return 0;
}