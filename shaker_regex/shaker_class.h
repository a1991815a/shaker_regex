#ifndef __SHAKER_CLASS__
#define __SHAKER_CLASS__
#include "shaker_define.h"
#include "shaker_string.h"

SHAKER_NS_START;
class shaker_object;
typedef shaker_object*(_cdecl* S_CreateFunc)(void);

class shaker_class{
public:
	shaker_class();
	~shaker_class();
	const string& getClassName() const;
	const std::vector<shaker_class*> getSurperClass() const;
	shaker_object* create_object() const;
private:
	string	m_sClassName;
	std::vector<shaker_class*> m_vSuperClass;
	S_CreateFunc	m_pfnCreateFunc;
};

SHAKER_NS_END;
#endif