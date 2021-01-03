#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    ofstream fout( "test.txt");
    fout <<  "abc" <<  " " <<  200;//先把abc 200写入到文件中
    fout.close();

    
    ifstream fin( "test.txt");
    string s;
    int n;
    //fin>>n>>s;不按照顺序读取的话，会输出异常状态
    fin >> s >> n;//用文件输入流打开文件，并将其输出
    cout << s <<  " " << n << endl;

    return 0;
}