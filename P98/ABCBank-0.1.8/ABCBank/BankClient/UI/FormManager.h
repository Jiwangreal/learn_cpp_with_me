#ifndef _FORM_MANAGER_H_
#define _FORM_MANAGER_H_

#include "../JFC/JForm.h"
#include "../../Public/Singleton.h"

#include <string>
#include <map>

using namespace PUBLIC;
using namespace JFC;

namespace UI
{

//整个客户端界面都保存在FormManager中，只保存一份
//FormManager是一个单例对象
class FormManager
{
	friend class Singleton<FormManager>;
public:
	//将form添加至map容器中
	void Add(const std::string& name, JForm* form)
	{
		forms_[name] = form;
	}

	//返回map当中的一个元素
	JForm* Get(const std::string& name)
	{
		return forms_[name];
	}
private:
	std::map<std::string, JForm*> forms_;
	FormManager();
	~FormManager();
};

}

#endif // _FORM_MANAGER_H_