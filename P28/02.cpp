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

    //����key=��bbb����ֵ
    //����1����bbb��ֵΪ0�����߲�����bbb��ֵ����n����ֵ��Ϊ0����֪���ܲ����ҵ�
    int n = mapTest["bbb"];
    cout<<n<<endl;
    mapTest["bbb"] = 2000;

    //����2���뷽��1��ȣ������ж��Ƿ��ҵ� 
    map<string, int>::iterator it;
    it = mapTest.find("ccc");
    if(it != mapTest.end())
    {
        //���ҵ���ccc��ֵ�޸�Ϊ3000������const_iterator�����ܸ�ֵ����Ϊ�ǳ���
        it->second = 3000;
    }
    else
    {
        cout<<"not found"<<endl;
    }
    


    //����map������Ҳʹ�õ�����
    // map<string, int>::const_iterator it;
    for(it=mapTest.begin(); it!=mapTest.end(); ++it) 
    {
        cout<it->first<<" "<<it->second<<endl;
    }

    return 0;

}



