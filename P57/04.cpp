#include <iostream>
using namespace std;


//用宏来实现计算某个变量的大小
//sizeof_v
//&x+1,x变量的地址+1，也就是偏移了1个元素的地址，如果元素是4个字节就偏移4个字节
//&x+1 - &x,地址相减，实际上都是指针类型，两个指针相减得到的是他们之间的偏移量，相隔几个元素
//char*类型的地址相隔几个元素就是相隔几个字节
#define sizeof_v(x) (char*)(&x+1) - (char*)&x

//使用宏来计算某个类型的大小
//sizeof_t
//((t*)0+1)，t*的指针类型，偏移+1，就是偏移一个元素的t类型，得到地址的值刚好等于t类型的大小，但是得到的值类型还是一个指针
//size_t强制转换为整数
#define sizeof_t(t) (sizeof_t)((t*)0+1)

//实现一个对齐的宏
//b必须是2的n次方
/*
eg：ALIGN(3, 16) 
v=3
b=16
写成二进制：
v=0011
b-1=1111，b减完1以后就是全1的
~(b-1)取反就是全0

(v+b-1)就是：
v       0011
b-1     1111
=      10010

(v+b-1) & ~(b-1)就是：
    10010
     0000   将后面4位都抹除掉了
=   10000      
10000=16
原理思想：某个数要对齐到16的整数倍，用二进制表示的话，后面就是4个0，0000（用十进制去想，100的十进制后面有2个0）
32的整数倍，后面就是5个0
3对齐到16使用的是向上对齐，3 + 15肯定是超过16，超出的部分抹除掉，对于16而言，就是将低4位都置为0，所以得到的值就是对齐的值

ALIGN(0, 16) = 0
ALIGN(16, 16) = 0
10000
 1111
11111
*/
#define ALIGN(v, b)  ((v+b-1) & ~(b-1))

//为什么要对齐宏ALIGN？因为内存池可能会使用到
/*
比如要分配3个字节，7个字节，9个字节。内存池中的内存块大小是规则的，规则的不容易产生内存碎片。（不规则的物品放在箱子里面会产生空隙或者内存碎片）
要分配内存就无法得到连续的空间，就会被浪费掉。
内存块可以是4K，16K大小的块，32K大小的块。
如果申请内存<=4K，就对齐到4K，保证申请的内存总是4K
如果是4K<内存<=16K，就对齐到16K
如果是16K<内存<=32K，就对齐到32K
采用分级的机制实现内存池
*/

class Empty
{

};

int main(void)
{
    Empty e;
    int n;
    // cout << sizeof(e)<<endl;
    // cout<<sizeof(Empty)<<endl;//空类的大小是一个字节

    cout<<sizeof_v(e)<<endl;
    cout<<sizeof_v(n)<<endl;
    cout<<sizeof_t(Empty)<<endl;
    cout<<sizeof_t(int)<<endl;

    //3对齐到16的整数倍，应该是16
    cout<<ALLGN(3,16)<<endl;
    //应该是32
    cout<<ALLGN(31,16)<<endl;
    //应该是0
    cout<<ALLGN(0,16)<<endl;
    //应该是8192
    cout<<ALLGN(4198,4096)<<endl;
    return 0;
}