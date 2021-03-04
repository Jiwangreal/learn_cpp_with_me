#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintFun(int n)
{
    cout<<n<<' ';
}

void Add3(int& n)
{
    n += 3;
}

//�ú�������ʽʵ��
class PrintObj
{
public:
    void operator()(int n)
    {
        cout<<n<<' ';
    }
};


class Addoobj
{
public:
    Addoobj(int number) number_(number) {}
    void operator()(int& n)
    {
        n += number_;
    }
private:
    //������������״̬�ģ����Զ���һ����Ա��������״̬����Ϊ�䱾���������
    //��ͨ�����ǲ��ܱ���״̬�ģ��������ڲ��о�̬��Ա
    int number_;
};

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a+5);

    for_each(v.begin(), v.end(), PrintFun);
    cout<<endl;

    //ע�⴫�ݵ��Ƕ��󣬶��������������ﴫ�ݵ�����������
    for_each(v.begin(), v.end(), PrintObj());
    cout<<endl;

    for_each(v.begin(), v.end(), Add3);
    for_each(v.begin(), v.end(), PrintFun);
    cout<<endl;

    for_each(v.begin(), v.end(), Addoobj(5));
    for_each(v.begin(), v.end(), PrintFun);
    cout<<endl;

    return 0;
}