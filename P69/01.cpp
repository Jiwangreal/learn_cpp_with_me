#include "Stack.h"


int main(void)
{
    //��ʾ��ʵ����һ��int���͵�ģ���࣬�������Զ��Ƶ���
    //Stack��һ��ģ��,Stack<int>��һ��ģ����
    Stack<int> s(10);//������ʹ��ʱ��Stack<int>����ʵ���������ڱ�������ɵģ��Ὣͷ�ļ������template
                    //��Щ������int�������滻��ģ��ʵ�����Ǻ�����صĽ�ϣ�ֻ��˵���صİ汾�Ǳ�����ά���ģ������ǳ���Ա
    s.Push(1);
    s.Push(2);
    s.Push(3);

    while (!s.Empty())
    {
        cout<<s.Top()<<endl;
        s.Pop();
    }

    return 0;
}