#include <iostream>
#include <sstream>

using namespace std;

//��double����ת��Ϊ�ַ���
string doubletostr( double val)
{
    ostringstream oss;
    oss << val;//������ַ������У��ַ������еĻ��������Ƿ���ռ䣬��val�������ռ���

    //str()�����ڲ��Ŀռ�����ַ���
    return oss.str(); // return string copy of character array
}

//�ַ���תdouble��C������strtod
double strtodouble( const string &str)
{
    istringstream iss(str);
     double val;
    iss >> val;//���ַ�����iss��ȡ���ݵ�val�����ַ���str���ַ�����iss���Ӧ��ʵ�����Ǵ��ַ���str��ȡ���ݵ�val
     return val;
}

int main( void)
{
     double val =  55. 55;

    string str = doubletostr(val);
    cout << str << endl;

    str =  "123.123";
    val = strtodouble(str);
    cout << val << endl;
     return  0;

}