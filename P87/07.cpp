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
        boost::weak_ptr<parent> child_;//Parent里面持有的指针由weak_ptr来持有
};

int  main( void)
{
        parent_ptr  parent( new  Parent);//Parent对象的引用计数为1
        child_ptr  child( new  Child);//Child对象的引用计数为1

        //Parent父亲对象中的孩子指向孩子智能指针对象child
        parent->child_  =  child;//因为是弱引用，Child对象的引用计数=1
        //Child孩子对象中的父亲指向父亲智能指针对象parent
        child->parent_  =  parent;//Parent父亲对象引用计数=2

        //这样父亲对象和孩子对象都无法正常释放
         return   0;
}