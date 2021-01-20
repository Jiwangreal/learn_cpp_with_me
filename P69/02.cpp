#include "Stack2.h"


int main(void)
{
    //显示的实例化一个int类型的模板类，而不是自动推导的
    //Stack是一个模板,Stack<int>是一个模板类
    Stack2<int, 10> s;//当我们使用时，Stack<int>进行实例化，是在编译器完成的，会将头文件里面的template
                    //那些东西用int类型来替换，模板实际上是宏和重载的结合，只是说重载的版本是编译器维护的，而不是程序员
    s.Push(1);
    s.Push(2);
    s.Push(3);

    while (!s.Empty())
    {
        cout<<s.Top()<<endl;
        s.Pop();
    }

    return 0;
}