#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    //key������string����һ��������
    //valueֵ������int��������
    //��Ϊ���뵽map�����ڲ���Ԫ��Ĭ���ǰ���key��С����������
    //����key����һ��Ҫ����<������������ſ��Խ��бȽϺ�����
    map<string,int> mapTest;

    //�����Ƕ�value����
    //�ڲ�������[]�������Ч�ʵ�һЩ������ֱ�ۣ���Ϊ����2�������Ȳ���key=��aaa����Ԫ�أ���ʼֵ����int���͵�Ĭ��ֵ��Ϊ0
    //�ڶ������ٰ�100��ֵ����
    //Ҳ����˵���ȹ���һ��Ԫ�أ���ֵ��Ĭ��ֵ��������Ļ�����ʹ����Ĺ��캯��������һ�����󣬷ŵ�map�����ڲ���Ȼ���ٰ�
    //�ö���ֵ����������Ķ���
    mapTest["aaa"] = 100;//int& operator[](const string& index)

    mapTest["eee"] = 500;
    mapTest["eee"] = 300;//���Ը���ԭ��eee��ֵ
    //������һ��value_type����
    //(map<string, int>::value_type����һ�������ͣ���һ��������key���ڶ���������value
    mapTest.insert(map<string, int>::value_type("bbb", 200));
    mapTest.insert(map<string, int>::value_type("bbb", 2000));//�����Ը���ԭ��bbb��ֵ
    
    //����һ��pair����pair��һ��������
    mapTest.insert(pair<string,int>("ccc", 300));
    mapTest.insert(pair<string,int>("ccc", 3000));//�����Ը���ԭ��ccc��ֵ

    //make_pair��һ�������������صľ���pair���Ͷ���������ĵȼ�
    mapTest.insert(make_pair("ddd",400));
    mapTest.insert(make_pair("ddd",4000));//�����Ը���ԭ��ddd��ֵ

   

    //����map������Ҳʹ�õ�����
    map<string, int>::const_iterator it;
    for(it=mapTest.begin(); it!=mapTest.end(); ++it) 
    {
        //it->first����string��it->second����int
        //������Զ�����key������
        cout<it->first<<" "<<it->second<<endl;
        
    }

    return 0;

}



