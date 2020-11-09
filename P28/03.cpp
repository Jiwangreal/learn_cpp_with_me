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

    //erase����ͨ��key��Ҳ����ͨ��������
    //����1
    mapTest.erase("bbb");



    //����2
    //����map������Ҳʹ�õ�����
    map<string, int>::const_iterator it;
    it = mapTest.find("ccc");
    if (it != mapTest.end())
    {
        mapTest.erase(it);
    }
    
    

    //Ҳ�����ڱ�����ʱ��ɾ����Ҫע��++it��ʹ�ã������Ļ��ο�P27\02.cpp
    for(it=mapTest.begin(); it!=mapTest.end(); ++it) 
    {
        cout<it->first<<" "<<it->second<<endl;
    }

    return 0;

}
