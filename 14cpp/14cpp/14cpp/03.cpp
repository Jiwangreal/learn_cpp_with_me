#include "Test.h"
#include <iostream>
using namespace std;

void TestFun(const Test t)//����t���������ڿ����������ڣ��������ڽ������ͻ�����
{

}

void TestFun2(const Test& t)
{

}

//������t�������쵽һ����ʱ������ȥ
Test TestFun3(const Test& t)
{
    //�����صĶ��������t�ǲ�ͬ��
	return t;
}

const Test& TestFun4(const Test& t)
{
	//return const_cast<Test&>(t);//ȥ��const����
	return t;
}

//TestFun4Ҳ������ôд��
//  Test& TestFun4(const Test& t)
// {
// 	return const_cast<Test&>(t);//ȥ��const����
// 	return t;
// }

int main(void)
{
	Test t(10);
	//t = TestFun3(t);//����һ����ʱ���󣬽���ʱ����ֵ��t�����õȺ����������������ʱ�������������
	//Test t2 = TestFun3(t);//�ڷ��ض����ʱ��Ҫ���ÿ������캯����������һ����ʱ������ʱ����t2�ӹ�
                            //TestFun3(t)��������ʱ���󲻻��������٣���ʱ��������ֳ�Ϊ��t2�������󣬻ᱻ��������t2�ӹ�

	//Test& t2 = TestFun3(t);//Destroy��....֮����ʱ���󲻻��������٣�����Ŀ������캯�����ں������ض����ʱ����õ�

	//Test t2 = TestFun4(t);//���ض����ʱ�򣬲�û�е��ÿ������캯�������ض�������ã�Ȼ�󽫶����ʼ����t2�����ÿ������캯��
	const Test& t2 = TestFun4(t);//���ٵ��ÿ������캯������Ϊ������t2���յģ�����Ҫ�ͷ��صĶ���t����һ���ڴ�ռ�
	cout<<"........"<<endl;

	return 0;
}