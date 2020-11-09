#include <iostream>
using namespace std;

class CObject
{
public:
    virtual void Serialize()
    {
        cout<<"CObject::Serialize ..."<<endl;
    }
};

class CDocument : public CObject
{
public:
    int data1_;
    void func()
    {
        cout<<"CDocument::func ..."<<endl;
        Serialize();
    }
    //���ǻ�����麯��
    virtual void Serialize()
    {
        cout<<"CDocument::Serialize ..."<<endl;
    }

    //��ΪҪ����������CMyDoc��Ĭ�Ϲ��캯����ҲҪ���û���CDocument��Ĭ�Ϲ��캯��������������Ҫ������
    //��ΪCMyDoc���й��캯����ʼ���б��в�û�и������캯����Ҳ��û�и�������Ĺ��죬������Ҫ��������Ĭ�Ϲ��캯��
    CDocument()
    {
        cout<<"CDocument"<<endl;
    }

    CDocument(const CDocument& other)
    {
        cout<<"CDocument(const CDocument& other)"<<endl;
    }
};

//�̳�func������CDocument���Serialize
class CMyDoc : public CDocument
{
public:
    int data2_;
    //��������󸲸�������Ļ����麯��
    virtual void Serialize()
    {
        cout<<"CMyDoc::Serialize ..."<<endl;
    }
};

int main()
{
    //������ײ�����������
    CMyDoc mydoc;
    CMyDoc* pmydoc = new CmyDoc;//����һ������ָ�����������

    cout<<"#1 testing"<<endl;
    mydoc.func();//��ʵ�ʶ�������ȥ���ң��ҵ��������Ӧ���麯��

    cout<<"#2 testing"<<endl;
    ((CDocument*)(&mydoc))->func();//((CDocument*)(&mydoc))�൱�ڻ���ָ��ָ�����������
                                //����CMyDocû���ض���func�����Ի����CDocument�е�func
                                //ʵ��ָ��Ķ�����mydoc�����Ի����CMyDoc�е�Serialize

    cout<<"#3 testing"<<endl;
    pmydoc->func();

    cout<<"#4 testing"<<endl;
    ((CDocument)mydoc).func();//mydoc����ǿ��ת��ΪCDocument��������ת��
                            //����ȫȫ�����������ת��Ϊ������󣬰�������Ѿ������˸ı䣬����CDocument�����
                            //����ת�ͻ���ù��캯����������ÿ������캯������������mydoc���󿽱�����ΪCDocument�������ûд�����Ի�
                            //����Ĭ�ϵĿ������캯��

    return 0;
}