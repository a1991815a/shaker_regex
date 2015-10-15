#ifndef __SHAKER_FUNCTION__
#define __SHAKER_FUNCTION__
#include "shaker_define.h"
#include "shaker_string.h"
#include "shaker_param.hpp"

SHAKER_NS_START;

#define S_PARAM(arg) &(arg)

typedef void(*S_FuncPtr)(void);

class shaker_function{
public:
	shaker_function();

	BaseType getReturnType() const;
	const std::vector<BaseType>& getParamType() const;
	size_t	getParamCount() const;
private:
	S_FuncPtr				m_pfnFunc;
	string					m_sSingature;
	BaseType				m_eReturnType;
	std::vector<BaseType>	m_vecParamType;
};

SHAKER_NS_END;
#endif