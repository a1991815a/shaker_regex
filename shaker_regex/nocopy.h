#ifndef __NOCOPY__
#define __NOCOPY__
#include "shaker_define.h"

SHAKER_NS_START;

class nocopy{
public:
	nocopy() {};
private:
	nocopy(const nocopy& obj);
	nocopy(nocopy&& obj);
};

SHAKER_NS_END;
#endif