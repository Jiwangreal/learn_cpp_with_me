#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Shape类不知道如何绘制Draw，所以定义为纯虚函数
//只要有纯虚函数就是抽象类，抽象类是不能定义对象的，它是现实中并不存在的事物
//在基类中不需要实现纯虚函数，如果派生类没有实现纯虚函数，那么该派生类
//也会成为抽象类，则需要派生类的派生类去实现这个纯虚函数
class Shape
{
public:
    virtual void Draw() = 0;
    //一个类作为抽象基类，多态用途的基类，析构函数就应该声明为虚析构函数
    virtual ~Shape()
    {

    }
};

class Circle : public Shape
{
public:
    void Draw()
    {
        cout<<"Circle::Draw() ..."<<endl;
    }
    ~Circle()
    {
        cout <<"~Circle ..."<<endl;
    }
};

class Square : public Shape
{
public:
    void Draw()
    {
        cout<<"Square::Draw() ..."<<endl;
    }
    ~Square()
    {
        cout <<"~Square ..."<<endl;
    }
};
//增加一个类
class Rectangle : public Shape
{
    void Draw()
    {
        cout<<"Rectangle::Draw() ..."<<endl;
    }
    ~Rectangle()
    {
        cout <<"~Rectangle ..."<<endl;
    }
};

void DrawAllShapes(const vector<Shape*>& v)
{
    vector<Square*>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
    {
        //it存放的是Shape*的指针，*it就是Shape*这个指针类型
        //基类指针*it指向派生类对象，会调用派生类的虚函数Draw
        //这里以一致的观点来看待不同的派生类对象
        (*it)->Draw();
    }
}

void DeleteAllShapes(const std::vector<Shape*>& v)
{
    vector<Square*>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
    {
        delete(*it);//析构函数是虚函数
                    //会依据指针所指向的类型来调用析构函数,实际指向的是派生类的对象，会释放派生类对象，会
                    //调用派生类的析构函数，再调用基类的析构函数，避免内存泄漏
                    
                    //如果析构函数不是虚的，则派生类的析构函数是无法被调用的
    }
}

//简单的工厂模式：new Circle;new Square;new Triangle;这些new对象统一在一个地方
//统一类对象的创建
class ShapeFactory
{
public:
    static Shape* CreateShape(const string& name)
    {
        Shape* ps = 0;
        if(name == "Circle")
        {
            ps = new Circle;
        }
        else if(name == "Square")
        {
            ps = new Square;
        }
        else if(name == "Rectangle")
        {
            ps = new Rectangle;
        }
        return ps;
    }
};



int main(void)
{
    // Shape s;//Error, 不能实例化抽象类
    vector<Shape*> v;

    //用工厂模式代替下面
    // Shape* ps;
    // ps =new Circle;
    // v.push_back(ps);
    // ps = new Square;
    // v.push_back(ps);
    // //上面的控制模块都不需要动

    // //新增
    // ps = new Triangle;
    // v.push_back(ps);

    //工厂模式使用如下
    Shape *ps;
    ps = ShapeFactory::CreateShape("Circle");
    v.push_back(ps);
    ps = ShapeFactory::CreateShape("Square");
    v.push_back(ps);
    ps = ShapeFactory::CreateShape("Rectangle");
    v.push_back(ps);


    //将vector中的各个形状绘制出来
    DrawAllShapes(v);
    DeleteAllShapes(v);
    return 0;
}