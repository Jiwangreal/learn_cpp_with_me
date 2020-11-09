#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    //key类型是string，有一定的限制
    //value值类型是int，无限制
    //因为插入到map容器内部的元素默认是按照key从小到大来排序
    //所以key类型一定要重载<运算符，这样才可以进行比较和排序
    map<string,int> mapTest;

    //仅仅是对value来讲
    //内部重载了[]运算符，效率低一些，但是直观：因为经历2步：首先插入key=“aaa”的元素，初始值等于int类型的默认值，为0
    //第二步，再把100赋值给它
    //也就是说，先构造一个元素，其值是默认值，若是类的话，就使用类的构造函数来构造一个对象，放到map容器内部，然后再把
    //该对象赋值给它（上面的对象）
    mapTest["aaa"] = 100;//int& operator[](const string& index)

    mapTest["eee"] = 500;
    mapTest["eee"] = 300;//可以更新原来eee的值
    //构造了一个value_type对象
    //(map<string, int>::value_type这是一个类类型，第一个参数是key，第二个参数是value
    mapTest.insert(map<string, int>::value_type("bbb", 200));
    mapTest.insert(map<string, int>::value_type("bbb", 2000));//不可以更新原来bbb的值
    
    //构造一个pair对象，pair是一个类类型
    mapTest.insert(pair<string,int>("ccc", 300));
    mapTest.insert(pair<string,int>("ccc", 3000));//不可以更新原来ccc的值

    //make_pair是一个函数，它返回的就是pair类型对象，与上面的等价
    mapTest.insert(make_pair("ddd",400));
    mapTest.insert(make_pair("ddd",4000));//不可以更新原来ddd的值

   

    //遍历map容器，也使用迭代器
    map<string, int>::const_iterator it;
    for(it=mapTest.begin(); it!=mapTest.end(); ++it) 
    {
        //it->first就是string，it->second就是int
        //输出会自动按照key来排序
        cout<it->first<<" "<<it->second<<endl;
        
    }

    return 0;

}



