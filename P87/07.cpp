#include  <boost/shared_ptr.hpp>
#include  <iostream>
using   namespace  std;

class  Parent;
class  Child;
typedef  boost::shared_ptr<Parent>  parent_ptr;
typedef  boost::shared_ptr<Child>  child_ptr;

class  Child
{
public:
        Child()
        {
                cout  <<   "Child  ..."  <<  endl;
        }
        ~Child()
        {
                cout  <<   "~Child  ..."  <<  endl;
        }
        parent_ptr  parent_;//����һ��Parent�������ָ�����
};

class  Parent
{
public:
        Parent()
        {
                cout  <<   "Parent  ..."  <<  endl;
        }
        ~Parent()
        {
                cout  <<   "~Parent  ..."  <<  endl;
        }
        boost::weak_ptr<parent> child_;//Parent������е�ָ����weak_ptr������
};

int  main( void)
{
        parent_ptr  parent( new  Parent);//Parent��������ü���Ϊ1
        child_ptr  child( new  Child);//Child��������ü���Ϊ1

        //Parent���׶����еĺ���ָ��������ָ�����child
        parent->child_  =  child;//��Ϊ�������ã�Child��������ü���=1
        //Child���Ӷ����еĸ���ָ��������ָ�����parent
        child->parent_  =  parent;//Parent���׶������ü���=2

        //�������׶���ͺ��Ӷ����޷������ͷ�
         return   0;
}