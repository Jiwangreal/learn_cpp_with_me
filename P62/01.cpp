#include <iostream>
#include <iomanip>//�����Ӹ�ʽ����Ҫ��ͷ�ļ�

using  namespace std;

// ͨ�������ӷ�ʽ���и�ʽ�����
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
    //Ĭ�����Ҷ���
    //���ڵĿ����10���ַ���64ǰ����8���ո��ܹ�10λ��n�������10λ
    cout << setw( 10) << n <<  '#' << n << endl;       // ��ȿ��Ʋ���Ӱ����һ�����
                                                    //��һ�����������д��ͬһ�У�Ҳ����д����һ��

    cout <<  "=================�������=====================" << endl;
    //setiosflags(ios::left)����Ϊ�����
    cout << setw( 10) << setiosflags(ios::left) << n <<  '#' << endl;
    cout << setw( 10) << n <<  '#' << endl;            // ������ƻ�Ӱ����һ�����
    //��ԭ���Ҷ��뷽ʽ1
    //cout<<setw(10)<<setiosflags(ios::right)<<n<<'#'<<endl;
    //��ԭ���Ҷ��뷽ʽ2��resetiosflags(ios::left)��ʾ��ios::leftȥ��
    cout << setw( 10) << resetiosflags(ios::left) << n <<  '#' << endl;  //ȥ�������

    cout <<  "=================������=====================" << endl;
    //Ĭ�����Կո�������
    //���ʺý�����䣺setfill('?')
    cout << setw( 10) << setfill('?') << n <<  '#' << endl;
    cout << setw( 10) << n <<  '#' << endl;            // �����ƻ�Ӱ����һ�����
    cout << setw( 10) << setfill(' ') << n <<  '#' << endl;

    cout <<  "=================���ȿ���=====================" << endl;
    cout << setprecision( 4) << d << endl;  //��Ч����
    cout << setprecision( 2) << d2 << endl;

    cout << setiosflags(ios::fixed);
    cout << setprecision( 4) << d << endl;  // С����������
    cout << setprecision( 2) << d2 << endl;

    cout <<  "=================�������=====================" << endl;

    cout << n << endl;//Ĭ��ʮ���Ʒ�ʽ���
     // cout << resetiosflags(ios::dec);
//     cout << setiosflags(ios::oct);
     // cout << resetiosflags(ios::oct);
//     cout << setiosflags(ios::hex);
    cout << oct << n << endl;//��򵥵ķ�ʽ��8����
    cout << hex << n << endl;//��򵥵ķ�ʽ��16����
    cout << endl;

     //�����ǰ׺
    cout << setiosflags(ios::showbase);  //�˽��Ƽ�ǰ׺0��ʮ�����Ƽ�ǰ׺0x
    cout << dec << n << endl;
    cout << oct << n << endl;
    cout << hex << n << endl;

    cout << endl;
    cout << setbase( 10) << n << endl;  //�˽��Ƽ�ǰ׺0��ʮ�����Ƽ�ǰ׺0x
    cout << setbase( 8) << n << endl;
    cout << setbase( 16) << n << endl;

     return  0;
}