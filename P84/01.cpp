#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

void ShowVec( const vector< int> &v)
{
     for (vector< int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it <<  ' ';
    }
    cout << endl;
}
int main( void)
{
     int a[] = { 1,  2,  3,  4,  5};
    vector< int> v(a, a +  5);
    vector< int> v2;

    //参数是容器类型
    back_insert_iterator<vector< int> > bii(v);

    //这个eg没啥意义，使用push_back同样可以
    //内部调用v.push_back(6);
    //对插入迭代器所关联的容器对象做一次插入操作
    //*bii = 6;//重载了*号运算符，返回了迭代器对象自身，不是取出迭代器所在位置的元素，将元素值6插入到容器v中
    // ShowVec(v);

    *bii =  6;//*bii的*号操作等价于bii，等价于bii =  6;
    ShowVec(v);

    //要求：vector< int> 必须有push_back操作，因为back_insert_iterator的=号运算符会调用push_back
    //传递进来的对象类型v2要与back_insert_iterator中的vector< int>容器类型一致
    //这里是类模板，必须传递一个类进来，类型是不能自动推导的
    back_insert_iterator<vector< int> > bii2(v2);
    copy(v.begin(), v.end(), bii2);//拷贝到迭代器bii2所在位置，就是拷贝到v2（拷贝到迭代器所关联的容器里面）
                                    //迭代器bii2的赋值运算，实际上是把元素push_back到v2向量中
    ShowVec(v2);

    //back_inserter函数模板是可以进行类型推导的
    back_inserter(v) =  7;//插入一个元素
    //返回值是一个模板类back_insert_iterator<_Container>，实例化一个模板函数
    //是不需要将对象类型传递进来，他可以根据对象的类型可以自动推导
    // back_inserter(vector<int>)(v) =  7;
    

    ShowVec(v);
    
    //back_inserter(v2)自动推导v2的类型就是vector< int> 
    //函数模板可以自动推导，类模板是不能自动推导的
    copy(v.begin(), v.end(), back_inserter(v2));//在尾部插入
    ShowVec(v2);


     return  0;
}