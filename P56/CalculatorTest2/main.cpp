#include <iostream>
using namespace std;
#include "DebugNew.h"
#include "Node.h"


int main(void)
{
    // int* p =new int;
    // delete p;

    // int* p2 = new int[5];
    // delete[] p2;

    Node* pNode = new Node;
    pNode->Calc();
    // //将pNode指针交给NodePtr来管理
    //构造函数和析构函数都被调用了，就没有析构函数了，这就是使用RAII技巧对资源进行管理，来管理这个指针
    //pNode称之为裸指针，很容易出现内存泄漏，成为空悬指针，因为资源在转移的过程中，是不容易管理的
    NodePtr np(pNode);
    //NodePtr是一个指针，实际上是对Node*的一种包装，是包装器，对裸指针进行包装，希望与裸指针有一样的语法。即能够
    //np->Calc();所以需要重载指针运算符
    np->Calc();//通过NodePtr也能直接访问Calc()方法，因为np返回的就是Node*的指针

    /*
    等价于义下写法
    NodePtr np(new Node);//在对象的构造函数中执行资源的获取(指针的初始化)，在析构函数中释放，即使没有调用delete，也会释放的
    np->Calc();
    */

   //重复释放的问题
   //默认的拷贝构造函数呢，是np2.ptr_=np.ptr_，两个指针持有同一个资源，在释放np2和np对象时，析构函数对同一个资源释放了两次，重复释放
   //应该将np所持有的资源转移到np2,相当于np要释放资源，提供一个释放资源的函数release，释放所有权,在拷贝构造的时候，转移给np2

    NodePtr np2(np);//np对象在析构的时候，其ptr_z指针已经是空的，C++ delet空指针没问题，C语言不能free空指针

    NodePtr np3;
    np3 = np2;//实际上代码也是：np3.ptr_=np2.ptr_;需要重载等号运算符

    /*
    总结：
    出现异常时，没有办法对裸指针所指向资源的引用，没办法去释放资源，因为指针所分配的对象是堆上分配的对象，这些对象在栈展开的过程中不会自动释放
    应用RAII技巧，将裸指针转换为智能指针(智能指针实际上是一个类)
    将指针操作转换为一个类对象的操作，而类对象的析构函数的调用，在生存期结束的时候，是确定调用的
    缺点是只能管理Node*这种类型的裸指针，不能管理任意类型裸指针，所以需要模板技术了，实际C++实际上提供了一个智能指针（用模板实现）：std::auto_ptr
    */

    return 0;
}