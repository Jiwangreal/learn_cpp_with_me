#include <iostream>
using namespace std;
int main(void)
{

    int n=static_cast<int>(3.14);
    count<<"n="<<n<<endl;//输出为3

    void* p=&n;
    int* p2=static_cast<int*>(p);
    return 0;
}



