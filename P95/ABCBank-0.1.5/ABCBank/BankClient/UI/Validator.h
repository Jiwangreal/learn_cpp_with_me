#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

#include <ctype.h>
#include <string>

namespace UI
{

bool ValidateName(const std::string& str, char ch);//名称校验器
bool ValidatePass(const std::string& str, char ch);//密码校验器
bool ValidateId(const std::string& str, char ch);//身份证ID校验器
bool ValidateAccountId(const std::string& str, char ch);//账号校验器
bool ValidateMoney(const std::string& str, char ch);//金额校验器
bool ValidateDate(const std::string& str, char ch);//日期校验器

}
#endif // _VALIDATOR_H_