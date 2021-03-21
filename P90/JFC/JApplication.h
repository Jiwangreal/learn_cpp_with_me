#ifndef _JAPPLICATION_H_
#define _JAPPLICATION_H_

//��JFC��������������ŵ�һ�����ƿռ�����
namespace JFC
{

class JWindow;

//һ��Ӧ�ó���JApplicationֻ������һ����������Ҫʵ�ֵ���ģʽ
// һ������ĵ���ģʽ��ģ��QT
class JApplication
{
public:
	JApplication();
	~JApplication();

	static JApplication* Instance() { return self_; }

	JWindow* GetCurrent() const { return current_; }
	JWindow* SetCurrent(JWindow* win) { current_ = win; }//��win����Ϊ��ǰ����
	JWindow* Root() const { return root_; }

	int Exec();				// ��Ϣѭ��

private:
	static JApplication* self_;//static����
	JWindow* current_;		// ��ǰ���հ����Ĵ���
	JWindow* root_;			// ��
};


//Ŀ�����������ļ�ģ��Ҳ���ʵ�JApplication app;����ģ��QT��qApp
#define jApp JApplication::Instance()
}
#endif // _JAPPLICATION_H_