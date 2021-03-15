#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using  namespace std;

int main( void)
{
     char *a[] = { "",  "BBB",  "CCC"};
    vector< char *> v(a, a +  2);
    vector< char *>::iterator it;
    //ptr_fun转换成二元的函数对象，a，b，最后是strcmp(value, "")，如果是空字符串，比较返回0，为假
    //find_if是判别式为非0的时候，才是我们需要的
    // bind2nd转换成一元函数对象
    it = find_if(v.begin(), v.end(), bind2nd(ptr_fun(strcmp),  ""));//查找第一个不是空串的字符串
     if (it != v.end())
        cout << *it << endl;

     return  0;
}