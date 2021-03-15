#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using  namespace std;

int main( void)
{
    int a[] = { 5,  1,  2,  4,  3};
    //默认构建的是一个最大堆
    //二叉堆是一颗完全二叉树，用数组来保存，堆数量不一定纵是二叉树，但是二叉树应用最广
    //最大堆：父亲比他的任意孩子都要大
    //最小堆：父亲比他的任意孩子都要小
    make_heap(a, a +  5);//默认是大堆

    // make_heap(a, a +  5, less< int>());大堆
    // make_heap(a, a +  5, greater< int>());小堆

    //从数组输出到输出流迭代器
    copy(a, a +  5, ostream_iterator< int>(cout,  " "));
    cout << endl;

     return  0;
}
