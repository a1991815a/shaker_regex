#include "shaker_class.h"

SHAKER_NS_START;

shaker_class::shaker_class()
{

}

shaker_class::~shaker_class()
{

}

const string& shaker_class::getClassName() const
{
	return m_sClassName;
}

const std::vector<shaker_class*> shaker_class::getSurperClass() const
{
	return m_vSuperClass;
}

shaker_object* shaker_class::create_object() const
{
	return m_pfnCreateFunc();
}


SHAKER_NS_END;