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

int main(void)
{
    Test test = {100, 200};
    //�Զ����Ʒ�ʽ��
    //ios::binary����Ӱ��\n�ַ���ת����������ü���
    ofstream fout("test4.txt", ios::out|ios::binary);
    //�Զ����Ʒ�ʽд��8���ֽڣ���100�ڻ����е��ڴ��ʾд���ļ��У���ת����char*
    fout.write(reinterpret_cast<char*>(&test), sizeof(Test));
    fout.close();

    //���֪��д��ɹ������Զ�ȡ����
    Test test2;
    ifstream fin("test4.txt", ios::in|ios::binary);
    fin.read(reinterpret_cast<char*>(&test2), sizeof(Test));
    cout<<test2.a<<" "<<test2.b<<endl;

    return 0;
}