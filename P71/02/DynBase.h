//����ģʽ:��̬�����������
#ifndef _DYN_BASE_H_
#define _DYN_BASE_H_
#include <map>
#include <string>
using namespace std;

//�ú���ָ�봴������
typedef void* (*CREAT_FUNC)();

//�������ĺô���:����Ҫ�����ַ���ȥ�ж�������ʲô����
//��������һ������,�Ͳ���Ҫʲô�Ķ�,��P35\01.cpp����ʵ�ֵĹ���ģʽ��Ҫ����if else���
class DynObjectFactory
{
public:
    static void* CreatObject(const string& name)
    {
        //��map�����в��Ҵ�������
        //����������ҪԤ��ע��òſ���
        map<string, CREAT_FUNC>::const_iterator it;
        it = mapCls_.find(name);//ȡ�������ĺ���ָ��
        if (it == mapCls_.end())
            return 0;
        else
            return it->second();//�õ���������,�Ӷ���������
        //����ָ����ָ��ĺ���,����һ������,��Щ����ָ����ָ��ĺ������ں�REGISTER_CLASS�и�����
        //ÿ��ע��һ����,����һ��NewInstance����
        //map�����ĵ�2���ֶξ���һ������ָ��,ͨ�����ú���ָ����ָ��ĺ�������������
        //����ָ����ָ��ĺ���,���ڲ�new ����
    }

    //ע�᷽��
    //���ַ����ʹ����������뵽map�����У�������CreatObject�е�map������ȡ����Ӧ�Ĵ�����������̬�������󣬶�̬�������󷽷����ǵ���
    //NewInstance()����
    static void Register(const string& name, CREAT_FUNC func)
    {
        mapCls_[name] = func;
    }
private:
    //������Ҫ��̬���������Ϣ,�ַ����ʹ�������
    static map<string, CREAT_FUNC> mapCls_;//static�������������,��Ҫ�����ⶨ��
};

//����DynTest.cpp�����˸�ͷ�ļ�,Shape.cppҲ�����˸�ͷ�ļ�,����ı��������ض���
//������������ڶ�Ӧ��cpp�ļ���,�����������չ����_declspec(selectany)��������,�����Ļ��Ϳ���ֻ����һ����
//���ʹ��g++������,��ʹ��__attribute((weak))���滻_declspec(selectany),ʵ�ֵ�Ч��һ��
_declspec(selectany) map<string, CREAT_FUNC> DynObjectFactory::mapCls_;




// class Register
// {
// public:
//     Register(const string& name, CREAT_FUNC func)
//     {
//         DynObjectFactory::Register(name, func);
//     }
// }

// //������θĳ�ģ�壬������ε������ǣ���ʵ����Ĵ�����ʽע���ȥ��new class_name;
// //##�������ӵ�,���紫������Circle,��ô�õ��������CircleRegister
// #define REGISTER_CLASS(class_name) \
// class class_name##Register { \
// public: \
//     //��δ�����ĺ���
//     //class_name���ݽ�����ʱ����һ���ַ���,������һ������,����֧��new class_name
//     static void* NewInstance() \
//     { \
//         return new class_name; \        //new Circle����new Circle������ָ��ע�ᵽmap�е�CREAT_FUNC
//     } \
//     //��REGISTER_CLASS��Ĵ�������NewInstanceע�ᵽmapCls_����,�Ա��ڲ���
// private: \
//     static Register reg_; \//static��������
// }; \

// //static��������
// //�������ⲿ����һ������
// //#class_name�е�#��ʾ��Ҫ�����ݽ���������ת��Ϊ�ַ���
// //(#class_name, class_name##Register::NewInstance)������Ͷ�Ӧ�Ĵ�������
// //Register CircleRegister::reg_("Circle", Register CircleRegister::NewInstance);������Register�Ĺ��캯��
// Register class_name##Register::reg_(#class_name, class_name##Register::NewInstance);

// /*ʲôʱ����ɵ�ע��?
// ���еĶ���reg_,mapCls_���Ǿ�̬�ĳ���ʼ���е�ʱ��ͳ�ʼ����,�����ǽ��뵽mainʱ,ʵ���϶��Ѿ�ע�����
// ��Ϊ��Щ�����Ǿ�̬����,�����ⲿ������,�ڳ������е�ʱ��ͻ�������Ĺ��캯��
// */


//��ģ��ķ�ʽʵ�֣�һ�����ʵ�ֵĹ��ܣ�ģ��Ҳ��ʵ�֣���չ���Ĺ���Ҳ�Ǳ���������ɵģ�����Ĺ���������ģ���ʵ�����������ں�չ��
//ί����
//class class_name##Register�൱�ڱ����ģ�壬ֻ��Ҫģ����Ĺ��켴�ɣ�������ע��
template <typename T>
class DelegatingClass
{
public:
    DelegatingClass(const string& name)
    {
        DynObjectFactory::Register(name, &(DelegatingClass::NewInstance);
    }
    static void* NewInstance()
    {
        return new T;
    }

};


//�����������������
//elegatingClass<class_name>��ģ���࣬class##class_name(#class_name)����һ�������Ķ���Ŀ�����������Ĺ��캯���ĵ���
#define REGISTER_CLASS(class_name) DelegatingClass<class_name> class##class_name(#class_name)


#endif/*_DYN_BASE_H_*/