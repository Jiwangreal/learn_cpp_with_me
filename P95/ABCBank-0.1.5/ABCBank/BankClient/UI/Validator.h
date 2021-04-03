#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

#include <ctype.h>
#include <string>

namespace UI
{

bool ValidateName(const std::string& str, char ch);//����У����
bool ValidatePass(const std::string& str, char ch);//����У����
bool ValidateId(const std::string& str, char ch);//���֤IDУ����
bool ValidateAccountId(const std::string& str, char ch);//�˺�У����
bool ValidateMoney(const std::string& str, char ch);//���У����
bool ValidateDate(const std::string& str, char ch);//����У����

}
#endif // _VALIDATOR_H_