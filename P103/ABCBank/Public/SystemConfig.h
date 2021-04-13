#ifndef _SYSTEM_CONFIG_H_
#define _SYSTEM_CONFIG_H_

#include <string>
#include <map>
#include <fstream>

using namespace std;

namespace PUBLIC
{

//读取配置文件的
class SystemConfig
{
public:
	SystemConfig(const string& filepath);//配置文件路径
	void Load();
	const std::string& GetProperty(const std::string& name);//根据名称key查找value

private:
	map<std::string, std::string> properties_;
	std::string filepath_;
};

}

#endif // _SYSTEM_CONFIG_H_
