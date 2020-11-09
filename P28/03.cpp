#include <iostream>
#include <map>
using namespace std;

int main(void)
{

    map<string,int> mapTest;

    mapTest["aaa"] = 100;//int& operator[](const string& index)

    mapTest.insert(map<string, int>::value_type("bbb", 200));
    mapTest.insert(pair<string,int>("ccc", 300));
    mapTest.insert(make_pair("ddd",400));

    //erase可以通过key，也可以通过迭代器
    //方法1
    mapTest.erase("bbb");



    //方法2
    //遍历map容器，也使用迭代器
    map<string, int>::const_iterator it;
    it = mapTest.find("ccc");
    if (it != mapTest.end())
    {
        mapTest.erase(it);
    }
    
    

    //也可以在遍历的时候删除，要注意++it的使用，不懂的话参看P27\02.cpp
    for(it=mapTest.begin(); it!=mapTest.end(); ++it) 
    {
        cout<it->first<<" "<<it->second<<endl;
    }

    return 0;

}
