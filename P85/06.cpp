#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>

using  namespace std;

int main( void)
{
    //Ĭ�ϴ�С��������
    //��map�����ǣ�keyֻ��1��������key������ӳ��ģ��洢�ڹؼ�������
    // set<int> s;
    set<int, greater<in> > s;//��������
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    for(set<int,greater<in> >::const_iterator it=s.begin(); it!=s.end();++it)
    // for(set<int>::const_iterator it=s.begin(); it!=s.end();++it)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
    return 0;

}