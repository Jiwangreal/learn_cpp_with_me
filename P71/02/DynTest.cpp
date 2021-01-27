#include <iostream>
#include <vector>
#include <string>
#include "Shape.h"
#include "DynBase.h"
using namespace std;

void DrawAllShapes(const vector<Shape*>& v)
{
    vector<Square*>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
    {
        (*it)->Draw();
    }
}

void DeleteAllShapes(const std::vector<Shape*>& v)
{
    vector<Square*>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
    {
        delete(*it);
    }
}

int main(void)
{
    // Shape s;//Error, 不能实例化抽象类
    vector<Shape*> v;

    Shape *ps;
    
    //动态创建对象的工厂类，根据字符串来创建对象
    //在调用CreatObject方法前，实际的类的动态创建方法都已经注册到map容器中了
    //因为Register class_name##Register::reg_(#class_name, class_name##Register::NewInstance);这是静态变量定义性的初始化，静态变量会初始化（程序一开始的
    //时候就会调用构造函数进行初始化的）
    //REGISTER_CLASS(Circle);类似也会初始化
    //所以这里的CreatObject是从mao容器中找到创建方法，返回void*
    ps = static_cast<Shape*>(DynObjectFactory::CreatObject("Circle"));//返回的是void*,所以需要转换下
    v.push_back(ps);
    ps = static_cast<Shape*>(DynObjectFactory::CreatObject("Square"));
    v.push_back(ps);
    ps = static_cast<Shape*>(DynObjectFactory::CreatObject("Rectangle"));
    v.push_back(ps);

    DrawAllShapes(v);
    DeleteAllShapes(v);
    return 0;
}