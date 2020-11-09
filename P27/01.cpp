#include <iostream>
#include <vector>
using namespace std;

//vector<int>��һ��ģ���࣬��������һ����
typedef vector<int> INTVEC;

void ShowVec(const INTVEC& v)
{
    //size()��������Ԫ�صĸ���
    unsigned int i;
    for (i=0; i<v.size(); i++)
    {
        cout<<" "<<v[i]<<" ";//�������Կ���һ�����飬��������[]�����
    }
    cout<<endl;
}
//stringҲ���Կ�����һ��������ͨ�������ַ�������ѣ�������ͨ������������������
//vector��STL�е�һ��������������֧�ֵ������Ĳ�����������ͨ������������������
//���������Կ�����������ָ�룬���Կ����Ƿ��ͳ���ָ�룬�����ŵ�Ԫ����int��vector<int> ���÷��ͳ���ָ��͵ȼ���int*
//��������������������ô�򵥵ĵȼ۵ģ������ĵ�����������һ����
//�õ�������ʵ��
void ShowVec(INTVEC& v)
{
    INTVEC::iterator it;//�����iterator���͵���int*

    //for (it = v.begin(); it < v.end(); ++it)Ҳ�У������κ�һ��������������!=���������<�������һ������������ĸ���
    //ǰ�᣺iterator��һ����������Ϊʲô����it++?����Ϊ���������++���һ����ʱ����Ĺ��죬Ч�ʵ�һЩ������⿴��23cpp\23cpp\23cpp\Integer.cpp
    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it<<"";
    }
    cout<<endl;
}

//���ʹ�ô�const����iteratorӦ��Ҳ��const
void ShowVec(const INTVEC& v)
{
    INTVEC::const_iterator it;//����*it���ܸ�ֵ�ˣ�*it = 4;����ȷ,*it���Ϊֻ���ģ����ܸ�ֵ

    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it<<"";
    }
    cout<<endl;
}


int main(void)
{
    //string�ȼ���basic_string<char>��stringҲ��һ����ģ�壬����ģ���ʵ����Ҳ���Կ���һ����
    INTVEC v;
    //����һ������v����ӡ������������ЩԪ��
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);   

    ShowVec(v);
    // //size()��������Ԫ�صĸ���
    // unsigned int i;
    // for (i=0; i<v.size(); i++)
    // {
    //     cout<<" "<<v[i]<<" ";//�������Կ���һ�����飬��������[]�����
    // }
    // cout<<endl;

    return 0;

    
}


