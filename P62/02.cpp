#include <iostream>
// #include <iomanip>

using  namespace std;

// 通过成员函数方式进行格式化输出
// 宽度控制
// 对齐控制
// 填充控制
// 精度控制
// 进制输出
int main( void)
{
     //system("chcp 936");//如果不能输出中文，加上这句话：更改活动代码页：936，用于支持中文输出
     int n =  64;
     double d =  123.45;
     double d2 =  0.0187;

    cout <<  "=================宽度控制=====================" << endl;
    cout << n <<  '#' << endl;
    cout.width( 10);
    cout << n <<  '#' << n << endl;                   // 宽度控制不会影响下一个输出

    cout <<  "=================对齐控制=====================" << endl;
    cout.width( 10);
    cout.setf(ios::left);
    cout << n <<  '#' << endl;
    cout.width( 10);
    cout << n <<  '#' << endl;                // 对齐控制会影响下一个输出
    //还原对齐方式1
     //cout.width(10);
     //cout.setf(ios::right);
     //cout<<n<<'#'<<endl;
     //还原对齐方式2
    cout.width( 10);
    cout.unsetf(ios::left);
    cout << n <<  '#' << endl;

    cout <<  "=================填充控制=====================" << endl;
    cout.width( 10);
    cout.fill( '?');
    cout << n <<  '#' << endl;

    cout.width( 10);
    cout << n <<  '#' << endl;                // 填充控制会影响下一个输出

    cout.width( 10);
    cout.fill(' ');
    cout << n <<  '#' << endl;

    cout <<  "=================精度控制=====================" << endl;
    cout.precision( 4);//有效数字
    cout << d << endl;
    cout.precision( 2);
    cout << d2 << endl;

    cout.setf(ios::fixed);// 小数点后面个数
    cout.precision( 4);
    cout << d << endl;
    cout.precision( 2);
    cout << d2 << endl;;

    cout <<  "=================进制输出=====================" << endl;

    cout.setf(ios::showbase);//输出前缀
    cout << n << endl;
    cout.unsetf(ios::dec);
    cout.setf(ios::oct);
    cout << n << endl;

    cout.unsetf(ios::oct);
    cout.setf(ios::hex);
    cout << n << endl;

     return  0;
}