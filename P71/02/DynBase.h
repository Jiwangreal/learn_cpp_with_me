//工厂模式:动态创建任意对象
#ifndef _DYN_BASE_H_
#define _DYN_BASE_H_
#include <map>
#include <string>
using namespace std;

//用函数指针创建方法
typedef void* (*CREAT_FUNC)();

//这样做的好处是:不需要依据字符串去判定到底是什么对象
//这里新增一个对象,就不需要什么改动,而P35\01.cpp这里实现的工厂模式需要增加if else语句
class DynObjectFactory
{
public:
    static void* CreatObject(const string& name)
    {
        //在map容器中查找创建函数
        //创建函数需要预先注册好才可以
        map<string, CREAT_FUNC>::const_iterator it;
        it = mapCls_.find(name);//取出容器的函数指针
        if (it == mapCls_.end())
            return 0;
        else
            return it->second();//得到创建方法,从而创建对象
        //调用指针所指向的函数,创建一个对象,这些函数指针所指向的函数都在宏REGISTER_CLASS中给出了
        //每当注册一个类,就有一个NewInstance方法
        //map容器的第2个字段就是一个函数指针,通过调用函数指针所指向的函数来创建对象
        //函数指针所指向的函数,其内部new 类型
    }

    //注册方法
    //将字符串和创建函数插入到map容器中，这样在CreatObject中的map容器中取出对应的创建方法来动态创建对象，动态创建对象方法就是调用
    //NewInstance()方法
    static void Register(const string& name, CREAT_FUNC func)
    {
        mapCls_[name] = func;
    }
private:
    //保存了要动态创建类的信息,字符串和创建方法
    static map<string, CREAT_FUNC> mapCls_;//static这里仅仅是声明,需要在类外定义
};

//由于DynTest.cpp包含了该头文件,Shape.cpp也包含了该头文件,下面的编译会出现重定义
//如果不把它放在对应的cpp文件中,则可以利用扩展属性_declspec(selectany)进行修饰,这样的化就可以只定义一次了
//如果使用g++编译器,得使用__attribute((weak))来替换_declspec(selectany),实现的效果一样
_declspec(selectany) map<string, CREAT_FUNC> DynObjectFactory::mapCls_;




// class Register
// {
// public:
//     Register(const string& name, CREAT_FUNC func)
//     {
//         DynObjectFactory::Register(name, func);
//     }
// }

// //下面这段改成模板，下面这段的作用是：将实际类的创建方式注册进去，new class_name;
// //##就是连接的,比如传进来是Circle,那么得到的类就是CircleRegister
// #define REGISTER_CLASS(class_name) \
// class class_name##Register { \
// public: \
//     //如何创建类的函数
//     //class_name传递进来的时候不是一个字符出,它就是一个类型,所以支持new class_name
//     static void* NewInstance() \
//     { \
//         return new class_name; \        //new Circle，将new Circle这样的指针注册到map中的CREAT_FUNC
//     } \
//     //将REGISTER_CLASS类的创建方法NewInstance注册到mapCls_里面,以便于查找
// private: \
//     static Register reg_; \//static变量声明
// }; \

// //static变量定义
// //在类体外部定义一个对象
// //#class_name中的#表示需要将传递进来的字样转换为字符串
// //(#class_name, class_name##Register::NewInstance)代表类和对应的创建方法
// //Register CircleRegister::reg_("Circle", Register CircleRegister::NewInstance);会引发Register的构造函数
// Register class_name##Register::reg_(#class_name, class_name##Register::NewInstance);

// /*什么时候完成的注册?
// 所有的对象reg_,mapCls_都是静态的程序开始运行的时候就初始化了,当我们进入到main时,实际上都已经注册好了
// 因为这些对象都是静态对象,在类外部定义了,在程序运行的时候就会调用它的构造函数
// */


//用模板的方式实现，一般宏能实现的功能，模板也能实现，宏展开的过程也是编译器来完成的，编译的过程来进行模板的实例化，类似于宏展开
//委托类
//class class_name##Register相当于变成了模板，只需要模板类的构造即可，来引发注册
template <typename T>
class DelegatingClass
{
public:
    DelegatingClass(const string& name)
    {
        DynObjectFactory::Register(name, &(DelegatingClass::NewInstance);
    }
    static void* NewInstance()
    {
        return new T;
    }

};


//传递类名，构造对象
//elegatingClass<class_name>是模板类，class##class_name(#class_name)定义一个这样的对象，目的是引发它的构造函数的调用
#define REGISTER_CLASS(class_name) DelegatingClass<class_name> class##class_name(#class_name)


#endif/*_DYN_BASE_H_*/