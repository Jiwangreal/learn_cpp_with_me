#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    ofstream fout( "test.txt");
    fout <<  "abc" <<  " " <<  200;//�Ȱ�abc 200д�뵽�ļ���
    fout.close();

    
    ifstream fin( "test.txt");
    string s;
    int n;
    //fin>>n>>s;������˳���ȡ�Ļ���������쳣״̬
    fin >> s >> n;//���ļ����������ļ������������
    cout << s <<  " " << n << endl;

    return 0;
}