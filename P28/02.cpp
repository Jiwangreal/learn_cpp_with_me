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

    //查找key=“bbb”的值
    //方法1，若bbb的值为0，或者不存在bbb的值，其n返回值都为0，不知道能不能找到
    int n = mapTest["bbb"];
    cout<<n<<endl;
    mapTest["bbb"] = 2000;

    //方法2：与方法1相比，可以判断是否找到 
    map<string, int>::iterator it;
    it = mapTest.find("ccc");
    if(it != mapTest.end())
    {
        //将找到的ccc的值修改为3000，若是const_iterator，则不能赋值，因为是常量
        it->second = 3000;
    }
    else
    {
        cout<<"not found"<<endl;
    }
    


    //遍历map容器，也使用迭代器
    // map<string, int>::const_iterator it;
    for(it=mapTest.begin(); it!=mapTest.end(); ++it) 
    {
        cout<it->first<<" "<<it->second<<endl;
    }

    return 0;

}



