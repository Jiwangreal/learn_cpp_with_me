#include <vector>
#include <iostrem>
using namespace std;


int main(void)
{
    //vector<int> ��һ��ģ���࣬����һ������v������ģ����Ĺ��캯���ĵ���
    vector<int> v;
    v.push_back(1);//�������ϵ�
    cout<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.capacity()<<endl;


    v.push_back(1);
    cout<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.capacity()<<endl;

    return 0;
}
