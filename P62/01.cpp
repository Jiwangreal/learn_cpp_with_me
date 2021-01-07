#include <iostream>
#include <iomanip>//操作子格式化需要该头文件

using  namespace std;

// 通过操纵子方式进行格式化输出
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
    //默认是右对齐
    //现在的宽度是10个字符，64前面有8个空格，总共10位，n的输出是10位
    cout << setw( 10) << n <<  '#' << n << endl;       // 宽度控制不会影响下一个输出
                                                    //下一个输出可以是写在同一行，也可以写再下一行

    cout <<  "=================对齐控制=====================" << endl;
    //setiosflags(ios::left)设置为左对齐
    cout << setw( 10) << setiosflags(ios::left) << n <<  '#' << endl;
    cout << setw( 10) << n <<  '#' << endl;            // 对齐控制会影响下一个输出
    //还原成右对齐方式1
    //cout<<setw(10)<<setiosflags(ios::right)<<n<<'#'<<endl;
    //还原成右对齐方式2，resetiosflags(ios::left)表示把ios::left去除
    cout << setw( 10) << resetiosflags(ios::left) << n <<  '#' << endl;  //去除左对齐

    cout <<  "=================填充控制=====================" << endl;
    //默认是以空格进行填充
    //以问好进行填充：setfill('?')
    cout << setw( 10) << setfill('?') << n <<  '#' << endl;
    cout << setw( 10) << n <<  '#' << endl;            // 填充控制会影响下一个输出
    cout << setw( 10) << setfill(' ') << n <<  '#' << endl;

    cout <<  "=================精度控制=====================" << endl;
    cout << setprecision( 4) << d << endl;  //有效数字
    cout << setprecision( 2) << d2 << endl;

    cout << setiosflags(ios::fixed);
    cout << setprecision( 4) << d << endl;  // 小数点后面个数
    cout << setprecision( 2) << d2 << endl;

    cout <<  "=================进制输出=====================" << endl;

    cout << n << endl;//默认十进制方式输出
     // cout << resetiosflags(ios::dec);
//     cout << setiosflags(ios::oct);
     // cout << resetiosflags(ios::oct);
//     cout << setiosflags(ios::hex);
    cout << oct << n << endl;//最简单的方式：8进制
    cout << hex << n << endl;//最简单的方式：16进制
    cout << endl;

     //输出的前缀
    cout << setiosflags(ios::showbase);  //八进制加前缀0，十六进制加前缀0x
    cout << dec << n << endl;
    cout << oct << n << endl;
    cout << hex << n << endl;

    cout << endl;
    cout << setbase( 10) << n << endl;  //八进制加前缀0，十六进制加前缀0x
    cout << setbase( 8) << n << endl;
    cout << setbase( 16) << n << endl;

     return  0;
}