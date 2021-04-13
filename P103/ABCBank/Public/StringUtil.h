#ifndef _STRING_UTIL_H_
#define _STRING_UTIL_H_

#include <vector>
#include <string>

namespace PUBLIC
{

//È¥³ý×Ö·û´®µÄ×óÓÒ¿Õ¸ñ
class StringUtil  
{
public:
	static std::string Trim(std::string& str);
	static std::string Ltrim(std::string& str);
	static std::string Rtrim(std::string& str);
	static std::vector<std::string> Split(const std::string& str, const char delim);//·Ö¸ô
};

}

#endif // _STRING_UTIL_H_
