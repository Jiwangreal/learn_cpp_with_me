#include <iostream>

using namespace std;

int main(void)
{
    int n = 100;
    int n2 = 200;
    cout <<n<<" "<<n2<<endl;

    //put��ostream���һ����Ա����
    //put�����ķ���ֵҲ��ostream��������ã�����Ҳ��������ʹ��
    cout.put('H');
    cout.put('i');
    cout.put(' ');
    cout.put('H').put('i').put('\n');


    return 0;
}