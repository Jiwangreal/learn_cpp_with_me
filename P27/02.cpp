#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<int>是一个模板类，把它看成一个类
typedef vector<int> INTVEC;

// void ShowVec(const INTVEC& v)
// {
//     //size()返回向量元素的个数
//     unsigned int i;
//     for (i=0; i<v.size(); i++)
//     {
//         cout<<" "<<v[i]<<" ";//向量可以看成一个数组，它重载了[]运算符
//     }
//     cout<<endl;
// }
// //string也可以看成是一种容器，通常看成字符串类而已，它可以通过迭代器来遍历容器
// //vector是STL中的一种容器，容器都支持迭代器的操作，它可以通过迭代器来遍历容器
// //迭代器可以看成是容器的指针，可以看成是泛型程序指针，如果存放的元素是int，vector<int> ，该泛型程序指针就等价于int*
// //但是其他容器并不是这么简单的等价的，其他的迭代器可能是一个类
// //用迭代器来实现
// void ShowVec(INTVEC& v)
// {
//     INTVEC::iterator it;//这里的iterator，就当作int*

//     //for (it = v.begin(); it < v.end(); ++it)也行，但是任何一种容器都会重载!=运算符，而<运算符不一定，所以下面的更好
//     //前提：iterator是一个类的情况，为什么不用it++?，因为后置运算符++会多一次临时对象的构造，效率低一些，不理解看：23cpp\23cpp\23cpp\Integer.cpp
//     for (it = v.begin(); it != v.end(); ++it)
//     {
//         cout << *it<<"";
//     }
//     cout<<endl;
// }

//如果使用带const，则iterator应该也是const
void ShowVec(const INTVEC& v)
{
    INTVEC::const_iterator it;//这里*it不能赋值了，*it = 4;不正确,*it会成为只读的，不能赋值

    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it<<"";
    }
    cout<<endl;
}


int main(void)
{
    //string等价于basic_string<char>，string也是一个类模板，是类模板的实例，也可以看成一个类
    INTVEC v;
    //给定一个向量v，打印出来里面有哪些元素
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);   
    v.push_back(4);
    v.push_back(5);
    v.push_back(3); 
    // cout<<v.back()<<endl;//输出最后一个元素，但是并不弹出
    // v.pop_back();//会将最后一个元素弹出来

    ShowVec(v);
    // v.erase(v.begin()+2);//v里面的参数是迭代器
    //凡是涉及到迭代器，其区间都是[,)闭开的
    // v.erase(v.begin(), v.begin() + 2);

    //移除值=3的元素,remove就是个算法，end()实际指向的是最后一个3后面的元素，因为是闭开区间
    //remove(v.begin(), v.end(), 3);只是把3挪到最后面了
    //方法1
    v.rease(remove(v.begin(), v.end(), 3), v.end());

    //方法2，删除值于给定的元素值的方法，其他容器删除给定元素值也可以采用这种方式
    INTVEC::iterator it;
    for(it=v.begin(); it!=v.end();)
    {
        if(*it == 3)
        {
            it = v.erase(it);//erase返回的是当前删除元素的下一个元素
        }
        else
            ++it;
        
    }


    ShowVec(v);


    return 0;

    
}


