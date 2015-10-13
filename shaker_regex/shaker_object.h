#ifndef __SHAKER_OBJECT__
#define __SHAKER_OBJECT__
#include "shaker_define.h"
#include "shaker_string.h"

SHAKER_NS_START;

class shaker_object{
public:
	shaker_object();
	~shaker_object();
	const string& getClassName() const;
	const std::vector<shaker_object*> getSurperClass() const;
private:
	string* m_sClassName;
	std::vector<shaker_object*>*		m_superClass;
};

SHAKER_NS_END;
#endif