#ifndef _PTR_VECTOR_H_
#define _PTR_VECTOR_H_

#include <vector>
#include <memory>

template<typename T>
class ptr_vector : public std::vector<T*>
{
public:
    ~ptr_vector()
    {
        clear();
    }
    //�ض���vector�е�clear����
    void clear()
    {
        //����ָ����ָ���ڴ�ռ���ͷ�
        std::vector<T*>::iterator it;
        for (it = std::begin(); it != std::end(); ++it)
            delete *it;//it����T*��ָ�룬ȡ*����T*
    }

    //�����clear�ͷ���ָ���������
    std::vector<T*>::clear();

    //��ָ�����������ʱ��ִ��operator new���ܷ����ڴ�ʧ�ܣ���ָ��û�в��뵽�����У�
    //std::vector<T*>::clear();���ܲ����ͷ��ڴ棬�����ڴ�й©
    //��������������Ȩת�Ƶ�����ָ��ptr�����ϣ���ʹ�ڲ��ڴ�ռ����ʧ�ܡ�����ָ����һ���ֲ�����
    //��׽�쳣ʱ����ջչ����ʱ����ͷŶ��󣬽�����е�valָ���ͷŵ�
    void push_back(T* const &val) 
    {
        std::auto_ptr<T*> ptr(val);
        std::vector<T*>::push_back(val);
        ptr.release();//�������е����˵��operator new�����ڴ�ɹ���ptr�ͷ�����Ȩ
    }

    //����һ���ӿڣ���һ������ָ����뵽������
    //ԭ����vector�ǲ��ܽ�ָ����뵽�����еģ����_Ty������ָ�����ͣ���ζ������ָ�����ͷ�����Ȩ��ʱ��
    //������ڲ���ָ�룬��ָ����Ϊ0���������������const��ָ���ڲ������ݳ�Ա�ǲ��ܸ��ĵ�
    void push_back(std::auto_ptr<T>& val)
    {
        //���ﲻҪʹ��std::vector<T*>::push_back(val.release());
        //push_back()��operator new��������Ϊrelease()���ͷ�����Ȩ��������ָ���ΪҰָ�룬û�˹ܣ�����ڴ�й©
        std::vector<T*>::push_back(val.get());
        //����ɹ����ͷ�����Ȩ
        val.release();//���������ָ���ڲ������ݳ�Ա�ģ�release()��ʾ����ָ���ͷ�����Ȩ
    }

    //boostҲ��ptr_vector�����ǵ����ݸ���

};





#endif // _PTR_VECTOR_H_