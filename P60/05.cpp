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

//���ԣ����ı���ʽ���ļ���Ҳ����д�����������
//д��������Ƕ����ƻ����ı�����򿪷�ʽ�޹أ���д��ʹ�õĺ����й�
int main(void)
{
    Test test = {100, 200};
    //���ı���ʽ��
    ofstream fout("test4.txt");
    //�Զ����Ʒ�ʽд��8���ֽڣ���100�ڻ����е��ڴ��ʾд���ļ��У���ת����char*
    fout.write(reinterpret_cast<char*>(&test), sizeof(Test));
    fout.close();

    //���֪��д��ɹ������Զ�ȡ����
    Test test2;
    ifstream fin("test4.txt");
    fin.read(reinterpret_cast<char*>(&test2), sizeof(Test));
    cout<<test2.a<<" "<<test2.b<<endl;

    return 0;
}