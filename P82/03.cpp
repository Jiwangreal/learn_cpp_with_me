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

    //greater��һ��ģ�壬��intʵ�������õ�һ��ģ���࣬�ұߵĿո���ʡ�ԣ�C++11����ʡ�ԣ�,��ʡ�ԣ�g++�������>>���������
    map<int,string,greater<int> > mapTest;
    //Ҳ�����Լ��ṩ��������
    //  map<int,string,MyGreater > mapTest;
    
    //map�����в�������
    mapTest.insert(map<int,string>::value_type(1, "aaa");
    mapTest.insert(map<int,string>::value_type(3, "ccc");
    mapTest.insert(map<int,string>::value_type(2, "bbb");
    
    for (map<int,string��greater<int> >::const_iterator it = mapTest.begin(); it != mapTest.end(); ++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    // for (map<int,string��MyGreater >::const_iterator it = mapTest.begin(); it != mapTest.end(); ++it)
    // {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }


    return 0;
}

