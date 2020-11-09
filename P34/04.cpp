#include <iostream>
using namespace std;

class CObject
{
public:
    virtual void Serialize()
    {
        cout<<"CObject::Serialize ..."<<endl;
    }
};

class CDocument : public CObject
{
public:
    int data1_;
    void func()
    {
        cout<<"CDocument::func ..."<<endl;
        Serialize();
    }
    //覆盖基类的虚函数
    virtual void Serialize()
    {
        cout<<"CDocument::Serialize ..."<<endl;
    }

    //因为要调用派生类CMyDoc的默认构造函数，也要调用基类CDocument的默认构造函数，所以这里需要定义下
    //因为CMyDoc类中构造函数初始化列表中并没有给出构造函数，也就没有给出基类的构造，所以需要定义基类的默认构造函数
    CDocument()
    {
        cout<<"CDocument"<<endl;
    }

    CDocument(const CDocument& other)
    {
        cout<<"CDocument(const CDocument& other)"<<endl;
    }
};

//继承func，覆盖CDocument类的Serialize
class CMyDoc : public CDocument
{
public:
    int data2_;
    //派生类对象覆盖了上面的基类虚函数
    virtual void Serialize()
    {
        cout<<"CMyDoc::Serialize ..."<<endl;
    }
};

int main()
{
    //都是最底层的派生类对象
    CMyDoc mydoc;
    CMyDoc* pmydoc = new CmyDoc;//定义一个对象，指向派生类对象

    cout<<"#1 testing"<<endl;
    mydoc.func();//从实际对象的虚表去查找，找到派生类对应的虚函数

    cout<<"#2 testing"<<endl;
    ((CDocument*)(&mydoc))->func();//((CDocument*)(&mydoc))相当于基类指针指向派生类对象
                                //由于CMyDoc没有重定义func，所以会调用CDocument中的func
                                //实际指向的对象是mydoc，所以会调用CMyDoc中的Serialize

    cout<<"#3 testing"<<endl;
    pmydoc->func();

    cout<<"#4 testing"<<endl;
    ((CDocument)mydoc).func();//mydoc对象强制转化为CDocument对象，向上转型
                            //完完全全将派生类对象转化为基类对象，包括虚表都已经发生了改变，都是CDocument虚表了
                            //向上转型会调用构造函数，这里调用拷贝构造函数，将派生类mydoc对象拷贝构造为CDocument类对象，若没写，所以会
                            //调用默认的拷贝构造函数

    return 0;
}