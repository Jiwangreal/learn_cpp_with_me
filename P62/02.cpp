#include <iostream>
// #include <iomanip>

using  namespace std;

// ͨ����Ա������ʽ���и�ʽ�����
// ��ȿ���
// �������
// ������
// ���ȿ���
// �������
int main( void)
{
     //system("chcp 936");//�������������ģ�������仰�����Ļ����ҳ��936������֧���������
     int n =  64;
     double d =  123.45;
     double d2 =  0.0187;

    cout <<  "=================��ȿ���=====================" << endl;
    cout << n <<  '#' << endl;
    cout.width( 10);
    cout << n <<  '#' << n << endl;                   // ��ȿ��Ʋ���Ӱ����һ�����

    cout <<  "=================�������=====================" << endl;
    cout.width( 10);
    cout.setf(ios::left);
    cout << n <<  '#' << endl;
    cout.width( 10);
    cout << n <<  '#' << endl;                // ������ƻ�Ӱ����һ�����
    //��ԭ���뷽ʽ1
     //cout.width(10);
     //cout.setf(ios::right);
     //cout<<n<<'#'<<endl;
     //��ԭ���뷽ʽ2
    cout.width( 10);
    cout.unsetf(ios::left);
    cout << n <<  '#' << endl;

    cout <<  "=================������=====================" << endl;
    cout.width( 10);
    cout.fill( '?');
    cout << n <<  '#' << endl;

    cout.width( 10);
    cout << n <<  '#' << endl;                // �����ƻ�Ӱ����һ�����

    cout.width( 10);
    cout.fill(' ');
    cout << n <<  '#' << endl;

    cout <<  "=================���ȿ���=====================" << endl;
    cout.precision( 4);//��Ч����
    cout << d << endl;
    cout.precision( 2);
    cout << d2 << endl;

    cout.setf(ios::fixed);// С����������
    cout.precision( 4);
    cout << d << endl;
    cout.precision( 2);
    cout << d2 << endl;;

    cout <<  "=================�������=====================" << endl;

    cout.setf(ios::showbase);//���ǰ׺
    cout << n << endl;
    cout.unsetf(ios::dec);
    cout.setf(ios::oct);
    cout << n << endl;

    cout.unsetf(ios::oct);
    cout.setf(ios::hex);
    cout << n << endl;

     return  0;
}