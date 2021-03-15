#include  <boost/shared_ptr.hpp>
#include  <iostream>
using   namespace  std;

class  Parent;
class  Child;
typedef  boost::shared_ptr<Parent>  parent_ptr;
typedef  boost::shared_ptr<Child>  child_ptr;

class  Child
{
public:
        Child()
        {
                cout  <<   "Child  ..."  <<  endl;
        }
        ~Child()
        {
                cout  <<   "~Child  ..."  <<  endl;
        }
        parent_ptr  parent_;//持有一个Parent类的智能指针对象
};

class  Parent
{
public:
        Parent()
        {
                cout  <<   "Parent  ..."  <<  endl;
        }
        ~Parent()
        {
                cout  <<   "~Parent  ..."  <<  endl;
        }
        child_ptr  child_;//持有一个Child的智能指针对象
};

int  main( void)
{
        parent_ptr  parent( new  Parent);
        child_ptr  child( new  Child);

        //Parent父亲对象中的孩子指向孩子对象
        parent->child_  =  child;//孩子对象引用计数=2
        //Child孩子对象中的父亲指向父亲对象
        child->parent_  =  parent;//父亲对象引用计数=2

        //这样父亲对象和孩子对象都无法正常释放
        parent->child_.reset();//让孩子对象的引用计数变成1，打破循环引用
        //child智能指针对象销毁时，当前引用计数从1->0，所以Child对象被销毁，且Child对象
        //又持有parent_，此时parent_引用计数减为1，当Parent对象销毁时，parent_计数从1->0，所以
        ///Parent会被销毁
         return   0;
}