
//���������Ƕ�̬��
//file y.h
#include "x.h"
class Y
{
    void Func();X x;
};

//file y.cpp
#include "y.h"
void Y::Fun()
{
    return x_.Fun();
}
//end���������Ƕ�̬��

//���������ǿͻ�����
//file main.cpp
#include "y.h"
int main(void)
{
    Y y;
    y.Fun();
}