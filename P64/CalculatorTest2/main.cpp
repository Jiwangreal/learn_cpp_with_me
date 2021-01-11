#include <iostream>
#include <memory>
#include <vector>

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

   //std::auto_ptr<Node>这里模板里面又是一个模板类Node，这里需要一个空格（C++11不需要），不这么做，编译器会解释为右引运算符
   std::auto_ptr<Node> node(new Node);
   vector<std::auto_ptr<Node> > v;
   v.push_back(node);//error,错误原因是：vector存放的元素类型是auto_ptr，在插入的时候不希望node类型改变，因为其类型是const _Ty的引用
                    //但是插入的时候一定涉及到了所有权的转移，因为里面肯定又拷贝构造函数的调用或等号运算符的调用
                    //所有权转移的过程中，other对象（看P56\CalculatorTest2\Node.h）一定会改变的，所以拷贝构造函数形参都不能是const
                    //所以auto_ptr的语义不适合存放到向量中

    /*
    auto_ptr总结
    （1）auto_ptr不能作为STL容器的元素
    （2）STL容器要求存放在容器中的元素是值语义（STL容器要求存放在容器中的元素能够被拷贝，也就是要求类型是值语义对象；auto_ptr就是值语义，实际上是将
    对象语义转化为值语义）
    （3）auto_ptr的拷贝构造或者赋值操作会改变右操作数，因为右操作数的所有权要发生转移
    STL接口，当把一个元素插入进去的时候，push_back不能够改变要插入元素的对象，即使在内部做了拷贝，当一个智能指针对象赋值（或者拷贝）给另外一个智能指针对象时，
    所有权会发生转移，不符合push_back中形参const的要求（void push_back(const _Ty& _Val)）,所以不能插入
    解决办法：可以采用其他类型的智能指针，eg：boost中的shared_ptr,scoped_ptr指针
    这样做不好，原因是：
    vector并没有持有指针所指向的资源，它需要去负责这些指针的释放的（MultipleNode::~MultipleNode()中的代码），还是要写delete方法去释放它，可以写一个
    指针容器去负责指针所指向的内存资源的释放，可以自己实现一个ptr_vector，它能够插入auto_ptr还能够管理指针所指向的内存。
    补充：
    ptr_vector是指针容器，是ptr_container中的一种特例，如果使用boost库，这些组件都是有的
    所以说C++内存管理：不仅会用智能指针，还必须明白值语义，对象语义，还需要明白STL容器的工作原理，到底是否管理到了指针所指向的资源。才能编写内存不泄露的程序
    */

    return 0;
}