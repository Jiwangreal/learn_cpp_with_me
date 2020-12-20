#include <iostream>
using namespace std;
#include "DebugNew.h"


int main(void)
{
    int* p =new int;
    delete p;

    int* p2 = new int[5];
    delete[] p2;
    return 0;
}