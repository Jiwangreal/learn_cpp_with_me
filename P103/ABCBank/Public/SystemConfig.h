#ifndef _SYSTEM_CONFIG_H_
#define _SYSTEM_CONFIG_H_

#include <string>
#include <map>
#include <fstream>

using namespace std;

namespace PUBLIC
{

//��ȡ�����ļ���
class SystemConfig
{
public:
	SystemConfig(const string& filepath);//�����ļ�·��
	void Load();
	const std::string& GetProperty(const std::string& name);//��������key����value

private:
	map<std::string, std::string> properties_;
	std::string filepath_;
};

}

#endif // _SYSTEM_CONFIG_H_
