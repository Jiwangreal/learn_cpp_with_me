#ifndef _SHAPE_H_
#define _SHAPE_H_
#include "Shape.h"

class Shape
{
public:
    virtual void Draw() = 0;
    virtual ~Shape()
    {

    }
};

class Circle : public Shape
{
public:
    void Draw();

    ~Circle();
};

class Square : public Shape
{
public:
    void Draw();
    ~Square();
};

//增加一个类
class Rectangle : public Shape
{
    void Draw();
    ~Rectangle();
};

#endif/*_SHAPE_H_*/