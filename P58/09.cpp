#include <iostream>

using namespace std;

int main(void)
{
    char c[10], c2, c3;
    c2 = cin.get();
    c3 = cin.get();
    cin.putback(c2);
    cin.getline(&c[0], 9);
    cout << c <<endl;

    return 0£»
}