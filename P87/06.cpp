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
        child_ptr  child_;//����һ��Child������ָ�����
};

int  main( void)
{
        parent_ptr  parent( new  Parent);
        child_ptr  child( new  Child);

        //Parent���׶����еĺ���ָ���Ӷ���
        parent->child_  =  child;//���Ӷ������ü���=2
        //Child���Ӷ����еĸ���ָ���׶���
        child->parent_  =  parent;//���׶������ü���=2

        //�������׶���ͺ��Ӷ����޷������ͷ�
        parent->child_.reset();//�ú��Ӷ�������ü������1������ѭ������
        //child����ָ���������ʱ����ǰ���ü�����1->0������Child�������٣���Child����
        //�ֳ���parent_����ʱparent_���ü�����Ϊ1����Parent��������ʱ��parent_������1->0������
        ///Parent�ᱻ����
         return   0;
}