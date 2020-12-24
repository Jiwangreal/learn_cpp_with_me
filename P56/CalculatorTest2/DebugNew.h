#ifndef _DEBUG_NEW_H
#define _DEBUG_NEW_H

#ifndef NODEBUG
#include "Tracer.h"

//在使用new int时，可以使用成new(__FILE__, __LINE__) int
//__FILE__:当前代码所处在的文件，__LINE__：当前代码的行
//此外，重载了operator new，实际调用的是operator new，并且将2个参数传递过去了
//此时的new等价于new(__FILE__, __LINE__)
#define new new(__FILE__, __LINE__)

//delete不支持下面的用法，不要这么去用
// #define delete delete(__FILE__, __LINE__)

#endif //NODEBUG

#endif // _DEBUG_NEW_H