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