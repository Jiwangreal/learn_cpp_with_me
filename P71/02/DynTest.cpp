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
    // Shape s;//Error, ����ʵ����������
    vector<Shape*> v;

    Shape *ps;
    
    //��̬��������Ĺ����࣬�����ַ�������������
    //�ڵ���CreatObject����ǰ��ʵ�ʵ���Ķ�̬�����������Ѿ�ע�ᵽmap��������
    //��ΪRegister class_name##Register::reg_(#class_name, class_name##Register::NewInstance);���Ǿ�̬���������Եĳ�ʼ������̬�������ʼ��������һ��ʼ��
    //ʱ��ͻ���ù��캯�����г�ʼ���ģ�
    //REGISTER_CLASS(Circle);����Ҳ���ʼ��
    //���������CreatObject�Ǵ�mao�������ҵ���������������void*
    ps = static_cast<Shape*>(DynObjectFactory::CreatObject("Circle"));//���ص���void*,������Ҫת����
    v.push_back(ps);
    ps = static_cast<Shape*>(DynObjectFactory::CreatObject("Square"));
    v.push_back(ps);
    ps = static_cast<Shape*>(DynObjectFactory::CreatObject("Rectangle"));
    v.push_back(ps);

    DrawAllShapes(v);
    DeleteAllShapes(v);
    return 0;
}