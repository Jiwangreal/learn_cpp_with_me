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
    // make_heap(a, a +  5);//默认是大堆

    make_heap(a, a +  5, less< int>());//大堆
    // make_heap(a, a +  5, greater< int>());小堆

    //从数组输出到输出流迭代器
    copy(a, a +  5, ostream_iterator< int>(cout,  " "));
    cout << endl;

    // sort(a, a +  5);
    //堆排序首先要构造成堆，才能排序
    //这里已经构造了堆了，可以用堆排序
    //什么样的堆，就决定他用什么样子的排序
    //less大堆得用less大堆排序
    //sort_heap不带参数默认是大堆
    sort_heap(a, a+5, less<int>());
    copy(a, a +  5, ostream_iterator< int>(cout,  " "));
    cout << endl;

     return  0;
}
