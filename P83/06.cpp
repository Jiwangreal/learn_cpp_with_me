#include  <iostream>
#include  <algorithm>
#include  <functional>
#include  <vector>
#include  <string>

using   namespace  std;

bool  check( int  elem)
{
         return  elem  <   3;
}

int  main( void)
{
    int  a[]  =  { 1,   2,   3,   4,   5};
    vector< int>  v(a,  a  +   5);

    vector< int>::iterator  it;
    // not1�е�no˵����>=3��ȡ��
    // not1Ҳ��һ��һԪ��������
    it  =  find_if(v.begin(),  v.end(),  not1(ptr_fun(check)));//���ص�һ��>=3��Ԫ��

    //������ôд��ԭ���ǣ���Ϊ���Ͳ�ƥ�䣬  not1��Ҫ��argument_type����check����û��
    //ptr_fun��һ������������������ͨ����ת����һԪ��������������not1�Ľӿ���ƥ����
    // it  =  find_if(v.begin(),  v.end(),  not1(check);
         if  (it  !=  v.end())
                cout  <<  *it  <<  endl;
         return   0;
}
