#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Test
{
    int a;
    int b;
};

//���ԣ��Զ����Ʒ�ʽ���ļ���Ҳ����д���ı�
int main(void)
{
    Test test = {100, 200};
    //�Զ����Ʒ�ʽ��
    
    ofstream fout("test4.txt", ios::out|ios::binary);

    //c���������<<�����ı���ʽд�����ݵ�
    //��Ȼ�Զ����Ʒ�ʽ�򿪣�����д��ķ�ʽ���ı��ķ�ʽ
    fout<<"abc"<<200;

    return 0;
}