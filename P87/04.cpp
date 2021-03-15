#include <boost/shared_ptr.hpp>
#include <iostream>
#include <memory>
#include <vector>
using  namespace std;

class X
{
public:
    X()
    {
        cout <<  "X ..." << endl;
    }
    ~X()
    {
        cout <<  "~X ..." << endl;
    }
};

int main( void)
{
    //����ʧ��
    // vector<auto_ptr<X> > v;
    // auto_ptr<X> p(new X);
    // v.push_back(p);

    //boost::shared_ptr<X>�ǿ��Էŵ�vector�е�
    vector<boost::shared_ptr<X> > v;
    boost::shared_ptr<X> p(new X);
    v.push_back(p);//push_back�ڲ��ṹ��һ��shared_ptr������pһ�����������Ϊ2
    cout<<v.use_count<<endl;//2������������X
    //��p�������٣�����v�еĶ���Ҳ�����ٵ�ʱ�����ü�����Ϊ0����Ѷ���X�Զ�������

    

    return  0;
}
