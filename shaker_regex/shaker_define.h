#ifndef __SHAKER_DEFINE__
#define __SHAKER_DEFINE__

//pcre正则表达式 库
#include "pcre_define.h"

#define SHAKER_DEPRECATED __declspec(deprecated)

#define SHAKER_NS_START namespace shaker{
#define SHAKER_NS_END	}
#define USING_NS_SHAKER using namespace shaker

#define SHAKER_SAFE_DELETE(p) do{if(p) delete p; p = nullptr;} while(0)

#define SHAKER_OBJECT 
#define S_OBJECT

#define SHAKER_INVOKEABLE
#define S_INVOKEABLE

#endif