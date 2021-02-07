#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Shape�಻֪����λ���Draw�����Զ���Ϊ���麯��
//ֻҪ�д��麯�����ǳ����࣬�������ǲ��ܶ������ģ�������ʵ�в������ڵ�����
//�ڻ����в���Ҫʵ�ִ��麯�������������û��ʵ�ִ��麯������ô��������
//Ҳ���Ϊ�����࣬����Ҫ�������������ȥʵ��������麯��
class Shape
{
public:
    virtual void Draw() = 0;
    //һ������Ϊ������࣬��̬��;�Ļ��࣬����������Ӧ������Ϊ����������
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
//����һ����
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
        //it��ŵ���Shape*��ָ�룬*it����Shape*���ָ������
        //����ָ��*itָ����������󣬻������������麯��Draw
        //������һ�µĹ۵���������ͬ�����������
        (*it)->Draw();
    }
}

void DeleteAllShapes(const std::vector<Shape*>& v)
{
    vector<Square*>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
    {
        delete(*it);//�����������麯��
                    //������ָ����ָ���������������������,ʵ��ָ�����������Ķ��󣬻��ͷ���������󣬻�
                    //����������������������ٵ��û�������������������ڴ�й©
                    
                    //�����������������ģ���������������������޷������õ�
    }
}

//�򵥵Ĺ���ģʽ��new Circle;new Square;new Triangle;��Щnew����ͳһ��һ���ط�
//ͳһ�����Ĵ���
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
    // Shape s;//Error, ����ʵ����������
    vector<Shape*> v;

    //�ù���ģʽ��������
    // Shape* ps;
    // ps =new Circle;
    // v.push_back(ps);
    // ps = new Square;
    // v.push_back(ps);
    // //����Ŀ���ģ�鶼����Ҫ��

    // //����
    // ps = new Triangle;
    // v.push_back(ps);

    //����ģʽʹ������
    Shape *ps;
    ps = ShapeFactory::CreateShape("Circle");
    v.push_back(ps);
    ps = ShapeFactory::CreateShape("Square");
    v.push_back(ps);
    ps = ShapeFactory::CreateShape("Rectangle");
    v.push_back(ps);


    //��vector�еĸ�����״���Ƴ���
    DrawAllShapes(v);
    DeleteAllShapes(v);
    return 0;
}