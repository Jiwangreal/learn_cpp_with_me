#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    map<int,string> mapTest;
    
    //map容器中插入数据
    mapTest.insert(map<int,string>::value_type(1, "aaa");
    mapTest.insert(map<int,string>::value_type(3, "ccc");
    mapTest.insert(map<int,string>::value_type(2, "bbb");
    
    for (map<int,string>::const_iterator it = mapTest.begin(); it != mapTest.end(); ++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}

