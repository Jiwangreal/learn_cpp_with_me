#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    string line;
    string word;
    // cin.getline();//参数是char*，不能是string

    //使用getline方法，因为他是全局的，可以标准输入流，文件流，字符串流都行
    //返回值是cin，读取到流结束时，跳出循环
    while (getline(cin, line))//读取一行数据到line
    {
        istringstream iss(line);//构造字符串输入流对象

        //相当于C中的sscanf
        //字符串流iss关联了字符串line
        //相当于从字符串line提取数据到word变量
         while (iss >> word)//提取数据到word，这一行有多个单词
            cout << word <<  "#";
        cout << endl;
    }
     return  0;

}