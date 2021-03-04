#include <map>
#include <string>
#include <iostream>

using namespace std;

struct MyGreater
{
    bool operator()(int left, int right)
    {
        return left > right;
    }
};

int main()
{
    // map<int,string> mapTest;

    //greater是一个模板，用int实例化，得到一个模板类，右边的空格不能省略（C++11可以省略）,若省略，g++会解析成>>右移运算符
    map<int,string,greater<int> > mapTest;
    //也可以自己提供函数对象
    //  map<int,string,MyGreater > mapTest;
    
    //map容器中插入数据
    mapTest.insert(map<int,string>::value_type(1, "aaa");
    mapTest.insert(map<int,string>::value_type(3, "ccc");
    mapTest.insert(map<int,string>::value_type(2, "bbb");
    
    for (map<int,string，greater<int> >::const_iterator it = mapTest.begin(); it != mapTest.end(); ++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    // for (map<int,string，MyGreater >::const_iterator it = mapTest.begin(); it != mapTest.end(); ++it)
    // {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }


    return 0;
}

