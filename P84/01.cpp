#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

void ShowVec( const vector< int> &v)
{
     for (vector< int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it <<  ' ';
    }
    cout << endl;
}
int main( void)
{
     int a[] = { 1,  2,  3,  4,  5};
    vector< int> v(a, a +  5);
    vector< int> v2;

    //��������������
    back_insert_iterator<vector< int> > bii(v);

    //���egûɶ���壬ʹ��push_backͬ������
    //�ڲ�����v.push_back(6);
    //�Բ��������������������������һ�β������
    //*bii = 6;//������*��������������˵�����������������ȡ������������λ�õ�Ԫ�أ���Ԫ��ֵ6���뵽����v��
    // ShowVec(v);

    *bii =  6;//*bii��*�Ų����ȼ���bii���ȼ���bii =  6;
    ShowVec(v);

    //Ҫ��vector< int> ������push_back��������Ϊback_insert_iterator��=������������push_back
    //���ݽ����Ķ�������v2Ҫ��back_insert_iterator�е�vector< int>��������һ��
    //��������ģ�壬���봫��һ��������������ǲ����Զ��Ƶ���
    back_insert_iterator<vector< int> > bii2(v2);
    copy(v.begin(), v.end(), bii2);//������������bii2����λ�ã����ǿ�����v2�����������������������������棩
                                    //������bii2�ĸ�ֵ���㣬ʵ�����ǰ�Ԫ��push_back��v2������
    ShowVec(v2);

    //back_inserter����ģ���ǿ��Խ��������Ƶ���
    back_inserter(v) =  7;//����һ��Ԫ��
    //����ֵ��һ��ģ����back_insert_iterator<_Container>��ʵ����һ��ģ�庯��
    //�ǲ���Ҫ���������ʹ��ݽ����������Ը��ݶ�������Ϳ����Զ��Ƶ�
    // back_inserter(vector<int>)(v) =  7;
    

    ShowVec(v);
    
    //back_inserter(v2)�Զ��Ƶ�v2�����;���vector< int> 
    //����ģ������Զ��Ƶ�����ģ���ǲ����Զ��Ƶ���
    copy(v.begin(), v.end(), back_inserter(v2));//��β������
    ShowVec(v2);


     return  0;
}