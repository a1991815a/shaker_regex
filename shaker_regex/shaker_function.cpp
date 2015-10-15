#include "shaker_function.h"



shaker::shaker_function::shaker_function()
	:m_pfnFunc(nullptr)
{

}

shaker::shaker_function::shaker_function(S_FuncPtr ptr)
	:m_pfnFunc(ptr)
{

}

BaseType shaker::shaker_function::getReturnType() const
{
	return m_eReturnType;
}

const std::vector<BaseType>& shaker::shaker_function::getParamType() const
{
	return m_vecParamType;
}

size_t shaker::shaker_function::getParamCount() const
{
	return m_vecParamType.size();
}
